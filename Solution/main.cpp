#include <iostream>
#include <iomanip>
#include "Money.h"

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
	setlocale(0, "rus");

	Money dol, eu;
	
	dol.setDollar( 20, 120 );
	eu.setEuro( 2, 130 );

	Money ruble = Money::exchangeToRuble( dol );
	Money ruble2 = Money::exchangeToRuble( eu );

	std::cout << std::fixed << std::setprecision( 0 ) << ruble.getRubleWhole() << " " << ruble.getRublePenny() << std::endl;
	std::cout << std::fixed << std::setprecision(0) << ruble2.getRubleWhole() << " " << ruble2.getRublePenny() << std::endl;

	Money::add(dol, eu);
}
