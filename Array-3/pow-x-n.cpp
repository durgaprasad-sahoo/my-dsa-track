class Solution {
public:
    double myPow(double x, int n) {
        //n=10->even 2^10 = (2x2)^5 = 4^5 --> formula: (x*x)^n/2;     x=4, n= 5;
        //n=5->odd   4^5 = (1x4)(4)^4   --> formula: (ans*x)^n-1;     n=4;
        //n=4->even  4^4 = (4x4)^2 = 16^2 --> x=16 n=2;
        //n=2->even  16^2 = (16x16)^1 = 256^1   --> x= 256  n=1;
        //n=1->odd   256^1 = (4x256)(256)^0   --> x=1024 n=0; 
        double ans = 1.0;
        //copy n into nn so that if n= negative we do not change the value in between
        //the code. so that in negative case we can use it later.
        long long nn = n;
        //convert -ve to +ve.   -10 to 10 so that solving will be easy. later do 
        //reciprocal.
        if(nn<0) nn = -1* nn;
        while(nn){ //until nn == 0
            if(nn%2){ //check nn is odd
                ans*=x;
                nn-=1;
            }else{
                x*=x;
                nn=nn/2;
            }
        } 
        if(n<0) ans = (double)(1.0)/(double)(ans);
        return ans;
    }
};
