#include "App.h"

#define ONE_KEY 1
#define TWO_KEY 2
#define THREE_KEY 3
#define FOUR_KEY 4
#define FIVE_KEY 5

double App::setRandomNum()
{
	return 1 + rand() % ( 200 - 1 );
}

void App::setTheCurrency(Money &one)
{

	std::cout << " �������� ������ ��� ������:\n 1: �����\n 2: ������\n 3: ����\n";

	switch(_getch()-48)
	{
		case ONE_KEY:
			one.setRuble( App::setRandomNum() , App::setRandomNum() );
			break;
		case TWO_KEY:
			one.setDollar( App::setRandomNum() , App::setRandomNum() );
			break;
		case THREE_KEY:
			one.setDollar( App::setRandomNum() , App::setRandomNum() );
			break;
	}

}
