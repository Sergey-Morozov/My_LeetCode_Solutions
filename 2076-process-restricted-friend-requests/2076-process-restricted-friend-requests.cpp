// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

class Solution {
private:
    int root(int person, vector<int>& friends) {
        while (friends[person] != person) {
            friends[person] = friends[friends[person]];
            person = friends[person];
        }
        return person;
    }
    bool join(int person1, int person2, vector<int>& friends,
              vector<vector<int>>& members, vector<unordered_set<int>>& blocks) {
        person1 = root(person1, friends);
        person2 = root(person2, friends);
        if (person1 != person2) {
            if (members[person1].size() < members[person2].size())
                swap(person1, person2);
            for (int i = 0; i < members[person2].size(); i++)
                if (blocks[person1].contains(members[person2][i]))
                    return false;
            friends[person2] = person1;
            for (int i = 0; i < members[person2].size(); i++)
                members[person1].push_back(members[person2][i]);
            blocks[person1].insert(blocks[person2].begin(), blocks[person2].end());
        }
        return true;
    }
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions,
                                vector<vector<int>>& requests) {
        vector<bool> res;
        vector<int> friends(n);
        vector<vector<int>> members(n);
        for (int i = 0; i < n; i++) {
            members[i].push_back(i);
            friends[i] = i;
        }
        vector<unordered_set<int>> blocks(n);
        for (int i = 0; i < restrictions.size(); i++) {
            blocks[restrictions[i][0]].insert(restrictions[i][1]);
            blocks[restrictions[i][1]].insert(restrictions[i][0]);
        }
        for (int i = 0; i < requests.size(); i++)
            res.push_back(join(requests[i][0], requests[i][1], friends, members, blocks));
        return res;
    }
};