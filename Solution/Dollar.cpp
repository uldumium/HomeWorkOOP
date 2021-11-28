#include "Dollar.h"
#include <iostream>
//Инициализация конструктора
Dollar::Dollar()
{
	whole = 0;
	penny = 0;
}

//метод для ввода целой части
void Dollar::setWhole( int whole )
{
	this->whole = whole;
}

//метод для ввода дробной части
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

//метод для получения целой части валюты
int Dollar::getWhole()
{
	return whole;
}

//метод для получения дробной части валюты
int Dollar::getPenny()
{
	return penny;
}
