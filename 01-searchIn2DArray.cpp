class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if (array.empty())
            return false;
        int row=array.size(), col=array[0].size();
        int i=row-1, j=0;
        while(i>=0 && j<col){
            if (target < array[i][j]){
                i--;
            }else if (target > array[i][j]){
                j++;
            }else{
                return true;
            }
        }
        return false;
    }
};