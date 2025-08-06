// 307. Range Sum Query - Mutable
class NumArray {
private:
    vector<int>copy;
    vector<int>segmentTree;
    int size;
    int createTree(int currIndex,int left,int right,vector<int>&nums){
        if(left==right){
            segmentTree[currIndex]=nums[left];
            return segmentTree[currIndex];
        }
        int mid=left+(right-left)/2;
        segmentTree[currIndex]=createTree(2*currIndex+1,left,mid,nums)+createTree(2*currIndex+2,mid+1,right,nums);
        return segmentTree[currIndex];
    }
    int getSum(int currIndex,int treeLeft,int treeRight,int left,int right){
        if(treeLeft>right||treeRight<left) return 0;
        if(left<=treeLeft&&treeRight<=right) return segmentTree[currIndex];
        int mid=treeLeft+(treeRight-treeLeft)/2;
        return getSum(2*currIndex+1,treeLeft,mid,left,right)+getSum(2*currIndex+2,mid+1,treeRight,left,right);
    }  
    void updateTree(int currIndex,int left,int right,int index,int value){
        if(index<left||index>right) return ;
        segmentTree[currIndex]+=value;
        if(left!=right){
            int mid=left+(right-left)/2;
            updateTree(2*currIndex+1,left,mid,index,value);
            updateTree(2*currIndex+2,mid+1,right,index,value);
        }
    } 
public:
    NumArray(vector<int>& nums) {
        size=nums.size();
        copy=nums;
        segmentTree.resize(2*pow(2,ceil(log2(size)))-1,0);
        createTree(0,0,size-1,nums);
    }
    
    void update(int index, int val) {
        updateTree(0,0,size-1,index,val-copy[index]);
        copy[index]=val;
    }
    
    int sumRange(int left, int right) {
        return getSum(0,0,size-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */