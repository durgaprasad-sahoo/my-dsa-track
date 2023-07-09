class Solution {
public:
    bool rotateString(string s, string goal) {
        queue<char>q1;
        queue<char>q2;
        for(int i=0; i<s.length(); i++){
            q1.push(s[i]);
            q2.push(goal[i]);
        }
        int k = q2.size()-1;
        while(k>=0){
            char ch = q2.front();
            q2.pop();
            q2.push(ch);
            if(q1==q2) return true;
            k--;
        }return false;

    }
};
