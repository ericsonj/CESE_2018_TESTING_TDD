/**
 * File:   rtp.c
 * Author: Ericson Joseph
 *
 * Created on October  7, 2018,  7:34 PM
 */

#include "rtp.h"

static uint16_t sequence;
static uint32_t timestamp;

void RTP_Init(uint8_t *buffer, size_t size) {
    buffer[0] = 0x80;
    sequence  = 0;
    timestamp = 0;
}

void RTP_AddPayload(uint8_t *buffer, size_t size, uint8_t payloadType) {
    switch (payloadType) {
    case PCMA: buffer[1] = PCMA; break;
    case PCMU: buffer[1] = PCMU; break;
    default: break;
    }
}

void RTP_AddMark(uint8_t *buffer, size_t size){
    buffer[1] |= 0x80;
}

void RTP_AddNextSequence(uint8_t *buffer, size_t size) {
    sequence++;
    buffer[2] = (uint8_t)((sequence & 0xFF00) >> 8);
    buffer[3] = (uint8_t)(sequence & 0x00FF);
}

void RTP_AddNextTimestamp(uint8_t *buffer, size_t size){
    
}
