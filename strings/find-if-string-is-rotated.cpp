class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        string concatS= s+s;
        return concatS.find(goal) != string::npos;
    }
};
