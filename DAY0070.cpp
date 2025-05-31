//909. Snakes and Ladders
class Solution {
public:
    vector<int>get_coords(int num,int size){
        int row = size - 1 - (num - 1) / size;
    	int col = (num - 1) % size;
        if((size%2==0&&row%2==0)||(size%2==1&&row%2==1)) col=size-1-col;
        return {row,col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int size=board.size();
        int moves=0;
        vector<vector<bool>>vis(size,vector<bool>(size,false));
        vis[size-1][0]=true;
        queue<int>queue;
        queue.push(1);
        while(!queue.empty()){
            int n=queue.size();
            while(n--){
                int curr=queue.front();
                queue.pop();
                if(curr==size*size) return moves;
                for(int i=1;i<=6;i++){
                    int next=curr+i;
                    if((curr+i)>size*size) break;
                    vector<int>coords=get_coords(next,size);
                    if(vis[coords[0]][coords[1]]) continue;
                    vis[coords[0]][coords[1]]=true;
                    if(board[coords[0]][coords[1]]!=-1) next=board[coords[0]][coords[1]];        
                    queue.push(next);
                }
            }
            moves++;
        }
        return -1;
    }
};
