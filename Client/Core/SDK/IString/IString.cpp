#include "IString.h"

void Core::SDK::IString::SetText(string s)
{
	Clear();
	UInt64 size = s.size();
	this->AllocatedLength = size | 15;
	if (size < 16) strcpy_s(InlineText, 16, s.c_str());
	else
	{
		char* ptr = (char*)malloc(AllocatedLength + 5);
		if (ptr != nullptr) strcpy_s(ptr, size + 1, s.c_str());
		else
		{
			Length = 0;
			AllocatedLength = 15;
			goto ret;
		}
		Length = size;
		AllocatedLength += 5;
	}
ret:
	return;
}
char* Core::SDK::IString::GetText()
{
	if (AllocatedLength < 16) return this->InlineText;
	else return this->TextPointer;
}
UInt64 Core::SDK::IString::GetLength()
{
	return Length;
}
UInt64 Core::SDK::IString::GetAllocatedLength()
{
	return AllocatedLength;
}
void Core::SDK::IString::Reset()
{
	memset(this, 0, sizeof(IString));
}
void Core::SDK::IString::Clear()
{
	if (AllocatedLength >= 16 && TextPointer != nullptr)
	{
		free(TextPointer);
	}
	memset(this, 0, sizeof(IString));
}
bool Core::SDK::IString::IsEmpty()
{
	if (Length == 0) return true;
	else return false;
}
bool Core::SDK::IString::IsPointer()
{
	if (Length > 16) return false;
	else return true;
}
Core::SDK::IString::IString()
{

}
Core::SDK::IString::IString(string text)
{
	SetText(text);
}
Core::SDK::IString::IString(void* textptr, UInt64 textlength)
{

}
Core::SDK::IString::~IString()
{
	if (Length >= 16 && TextPointer != nullptr)
	{
		free(TextPointer);
	}
}