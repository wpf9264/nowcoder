/*跳台阶*/
class Solution {
public:
    int jumpFloor(int number) {
        if (number<2)    return 1;
        int f=1,g=1,sum;
        while(--number){
            sum=f+g;
            f=g;
            g=sum;
        }
        return sum;
    }
};
