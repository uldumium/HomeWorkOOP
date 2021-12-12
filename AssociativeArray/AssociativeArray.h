#pragma once
#include <iostream>

#define RED_TEXT "\033[1;31m"
#define GREEN_TEXT "\033[1;32m"
#define DEFAULT_TEXT "\033[1;0m"


template <typename TKey , typename DValue , size_t SIZE>
class AssociativeArray
{
public:
#pragma region CONSTRUCTORS

	// ����������� �� ���������
	AssociativeArray();

	// ����������� �����������
	AssociativeArray(const AssociativeArray &right);

#pragma endregion

#pragma region RELOAD OPERATORS

	// ���������� ��������� ����������
	void operator[]( TKey key );

	// ���������� ��������� ������������
	AssociativeArray& operator= (const AssociativeArray &right);

	// ���������� ��������� ���������
	void operator==( AssociativeArray& right );

#pragma endregion

#pragma region GETTERS

	// ��������� ����� �� �������
	TKey getKey( int index );

	// ��������� �������� �� �������
	DValue getValue( int index );

	// ��������� ���-�� ��������� � ������
	size_t getSize();

#pragma endregion

#pragma region METHODS

	// �������� ����� ������� � ������
	void put( TKey key , DValue value );

	// ������ ����� �������� �� ����� � ������
	void newValue( TKey key , DValue value );

	// ����� �������� �� �����
	void searchValue( TKey key );

	// ����� ����� � ������
	void searchKey( TKey key );

#pragma endregion

private:

	// ����������� ������ ������
	TKey key[ SIZE ];

	// ����������� ������ ��������
	DValue value[ SIZE ];

	// ���-�� ��������� � ������
	size_t size;

	// ������ ������
	int capasity = SIZE;
};

template<typename TKey , typename DValue , size_t SIZE>
AssociativeArray<TKey , DValue , SIZE>::AssociativeArray()
{
	AssociativeArray::capasity = SIZE;
	AssociativeArray::size = 0;
}

template<typename TKey , typename DValue , size_t SIZE>
AssociativeArray<TKey , DValue , SIZE>::AssociativeArray( const AssociativeArray& right )
{
	*this = right;
}

template<typename TKey , typename DValue , size_t SIZE>
void AssociativeArray<TKey , DValue , SIZE>::operator[]( TKey key )
{
	if(0 < AssociativeArray::size)
	{
		int buffer = 0;

		for(int i = 0; i < AssociativeArray::size; i++)
		{
			if(key == AssociativeArray::key[ i ])
			{
				buffer = i;
			}
		}

		if(0 <= buffer)
			std::cout << AssociativeArray::key[ buffer ] << " " << AssociativeArray::value[ buffer ] << std::endl;
		else std::cout << "� ������ ��� ��������� �����\n";
	}
	else
	{
		std::cout << "������ ����\n";
	}
}

template<typename TKey , typename DValue , size_t SIZE>
AssociativeArray<TKey , DValue , SIZE>& AssociativeArray<TKey , DValue , SIZE>::operator=( const AssociativeArray &right )
{
	AssociativeArray::capasity = right.capasity;
	AssociativeArray::size = right.size;

	for(int i = 0; i < right.size; i++)
	{
		AssociativeArray::key[ i ] = right.key[ i ];
		AssociativeArray::value[ i ] = right.value[ i ];
	}

	return *this;
}

template<typename TKey , typename DValue , size_t SIZE>
void AssociativeArray<TKey , DValue , SIZE>::operator==( AssociativeArray& right )
{
	bool flagKey = false;
	bool flagValue = false;

	if(right.size == AssociativeArray::size)
	{
		for(int i = 0; i < right.size; i++)
		{
			if(AssociativeArray::key[ i ] == right.key[ i ])
				flagKey = true;

			if(AssociativeArray::value[ i ] == right.value[ i ])
				flagValue = true;
		}
		if(flagKey && flagValue == true)
			std::cout << GREEN_TEXT << "������ �����\n" << DEFAULT_TEXT;
		else std::cout << RED_TEXT << "������ �� �����!\n" << DEFAULT_TEXT;
	}
	else
	{
		std::cout << RED_TEXT << "������ �� �����!\n" << DEFAULT_TEXT;
	}
}

template<typename TKey , typename DValue , size_t SIZE>
void AssociativeArray<TKey , DValue , SIZE>::put( TKey key , DValue value )
{
	if(AssociativeArray::size == AssociativeArray::capasity)
	{
		std::cout << "��� �����" << std::endl;
	}
	else
	{
		AssociativeArray::key[ size ] = key;
		AssociativeArray::value[ size ] = value;
		++size;
	}
}

template<typename TKey , typename DValue , size_t SIZE>
TKey AssociativeArray<TKey , DValue , SIZE>::getKey( int index )
{
	return AssociativeArray::key[ index ];
}

template<typename TKey , typename DValue , size_t SIZE>
DValue AssociativeArray<TKey , DValue , SIZE>::getValue( int index )
{
	return AssociativeArray::value[ index ];
}

template<typename TKey , typename DValue , size_t SIZE>
size_t AssociativeArray<TKey , DValue , SIZE>::getSize()
{
	return AssociativeArray::size;
}

template<typename TKey , typename DValue , size_t SIZE>
void AssociativeArray<TKey , DValue , SIZE>::newValue( TKey key , DValue value )
{
	int counter = 0;

	bool flag = false;

	for(int i = 0; i < AssociativeArray::size; i++)
	{
		if(AssociativeArray::key[ i ] == key)
		{
			AssociativeArray::value[ i ] = value;

			flag = true;

			counter++;
		}
	}
	if(flag == true)
		std::cout << counter << " key ���� ��������\n";
	else
		std::cout << key << " - ����� �� ��� ������\n";
}

template<typename TKey , typename DValue , size_t SIZE>
void AssociativeArray<TKey , DValue , SIZE>::searchValue( TKey key )
{
	int counter = 0;

	for(int i = 0; i < AssociativeArray::size; i++)
	{
		if(key == AssociativeArray::key[ i ])
			counter++;
	}
	if(0 != counter)
	{
		std::cout << "������� " << counter << " value �� ����� " << key << std::endl;

		for(int i = 0; i < AssociativeArray::size; i++)
		{
			if(key == AssociativeArray::key[ i ])
				std::cout << AssociativeArray::value[ i ] << " ";
		}

		std::cout << std::endl;
	}
	else
	{
		std::cout << "������� " << counter << " value �� ����� " << key << std::endl;
	}
}

template<typename TKey , typename DValue , size_t SIZE>
void AssociativeArray<TKey , DValue , SIZE>::searchKey( TKey key )
{
	bool flag = false;

	for(int i = 0; i < AssociativeArray::size; i++)
	{
		if(key == AssociativeArray::key[ i ])
		{
			flag = true;
		}
	}
	if(flag == true)
		std::cout << key << " - ���� ������\n";
	else std::cout << key << " - ���� �� ������\n";
}