#include <vector>

class Solution
{
public:
    int missingNumber(std::vector<int> &nums)
    {
        int output = 0;

        for (size_t i = 0; i < nums.size(); i++)
        {
            output ^= i ^ nums[i];
        }

        return output ^ nums.size();
    }

    int missingNumberSol2(std::vector<int> &nums)
    {
        int output = 0;

        for (size_t i = 0; i < nums.size(); i++)
        {
            output += nums[i];
            output -= i;
        }

        output -= nums.size();

        return -output;
    }
};

