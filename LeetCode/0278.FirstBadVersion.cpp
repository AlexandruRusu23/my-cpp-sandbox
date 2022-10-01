// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int left = 1;
        int right = n;
        int mid;

        while (true)
        {
            mid = static_cast<int>((double)left / 2 + (double)right / 2);
            if (isBadVersion(mid))
            {
                right = mid - 1;
            }
            else
            {
                if (isBadVersion(mid + 1))
                    return mid + 1;
                left = mid + 1;
            }
        }

        return 0;
    }
};

