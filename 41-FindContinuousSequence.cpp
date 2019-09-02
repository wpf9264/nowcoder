/*和为S的连续整数序列*/
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        int left=1,right=2;
        //[left,right]区间内有效
        while(left<right){
            int curSum=(left+right)*(right-left+1)/2;
            if (curSum>sum){
                left++;
            }else if (curSum<sum){
                right++;
            }else{
                vector<int> tmp;
                for(int i=left; i<=right; ++i){
                    tmp.push_back(i);
                }
                left++;
                res.push_back(tmp);
            }
        }
        return res;
    }
};
