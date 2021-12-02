#pragma once
#include <iostream>
#include <ctime>
#include <fstream>

// Возращает число в веденном диапазоне
int randomInteger( int min , int max );

// Возращает рандомную строку из файла
std::string randomLine(std::string file);

// Функция считывающая количество строк в файле
int getValueLineFile( std::string file );