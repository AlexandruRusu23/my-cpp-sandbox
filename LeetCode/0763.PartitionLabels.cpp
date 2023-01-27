#include <string>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> partitionLabels(std::string s)
    {
        std::vector<int> output;
        std::unordered_map<char, size_t> freq;

        for (size_t i = 0; i < s.size(); i++)
            freq[s[i]] = i;

        size_t left = 0, right;
        size_t prev_left = 0;

        while (left < s.size())
        {
            right = freq[s[left]];
            while (left < right)
            {
                if (freq[s[left]] > right)
                {
                    right = freq[s[left]];
                }
                left++;
            }

            if (left == right)
            {
                output.push_back(right - prev_left + 1);
                left++;
                prev_left = left;
            }
        }

        return output;
    }
};

