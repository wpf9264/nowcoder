/*整数中1出现的次数*/
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int count=0;
        int tmp=1;
        while(n/tmp>0){
            int a=n/(tmp*10);//左边的
            int b=n/tmp-a*10;//自己
            int c=n%tmp;//右边
            if (b>1){
                count+=(a+1)*tmp;
            }else if (b==0){
                count+=a*tmp;
            }else{
                count+=a*tmp+c+1;
            }
            tmp*=10;
        }
        return count;
    }
};


class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int count = 0;
        int i = 1;//个位开始
        for(int i=1; i<=n; i*=10)
        {
            int preNum = n / i;
            int nextNum= n % i;
            //这一步是真的非常牛逼，能通过补8来分析该位为0,1，>1的情况
            // =0或1时，补8，成9，不会对除10产生影响
            // >1时，补9，高位进一
            //后面判断低位的影响
            count += (preNum+8)/10*i + (preNum%10==1)*(nextNum+1);
        }
        return count;
    }
};
