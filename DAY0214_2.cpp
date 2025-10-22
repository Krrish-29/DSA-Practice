// 3694. Distinct Points Reachable After Substring Removal
class Solution {
private:
    int x,y;
    void getCoords(char &c){
        x=0;y=0;
        if(c=='U') y=1;
        else if(c=='D') y=-1;
        else if(c=='L') x=-1;
        else if(c=='R') x=1;
    }
public:
    int distinctPoints(string s, int k) {
        set<pair<int,int>>visited;
        int size=s.size();
        int netX=0,netY=0;
        for(int i=0;i<k;i++){
            getCoords(s[i]);
            netX+=x;
            netY+=y;
        }
        visited.insert({netX,netY});
        for(int i=1;i<=size-k;i++){
            getCoords(s[i-1]);
            netX-=x;
            netY-=y;
            getCoords(s[i+k-1]);
            netX+=x;
            netY+=y;
            visited.insert({netX,netY});
        }
        return visited.size();
    }
};