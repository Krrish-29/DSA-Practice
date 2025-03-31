// 26. Remove Duplicates from Sorted Array

// class Solution {
//     public:
//         int removeDuplicates(vector<int>& nums) {
//             int answer=1,x=nums[0];
//             for(int i=1;i<nums.size();i++){
//                 if(x==nums[i]){
//                     nums.erase(nums.begin()+i);
//                     i--;
//                 }
//                 else{
//                     x=nums[i];
//                     answer++;
//                 }
//             }
//             return answer;
//         }
//     };

// class Solution {
//     public:
//         int removeDuplicates(vector<int>& nums) {
//             int i=0,j=1;
//             while(j<nums.size()){
//                 if(nums[i]!=nums[j]){
//                     i++;
//                     nums[i]=nums[j];
//                 }
//                 else{
//                     j++;
//                 }
//             }
//             return i+1;
//         }
//     };