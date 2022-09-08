#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int index;
        
        while (left != right)
        {
            if (left > right)
                break;
            
            index = (right + left) / 2;
            
            if (target == nums[index])
                return index;
            
            if (target < nums[index])
                right = index - 1;
            else
                left = index + 1;
        }
        
        index = (right + left) / 2;
        
        if (target > nums[index])
            return index + 1;
        else
            return index;
    }
};

