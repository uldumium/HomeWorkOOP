#pragma once
#include "Dollar.h"
#include "Euro.h"
#include "Ruble.h"
#include <iostream>

//Класс волюты
class Money
{
private:

	Dollar dollar;
	Euro euro;
	Ruble ruble;

public:

	Money()
	{
		dollar.setWhole( 0 );
		dollar.setPenny( 0 );

		euro.setWhole( 0 );
		euro.setPenny( 0 );

		ruble.setWhole( 0 );
		ruble.setWhole( 0 );
	}

#pragma region METHODS
	// Перевод валюты в осмновную, рубль
	static Money exchange( Money one );

	// Сложение
	void add( Money one, Money two );

	// Вычитание
	void sub( Money one, Money two );

	// Деление
	void div( Money one, Money two );

	// Умножение
	void mult( Money one, Money two );

#pragma endregion

#pragma region SETTERS

	// Задаем значение доллару
	void setDollar( double whole, double penny);


	// Задаем значение евро
	void setEuro( double whole, double penny );

	// Задаем значение рублю
	void setRuble( double whole, double penny );


#pragma endregion

#pragma region GETTERS

	// Возращает целое значение доллара
	double getDollarWhole();

	// Возращает дробное значение доллара
	double getDollarPenny();

	// Возращает целое значение евро
	double getEuroWhole();

	// Возращает дробное значение евро
	double getEuroPenny();

	// Возращает целое значение рубля
	double getRubleWhole();

	// Возращает дробное значение рубля
	double getRublePenny();

#pragma endregion
};

