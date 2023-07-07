
class Solution
{
    public:
    
    void solve(stack<int>&s, int mid, int count){
        if(mid==count){
            s.pop();
            return;
        }
        int temp = s.top();
        s.pop();
        solve(s, mid, count+1);
        s.push(temp);
    }
    
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int mid = sizeOfStack/2;
        solve(s, mid, 0);
    }
};
