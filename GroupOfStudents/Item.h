#pragma once
#include "MyFuncttion.h"


class Item
{
public:

	// Конструктор по умолчанию 
	Item();

	// Конструктор с параметром
	Item( std::string nameItem );

	// Инициализация имени предмета
	void setNameItem(std::string nameItem);

	// Возращает имя предмета
	std::string getNameItem();

private:

	// Имя предмета
	std::string nameItem;
};

