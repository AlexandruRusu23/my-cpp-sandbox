#include <vector>

class Solution
{
public:
    int singleNumber(std::vector<int> &nums)
    {
        int output = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            output ^= nums[i];
        }

        return output;
    }
};

