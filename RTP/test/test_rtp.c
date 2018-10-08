/**
 * File:   test_rtp.c
 * Author: Ericson Joseph
 *
 * Created on October  7, 2018,  7:12 PM
 */

#include <stdlib.h>
#include <stdint.h>
#include <strings.h>
#include "unity.h"
#include "rtp.h"

#define RTP_SIZE 172

uint8_t buffer[RTP_SIZE];

void setUp(void) {
    bzero(buffer, RTP_SIZE);
}

void tearDown(void) {
}

void test_RTP_Init(void) {
    RTP_Init(buffer, RTP_SIZE);
    TEST_ASSERT_EQUAL(0x80, buffer[0]);
}
