#include "Memory.h"

// Unresolved Externals Fix
namespace Static
{
    static bool IsInRangeByte(Byte x, Byte min, Byte max) { return x >= min && x <= max; }
    static byte CharToByteHex(char value)
    {
        unsigned char ret = 0;
        if (value >= '0' && value <= '9')
        {
            ret = value - '0';
            return ret;
        }
        if (value >= 'A' && value <= 'F')
        {
            ret = value - 'A' + 0xA;
            return ret;
        }
        std::string exception_message = "";
        exception_message += "Could not convert ";
        exception_message += value;
        exception_message += " into a byte.";
        throw new std::exception(exception_message.c_str());
    }
}

Core::Memory::SignatureElement::SignatureElement(byte value, bool ignore = false)
{
    Value = value;
    Ignore = ignore;
}
int Core::Memory::Signature::GetLength() 
{ 
    return Bytes.size(); 
}
bool Core::Memory::Signature::HasValue()
{
    for (auto s : Bytes)
    {
        if (!s.Ignore)
            return true;
    }
    return false;
}
Core::Memory::Signature::Signature(string value)
{
    Vector<SignatureElement> bytes;
    for (int i = 0; i < value.length(); i++)
    {
        // _
        if (value[i] == ' ')
            continue;
        // ..
        if ((i + 1) > value.length())
        {
            // ??
            if (value[i] == '?' && value[i + 1] == '?')
            {
                bytes.push_back(SignatureElement(0, true));
                i++;
                continue;
            }
            // ?
            if (value[i] == '?')
            {
                bytes.push_back(SignatureElement(0, true));
                continue;
            }
            // XX
            if ((Static::IsInRangeByte(value[i], '0', '9') || Static::IsInRangeByte(value[i], 'A', 'F'))
                && (Static::IsInRangeByte(value[i + 1], '0', '9') || Static::IsInRangeByte(value[i + 1], 'A', 'F')))
            {
                bytes.push_back(SignatureElement(Static::CharToByteHex(value[i]) << 4 | Static::CharToByteHex(value[i + 1])));
                i++;
                continue;
            }
            // X.
            if (Static::IsInRangeByte(value[i], '0', '9') || Static::IsInRangeByte(value[i], 'A', 'F'))
            {
                bytes.push_back(SignatureElement(Static::CharToByteHex(value[i])));
                continue;
            }
        }
        // ?
        if (value[i] == '?')
        {
            bytes.push_back(SignatureElement(0, true));
            continue;
        }
        // X
        if (Static::IsInRangeByte(value[i], '0', '9') || Static::IsInRangeByte(value[i], 'A', 'F'))
        {
            bytes.push_back(SignatureElement(Static::CharToByteHex(value[i])));
            continue;
        }
    }
    Bytes = bytes;
}
Core::Memory::Signature::Signature(Vector<SignatureElement> bytes)
{
    Bytes = bytes;
}
Core::Memory::Signature::Signature(Vector<SignatureElement>& bytes)
{
    Bytes = bytes;
}
Ptr Core::Memory::FindSignature(string value)
{
    return FindSignature(Signature(value));
}
Ptr Core::Memory::FindSignature(Signature signature)
{
    if (!signature.HasValue()) return null;

    Ptr FirstMatch = null;
    Ptr StartAddress = 0;
    Ptr EndAddress = 0;
    Char FirstByte = signature.Bytes[0].Value;
    for (Ptr CurrentAddress = StartAddress; CurrentAddress < EndAddress; CurrentAddress++)
    {
        try
        {
            if ((c_byte CurrentAddress == FirstByte) && ((CurrentAddress + signature.GetLength()) < EndAddress))
            {
                bool result = true;
                for (int i = CurrentAddress + 1; i < CurrentAddress + signature.GetLength(); i++)
                {
                    if (!signature.Bytes[i - CurrentAddress].Ignore)
                    {
                        if (signature.Bytes[i - CurrentAddress].Value == c_byte i) continue;
                        else
                        {
                            result = false;
                            break;
                        }
                    }
                }
                if (result)
                    return CurrentAddress;
            }
        }
        catch (...) { return null; }
    }
    return null;
}
