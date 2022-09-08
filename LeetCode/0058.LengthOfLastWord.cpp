#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s)
    {
        int last_index = s.size() - 1;
        while (last_index >= 0 && s[last_index] == ' ')
            last_index--;
        
        int count = 0;
        while (last_index >= 0 && s[last_index] != ' ')
        {
            count++;
            --last_index;
        }
        
        return count;
    }
};

