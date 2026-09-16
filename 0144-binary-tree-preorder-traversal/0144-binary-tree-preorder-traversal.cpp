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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        stack<TreeNode*> s;
        s.push(root);
        vector<int> ans;

        while(!s.empty()) {
            TreeNode* Node = s.top();
            s.pop();

            ans.push_back(Node->val);

            if(Node->right != NULL) s.push(Node->right);

            if(Node->left != NULL) s.push(Node->left);
        }
        return ans;
    }
};