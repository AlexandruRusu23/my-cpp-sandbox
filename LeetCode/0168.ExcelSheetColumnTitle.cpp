#include <string>

class Solution
{
public:
    std::string convertToTitle(int columnNumber)
    {
        std::string output = "";
        columnNumber--;

        while (columnNumber >= 0)
        {
            output = static_cast<char>('A' + columnNumber % 26) + output;
            columnNumber /= 26;
            columnNumber--;
        }

        return output;
    }
};

