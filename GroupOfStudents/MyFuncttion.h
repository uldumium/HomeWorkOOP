#pragma once
#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>

// ��������� ����� � �������� ���������
int getRandomInteger( int min , int max );

// ��������� ��������� ������ �� �����
std::string getRandomLine(std::string file);

// ������� ����������� ���������� ����� � �����
int getValueLineFile( std::string file );