/*数组中的逆序数*/
class Solution {
public:
    int InversePairs(vector<int> data) {
        vector<int>tmp(data);
         long long res=numOfPairs(data,tmp,0,data.size()-1);
        return res%1000000007;
    }
    //[left,right]范围内的逆序对个数,且tmp逐渐有序
    long long numOfPairs(vector<int>&data,vector<int>&tmp,int left,int right)
    {
        if (left==right)    return 0;
        int mid=left+(right-left)/2;
        long long L = numOfPairs(data,tmp,left,mid);
        long long R = numOfPairs(data,tmp,mid+1,right);
        long long count=0;
        int i=mid,j=right,index=j;
        while(i>=left && j>=mid+1){
            if (data[i]>data[j]){
                count+=(j-mid);
                tmp[index--]=data[i--];
            }else{
                tmp[index--]=data[j--];
            }
        }
        while(i>=left)    tmp[index--]=data[i--];
        while(j>mid)      tmp[index--]=data[j--];
        for(int k=left; k<=right; ++k){
            data[k]=tmp[k];
        }
        return L+R+count;
    }
};
