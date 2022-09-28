#include <cstdint>

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        int counter = sizeof(uint32_t) * 8 - 1;
        uint32_t output = 0;
        int bit;
        while (n)
        {
            bit = n & 1;
            n >>= 1;
            output |= (bit << counter);
            counter--;
        }

        return output;
    }
};

