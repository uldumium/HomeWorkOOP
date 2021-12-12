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

	// Конструктор по умолчанию
	AssociativeArray();

	// Конструктор копирования
	AssociativeArray(const AssociativeArray &right);

#pragma endregion

#pragma region RELOAD OPERATORS

	// Перегрузка оператора индексации
	void operator[]( TKey key );

	// Перегрузка оператора присваивания
	AssociativeArray& operator= (const AssociativeArray &right);

	// Перегрузка оператора сравнения
	void operator==( AssociativeArray& right );

#pragma endregion

#pragma region GETTERS

	// Получение ключа по индексу
	TKey getKey( int index );

	// Получение значения по индексу
	DValue getValue( int index );

	// Получение кол-ва элементов в списке
	size_t getSize();

#pragma endregion

#pragma region METHODS

	// Вставить новый элемент в список
	void put( TKey key , DValue value );

	// Задать новое значение по ключу в списке
	void newValue( TKey key , DValue value );

	// Поиск значения по ключу
	void searchValue( TKey key );

	// Поиск ключа в списке
	void searchKey( TKey key );

#pragma endregion

private:

	// Статический массив ключей
	TKey key[ SIZE ];

	// Статический массив значений
	DValue value[ SIZE ];

	// Кол-во элементов в списке
	size_t size;

	// Размер списка
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
		else std::cout << "В списке нет веденного ключа\n";
	}
	else
	{
		std::cout << "Список пуст\n";
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
			std::cout << GREEN_TEXT << "Списки равны\n" << DEFAULT_TEXT;
		else std::cout << RED_TEXT << "Списки не равны!\n" << DEFAULT_TEXT;
	}
	else
	{
		std::cout << RED_TEXT << "Списки не равны!\n" << DEFAULT_TEXT;
	}
}

template<typename TKey , typename DValue , size_t SIZE>
void AssociativeArray<TKey , DValue , SIZE>::put( TKey key , DValue value )
{
	if(AssociativeArray::size == AssociativeArray::capasity)
	{
		std::cout << "Нет места" << std::endl;
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
		std::cout << counter << " key были изменены\n";
	else
		std::cout << key << " - ключа не был найден\n";
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
		std::cout << "Найдено " << counter << " value по ключу " << key << std::endl;

		for(int i = 0; i < AssociativeArray::size; i++)
		{
			if(key == AssociativeArray::key[ i ])
				std::cout << AssociativeArray::value[ i ] << " ";
		}

		std::cout << std::endl;
	}
	else
	{
		std::cout << "Найдено " << counter << " value по ключу " << key << std::endl;
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
		std::cout << key << " - ключ найден\n";
	else std::cout << key << " - ключ не найден\n";
}