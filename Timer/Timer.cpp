#include "Timer.h"

class Timer
{
private:
    int second = 0;
public:

    void setCursor( int x , int y )
    {
        HANDLE console = GetStdHandle( STD_OUTPUT_HANDLE );
        COORD cursorPosition{ x,y };
        SetConsoleCursorPosition( console , cursorPosition );
    }
    void deleteCursor()
    {
        HANDLE console = GetStdHandle( STD_OUTPUT_HANDLE );
        CONSOLE_CURSOR_INFO info{ 100,false };
        SetConsoleCursorInfo( console , &info );
    }

    void run()
    {
        second = 0;
        while(true)
        {
            setCursor( 4 , 0 );
            std::cout << "ОСТАНОВИТЬ";
            setCursor( 1 , 7 );
            std::cout << "Для выхода нажмите 2\n"
                << " Для обнуления, нажмите любую кнопку два раза";
            setCursor( 5 , 1 );
            std::cout << std::setfill( '0' ) << std::setw( 2 ) << second / 60 / 60 << ":" << std::setfill( '0' ) << std::setw( 2 ) << second / 60 << ":" << std::setfill( '0' ) << std::setw( 2 ) << second % 60;
            std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
            second += 1;

            if(_kbhit())
            {
                setCursor( 4 , 0 );
                std::cout << "  СТАРТ       ";
                int a = _getch() - 48;
                if(a == 2)
                {
                    break;
                }
                system( "pause >> NUL" );
                second = 0;
            }
        }
    }
};