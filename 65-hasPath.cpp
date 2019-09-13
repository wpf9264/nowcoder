/*矩阵中的路径*/
class Solution {
public:
    int r,c;
    vector<vector<bool>> visited;
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        r=rows; c=cols;
        visited=vector<vector<bool>>(r,vector<bool>(c,false));
        for(int i=0; i<rows; ++i){
            for(int j=0; j<cols; ++j){
                if (dfs(matrix,str,i,j,0))
                    return true;
            }
        }
        return false;
    }
    /*判断matrix[i][j]与str[k]是否相同,是就继续dfs*/
    bool dfs(char* matrix, char* str, int i, int j,int k)
    {
        int index=i*c+j;
        if (i>=r || j>=c || matrix[index]!=str[k] || visited[i][j]==true)
            return false;
        if (str[k+1]=='\0')
            return true;
        visited[i][j]=true;
        bool res=false;
        if (i>0   && visited[i-1][j]==false)    res|=dfs(matrix,str,i-1,j,k+1);
        if (i<r-1 && visited[i+1][j]==false)    res|=dfs(matrix,str,i+1,j,k+1);
        if (j>0   && visited[i][j-1]==false)    res|=dfs(matrix,str,i,j-1,k+1);
        if (i<c-1 && visited[i][j+1]==false)    res|=dfs(matrix,str,i,j+1,k+1);
        visited[i][j]=false;
        return res;
    }


};
