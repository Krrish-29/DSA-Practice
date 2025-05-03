// 1007. Minimum Domino Rotations For Equal Row
class Solution {
    public:
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
            vector<int>hash_top(7,0);
            vector<int>hash_bottom(7,0);
            vector<int>hash_similar(7,0);
            int size=tops.size();
            for(int i=0;i<size;i++){
                hash_top[tops[i]]++;
                hash_bottom[bottoms[i]]++;
                if(tops[i]==bottoms[i]) hash_similar[tops[i]]++;
            }
            vector<int>().swap(tops);
            vector<int>().swap(bottoms);
            for(int i=0;i<=6;i++){
                if(hash_top[i]+hash_bottom[i]-hash_similar[i]==size){
                    int x=hash_top[i],y=hash_bottom[i];
                    vector<int>().swap(hash_top);
                    vector<int>().swap(hash_bottom);
                    vector<int>().swap(hash_similar);
                    return size-max(x,y);
                }
            }
            return -1;
        }
    };

    // class Solution {
    //     public:
    //         int check(vector<int>tops,vector<int>bottoms,int x){
    //             int top=0,bottom=0;
    //             for(int i=0;i<tops.size();i++){
    //                 if(tops[i]!=x&&bottoms[i]!=x) {
    //                     return INT_MAX;
    //                 }
    //                 else if(tops[i]!=x){
    //                     top++;
    //                 }
    //                 else if(bottoms[i]!=x){
    //                     bottom++;
    //                 }
    //             }
    //             return min(top,bottom);
    //         }
    //         int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    //             int answer=min(check(tops,bottoms,tops[0]),check(tops,bottoms,bottoms[0]));
    //             if(answer>=INT_MAX) return -1;
    //             else return answer;
    //         }
    //     };