/*
 * 数组中出现次数超过一般的数字
 *         首先我们要知道这种数组的哟个特性：
        假如存在某一元素temp出现的次数超过长度的一半，
        那么我们从数组中去掉两个相异的数字，temp出现的次数还是大于剩下数组长度的一半。
        基于这个事实，我们每次比较两个元素：
        1.首先选定numbers[0]为基准元素temp，此时temp出现次数count为1
        2.如果numbers[1]与temp相同，计数count加一
        3.如果numbers[1]与temp不同，计数count减一
        在此过程中肯定会遇到计数为零的情况，计数为零说明前面的元素均为成对相异，
        因此我们直接选定剩下子数组的首元素为新的额基准temp，这并不会破坏该数组的特性。
 */
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty())
            return 0;
            
        int pre=numbers[0],count=1;
        for(int i=1; i<numbers.size(); ++i){
            if (count==0){
                pre=numbers[i];
                count=1;
                continue;
            }
            if (numbers[i]==pre){
                count++;
            }else{
                count--;
            }
        }
        count=0;
        for(auto&x:numbers){
            if (x==pre)
                count++;
        }
        return count>numbers.size()/2?pre:0;
    }
    
    int MoreThanHalfNum_Solution(vector<int> numbers) 
    {
        if (numbers.empty())    return 0;
        sort(numbers.begin(),numbers.end());
        return 
    }
};
