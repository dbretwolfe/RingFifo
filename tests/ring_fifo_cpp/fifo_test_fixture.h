#pragma once

#include <gtest/gtest.h>

#include "ring_fifo.h"

class FifoTestCpp : public testing::Test
{
protected:
    void SetUp() override
    {   
    }

    const size_t maxFifoSize = 256;
    RingFifo::RingFifo<uint8_t> fifo = RingFifo::RingFifo<uint8_t>(maxFifoSize);
};