class Solution {
public:
    string intToRoman(int num) {
        string roman;
        vector<string>notations={"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int>values={1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        //2856
        for(int i=0; num>0; i++){
            while(num>=values[i]){
                // 2856>1000
                roman+= notations[i];
                //roman= M
                num-=values[i];
                //num = 1856
            }
        }return roman;
    }
};
