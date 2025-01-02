#pragma once

#include <gtest/gtest.h>

#include "ring_fifo.hpp"

class FifoTestCpp : public testing::Test
{
protected:
    void SetUp() override
    {   
    }

    static constexpr size_t maxFifoSize = 256;
    FifoTemplates::RingFifo<uint8_t> fifo = FifoTemplates::RingFifo<uint8_t>(maxFifoSize);
};