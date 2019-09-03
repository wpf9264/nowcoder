/*扑克牌顺子*/
class Solution {
public:
    /*
max 记录 最大值
min 记录  最小值
min ,max 都不记0
满足条件 1 max - min <5
        2 除0外没有重复的数字(牌)
        3 数组长度 为5
    */
    bool IsContinuous( vector<int> numbers )
    {
        if (numbers.empty())
            return false;
        int count[14]={0},minVal=14,maxVal=0;
        for(auto&x:numbers){
            if (x==0){
                count[x]++;
            }else{
                if (count[x]>0 || x>13 || x<0)
                    return false;
                else{
                    count[x]++;
                    maxVal=max(maxVal,x);
                    minVal=min(minVal,x);
                }
            }
        }
        if (maxVal-minVal>4)    return false;
        return true;
    }
    
    
    /*
    bool IsContinuous( vector<int> numbers ) {
        if (numbers.size()<5)    return false;
        sort(numbers.begin(),numbers.end());
        int numOfZero=0;
        int i=0;
        while(numbers[i++]==0)
            numOfZero++;
        for(i=numOfZero; i<numbers.size()-1; ++i){
            if (numbers[i]==numbers[i+1])    return false;
            int dif=numbers[i+1]-numbers[i];
            if(dif>1){
                numOfZero-=(dif-1);
                if (numOfZero<0)    return false;
            }
        }
        return true;
    }*/
};
