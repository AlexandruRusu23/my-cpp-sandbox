#include <string>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int i = 0;
        int j = s.size() - 1;
        while ( i < j )
        {
            while (!isalnum(s[i]) && i < j)
            {
                i++;
            }
            
            while (!isalnum(s[j]) && i < j)
            {
                j--;
            }
            
            if (i > j)
                break;
            
            if (std::tolower(s[i]) != std::tolower(s[j]))
                return false;
            
            i++;
            j--;
        }
        
        return true;
    }
};

