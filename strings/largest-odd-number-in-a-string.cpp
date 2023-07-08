class Solution {
public:
    string largestOddNumber(string num) {
        // for(int i=num.size()-1; i>=0; i--){
        //     if(num[i]%2) return num;
        //     else num.erase(i, 1); //starting index from which the character will be remove, 1 charcter will be removed
        // }return "";

        int lastOddIndex = -1;
        for(int i=num.size()-1; i>=0; i--){
            if(num[i]%2){
                lastOddIndex = i;
                break;
            }
        }return (lastOddIndex==-1) ? "" : num.substr(0, lastOddIndex+1);
    }
};
