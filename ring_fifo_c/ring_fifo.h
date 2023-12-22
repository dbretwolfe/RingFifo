#pragma once

#include <stdint.h>
#include <stdbool.h>

#define RING_FIFO_MAX_SIZE (256)

typedef uint8_t fifoDataType;

typedef struct 
{
    // One FIFO slot is wasted to disambiguate the FIFO full condition in a SPSC thread safe manner.
    fifoDataType buffer[RING_FIFO_MAX_SIZE + 1];
    size_t writeIndex;
    size_t readIndex;
} RingFifo;

void RingFifo_Reset(RingFifo* fifo);
int RingFifo_Push(RingFifo* fifo, fifoDataType data);
int RingFifo_Pop(RingFifo* fifo, fifoDataType* dataOut);
size_t RingFifo_GetSize(const RingFifo* fifo);
size_t RingFifo_GetSizeRemaining(const RingFifo* fifo);
bool RingFifo_IsFull(const RingFifo* fifo);
bool RingFifo_IsEmpty(const RingFifo* fifo);
