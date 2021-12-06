#include "StringEx.h"
#include <string>
#include "MyFunctions.h"


//-------------------------------------------------------------------------------------------------------------------------
// �������� ����� StringEx (������) 
//* ��������* Ex ������� ���� ��������� � ��������� ������� string
//-------------------------------------------------------------------------------------------------------------------------
//� ������ ������ ���� :
// 
//-����������� �� ��������� - READY
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
//- ����� insert - ��������� �������� ����� �� �������( "first".->Insert( "second" , 3 ) ==> "firsecondst" ) - In the process
// 
//- ����� contains - ���� ��������� ��������� � ������ , �������� "tai" � "contains"
// 
//-------------------------------------------------------------------------------------------------------------------------



int main()
{
	setlocale( 0 , "rus" );

	std::cout << "����������� �� ���������:\n";
	StringEx str1;
	std::cout << str1 << std::endl;

	std::cout << "\n����������� c ����������:\n";
	StringEx str2{"Hello"};
	std::cout << str2 << std::endl;

	std::cout << "\n����������� �����������:\n";
	StringEx str3(str2); 
	std::cout << str3 << std::endl;

	std::cout << "\n������������:\n";
	std::cout << str2 << std::endl;
	std::cout << str3 << std::endl;
	StringEx str4 = str2 + str3;
	std::cout << str4 << std::endl;


	StringEx op{"Hello my world"};
	std::cout << "\n����� �����:\n";
	std::cout << op << std::endl;
	StringEx* more = op.split( ' ' );
	for(int i = 0; more[i] != '\0'; i++)
	{
		int counter = 1;
		std::cout << counter << " stroke: " << more[ i ] << std::endl;
	}

	return 0;
}