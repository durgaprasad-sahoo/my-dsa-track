class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //bruteForce
        // int n = nums.size();
        // if(n==0) return 0;

        // sort(nums.begin(), nums.end());
        // //1 2 3 4 100 200

        // int prev = nums[0];
        // int longestYet= 1;
        // int currentLongest = 1;
        
        // for(int i=1; i<n; i++){
        //     if(nums[i]==prev+1) currentLongest++;
        //     else if(nums[i]!=prev) currentLongest=1;
        //     prev = nums[i];
        //     longestYet = max(longestYet, currentLongest);
        // }
        // return longestYet;

        //using unordered_set
        int n = nums.size();
        if(n==0) return 0;

        unordered_set<int> st;

        int longest = 1;

        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }
        for(auto itr : st){
            //st.find(itr-1)==st.end() means if itr-1th element is not in set, it'll point
            // to end. that means itr will  be the first element of the kind.
            if(st.find(itr-1)==st.end()){
                int x = itr;
                int count = 1;
                
                //while(st.find(x+1)!=st.end()) means until and unless itr+1 is 
                //present and is not at end. that means the elements are in set
                while(st.find(x+1)!=st.end()){
                    count++;
                    x++;
                }
                longest = max(longest, count);
            }
        }return longest;
    }
}
