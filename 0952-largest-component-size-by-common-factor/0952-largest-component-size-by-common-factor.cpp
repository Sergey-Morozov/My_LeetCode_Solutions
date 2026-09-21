// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
private:
    const vector<int> primes{2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,
                       37,  41,  43,  47,  53,  59,  61,  67,  71,  73,  79,
                       83,  89,  97,  101, 103, 107, 109, 113, 127, 131, 137,
                       139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193,
                       197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257,
                       263, 269, 271, 277, 281, 283, 293, 307, 311, 313};


    // Disjoint set union infrastructure, see
    // https://cp-algorithms.com/data_structures/disjoint_set_union.html

    void union_sets(int a, int b, vector<int>& parent, vector<int>& size) {
        a = find_set(a, parent);
        b = find_set(b, parent);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }

    int find_set(int v, vector<int>& parent) {
        while (v != parent[v]) {
            parent[v] = parent[parent[v]];
            v = parent[v];
        }
        return v;
    }

public:
    int largestComponentSize(vector<int>& nums) {

        int res = 0;
        const int n = nums.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        vector<int> size(n, 1);
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            int k = nums[i];
            for (int d : primes) {
                if (d * d > k)
                    break;
                if (k % d == 0) {
                    if (m.contains(d))
                        union_sets(i, m[d], parent, size);
                    else
                        m[d] = i;
                    while (k % d == 0)
                        k /= d;
                }
            }
            if (k > 1)
                if (m.contains(k))
                    union_sets(i, m[k], parent, size);
                else
                    m[k] = i;
        }
        for (int i : size)
            res = max(res, i);
        return res;
    }
};