#include "Dollar.h"
#include <iostream>
//Инициализация конструктора
Dollar::Dollar()
{
	whole = 0;
	penny = 0;
}

//метод для ввода целой части
void Dollar::setWhole( double whole )
{
	this->whole = whole;
}

//метод для ввода дробной части
void Dollar::setPenny( double penny )
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
double Dollar::getWhole()
{
	return whole;
}

//метод для получения дробной части валюты
double Dollar::getPenny()
{
	return penny;
}
