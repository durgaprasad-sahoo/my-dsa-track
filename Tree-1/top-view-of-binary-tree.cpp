/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    vector<int> topView(Node *root){
        vector<int>ans;
        if(root==NULL) return ans;
        map<int, int>mpp;
        queue<pair<Node*, int>>q;
        
        q.push(make_pair(root, 0));
        while(!q.empty()){
            auto it= q.front();
            Node* node= it.first;
            int verticalLine = it.second;
            q.pop();
            
            if(mpp.find(verticalLine)==mpp.end()) mpp[verticalLine]= node->data;
            
            if(node->left) q.push(make_pair(node->left, verticalLine-1));
            if(node->right) q.push(make_pair(node->right, verticalLine+1));
        }
        for(it: mpp){
            ans.emplace_back(it.second);
        }return ans;
    }

};
