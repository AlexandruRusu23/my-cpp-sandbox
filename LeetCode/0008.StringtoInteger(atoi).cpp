#include <climits>
#include <string>

class Solution
{
public:
    int myAtoi(std::string s)
    {
        int result = 0;
        bool negative = false;

        int pop = 0;

        int index = 0;
        while (index < s.size() && s[index] == ' ')
            index++;

        if (index == s.size())
            return result;

        if (s[index] == '-')
        {
            negative = true;
            index++;
        }
        else if (s[index] == '+')
            index++;

        if (index == s.size())
            return result;

        else if (s[index] != '+' && (s[index] < '0' && s[index] > '9'))
            return result;

        for (int i = index; i < s.size(); i++)
        {
            if (s[i] < '0' || s[i] > '9')
                break;

            pop = static_cast<int>(s[i] - '0');
            if (!negative && (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop >= 7)))
                return INT_MAX;
            if (negative && (result > INT_MAX / 10 || (result == INT_MAX / 10 && pop >= 8)))
                return INT_MIN;
            result = result * 10 + pop;
        }

        return negative ? -result : result;
    }
};

