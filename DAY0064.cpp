// 2131. Longest Palindrome by Concatenating Two Letter Words
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        //memory optimization
        // ios::sync_with_stdio(0);
        // cin.tie(0);
        vector<vector<int>>hashmap(26,vector<int>(26,0));
        int answer=0;
        int size=words.size();
        for(int i=0;i<size;i++){
            if(hashmap[words[i][1]-'a'][words[i][0]-'a']>0){
                answer+=4;
                hashmap[words[i][1]-'a'][words[i][0]-'a']--;
            }
            else{
                hashmap[words[i][0]-'a'][words[i][1]-'a']++;
            }
        }
        for(int i=0;i<26;i++){
            if(hashmap[i][i]>0){
                answer+=2;
                break;
            }
        }
        // vector<vector<int>>().swap(hashmap);
        return answer;
    }
};