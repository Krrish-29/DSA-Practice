// 407. Trapping Rain Water II
class Solution {
private:
    struct Compare {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0]; // min-heap based on a[0]
        }
    };
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        // create a min heap to strore the boundary heights
        int row=heightMap.size(),col=heightMap[0].size();
        priority_queue<vector<int>,vector<vector<int>>,Compare>pq;
        for(int i=0;i<row;i++){
            pq.push({heightMap[i][0],i,0});
            heightMap[i][0]=-1;
            pq.push({heightMap[i][col-1],i,col-1});
            heightMap[i][col-1]=-1;
            if(i==0||i==row-1){
                for(int j=1;j<col-1;j++){
                    pq.push({heightMap[i][j],i,j});
                    heightMap[i][j]=-1;
                }
            }
            
        }
        // use minheap to process the boundary elements and calculate trapped water by checking the neighbors
        int water=0,maxH=-1;
        int h,r,c;
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        while(!pq.empty()){
            auto top=pq.top();
            h=top[0],r=top[1],c=top[2];
            pq.pop();
            maxH=max(h,maxH);
            water+=maxH-h;
            for(const auto &d:dir){
                if(r+d[0]<0||r+d[0]>=row||c+d[1]<0||c+d[1]>=col||heightMap[r+d[0]][c+d[1]]==-1) continue;
                pq.push({heightMap[r+d[0]][c+d[1]],r+d[0],c+d[1]});
                heightMap[r+d[0]][c+d[1]]=-1;
            }
        }
        return water;
    }
};