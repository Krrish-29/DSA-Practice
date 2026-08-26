// 773. Sliding Puzzle
class Solution {
private:
    string getConfig(vector<vector<int>>& board){ 
        return to_string(board[0][0])+to_string(board[0][1])+to_string(board[0][2])+to_string(board[1][0])+to_string(board[1][1])+to_string(board[1][2]);
    }
    unordered_map<string,int>dist;
    int min_moves=INT_MAX;
    void dfs(vector<vector<int>>& board,int x,int y,int moves){
        if(moves>=min_moves) return;
        string config=getConfig(board);
        if(config=="123450") {
            min_moves=min(min_moves,moves);
            return;
        }
        if(dist.count(config) && dist[config]<=moves) return ;
        dist[config]=moves;
        if(y>0) {
            swap(board[x][y],board[x][y-1]);
            dfs(board,x,y-1,moves+1);
            swap(board[x][y],board[x][y-1]);
        }
        if(y+1<3) {
            swap(board[x][y],board[x][y+1]);
            dfs(board,x,y+1,moves+1);
            swap(board[x][y],board[x][y+1]);
        }
        if(x>0) {
            swap(board[x][y],board[x-1][y]);
            dfs(board,x-1,y,moves+1);
            swap(board[x][y],board[x-1][y]);
        }
        if(x+1<2) {
            swap(board[x][y],board[x+1][y]);
            dfs(board,x+1,y,moves+1);
            swap(board[x][y],board[x+1][y]);
        }
    }
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // dfs
        // for(int i=0;i<2;i++){
        //     for(int j=0;j<3;j++){
        //         if(board[i][j]==0) dfs(board,i,j,0);
        //     }
        // }
        // return min_moves==INT_MAX?-1:min_moves;

        // bfs
        // consider all moving positions based on current location of 0
        // for easier working make the grid into a string and convert the i,j to i*3+j 
        // also due to nature of bfs the first target config we find would be the least moves one
        // also since there are limited configs use a set to store seen ones
        // to avoid TLE and MLE.
        // 0 1 2 
        // 3 4 5
        vector<vector<int>> dirs = {{1,3},{0,2,4},{1,5},{0,4},{3,1,5},{4,2}};
        string puzzle;
        string target="123450";
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                puzzle += to_string(board[i][j]);
            }
        }
        queue<pair<int,string>>q; // moves , config
        unordered_set<string>seen;
        q.push({0,puzzle});
        seen.insert(puzzle);
        while(!q.empty()){
            pair<int,string>ele = q.front();q.pop();
            if(ele.second == target) return ele.first;
            int idx = ele.second.find('0');
            string newPuzzle;
            for(auto &dir:dirs[idx]){
                newPuzzle=ele.second;
                swap(newPuzzle[idx],newPuzzle[dir]);
                if(!seen.count(newPuzzle)){
                    q.push({ele.first+1,newPuzzle});
                    seen.insert(newPuzzle);
                }
            }
        }
        return -1;
    }
};