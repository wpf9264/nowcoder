/*
    调整数组顺序使奇数位于偶数前面
    时间换空间,将奇数前的偶数逐个后移一位
*/
class Solution {
public:
    void reOrderArray(vector<int> &array) 
    {
        if (array.empty())    return;
        /*[0,k)区间内为已排序元素(左闭右开)*/
        int k=0;
        for(int i=0; i<array.size(); ++i){
            if (array[i]&0x1){
                int tmp=array[i];
                int j=i;
                while(j>k){
                    array[j]=array[j-1];
                    j--;
                }
                array[k++]=tmp;
            }
        }
    }
};
