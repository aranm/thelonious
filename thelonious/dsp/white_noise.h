#ifndef THELONIOUS_WHITE_NOISE_H
#define THELONIOUS_WHITE_NOISE_H

#include <random>

#include "thelonious/types.h"
#include "thelonious/unit.h"
#include "thelonious/constants/sizes.h"

namespace thelonious {
namespace dsp {

template <size_t N>
class WhiteNoiseN : public Unit<N> {
public:
    WhiteNoiseN() {}

    void tick(Block<N> &block) {
        for (uint32_t i=0; i<N; i++) {
            for (uint32_t j=0; j<constants::BLOCK_SIZE; j++) {
                block[i][j] = ((float) std::rand() / RAND_MAX) * 2.0f - 1.0f;
            }
        }
    }
};

typedef WhiteNoiseN<1> WhiteNoise;

} // namespace dsp
} // namespace thelonious

#endif