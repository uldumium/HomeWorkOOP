#include "App.h"

void App::menu()
{
	std::cout << "\n\n\n\n1: ������� ������ ��������� �� ���������\n"
		<< "2: ������� ������ ���������\n"
		<< "3: ������� ������ �� ���������\n"
		<< "4: ������� ���� ������\n"
		<< "5: ������������ � ����������� ������ �� ��������� � ��������� ���������\n"
		<< "0: Exit";
}

void App::�hoice( Group p )
{
	int a = 1;
	do
	{
		App::menu();
		a = _getch() - 48;
		switch(a)
		{
			case 1:
				system( "cls" );
				Group::averageGradesInSubjects( p );
				break;
			case 2:
				system( "cls" );
				Group::averageScoreOfStudents( p );
				break;
			case 3:
				system( "cls" );
				Group::studentsGradesBySubject( p );
				break;
			case 4:
				system( "cls" );
				Group::groupAverageScore( p );
				break;
			case 5:
				system( "cls" );
				Group::minimumAndMaximumGrades( p );
				break;
			default:
				system( "cls" );
				break;
		}
	} while(a != 0);
}
