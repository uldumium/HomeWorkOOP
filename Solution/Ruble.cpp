#include "Ruble.h"
#include <iostream>

//������������� ������������
Ruble::Ruble()
{
	whole = 0;
	penny = 0;
}

//����� ��� ����� ����� �����
void Ruble::setWhole( int whole )
{
	this->whole = whole;
}

//����� ��� ����� ������� �����
void Ruble::setPenny( int penny )
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
int Ruble::getWhole()
{
	return whole;
}

//����� ��� ��������� ������� ����� ������
int Ruble::getPenny()
{
	return penny;
}
