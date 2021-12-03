#include "App.h"

void App::menu()
{
	std::cout << "\n\n\n\n1: Таблица оценок студентов по предметам\n"
		<< "2: Средние оценки студентов\n"
		<< "3: Средние оценки по предметам\n"
		<< "4: Средний балл группы\n"
		<< "5: Максимальные и минимальные оценки по предметам с указанием студентов\n"
		<< "0: Exit";
}

void App::сhoice( Group p )
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
