#include <cstdint>

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int output = 0;

        while (n)
        {
            output++;
            n = n & (n - 1);
        }

        return output;
    }
};

