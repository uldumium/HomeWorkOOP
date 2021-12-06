#include "StringEx.h"
#include <string>
#include "MyFunctions.h"


//-------------------------------------------------------------------------------------------------------------------------
// Написать класс StringEx (строка) 
//* постфикс* Ex добавть дабы различать с системным классом string
//-------------------------------------------------------------------------------------------------------------------------
//В классе должны быть :
// 
//-конструктор по умолчанию - READY
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
//- метод insert - вставляет заданный текст на позицию( "first".->Insert( "second" , 3 ) ==> "firsecondst" ) - In the process
// 
//- метод contains - ищет вхождение подстроки в строке , например "tai" в "contains"
// 
//-------------------------------------------------------------------------------------------------------------------------



int main()
{
	setlocale( 0 , "rus" );

	std::cout << "Конструктор по умолчанию:\n";
	StringEx str1;
	std::cout << str1 << std::endl;

	std::cout << "\nКонструктор c параметром:\n";
	StringEx str2{"Hello"};
	std::cout << str2 << std::endl;

	std::cout << "\nКонструктор копирования:\n";
	StringEx str3(str2); 
	std::cout << str3 << std::endl;

	std::cout << "\nКонкатинация:\n";
	std::cout << str2 << std::endl;
	std::cout << str3 << std::endl;
	StringEx str4 = str2 + str3;
	std::cout << str4 << std::endl;


	StringEx op{"Hello my world"};
	std::cout << "\nМетод сплит:\n";
	std::cout << op << std::endl;
	StringEx* more = op.split( ' ' );
	for(int i = 0; more[i] != '\0'; i++)
	{
		int counter = 1;
		std::cout << counter << " stroke: " << more[ i ] << std::endl;
	}

	return 0;
}