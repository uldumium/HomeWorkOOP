#pragma once
class Euro
{
	//�����
	int whole;
	//�������
	int penny;

public:

	//����������� ������
	Euro();

#pragma region Setters

	//������ ��� ������
	void setWhole( int whole );

	//������ ��� �������(�������)
	void setPenny( int penny );

#pragma endregion

#pragma region Getters

	//������ ��� ������
	int getWhole();

	//������ ��� ��������(�������)
	int getPenny();

#pragma endregion
};