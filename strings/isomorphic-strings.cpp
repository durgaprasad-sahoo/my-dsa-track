class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sToT, tToS;
        for(int i=0; i<s.length(); i++){
            if(sToT[s[i]] and sToT[s[i]]!= t[i]) return false;
            if(tToS[t[i]] and tToS[t[i]]!=s[i])  return false;
            sToT[s[i]]= t[i];
            tToS[t[i]]= s[i]; 
        }return true;
    }
};
