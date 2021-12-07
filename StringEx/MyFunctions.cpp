#include "MyFunctions.h"

int getMyLength( const char* other )
{
	int length = 0;

	if(nullptr != other)
	{
		for(int i = 0; other[ i ] != '\0'; i++)
		{
			length++;
		}
	}

	return length;
}
