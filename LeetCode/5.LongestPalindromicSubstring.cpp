#include <string>
#include <string.h>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int n = s.size();
        int left = 0;
        int size = 1;
        bool dp[n][n];
        memset(dp, false, sizeof(dp));
        
        for (int i = 0; i < n - 1; i++)
        {
            dp[i][i] = true;
            if (s[i] == s[i+1])
            {
                dp[i][i+1] = true;
                left = i;
                size = 2;
            }
        }
        
        for (int len = 3; len <= n; len++)
        {
            for (int i = 0; i <= n - len; i++)
            {
                int j = i + len - 1;
                
                if (dp[i+1][j-1] && s[i] == s[j])
                {
                    dp[i][j] = true;
                    left = i;
                    size = len;
                }
            }
        }
        
        return s.substr(left, size);
    }
};

