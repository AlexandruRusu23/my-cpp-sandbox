#include <vector>

class Solution
{
public:
    void reverseString(std::vector<char> &s)
    {
        char aux;
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
        {
            aux = s[i];
            s[i] = s[j];
            s[j] = aux;
        }
    }
};

