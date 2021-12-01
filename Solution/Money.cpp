#include "Money.h"

#pragma region METHODS

Money Money::exchangeToRuble( Money one )
{
	Money exchangeBuffer;

	if(one.dollar.getWhole() > 0)
	{
		// Доллар к рублю
		double exchangeValue = 74.86;

		exchangeBuffer.ruble.setWhole( one.dollar.getWhole() * exchangeValue );
		exchangeBuffer.ruble.setPenny( one.dollar.getPenny() * exchangeValue );
	}
	else if(one.euro.getWhole() > 0)
	{
		// Евро к рублю
		double exchangeValue = 84.82;

		exchangeBuffer.ruble.setWhole( one.euro.getWhole() * exchangeValue );
		exchangeBuffer.ruble.setPenny( one.euro.getPenny() * exchangeValue );
	}
	else if(one.ruble.getWhole() > 0)
	{
		exchangeBuffer.ruble.setWhole( one.ruble.getWhole() );
		exchangeBuffer.ruble.setPenny( one.ruble.getPenny() );
	}

	return exchangeBuffer;
}

Money Money::exchangeToDollar( Money one )
{
	Money exchangeBuffer;

	if(one.ruble.getWhole() > 0)
	{
		// Рубль к доллару
		double exchangeValue = 0.013;

		exchangeBuffer.dollar.setWhole( one.ruble.getWhole() * exchangeValue );
		exchangeBuffer.dollar.setPenny( one.ruble.getPenny() * exchangeValue );
	}
	else if(one.euro.getWhole() > 0)
	{
		// Евро в доллар
		double exchangeValue = 1.14;

		exchangeBuffer.dollar.setWhole( one.euro.getWhole() * exchangeValue );
		exchangeBuffer.dollar.setPenny( one.euro.getPenny() * exchangeValue );
	}
	else if(one.dollar.getWhole() > 0)
	{
		exchangeBuffer.dollar.setWhole( one.dollar.getWhole() );
		exchangeBuffer.dollar.setPenny( one.dollar.getPenny() );
	}

	return exchangeBuffer;
}

Money Money::exchangeToEuro( Money one )
{
	Money exchangeBuffer;

	if(one.ruble.getWhole() > 0)
	{
		//Рубль в евро
		double exchangeValue = 0.012;

		exchangeBuffer.euro.setWhole( one.ruble.getWhole() * exchangeValue );
		exchangeBuffer.euro.setPenny( one.ruble.getPenny() * exchangeValue );
	}
	else if(one.dollar.getWhole() > 0)
	{
		//Доллар в евро
		double exchangeValue = 0.88;

		exchangeBuffer.euro.setWhole( one.dollar.getWhole() * exchangeValue );
		exchangeBuffer.euro.setPenny( one.dollar.getPenny() * exchangeValue );
	}
	else if(one.euro.getWhole() > 0)
	{
		exchangeBuffer.euro.setWhole( one.euro.getWhole() );
		exchangeBuffer.euro.setPenny( one.euro.getPenny() );
	}

	return exchangeBuffer;
}

void Money::add( Money one , Money two )
{

	// Монета в рублях, первой монеты (ой)
	Money exchangeRubleOne;

	// Монета в рублях, второй монеты (ой)
	Money exchangeRubleTwo;

	//Монета результата
	Money bufferResult;

	//Конвертируем первую и вторую монету в основную
	exchangeRubleOne = Money::exchangeToRuble( one );
	exchangeRubleTwo = Money::exchangeToRuble( two );

	// Инициализаруем результат сложения двух монет
	bufferResult.ruble.setWhole( exchangeRubleOne.ruble.getWhole() + exchangeRubleTwo.ruble.getWhole() );
	bufferResult.ruble.setPenny( exchangeRubleOne.ruble.getPenny() + exchangeRubleTwo.ruble.getPenny() );

	// Выводим результат сложения
	std::cout << std::fixed << std::setprecision( 0 ) << " Результат сложения в рублях: " << bufferResult.ruble.getWhole() << " Копеек: " << std::setfill( '0' ) << std::setw( 2 ) << bufferResult.ruble.getPenny() << std::endl;

	// Переводим в доллары c выводом результата
	bufferResult = Money::exchangeToDollar( bufferResult );
	std::cout << " Результат сложения в долларах: " << bufferResult.dollar.getWhole() << " Копеек: " << std::setfill( '0' ) << std::setw( 2 ) << bufferResult.dollar.getPenny() << std::endl;

	// Перевод в евро с выводом результата
	bufferResult = Money::exchangeToEuro( bufferResult );
	std::cout << " Результат сложения в евро: " << bufferResult.euro.getWhole() << " Копеек: " << std::setfill( '0' ) << std::setw( 2 ) << bufferResult.euro.getPenny() << std::endl;
	std::cout << std::endl;

}

void Money::sub( Money one , Money two )
{

	// Монета в рублях, первой монеты (ой)
	Money exchangeRubleOne;

	// Монета в рублях, второй монеты (ой)
	Money exchangeRubleTwo;

	// Монета результата
	Money bufferResult;

	//Конвертируем первую и вторую монету в основную
	exchangeRubleOne = Money::exchangeToRuble( one );
	exchangeRubleTwo = Money::exchangeToRuble( two );

	// Инициализаруем результат сложения двух монет
	bufferResult.ruble.setWhole( exchangeRubleOne.ruble.getWhole() - exchangeRubleTwo.ruble.getWhole() );
	bufferResult.ruble.setPenny( exchangeRubleOne.ruble.getPenny() - exchangeRubleTwo.ruble.getPenny() );

	// Выводим результат сложения
	std::cout << std::fixed << std::setprecision( 0 ) << " Результат разности в рублях: " << bufferResult.ruble.getWhole() << " Копеек: " << std::setfill( '0' ) << std::setw( 2 ) << bufferResult.ruble.getPenny() << std::endl;

	// Переводим в доллары c выводом результата
	bufferResult = Money::exchangeToDollar( bufferResult );
	std::cout << " Результат разности в долларах: " << bufferResult.dollar.getWhole() << " Копеек: " << std::setfill( '0' ) << std::setw( 2 ) << bufferResult.dollar.getPenny() << std::endl;

	// Перевод в евро с выводом результата
	bufferResult = Money::exchangeToEuro( bufferResult );
	std::cout << " Результат разности в евро: " << bufferResult.euro.getWhole() << " Копеек: " << std::setfill( '0' ) << std::setw( 2 ) << bufferResult.euro.getPenny() << std::endl;
	std::cout << std::endl;

}

void Money::div( Money one , Money two )
{

	// Монета в рублях, первой монеты (ой)
	Money exchangeRubleOne;

	// Монета в рублях, второй монеты (ой)
	Money exchangeRubleTwo;

	// Монета результата
	Money bufferResult;

	//Конвертируем первую и вторую монету в основную
	exchangeRubleOne = Money::exchangeToRuble( one );
	exchangeRubleTwo = Money::exchangeToRuble( two );

	// Инициализаруем результат сложения двух монет
	bufferResult.ruble.setWhole( exchangeRubleOne.ruble.getWhole() / exchangeRubleTwo.ruble.getWhole() );
	bufferResult.ruble.setPenny( exchangeRubleOne.ruble.getPenny() / exchangeRubleTwo.ruble.getPenny() );

	// Выводим результат сложения
	std::cout << std::fixed << std::setprecision( 0 ) << " Результат частного в рублях: " << bufferResult.ruble.getWhole() << " Копеек: " << std::setfill( '0' ) << std::setw( 2 ) << bufferResult.ruble.getPenny() << std::endl;

	// Переводим в доллары c выводом результата
	bufferResult = Money::exchangeToDollar( bufferResult );
	std::cout << " Результат частного в долларах: " << bufferResult.dollar.getWhole() << " Копеек: " << std::setfill( '0' ) << std::setw( 2 ) << bufferResult.dollar.getPenny() << std::endl;

	// Перевод в евро с выводом результата
	bufferResult = Money::exchangeToEuro( bufferResult );
	std::cout << " Результат частного в евро: " << bufferResult.euro.getWhole() << " Копеек: " << std::setfill( '0' ) << std::setw( 2 ) << bufferResult.euro.getPenny() << std::endl;
	std::cout << std::endl;

}

void Money::mult( Money one , Money two )
{

	// Монета в рублях, первой монеты (ой)
	Money exchangeRubleOne;

	// Монета в рублях, второй монеты (ой)
	Money exchangeRubleTwo;

	// Монета результата
	Money bufferResult;

	//Конвертируем первую и вторую монету в основную
	exchangeRubleOne = Money::exchangeToRuble( one );
	exchangeRubleTwo = Money::exchangeToRuble( two );

	// Инициализаруем результат сложения двух монет
	bufferResult.ruble.setWhole( exchangeRubleOne.ruble.getWhole() * exchangeRubleTwo.ruble.getWhole() );
	bufferResult.ruble.setPenny( exchangeRubleOne.ruble.getPenny() * exchangeRubleTwo.ruble.getPenny() );

	// Выводим результат сложения
	std::cout << std::fixed << std::setprecision( 0 ) << " Результат произведения в рублях: " << bufferResult.ruble.getWhole() << " Копеек: " << std::setfill( '0' ) << std::setw( 2 ) << bufferResult.ruble.getPenny() << std::endl;

	// Переводим в доллары c выводом результата
	bufferResult = Money::exchangeToDollar( bufferResult );
	std::cout << " Результат произведения в долларах: " << bufferResult.dollar.getWhole() << " Копеек: " << std::setfill( '0' ) << std::setw( 2 ) << bufferResult.dollar.getPenny() << std::endl;

	// Перевод в евро с выводом результата
	bufferResult = Money::exchangeToEuro( bufferResult );
	std::cout << " Результат произведения в евро: " << bufferResult.euro.getWhole() << " Копеек: " << std::setfill( '0' ) << std::setw( 2 ) << bufferResult.euro.getPenny() << std::endl;
	std::cout << std::endl;

}

void Money::comparison( Money one , Money two )
{

	// Монета в рублях, первой монеты (ой)
	Money exchangeRubleOne;

	// Монета в рублях, второй монеты (ой)
	Money exchangeRubleTwo;

	//Конвертируем первую и вторую монету в основную
	exchangeRubleOne = Money::exchangeToRuble( one );
	exchangeRubleTwo = Money::exchangeToRuble( two );

	//Сравнение целых чисел валют, так как копейки роли не сыграют.
	if(exchangeRubleOne.getRubleWhole() > exchangeRubleTwo.getRubleWhole())
	{
		std::cout << " \n\nПервая валюта больше второй\n";
	}
	else if(exchangeRubleTwo.getRubleWhole() > exchangeRubleOne.getRubleWhole())
	{
		std::cout << " \n\nВторая валюта больше первой\n";
	}
	else if(exchangeRubleOne.getRubleWhole() == exchangeRubleTwo.getRubleWhole())
	{
		std::cout << " \n\nВалюты равны\n";
	}

}

#pragma endregion

#pragma region SETTERS

void Money::setDollar( double whole , double penny )
{
	this->dollar.setWhole( whole );
	this->dollar.setPenny( penny );
}

void Money::setEuro( double whole , double penny )
{
	this->euro.setWhole( whole );
	this->euro.setPenny( penny );
}

void Money::setRuble( double whole , double penny )
{
	this->ruble.setWhole( whole );
	this->ruble.setPenny( penny );
}

#pragma endregion

#pragma region GETTERS

double Money::getDollarWhole()
{
	return Money::dollar.getWhole();
}

double Money::getDollarPenny()
{
	return Money::dollar.getPenny();
}

double Money::getEuroWhole()
{
	return Money::euro.getWhole();
}

double Money::getEuroPenny()
{
	return Money::euro.getPenny();
}

double Money::getRubleWhole()
{
	return Money::ruble.getWhole();
}

double Money::getRublePenny()
{
	return Money::ruble.getPenny();
}

#pragma endregion