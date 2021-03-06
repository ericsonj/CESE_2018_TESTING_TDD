/**
 * File:   test_rtp.c
 * Author: Ericson Joseph
 *
 * Created on October  7, 2018,  7:12 PM
 */

#include "rtp.h"
#include "unity.h"
#include <stdint.h>
#include <stdlib.h>
#include <strings.h>

#define RTP_SIZE 172

uint8_t buffer[RTP_SIZE];

void setUp(void) { bzero(buffer, RTP_SIZE); }

void tearDown(void) {}

void test_RTP_Init(void) {
    RTP_Init(buffer, RTP_SIZE);
    TEST_ASSERT_EQUAL(0x80, buffer[0]);
}

void test_RTP_AddPayload(void) {
    RTP_AddPayload(buffer, RTP_SIZE, PCMA);
    TEST_ASSERT_EQUAL_MESSAGE(PCMA, buffer[1], "Test payload PCMA");

    RTP_AddPayload(buffer, RTP_SIZE, PCMU);
    TEST_ASSERT_EQUAL_MESSAGE(PCMU, buffer[1], "Test payload PCMU");
}

void test_RTP_AddMark(void) {
    RTP_AddPayload(buffer, RTP_SIZE, PCMA);
    RTP_AddMark(buffer, RTP_SIZE);
    TEST_ASSERT_BITS(0x80, 0xFF, buffer[1]);
}

void test_RTP_AddNextSequence(void) {

    uint16_t initseq = 0;
    uint16_t nextseq = 0;

    RTP_AddNextSequence(buffer, RTP_SIZE);
    initseq = (buffer[2] << 8) + (buffer[3]);

    for (uint16_t i = 0; i < 1500; i++) {
        RTP_AddNextSequence(buffer, RTP_SIZE);
        nextseq = (buffer[2] << 8) + (buffer[3]);
        TEST_ASSERT_EQUAL_MESSAGE(initseq + 1, nextseq, "Test sequence");
        initseq++;
    }
}

void test_RTP_AddNextTimestamp(void) {

    uint32_t timestamp     = 0;
    uint32_t nextTimestamp = 0;

    RTP_AddNextTimestamp(buffer, RTP_SIZE);
    timestamp =
        (buffer[4] << 24) + (buffer[5] << 16) + (buffer[6] << 8) + (buffer[7]);

    for (uint32_t i = 20 ; i < 2000; i++) {        
        RTP_AddNextTimestamp(buffer, RTP_SIZE);
        nextTimestamp =
            (buffer[4] << 24) + (buffer[5] << 16) + (buffer[6] << 8) + (buffer[7]);

        TEST_ASSERT_EQUAL_MESSAGE(timestamp + 20, nextTimestamp, "Test timestamp");
        timestamp += 20;
    }

}
