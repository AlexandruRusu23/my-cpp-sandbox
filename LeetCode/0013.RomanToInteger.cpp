#include <string>

class Solution
{
public:
    int romanToInt(std::string s)
    {
        int output = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            int num = 0;
            switch (s[i])
            {
            case 'I':
                num = 1;
                break;
            case 'V':
                num = 5;
                break;
            case 'X':
                num = 10;
                break;
            case 'L':
                num = 50;
                break;
            case 'C':
                num = 100;
                break;
            case 'D':
                num = 500;
                break;
            case 'M':
                num = 1000;
                break;
            default:
                num = 0;
                break;
            }
            if (num * 4 < output)
                output -= num;
            else
                output += num;
        }

        return output;
    }
};

