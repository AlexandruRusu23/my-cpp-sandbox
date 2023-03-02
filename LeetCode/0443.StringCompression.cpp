#include <string>
#include <vector>

class Solution
{
public:
    int compress(std::vector<char> &chars)
    {
        int first = 0;
        int second = 0;
        int tempSz = 0;
        std::string tempSzStr;

        while (second < chars.size())
        {
            if (chars[first] == chars[second])
            {
                second++;
                tempSz++;
            }
            else
            {
                if (tempSz > 1)
                {
                    tempSzStr = std::to_string(tempSz);
                    for (size_t i = 0; i < tempSzStr.size(); i++)
                    {
                        chars[first + i + 1] = tempSzStr[i];
                    }
                    first = first + tempSzStr.size() + 1;
                }
                else
                {
                    first++;
                }

                if (first < chars.size())
                {
                    chars[first] = chars[second];
                }
                tempSz = 0;
            }
        }

        if (first < chars.size())
        {
            if (tempSz > 1)
            {
                tempSzStr = std::to_string(tempSz);
                for (size_t i = 0; i < tempSzStr.size(); i++)
                {
                    chars[first + i + 1] = tempSzStr[i];
                }
                first = first + tempSzStr.size() + 1;
            }
            else
            {
                first++;
            }
        }

        return first;
    }
};

