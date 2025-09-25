// 49. Group Anagrams
class Solution {
private:
    const int mod=1e9+7;
   int primes[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>answer;
        map<int,int>map;
        for(auto str:strs){
            long hash=1;
            for(char ch:str){
                hash=(hash*primes[ch-'a'])%mod;
            }
            if(map.find(hash)==map.end()){
                answer.push_back({str});
                map[hash]=((int)answer.size()-1);
            }
            else answer[map[hash]].push_back(str);
        }
        return answer;
    }
};