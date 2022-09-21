#include <string>
#include <unordered_map>

class Solution
{
public:
    bool isIsomorphic(std::string s, std::string t)
    {
        std::unordered_map<char, char> key_binds;

        for (int i = 0; i < s.size(); i++)
        {
            if (key_binds.find(t[i]) != key_binds.end())
            {
                if (key_binds[t[i]] != s[i])
                    return false;
            }
            else
            {
                key_binds[t[i]] = s[i];
            }
        }

        return true;
    }
};

