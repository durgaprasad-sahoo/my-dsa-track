class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mpp (256,-1);
        int l = 0;
        int r = 0;
        int len = 0;
        //abcaabcdba
        while(r<s.size()){
            //if right element is there in string
            if(mpp[s[r]]!=-1) l = max(l, mpp[s[r]]+1); //ex: sets value of a for the second time as 4 
            len = max(len, r-l+1);
            mpp[s[r]]=r; // stores element and it's index
            r++;
        }return len;
    }
};
