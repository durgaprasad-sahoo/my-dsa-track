//better approach
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int prefix[n], suffix[n];
        prefix[0]= height[0];
        for(int i=1; i<n; i++){
            prefix[i] = max(prefix[i-1], height[i]);
        }
        //prefix: 0 1 1 2 2 2 2 3 3 3 3 3(from lefft to right)
        suffix[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            suffix[i]=max(suffix[i+1],height[i]);
        }
        //suffix: 3 3 3 3 3 3 3 3 2 2 2 1(from right to lefft)
        int waterTrapped = 0;
        for(int i=0; i<n; i++){
            waterTrapped+= (min(prefix[i], suffix[i])-height[i]);
        }return waterTrapped;
    }
};

//optimal solution
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int waterTrapped = 0;
        int maxLeft = 0;
        int maxRight = 0;
        while(left <= right){
            if(height[left]<height[right]){
                if(height[left]>=maxLeft) maxLeft = height[left];
                else waterTrapped+= maxLeft-height[left];
                left++;
            }else{
                if(height[right]>=maxRight) maxRight = height[right];
                else waterTrapped += maxRight - height[right];
                right--;
            }
        }return waterTrapped;
    }
};
