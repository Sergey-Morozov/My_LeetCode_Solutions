// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() < nums2.size())
        {
            swap(nums1, nums2);
        };
        if (nums2.size() == 0)
            return (double(nums1[int(floor(double(nums1.size() - 1) / 2))] + nums1[int(ceil(double(nums1.size() - 1) / 2))]) / 2);
        int l1 = 0;
        int l2 = 0;
        int r1 = nums1.size() - 1;
        int r2 = nums2.size() - 1;
        while (r2 - l2 > 1)
        {
            int m2 = int(floor(double(l2 + r2) / 2));
            if (nums1[int(ceil(double(l1 + r1) / 2))] > nums2[m2])
            {
                r1 -= m2 - l2;
                l2 = m2;
            }
            else
            {
                l1 += r2 - m2;
                r2 = m2;
            };
        };
        double m1 = double(l1 + r1) / 2;
        if (l2 == r2)
        {
            if ((r1 - l1) % 2 != 0)
            {
                if (nums1[int(floor(m1))] >= nums2[l2])
                {
                    return (nums1[int(floor(m1))]);
                }
                else
                {
                    if (nums1[int(ceil(m1))] <= nums2[l2])
                    {
                        return (nums1[int(ceil(m1))]);
                    }
                    else
                    {
                        return (nums2[l2]);
                    }
                }
            }
            else
            {
                if (r1 == l1)
                {
                    return (double(nums1[l1] + nums2[l2]) / 2);
                }
                if (nums1[m1 - 1] >= nums2[l2])
                {
                    return (double(nums1[m1 - 1] + nums1[m1]) / 2);
                }
                else if (nums1[m1 + 1] <= nums2[l2])
                {
                    return (double(nums1[m1] + nums1[m1 + 1]) / 2);
                }
                else
                {
                    return (double(nums1[m1] + nums2[l2]) / 2);
                }
            };
        }
        else
        {
            if ((r1 - l1) % 2 != 0)
            {
                if (nums1[int(floor(m1))] >= nums2[r2])
                {
                    if (l1 == int(floor(m1)))
                    {
                        return (double(nums1[int(floor(m1))] + nums2[r2]) / 2);
                    }
                    else
                    {
                        if (nums1[int(floor(m1)) - 1] <= nums2[r2])
                        {
                            return (double(nums1[int(floor(m1))] + nums2[r2]) / 2);
                        }
                        else
                        {
                            return (double(nums1[int(floor(m1))] + nums1[int(floor(m1)) - 1]) / 2);
                        }
                    }
                }
                else
                {
                    if (nums1[int(ceil(m1))] <= nums2[l2])
                    {
                        if (r1 == int(ceil(m1)))
                        {
                            return (double(nums1[int(ceil(m1))] + nums2[l2]) / 2);
                        }
                        else
                        {
                            if (nums1[int(ceil(m1)) + 1] >= nums2[l2])
                            {
                                return (double(nums1[int(ceil(m1))] + nums2[l2]) / 2);
                            }
                            else
                            {
                                return (double(nums1[int(ceil(m1))] + nums1[int(ceil(m1)) + 1]) / 2);
                            }
                        }
                    }
                    else
                    {
                        if (nums1[int(ceil(m1))] >= nums2[r2])
                        {
                            if (nums1[int(floor(m1))] <= nums2[l2])
                            {
                                return (double(nums2[r2] + nums2[l2]) / 2);
                            }
                            else
                            {
                                return (double(nums1[int(floor(m1))] + nums2[r2]) / 2);
                            }
                        }
                        else
                        {
                            if (nums1[int(floor(m1))] <= nums2[l2])
                            {
                                return (double(nums1[int(ceil(m1))] + nums2[l2]) / 2);
                            }
                            else
                            {
                                return (double(nums1[int(floor(m1))] + nums1[int(ceil(m1))]) / 2);
                            }
                        }
                    }
                }
            }
            else
            {
                if (nums1[m1 - 1] >= nums2[r2])
                {
                    return (nums1[m1 - 1]);
                }
                else if (nums1[m1 + 1] <= nums2[l2])
                {
                    return (nums1[m1 + 1]);
                }
                else if (nums1[m1] >= nums2[r2])
                {
                    return (nums2[r2]);
                }
                else if (nums1[m1] <= nums2[l2])
                {
                    return (nums2[l2]);
                }
                else
                {
                    return (nums1[m1]);
                }
            };
        }
    };
};