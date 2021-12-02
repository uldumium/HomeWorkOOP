#include "Group.h"


int main()
{
    // Для рандома
    srand(time( NULL ) );
    //Русский язык
    setlocale( 0 , "rus" );


	/*std::string name[ MAX_SIZE_VALUE_ITEM ];
	std::ifstream in;
	in.open( "Items.txt" );
	if(in.is_open())
	{
		for(int i = 0; i < MAX_SIZE_VALUE_ITEM; i++)
		{
			in >> name[ i ];
		}
		in.close();
	}
	int size = sizeof( name ) / sizeof( name[ 0 ] );
	for(int i = 0; i < size; i++)
	{
		std::cout << name[ i ] << std::endl;
	}*/
	
	Group p;

	p.fillStudentList();
}
