class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
            return 0;

        int output = 1;

        while (output * output <= x)
        {
            if (output * output == x)
                return output;

            output++;

            if (x / output < output)
                break;
        }

        return output - 1;
    }
};

