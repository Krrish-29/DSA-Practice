// 303. Range Sum Query - Immutable
class NumArray {
private:
    vector<int>sum;
public:
    NumArray(vector<int>& nums) {
        int size=nums.size();
        sum=move(nums);
        for(int i=1;i<size;i++){
            sum[i]+=sum[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0) return sum[right];
        return sum[right]-sum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */