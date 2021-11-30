#include "Money.h"

#pragma region METHODS

Money Money::exchangeToRuble( Money one )
{
    Money exchangeBuffer;

    if( one.dollar.getWhole() > 0 )
    {
        // ������ � �����
        double exchangeValue = 74.86;

        exchangeBuffer.ruble.setWhole( one.dollar.getWhole() * exchangeValue );
        exchangeBuffer.ruble.setPenny( one.dollar.getPenny() * exchangeValue );
    }
    else if( one.euro.getWhole() > 0 )
    {
        // ���� � �����
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

Money Money::exchangeToDollar(Money one)
{
    Money exchangeBuffer;

    if (one.ruble.getWhole() > 0)
    {
        // ����� � �������
        double exchangeValue = 0.013;

        exchangeBuffer.dollar.setWhole(one.ruble.getWhole() * exchangeValue);
        exchangeBuffer.dollar.setPenny(one.ruble.getPenny() * exchangeValue);
    }
    else if (one.euro.getWhole() > 0)
    {
        // ���� � ������
        double exchangeValue = 1.14;

        exchangeBuffer.dollar.setWhole(one.euro.getWhole() * exchangeValue);
        exchangeBuffer.dollar.setPenny(one.euro.getPenny() * exchangeValue);
    }
    else if (one.dollar.getWhole() > 0)
    {
        exchangeBuffer.dollar.setWhole(one.dollar.getWhole());
        exchangeBuffer.dollar.setPenny(one.dollar.getPenny());
    }

    return exchangeBuffer;
}

Money Money::exchangeToEuro(Money one)
{
    Money exchangeBuffer;

    if(one.ruble.getWhole() > 0 )
    {
        //����� � ����
        double exchangeValue = 0.012;

        exchangeBuffer.euro.setWhole(one.ruble.getWhole() * exchangeValue);
        exchangeBuffer.euro.setPenny(one.ruble.getPenny() * exchangeValue);
    }
    else if (one.dollar.getWhole() > 0)
    {
        //������ � ����
        double exchangeValue = 0.88;

        exchangeBuffer.euro.setWhole(one.dollar.getWhole() * exchangeValue);
        exchangeBuffer.euro.setPenny(one.dollar.getPenny() * exchangeValue);
    }
    else if (one.euro.getWhole() > 0)
    {
        exchangeBuffer.euro.setWhole(one.euro.getWhole());
        exchangeBuffer.euro.setPenny(one.euro.getPenny());
    }

    return exchangeBuffer;
}

void Money::add(Money one, Money two)
{
    // ������ � ������, ������ ������ (��)
    Money exchangeRubleOne;

    // ������ � ������, ������ ������ (��)
    Money exchangeRubleTwo;

    //������ ����������
    Money bufferResult;

    //������������ ������ � ������ ������ � ��������
    exchangeRubleOne = Money::exchangeToRuble(one);
    exchangeRubleTwo = Money::exchangeToRuble(two);

    // �������������� ��������� �������� ���� �����
    bufferResult.ruble.setWhole(exchangeRubleOne.ruble.getWhole() + exchangeRubleTwo.ruble.getWhole());
    bufferResult.ruble.setPenny(exchangeRubleOne.ruble.getPenny() + exchangeRubleTwo.ruble.getPenny());

    // ������� ��������� ��������
    std::cout << " ����� � ������: " << bufferResult.ruble.getWhole() << " ������: " << bufferResult.ruble.getPenny() << std::endl;

    // ��������� � ������� c ������� ����������
    bufferResult = Money::exchangeToDollar(bufferResult);
    std::cout << " ����� � ��������: " << bufferResult.dollar.getWhole() << " ������: " << bufferResult.dollar.getPenny() << std::endl;

    // ������� � ���� � ������� ����������
    bufferResult = Money::exchangeToEuro(bufferResult);
    std::cout << " ����� � ����: " << bufferResult.euro.getWhole() << " ������: " << bufferResult.euro.getPenny() << std::endl;
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