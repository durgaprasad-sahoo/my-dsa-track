class Solution{
private:
    long long int cnt=0;
    void merge(long long arr[], long long s, long long m, long long e){
        long long l = s;
        long long r = m+1;
        vector<long long>temp;
        while(l<=m && r<=e){
            if(arr[l]<=arr[r]){
                temp.emplace_back(arr[l]);
                l++;
            }else{
                temp.emplace_back(arr[r]);
                cnt+=(m-l+1);  //only this thing is added in mergesort
                r++;
            }
        }
        while(l<=m) temp.emplace_back(arr[l++]);
        while(r<=e) temp.emplace_back(arr[r++]);
        for(int i=s; i<=e; i++){
            arr[i]= temp[i-s];
        }
    }
    void mergeSort(long long arr[], long long s, long long e){
        if(s>=e) return;
        long long m = (s+e)/2;
        mergeSort(arr, s, m);
        mergeSort(arr, m+1, e);
        merge(arr, s, m, e);
    }
public:
    long long int inversionCount(long long arr[], long long N){
        mergeSort(arr, 0, N-1);
        return cnt;
    }

};
