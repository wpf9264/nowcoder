/*
    数值的整数次方
    注意是如何通过二分加速求次方 
        n^1101 = n^1000 * n^0100 * n^0001
        6^13   = 6^8    * 6^4    * 6^1
*/
class Solution {
public:
    double Power(double base, int exponent) {
        if (isZero(base))    return 0.0;
        if (exponent==0)        return 1.0;
        int tmp=exponent;
        if (exponent<0){
            tmp=-tmp;
        }
        double res=1;
        double cur=base;
        while(tmp&0x1){
            res*=cur;
            cur*=cur;
            tmp>>=1;
        }
        return exponent<0 ? 1.0/res : res;
    }
    bool isZero(double num){
        if (abs(num-0)<1e-5)
            return true;
        return false;
    }
};
