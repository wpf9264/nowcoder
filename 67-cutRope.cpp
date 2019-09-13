/*剪绳子*/
class Solution {
public:
    int cutRope(int number) {
        if (number==2)    return 1;
        if (number==3)    return 2;
        int x=number%3;
        int y=number/3;
        if (x==0)    return pow(3,y);
        if (x==1)    return pow(3,y-1)*4;
        return pow(3,y)*2;
    }
};
