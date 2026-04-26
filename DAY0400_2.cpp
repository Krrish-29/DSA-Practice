// 3913. Sort Vowels by Frequency
class Solution {
public:
    string sortVowels(string s) {
        // freq, character (will be used later for reassining) , idx (very imp cause if frq is same then we need to check the first occurence )
        vector<pair<int,pair<char,vector<int>>>>vec(5);
        vector<int>idx;
        int size=s.size();
        for(int i=0;i<size;i++){
            if(s[i]=='a') {
                idx.push_back(i);
                vec[0].first++;
                vec[0].second.first='a';
                vec[0].second.second.push_back(i);
            }
            if(s[i]=='e') {
                idx.push_back(i);
                vec[1].first++;
                vec[1].second.first='e';
                vec[1].second.second.push_back(i);
            }
            if(s[i]=='i') {
                idx.push_back(i);
                vec[2].first++;
                vec[2].second.first='i';
                vec[2].second.second.push_back(i);
            }
            if(s[i]=='o') {
                idx.push_back(i);
                vec[3].first++;
                vec[3].second.first='o';
                vec[3].second.second.push_back(i);
            }
            if(s[i]=='u') {
                idx.push_back(i);
                vec[4].first++;
                vec[4].second.first='u';
                vec[4].second.second.push_back(i);
            }
        }
        sort(vec.begin(),vec.end(),[](const pair<int,pair<char,vector<int>>> & a,const pair<int,pair<char,vector<int>>>& b){
            if(a.first==b.first&&a.first!=0){
                return a.second.second[0]<b.second.second[0];
            }
            return a.first>b.first;
        });
        int idxE=0;
        for(int i=0;i<5;i++){
            // printf("%d :",vec[i].first);
            for(int j=0;j<vec[i].first;j++){
                // printf("%d ",vec[i].second[j]);
                s[idx[idxE]]=vec[i].second.first;
                idxE++;
            }
            // printf("\n");
        }
        return s;
    }
};