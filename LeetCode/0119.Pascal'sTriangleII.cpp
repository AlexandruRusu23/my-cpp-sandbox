#include <vector>

class Solution
{
public:
    std::vector<int> getRow(int rowIndex)
    {
        std::vector<int> prev_row = {1};
        std::vector<int> output = {1};

        for (int i = 1; i <= rowIndex; i++)
        {
            output.resize(i + 1);
            output[0] = 1;
            output[output.size() - 1] = 1;

            for (int j = 1; j < i; j++)
            {
                output[j] = prev_row[j - 1] + prev_row[j];
            }
            prev_row = output;
        }

        return output;
    }
};

