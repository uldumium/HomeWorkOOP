#pragma once
class Dollar
{
	//Целлы
	int whole;
	//Дробные
	int penny;

public:

	//конструктор класса
	Dollar();

#pragma region Setters

	//сеттер для целого
	void setWhole( int whole );

	//сеттер для дробной(копейки)
	void setPenny( int penny );

#pragma endregion

#pragma region Getters

	//геттер для целого
	int getWhole();

	//геттер для дробного(копейки)
	int getPenny();

#pragma endregion
};