/*变态跳台阶*/
class Solution {
public:
    int jumpFloorII(int number) 
    {
        if (number<1)    return 0;
        return 1<<(number-1);
    }
};
