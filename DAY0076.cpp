// 2434. Using a Robot to Print the Lexicographically Smallest String
class Solution {
public:
    string robotWithString(string s) {
        vector<int>hashmap(26,0);
        int size=s.length();
        for(int i=0;i<size;i++){
            hashmap[s[i]-'a']++;
        }
        string answer;
        stack<char> t;
        char small='a';
        for(char c:s){
            hashmap[c - 'a']--;  
            while (small <= 'z' && hashmap[small - 'a'] == 0) {
                small++; 
            }   
            t.push(c);
            while (!t.empty() && t.top() <= small) {
                answer += t.top();
                t.pop();
            }
        }
        while (!t.empty()) {
            answer += t.top();
            t.pop();
        }
        return answer;
    }
};