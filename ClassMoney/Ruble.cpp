#include "Ruble.h"
#include <iostream>

//Инициализация конструктора
Ruble::Ruble()
{
	whole = 0;
	penny = 0;
}

//метод для ввода целой части
void Ruble::setWhole( double whole )
{
	this->whole = whole;
}

//метод для ввода дробной части
void Ruble::setPenny( double penny )
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
double Ruble::getWhole()
{
	return whole;
}

//метод для получения дробной части валюты
double Ruble::getPenny()
{
	return penny;
}
