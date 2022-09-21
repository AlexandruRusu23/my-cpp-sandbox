#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> generate(int numRows)
    {
        std::vector<std::vector<int>> output;

        for (int i = 0; i < numRows; i++)
        {
            std::vector<int> row(i + 1);
            row[0] = 1;
            row[row.size() - 1] = 1;

            for (int j = 1; j < i; j++)
            {
                row[j] = output[i - 1][j - 1] + output[i - 1][j];
            }

            output.emplace_back(row);
        }
        return output;
    }
};

