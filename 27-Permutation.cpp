/*字符循环的排列*/
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        if (str.empty())
            return res;
        helper(res,str,0);
        sort(res.begin(),res.end());
        return res;
    }
    void helper(vector<string>&res,string str,int k)
    {
        /*
            整体思路：
            1.将首字符逐个与后面的的字符相交换，
            2.然后将次首字符与后面的字符交换
            3.直到只剩下最后一位字符，无法再继续交换
        */
        //当某字符要与其后字符交换时：发现其自身已经是最后一个字符了
        //不可能有别的组合情况了，res
        if (k==str.size()-1)    res.push_back(str);
        //将当前子串的首字符依次与后面的字符交换位置
        for(int i=k; i<str.size(); ++i){
            //首字符与其后面的字符相同，跳过
            if (i!=k && str[i]==str[k])
                continue;
            //交换位置后,获得一个新的子串[k+1: ],再对改子串递归处理
            std:;swap(str[i],str[k]);
            helper(res,str,k+1);
        }
    }
};
