#pragma once

namespace LzmaNet
{
	public enum class LzmaError
	{
		Data = SZ_ERROR_DATA,
		Memory = SZ_ERROR_MEM,
		Parameter = SZ_ERROR_PARAM,
		InputEof = SZ_ERROR_INPUT_EOF,
		OutputEof = SZ_ERROR_OUTPUT_EOF,
		Thread = SZ_ERROR_THREAD,
	};
}