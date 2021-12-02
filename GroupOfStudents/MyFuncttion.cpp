#include "MyFuncttion.h"

int randomInteger( int min , int max )
{
	return min + rand() % ( max - min);
}

std::string randomLine( std::string file )
{
	// рандомное число
	int bufferValue = randomInteger( 1 , getValueLineFile(file));

	std::ifstream in;
	in.open( file);
	std::string line;
	if(in.is_open())
	{
		while(in>>line)
		{
			for(int i = 0; i < bufferValue; i++)
			{
				in >> line;
			}
			break;
		}
	}
	in.close();
	return line;
}

int getValueLineFile( std::string file )
{
	int counter = 0;

	std::ifstream ot;
	ot.open( file );
	std::string buffer;
	if(ot.is_open())
	{
		while(!ot.eof())
		{
			ot >> buffer;
			counter++;
		}
		ot.close();
		return counter;
	}
}
