class Solution {
public:
  int compareVersion(string version1, string version2) {
    // version1 = "1.01.3.004.5", version2 = "1.001.03.4.06"
    int num1= 0;
    int num2=0;
    int i=0;
    int j=0;
    while(i<version1.size() || j<version2.size()){
      num1=0;
      num2=0;
      while(i<version1.size() && version1[i] != '.'){
        num1 = num1 * 10 + (version1[i]-'0');
        i++;
      }while(j<version2.size() && version2[j]!='.'){
        num2 = num2* 10 + (version2[j]-'0');
        j++;
      }
      if(num1<num2) return -1;
      if(num1>num2) return 1;
      i++;
      j++;
    }return 0;
    
  }
};
