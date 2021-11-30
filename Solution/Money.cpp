#include "Money.h"

#pragma region METHODS

Money Money::exchange( Money one )
{
    Money exchangeBuffer;

    if( one.dollar.getWhole() > 0 )
    {
        // Доллар к рублю
        double exchangeValue = 74.86;

        exchangeBuffer.ruble.setWhole( one.dollar.getWhole() * exchangeValue );
        exchangeBuffer.ruble.setPenny( one.dollar.getPenny() * exchangeValue );
    }
    else if( one.euro.getWhole() > 0 )
    {
        // Евро к рублю
        double exchangeValue = 84.82;

        exchangeBuffer.ruble.setWhole( one.euro.getWhole() * exchangeValue );
        exchangeBuffer.ruble.setPenny( one.euro.getPenny() * exchangeValue );
    }
    else if( one.ruble.getWhole() > 0 )
    {
        exchangeBuffer.ruble.setWhole( one.ruble.getWhole());
        exchangeBuffer.ruble.setPenny( one.ruble.getPenny());
    }

    return exchangeBuffer;
}

void Money::add( Money one, Money two )
{
    // Монета в рублях, первой монеты (ой)
    Money exchangeRubleOne;

    // Монета в рублях, второй монеты (ой)
    Money exchangeRubleTwo;

    if( one.dollar.getWhole() > 0 )
    {
        exchangeRubleOne = Money::exchange( one );
    }
}

#pragma endregion

#pragma region SETTERS

void Money::setDollar( double whole, double penny )
{
    this->dollar.setWhole(whole);
    this->dollar.setPenny( penny );
}

void Money::setEuro( double whole, double penny )
{
    this->euro.setWhole( whole );
    this->euro.setPenny( penny );
}

void Money::setRuble( double whole, double penny )
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