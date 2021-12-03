#include "Group.h"


int main()
{
    // Для рандома
    srand(time( NULL ) );
    //Русский язык
    setlocale( 0 , "rus" );

    Group p;
    p.fillStudentList();


    Group::averageGradesInSubjects(p);
    std::cout << std::endl;
    Group::averageScoreOfStudents( p );
    std::cout << std::endl;
    Group::studentsGradesBySubject( p );
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    Group::groupAverageScore( p );
}
