#include "Stdafx.hpp"

#pragma managed
#include "LzmaProperties.hpp"

using namespace LzmaNet;

LzmaProperties::LzmaProperties()
{
	DictSize = 0;
	Level = -1;
	LiteralContextBits = -1;
	LiteralPosBits = -1;
	PosBits = -1;
	WordSize = -1;
	NumThreads = -1;
}