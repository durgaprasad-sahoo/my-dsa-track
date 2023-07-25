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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        queue<pair<TreeNode*, int>>q;
        q.push(make_pair(root, 0));

        while(!q.empty()){
            int size= q.size();
            int minimum = q.front().second;
            int firstIndex, lastIndex;
            for(int i=0; i<size; i++){
                TreeNode* node = q.front().first;
                long long changed_index = q.front().second - minimum; //done to stop INT overflowing
                q.pop();

                if(i==0) firstIndex = changed_index; //changed index of only first;
                //middle indexs' changed index need not to be stored. as max is between last and first
                if(i==size-1) lastIndex = changed_index; //changed index of only last;
                if(node->left) q.push(make_pair(node->left, changed_index*2+1));
                if(node->right) q.push(make_pair(node->right, changed_index*2+2));
            }ans = max(ans, lastIndex-firstIndex + 1);
        }return ans;
    }
};
