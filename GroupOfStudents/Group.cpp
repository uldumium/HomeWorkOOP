#include "Group.h"

Group::Group()
{
	// ������������� ����� ������ �� ���������
	Group::nameGroup = "N/O";

	// ������������� �������� ��������� �� �����
	std::ifstream in;
	std::string line; // ���������� - ������
	in.open( "Items.txt" ); // ���� � ��������� ���������
	if(in.is_open())
	{
		for(int i = 0; i < MAX_SIZE_VALUE_ITEM; i++)
		{
			in >> line;
			Group::itemList[ i ].setNameItem( line );
		}
		in.close();
	}

	// ������������� ���������
	for(int i = 0; i < MAX_SIZE_GROUP_STUDENTS; i++)
	{
		Group::studentList[ i ].setName("N/O");
		Group::studentList[ i ].setSurName( "N/O" );
		Group::studentList[ i ].setMarks( 0 );
	}
}

void Group::studentsGradesBySubject(Group p)
{
	std::cout << "|" << std::setw( 25 ) << std::left << "��� � ������� ��������" << "|";

	for(int i = 0; i < MAX_SIZE_VALUE_ITEM; i++)
	{
		std::cout << std::setw( 11 ) << std::left << p.printItems( i ) << "|";
	}
	std::cout << std::endl;
	for(int i = 0; i < MAX_SIZE_GROUP_STUDENTS; i++)
	{
		std::cout << "|" << std::setw( 10 ) << std::left << p.getSurnameStudentGroup( i ) << " ";
		std::cout << std::setw( 14 ) << std::left << p.getNameStudentGroup( i ) << "|";

		for(int j = 0; j < MAX_COUNT_ITEMS; j++)
		{
			std::cout << " ";
			p.printMarksStudentsGroup( j );
			std::cout << "|";
		}

		std::cout << std::endl;
	}
}

void Group::averageScoreOfStudents( Group p )
{
	double summa = 0;

	std::cout <<"��� � ������� ��������: \n";
	for(int t = 0; t < MAX_SIZE_GROUP_STUDENTS; t++)
	{
		summa = 0;
		std::cout << p.studentList[ t ].getName() << " " << p.studentList[ t ].getSurName();
		for(int i = 0; i < MAX_COUNT_ITEMS; i++)
		{
			for(int j = 0; j < MAX_MARKS; j++)
			{
				summa += p.studentList[t].getGrade( i , j );
			}
		}
		std::cout << " - ������� ������: " << summa / ( MAX_COUNT_ITEMS * MAX_MARKS ) << std::endl;
	}
	
}

std::string Group::printItems( int a )
{
	return Group::itemList[ a ].getNameItem();
}

void Group::printMarksStudentsGroup( int a )
{
	Group::studentList->printStudentMarks(a);
}

void Group::setNameGroup( std::string name )
{
	Group::nameGroup = name;
}

void Group::fillStudentList()
{
	for(int i = 0; i < MAX_SIZE_GROUP_STUDENTS; i++)
	{
		Group::studentList[ i ].setName( getRandomLine( "Names.txt" ) );
		Group::studentList[ i ].setSurName( getRandomLine( "Surnames.txt" ) );
		Group::studentList[ i ].setMarks();
	}
}

std::string Group::getNameStudentGroup( int a )
{
	return Group::studentList[ a ].getName();
}

std::string Group::getSurnameStudentGroup( int a )
{
	return Group::studentList[ a ].getSurName();
}
