// Author: Sergey Morozov
// https://leetcode.com/u/Sergey-Morozov/
// https://github.com/Sergey-Morozov
// https://www.linkedin.com/in/sergey-morozov-6ba2705/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {

    TreeNode* SubTree(vector<int>& inorder, int a, int b,
                      vector<int>& postorder, int c, int d,
                      unordered_map<int, int>& m) {
        if (a == b)
            return nullptr;
        int rootPos = m[postorder[d - 1]];
        return new TreeNode(
            inorder[rootPos],
            SubTree(inorder, a, rootPos, postorder, c, c + rootPos - a, m),
            SubTree(inorder, rootPos + 1, b, postorder, d + rootPos - b, d - 1,
                    m));
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> m;
        for (int i = 0; i < inorder.size(); i++)
            m[inorder[i]] = i;
        return SubTree(inorder, 0, inorder.size(), postorder, 0,
                       postorder.size(), m);
    }
};