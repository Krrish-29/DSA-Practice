// 149. Max Points on a Line
class Solution {
struct pair_hash {
    std::size_t operator()(const std::pair<int, int>& p) const {
        return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
    }
};
    int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int size=points.size();
        if(size<3) return size;
        int maxVal=INT_MIN;
        int x,y;
        for(int i=0;i<size;i++){
            unordered_map<pair<int,int>,int,pair_hash>map;
            for(int j=i+1;j<size;j++){
                x=points[j][1]-points[i][1];
                y=points[j][0]-points[i][0];
                int c=gcd(x,y);
                if(c!=0){ x/=c ; y/=c ; }
                if(x<0) { x=-x ; y=-y ; }
                map[{x,y}]++;
                maxVal=max(maxVal,map[{x,y}]);
            }
        }
        return maxVal+1;
    }
};