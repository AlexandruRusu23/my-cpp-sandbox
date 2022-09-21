#include <string>

class Solution
{
public:
    int titleToNumber(std::string columnTitle)
    {
        int output = 0;
        int expo = 1;
        int n = columnTitle.size();

        while (--n >= 0)
        {
            output += (columnTitle[n] - 'A' + 1) * expo;
            if (n > 0)
                expo *= 26;
        }

        return output;
    }
};

