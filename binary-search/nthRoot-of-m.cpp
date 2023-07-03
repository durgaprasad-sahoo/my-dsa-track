int NthRoot(int n, int m) {
  int low = 1;
  int high = m;
  while(low<=high){
    int mid = (low+high)/2;
    int power = pow(mid, n);
    if(pow(mid, n)==m) return mid;
    if(pow(mid, n)>m) high = mid-1;
    else low = mid+1;
  }return -1;
}
