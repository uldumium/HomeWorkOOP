#include "Student.h"
#include "Item.h"


int main()
{
    // Для рандома
    srand(time( NULL ) );
    //Русский язык
    setlocale( 0 , "rus" );

    Student* group[ 10 ];
    Item* items[ 10 ];

    for(int i = 0; i < 10; i++)
    {
        group[ i ] = new Student;
        items[ i ] = new Item;
    }

    for(int i = 0; i < 10; i++)
    {
        group[ i ]->setName( randomLine( "Names.txt" ) );
        group[ i ]->setSurName( randomLine( "Surnames.txt" ) );
        group[ i ]->setMarks();
        items[ i ]->setNameItem( randomLine( "Items.txt" ) );
    }
    
    for(int i = 0; i < 10; i++)
    {
        std::cout << items[ i ]->getNameItem() << std::endl;
        group[ i ]->printStudent();
    }
}
