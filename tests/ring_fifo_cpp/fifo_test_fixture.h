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
    FifoTemplates::RingFifo<uint8_t> fifo = FifoTemplates::RingFifo<uint8_t>(maxFifoSize);
};