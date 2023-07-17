vector<int>generateLPSArr(const string& A){
    //baabcd
    vector<int>LPSArr(A.size(), 0);
    int i=0;
    int j=1;
    while(j<A.size()){
        if(A[i]==A[j]){
            i++;
            LPSArr[j]=i;
            // i++;
            j++;
        }else{
            if(i==0){
                LPSArr[j]=0;
                j++;
            }else if(i!=0){
                i = LPSArr[i-1];
            }
        }
    }return LPSArr;
}
int Solution::solve(string A) {
    //baabcd
    int n = A.size();
    string rev = A;
    reverse(rev.begin(), rev.end());
    A = A+ '#'+ rev;
    vector<int>LPSArr= generateLPSArr(A);
    if(LPSArr.back()==0)return {0};
    else return n-LPSArr.back();
}
