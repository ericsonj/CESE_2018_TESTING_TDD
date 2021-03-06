/**
 * File:   rtp.h
 * Author: Ericson Joseph
 *
 * Created on October  7, 2018,  7:18 PM
 */

#ifndef __RTP_H
#define __RTP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdlib.h>

enum RPT_PAYLOAD_TYPE { PCMU = 0x00, PCMA = 0x08 };

void RTP_Init(uint8_t *buffer, size_t size);

void RTP_AddPayload(uint8_t *buffer, size_t size, uint8_t payloadType);

void RTP_AddMark(uint8_t *buffer, size_t size);

void RTP_AddNextSequence(uint8_t *buffer, size_t size);

void RTP_AddNextTimestamp(uint8_t *buffer, size_t size);

#ifdef __cplusplus
}
#endif

#endif /* __RTP_H */
