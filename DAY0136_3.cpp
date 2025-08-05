// 3638. Maximum Balanced Shipments
class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int currMax=0,shipment=0;
        int size=weight.size();
        for(int i=1;i<size;i++){
            if(weight[i]<weight[i-1]){
                shipment++;
                i++;
            }
        }
        return shipment;
    }
};