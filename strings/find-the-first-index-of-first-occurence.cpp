class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0;
        int j=0;
        int n = haystack.size();
        int m = needle.size();
        if(haystack==needle) return 0;

        while(i<n){
            int index = i;
            string tempToCheck;
            if(haystack[i]==needle[j]){
                while(i <n && j<m && haystack[i]==needle[j]){
                    tempToCheck+=haystack[i];
                    i++;
                    j++;
                }
                if(tempToCheck==needle) return index;
                else{
                    i = index+1;
                    j = 0;
                }
            }else{
                i++;
            }
        }return -1;
    }
};
