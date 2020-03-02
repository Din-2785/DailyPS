#include<iostream>
#include<vector>

int main()
{
	int numberOfTestCase = 0 ;
	
	std::cin >> numberOfTestCase ;

	std::vector<int> resultList ;

	for( int testIdx = 0; testIdx < numberOfTestCase; testIdx++ )
	{
		int a = 0 ;
		int b = 0 ;
		
		std::cin >> a >> b ;

		//실질적으로 필요한 거듭제곱 횟수를 구함(b 값 변환)
		int exactPowerCnt = ( b % 4 ) ;
		
		if( 0 == exactPowerCnt )
		{
			exactPowerCnt = 4 ;
		}
		
		int res = 1 ;

		for( int multipleCnt = 1; multipleCnt <= exactPowerCnt ; multipleCnt++ )
		{
			res = res * a ;
		}

		res = res % 10 ;

		//res 가 0이라는 뜻은 10번째 컴퓨터임을 말함
		if( 0 == res )
		{
			resultList.push_back( 10 ) ;
		}
		else
		{
			resultList.push_back( res ) ;
		}
	}
	
	for( int res : resultList )
	{
		std::cout << res << std::endl ;
	}
}