#include "stdafx.hpp"

#pragma managed
#include "Lzma.hpp"
#include "LzmaException.hpp"
#include "LzmaProperties.hpp"
#include "LzmaError.hpp"

using namespace System;
using namespace LzmaNet;

#define CheckNull(o) if ((o) == nullptr) throw gcnew ArgumentNullException(#o);

#define CheckBounds(arr, index, count) do { if ((arr) == nullptr) throw gcnew ArgumentNullException(#arr); \
	if ((index) < 0 || (index) > (arr)->Length) throw gcnew ArgumentOutOfRangeException(#index); \
	if ((count) < 0 || (index) + (count) > (arr)->Length) throw gcnew ArgumentOutOfRangeException(#count); } while (false)

void Lzma::CheckLzmaCode(System::String^ operation, int code)
{
	if (code == SZ_OK)
		return;

	LzmaError error = static_cast<LzmaError>(code);
	throw gcnew LzmaException(operation + " failed with error " + error.ToString(), error);
}

void Lzma::Uncompress(
	array<System::Byte>^ source, int sourceIndex, int% sourceCount,
	array<System::Byte>^ dest, int destIndex, int% destCount,
	array<System::Byte>^ props, int propsIndex, int propsCount)
{
	CheckBounds(source, sourceIndex, sourceCount);
	CheckBounds(dest, destIndex, destCount);
	CheckBounds(props, propsIndex, propsCount);

	pin_ptr<unsigned char> pSource = sourceCount > 0 ? &source[sourceIndex] : nullptr;
	pin_ptr<unsigned char> pDest = destCount > 0 ? &dest[destIndex] : nullptr;
	pin_ptr<unsigned char> pProps = propsCount > 0 ? &props[propsIndex] : nullptr;

	SizeT srcLen = static_cast<SizeT>(sourceCount);
	size_t destLen = static_cast<size_t>(destCount);
	int code = LzmaUncompress(pDest, &destLen, pSource, &srcLen, pProps, static_cast<size_t>(propsCount));

	sourceCount = static_cast<int>(srcLen);
	destCount = static_cast<int>(destLen);

	CheckLzmaCode("Uncompress", code);
}

void Lzma::Compress(
	array<System::Byte>^ source, int sourceIndex, int sourceCount,
	array<System::Byte>^ dest, int destIndex, int% destCount,
	array<System::Byte>^ outProps, int outPropsIndex, int% outPropsCount,
	LzmaProperties^ properties)
{
	CheckBounds(source, sourceIndex, sourceCount);
	CheckBounds(dest, destIndex, destCount);
	CheckBounds(outProps, outPropsIndex, outPropsCount);
	CheckNull(properties);

	pin_ptr<unsigned char> pSource = sourceCount > 0 ? &source[sourceIndex] : nullptr;
	pin_ptr<unsigned char> pDest = destCount > 0 ? &dest[destIndex] : nullptr;
	pin_ptr<unsigned char> pOutProps = outPropsCount > 0 ? &outProps[outPropsIndex] : nullptr;

	size_t destLen = static_cast<size_t>(destCount);
	size_t outPropsSize = static_cast<size_t>(outPropsCount);

	int code = LzmaCompress(pDest, &destLen, pSource, static_cast<size_t>(sourceCount),	pOutProps, &outPropsSize,
		properties->Level, 
		properties->DictSize, 
		properties->LiteralContextBits,
		properties->LiteralPosBits, 
		properties->PosBits, 
		properties->WordSize, 
		properties->NumThreads);

	destCount = static_cast<int>(destLen);
	outPropsCount = static_cast<int>(outPropsSize);

	CheckLzmaCode("Compress", code);
}