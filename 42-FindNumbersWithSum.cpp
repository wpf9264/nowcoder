/*和为S的两个数字*/
class Solution {
public:
    //左右加逼，两个数相差越大，即左边的数越小，乘积越小
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int i=0,j=array.size()-1;
        vector<int>res;
        while(i<j){
            int tmp=array[i]+array[j];
            if (tmp>sum){
                --j;
            }else if (tmp<sum){
                ++i;
            }else{
                res.push_back(array[i]);
                res.push_back(array[j]);
                return res;
            }
        }
        return res;
    }
};
