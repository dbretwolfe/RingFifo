#include <string.h>
#include <assert.h>

#include "ring_fifo.h"

// The actual length of the ring FIFO buffer is equal to the FIFO size plus 1.
#define BUFFER_SIZE (RING_FIFO_MAX_SIZE + 1)

void RingFifo_Reset(RingFifo* fifo)
{
    assert(fifo);

    memset(fifo, 0, sizeof(RingFifo));
}

int RingFifo_Push(RingFifo* fifo, fifoDataType data)
{
    assert(fifo);

    if ((fifo == NULL) || (RingFifo_IsFull(fifo) == true)) {
        return -1;
    }

    fifo->buffer[fifo->writeIndex] = data;
    fifo->writeIndex = ((fifo->writeIndex + 1) % BUFFER_SIZE);

    return 0;
}

int RingFifo_Pop(RingFifo* fifo, fifoDataType* dataOut)
{
    assert(fifo);

    if ((fifo == NULL) || (RingFifo_IsEmpty(fifo))) {
        return -1;
    }

    *dataOut = fifo->buffer[fifo->readIndex];
    fifo->readIndex = ((fifo->readIndex + 1) % BUFFER_SIZE);

    return 0;
}

size_t RingFifo_GetSize(const RingFifo* fifo)
{
    assert(fifo);
    
    // Check to see if the write index has wrapped around the end of the buffer.
    if (fifo->writeIndex < fifo->readIndex) {
        return ((fifo->writeIndex + RING_FIFO_MAX_SIZE) - fifo->readIndex);
    }
    else {
        return (fifo->writeIndex - fifo->readIndex);
    }
}

size_t RingFifo_GetSizeRemaining(const RingFifo* fifo)
{
    assert(fifo);

    return (RING_FIFO_MAX_SIZE - RingFifo_GetSize(fifo));
}

bool RingFifo_IsEmpty(const RingFifo* fifo)
{
    assert(fifo);

    return (fifo->writeIndex == fifo->readIndex);
}

bool RingFifo_IsFull(const RingFifo* fifo)
{
    assert(fifo);

    // Returns true if the write index is one slot behind the read index.
    return (((fifo->writeIndex + 1) % BUFFER_SIZE) == fifo->readIndex);
}
