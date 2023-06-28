class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    int lb = lower_bound(arr, arr+n, x)-arr;
	    int last_occurence = upper_bound(arr, arr+n, x)-arr-1;
	    if(lb==n || arr[lb]!=x) return 0;
	    else return last_occurence-lb+1;
	}
};
