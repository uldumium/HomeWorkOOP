#include "StringEx.h"
#include <string>
#include "MyFunctions.h"


//-------------------------------------------------------------------------------------------------------------------------
// �������� ����� StringEx (������) 
//* ��������* Ex ������� ���� ��������� � ��������� ������� string
//-------------------------------------------------------------------------------------------------------------------------
//� ������ ������ ���� :
// 
//- ����������� �� ��������� - READY
// 
//- ����������� � ���������� � ������� �� �������� ������ ����� - READY
// 
//- ����������� �����������( �����������!!!) - READY
// 
//- ���������� , ������� ������� ������������ ������ - READY
// 
//- ����� ������������	- READY
// 
//- ����� split - ��������� ������ �� ��������� �� ������� �����������( "29/11/2021 ����" -> {"29" , "11" , "2021 ����"} ) - READY
// 
//- ����� insert - ��������� �������� ����� �� �������( "first".->Insert( "second" , 3 ) ==> "firsecondst" ) - READY
// 
//- ����� contains - ���� ��������� ��������� � ������ , �������� "tai" � "contains" - READY
// 
//-------------------------------------------------------------------------------------------------------------------------

// ���� ����� ������ � �����.

int main()
{
	setlocale( 0 , "rus" );

	//-------------------------------------------------
	std::cout << RED_TEXT << "����������� �� ���������:\n" << DEFAULT_TEXT;
	StringEx str1;

	//-------------------------------------------------
	std::cout << RED_TEXT << "\n����������� c ����������:\n" << DEFAULT_TEXT;
	StringEx str2{ "Hello" };
	std::cout << str2 << std::endl;

	//-------------------------------------------------
	std::cout << RED_TEXT << "\n����������� �����������:\n" << DEFAULT_TEXT;
	StringEx str3( str2 );
	std::cout << str3 << std::endl;

	//-------------------------------------------------
	std::cout << RED_TEXT << "\n������������:\n" << DEFAULT_TEXT;
	std::cout << str2 << std::endl;
	std::cout << str3 << std::endl;
	StringEx str4 = str2 + str3;
	std::cout << str4 << std::endl;

	//-------------------------------------------------
	StringEx op{ "Hello my world" };
	std::cout << RED_TEXT << "\n����� SPLIT:\n" << DEFAULT_TEXT;
	std::cout << op << std::endl;
	int counterSubmassive = 0;
	StringEx* more = op.split( ' ' , counterSubmassive );
	for(int i = 0; i < counterSubmassive; i++)
	{
		std::cout << more[ i ] << std::endl;
	}
	std::cout << std::endl;

	//-------------------------------------------------
	std::cout << RED_TEXT << "����� INSERT:\n" << DEFAULT_TEXT;
	std::cout << op << std::endl;
	op.insert( "RARRAR" , 10 );
	std::cout << op << std::endl;

	//-------------------------------------------------
	StringEx newStringEx{ "Hello my first stroke" };
	std::cout << RED_TEXT << "\n����� CONTAINS:\n" << DEFAULT_TEXT;
	std::cout << newStringEx << std::endl;
	std::cout << "Result: " << newStringEx.contains( "irst" );
	std::cout << std::endl;
	return 0;
}