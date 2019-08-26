/*最小的k个数*/
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int>res;
        if (input.empty() || k>input.size() || k<=0)
            return res;
        multiset<int> s;
        for(auto&x:input){
            if (s.size()<k){
                s.insert(x);
            }else{
                auto iter=s.end();
                --iter;
                if (x<*iter){
                    s.erase(iter);
                    s.insert(x);
                }
            }
        }
        for(auto iter1=s.begin(); iter1!=s.end(); ++iter1){
            res.push_back(*iter1);
        }
        return res;
    }
};
