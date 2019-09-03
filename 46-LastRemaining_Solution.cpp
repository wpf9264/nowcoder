/*圆圈中最后剩下的数*/
class Solution {
public:
    /*
    int LastRemaining_Solution(int n, int m)
    {
        if (n<1)    return -1;
        queue<int> q;
        for(int i=0; i<n; ++i)    q.push(i);
        int i=0;
        while(q.size()>1){
            if (i==m-1){
                i=0;
            }else{
                q.push(q.front());
                i++;
            }
            q.pop();
        }
        return q.front();
    }
    */
    int LastRemaining_Solution(int n, int m)
    {
        if (n<1 || m<0)    return -1;
        list<int> tmp;
        for(int i=0; i<n; ++i)    tmp.push_back(i);
        int i=0;
        auto iter=tmp.begin();
        while(tmp.size()>1){
            if (i==m-1){
                iter=tmp.erase(iter);
                i=0;
            }else{
                iter++;  i++;
            }
            if (iter==tmp.end())    iter=tmp.begin();
        }
        return tmp.front();
    }
};
