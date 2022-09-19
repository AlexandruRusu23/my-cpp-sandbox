#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> hashmap;
        std::vector<int> output(2);

        for (int i = 0; i < nums.size(); i++)
        {
            if (hashmap.count(target - nums[i]) > 0)
            {
                output[0] = i;
                output[1] = hashmap[target - nums[i]];
            }
            else
            {
                hashmap[nums[i]] = i;
            }
        }

        return output;
    }
};

