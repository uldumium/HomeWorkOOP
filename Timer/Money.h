#pragma once
#include "Dollar.h"
#include "Euro.h"
#include "Ruble.h"
#include <iostream>
#include <iomanip>
#include <conio.h>

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
	// Перевод валюты в основную, рубль
	static Money exchangeToRuble( Money one );

	// Перевод валюты в доллар
	static Money exchangeToDollar( Money one );

	//Перевод валюты в евро
	static Money exchangeToEuro( Money one );

	// Сложение
	static void add( Money one , Money two );

	// Вычитание
	static void sub( Money one , Money two );

	// Деление
	static void div( Money one , Money two );

	// Умножение
	static void mult( Money one , Money two );

	// Сравнение
	static void comparison( Money one , Money two );

#pragma endregion

#pragma region SETTERS

	// Задаем значение доллару
	void setDollar( double whole , double penny );


	// Задаем значение евро
	void setEuro( double whole , double penny );

	// Задаем значение рублю
	void setRuble( double whole , double penny );


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

