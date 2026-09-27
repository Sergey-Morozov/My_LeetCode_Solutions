class Solution {
private:
    unsigned char oldFriends[100];
    unsigned char seenFriends[100];
    unsigned char videos[9900][9]; // first char for ferquency
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,
                                          vector<vector<int>>& friends, int id,
                                          int level) {
        const int n = friends.size();
        int p1 = 0, p2 = 1, p3 = 1;
        oldFriends[0] = id;
        for (int i = 0; i < n; i++)
            seenFriends[i] = 0;
        seenFriends[id] = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 9; j++)
                videos[i][j] = 0;

        for (int i = 0; i < level; i++) {
            for (int j = p1; j < p2; j++) {
                for (int k = 0; k < friends[oldFriends[j]].size(); k++) {
                    int fofjk = friends[oldFriends[j]][k];
                    if (!seenFriends[fofjk]) {
                        oldFriends[p3] = fofjk;
                        p3++;
                        seenFriends[fofjk] = 1;
                    }
                }
            }
            p1 = p2;
            p2 = p3;
        }

        p3 = 0;
        for (int j = p1; j < p2; j++) {
            for (int l = 0; l < watchedVideos[oldFriends[j]].size(); l++) {
                int m = 0, n = 0;
                int wvofjll = watchedVideos[oldFriends[j]][l].length();
                while (m < p3) {
                    while (n < wvofjll &&
                           videos[m][n + 1] ==
                               watchedVideos[oldFriends[j]][l][n])
                        n++;
                    if (n == wvofjll && (n == 8 || !videos[m][n + 1])) {
                        videos[m][0]++;
                        break;
                    }
                    m++;
                    n = 0;
                }
                if (m < p3)
                    continue;
                videos[p3][0] = 1;
                for (int m = 0; m < wvofjll; m++)
                    videos[p3][m + 1] = watchedVideos[oldFriends[j]][l][m];
                p3++;
            }
        }

        vector<string> res;
        for (int i = 0; i < p3; i++) {
            string tmp;
            for (int j = 0; j < 9; j++)
                tmp += videos[i][j];
            res.push_back(tmp);
        }
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++) {
            int j = 2;
            while (j < 9 && res[i][j] != 0)
                j++;
            res[i] = res[i].substr(1, j - 1);
        }
        return res;
    }
};