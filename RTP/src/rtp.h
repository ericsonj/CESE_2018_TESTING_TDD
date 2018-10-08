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

void RTP_Init(uint8_t *buffer, size_t size);

#ifdef __cplusplus
}
#endif

#endif /* __RTP_H */
