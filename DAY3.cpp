// 3492. Maximum Containers on a Ship
class Solution {
    public:
        int maxContainers(int n, int w, int maxWeight) {
            return n*n<maxWeight/w?n*n:maxWeight/w;
        }
    };