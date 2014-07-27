/*
 * multibyte_test.cpp
 *
 * Copyright (c) 2014, Shuji SUZUKI
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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


