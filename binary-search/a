    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(m<n) return kthElement(arr2, arr1, m, n, k);
        //7 12 14 15
        //1 2  3  4  9  11
        
        //k=3, n=4, low = 0, high = 3.. minimum 0 elements from array1 and max 3 elements from array1
        //k=7, m = 6, low = 1, high = 4 minimum 1 element from array 1 and max 6 elements from array2
        int low = max(0, k-m);
        int high = min(k, n);
        
        while(low<=high){
            int cut1 = (low+high)/2;
            int cut2 = k-cut1;
            //1 2 3 4 7
            int left1 = cut1 != 0 ? arr1[cut1-1]: INT_MIN;
            int left2 = cut2 != 0 ? arr2[cut2-1] : INT_MIN;
            int right1 = cut1 != n ? arr1[cut1] : INT_MAX;
            int right2 = cut2 != m ? arr2[cut2] : INT_MAX;
            if(left1 <= right2 && left2 <= right1){
                return max(left1, left2);
            }
            else if(left1>right2){
                high = cut1-1;
            }else{
                 low = cut1+1;
            }
        }
        return 1;
    }
};
