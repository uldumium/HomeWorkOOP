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

StringEx* StringEx::split( const char delimiter )
{
	int counterSubstring = 1;
	int bufferCounter = 0;
	int counterBufferArray = 0;

	for(int i = 0; StringEx::str[i] != '\0'; i++)
	{
		if(delimiter == str[ i ])
		{
			counterSubstring++;
		}
	}
	
	StringEx* bufferArray = new StringEx[ counterSubstring ];
	int thisLength = getMyLength( StringEx::str );

	for(int i = 0; i < thisLength+1; i++)
	{
		if(delimiter != str[ i ] && '\0' != str[i])
		{
			bufferCounter++;
		}
		else
		{
			StringEx bufferOne;

			bufferOne.str = new char[ bufferCounter + ONE];

			for(int j = i - bufferCounter, o = 0; j < i; j++,o++)
			{
				bufferOne.str[ o ] = StringEx::str[ j ];
			}

			bufferOne.str[ bufferCounter ] = '\0';

			bufferArray[ counterBufferArray ] = bufferOne;

			counterBufferArray++;

			bufferCounter = 0;
		}
	}

	return bufferArray;
}

char* StringEx::getStr() const
{
	return str;
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

bool StringEx::operator!=( const char other )
{
	for(int i = 0; i < getMyLength(StringEx::str); i++)
	{
		if('\0' != StringEx::str[ i ])
			return false;
		return true;
	}
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
