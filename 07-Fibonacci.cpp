/*斐波那契数列*/
class Solution {
public:
    int Fibonacci(int n) {
        if (n==0)    return 0;
        if (n==1)    return 1;
        int f=0,g=1,sum;
        while(--n){
            sum=f+g;
            f=g;
            g=sum;
        }
        return sum;
    }
};
