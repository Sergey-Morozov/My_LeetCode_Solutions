/**
 * LeetCode #1: Two Sum
 * Difficulty: Easy
 * Language: Cpp
 * Date: 2026-09-21T11:48:06.355Z
 */

#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

static constexpr size_t max_align = alignof(max_align_t);
alignas(max_align) static unsigned char BUFFER[64 * 1024 * 1024];
static size_t pos = 0;

void *operator new(const size_t size) {
    const size_t padding = (max_align - (pos % max_align)) % max_align;
    pos += padding + size;
    return static_cast<void *>(&BUFFER[pos - size]);
}

void *operator new[](const size_t size) { return operator new(size); }
void operator delete(void *) noexcept {}
void operator delete[](void *) noexcept {}
void operator delete(void *, size_t) noexcept {}
void operator delete[](void *, size_t) noexcept {}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> nums1 = nums;
        sort(nums1.begin(), nums1.end());
        int beg = 0;
        int fin = nums.size() - 1;
        while (true) {
            if (nums1[beg] + nums1[fin] == target) {
                int i1 = 0;
                while (nums[i1] != nums1[beg])
                    i1++;
                int i2 = nums.size() - 1;
                while (nums[i2] != nums1[fin])
                    i2--;
                vector<int> res{i1, i2};
                return res;
            }
            int mid = (beg + fin) / 2;
            if (nums1[beg] + nums1[fin] < target)
                while (mid > beg)
                    if (nums1[mid] + nums1[fin] < target)
                        beg = mid + 1;
                    else {
                        mid = (beg + mid) / 2;
                        if (mid == beg)
                            beg++;
                    }
            else
                while (mid < fin)
                    if (nums1[mid] + nums1[beg] > target)
                        fin = mid - 1;
                    else {
                        mid = (fin + mid) / 2;
                        if (mid == fin - 1)
                            fin--;
                    }
        }
    }
};