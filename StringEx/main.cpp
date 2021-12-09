#include "StringEx.h"
#include <string>
#include "MyFunctions.h"


//-----------------------------------------------------------------------------------------------------------------------------------------
// 
//	Дополнить класс String перегрузками операций.
// 
//-----------------------------------------------------------------------------------------------------------------------------------------
// 
//	- Придумать и реализовать перегрузки операций для методов concat, split, contains.
// 
//-----------------------------------------------------------------------------------------------------------------------------------------
// 
// 1 - Конкатинация перегружена оператором += - READY
// 
// 2 - contains перегружен оператором -       - READY
// 
// 3 - split перегружен рператором, который сразу выводит массив подстрок в консоль
// 
//-----------------------------------------------------------------------------------------------------------------------------------------

int main()
{
	setlocale( 0 , "rus" );
	//-----------------------------------
	std::cout << RED_TEXT << "Конкатинация перегружена оператором +=\n" << DEFAULT_TEXT;
	StringEx newString{ "Hello" };
	StringEx newString2{ "_World" };
	StringEx newString3;
	std::cout << "1 Stroke: " << newString << std::endl;
	std::cout << "2 Stroke: " << newString2 << std::endl;
	newString3 = newString += newString2;
	std::cout << newString3 << std::endl << std::endl;

	//-----------------------------------
	std::cout << RED_TEXT << "contains перегружен оператором - \n" << DEFAULT_TEXT;
	StringEx newString4{ "Hello" };
	StringEx newString5{ "Hel" };
	StringEx newString6{ "Hola" };
	std::cout << "4 Stroke: " << newString4 << std::endl;
	std::cout << "5 Stroke: " << newString5 << std::endl;
	std::cout << "6 Stroke: " << newString6 << std::endl;
	std::cout << " Входит ли в 4 строку, строка 5?\n";
	newString4 - newString5;
	std::cout << std::endl;
	std::cout << " Входит ли в 4 строку, строка 6?\n";
	newString4 - newString6;
	std::cout << std::endl << std::endl;

	//-----------------------------------
	std::cout << RED_TEXT << "split перегружен оператором / \n" << DEFAULT_TEXT;
	StringEx newString7{ "Hello my little world!" };
	std::cout << newString7 << std::endl;
	newString7 / ' ';

	return 0;
}