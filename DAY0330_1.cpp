// 3842. Toggle Light Bulbs
class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int>switchs(100,0);
        for(int &num:bulbs){
            switchs[num-1]++;
        }
        vector<int>ans;
        for(int i=0;i<100;i++){
            if(switchs[i]%2==1) ans.push_back(i+1);
        }
        return ans;
    }
};