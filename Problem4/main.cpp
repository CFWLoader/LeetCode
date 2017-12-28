#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int recursiveDepth = 0;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int total = nums1.size() + nums2.size();
        if (total & 0x1)
            return findKth(nums1.data(), nums1.size(), nums2.data(), nums2.size(), total / 2 + 1);
        else
            return (findKth(nums1.data(), nums1.size(), nums2.data(), nums2.size(), total / 2)
                    + findKth(nums1.data(), nums1.size(), nums2.data(), nums2.size(), total / 2 + 1)) / 2;
    }

    double findKth(int a[], int m, int b[], int n, int k)
    {
        //always assume that m is equal or smaller than n
        if (m > n)
            return findKth(b, n, a, m, k);
        if (m == 0)
            return b[k - 1];
        if (k == 1)
            return min(a[0], b[0]);
        //divide k into two parts
        int pa = min(k / 2, m), pb = k - pa;
        if (a[pa - 1] < b[pb - 1])
            return findKth(a + pa, m - pa, b, n, k - pa);
        else if (a[pa - 1] > b[pb - 1])
            return findKth(a, m, b + pb, n - pb, k - pb);
        else
            return a[pa - 1];
    }
};

int main()
{
    vector<int> nums1 = {1};
    vector<int> nums2 = {1};

    Solution solution;

    cout << solution.findMedianSortedArrays(nums1, nums2);

    return 0;
}