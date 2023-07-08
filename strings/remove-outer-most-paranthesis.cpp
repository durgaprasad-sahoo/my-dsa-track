class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int count=0;
        for(int i =0; i<s.size(); i++){
            if(count == 0 && s[i]=='(') count++; //if count is 0 then ( is first, so it'll be skipped
            else if(count>0 && s[i]=='('){ //if there's already an element (, then add ( to the ans and increase the count
                ans+=s[i]; 
                count++;
            }
            else if(count>1 && s[i]==')'){// the last bracket will be solved separetely to be skipped, 
            // so this will go till the count > 1
                ans+=s[i]; 
                count--;
            }
            else if(count==1 && s[i]==')') count--; // if last count is 1, and this again is ) means that it is the ending point
        }return ans;
    }
};
