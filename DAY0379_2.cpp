// 3890. Integers With Multiple Sum of Two Cubes
class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        vector<int>cubes;
        for(int i=1;i<1001;i++){
            cubes.push_back(i*i*i);
        }
        unordered_map<int,int>map;
        for(int i=0;i<1000;i++){
            for(int j=i;j<1000;j++){
                if(cubes[i]+cubes[j]<=n) map[cubes[i]+cubes[j]]++;
            }
        }
        vector<int>ans;
        for(auto it=map.begin();it!=map.end();++it){
            if(it->second>=2) ans.push_back(it->first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};