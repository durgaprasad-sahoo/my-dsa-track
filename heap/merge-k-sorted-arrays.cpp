#include <bits/stdc++.h> 
class Node {
public:
    int value;
    int arrayIndex;
    int elementIndex;

    Node(int val, int arrInd, int elemInd) : value(val), arrayIndex(arrInd), elementIndex(elemInd) {}
};

class compare {
public:
    bool operator()(Node a, Node b) {
        return a.value > b.value;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<Node, vector<Node>, compare> pq;
    vector<int> ans;

    // Push the first element from each array into the min-heap.
    for (int i = 0; i < k; i++) {
        if (!kArrays[i].empty()) {
            Node d(kArrays[i][0], i, 0);
            pq.push(d);
        }
    }

    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();
        ans.push_back(curr.value);

        int curRow = curr.arrayIndex;
        int curCol = curr.elementIndex;

        // Move to the next element in the same array if available.
        if (curCol + 1 < kArrays[curRow].size()) {
            Node d(kArrays[curRow][curCol + 1], curRow, curCol + 1);
            pq.push(d);
        }
    }

    return ans;
}
