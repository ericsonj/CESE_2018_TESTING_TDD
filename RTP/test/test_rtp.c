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

void test_RTP_AddNextSequence(void) {

  uint16_t initseq = 0;
  uint16_t nextseq = 0;

  RTP_AddNextSequence(buffer, RTP_SIZE);
  initseq = (buffer[2] << 8) + (buffer[3]);

  for (uint16_t i = 0; i < 1500; i++) {
    RTP_AddNextSequence(buffer, RTP_SIZE);
    nextseq = (buffer[2] << 8) + (buffer[3]);
    TEST_ASSERT_EQUAL(initseq + 1, nextseq);
    initseq++;
  }
}
