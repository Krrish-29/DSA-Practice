// 3941. Password Strength
class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char>seen;
        int points=0;
        for(char &c:password){
            if(seen.count(c)) continue;
            if(c>='a'&&c<='z') points+=1;
            else if(c>='A'&&c<='Z') points+=2;
            else if(c>='0'&&c<='9') points+=3;
            else points+=5;
            seen.insert(c);
        }
        return points;
    }
};