#include <cmath>
#include <vector>

class Solution
{
public:
    int maxArea(std::vector<int> &height)
    {
        int output = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right)
        {
            if (height[left] < height[right])
            {
                output = std::max(output, height[left] * (right - left));
                left++;
            }
            else
            {
                output = std::max(output, height[right] * (right - left));
                right--;
            }
        }

        return output;
    }
};

