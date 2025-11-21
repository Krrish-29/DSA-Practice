// 1930. Unique Length-3 Palindromic Subsequences
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        //Approach 1: for every unique element u have find its last pos and traverse in between that
        // unordered_set<string>str;
        // unordered_set<char>seen;
        // int size=s.size();
        // for(int j=0;j<size;j++){
        //     if(seen.find(s[j])!=seen.end()) continue;
        //     for(int i=size-1;i>j;i--){
        //         if(s[i]==s[j]){
        //             for(int x=j+1;x<i;x++){
        //                 str.insert(string(1,s[j])+s[x]+string(1,s[j]));
        //             }
        //             break;
        //         } 
        //     }
        //     seen.insert(s[j]);
        // }
        // return str.size();

        //Approach 2: For every char find its first and last pos and check in between
        // unordered_set<string>str;
        // int size=s.size();
        // for(char ch='a';ch<='z';ch++){
        //     int first=-1,last=-1;
        //     for(int i=0;i<size;i++){
        //         if(ch==s[i]){
        //             if(first==-1) first=i;
        //             last=i;
        //         }
        //     }
        //     if(first!=-1&&last!=-1&&first<last){
        //         for(int i=first+1;i<last;i++){
        //             str.insert(string(1,ch)+s[i]+string(1,ch));
        //         }
        //     }
        // }
        // return str.size();

        //Approach 3:Traverse only once and find every pos of each ele and traverse in between for ele having both first and last pos filled
        int size=s.size();
        vector<pair<int,int>>pos(26,{-1,-1});
        for(int i=0;i<size;i++){
            if(pos[s[i]-'a'].first==-1) pos[s[i]-'a'].first=i;
            else pos[s[i]-'a'].second=i;
        }
        int count=0;
        for(int i=0;i<26;i++){
            if(pos[i].second==-1) continue;
            unordered_set<char>temp;
            for(int x=pos[i].first+1;x<pos[i].second;x++){
                temp.insert(s[x]);
            }
            count+=temp.size();
        }
        return count;
    }
};