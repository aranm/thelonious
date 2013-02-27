#ifndef THELONIOUS_MODULO_H
#define THELONIOUS_MODULO_H

#include "types.h"
#include "unit.h"
#include "parameter.h"
#include "util.h"

namespace thelonious {

// Modulo (%) operators

// For Channels

template <size_t N>
Channel<N> operator%(const Channel<N> &a, const Channel<N> &b) {
    Channel<N> channel;
    for (uint32_t i=0; i<N; i++) {
        channel[i] = modulo(a[i],  b[i]);
    }
    return channel;
}

template <size_t N>
Channel<N> operator%(const Channel<N> &a, Sample b) {
    Channel<N> channel;
    for (uint32_t i=0; i<N; i++) {
        channel[i] = modulo(a[i], b);
    }
    return channel;
}

template <size_t N>
Channel<N> operator%(Sample a, const Channel<N> &b) {
    Channel<N> channel;
    for (uint32_t i=0; i<N; i++) {
        channel[i] = modulo(a, b[i]);
    }
    return channel;
}

// For Buffers

template <size_t M, size_t N>
Buffer<M, N> operator%(const Buffer<M, N> &a, const Buffer<M, N> &b) {
    Buffer<M, N> buffer;
    for (uint32_t i=0; i<M; i++) {
        buffer[i] = a[i] % b[i];
    }
    return buffer;
}

template <size_t M, size_t N>
Buffer<M, N> operator%(const Buffer<M, N> &a, Sample b) {
    Buffer<M, N> buffer;
    for (uint32_t i=0; i<M; i++) {
        buffer[i] = a[i] % b;
    }
    return buffer;
}

template <size_t M, size_t N>
Buffer<M, N> operator%(Sample a, const Buffer<M, N> &b) {
    Buffer<M, N> buffer;
    for (uint32_t i=0; i<M; i++) {
        buffer[i] = a % b[i];
    }
    return buffer;
}

// End modulo (%) operators

// Modulo assignment (%=) operators

// For Channels

template <size_t N>
Channel<N> & operator%=(Channel<N> &a, const Channel<N> &b) {
    for (uint32_t i=0; i<N; i++) {
       a[i] = modulo(a[i], b[i]);
    }
    return a;
}

template <size_t N>
Channel<N> & operator%=(Channel<N> &a, Sample b) {
    for (uint32_t i=0; i<N; i++) {
        a[i] = modulo(a[i], b);
    }
    return a;
}

// For Buffers

template <size_t M, size_t N>
Buffer<M, N> & operator%=(Buffer<M, N> &a, const Buffer<M, N> &b) {
    for (uint32_t i=0; i<M; i++) {
        a[i] %= b[i];
    }
    return a;
} 

template <size_t M, size_t N>
Buffer<M, N> & operator%=(Buffer<M, N> &a, Sample b) {
    for (uint32_t i=0; i<M; i++) {
        a[i] %= b;
    }
    return a;
}

// End modulo assignment (%=) operators

template <size_t N>
class Modulo : public Unit<N> {
public:
    Modulo(Sample value=0.0f): value(value) {}

    void tick(Block<N> &block) {
        Chock valueChock = value.get();

        for (uint32_t i=0; i<N; i++) {
            block[i] %= valueChock;
        }
    }

    Parameter value;
};

}

#endif
