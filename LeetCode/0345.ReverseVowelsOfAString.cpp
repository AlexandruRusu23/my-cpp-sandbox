#include <string>

class Solution
{
public:
    std::string reverseVowels(std::string s)
    {
        bool vowels[256];
        std::memset(vowels, false, 256);
        vowels['a'] = true;
        vowels['e'] = true;
        vowels['i'] = true;
        vowels['o'] = true;
        vowels['u'] = true;
        vowels['A'] = true;
        vowels['E'] = true;
        vowels['I'] = true;
        vowels['O'] = true;
        vowels['U'] = true;
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            if (vowels[s[left]] == false)
                left++;
            else if (vowels[s[right]] == false)
                right--;
            else
            {
                std::swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};

