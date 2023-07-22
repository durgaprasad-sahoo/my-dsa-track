class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        if (root == NULL) return ans;
        while (root != NULL || !st.empty()) {
            if (root != NULL) {
                st.push(root);
                root = root->left;
            } else {
                TreeNode* temp = st.top()->right;
                root = temp;
                if (root == NULL) {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while (!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
            }
        }
        return ans;
    }
};
