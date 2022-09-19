
class Solution
{
public:
    int getSum(int n)
    {
        int output = 0;
        while (n)
        {
            int digit = n % 10;
            output += digit * digit;
            n /= 10;
        }

        return output;
    }

    bool isHappy(int n)
    {
        int slow, fast;
        slow = getSum(n);
        fast = getSum(slow);

        while (slow != fast)
        {
            slow = getSum(slow);
            fast = getSum(getSum(fast));
        }

        if (slow == 1)
            return true;
        return false;
    }
};

