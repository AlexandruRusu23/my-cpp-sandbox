#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits)
    {
        int index = digits.size() - 1;
        while (index >= 0)
        {
            if (digits[index] + 1 > 9)
            {
                digits[index] = 0;
                index--;
            }
            else
            {
                digits[index]++;
                break;
            }
        }
        
        if (index == -1)
            digits.insert(digits.begin(), 1);
        
        return digits;
    }
};

