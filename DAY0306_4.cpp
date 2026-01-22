// 1870. Minimum Speed to Arrive on Time
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left=1,right=1e7,mid,size=dist.size();
        if(size-1>=hour) return -1;
        while(left<right){
            mid=left+(right-left)/2;
            double time=0;
            for(int i=0;i<size-1;i++){
                time+=(ceil((double)dist[i]/mid));
            }
            time+=(double)dist[size-1]/mid;
            if(time>hour) left=mid+1;
            else right=mid;
        }
        return left;

    }
};