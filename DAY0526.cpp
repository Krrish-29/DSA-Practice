// 1284. Minimum Number of Flips to Convert Binary Matrix to Zero Matrix
class Solution {
private:
    void flip(char &ch){
        if(ch=='0') ch='1';
        else if(ch=='1') ch='0';
    }
public:
    int minFlips(vector<vector<int>>& mat) {
        // first the grid is not too big we can try all combinations 
        // at max the grid can be 3X3 and each cell can have 0 or 1 making at max 2^9 different configs of the grid
        // to start off convert the grid to a row major string to save on space 
        // then using bfs , set for seen configs and dirs to flip the adjacent neighbours
        // first we have to convert each idx to x and y check if the neighbours are available
        // and flip them as well as the currIdx , after this if the string created is not seen add to queue with moves+1
        // we are bruteforcing each idx cause only fliping 1 or 0 might not result in minimum ans
        int m=mat.size(),n=mat[0].size();
        string grid;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid+=to_string(mat[i][j]);
            }
        }

        queue<pair<int,string>>q; // moves , grid
        unordered_set<string>seen;
        q.push({0,grid});
        seen.insert(grid);
        vector<vector<int>>dirs={{0,1},{0,-1},{1,0},{-1,0}};
        int moves,x,y,newX,newY,newI;
        string str,newStr,target = string(m*n,'0');

        while(!q.empty()){
            auto ele = q.front();q.pop();
            moves = ele.first;
            str = ele.second;
            if(str == target) return moves;
            for(int i=0;i<m*n;i++){
                newStr = str;
                x = i/n;
                y = i%n;
                flip(newStr[i]);
                for(auto &dir:dirs){
                    newX = dir[0]+x;
                    newY = dir[1]+y;
                    if(newX>=0 && newX<m && newY>=0 && newY<n){
                        newI = newX*n+newY;
                        flip(newStr[newI]);
                    }
                }
                if(!seen.count(newStr)) {
                    q.push({moves+1,newStr});
                    seen.insert(newStr);
                }
            }
        }
        return -1;
    }
};