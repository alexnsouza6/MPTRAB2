#include <gtest/gtest.h>
#include <stdio.h>
#include <stdlib.h>
#include "Romano.h"

TEST(TestaROMANO, Units){
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

TEST(TestaROMANO, Hundreds2){
	EXPECT_EQ (400, transforma_romano("CD"));
	EXPECT_EQ (500, transforma_romano("D"));
	EXPECT_EQ (572, transforma_romano("DLXXII"));
	EXPECT_EQ (669, transforma_romano("DCLXIX"));
	EXPECT_EQ (882, transforma_romano("DCCCLXXXII"));
	EXPECT_EQ (899, transforma_romano("DCCCXCIX"));
}

TEST(TestaROMANO, Thousands){
	EXPECT_EQ (900, transforma_romano("CM"));
	EXPECT_EQ (1032, transforma_romano("MXXXII"));
	EXPECT_EQ (1500, transforma_romano("MD"));
	EXPECT_EQ (1869, transforma_romano("MDCCCLXIX"));
	EXPECT_EQ (2049, transforma_romano("MMXLIX"));
	EXPECT_EQ (2204, transforma_romano("MMCCIV"));
}

TEST(TestaROMANO, Invalid_Operands){
	EXPECT_EQ (-1, transforma_romano("IIII"));
	EXPECT_EQ (-1, transforma_romano("VX"));
	EXPECT_EQ (-1, transforma_romano("VL"));
	EXPECT_EQ (-1, transforma_romano("VC"));
	EXPECT_EQ (-1, transforma_romano("VVVV"));
	EXPECT_EQ (-1, transforma_romano("XD"));
	EXPECT_EQ (-1, transforma_romano("XXXX"));
	EXPECT_EQ (-1, transforma_romano("LD"));
	EXPECT_EQ (-1, transforma_romano("LL"));
	EXPECT_EQ (-1, transforma_romano("DM"));
	EXPECT_EQ (-1, transforma_romano("CCCC"));
	EXPECT_EQ (-1, transforma_romano("MMMM"));	
}





int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

