#include "StringEx.h"
#include <string>
#include "MyFunctions.h"


//-------------------------------------------------------------------------------------------------------------------------
// Написать класс StringEx (строка) 
//* постфикс* Ex добавть дабы различать с системным классом string
//-------------------------------------------------------------------------------------------------------------------------
//В классе должны быть :
// 
//- конструктор по умолчанию - READY
// 
//- конструктор с параметром в который мы помещаем массив чаров - READY
// 
//- конструктор копирования( обязательно!!!) - READY
// 
//- деструктор , который очистит динамические данные - READY
// 
//- метод конкатенации	- READY
// 
//- метод split - разделяет строку на подстроки по символу разделителю( "29/11/2021 года" -> {"29" , "11" , "2021 года"} ) - READY
// 
//- метод insert - вставляет заданный текст на позицию( "first".->Insert( "second" , 3 ) ==> "firsecondst" ) - READY
// 
//- метод contains - ищет вхождение подстроки в строке , например "tai" в "contains" - READY
// 
//-------------------------------------------------------------------------------------------------------------------------

// Весь вывод сделал в мейне.

int main()
{
	setlocale( 0 , "rus" );

	//-------------------------------------------------
	std::cout << RED_TEXT << "Конструктор по умолчанию:\n" << DEFAULT_TEXT;
	StringEx str1;

	//-------------------------------------------------
	std::cout << RED_TEXT << "\nКонструктор c параметром:\n" << DEFAULT_TEXT;
	StringEx str2{ "Hello" };
	std::cout << str2 << std::endl;

	//-------------------------------------------------
	std::cout << RED_TEXT << "\nКонструктор копирования:\n" << DEFAULT_TEXT;
	StringEx str3( str2 );
	std::cout << str3 << std::endl;

	//-------------------------------------------------
	std::cout << RED_TEXT << "\nКонкатинация:\n" << DEFAULT_TEXT;
	std::cout << str2 << std::endl;
	std::cout << str3 << std::endl;
	StringEx str4 = str2 + str3;
	std::cout << str4 << std::endl;

	//-------------------------------------------------
	StringEx op{ "Hello my world" };
	std::cout << RED_TEXT << "\nМетод SPLIT:\n" << DEFAULT_TEXT;
	std::cout << op << std::endl;
	int counterSubmassive = 0;
	StringEx* more = op.split( ' ' , counterSubmassive );
	for(int i = 0; i < counterSubmassive; i++)
	{
		std::cout << more[ i ] << std::endl;
	}
	std::cout << std::endl;

	//-------------------------------------------------
	std::cout << RED_TEXT << "Метод INSERT:\n" << DEFAULT_TEXT;
	std::cout << op << std::endl;
	op.insert( "RARRAR" , 10 );
	std::cout << op << std::endl;

	//-------------------------------------------------
	StringEx newStringEx{ "Hello my first stroke" };
	std::cout << RED_TEXT << "\nМетод CONTAINS:\n" << DEFAULT_TEXT;
	std::cout << newStringEx << std::endl;
	std::cout <<"Result: " << newStringEx.contains("irst");
	std::cout << std::endl;
	return 0;
}