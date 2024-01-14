#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#define MIN(a, b) a < b ? a : b

template <class T> class RingBuffer {
    public:
        RingBuffer(unsigned int maxSize) :
            maxSize(maxSize),
            currentSize(0),
            currentIndex(0) {
               pBuffer = new T[maxSize];
        }

        ~RingBuffer() {
            delete pBuffer;
        }

        void add(T element) {
            pBuffer[currentIndex] = element;
            currentIndex = (currentIndex + 1) % maxSize;
            currentSize = MIN(currentSize + 1, maxSize);
        }

        unsigned int getCurrentSize() {
            return currentSize;
        }

        T getElelemtAt(unsigned int index) {
            return pBuffer[index % maxSize];
        }
    private:
        unsigned int maxSize;
        unsigned int currentSize;
        unsigned int currentIndex;
        T *pBuffer;
};

#endif
