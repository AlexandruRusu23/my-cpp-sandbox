#include <vector>

class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        int min_share = prices[0];
        int max = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < min_share)
                min_share = prices[i];

            if (prices[i] - min_share > max)
                max = prices[i] - min_share;
        }

        return max;
    }
};

