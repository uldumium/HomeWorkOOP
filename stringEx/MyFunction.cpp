#include "MyFunction.h"

int LengthEx( const char* str )
{
	int length = 0;

	for(int i = 0; '\0' != str[ i ]; i++)
	{
		length++;
	}

	return length;
}
