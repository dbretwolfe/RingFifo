#include <gtest/gtest.h>

extern "C"
{
    #include "../../ring_fifo_c/ring_fifo.h"
}

// TODO: Add test fixture for the FIFO object.

TEST(FifoTestC, Reset)
{
    RingFifo fifo;
    RingFifo_Reset(&fifo);

    // Fifo should be empty after reset.
    EXPECT_EQ(0, RingFifo_GetSize(&fifo));
    EXPECT_EQ(RING_FIFO_MAX_SIZE, RingFifo_GetSizeRemaining(&fifo));
}

TEST(FifoTestC, PushPop)
{
    RingFifo fifo;
    RingFifo_Reset(&fifo);

    int testVector[RING_FIFO_MAX_SIZE] = {0};

    for (int i = 0; i < RING_FIFO_MAX_SIZE; i++)
    {
        // TODO: Add scoped trace to loop.
        RingFifo_Push(&fifo, i);
        testVector[i] = i;

        EXPECT_EQ((i + 1), RingFifo_GetSize(&fifo));
        EXPECT_EQ((RING_FIFO_MAX_SIZE - (i + 1)), RingFifo_GetSizeRemaining(&fifo));
    }
}