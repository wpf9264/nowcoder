/*二进制中1的个数*/
class Solution {
public:
     int  NumberOf1(int n) {
         int res=0;
         while(n!=0){
             n&=(n-1);
             res++;
         }
         return res;
     }
};
