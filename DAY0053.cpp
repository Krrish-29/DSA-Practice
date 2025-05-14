// 79. Word Search
class Solution {
public:
    // bool dfs(int i,int j,int index,vector<vector<char>>& board, string & word){
    //     if(index==word.size()) return true;
    //     vector<vector<int>> directions={{1,0},{-1,0},{0,1},{0,-1}};
    //     if(i<0||i>=board.size()||j<0||j>=board[0].size()||word[index]!=board[i][j]) return false;
    //     char temp=board[i][j];
    //     board[i][j]='#';
    //     for(int x=0;x<4;x++){
    //         int row=i+directions[x][0],col=j+directions[x][1];
    //         if(dfs(row,col,index+1,board,word)) return true;
    //     }
    //     board[i][j]=temp;
    //     return false;
    // }
    // bool exist(vector<vector<char>>& board, string word) {
    //     int ROW=board.size(),COL=board[0].size();
    //      unordered_map<char, int> board_freq;
    //     for (int i = 0; i < ROW; i++) {
    //         for (int j = 0; j < COL; j++) {
    //             board_freq[board[i][j]]++;
    //         }
    //     }
    //     unordered_map<char, int> word_freq;
    //     for (char ch : word) {
    //         word_freq[ch]++;
    //     }
    //     for (const auto& entry : word_freq) {
    //         if (board_freq[entry.first] < entry.second) {
    //             return false;
    //         }
    //     }
    //     for(int i=0;i<ROW;i++){
    //         for(int j=0;j<COL;j++){
    //             if(dfs(i,j,0,board,word)) return true;
    //         }
    //     }
    //     return false;
    // }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        unordered_set<string> visited;
        auto dfs = [&](int r, int c, int k, auto& dfs) -> bool {
            if (k == word.length()) {
                return true;
            }
            if (r < 0 || r >= rows || c < 0 || c >= cols || visited.count(to_string(r) + "," + to_string(c)) || board[r][c] != word[k]) {
                return false;
            }
            visited.insert(to_string(r) + "," + to_string(c));
            bool res = dfs(r + 1, c, k + 1, dfs) || dfs(r - 1, c, k + 1, dfs) || dfs(r, c + 1, k + 1, dfs) || dfs(r, c - 1, k + 1, dfs);
            visited.erase(to_string(r) + "," + to_string(c));
            return res;
        };
        unordered_map<char, int> count;
        for (char c : word) {
            count[c]++;
        }
        if (count[word[0]] > count[word.back()]) {
            reverse(word.begin(), word.end());
        }
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (dfs(r, c, 0, dfs)) {
                    return true;
                }
            }
        }
        return false;        
    }
};