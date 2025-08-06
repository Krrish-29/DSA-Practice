// 3479. Fruits Into Baskets III
class Solution {
private:
    void buildTree(vector<int>&segmentTree,vector<int>&baskets,int currIndex,int left ,int right){
        if(left==right){
            segmentTree[currIndex]=baskets[left];
            return ;
        }
        int mid=left+(right-left)/2;
        buildTree(segmentTree,baskets,2*currIndex+1,left,mid);
        buildTree(segmentTree,baskets,2*currIndex+2,mid+1,right);
        segmentTree[currIndex]=max(segmentTree[2*currIndex+1],segmentTree[2*currIndex+2]);
    }   
    void getBasket(vector<int>&segmentTree,int currIndex,int left,int right,int fruit,int &unplaced){
        if(segmentTree[currIndex]<fruit) {
            unplaced++;
            return;
        }
        if(left==right){
            segmentTree[currIndex]=-1;
            return ;
        }
        int mid=left+(right-left)/2;
        if(segmentTree[2*currIndex+1]>=fruit){
            getBasket(segmentTree,2*currIndex+1,left,mid,fruit,unplaced);
        }
        else{
            getBasket(segmentTree,2*currIndex+2,mid+1,right,fruit,unplaced);
        }
        segmentTree[currIndex]=max(segmentTree[2*currIndex+1],segmentTree[2*currIndex+2]);
    }
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int size=baskets.size();
        vector<int>segmentTree(2*pow(2,ceil(log2(size)))-1,0);
        buildTree(segmentTree,baskets,0,0,size-1);
        int unplaced=0;
        for(int fruit:fruits){
            getBasket(segmentTree,0,0,size-1,fruit,unplaced);
        }
        return unplaced;
    }
};