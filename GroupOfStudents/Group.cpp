#include "Group.h"

Group::Group()
{
	Group::nameGroup = "N/O";

	/*for(int i = 0; i < MAX_SIZE_VALUE_ITEM; i++)
	{
		Group::itemList[ i ]->setNameItem( "name" );
	}*/

	/*Group::itemList[ 0 ]->setNameItem( "0" );*/
	
	/*for(int i = 0; i < MAX_SIZE_GROUP_STUDENTS; i++)
	{
		Group::studentList[ i ]->setName("N/O");
		Group::studentList[ i ]->setSurName( "N/O" );
		Group::studentList[ i ]->setMarks( 0 , 0 , 0 );
	}*/
}

void Group::printItems()
{
	for(int i = 0; i < MAX_SIZE_VALUE_ITEM; i++)
	{
		std::cout<<Group::itemList[ i ] << " ";
	}
}

void Group::setNameGroup( std::string name )
{
	Group::nameGroup = name;
}

void Group::fillStudentList()
{
	for(int i = 0; i < MAX_SIZE_GROUP_STUDENTS; i++)
	{
		Group::studentList[ i ]->setName( getRandomLine( "Names.txt" ) );
		Group::studentList[ i ]->setSurName( getRandomLine( "Surnames.txt" ) );
		Group::studentList[ i ]->setMarks();
	}
}