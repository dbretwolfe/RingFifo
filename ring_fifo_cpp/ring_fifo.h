#pragma once

#include <exception>
#include <vector>

namespace RingFifo
{
    template <typename T> class RingFifo
    {
    public:
        RingFifo(size_t maxSize) : 
            maxFifoSize(maxSize),
            fifoBufferSize(maxSize + 1)
        {
            buffer.resize(fifoBufferSize);
        }

        ~RingFifo(){}

        void Reset()
        {
            writeIndex = 0;
            readIndex = 0;
        }

        void Push(T data)
        {
            if (GetSizeRemaining() == 0)
            {
                throw std::overflow_error("FIFO is full, cannot push!");
            }

            buffer[writeIndex] = data;
            writeIndex = ((writeIndex + 1) % fifoBufferSize);
        }

        T& Pop()
        {
            if (GetSize() == 0)
            {
                throw std::underflow_error("FIFO is empty, cannot pop!");
            }

            T& dataOut = buffer[readIndex];
            readIndex = ((readIndex + 1) % fifoBufferSize);

            return dataOut;
        }

        size_t GetSize() const
        {
            if (writeIndex < readIndex)
            {
                return ((writeIndex + maxFifoSize) - readIndex);
            }
            else
            {
                return (writeIndex - readIndex);
            }
        }

        size_t GetSizeRemaining() const
        {
            return (maxFifoSize - GetSize());
        }

    private:
        std::vector<T> buffer;
        size_t writeIndex = 0;
        size_t readIndex = 0;

        const size_t maxFifoSize;
        const size_t fifoBufferSize;
    };
}
