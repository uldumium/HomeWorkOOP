#pragma once

//Доллар
class Dollar
{
	//Целлы
	double whole;
	//Дробные
	double penny;

public:

	//конструктор класса
	Dollar();

#pragma region Setters

	//сеттер для целого
	void setWhole( double whole );

	//сеттер для дробной(копейки)
	void setPenny( double penny );

#pragma endregion

#pragma region Getters

	//геттер для целого
	double getWhole();

	//геттер для дробного(копейки)
	double getPenny();

#pragma endregion
};