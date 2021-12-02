#include "Student.h"

Student::Student()
{
    name = "N/O";
    surName = "N/O";
    for(int i = 0; i < MAX_MARKS; i++)
    {
        marks[ i ] = 0;
    }
}

void Student::setName( std::string name )
{
    this->name = name;
}

void Student::setSurName( std::string surName )
{
    this->surName = surName;
}

void Student::setMarks()
{
    for(int i = 0; i < MAX_MARKS; i++)
    {
        Student::marks[ i ] = getRandomInteger( 2 , 5 );
    }
}

void Student::setMarks( int a , int b , int c )
{
    Student::marks[ 0 ] = a;
    Student::marks[ 1 ] = b;
    Student::marks[ 2 ] = c;
}

std::string Student::getName()
{
    return name;
}

std::string Student::getSurName()
{
    return surName;
}

void Student::printStudent()
{
    std::cout << Student::name << " " << Student::surName;
    Student::printStudentMarks();
    std::cout << std::endl;
}

void Student::printStudentMarks()
{
    // ”знаем размер массива
    int size = sizeof( Student::marks ) / sizeof( Student::marks[ 0 ] );

    std::cout << "\nќценки - [ ";

    for(int i = 0; i < size; i++)
    {
        std::cout << Student::marks[ i ] << " ";
    }

    std::cout << "]" << std::endl;
}
