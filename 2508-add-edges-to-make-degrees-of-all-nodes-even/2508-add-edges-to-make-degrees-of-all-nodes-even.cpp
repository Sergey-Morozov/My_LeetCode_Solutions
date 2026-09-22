class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<bool> even(n + 1, true);
        for (int i = 0; i < edges.size(); i++) {
            even[edges[i][0]] = !even[edges[i][0]];
            even[edges[i][1]] = !even[edges[i][1]];
        }
        vector<int> odd;
        for (int i = 1; i <= n; i++)
            if (!even[i])
                odd.push_back(i);
        if (odd.size() == 0)
            return true;
        if (odd.size() == 2) {
            fill(even.begin(), even.end(), false);
            for (int i = 0; i < edges.size(); i++) {
                if (edges[i][0] == odd[0] || edges[i][0] == odd[1])
                    even[edges[i][1]] = true;
                if (edges[i][1] == odd[0] || edges[i][1] == odd[1])
                    even[edges[i][0]] = true;
            }
            for (int i = 1; i <= n; i++)
                if (!even[i])
                    return true;
            return false;
        }
        if (odd.size() == 4) {
            vector<int> count(4, 0);
            for (int i = 0; i < edges.size(); i++) {
                for (int j = 0; j < 3; j++)
                    for (int k = j + 1; k < 4; k++)
                        if (edges[i][0] == odd[j] && edges[i][1] == odd[k] ||
                            edges[i][1] == odd[j] && edges[i][0] == odd[k]) {
                            count[j]++;
                            count[k]++;
                        }
            }
            sort(count.begin(), count.end());
            if (count[0] == 0 && count[1] == 2 || count[3] >= 3)
                return false;
            return true;
        }
        return false;
    }
};