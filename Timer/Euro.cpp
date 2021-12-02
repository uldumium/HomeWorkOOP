#include "Euro.h"
#include <iostream>

//Инициализация конструктора
Euro::Euro()
{
	whole = 0;
	penny = 0;
}

//метод для ввода целой части
void Euro::setWhole( double whole )
{
	this->whole = whole;
}

//метод для ввода дробной части
void Euro::setPenny( double penny )
{
	if( penny >= 100 )
	{
		whole++;
		setPenny( penny - 100 );
	}
	else
	{
		this->penny = penny;
	}
}

//метод для получения целой части валюты
double Euro::getWhole()
{
	return whole;
}

//метод для получения дробной части валюты
double Euro::getPenny()
{
	return penny;
}
