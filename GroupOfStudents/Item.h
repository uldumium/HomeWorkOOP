#pragma once
#include "MyFuncttion.h"


class Item
{
public:

	// ����������� �� ��������� 
	Item();
	// ������������� ����� ��������
	void setNameItem(std::string nameItem);

	// ��������� ��� ��������
	std::string getNameItem();

private:

	// ��� ��������
	std::string nameItem;
};

