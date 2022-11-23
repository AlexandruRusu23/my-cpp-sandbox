#include <vector>

class Solution
{
public:
    std::vector<int> countBits(int n)
    {
        std::vector<int> output;

        for (int i = 0; i <= n; i++)
        {
            int copy = i;
            int number = 0;
            while (copy)
            {
                number++;
                copy = copy & (copy - 1);

                if (output.size() > copy)
                {
                    number += output[copy];
                    break;
                }
            }
            output.push_back(number);
        }

        return output;
    }
};

