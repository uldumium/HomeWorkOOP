#pragma once
#include "Dollar.h"
#include "Euro.h"
#include "Ruble.h"
#include <iostream>

//����� ������
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
	// ������� ������ � ���������, �����
	static Money exchange( Money one );

	// ��������
	void add( Money one, Money two );

	// ���������
	void sub( Money one, Money two );

	// �������
	void div( Money one, Money two );

	// ���������
	void mult( Money one, Money two );

#pragma endregion

#pragma region SETTERS

	// ������ �������� �������
	void setDollar( double whole, double penny);


	// ������ �������� ����
	void setEuro( double whole, double penny );

	// ������ �������� �����
	void setRuble( double whole, double penny );


#pragma endregion

#pragma region GETTERS

	// ��������� ����� �������� �������
	double getDollarWhole();

	// ��������� ������� �������� �������
	double getDollarPenny();

	// ��������� ����� �������� ����
	double getEuroWhole();

	// ��������� ������� �������� ����
	double getEuroPenny();

	// ��������� ����� �������� �����
	double getRubleWhole();

	// ��������� ������� �������� �����
	double getRublePenny();

#pragma endregion
};

