class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int low = 0, high = n-1, ans = INT_MAX;
	    int ind = -1;
	    while(low<=high){
	        int mid = (low+high)/2;
	        if(arr[low]<=arr[high]){
	            if(arr[low]< ans){
	                ans = arr[low];
	                ind = low;
	            }break;
	        }
	        if(arr[low]<=arr[mid]){
	            if(arr[low]<ans){
	                ans = arr[low];
	                ind = low;
	            }
	            low = mid+1;
	        }else{
	            if(arr[mid]<ans){
	                ans = arr[mid];
	                ind = mid;
	            }
	            high = mid-1;
	        }
	    }
	    return ind;
	}

};
