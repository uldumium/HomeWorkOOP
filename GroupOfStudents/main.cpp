#include "Student.h"



int main()
{
    // Для рандома
    srand(time( NULL ) );
    //Русский язык
    setlocale( 0 , "rus" );

    Student* group[ 10 ];

    for(int i = 0; i < 10; i++)
    {
        group[ i ] = new Student;
    }

    for(int i = 0; i < 10; i++)
    {
        group[ i ]->setName( randomLine( "Names.txt" ) );
        group[ i ]->setSurName( randomLine( "Surnames.txt" ) );
        group[ i ]->setMarks();
    }
    
    for(int i = 0; i < 10; i++)
    {
        group[ i ]->printStudent();
    }
}
