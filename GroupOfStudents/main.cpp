#include "Group.h"


int main()
{
    // Для рандома
    srand(time( NULL ) );
    //Русский язык
    setlocale( 0 , "rus" );


    Group p;
    p.fillStudentList();


    Group::studentsGradesBySubject(p);


}
