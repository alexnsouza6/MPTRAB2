#include <gtest/gtest.h>
#include <stdio.h>
#include <stdlib.h>
#include "Romano.h"

/** \brief Teste realizado para os números entre 1 e 10*/
TEST(TestaROMANO, Units){
	EXPECT_EQ (1, transforma_romano("I")); //Dado a entrada "I", espera-se obter o retorno "1"
	EXPECT_EQ (2, transforma_romano("II")); //Dado a entrada "II", espera-se obter o retorno "2"
	EXPECT_EQ (3, transforma_romano("III")); //Dado a entrada "III", espera-se obter o retorno "3"
	EXPECT_EQ (4, transforma_romano("IV")); //Dado a entrada "IV", espera-se obter o retorno "4"
	EXPECT_EQ (5, transforma_romano("V")); //Dado a entrada "V", espera-se obter o retorno "5"
	EXPECT_EQ (8, transforma_romano("VIII")); //Dado a entrada "VIII", espera-se obter o retorno "8"
	EXPECT_EQ (9, transforma_romano("IX")); //Dado a entrada "IX", espera-se obter o retorno "9"
	EXPECT_EQ (10, transforma_romano("X"));	 //Dado a entrada "X", espera-se obter o retorno "10"
}


/** \brief Teste realizado para alguns números entre 11 e 39*/
TEST(TestaROMANO, Tens){
	EXPECT_EQ (11, transforma_romano("XI")); //Dado a entrada "XI", espera-se obter o retorno "10"
	EXPECT_EQ (18, transforma_romano("XVIII")); //Dado a entrada "XVIII", espera-se obter o retorno "18"
	EXPECT_EQ (23, transforma_romano("XXIII")); //Dado a entrada "XXIII", espera-se obter o retorno "23"
	EXPECT_EQ (28, transforma_romano("XXVIII")); //Dado a entrada "XXVIII", espera-se obter o retorno "28"
	EXPECT_EQ (29, transforma_romano("XXIX")); //Dado a entrada "XXIX", espera-se obter o retorno "29"
	EXPECT_EQ (30, transforma_romano("XXX")); //Dado a entrada "XXX", espera-se obter o retorno "30"
	EXPECT_EQ (35, transforma_romano("XXXV")); //Dado a entrada "XXXV", espera-se obter o retorno "35"
	EXPECT_EQ (39, transforma_romano("XXXIX"));	 //Dado a entrada "XXXIX", espera-se obter o retorno "39"
}

/** \brief Teste realizado para alguns números entre 40 e 89*/
TEST(TestaROMANO, Tens2){
	EXPECT_EQ (40, transforma_romano("XL")); //Dado a entrada "XL", espera-se obter o retorno "40"
	EXPECT_EQ (50, transforma_romano("L")); //Dado a entrada "L", espera-se obter o retorno "50"
	EXPECT_EQ (58, transforma_romano("LVIII")); //Dado a entrada "LVIII", espera-se obter o retorno "58"
	EXPECT_EQ (69, transforma_romano("LXIX")); //Dado a entrada "LXIX", espera-se obter o retorno "69"
	EXPECT_EQ (75, transforma_romano("LXXV")); //Dado a entrada "LXXV", espera-se obter o retorno "75"
	EXPECT_EQ (81, transforma_romano("LXXXI")); //Dado a entrada "LXXXI", espera-se obter o retorno "81"
	EXPECT_EQ (87, transforma_romano("LXXXVII")); //Dado a entrada "LXXXVII", espera-se obter o retorno "87"
}

/** \brief Teste realizado para alguns números entre 90 e 390*/
TEST(TestaROMANO, Hundreds){
	EXPECT_EQ (90, transforma_romano("XC")); //Dado a entrada "XC", espera-se obter o retorno "90"
	EXPECT_EQ (100, transforma_romano("C")); //Dado a entrada "C", espera-se obter o retorno "100"
	EXPECT_EQ (109, transforma_romano("CIX")); //Dado a entrada "CIX", espera-se obter o retorno "109"
	EXPECT_EQ (157, transforma_romano("CLVII")); //Dado a entrada "CLVII", espera-se obter o retorno "157"
	EXPECT_EQ (200, transforma_romano("CC")); //Dado a entrada "CC", espera-se obter o retorno "200"
	EXPECT_EQ (240, transforma_romano("CCXL")); //Dado a entrada "CCXL", espera-se obter o retorno "240"
	EXPECT_EQ (390, transforma_romano("CCCXC")); //Dado a entrada "CCCXC", espera-se obter o retorno "390"
}

/** \brief Teste realizado para alguns números entre 400 e 899*/
TEST(TestaROMANO, Hundreds2){
	EXPECT_EQ (400, transforma_romano("CD")); //Dado a entrada "CD", espera-se obter o retorno "400"
	EXPECT_EQ (500, transforma_romano("D")); //Dado a entrada "D", espera-se obter o retorno "500"
	EXPECT_EQ (572, transforma_romano("DLXXII")); //Dado a entrada "DLXXII", espera-se obter o retorno "572"
	EXPECT_EQ (669, transforma_romano("DCLXIX")); //Dado a entrada "DCLXIX", espera-se obter o retorno "669"
	EXPECT_EQ (882, transforma_romano("DCCCLXXXII")); //Dado a entrada "DCCCLXXXII", espera-se obter o retorno "882"
	EXPECT_EQ (899, transforma_romano("DCCCXCIX")); //Dado a entrada "DCCCXCIX", espera-se obter o retorno "899"
}

/** \brief Teste realizado para alguns números entre 900 e 3000*/
TEST(TestaROMANO, Thousands){
	EXPECT_EQ (900, transforma_romano("CM")); //Dado a entrada "CM", espera-se obter o retorno "900"
	EXPECT_EQ (1032, transforma_romano("MXXXII")); //Dado a entrada "MXXXII", espera-se obter o retorno "1032"
	EXPECT_EQ (1500, transforma_romano("MD")); //Dado a entrada "MD", espera-se obter o retorno "1500"
	EXPECT_EQ (1869, transforma_romano("MDCCCLXIX")); //Dado a entrada "MDCCCLXIX", espera-se obter o retorno "1869"
	EXPECT_EQ (2049, transforma_romano("MMXLIX")); //Dado a entrada "MMXLIX", espera-se obter o retorno "2049"
	EXPECT_EQ (2204, transforma_romano("MMCCIV")); //Dado a entrada "MMCCIV", espera-se obter o retorno "2204"
}

/** \brief Teste realizado para números inválidos*/
TEST(TestaROMANO, Invalid_Operands){
	ASSERT_EQ (-1, transforma_romano("IIII")); //Dado a entrada "IIII", espera-se obter o retorno "-1"
	EXPECT_EQ (-1, transforma_romano("IC")); //Dado a entrada "IC", espera-se obter o retorno "-1"
	EXPECT_EQ (-1, transforma_romano("IL")); //Dado a entrada "IL", espera-se obter o retorno "-1"
	EXPECT_EQ (-1, transforma_romano("ID")); //Dado a entrada "ID", espera-se obter o retorno "-1"
	EXPECT_EQ (-1, transforma_romano("IM")); //Dado a entrada "IM", espera-se obter o retorno "-1"
	EXPECT_EQ (-1, transforma_romano("VX")); //Dado a entrada "VX", espera-se obter o retorno "-1"
	EXPECT_EQ (-1, transforma_romano("VL")); //Dado a entrada "VL", espera-se obter o retorno "-1"
	EXPECT_EQ (-1, transforma_romano("VC")); //Dado a entrada "VC", espera-se obter o retorno "-1"
	EXPECT_EQ (-1, transforma_romano("VVVV")); //Dado a entrada "VVVV", espera-se obter o retorno "-1"
	EXPECT_EQ (-1, transforma_romano("XD")); //Dado a entrada "XD", espera-se obter o retorno "-1"
	EXPECT_EQ (-1, transforma_romano("XXXX")); //Dado a entrada "XXXX", espera-se obter o retorno "-1"
	EXPECT_EQ (-1, transforma_romano("LD")); //Dado a entrada "LD", espera-se obter o retorno "-1"
	EXPECT_EQ (-1, transforma_romano("LL")); //Dado a entrada "LL", espera-se obter o retorno "-1"
	EXPECT_EQ (-1, transforma_romano("DM")); //Dado a entrada "DM", espera-se obter o retorno "-1"
	EXPECT_EQ (-1, transforma_romano("CCCC")); //Dado a entrada "CCCC", espera-se obter o retorno "-1"
	EXPECT_EQ (-1, transforma_romano("MMMM"));	 //Dado a entrada "MMMM", espera-se obter o retorno "-1"
}





int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

