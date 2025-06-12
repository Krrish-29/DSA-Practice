// 3000. Maximum Area of Longest Diagonal Rectangle
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxproduct=0,maxdiag=0;
        for(int i=0;i<dimensions.size();i++){
            int currentdiag=dimensions[i][0]*dimensions[i][0]+dimensions[i][1]*dimensions[i][1];
            if(maxdiag<currentdiag){
                maxdiag=currentdiag;
                maxproduct=dimensions[i][0]*dimensions[i][1];
            }
            else if(maxdiag==currentdiag){
                maxproduct=max(maxproduct,dimensions[i][0]*dimensions[i][1]);
            }
        }
        return maxproduct;
    }
};