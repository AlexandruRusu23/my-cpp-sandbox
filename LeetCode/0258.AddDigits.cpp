class Solution
{
public:
    int getDigitsSum(int n)
    {
        int output = 0;

        while (n)
        {
            output += n % 10;
            n /= 10;
        }

        return output;
    }

    int addDigitsRecursive(int num)
    {
        while (num > 9)
        {
            num = getDigitsSum(num);
        }

        return num;
    }

    int addDigits(int num)
    {
        return 1 + (num - 1) % 9;
    }
};

