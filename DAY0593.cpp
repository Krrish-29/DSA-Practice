// 1385. Find the Distance Value Between Two Arrays
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int distance = 0;
        bool check = true;
        for(int &n1:arr1){
            check = true;
            for(int &n2:arr2){
                if(abs(n1-n2) <= d) {
                    check = false;
                    break;
                }
            }
            if(check) distance++;
        }
        return distance;
    }
};