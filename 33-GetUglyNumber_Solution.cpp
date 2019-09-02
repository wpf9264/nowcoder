/*丑数*/
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        //质因数：能整除给定正整数的质数
        //质数：除了1和它本身以外不再有其他因数
        //将一个数分解因子，分解到无可再分的时候，只包含2,3,5就行
        //12：==> 2*2*3是    14：==> 2*7 不是
        if (index==0)    return 0;
        vector<int> record;
        record.push_back(1);
        int p2=0,p3=0,p5=0;
        while(record.size()<index){
            //p2,p3,p5分别指向对某个数进行乘2,3,5得到的最小值
            int newVal=min(record[p2]*2,min(record[p3]*3,record[p5]*5));
            if (record[p2]*2==newVal)    p2++;
            if (record[p3]*3==newVal)    p3++;
            if (record[p5]*5==newVal)    p5++;
            record.push_back(newVal);
        }
        return record.back();
    }
};
