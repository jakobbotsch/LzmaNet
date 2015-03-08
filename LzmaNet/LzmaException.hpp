#pragma once

namespace LzmaNet
{
	enum class LzmaError;

	public ref class LzmaException : System::Exception
	{
	private:
		LzmaError _error;
	public:
		LzmaException(System::String^ message, LzmaError error) : System::Exception(message)
		{
			_error = error;
		}

		property LzmaError Error { LzmaError get(); }
	};
}