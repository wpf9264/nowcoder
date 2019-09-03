/*求1+2+...+n*/
class Solution {
public:
    int Sum_Solution(int n) {
        //逻辑与的短路原理，当n为0，后面的就不再判断
        //递归求解,
        int res=n;
        res && (res+=Sum_Solution(n-1));
        return res;
    }
};
