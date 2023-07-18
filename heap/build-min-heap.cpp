#include <bits/stdc++.h> 
void heapify(int n, vector<int>&q, int i){
    int smallest=i;
    int left= 2*i+1;
    int right= 2*i+2;
    if(left<n && q[smallest]> q[left]){
        smallest = left;
    }
    if(right<n && q[smallest]>q[right]){
        smallest= right;
    }
    if(smallest!=i){
        swap(q[smallest], q[i]);
        heapify(n, q, smallest);
    }
}
vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size();
    for(int i=(n/2)-1; i>=0; i--){
        heapify(n, arr, i);
    }return arr;
}
