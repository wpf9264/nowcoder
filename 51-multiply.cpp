/*构建成绩数组*/
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        /*对于B[i]是由两部分构成,先求左侧,再求右侧*/
        vector<int>B(A.size(),1);
        for(int i=1; i<A.size(); ++i){
            B[i]=B[i-1]*A[i-1];
        }
        int tmp=1;
        for(int i=A.size()-2; i>=0; --i){
            tmp*=A[i+1];
            B[i]*=tmp;
        }
        return B;
    }
};
