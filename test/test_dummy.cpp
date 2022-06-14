#include <gtest/gtest.h>

static const double epsilon = 1e-9;

TEST(Dummy, test_1) {
    double input    = 2.0;
    double expected = 1.0 * 2.0;

    EXPECT_NEAR(expected, input, epsilon);
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}