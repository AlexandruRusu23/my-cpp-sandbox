#include <string>
#include <unordered_map>

class Solution
{
public:
    bool checkInclusion(std::string s1, std::string s2)
    {
        if (s2.size() < s1.size())
            return false;

        std::unordered_map<char, int> freq_s1;
        if (s1.size() == s2.size())
        {
            for (size_t i = 0; i < s1.size(); i++)
            {
                freq_s1[s1[i]]++;
                freq_s1[s2[i]]--;
            }

            for (auto &it : freq_s1)
            {
                if (it.second != 0)
                    return false;
            }

            return true;
        }

        std::unordered_map<char, int> freq_s2;
        for (size_t i = 0; i < s1.size(); i++)
        {
            freq_s1[s1[i]]++;
        }

        for (size_t i = 0; i < s2.size(); i++)
        {
            freq_s2.clear();
            if (i + s1.size() > s2.size())
                break;

            for (size_t j = 0; j < s1.size(); j++)
            {
                freq_s2[s2[i + j]]++;
            }

            if (freq_s1 == freq_s2)
                return true;
        }
        return false;
    }
};

