#include <string>

class Solution
{
public:
    std::string addBinary(std::string a, std::string b)
    {
        std::string output = "";

        int iter = a.size() - 1;
        int jter = b.size() - 1;

        bool isOver = false;

        while (iter >= 0 && jter >= 0)
        {
            if (a[iter] == b[jter])
            {
                output = (isOver ? "1" : "0") + output;
                isOver = false;
                if (a[iter] == '1')
                {
                    isOver = true;
                }
            }
            else
            {
                output = (isOver ? "0" : "1") + output;
            }
            iter--;
            jter--;
        }

        while (iter >= 0)
        {
            if (a[iter] == '0')
            {
                output = (isOver ? "1" : "0") + output;
                isOver = false;
            }
            else
            {
                output = (isOver ? "0" : "1") + output;
            }

            iter--;
        }

        while (jter >= 0)
        {
            if (b[jter] == '0')
            {
                output = (isOver ? "1" : "0") + output;
                isOver = false;
            }
            else
            {
                output = (isOver ? "0" : "1") + output;
            }

            jter--;
        }

        if (isOver)
            output = "1" + output;

        return output;
    }
};

