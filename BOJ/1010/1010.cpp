#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class obj
{
public:
	int a;
	int b;

	obj( int x, int y ) :a( x ), b( y ) {}
};

vector<obj> ob_arr;

int bin( int n, int k )
{
	long int arr[ 31 ][ 31 ];
	for( int i = 0; i <= n; i++ )
	{
		for( int j = 0; j <= min( i, k ); j++ )
		{
			if( j == 0 || i == j )
			{
				arr[ i ][ j ] = 1;
			}
			else
			{
				arr[ i ][ j ] = arr[ i - 1 ][ j - 1 ] + arr[ i - 1 ][ j ];
			}
		}
	}

	return arr[ n ][ k ];
}

int main()
{
	int temp;
	cin >> temp;

	for( size_t i = 0; i < temp; i++ )
	{
		int x;
		int y;	//M
		cin >> x >> y;
		ob_arr.push_back( obj( y, x ) );
	}

	for( size_t i = 0; i < temp; i++ )
	{
		int a = ob_arr[ i ].a;
		int b = ob_arr[ i ].b;

		cout << bin( a, b ) << endl;
	}

	//system("pause");
}