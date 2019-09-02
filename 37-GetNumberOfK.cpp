/*数字在排序数组中出现的次数*/
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        return insert(data,k+0.5)-insert(data,k-0.5);
    }
    int insert(vector<int>&data,float x)
    {
        int i=0,j=data.size()-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if (data[mid]<x)
                i=mid+1;
            else
                j=mid-1;
        }
        return i;
    }
     
};
