#include "App.h"
#include "Money.h"

#define ESC_KEY 27
#define ONE_KEY 1
#define TWO_KEY 2
#define THREE_KEY 3
#define FOUR_KEY 4
#define FIVE_KEY 5

//-----------------------------------------------------------//
///															///
///		В программе главная валюта это рубли				///
///		По итогу, все конвертируется и сверяется по рублю	///
///															///
//-----------------------------------------------------------//

// std::fixed - записывает значения с плавающей запятой в нотации с фиксированной запятой
// std::setprecision( 0 ) - ограничение знаков вывода в консоль после запятой


int main()
{
	srand(time( NULL ) );
	setlocale( 0 , "rus" );
	Money one , two;
	
	do
	{
		system( "cls" );
		std::cout << " 1: Сложение\n 2: Вычитание\n 3: Произведение\n 4: Частное\n 5: Сравнение\n\n";
		switch(_getch()-48)
		{
			case ONE_KEY:
				system( "cls" );
				App::setTheCurrency( one );
				App::setTheCurrency( two );

				Money::add( one , two );
				break;
			case TWO_KEY:
				system( "cls" );
				App::setTheCurrency( one );
				App::setTheCurrency( two );

				Money::sub( one , two );
				break;
			case THREE_KEY:
				system( "cls" );
				App::setTheCurrency( one );
				App::setTheCurrency( two );

				Money::mult( one , two );
				break;
			case FOUR_KEY:
				system( "cls" );
				App::setTheCurrency( one );
				App::setTheCurrency( two );

				Money::div( one , two );
				break;
			case FIVE_KEY:
				system( "cls" );
				App::setTheCurrency( one );
				App::setTheCurrency( two );
				
				Money::comparison( one , two );
				break;
		}

	} while(_getch() != ESC_KEY);

	return 0;
}
