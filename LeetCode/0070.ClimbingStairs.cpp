class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        int first = 1, second = 2;
        int index = 3;
        while (index <= n)
        {
            int aux = first + second;
            first = second;
            second = aux;
            index++;
        }

        return second;
    }
};
