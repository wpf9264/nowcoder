/*连续子数组的最大和*/
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.empty())
            return 0;
        int maxSum,curSum;
        maxSum=curSum=array[0];
        for(int i=1; i<array.size(); ++i){
            curSum=curSum<0?array[i]:max(curSum,array[i-1])+array[i];
            maxSum =max(maxSum,curSum);
        }
        return maxSum;
    }
};
