#include "StringEx.h"

StringEx::StringEx()
{
	// Присваиваем nullptr
	StringEx::str = nullptr;
}

StringEx::StringEx( const char* other )
{
	// Чистим объект, в который хотим внести значения
	StringEx::clearObj();

	// Узнаем длину массива other
	int thisLength = getMyLength( other );

	// Выделяем динамическую память для массива Str, которая равна длине массива other + ONE (терминальный нуль)
	StringEx::str = new char[ thisLength + ONE ]; // One нужен для Терминального нуля

	// Цикл присвоения елементов второго массива, первому
	for(int i = 0; i < thisLength; i++)
	{
		StringEx::str[ i ] = other[ i ];
	}

	// Присваиваем последнему элементу массива терминальный нуль, который обозначает конец строки
	StringEx::str[ thisLength ] = '\0';
}

StringEx::StringEx( const StringEx& other )
{
	// С помощью перегрузки оператора равно, копируем второй обьект в первый
	*this = other;
}

void StringEx::clearObj()
{
	// Проверка на наличие данных в оъекте, если они есть, но чистим динамическую память, выделенную для массива и присваиваем nullptr
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
	// Очистка динамической памяти при конце жизни объекта
	delete[] StringEx::str;
}

StringEx StringEx::operator+( const StringEx& right )
{	
	// Создаем буффер нашей строки
	StringEx bufferString;

	// Узнаем размеры двух строк, который мы хотим склеить
	int thisLength = getMyLength( StringEx::str );
	int rightLength = getMyLength( right.str );
	
	// Выделяем память для нашей строки, длина первой строки + длина второй строки + ONE ( это для терминального нуля)
	bufferString.str = new char[ thisLength + rightLength + ONE ];

	//Счетчик для буффера
	int k = 0;

	// Два цикла, которые закидывают чары из массивов в буффер
	for(int i = 0; i < thisLength; i++)
	{
		bufferString.str[ k++ ] = StringEx::str[ i ];
	}
	for(int i = 0; i < rightLength; i++)
	{
		bufferString.str[ k++ ] = right.str[ i ];
	}

	// Присваиваем последнему элементу массива терминальный нуль, который обозначает конец строки
	bufferString.str[ thisLength + rightLength ] = '\0';

	// Возращаем объект
	return bufferString;
}

StringEx& StringEx::operator=( const StringEx& other )
{
	// Чистим объект
	StringEx::clearObj();

	// Узнаем длинну массива other
	int length = getMyLength( other.str );

	// Выделяем память для нашей строки, длина первой строки + ONE ( это для терминального нуля)
	StringEx::str = new char[ length + ONE ];

	// Цикл присвоения элементов массива other в str
	for(int i = 0; i < length; i++)
	{
		StringEx::str[ i ] = other.str[ i ];
	}

	// Присваиваем последнему элементу массива терминальный нуль, который обозначает конец строки
	StringEx::str[ length ] = '\0';

	// Возращаем наш измененный объект
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
	// Узнаем длинну массива other
	int length = getMyLength( other.str );

	// Цикл, в котором, в объект outPut закидываем элементы массива other
	for(int i = 0; i < length; i++)
	{
		outPut << other.str[ i ];
	}

	// Возращаем объект
	return outPut;
}
