#include <iostream>
#include <vector>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    std::vector<std::string> binaryTreePaths(TreeNode* root) {
        std::string s;
        std::vector<std::string> result;
        PathsTree(root, s, result);
        return result;
    }
    void PathsTree(TreeNode* node, std::string& path, std::vector<std::string>& result) {
        if (node == NULL) {
            path.push_back('>');
            return;
        }
        path += std::to_string(node->val) + "->";
        if (node->left == NULL && node->right == NULL) {
            path.pop_back(); path.pop_back();
            result.push_back(path);
            return;
        }
        PathsTree(node->left, path, result);
        do path.pop_back();
        while (path[path.size() - 1] != '>');
        PathsTree(node->right, path, result);
        do path.pop_back();
        while (path[path.size() - 1] != '>');
    }
};
