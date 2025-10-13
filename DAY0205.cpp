// 2273. Find Resultant Array After Removing Anagrams
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int size=words.size();
        deque<pair<string,int>>dq;
        string temp=words[0];
        sort(temp.begin(),temp.end());
        dq.push_front(make_pair(temp,0));
        for(int i=1;i<size;i++){
            temp=words[i];
            sort(temp.begin(),temp.end());
            if(dq.front().first!=temp) dq.push_front(make_pair(temp,i));
        }

        vector<string>ans;
        while(!dq.empty()){
            auto temp=dq.back();dq.pop_back();
            ans.push_back(words[temp.second]);
        }
        return ans;
    }
};