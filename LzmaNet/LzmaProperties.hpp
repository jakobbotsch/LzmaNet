#pragma once

namespace LzmaNet
{
	public ref class LzmaProperties
	{
	public:
		LzmaProperties();

		property unsigned DictSize;
		property int Level;
		property int LiteralContextBits;
		property int LiteralPosBits;
		property int PosBits;
		property int WordSize;
		property int NumThreads;
	};
}