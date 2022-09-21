#include <vector>
#include <unordered_set>

class Solution
{
public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        std::unordered_set<int> numbers;

        for (auto it : nums)
        {
            if (numbers.find(it) != numbers.end())
            {
                return true;
            }
            else
            {
                numbers.insert(it);
            }
        }

        return false;
    }
};

