#pragma once

#include <stdint.h>

#define RING_FIFO_MAX_SIZE (256)

typedef uint8_t fifoDataType;

typedef struct 
{
    fifoDataType buffer[RING_FIFO_MAX_SIZE];
    size_t writeIndex;
    size_t readIndex;
} RingFifo;

void RingFifo_Reset(RingFifo* fifo);
int RingFifo_Push(RingFifo* fifo, fifoDataType data);
int RingFifo_Pop(RingFifo* fifo, fifoDataType* dataOut);
size_t RingFifo_GetSize(const RingFifo* fifo);
size_t RingFifo_GetSizeRemaining(const RingFifo* fifo);