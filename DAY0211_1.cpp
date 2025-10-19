// 1625. Lexicographically Smallest String After Applying Operations
class Solution {
private:
    set<string>set;
    int a , b;
    string rotate(string s,int &b){
        return s.substr(s.size()-b)+s.substr(0,s.size()-b);
    }
    string add(string s,int &a){
        for(int i=1;i<s.size();i+=2){
            s[i]='0'+(s[i]-'0'+a)%10;
        }
        return s;
    }
    void bfs(string s,int &a,int &b){
        if(set.find(s)!=set.end()) return ;
        set.insert(s);
        bfs(add(s,a),a,b);
        bfs(rotate(s,b),a,b);
    }
public:
    string findLexSmallestString(string s, int a, int b) {
        //recursive
        // bfs(s,a,b);
        // return *set.begin();

        // iterative
        unordered_set<string>visited;
        queue<string>q;
        string res=s;
        visited.insert(s);
        q.push(s);
        while(!q.empty()){
            string curr=q.front();q.pop();
            res=min(curr,res);
            string added=curr;
            for(int i=1;i<curr.size();i+=2){
                added[i]='0'+(added[i]-'0'+a)%10;
            }
            if(!visited.count(added)){
                q.push(added);
                visited.insert(added);
            }
            string rotated=curr.substr(curr.size()-b)+curr.substr(0,curr.size()-b);
            if(!visited.count(rotated)){
                q.push(rotated);
                visited.insert(rotated);
            }
        }
        return res;
    }
};