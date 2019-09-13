/*机器人的运动范围*/
class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        return dfs(visited,rows,cols,0,0,threshold);
    }
    
    int dfs(vector<vector<bool>>& visited,int rows,int cols,int i,int j,int threshold)
    {
        if (i<0 || i>=rows || j<0 || j>=cols ||(sum(i)+sum(j))>threshold || visited[i][j]==true ){
            return 0;
        }
        visited[i][j]=true;
        return  dfs(visited,rows,cols,i+1,j,threshold)+
                dfs(visited,rows,cols,i-1,j,threshold)+
                dfs(visited,rows,cols,i,j+1,threshold)+
                dfs(visited,rows,cols,i,j-1,threshold)+1;
    }
    int sum(int x){
        int sum=0;
        while(x!=0){
            sum+=x%10;
            x/=10;
        }
        return sum;
    }
};
