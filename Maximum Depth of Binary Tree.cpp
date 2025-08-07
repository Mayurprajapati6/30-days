class Solution {
public:

    int dfs(TreeNode* root,int count){
        if(root == NULL){
            return 0;
        }

        count++;
        int left = dfs(root->left,count);
        int right = dfs(root->right,count);

        return max(left,right) + 1;
        
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        return dfs(root,0);
        
    }
};
