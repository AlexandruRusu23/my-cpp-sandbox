#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string intToRoman(int num) {
        std::string output = "";
        int pop = 0;
        int order = 10;

        std::vector<std::vector<std::pair<int, std::string>>> legend( 10001 );
        legend[ 10 ].push_back( std::make_pair( 1, "I" ) );
        legend[ 10 ].push_back( std::make_pair( 5, "V" ) );
        legend[ 100 ].push_back( std::make_pair( 10, "X" ) );
        legend[ 100 ].push_back( std::make_pair( 50, "L" ) );
        legend[ 1000 ].push_back( std::make_pair( 100, "C" ) );
        legend[ 1000 ].push_back( std::make_pair( 500, "D" ) );
        legend[ 10000 ].push_back( std::make_pair( 1000, "M" ) );

        while ( num > 0 )
        {
            pop = num % order;
            num -= pop;

            if ( pop > 0 )
            {
                if ( 4 * legend[ order ][ 0 ].first == pop )
                {
                    output = output + legend[ order ][ 1 ].second + legend[ order ][ 0 ].second;
                }
                else if ( pop + pop / 9 >= order )
                {
                    output = output + legend[ order * 10 ][ 0 ].second + legend[ order ][ 0 ].second;
                }
                else
                {
                    std::string number = "";
                    for ( int i = legend[ order ].size() - 1; i >= 0; i-- )
                    {
                        while ( pop - legend[ order ][ i ].first >= 0 )
                        {
                            pop -= legend[ order ][ i ].first;
                            number = legend[ order ][ i ].second + number;
                        }
                    }
                    output = output + number;
                }
            }

            order *= 10;
        }

        std::reverse( output.begin(), output.end() );

        return output;
    }
};

