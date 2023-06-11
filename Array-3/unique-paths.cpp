class Solution {
public:
  
    //bruteForce: recursion
    //better approach: Dp(recursion+memorization)
    //optimal solution
    int uniquePaths(int m, int n) {
      //using Ncr
        int N = m+n-2;
        int r= n-1;
        double ans =1;
        for(int i=1; i<=r; i++){
            ans= ans*(N-r+i)/i;
        }return (int)ans;
    }
};
