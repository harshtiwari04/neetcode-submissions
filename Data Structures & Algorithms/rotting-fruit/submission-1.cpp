class Solution {
    private:
    void bfs(vector<vector<int>>& grid , vector<vector<int>>&vis,queue<pair<int,int>>&q){
        int m = grid.size();
        int n = grid[0].size();

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();

            for(int d=0 ; d<4 ;d++){
                int nrow=r+dx[d];
                int ncol=c+dy[d];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n
                && grid[nrow][ncol]==1 && vis[nrow][ncol]==-1){
                    vis[nrow][ncol]=vis[r][c]+1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,-1));
        queue<pair<int,int>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    vis[i][j]=0;
                }
            }
        }
        bfs(grid,vis,q);


        int maxminutes = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==-1){
                    return -1;
                }
                maxminutes=max(maxminutes,vis[i][j]);
            }
        }
     return maxminutes;   
    }
};
