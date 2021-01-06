#pragma once

#include <string>
#include <vector>

#include "../Cmr/Cmr.h"

using namespace Core::Cmr::Types;
using namespace Core::Cmr::ExtendedTypes;

namespace Core
{
	class Memory
	{
		Public 
		Public struct SignatureElement
		{
			Public byte Value;
			Public bool Ignore;
			Public SignatureElement(byte, bool);
		};
		Public struct Signature
		{
			Public Vector<SignatureElement> Bytes;
			Public int GetLength();
			Public bool HasValue();
			Public Signature(Vector<SignatureElement>);
			Public Signature(Vector<SignatureElement>&);
			Public Signature(string);
		};
		Public static Ptr FindSignature(string);
		Public static Ptr FindSignature(Memory::Signature);
	};
}