/*
 * multibyte_test.cpp
 *
 *  Created on: 2014/07/27
 *      Author: shu
 */

#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <stdint.h>

#include "../src/multibyte.h"
using namespace std;

TEST(MultiByteTest, Length) {
	typedef mutibyte::MultiByte<char, 8> TestMultiByte;
	EXPECT_EQ(8, TestMultiByte::kLength);
}

TEST(MultiByteTest, Value) {
	typedef mutibyte::MultiByte<char, 8> TestMultiByte;
	string str = string("!!!Hello World!!!");
	vector<TestMultiByte> str_multibyte((str.size() + TestMultiByte::kLength - 1)/TestMultiByte::kLength);
	memcpy((char *)&str_multibyte[0], &str[0], sizeof(str[0])*str.size());

	size_t str_i = 0;
	for (size_t i = 0; i < str_multibyte.size() && str_i < str.size(); ++i) {
		TestMultiByte &m = str_multibyte[i];
		for (size_t value_i = 0; value_i < TestMultiByte::kLength && str_i < str.size(); ++value_i, ++str_i) {
			EXPECT_EQ(str[str_i], m.value[value_i]);
		}
	}
}


