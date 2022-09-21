#include <string>
#include <vector>

class Solution
{
public:
    bool isAnagram(std::string s, std::string t)
    {
        if (s.size() != t.size())
            return false;

        std::vector<int> freq(255, 0);

        for (int i = 0; i < s.size(); i++)
        {
            freq[s[i]]++;
            freq[t[i]]--;
        }

        for (auto it : freq)
        {
            if (it != 0)
                return false;
        }

        return true;
    }
};

