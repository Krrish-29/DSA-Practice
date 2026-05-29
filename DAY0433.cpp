// 79. Word Search
class Solution {
private:
    int m,n;
    vector<vector<int>>dirs={{0,-1},{-1,0},{1,0},{0,1}};
    // struct hash{
    //     size_t operator()(const pair<int,int>&p)const {
    //         return ((size_t)p.first<<31)^(size_t)p.second;
    //     }
    // };
    // bool dfs(vector<vector<char>>& board,int i,int j,string word,int idx,unordered_set<pair<int,int>,hash> &seen){
    //     if(idx==word.size()) return true;
    //     seen.insert({i,j});
    //     for(auto &dir:dirs){
    //         int newX=dir[0]+i,newY=dir[1]+j;
    //         if(newX>=0 && newX<m && newY>=0 && newY<n && !seen.count({newX,newY}) && word[idx]==board[newX][newY]) {
    //             if(dfs(board,newX,newY,word,idx+1,seen)) return true;
    //         }
    //     }
    //     seen.erase({i,j});
    //     return false;
    // }
    bool dfs(vector<vector<char>>& board,int i,int j,string word,int idx){
        if(idx==word.size()) return true;
        char t=board[i][j];
        board[i][j]='1';
        for(auto &dir:dirs){
            int newX=dir[0]+i,newY=dir[1]+j;
            if(newX>=0 && newX<m && newY>=0 && newY<n && word[idx]==board[newX][newY]) {
                if(dfs(board,newX,newY,word,idx+1)) return true;
            }
        }
        board[i][j]=t;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        // unordered_set<pair<int,int>,hash>seen;
        m=board.size();n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]) {
                    // if(dfs(board,i,j,word,1,seen)) return true;
                    if(dfs(board,i,j,word,1)) return true;
                }
            }
        }
        return false;
    }
};