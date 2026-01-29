// 2812. Find the Safest Path in a Grid
class Solution {
private:    
    vector<vector<int>>dirs={{0,1},{1,0},{-1,0},{0,-1}};
    int getSafeScore(vector<vector<int>>&preSafe,vector<vector<int>>&grid,int n){
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) {
                    q.push({i,j});
                    preSafe[i][j]=0;
                }
            }
        }
        int maxScore=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto ele=q.front();q.pop();
                for(auto &dir:dirs){
                    int x=ele.first+dir[0],y=ele.second+dir[1];
                    if(x<n&&y<n&&x>=0&&y>=0&&preSafe[x][y]==-1) {
                        q.push({x,y});
                        preSafe[x][y]=1+preSafe[ele.first][ele.second];
                        maxScore=max(maxScore,preSafe[x][y]);
                    }
                }
            }
        }
        return maxScore;
    }
    bool isPossible(vector<vector<int>>&grid,vector<vector<int>>&preSafe,int target,int n){
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        queue<pair<int,int>>q;
        if(preSafe[0][0]<target) return false;
        q.push({0,0});
        vis[0][0]=true;
        while(!q.empty()){
            auto ele=q.front();q.pop();
            if(ele.first==n-1&&ele.second==n-1) return true;
            for(auto &dir:dirs){
                int x=ele.first+dir[0],y=ele.second+dir[1];
                if(x<n&&y<n&&x>=0&&y>=0&&!vis[x][y]&&preSafe[x][y]>=target){
                    q.push({x,y});
                    vis[x][y]=true;
                }
            }
        }
        return false;
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1||grid[n-1][n-1]==1) return 0;
        vector<vector<int>>preSafe(n,vector<int>(n,-1));
        int left=0,right=getSafeScore(preSafe,grid,n),mid,ans=0;
        while(left<=right){
            mid=left+(right-left)/2;
            if(isPossible(grid,preSafe,mid,n)){
                ans=mid;
                left=mid+1;
            }
            else right=mid-1;
        }
        return ans;
    }
};