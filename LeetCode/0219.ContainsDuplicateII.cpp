#include <cmath>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    bool containsNearbyDuplicate(std::vector<int> &nums, int k)
    {
        std::unordered_map<int, int> numbers;

        for (int i = 0; i < nums.size(); i++)
        {
            if (numbers.find(nums[i]) != numbers.end())
            {
                if (std::abs(numbers[nums[i]] - i) <= k)
                    return true;
                else
                    numbers[nums[i]] = i;
            }
            else
            {
                numbers[nums[i]] = i;
            }
        }

        return false;
    }
};

