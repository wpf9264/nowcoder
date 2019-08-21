/*举行覆盖*/
class Solution {
public:
    int rectCover(int number) {
        if (number<1)    return 0;
        if (number==1)    return 1;
        int f=1,g=1,sum;
        while(--number){
            sum=f+g;
            f=g;
            g=sum;
        }
        return sum;
    }
};
