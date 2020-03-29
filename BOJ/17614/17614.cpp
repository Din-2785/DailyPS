#include<iostream>
#include<math.h>

int main()
{
	int clap = 0 ;
	int userinput = 0 ;

	std::cin >> userinput ;

	for( int i = 1; i <= userinput; i++ )
	{
		int copied_i = i ;

		for( int k = 6; k >= 0; k-- )
		{
			int quotient = copied_i / static_cast< int >( pow( 10, k ) ) ;

			if( 0 != quotient )
			{
				if( 3 == quotient ||
					6 == quotient ||
					9 == quotient )
				{
					clap++ ;
				}

				copied_i = copied_i % static_cast< int >( pow( 10, k ) ) ;
			}
		}
	}

	std::cout << clap << std::endl ;
}