#include <string>
#include <vector>

class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string> &strs)
    {
        std::string output = strs[0];

        for (auto str : strs)
        {
            while (str.find(output) != 0)
            {
                output = output.substr(0, output.size() - 1);
                if (output == "")
                    return "";
            }
        }

        return output;
    }
};

