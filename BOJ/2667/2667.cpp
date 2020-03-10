#include <iostream>
#include <vector>

static int n ;
static int complexCnt = 0 ;
static char map[ 25 ][ 25 ]{ 0, } ;
static bool isVisited[ 25 ][ 25 ]{ false, } ;
static std::vector<int> houseCntList ;

void Dfs( int nameIdx, int i, int j, int &houseCnt )
{
	if( 0 > i || 0 > j )
	{
		return ;
	}
	else if( ( n - 1 ) < i || ( n - 1 ) < j )
	{
		return ;
	}
	else
	{
		if( false == isVisited[ i ][ j ] && '1' == map[ i ][ j ] )
		{
			isVisited[ i ][ j ] = true ;
			houseCnt++ ;

			Dfs( nameIdx, i + 1, j, houseCnt ) ;
			Dfs( nameIdx, i - 1, j, houseCnt ) ;
			Dfs( nameIdx, i, j + 1, houseCnt ) ;
			Dfs( nameIdx, i, j - 1, houseCnt ) ;
		}
	}
}

void insertion_sort( std::vector<int>& houseCntList )
{
	int sizeOfList = houseCntList.size() ;

	int i ;
	int j ;

	for( i = 1; i < sizeOfList; i++ )
	{
		int compareTarget = houseCntList[ i ] ;

		for( j = i - 1; ( j >= 0 ) && ( houseCntList[ j ] > compareTarget ) ; j-- )
		{
			houseCntList[ j + 1 ] = houseCntList[ j ] ;
		}

		houseCntList[ j + 1 ] = compareTarget ;
	}
}

int main()
{
	std::cin >> n ;

	for( int i = 0; i < n; i++ )
	{
		for( int j = 0; j < n; j++ )
		{
			std::cin >> map[ i ][ j ] ;
		}
	}

	for( int i = 0; i < n; i++ )
	{
		for( int j = 0; j < n; j++ )
		{
			if( false == isVisited[ i ][ j ] && '1' == map[ i ][ j ] )
			{
				int houseCnt = 0 ;

				Dfs( complexCnt, i, j, houseCnt ) ;

				houseCntList.push_back( houseCnt ) ;
				complexCnt++ ;
			}
		}
	}

	std::cout << complexCnt << std::endl ;
	
	insertion_sort( houseCntList ) ;

	for( int houseCnt : houseCntList )
	{
		std::cout << houseCnt << std::endl ;
	}
	
}