#include "StringEx.h"
#include <string>
#include "MyFunctions.h"


//-----------------------------------------------------------------------------------------------------------------------------------------
//Дополнить класс String новыми методами и перегрузками операций.
//-----------------------------------------------------------------------------------------------------------------------------------------
//	- дополнить класс методами isEmpty - READY
// 
//	- дополнить класс методами size - READY (.clearObj)
// 
//	- дополнить класс методами clear - READY
// 
//	- добавить по необходимости иные методы , упрощающие работу с классом
//
//	- добавить перегрузку оператора вывода в консоль - READY
// 
//	- добавить конструктор копирования и перегрузку оператора присваивания - READY (Конструктор копирования был реализован еще в 4 задании)
// 
//	- добавить перегрузку оператора индексации - READY
// 
//	- добавить перегрузку операторов сравнения - READY
//-----------------------------------------------------------------------------------------------------------------------------------------

// Весь вывод сделал в мейне.
// У метода .clear было изменено название на .clearObj

int main()
{
	setlocale( 0 , "rus" );

	//-------------------------------------------------
	StringEx newStringEx{ "Hello my first stroke" };
	std::cout << RED_TEXT << "Метод SIZE:\n" << DEFAULT_TEXT;
	std::cout << newStringEx << std::endl;
	std::cout << newStringEx.size() << std::endl;

	//-------------------------------------------------
	StringEx newString;
	StringEx newStrEx{ "Hello my first stroke" };
	std::cout << RED_TEXT << "Метод isEmpty:\n" << DEFAULT_TEXT;
	std::cout << newStrEx.isEmpty() << std::endl;
	std::cout << newString.isEmpty() << std::endl;

	//-------------------------------------------------
	StringEx indexString{ "Hello my first stroke" };
	std::cout << RED_TEXT << "Перегрузка оператора []:\n" << DEFAULT_TEXT;
	std::cout << indexString << std::endl;
	for(int i = 0; i < indexString.size(); i++)
	{
		std::cout << indexString[ i ] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	//-------------------------------------------------
	StringEx str{ "MARTY HELLO" };
	StringEx str2{ "MARTY HELLO" };
	StringEx str3{ "MARTY HeLLO" };
	std::cout << RED_TEXT << "Перегрузка оператора ==:\n" << DEFAULT_TEXT;
	std::cout << "1: " << str << std::endl;
	std::cout << "2: " << str2 << std::endl;
	std::cout << "3: " << str3 << std::endl;
	std::cout << " Сравнение первой и второй строки:\n";
	StringEx::comparison( str , str2 ); 
	std::cout << " Сравнение второй и третей строки:\n";
	StringEx::comparison( str2 , str3 );

	return 0;
}