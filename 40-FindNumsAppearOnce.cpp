/*数组中只出现一次的数字*/
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        unordered_set<int> record;
        for(auto&x:data){
            if (record.find(x)==record.end()){
                record.insert(x);
            }else{
                record.erase(x);
            }
        }
        auto iter=record.begin();
        *num1=*iter++;
        *num2=*iter;
    }
};
