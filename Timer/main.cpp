#include "Timer.cpp"


int main()
{
	HWND hwnd = GetConsoleWindow();
	HMENU hmenu = GetSystemMenu( hwnd , FALSE );
	DeleteMenu( hmenu , SC_MAXIMIZE , MF_BYCOMMAND );
	DeleteMenu( hmenu , SC_MINIMIZE , MF_BYCOMMAND );
	DeleteMenu( hmenu , SC_CLOSE , MF_BYCOMMAND );

	system( "title Таймер" );
	system( "mode con cols=60 lines=9" );
	setlocale( 0 , "rus" );
	Timer newTimer;
	newTimer.deleteCursor();
	do
	{
		system( "cls" );
		std::cout << "После старта программы, нужно будет нажать любую кнопку\n"
			<< "    для остановки, все так же, любая кнопка\n\n";
		std::cout << "1: Старт\n2: Выход\n";
		int a = _getch() - 48;
		switch(a)
		{
			case 1:
				{
					system( "cls" );
					newTimer.run();
					break;
				}
			case 2:
				{
					exit( 1 );
					break;
				}
			default:
				break;
		}
	} while(true);
}