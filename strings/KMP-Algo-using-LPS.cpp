//Find the Index of the First Occurrence in a String
class Solution {
private: //lps array
    vector<int>generateLPSArr(const string& needle){
        //i j
        //  i   j
        //
        //a b a b a b a b c a
        //0 1 2 3 4 5 6 7 8 9

        int i=0;
        int j = 1;
        vector<int>lpsArr(needle.size(), 0);
        while(j<needle.size()){
            if(needle[i]==needle[j]){
                lpsArr[j]= i+1;
                i++;
                j++;
            }
            else{ // needle[i]!=needle[j]
                if(i==0){ //needle[i]!=needle[j] and i is still in first index
                    lpsArr[j]= 0;
                    j++;
                }else{ //needle[i]!=needle[j] and i is not the first index.
                    i = lpsArr[i-1];
                    //0 1 2 3 4 5 6 7 8 9  index
                    //0 0 1 2 3 4 5 6 0 1  lpsArr
                    //a b a b a b a b c a
                    //            i   j       a!=c. do not move i directly to the first index, rather: i = i's new index i.e i-1's value. ex: lpsArr[6-1]=>4 
                    //          i     j    //check if lpsArr[i]==lpsArr[j]
                }
            }
        }return lpsArr;
    }
public:

    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        vector<int>LPSArr= generateLPSArr(needle);// generateLps will generate the LPS array and it'll be stored in vector LPSArr
        //z a b c a b a b a b a b c f a b a b a b a b c a z z
         
        int i = 0; //traverse haystack
        int j = 0; //traverse LPSArr
        while(i<haystack.size()){
            if(haystack[i]==needle[j]){
                i++;
                j++;
                if(j==needle.size()) return i-j; //if j reaches needles' end means needle found
                //ex: //sadbutsad   i's index: 7
                      //but         j's index: 3   index where needle is present in haystack is 7-3
            }else{
                if(j!=0) j=LPSArr[j-1];  //similar to that done in lpsArr
                else i++;
            }
        }return -1;

    }
};
