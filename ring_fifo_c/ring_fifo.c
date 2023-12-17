#include <string.h>

#include "ring_fifo.h"

void RingFifo_Reset(RingFifo* fifo)
{
    if (fifo == NULL)
    {
        return;
    }

    memset(fifo, 0, sizeof(RingFifo));
}

int RingFifo_Push(RingFifo* fifo, fifoDataType data)
{
    if ((fifo == NULL) || (RingFifo_GetSizeRemaining(fifo) == 0))
    {
        return -1;
    }

    fifo->buffer[fifo->writeIndex] = data;
    fifo->writeIndex = ((fifo->writeIndex + 1) % RING_FIFO_MAX_SIZE);

    return 0;
}

int RingFifo_Pop(RingFifo* fifo, fifoDataType* dataOut)
{
    if ((fifo == NULL) || (RingFifo_GetSize(fifo) == 0))
    {
        return -1;
    }

    *dataOut = fifo->buffer[fifo->readIndex];
    fifo->readIndex = ((fifo->readIndex + 1) % RING_FIFO_MAX_SIZE);

    return 0;
}

size_t RingFifo_GetSize(const RingFifo* fifo)
{
    if (fifo == NULL)
    {
        return 0;
    }
    
    // Check to see if the write index has wrapped around the end of the buffer.
    if (fifo->writeIndex < fifo->readIndex)
    {
        return ((fifo->writeIndex + RING_FIFO_MAX_SIZE) - fifo->readIndex);
    }
    else
    {
        return (fifo->writeIndex - fifo->readIndex);
    }
}

size_t RingFifo_GetSizeRemaining(const RingFifo* fifo)
{
    return RING_FIFO_MAX_SIZE - RingFifo_GetSize(fifo);
}