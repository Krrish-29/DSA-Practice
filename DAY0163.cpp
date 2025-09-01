// 1792. Maximum Average Pass Ratio
// try again concept is good but implementation is hard
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double answer=0;
        priority_queue<tuple<double,int,int>>maxheap;
        int size=classes.size();
        for(int i=0;i<size;i++) maxheap.emplace(((((double)(classes[i][0]+1)/(classes[i][1]+1))-((double)(classes[i][0])/(classes[i][1])))),classes[i][0],classes[i][1]);
        while(--extraStudents>=0){
            auto [a,b,c]=maxheap.top();
            maxheap.pop();
            b++;
            c++;
            maxheap.emplace(((double)(b+1)/(c+1))-((double)b/c),b,c);
        }
        while(!maxheap.empty()){
            auto [a,b,c]=maxheap.top();
            answer+=((double)b/c);
            maxheap.pop();
        }
        return answer/size;
    }
};