/*位运算实现加法*/
class Solution {
public:
    int Add(int num1, int num2)
    {
        while(num2!=0){
            int a=num1^num2;
            int b=(num1&num2)<<1;
            num1=a;
            num2=b;
        }
        return num1;
    }
};
