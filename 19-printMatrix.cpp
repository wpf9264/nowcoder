/*顺时针打印矩阵*/
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        if (matrix.empty())    return res;
        int i=0, j=matrix.size()-1;
        int l=0, r=matrix[0].size()-1;
        /*至少得有一个元素*/
        while(i<=j && l<=r){
            /*右*/
            if (l<=r){
                for(int k=l; k<=r; ++k)    res.push_back(matrix[i][k]);
            }
            /*下*/
            if (i<j){
                for(int k=i+1; k<=j; ++k)    res.push_back(matrix[k][r]);
            }
            /*左*/
            if (i<j && l<r){
                for(int k=r-1; k>=l; --k)    res.push_back(matrix[j][k]);
            }
            /*上*/
            if (i+1<j && l<r){
                for(int k=j-1; k>i; --k)    res.push_back(matrix[k][l]);
            }
            i++;j--;l++;r--;
        }
        return res;
    }
};
