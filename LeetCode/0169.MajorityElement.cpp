#include <vector>

class Solution
{
public:
    int majorityElement(std::vector<int> &nums)
    {
        int counter = 1;
        int output = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (counter == 0)
                output = nums[i];

            counter += output == nums[i] ? 1 : -1;
        }

        return output;
    }
};

