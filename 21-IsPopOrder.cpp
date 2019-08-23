/*栈的压入,弹出序列*/
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> s;
        int i=0,j=0,n=pushV.size();
        for(int i=0; i<n; ++i){
            s.push(pushV[i]);
            while (!s.empty() && j<n && s.top()==popV[j]){
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};
