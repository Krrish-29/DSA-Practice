// 216. Combination Sum III
// using freq map to use one elem at a time but since we are using start var to limit the combinations we generally do not require it 
class Solution {
private:
    vector<vector<int>>ans;
    void backTrack(int k,int target,vector<int>&freq,int start){
        if(k==0&&target==0){
            vector<int>a;
            for(int i=1;i<10;i++){
                if(freq[i-1]==1) a.push_back(i);
            }
            ans.push_back(a);
        } 
        if(k==0||target==0) return ;
        for(int i=start;i<10;i++){
            if(freq[i-1]==0){
                freq[i-1]=1;
                backTrack(k-1,target-i,freq,i+1);
                freq[i-1]=0;
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>freq(9,0);
        backTrack(k,n,freq,1);
        return ans;
    }
};
// using a simple vector to store used elements
// class Solution {
// private:
//     vector<vector<int>>ans;
//     void backTrack(int k,int target,vector<int>freq,int start){
//         if(k==0&&target==0) ans.push_back(freq);
//         if(k==0||target==0) return ;
//         for(int i=start;i<10;i++){
//             freq.push_back(i);
//             backTrack(k-1,target-i,freq,i+1);
//             freq.pop_back();
//         }
//     }
// public:
//     vector<vector<int>> combinationSum3(int k, int n) {
//         backTrack(k,n,{},1);
//         return ans;
//     }
// };