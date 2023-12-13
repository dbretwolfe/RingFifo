#pragma once

#include <exception>
#include <cassert>

namespace RingFifo
{
    template <typename T> class RingFifo
    {
    public:
        RingFifo(size_t size) : maxFifoSize(size) 
        {
            buffer = new T[size];
        }

        ~RingFifo()
        {
            delete [] buffer;
        }

        void Push(T data)
        {
            if (GetSizeRemaining() == 0)
            {
                throw std::exception("FIFO is full, cannot push!");
            }

            buffer[writeIndex] = data;
            writeIndex = ((writeIndex + 1) % maxFifoSize);
        }

        T Pop() const
        {
            if (GetSize() == 0)
            {
                throw std::exception("FIFO is empty, cannot pop!");
            }

            T dataOut = buffer[readIndex];
            readIndex = ((readIndex + 1) % maxFifoSize);

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
                return (writeIndex - maxFifoSize);
            }
        }

        size_t GetSizeRemaining() const
        {
            assert (maxFifoSize <= GetSize());
            return (maxFifoSize - GetSize());
        }

    private:
        T* buffer;
        size_t writeIndex = 0;
        size_t readIndex = 0;

        const size_t maxFifoSize;
    };
}