class Solution {
public:
    string reverseWords(string s) {
        //the sky is blue
        //"  hello world  "
        //a good   example
        //sky
        int left= 0;
        int right = s.length()-1;
        string word;
        string reversedString;
        while(left<=right){
            if(s[left] !=' '){
                word+=s[left];
            }else if(s[left]==' '){
                if(!word.empty()){
                    if(reversedString.size()==0) reversedString+= word;
                    //if reversedString.size()!=0
                    else reversedString = word + " " + reversedString;
                    //setting word to ""
                    word = "";
                }
                
            }left++;
        }
        //ex: if string has no space at last, in above while loop, the code will never
        //go to the else part, so word will still be having a word in it.
        //ex: word = blue   reversedString= is sky the. we need to add the word in it
        if(word!=""){
            
            if(reversedString.size()!=0) reversedString = word + " " + reversedString;
            //there might be a case of single word like Rishi. it'll never go to the 
            //else part in the while loop, so the word will not be empty, but reversedString will 
            //be empty, so have to put the single word in the reversedString
            else reversedString+= word;
        } return reversedString;
    }
};
