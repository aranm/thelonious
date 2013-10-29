#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "thelonious/dsl/buffer.h"

using namespace thelonious;
using namespace testing;

class BufferTest : public Test {
public:
    void SetUp() {
        
        for (uint32_t i=0; i<constants::BLOCK_SIZE; i++) {
            for (uint32_t j=0; j<2; j++) {
                ones[j][i] = 1.f;
                twos[j][i] = 2.f;
                threes[j][i] = 3.f;
            }
        }
    }

    Block<2> ones;
    Block<2> twos;
    Block<2> threes;
};


TEST_F(BufferTest, AddBuffer) {
    Block<2> block = ones + twos;
    ASSERT_THAT(block[0], Each(FloatEq(3.f)));
    ASSERT_THAT(block[1], Each(FloatEq(3.f)));
}

TEST_F(BufferTest, AddSample) {
    Block<2> block = ones + 2.f;
    ASSERT_THAT(block[0], Each(FloatEq(3.f)));
    ASSERT_THAT(block[1], Each(FloatEq(3.f)));
}

TEST_F(BufferTest, AddSample2) {
    Block<2> block = 2.f + ones;
    ASSERT_THAT(block[0], Each(FloatEq(3.f)));
    ASSERT_THAT(block[1], Each(FloatEq(3.f)));
}

TEST_F(BufferTest, AddAssignBuffer) {
    Block<2> block = ones;
    block += twos;
    ASSERT_THAT(block[0], Each(FloatEq(3.f)));
    ASSERT_THAT(block[1], Each(FloatEq(3.f)));
}

TEST_F(BufferTest, AddAssignSample) {
    Block<2> block = ones;
    block += 2.f;
    ASSERT_THAT(block[0], Each(FloatEq(3.f)));
    ASSERT_THAT(block[1], Each(FloatEq(3.f)));
}

TEST_F(BufferTest, SubtractBuffer) {
    Block<2> block = threes - twos;
    ASSERT_THAT(block[0], Each(FloatEq(1.f)));
    ASSERT_THAT(block[1], Each(FloatEq(1.f)));
}

TEST_F(BufferTest, SubtractSample) {
    Block<2> block = threes - 2.f;
    ASSERT_THAT(block[0], Each(FloatEq(1.f)));
    ASSERT_THAT(block[1], Each(FloatEq(1.f)));
}

TEST_F(BufferTest, SubtractSample2) {
    Block<2> block = 3.f - twos;
    ASSERT_THAT(block[0], Each(FloatEq(1.f)));
    ASSERT_THAT(block[1], Each(FloatEq(1.f)));
}

TEST_F(BufferTest, SubtractAssignBuffer) {
    Block<2> block = threes;
    block -= twos;
    ASSERT_THAT(block[0], Each(FloatEq(1.f)));
    ASSERT_THAT(block[1], Each(FloatEq(1.f)));
}

TEST_F(BufferTest, SubtractAssignSample) {
    Block<2> block = threes;
    block -= 2.f;
    ASSERT_THAT(block[0], Each(FloatEq(1.f)));
    ASSERT_THAT(block[1], Each(FloatEq(1.f)));
}

TEST_F(BufferTest, MultiplyBuffer) {
    Block<2> block = twos * threes;
    ASSERT_THAT(block[0], Each(FloatEq(6.f)));
    ASSERT_THAT(block[1], Each(FloatEq(6.f)));
}

TEST_F(BufferTest, MultiplySample) {
    Block<2> block = twos * 3.f;
    ASSERT_THAT(block[0], Each(FloatEq(6.f)));
    ASSERT_THAT(block[1], Each(FloatEq(6.f)));
}

TEST_F(BufferTest, MultiplySample2) {
    Block<2> block = 3.f * twos;
    ASSERT_THAT(block[0], Each(FloatEq(6.f)));
    ASSERT_THAT(block[1], Each(FloatEq(6.f)));
}

TEST_F(BufferTest, MultiplyAssignBuffer) {
    Block<2> block = threes;
    block *= twos;
    ASSERT_THAT(block[0], Each(FloatEq(6.f)));
    ASSERT_THAT(block[1], Each(FloatEq(6.f)));
}

TEST_F(BufferTest, MultiplyAssignSample) {
    Block<2> block = threes;
    block *= 2.f;
    ASSERT_THAT(block[0], Each(FloatEq(6.f)));
    ASSERT_THAT(block[1], Each(FloatEq(6.f)));
}

TEST_F(BufferTest, DivideBuffer) {
    Block<2> block = threes / twos;
    ASSERT_THAT(block[0], Each(FloatEq(1.5f)));
    ASSERT_THAT(block[1], Each(FloatEq(1.5f)));
}

TEST_F(BufferTest, DivideSample) {
    Block<2> block = threes / 2.f;
    ASSERT_THAT(block[0], Each(FloatEq(1.5f)));
    ASSERT_THAT(block[1], Each(FloatEq(1.5f)));
}

TEST_F(BufferTest, DivideSample2) {
    Block<2> block = 3.f / twos ;
    ASSERT_THAT(block[0], Each(FloatEq(1.5f)));
    ASSERT_THAT(block[1], Each(FloatEq(1.5f)));
}

TEST_F(BufferTest, DivideAssignBuffer) {
    Block<2> block = threes;
    block /= twos;
    ASSERT_THAT(block[0], Each(FloatEq(1.5f)));
    ASSERT_THAT(block[1], Each(FloatEq(1.5f)));
}

TEST_F(BufferTest, DivideAssignSample) {
    Block<2> block = threes;
    block /= 2.f;
    ASSERT_THAT(block[0], Each(FloatEq(1.5f)));
    ASSERT_THAT(block[1], Each(FloatEq(1.5f)));
}

TEST_F(BufferTest, ModuloBuffer) {
    Block<2> block = threes % twos;
    ASSERT_THAT(block[0], Each(FloatEq(1.f)));
    ASSERT_THAT(block[1], Each(FloatEq(1.f)));
}

TEST_F(BufferTest, ModuloSample) {
    Block<2> block = threes % 2.f;
    ASSERT_THAT(block[0], Each(FloatEq(1.f)));
    ASSERT_THAT(block[1], Each(FloatEq(1.f)));
}

TEST_F(BufferTest, ModuloSample2) {
    Block<2> block = 3.f % twos ;
    ASSERT_THAT(block[0], Each(FloatEq(1.f)));
    ASSERT_THAT(block[1], Each(FloatEq(1.f)));
}

TEST_F(BufferTest, ModuloAssignBuffer) {
    Block<2> block = threes;
    block %= twos;
    ASSERT_THAT(block[0], Each(FloatEq(1.f)));
    ASSERT_THAT(block[1], Each(FloatEq(1.f)));
}

TEST_F(BufferTest, ModuloAssignSample) {
    Block<2> block = threes;
    block %= 2.f;
    ASSERT_THAT(block[0], Each(FloatEq(1.f)));
    ASSERT_THAT(block[1], Each(FloatEq(1.f)));
}



int main(int argc, char** argv) {
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}