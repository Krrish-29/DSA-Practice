// 2300. Successful Pairs of Spells and Potions
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int size=spells.size();
        vector<int>answer;
        for(int s:spells){
            if(success%s==0) answer.push_back(potions.end()-lower_bound(potions.begin(),potions.end(),success/s));
            else answer.push_back(potions.end()-upper_bound(potions.begin(),potions.end(),success/s));
        }
        return answer;
    }
};