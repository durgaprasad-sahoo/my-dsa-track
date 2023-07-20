class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>,greater<int>>minHeap;

    MedianFinder() {}
    void addNum(int num) {
        int lSize= maxHeap.size();
        int rSize= minHeap.size();
        if(lSize==0) maxHeap.push(num);
        else if(lSize==rSize){ //equal means num is to be pushed in maxHeap
            if(num<minHeap.top())  maxHeap.push(num);
            else{
                int temp= minHeap.top();
                minHeap.pop();
                minHeap.push(num);
                maxHeap.push(temp);
            }
        }else{ //lSize>rSize
            if(rSize==0){    //maxheap: 5 minHeap: empty 
                if(num>maxHeap.top()) minHeap.push(num);   //maxheap: 5 minHeap: empty .push(7)
                else{   //maxheap: 5 minHeap: empty .push(2)
                    int temp = maxHeap.top();
                    maxHeap.pop();
                    maxHeap.push(num);
                    minHeap.push(temp);
                }
            }
            else if(num>=minHeap.top())  minHeap.push(num); //maxHeap: 2 3 6 minHeap: 7 8. push(10)
            else{ //maxHeap: 2 3 6 minHeap: 7 8. push(1)
                if(num<maxHeap.top()){
                    int temp = maxHeap.top();
                    maxHeap.pop();
                    maxHeap.push(num);
                    minHeap.push(temp);
                }else{
                    minHeap.push(num);
                }
            }
            
        }
    }
    
    double findMedian() {
        int lSize= maxHeap.size();
        int rSize = minHeap.size();
        if(lSize>rSize) return double(maxHeap.top());
        else return (double(maxHeap.top())+ double(minHeap.top()))/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<int>>minHeap;
    MedianFinder() {  }
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if(minHeap.size()>maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        } 
    }
    
    double findMedian() {
        if(maxHeap.size()>minHeap.size()) return double(maxHeap.top());
        else return (double(maxHeap.top())+ double(minHeap.top()))/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
