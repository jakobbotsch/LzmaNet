#include "Stdafx.hpp"

#pragma managed
#include "LzmaException.hpp"
#include "LzmaError.hpp"

using namespace LzmaNet;
LzmaError LzmaException::Error::get()
{
	return _error;
}