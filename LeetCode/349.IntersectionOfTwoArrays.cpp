#include <vector>
#include <unordered_set>

class Solution
{
public:
    std::vector<int> intersection(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
        {
            std::swap(nums1, nums2);
        }

        std::unordered_set<int> set1(nums1.begin(), nums1.end());
        std::unordered_set<int> out_set;

        for (size_t j = 0; j < nums2.size(); j++)
        {
            if (set1.find(nums2[j]) != set1.end())
            {
                out_set.insert(nums2[j]);
            }
        }

        return std::vector<int>(out_set.begin(), out_set.end());
    }
};

