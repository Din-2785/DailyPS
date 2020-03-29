#include<iostream>

bool IsClockNumber( int x ) ;
int GetClockNumber( int card[] ) ;

int main()
{
	int count = 0 ;
	int userInput[ 4 ] ;

	for( int i = 0; i < 4; i++ )
	{
		std::cin >> userInput[ i ] ;
	}

	int calculatedClockNumber = GetClockNumber( userInput ) ;
	
	for( int i = 1111; i < calculatedClockNumber; i++ )
	{
		bool isClockNumber = IsClockNumber( i ) ;

		if( true == isClockNumber )
		{
			count++ ;
		}
	}

	std::cout << count + 1 << std::endl ;
}

int GetClockNumber( int card[] )
{
	int ret = 9999 ;
	
	for( int cardIndex = 0; cardIndex < 4; cardIndex++ )
	{
		//value from rotation
		int rtNumber = 0 ;
		int value4GetEachDigit = 1000 ;

		for( int iter = 0; iter < 4; iter++ )
		{
			rtNumber += card[ ( cardIndex + iter ) % 4 ] * value4GetEachDigit ;

			value4GetEachDigit /= 10 ;
		}

		if( rtNumber < ret )
		{
			ret = rtNumber ;
		}
	}

	return ret ;
}


bool IsClockNumber( int x )
{
	bool ret = false ;

	int card[ 4 ]{ 0, } ;
	int value4GetEachDigit = 1000 ;
	int target4Dividing = x ;

	for( int cardIndex = 0; cardIndex < 4; cardIndex++ )
	{
		card[ cardIndex ] = target4Dividing / value4GetEachDigit ;

		if( 0 == card[ cardIndex ] )
		{
			return ret ;
		}

		target4Dividing = target4Dividing % value4GetEachDigit ;

		value4GetEachDigit /= 10 ;
	}

	int clockNumber = GetClockNumber( card ) ;

	if( x == clockNumber )
	{
		ret = true ;
	}

	return ret ;
}
