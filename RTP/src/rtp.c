/**
 * File:   rtp.c
 * Author: Ericson Joseph
 *
 * Created on October  7, 2018,  7:34 PM
 */

#include "rtp.h"

void RTP_Init(uint8_t *buffer, size_t size){
    buffer[0] = 0x80;
}

void RTP_AddNextSequence(uint8_t *buffer, size_t size){
    
}
