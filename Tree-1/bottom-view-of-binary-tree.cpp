class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int>ans;
        if(!root) return ans;
        queue<pair<Node*, int>>q;
        map<int, int>mpp;
        q.push({root, 0});
        while(!q.empty()){
            auto it= q.front();
            Node* node = it.first;
            int verticalLine = it.second;
            q.pop();
            // if(mpp.find(verticalLine)== mpp.end()) mpp[verticalLine]= node->data;
            // else if(mpp.find(verticalLine)!=mpp.end()){
            //     mpp[verticalLine]= node->data;
            // }
            mpp[verticalLine]= node->data;
            if(node->left) q.push({node->left, verticalLine-1});
            if(node->right) q.push({node->right, verticalLine+1});
        }
        for(auto it: mpp){
            ans.push_back(it.second);
        }return ans;
    }
};
