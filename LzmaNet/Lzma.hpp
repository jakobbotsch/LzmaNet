#pragma once

namespace LzmaNet
{
	ref class LzmaProperties;

	public ref class Lzma abstract sealed
	{
	private:
		static void CheckLzmaCode(System::String^ operation, int code);

	public:
		literal int PropertiesSize = LZMA_PROPS_SIZE;

		static void Uncompress(
			array<System::Byte>^ source, int sourceIndex, int% sourceCount,
			array<System::Byte>^ dest, int destIndex, int% destCount,
			array<System::Byte>^ props, int propsIndex, int propsCount);

		static void Compress(
			array<System::Byte>^ source, int sourceIndex, int sourceCount,
			array<System::Byte>^ dest, int destIndex, int% destCount,
			array<System::Byte>^ outProps, int outPropsIndex, int% outPropsCount,
			LzmaProperties^ properties);
	};
}
