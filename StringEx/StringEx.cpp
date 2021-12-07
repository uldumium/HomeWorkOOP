#include "StringEx.h"

StringEx::StringEx()
{
	// ����������� nullptr
	StringEx::str = nullptr;
}

StringEx::StringEx( const char* other )
{
	// ������ ������, � ������� ����� ������ ��������
	StringEx::clearObj();

	// ������ ����� ������� other
	int thisLength = getMyLength( other );

	// �������� ������������ ������ ��� ������� Str, ������� ����� ����� ������� other + ONE (������������ ����)
	StringEx::str = new char[ thisLength + ONE ]; // One ����� ��� ������������� ����

	// ���� ���������� ��������� ������� �������, �������
	for(int i = 0; i < thisLength; i++)
	{
		StringEx::str[ i ] = other[ i ];
	}

	// ����������� ���������� �������� ������� ������������ ����, ������� ���������� ����� ������
	StringEx::str[ thisLength ] = '\0';
}

StringEx::StringEx( const StringEx& other )
{
	// � ������� ���������� ��������� �����, �������� ������ ������ � ������
	*this = other;
}

void StringEx::clearObj()
{
	// �������� �� ������� ������ � ������, ���� ��� ����, �� ������ ������������ ������, ���������� ��� ������� � ����������� nullptr
	if(nullptr != StringEx::str)
	{
		delete[] StringEx::str;

		StringEx::str = nullptr;
	}
}

StringEx* StringEx::split( const char delimiter , int& count )
{
	// ������� �������� ��� ������
	int counterSubstring = 1; // ������� ����
	int bufferCounter = 0; // ������� ����� ���������
	int counterBufferArray = 0; // ������� ��������

	// ����, � ������� �������� ������ ������� ����������� � ����� �������
	for(int i = 0; StringEx::str[ i ] != '\0'; i++)
	{
		if(delimiter == str[ i ])
		{
			counterSubstring++; // ���� ����������� ������ ���� ������������ ����, ����������� �������
		}
	}

	// ������� ������ �������� ������ StringEx
	StringEx* bufferArray = new StringEx[ counterSubstring ];

	// ���������� ������� �������� ����� ������� ����� ��������, ������� �� ����� ��������� �� ����������
	int thisLength = getMyLength( StringEx::str );

	// ������� ����, ������� ���� �� ����� ������ �������, ������� �� ����� ������� �� ����������
	for(int i = 0; i < thisLength + 1; i++)
	{
		if(delimiter != str[ i ] && '\0' != str[ i ]) // ������� �� �������� ������� ����� ����������
		{
			bufferCounter++;
		}
		else
		{
			StringEx bufferOne; // ������� ������

			bufferOne.str = new char[ bufferCounter + ONE ]; // �������� ������� ������ ��� ���� + ������������ ����

			for(int j = i - bufferCounter , o = 0; j < i; j++ , o++) // ���� ����������� ���������� � ����� ������
			{
				bufferOne.str[ o ] = StringEx::str[ j ];
			}

			bufferOne.str[ bufferCounter ] = '\0'; // ����������� ���������� ��������� ������� ������������ ����

			bufferArray[ counterBufferArray ] = bufferOne; // ������� �������, ����������� ������

			counterBufferArray++; // ����������� ������� ������� ��������

			bufferCounter = 0; // �������� ������� ����� ���������
		}
	}

	count = counterSubstring;

	// ��������� ������ �������� ������ StringEx
	return bufferArray;
}

void StringEx::insert( const char* subArray , const int index )
{
	// ��������� ������������ ����� �����
	int thisLength = getMyLength( StringEx::str );
	int subArrayLength = getMyLength( subArray );
	int newBufferLength = thisLength + subArrayLength;

	// ����� ������������
	StringEx bufferStringEx;

	// �������� ������ ��� ����� ������ + ��� ������������� ����
	bufferStringEx.str = new char[ newBufferLength + ONE ];

	// ���� �� ����� ����� �������
	for(int i = 0 , k = 0; i < newBufferLength; i++ , k++)
	{
		if(index == i) // ���� i-��� ����� ����� ������ �������, ������� �� ��������, ����������� ����, ������� ��������� ��������� ������
		{
			for(int j = 0; j < subArrayLength; j++)
			{
				bufferStringEx.str[ k++ ] = subArray[ j ];
			}
		}

		// �������� � ������������ ������ ��������� �������
		bufferStringEx.str[ k ] = StringEx::str[ i ];
	}

	// ����������� ���������� �������� ������������ ���������� ����
	bufferStringEx.str[ newBufferLength ] = '\0';

	// ������ ������ ������� ��������
	StringEx::clearObj();

	// ����������� ������ ������� ������� ������ ��� ������ ���������� ���������
	*this = bufferStringEx;
}

bool StringEx::contains( const char* other ) const
{
	// ������ ����� ������ � ������� ���� � ����� ���������
	int thisLength = getMyLength( StringEx::str );
	int otherLength = getMyLength( other );

	// ������� ����, � ������� �������� ����� ������ ���������
	bool flag = false;

	// �������� ����, ������� ���� �� ����� ������, � ������� �� ���� ���������
	for(int i = 0; i < thisLength; i++)
	{
		// ���� ���� ���������� , ��������� ����, ������� ���� �� ����� ����� ���������
		// ���� ��������� ��������� �������� �� �������, � ������� ����, ���� ������ flag - true
		if(StringEx::str[ i ] == other[ 0 ])
		{
			for(int j = 0 , k = i; j < otherLength; j++ , k++)
			{
				if(StringEx::str[ k ] == other[ j ])
					flag = true;
				else flag = false;
			}
			// ���� ���� true, �� �� ����� ���������
			if(true == flag)
				return true;
		}
	}

	return false;
}

StringEx::~StringEx()
{
	// ������� ������������ ������ ��� ����� ����� �������
	delete[] StringEx::str;
}

StringEx StringEx::operator+( const StringEx& right )
{
	// ������� ������ ����� ������
	StringEx bufferString;

	// ������ ������� ���� �����, ������� �� ����� �������
	int thisLength = getMyLength( StringEx::str );
	int rightLength = getMyLength( right.str );

	// �������� ������ ��� ����� ������, ����� ������ ������ + ����� ������ ������ + ONE ( ��� ��� ������������� ����)
	bufferString.str = new char[ thisLength + rightLength + ONE ];

	//������� ��� �������
	int k = 0;

	// ��� �����, ������� ���������� ���� �� �������� � ������
	for(int i = 0; i < thisLength; i++)
	{
		bufferString.str[ k++ ] = StringEx::str[ i ];
	}
	for(int i = 0; i < rightLength; i++)
	{
		bufferString.str[ k++ ] = right.str[ i ];
	}

	// ����������� ���������� �������� ������� ������������ ����, ������� ���������� ����� ������
	bufferString.str[ thisLength + rightLength ] = '\0';

	// ��������� ������
	return bufferString;
}

StringEx& StringEx::operator=( const StringEx& other )
{
	// ������ ������
	StringEx::clearObj();

	// ������ ������ ������� other
	int length = getMyLength( other.str );

	// �������� ������ ��� ����� ������, ����� ������ ������ + ONE ( ��� ��� ������������� ����)
	StringEx::str = new char[ length + ONE ];

	// ���� ���������� ��������� ������� other � str
	for(int i = 0; i < length; i++)
	{
		StringEx::str[ i ] = other.str[ i ];
	}

	// ����������� ���������� �������� ������� ������������ ����, ������� ���������� ����� ������
	StringEx::str[ length ] = '\0';

	// ��������� ��� ���������� ������
	return *this;
}

std::ostream& operator<<( std::ostream& outPut , const StringEx& other )
{
	// ������ ������ ������� other
	int length = getMyLength( other.str );

	// ����, � �������, � ������ outPut ���������� �������� ������� other
	for(int i = 0; i < length; i++)
	{
		outPut << other.str[ i ];
	}

	// ��������� ������
	return outPut;
}