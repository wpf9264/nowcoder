/*翻转单词顺序列*/
class Solution {
public:
    /*
    string ReverseSentence(string str) {
        auto iter1=str.begin();
        auto iter2=iter1;
        for( ; iter2!=str.end(); ++iter2){
            if (*iter2==' '){
                reverse(iter1,iter2);
                iter1=iter2+1;
            }
        }
        reverse(iter1,iter2);
        reverse(str.begin(),str.end());
        return str;
    }
    */
    string ReverseSentence(string str)
    {
        string res="",tmp="";
        for(auto&c:str){
            if (c==' '){
                res = " "+tmp+res;
                tmp="";
            }else{
                tmp+=c;
            }
        }
        if (!tmp.empty())
            res = tmp+res;
        return res;
    }
};
