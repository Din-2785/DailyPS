#include<iostream>

int main()
{
	int x, y, w, h ;

	std::cin >> x >> y >> w >> h ;

	int res = 0 ;
	
	for( int d = 0; d <= 1000; d++ )
	{
		if( 0 == ( x - d ) ||
			w == ( x + d ) )
		{
			res = d ;
		}
		else if( 0 == ( y - d ) ||
				 h == ( y + d ) )
		{
			res = d ;
		}

		if( 0 != res )
		{
			break ;
		}
	}

	std::cout << res ;
}