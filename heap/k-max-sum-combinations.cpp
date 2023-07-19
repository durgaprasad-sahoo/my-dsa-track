vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    // A = 1 2 3 4
    // B = 1 2 5 6
    int n = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    priority_queue<pair<int, pair<int, int>>>maxHeap;
    set<pair<int, int>>s;
    maxHeap.push({A[n-1]+B[n-1], {n-1, n-1}}); // 4 + 6
    s.insert({n-1,n-1}); //3 3
    
    vector<int>ans;
    
    while(C--){
        pair<int, pair<int, int>> topEle = maxHeap.top(); // 10, 3 3
        maxHeap.pop();
        int sum = topEle.first; // 10
        int x = topEle.second.first;  //3
        int y = topEle.second.second; //3
        ans.emplace_back(sum); //10 9 9 8
        if(s.find({x, y-1})==s.end()){
            maxHeap.push({A[x]+B[y-1], {x, y-1}});
            s.insert({x, y-1});
        }
        
        if(s.find({x-1, y})==s.end()){
            maxHeap.push({A[x-1]+B[y],{x-1, y}});
            s.insert({x-1, y});
        }
    }return ans;
}
