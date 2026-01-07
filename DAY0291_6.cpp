// 1470. Shuffle the Array
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for(int i=n-1;i>=1;i--){
            for(int j=i;j<2*i;j++){
                swap(nums[j],nums[j+1]);
            }
        }
        return nums;
        //idx0 1 2 3 4 5 6 7 
        //   1 2 3 4 5 6 7 8
        //   swap 4 5 6 7 (i 3->6) from 4 to 7 making it 5 6 7 4
        //   1 2 3 5 6 7 4 8
        //   swap 3 5 6 (i 2->4) from 3 to 6 making it 5 6 3
        //   1 2 5 6 3 7 4 8
        //   swap 2 5 (i 1->2) from 2 to 5 making it 5 2
        //   1 5 2 6 3 7 4 8
    }
};