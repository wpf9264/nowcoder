/*正则表达式匹配*/
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        /* 1.如果均为空，返回真
         * 2.字符串为空，模式非空，返回假
         * 3.当前比较位置的后一位不是*
             3.1 两个首字符相同，字符串和模式均后移一位        递归调用本身
             3.2 字符串非空，模式为.，字符串和模式均后移一位    递归调用本身
             3.3 否则返回假
           4.当前比较位置的后一位是*
             4.1 模式*匹配到了0个字符，模式后移两位，跳过*，   递归调用本身
             4.2 模式*匹配到了字符
                 4.2.1有可能匹配的字符比较完了，就相当于4.1
                 4.2.2多于1个，字符串后移一位，模式不变，     递归调用本身
        */
        if (*str=='\0' && *pattern=='\0')    return true;
        if (*str!='\0' && *pattern=='\0')    return false;
        if (*(pattern+1)!='*'){
            if (*str==*pattern || (*str!='\0' && *pattern=='.'))
                return match(str+1,pattern+1);
            else
                return false;
        }else{
            if (*str==*pattern || (*str!='\0' && *pattern=='.'))
                return match(str,pattern+2) || match(str+1,pattern);
            else
                return match(str,pattern+2);
        }
    }
};
