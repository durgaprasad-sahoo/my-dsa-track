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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>>mp;
        //buildings(vertical)i.e col, <levels(floor). ie. row, rooms(nodes)>;
        queue<pair<TreeNode*, pair<int, int>>>q;
        //4: node, <vertical i.e col(building), level i.e row(floor)>

        q.push(make_pair(root, make_pair(0,0)));

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node= it.first;
            int building = it.second.first;
            int floor = it.second.second;

            mp[building][floor].insert(node->val);

            if(node->left) q.push(make_pair(node->left, make_pair(building-1, floor+1)));
            if(node->right) q.push(make_pair(node->right, make_pair(building+1, floor+1)));
        }

        vector<vector<int>>ans;
        for(auto it: mp){
            vector<int>col;
            for(auto z : it.second){
                col.insert(col.end(), z.second.begin(), z.second.end());
            }ans.push_back(col);
        }return ans;

    }
};
