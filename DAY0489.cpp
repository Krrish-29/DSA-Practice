// 3514. Number of Unique XOR Triplets II
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        // int size=nums.size();
        // unordered_set<int>seen;
        // for(int i=0;i<size;i++){
        //     for(int j=i;j<size;j++){
        //         for(int k=j;k<size;k++){
        //             seen.insert(nums[i]^nums[j]^nums[k]);
        //         }
        //     }
        // }
        // return seen.size();

        // add elems from set 2 to set 3 by doing xor with current num
        // add elems from set 1 to set 2 by doing xor with current num
        // then add curr elems xor to set 1 ,2 and 3
        // set 1 means normal elems 
        // set 2 is values obtained by doing xor of 2 elems
        // set 3 is values obtained by doing xor of 3 elems
        unordered_set<int>set1;
        unordered_set<int>set2;
        unordered_set<int>set3;
        for(int &num:nums){
            for(auto &twoXor:set2){
                set3.insert(twoXor^num);
            }
            for(auto &oneXor:set1){
                set2.insert(oneXor^num);
            }
            set1.insert(num);
            set2.insert(num^num);
            set3.insert(num^num^num);
        }
        return set3.size();
    }
};