#include <string>
#include <sstream>
#include <unordered_map>

class Solution
{
public:
    bool wordPattern(std::string pattern, std::string s)
    {
        std::stringstream ss(s);
        std::string word;
        std::unordered_map<char, std::string> freq;
        std::unordered_map<std::string, char> un_freq;

        int i = 0;
        while (std::getline(ss, word, ' '))
        {
            if (freq.find(pattern[i]) != freq.end())
            {
                if (freq[pattern[i]] != word)
                    return false;
                if (un_freq[word] != pattern[i])
                    return false;
            }
            else
            {
                if (un_freq.find(word) != un_freq.end())
                {
                    if (un_freq[word] != pattern[i])
                        return false;
                }
                else
                {
                    freq[pattern[i]] = word;
                    un_freq[word] = pattern[i];
                }
            }
            i++;
        }

        if (i != pattern.size())
            return false;

        return true;
    }
};

