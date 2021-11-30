#include <iostream>
#include <iomanip>
#include "Money.h"

// std::fixed - записывает значения с плавающей запятой в нотации с фиксированной запятой
// std::setprecision( 0 ) - ограничение знаков вывода в консоль после запятой

int main()
{
	Money dol, eu;
	
	dol.setDollar( 20, 120 );
	eu.setEuro( 20, 120 );

	Money ruble = Money::exchange( dol );
	Money ruble2 = Money::exchange( eu );

	std::cout << std::fixed << std::setprecision( 0 ) << ruble.getRubleWhole() << " " << ruble.getRublePenny() << std::endl;
	std::cout << std::fixed << std::setprecision( 0 ) << ruble2.getRubleWhole() << " " << ruble2.getRublePenny();
}
