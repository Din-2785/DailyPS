#include <iostream>

int main()
{
	int stickLength = 64 ;
	int count = 0 ;
	
	int x ;
	std::cin >> x ;

	for( int shifter = 0; shifter <= 6; shifter++ )
	{
		int compareBit = ( 1 << shifter ) ;

		if( 0 != ( x & compareBit ) )
		{
			count++ ;
		}
	}

	std::cout << count << std::endl ;
}