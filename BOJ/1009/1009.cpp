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

		//���������� �ʿ��� �ŵ����� Ƚ���� ����(b �� ��ȯ)
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

		//res �� 0�̶�� ���� 10��° ��ǻ������ ����
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