/*
 * multibyte.h
 *
 *  Created on: 2014/07/27
 *      Author: shu
 */

#pragma once

namespace mutibyte {

template <typename T,size_t TLength>
struct MultiByte {
	typedef T Type;
	static const size_t kLength;
	static const size_t kByteSize;
	T value[TLength];
};

template <typename T,size_t TLength>
const size_t MultiByte<T, TLength>::kLength = TLength;

template <typename T,size_t TLength>
const size_t MultiByte<T, TLength>::kByteSize = sizeof(T)*TLength;

}

