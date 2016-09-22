#include <gtest/gtest.h>
#include <stdio.h>
#include <stdlib.h>
#include "Romano.h"

TEST(TestaROMANO, Unit){

	EXPECT_EQ (1, transforma_romano("I"));
	EXPECT_EQ (2, transforma_romano("II"));
	EXPECT_EQ (3, transforma_romano("III"));
	EXPECT_EQ (4, transforma_romano("IV"));
	EXPECT_EQ (5, transforma_romano("V"));
	EXPECT_EQ (8, transforma_romano("VIII"));
	EXPECT_EQ (9, transforma_romano("IX"));
	EXPECT_EQ (10, transforma_romano("X"));	
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

