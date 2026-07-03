class Solution {
    private:
    int bfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();


        queue<pair<int,int>>q;
        q.push({row,col});
        vis[row][col]=1;

        int area =1;

        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};


        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();

        for(int k=0;k<4;k++){
            int newr=r+dx[k];
            int newc=c+dy[k];

            if(newr>=0 && newr<n && newc>=0 && newc<m &&
            !vis[newr][newc] && grid[newr][newc]==1){
                vis[newr][newc]=1;
                q.push({newr,newc});
                area++;
            }
        }
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        int maxarea=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    maxarea = max(maxarea , bfs(i,j,vis,grid));
                }
                
            }
        }
   return maxarea;
    }
};
