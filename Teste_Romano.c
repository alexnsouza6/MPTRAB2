#include <gtest/gtest.h>
#include <stdio.h>
#include <stdlib.h>
#include "Romano.h"

TEST (TestaROMANO, Unit) {

EXPECT_EQ (1, transforma_romano("I"));
EXPECT_EQ (2, transforma_romano("II"));
EXPECT_EQ (3, transforma_romano("III"));
    
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

