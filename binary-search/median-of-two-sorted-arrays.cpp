class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 1 2 3 4 9 11
        //7 12 14 15
        if(nums2.size()< nums1.size()) return findMedianSortedArrays(nums2, nums1);
        //7 12 14 15
        // 1 2 3 4 9 11
        int n1 = nums1.size();
        int n2= nums2.size();
        int low = 0;
        int high = n1;
        //binary search will be done only on 1st array
        while(low<=high){
            int cut1 = (low+high)/2;
            int cut2 = (n1+n2+1)/2-cut1; //works in both odd and even case
            
            int left1= (cut1 !=0) ? nums1[cut1-1] : INT_MIN;
            int left2= (cut2 !=0) ? nums2[cut2-1] : INT_MIN;

            int right1 = (cut1 != n1) ? nums1[cut1] : INT_MAX;
            int right2 = (cut2 != n2) ? nums2[cut2] : INT_MAX;

            //validate
            if(left1<= right2 && left2 <= right1){
                //even
                if((n1+n2)%2==0){
                    return (max(left1, left2)+ min(right1, right2))/2.0;
                }else{
                    //odd
                    return max(left1, left2);
                }
            }else if(left1> right2){
                high = cut1-1; //shift left
            }else{
                low = cut1+1;  //shift right
            }
        }
        return 0.0;
        
    }
};
