#include <format>

#include <gtest/gtest.h>

#include "fifo_test_fixture.h"

TEST_F(FifoTestC, Reset)
{
    RingFifo_Reset(&fifo);

    // Fifo should be empty after reset.
    EXPECT_EQ(0, RingFifo_GetSize(&fifo));
    EXPECT_EQ(RING_FIFO_MAX_SIZE, RingFifo_GetSizeRemaining(&fifo));
}

TEST_F(FifoTestC, PushPop)
{
    RingFifo_Reset(&fifo);

    uint8_t testVector[RING_FIFO_MAX_SIZE] = {0};

    // Try to pop, should fail because FIFO is empty.
    uint8_t dataOut = 0;
    EXPECT_EQ(-1, RingFifo_Pop(&fifo, &dataOut));

    // Push until full, testing size along the way.
    for (int i = 0; i < RING_FIFO_MAX_SIZE; i++)
    {
        SCOPED_TRACE(std::format("Push loop iteration {}\r\n", i));
        RingFifo_Push(&fifo, i);
        testVector[i] = i;

        EXPECT_EQ((i + 1), RingFifo_GetSize(&fifo));
        EXPECT_EQ((RING_FIFO_MAX_SIZE - (i + 1)), RingFifo_GetSizeRemaining(&fifo));
    }

    // Try to push, should fail because FIFO is full.
    EXPECT_EQ(-1, RingFifo_Push(&fifo, 0));

    // Push until full, testing size along the way.
    for (int i = (RING_FIFO_MAX_SIZE - 1); i >= 0; i--)
    {
        SCOPED_TRACE(std::format("Pop loop iteration {}\r\n", i));
        dataOut = 0;
        RingFifo_Pop(&fifo, &dataOut);
        EXPECT_EQ(testVector[i], dataOut);

        EXPECT_EQ((i + 1), RingFifo_GetSize(&fifo));
        EXPECT_EQ((RING_FIFO_MAX_SIZE - (i + 1)), RingFifo_GetSizeRemaining(&fifo));
    }
}