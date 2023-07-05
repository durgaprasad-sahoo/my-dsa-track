bool allocationIsPossible(int barrier, vector<int>&pagesArr, int students){
    int allocatedStudents = 1; //initially assigning 1 student
    int pages = 0;
    
    for(int i=0; i<pagesArr.size(); i++){
        //example the mid of 12 and 203 is 107
        //student1: 12+ 34
        if(pagesArr[i]> barrier) return false; //means if the pagesArr[i] is 12 and the barrier
        //  is 10 then the first guy cannot be allocated any pages
        if(pages + pagesArr[i] > barrier){ // if pages+ pagesArr[i] > barrier // ex: 12+34+67>107
            allocatedStudents++; //allocatedStudents :2
            pages= pagesArr[i]; //pages = 67
            
        }else{ 
            pages+= pagesArr[i]; // 12 + 34 < 107
        }
    }
    if(allocatedStudents>students) return false;
    return true;
}
int Solution::books(vector<int> &A, int B) {
    //12 34 67 90
    //low = 12, high = 203 i.e 12+34+67+90. This is the search space
    if(B> A.size()) return -1;
    int low = A[0];
    int high = 0;
    for(int i=0; i<A.size(); i++){
        high+= A[i];
    }
    while(low<=high){
        int mid = (low+high)/2;
        if(allocationIsPossible(mid, A, B)){
            high = mid-1;
        }else low = mid+1;
    }
    return low;
}
