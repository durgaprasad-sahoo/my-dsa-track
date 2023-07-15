class Solution {
public:
    string longestPalindrome(string s) {
       int maxLen = 0;
       int startPoint = 0;
       //a b r b a d a a d a b
        for(int i=0; i<s.size(); i++){
            int oddsLen = check(s, i, i);
            int evensLen = check(s, i,i+1);
            int curLen = max(oddsLen, evensLen);
            if(curLen>maxLen){
                maxLen= curLen;
                startPoint = i-(maxLen-1)/2; //checks the starting point of the palindrome
            }
        }return s.substr(startPoint, maxLen);
    }
private:
    int check(const string& s, int left, int right){
        while(left>=0 && right <s.size() && s[left]==s[right]){left--; right++;};
        return right-left-1;
    }
};
