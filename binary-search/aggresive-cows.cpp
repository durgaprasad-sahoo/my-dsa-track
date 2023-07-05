bool canBePlaced(vector<int>& stalls, int cows, int distance){
    int cowsCount = 1;
    int lastCow = stalls[0];
    for(int i=1; i< stalls.size(); i++){
        if(stalls[i]-lastCow>= distance){
            cowsCount++;
            lastCow = stalls[i];
        }
        if(cowsCount>= cows) return true;
        
    }return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    // 0 3 4 7 10 9 sort it ro 0 3 4 7 9 10
    sort(stalls.begin(), stalls.end());
    int n =  stalls.size();
    int low = 1;
    int high = stalls[n-1]- stalls[0];
    while(low<=high){
        int mid = low+ high >> 1;
        if(canBePlaced(stalls, k, mid)){
            low = mid+1;
        }else{
            high = mid-1;
        }
    } 
    return high;
}
