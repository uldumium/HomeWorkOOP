#include "Euro.h"
#include <iostream>

//������������� ������������
Euro::Euro()
{
	whole = 0;
	penny = 0;
}

//����� ��� ����� ����� �����
void Euro::setWhole( int whole )
{
	this->whole = whole;
}

//����� ��� ����� ������� �����
void Euro::setPenny( int penny )
{
	if( penny > 100 )
	{
		std::cout << "Error. Max value penny = 99\n";
		std::cout << " Enter the permitted value\n";

		int buffer;

		std::cin >> buffer;
		setPenny( buffer );
	}
	else
	{
		this->penny = penny;
	}
}

//����� ��� ��������� ����� ����� ������
int Euro::getWhole()
{
	return whole;
}

//����� ��� ��������� ������� ����� ������
int Euro::getPenny()
{
	return penny;
}
