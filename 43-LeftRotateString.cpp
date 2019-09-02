#include <assert.h>
class Solution {
public:
    string LeftRotateString(string str, int n) {
        //原理：YX = (XTYT)T
        assert(n>=0);
        if (n==0 || str.size()<2)    return str;
        int len=str.size();
        for(int i=0,j=n-1; i<=j; ++i,--j){
            std::swap(str[i],str[j]);
        }
        for(int i=n,j=len-1; i<=j; ++i,--j){
            std::swap(str[i],str[j]);
        }
        for(int i=0,j=len-1; i<=j; ++i,--j){
            std::swap(str[i],str[j]);
        }
        return str;
    }
};
