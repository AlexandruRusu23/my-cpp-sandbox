#include <vector>
#include <string>

class Solution
{
public:
    std::vector<std::string> summaryRanges(std::vector<int> &nums)
    {
        if (nums.empty())
            return {};

        int first = 0;
        int second = 0;
        std::vector<std::string> output;
        while (second < nums.size())
        {
            if (second + 1 < nums.size() && nums[second] + 1 == nums[second + 1])
            {
                second++;
            }
            else
            {
                if (nums[first] == nums[second])
                    output.push_back(std::to_string(nums[first]));
                else
                    output.push_back(std::to_string(nums[first]) + "->" + std::to_string(nums[second]));

                first = second + 1;
                second = second + 1;
            }
        }

        return output;
    }
};

