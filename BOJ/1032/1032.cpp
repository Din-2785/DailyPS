#include <iostream>
#include <vector>
#include <string>

bool IsPatternChar( const int compareCharIdx,
					const int inputListSize,
					const std::vector<std::string>& inputList )
{
	bool ret = true ;

	const char compareTargetChar = inputList[ 0 ][ compareCharIdx ] ;

	for( int inputListIdx = 0; inputListIdx < inputListSize; inputListIdx++ )
	{
		if( compareTargetChar != inputList[ inputListIdx ][ compareCharIdx ] )
		{
			ret = false ;
			
			break ;
		}
	}

	return ret ;
}

int main()
{
	int n = 0 ;

	std::cin >> n ;

	if( 0 == n )
	{
		return 0 ;
	}

	int inputListSize = 0 ;
	int inputStringSize = 0 ;

	std::string res ; 
	std::vector<std::string> inputList ;

	//유저 입력
	for( int i = 0; i < n; i++ )
	{
		std::string userInput ;
		std::cin >> userInput ;

		inputList.push_back( userInput ) ;
	}

	inputListSize = inputList.size() ;

	if( 0 == inputListSize )
	{
		return 0 ;
	}

	inputStringSize = inputList[ 0 ].size() ;
	
	for( int compareCharIdx = 0; compareCharIdx < inputStringSize; compareCharIdx++ )
	{
		bool isPatternChar = IsPatternChar( compareCharIdx, inputListSize, inputList ) ;

		if( true == isPatternChar )
		{
			res.push_back( inputList[ 0 ][ compareCharIdx ] ) ;
		}
		else
		{
			res.push_back( '?' ) ;
		}
	}

	std::cout << res << std::endl ;

}