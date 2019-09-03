/*把字符串转换成整数*/
class Solution {
public:
    int StrToInt(string str) {
        bool hasSign=false;
        bool isNega=false;
        int res=0;
        for(int i=0; i<str.size(); ++i){
            if (i==0){
                if (str[i]=='-'){
                    isNega=true;
                    hasSign=true;
                }else if (str[i]=='+'){
                    hasSign=true;
                }else if (isNum(str[i])){
                    res=(str[i]-'0');
                }else
                    return 0;
            }else{
                if (!isNum(str[i]))    return 0;
                res=(str[i]-'0')+ res*10;
            }
        }
        if (isNega)    return -res;
        return res;
    }
    bool isNum(char c)
    {
        if (c>='0' && c<='9')
            return true;
        return false;
    }
};
