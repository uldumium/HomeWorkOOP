#include "Dollar.h"
#include <iostream>
//������������� ������������
Dollar::Dollar()
{
	whole = 0;
	penny = 0;
}

//����� ��� ����� ����� �����
void Dollar::setWhole( int whole )
{
	this->whole = whole;
}

//����� ��� ����� ������� �����
void Dollar::setPenny( int penny )
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
int Dollar::getWhole()
{
	return whole;
}

//����� ��� ��������� ������� ����� ������
int Dollar::getPenny()
{
	return penny;
}
