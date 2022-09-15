#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) 
    {
        if ( n == 0 )
            return;

        int first = m - 1;
        int second = n - 1;
        int index = m + n - 1;

        if ( m == 0 )
        {
            while ( index >= 0 )
            {
                nums1[ index ] = nums2[ second ];
                second--;
                index--;
            }
            return;
        }

        while ( index > 0 && second >= 0 && first >= 0)
        {
            if ( nums2[ second ] > nums1[ first ] )
            {
                nums1[ index ] = nums2[ second ];
                second--;
            }
            else
            {
                nums1[ index ] = nums1[ first ];
                first--;
            }
            
            index--;
        }

        if ( second >= 0 )
        {
            while ( index >= 0 )
            {
                nums1[ index ] = nums2[ second ];
                second--;
                index--;
            }
        }
    }
};

