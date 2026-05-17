// 3923. Minimum Generations to Target Point
class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        unordered_set<int>set1;
        bool existsX=false,existsY=false,existsZ=false;
        for(auto &point:points){
            if(point[0]>=target[0]) existsX=true;
            if(point[1]>=target[1]) existsY=true;
            if(point[2]>=target[2]) existsZ=true;
            set1.insert(point[0]*100+point[1]*10+point[2]);
            if(point==target) return 0;
        }
        if((!existsX)||(!existsY)||(!existsZ)) return -1;
        int k=1,x1,x2,y1,y2,z1,z2,newX,newY,newZ,newPoint,targetPoint=target[0]*100+target[1]*10+target[2];
        while(k<100){
            unordered_set<int>newSet;
            for(auto it1=set1.begin();it1!=set1.end();++it1){
                for(auto it2=next(it1);it2!=set1.end();++it2){
                    x1=(*it1)/100;
                    x2=(*it2)/100;
                    y1=((*it1)/10)%10;
                    y2=((*it2)/10)%10;
                    z1=(*it1)%10;
                    z2=(*it2)%10;
                    newX=(x1+x2)/2;
                    newY=(y1+y2)/2;
                    newZ=(z1+z2)/2;
                    newPoint=newX*100+newY*10+newZ;
                    if(newPoint==targetPoint) return k;
                    if(!set1.count(newPoint)) newSet.insert(newPoint);
                }
            }
            if(newSet.empty()) return -1;
            for(auto & it:newSet) set1.insert(it);
            k++;
        }
        return -1;
    }
};