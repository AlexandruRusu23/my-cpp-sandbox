#include <climits>

int reverse(int x)
{
    int reversed = 0;
    int last = 0;

    while (x)
    {
        last = x % 10;
        x /= 10;
        if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && last < -8))
            return 0;
        if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && last > 7))
            return 0;
        reversed = reversed * 10 + last;
    }

    return reversed;
}

