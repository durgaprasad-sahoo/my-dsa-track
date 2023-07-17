class Solution {
public:
    string countAndSay(int n) {
        //n=4
        if(n==1) return "1";
        string s= countAndSay(n-1);
        string ans;
        int freq=0;
        for(int i =0; i<s.size(); i++){
            freq++;
            if(i==s.size()-1 || s[i]!=s[i+1]){
                ans= ans+ to_string(freq)+ s[i];
                freq=0;
            }
        }return ans;
    }
};
