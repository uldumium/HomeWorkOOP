#pragma once
class Dollar
{
	//�����
	int whole;
	//�������
	int penny;

public:

	//����������� ������
	Dollar();

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