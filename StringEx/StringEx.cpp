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

StringEx* StringEx::split( const char delimiter , int& count )
{
	// Создаем счетчики для метода
	int counterSubstring = 1; // Счетчик слов
	int bufferCounter = 0; // Счетчик длины подстроки
	int counterBufferArray = 0; // Счетчик объектов

	// Цикл, с помощью которого узнаем сколько подмассивов в нашем объекте
	for(int i = 0; StringEx::str[i] != '\0'; i++)
	{
		if(delimiter == str[ i ])
		{
			counterSubstring++; // Если встречается пробел либо терминальный нуль, увеличиваем счетчик
		}
	}
	
	// создаем массив объектов класса StringEx
	StringEx* bufferArray = new StringEx[ counterSubstring ];
	
	// Переменная которая содержит длину массива чаров объектра, который мы хотим разделить на подмассивы
	int thisLength = getMyLength( StringEx::str );

	// Главный цикл, который идет до конца строки объекта, который мы хотим разбить на подмассивы
	for(int i = 0; i < thisLength+1; i++)
	{
		if(delimiter != str[ i ] && '\0' != str[i]) // Условие по которому считаем длину подмассива
		{
			bufferCounter++;
		}
		else
		{
			StringEx bufferOne; // Создаем объект

			bufferOne.str = new char[ bufferCounter + ONE]; // Выделяем объекту память под чары + терминальный нуль

			for(int j = i - bufferCounter, o = 0; j < i; j++,o++) // Цикл копирования подмассива в новый объект
			{
				bufferOne.str[ o ] = StringEx::str[ j ];
			}

			bufferOne.str[ bufferCounter ] = '\0'; // Присваиваем последнему эелементу массива терминальный нуль

			bufferArray[ counterBufferArray ] = bufferOne; // Массиву объекту, присваиваем объект

			counterBufferArray++; // Увеличиваем счетчик массима объектов

			bufferCounter = 0; // Обнуляем счетчик длины подстроки
		}
	}

	count = counterSubstring;

	// Возращаем массив объектов класса StringEx
	return bufferArray;
}

void StringEx::insert(const char* subArray, const int index)
{
	// Перменные обозначающие длины строк
	int thisLength = getMyLength(StringEx::str);
	int subArrayLength = getMyLength(subArray);
	int newBufferLength = thisLength + subArrayLength;

	// Новый буфферОбъект
	StringEx bufferStringEx;

	// Выделяем память для новой строки + для терминального нуля
	bufferStringEx.str = new char[newBufferLength + ONE];

	// Цикл до конца длины буффера
	for (int i = 0,k = 0; i < newBufferLength; i++,k++)
	{
		if (index == i) // Если i-тый будет равен нашему индексу, который мы передали, запускается цикл, который вставляет подмассив строку
		{
			for (int j = 0; j < subArrayLength; j++)
			{
				bufferStringEx.str[k++] = subArray[j];
			}
		}

		// Копирует в буфферСтроку строку основного объекта
			bufferStringEx.str[k] = StringEx::str[i];
	}

	// Присваиваем последнему элементу буфферСтроки термальный нуль
	bufferStringEx.str[newBufferLength] = '\0';

	// Чистим объект который изменили
	StringEx::clearObj();

	// Присваиваем нашему чистому объекту буффер при помощи перегрузки оператора
	*this = bufferStringEx;
}

bool StringEx::contains(const char* other) const
{
	int thisLength = getMyLength(StringEx::str);
	int otherLength = getMyLength(other);

	int hitCounter = 0;

	for (int i = 0,k=0; i < thisLength; i++,k++)
	{
		if (StringEx::str[i] == other[k])
		{
			for (int j = 0, p = i; j < otherLength; j++, p++)
			{
				if (StringEx::str[p] == other[j])
				{
					hitCounter++;
				}

				if (otherLength == hitCounter)
					return true;
			}
		}
	}

	return false;
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

std::ostream& operator<<( std::ostream& outPut , const StringEx& other )
{
	// Узнаем длинну массива other
	int length = getMyLength(other.str);

	// Цикл, в котором, в объект outPut закидываем элементы массива other
	for (int i = 0; i < length; i++)
	{
		outPut << other.str[i];
	}

	// Возращаем объект
	return outPut;
}