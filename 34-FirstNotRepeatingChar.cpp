/*第一个只出现一次的字符*/
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        unordered_map<char,int>    record;
        for(auto&c:str)
            record[c]++;
        for(int i=0; i<str.size(); ++i){
            if (record[str[i]]==1)
                return i;
        }
        return -1;
    }
};
