#pragma once
#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <conio.h>

// Возращает число в веденном диапазоне
int getRandomInteger( int min , int max );

// Возращает рандомную строку из файла
std::string getRandomLine(std::string file);

// Функция считывающая количество строк в файле
int getValueLineFile( std::string file );