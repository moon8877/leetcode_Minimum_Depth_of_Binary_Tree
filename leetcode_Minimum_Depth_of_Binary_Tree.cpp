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
    int minDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        int count=1;
        vector<int> depth;
        dfs(root,depth,count);
        return *min_element(depth.begin(),depth.end());
    }
private:
    void dfs(TreeNode* root,vector<int>& depth,int count){
        if(root->left==nullptr && root->right==nullptr){
            depth.push_back(count);
            return;
        }
        if(root->left){
            dfs(root->left,depth,count+1);
        }
        if(root->right){
            dfs(root->right,depth,count+1);
        }
    }
};
