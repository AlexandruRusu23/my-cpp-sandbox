#include <string>
#include <string.h>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int index = 0;
        int freq[256];
        memset(freq, -1, sizeof(freq));

        int size = 0, max = 0;

        if ( s.empty() )
            return max;

        while ( index < s.size() )
        {
            if ( freq[s[index]] > -1 )
            {
                index = freq[s[index]];
                memset(freq, -1, sizeof(freq));
                if ( max < size )
                    max = size;
                size = 0;
            }
            else
            {
                freq[ s[ index ] ] = index;
                size++;
            }

            index++;
        }

        if ( max < size )
            max = size;

        return max;
    }
};

