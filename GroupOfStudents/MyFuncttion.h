#pragma once
#include <iostream>
#include <ctime>
#include <fstream>

// ��������� ����� � �������� ���������
int randomInteger( int min , int max );

// ��������� ��������� ������ �� �����
std::string randomLine(std::string file);

// ������� ����������� ���������� ����� � �����
int getValueLineFile( std::string file );