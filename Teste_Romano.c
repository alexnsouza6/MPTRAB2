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

TEST(TestaROMANO, Tens){
	EXPECT_EQ (11, transforma_romano("XI"));
	EXPECT_EQ (18, transforma_romano("XVIII"));
	EXPECT_EQ (23, transforma_romano("XXIII"));
	EXPECT_EQ (28, transforma_romano("XXVIII"));
	EXPECT_EQ (29, transforma_romano("XXIX"));
	EXPECT_EQ (30, transforma_romano("XXX"));
	EXPECT_EQ (35, transforma_romano("XXXV"));
	EXPECT_EQ (39, transforma_romano("XXXIX"));	
}

TEST(TestaROMANO, Tens2){
	EXPECT_EQ (40, transforma_romano("XL"));
	EXPECT_EQ (50, transforma_romano("L"));
	EXPECT_EQ (58, transforma_romano("LVIII"));
	EXPECT_EQ (69, transforma_romano("LXIX"));
	EXPECT_EQ (75, transforma_romano("LXXV"));
	EXPECT_EQ (81, transforma_romano("LXXXI"));
	EXPECT_EQ (87, transforma_romano("LXXXVII"));
}

TEST(TestaROMANO, Hundreds){
	EXPECT_EQ (90, transforma_romano("XC"));
	EXPECT_EQ (100, transforma_romano("C"));
	EXPECT_EQ (109, transforma_romano("CIX"));
	EXPECT_EQ (157, transforma_romano("CLVII"));
	EXPECT_EQ (200, transforma_romano("CC"));
	EXPECT_EQ (240, transforma_romano("CCXL"));
	EXPECT_EQ (390, transforma_romano("CCCXC"));
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

