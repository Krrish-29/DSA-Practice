// 2785. Sort Vowels in a String
class Solution {
public:
    string sortVowels(string s) {
        int size=s.size();
        vector<char>t;
        queue<int>queue;
        string vowels="AEIOUaeiou";
        for(int i=0;i<size;i++){
            if(vowels.find(s[i])!=string::npos){
                t.push_back(s[i]);
                queue.push(i);
            }
        }
        sort(t.begin(),t.end());
        for(int i=0;!queue.empty();i++){
            s[queue.front()]=t[i];
            queue.pop();
        }
        return s;
    }
};