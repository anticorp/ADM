#include "TypeContainers.h"

namespace adm
{
	namespace _
	{
		DblContainer::DblContainer(const double _inDouble)
			:	number(_inDouble)
		{
		}
		DblContainer::operator double()
		{
			return number;
		}
	}
}