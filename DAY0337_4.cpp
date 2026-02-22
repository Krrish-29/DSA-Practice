// 3850. Count Sequences to K
class Solution {
private:
    map<tuple<int,long long,long long>,int>dp;
    void normalize(long long &a,long long &b){
        long long g=gcd(a,b);
        a/=g;
        b/=g;
    }
    int helper(vector<int>&nums,long long &k,int idx,long long num,long long denum){
        normalize(num,denum);
        if(idx==nums.size()){
            return (num==k&&denum==1);
        }
        int count=0;
        if(dp.count({idx,num,denum})) return dp[{idx,num,denum}];
        count+=helper(nums,k,idx+1,num*nums[idx],denum);
        count+=helper(nums,k,idx+1,num,denum*nums[idx]);
        count+=helper(nums,k,idx+1,num,denum);
        return dp[{idx,num,denum}]=count;
    }
public:
    int countSequences(vector<int>& nums, long long k) {
        // can be solved with meet in the middle for O(3^(n/2))
        // but also with recursion just needed a little memo for caching 
        // so used a map with tuple as the idx num and denum are the states that change 
        // initially did recursion without memo and got tle (obviously) 
        // and need to normalize the num and denum every time with gcd
        long long num=1,denum=1;
        return helper(nums,k,0,num,denum);
    }
};
// class Solution {
// private:
//     struct hash_pair{
//         size_t operator()(const pair<long long,long long>&p) const{
//             return hash<long long>()(p.first)^hash<long long>()(p.second);
//         }
//     };
//     int count=0;
//     unordered_map<pair<long long,long long>,int,hash_pair>map;
//     void normal(long long &a,long long & b){
//         long long g=gcd(a,b);
//         a/=g;
//         b/=g;
//     }
//     void helper(vector<int>&nums,long long k,int idx,int size,long long num,long long denum){
//         if(idx==size){
//             normal(num,denum);
//             map[{num,denum}]++;
//             return ;
//         }
//         helper(nums,k,idx+1,size,num*nums[idx],denum);
//         helper(nums,k,idx+1,size,num,denum*nums[idx]);
//         helper(nums,k,idx+1,size,num,denum);
//     }
//     void helper1(vector<int>&nums,long long k,int idx,int size,long long num,long long denum){
//         if(idx==size){
//             denum*=k;
//             normal(denum,num);
//             if(map.count({denum,num})>0) count+=(map.count({denum,num})*map.count({num,denum}));
//             return ;
//         }
//         helper1(nums,k,idx+1,size,num*nums[idx],denum);
//         helper1(nums,k,idx+1,size,num,denum*nums[idx]);
//         helper1(nums,k,idx+1,size,num,denum);
//     }
// public:
//     int countSequences(vector<int>& nums, long long k) {
//         map[{1,1}]=1;
//         long long num=1,denum=1;
//         int size=nums.size();
//         helper(nums,k,0,size/2,num,denum);
//         helper1(nums,k,size/2,size,num,denum);
//         return count;
//     }
// };