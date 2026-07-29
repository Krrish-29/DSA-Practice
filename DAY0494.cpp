// 3996. Even Number of Knight Moves
class Solution {
private:
    struct hash{
        size_t operator()(const pair<int,int>&a) const {
            return (a.first*31)^(a.second);
        }
    };
    vector<vector<int>>moves={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
    unordered_set<pair<int,int>,hash>seen;
    bool dfs(int startX,int startY,int &targetX,int &targetY,int movesCount){
        if(startX==targetX && startY==targetY && movesCount%2==0) return true;
        for(auto &move:moves){
            int x=startX+move[0],y=startY+move[1];
            if(x>=0 && x<=7 && y>=0 && y<=7 && !seen.count({x,y})){
                seen.insert({x,y});
                if(dfs(x,y,targetX,targetY,movesCount+1)) return true;
            }
        }
        return false;
    }
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        // do simple dfs
        // return dfs(start[0],start[1],target[0],target[1],0);
        
        // another trick 
        // if startX and startY sum is even then at every moves we take adds 3 to sum making it odd
        // therefore doing it again will make sum even again , same situation for starting sum being odd
        // so if we do even moves then if we start from even sum we will end up at even sum
        return (start[0]+start[1])%2==(target[0]+target[1])%2;
    }
};