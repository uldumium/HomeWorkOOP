#include "Student.h"

Student::Student()
{
    name = "N/O";
    surName = "N/O";
    for(int i = 0; i < MAX_COUNT_ITEMS; i++)
    {
        for(int j = 0; j < MAX_MARKS; j++)
        {
            marks[ i ][ j ] = 0;
        }
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
    for(int i = 0; i < MAX_COUNT_ITEMS; i++)
    {
        for(int j = 0; j < MAX_MARKS; j++)
        {
            Student::marks[ i ][ j ] = getRandomInteger( 2 , 5 );
        }
    }
}

void Student::setMarks(int a)
{
    for(int i = 0; i < MAX_COUNT_ITEMS; i++)
    {
        for(int j = 0; j < MAX_MARKS; j++)
        {
            Student::marks[ i ][ j ] = a;
        }
    }
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
    //Student::printStudentMarks();
    std::cout << std::endl;
}

void Student::printStudentMarks(int a)
{
        for(int j = 0; j < MAX_MARKS; j++)
        {
            std::cout << Student::marks[ a ][ j ] << " ";
        }
}
