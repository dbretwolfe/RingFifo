#pragma once

#include <gtest/gtest.h>

extern "C"
{
    #include "ring_fifo.h"
}

class FifoTestC : public testing::Test
{
protected:
    void SetUp() override
    {
    }

    RingFifo fifo;
};