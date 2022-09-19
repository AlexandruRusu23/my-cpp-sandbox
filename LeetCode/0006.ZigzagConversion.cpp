#include <string>
#include <vector>

class Solution
{
public:
    std::string convert(std::string s, int numRows)
    {
        if (numRows == 1)
            return s;

        std::vector<std::string> letters(numRows);

        int index = 0;
        int row = 0;
        bool ascending = true;

        while (index < s.size())
        {
            letters[row].push_back(s[index]);
            index++;

            if (ascending && row < numRows - 1)
            {
                row++;
                continue;
            }
            if (!ascending && row > 0)
            {
                row--;
                continue;
            }
            if (row == numRows - 1)
            {
                row--;
                ascending = false;
                continue;
            }
            if (row == 0)
            {
                row++;
                ascending = true;
                continue;
            }
        }

        std::string output = "";
        for (int i = 0; i < letters.size(); i++)
        {
            output += letters[i];
        }

        return output;
    }
};

