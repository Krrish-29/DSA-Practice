// 3027. Find the Number of Ways to Place People II
struct Comparator{
    bool operator()(const vector<int>&a,const vector<int>&b) const 
    {
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
};
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int size=points.size(),pairs=0;
        sort(points.begin(),points.end(),Comparator());
        for(int i=0;i<size;i++){
            int lower_right=INT_MIN;
            for(int j=i+1;j<size;j++){
                // consider a lower limit and pairs will be only be able to form 
                // in bewteen that lower limit and the current point y coords and 
                // everytime we get a y coords more than current we skip it and 
                // if that y coord is less than current y coord we check that 
                // can we take it or does it lie within safe limit that 
                // no other point would interfere with it and everytime we get 
                // the limit closer to the current y coord we update it if the pair is correct.
                if(points[j][1]<=points[i][1]&&lower_right<points[j][1]){
                    lower_right=points[j][1];
                    pairs++;
                }
            }
        }
        return pairs;
    }
};