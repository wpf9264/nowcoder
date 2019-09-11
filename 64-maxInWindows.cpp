/*滑动窗口的最大值*/
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int>res;
        if (num.empty() || num.size()<size || size<=0)
            return res;
        for(int i=0; i<num.size()-size+1; ++i){
            int tmp=num[i];
            for(int j=1; j<size; ++j){
                tmp=max(tmp,num[i+j]);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
