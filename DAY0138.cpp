// 3363. Find the Maximum Number of Fruits Collected
class Solution {
private:
    vector<vector<int>>memo;
    int dfs(int row,int col,int moves,int size,vector<pair<int,int>>&dir,vector<vector<int>>&fruits){
        if(row==size-1&&col==size-1) return moves==0?0:INT_MAX;
        if(moves==0||row==col) return INT_MAX;
        if(memo[row][col]!=-1) return memo[row][col];
        long long maxFruits=-1;
        for(auto const [i,j]:dir){
            if(row+i>=0&&row+i<size&&col+j>=0&&col+j<size){
                int temp=dfs(row+i,col+j,moves-1,size,dir,fruits);
                if(temp!=INT_MAX) maxFruits=max(maxFruits,(long long )temp);
            }
        }
        return memo[row][col]=(maxFruits<0?INT_MAX:maxFruits+fruits[row][col]);
    }
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        long total=0,size=fruits.size();

        // child 1 (0,0)
        for(int i=0;i<size;i++){
            total+=fruits[i][i];

        }
        // child 2(0,n-1)
        memo.resize(size,vector<int>(size,-1));
        vector<pair<int,int>>dir={{1,1},{1,0},{1,-1}};
        total+=dfs(0,size-1,size-1,size,dir,fruits);

        // child 3(n-1,0)
        for (auto& row : memo) fill(row.begin(), row.end(), -1);
        dir={{1,1},{0,1},{-1,1}};
        total+=dfs(size-1,0,size-1,size,dir,fruits);
        return total;
    }
};