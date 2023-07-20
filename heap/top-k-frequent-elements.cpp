class Node{
public:
    int no;
    int freq;
    Node(int a, int b): no(a), freq(b){};
};
class Compare{ //maxHeap comparator class for freq
public:
    bool operator()(Node a, Node b){
        return a.freq< b.freq;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        priority_queue<Node, vector<Node>, Compare>maxHeap; //maxheap of freq
        for(auto it: nums){
            mp[it]++;
        }
        for(auto it: mp){
            Node d(it.first, it.second);
            maxHeap.push(d);
        }
        vector<int>ans;
        while(k--){
            Node temp = maxHeap.top();
            maxHeap.pop();
            ans.emplace_back(temp.no);
        }return ans;
    }
};
