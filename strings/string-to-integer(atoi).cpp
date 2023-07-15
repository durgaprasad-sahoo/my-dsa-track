class Solution {
public:
    int myAtoi(string s) {
        int ans=0;
        int sign = 1;
        int i=0;
        while(s[i]==' ') i++;
        if(s[i]=='+'|| s[i]=='-'){
            sign = (s[i]=='-') ? -1 : 1;
            i++;
        }
        while(isdigit(s[i])){
            int digit = s[i]-'0';
            if(ans>(INT_MAX-digit)/10){
                return (sign==-1)? INT_MIN : INT_MAX;
            }
            ans = ans*10 +digit;
            i++;
        }
        return sign * ans;
    }
};
