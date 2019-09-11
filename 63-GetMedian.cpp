/*数据流中的中位数*/
class Solution {
public:
    vector<int> v;
    int n=0;
    void Insert(int num)
    {
        v.push_back(num);
        n=v.size();
        for(int i=n-1; i>=0 && v[i]<v[i-1]; --i)
            swap(v[i],v[i-1]);
    }

    double GetMedian()
    { 
        return (v[(n-1)/2]+v[n/2])/2.0;
    }

};
