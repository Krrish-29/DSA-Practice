// 1394. Find Lucky Integer in an Array
class Solution {
public:
    int findLucky(vector<int>& arr) {
        // int answer=-1;
        // vector<int>hashmap(500,0);
        // int size=arr.size();
        // for(int i=0;i<size;i++){
        //     hashmap[arr[i]-1]++;
        // }
        // for(int i=0;i<500;i++){
        //     if(i+1==hashmap[i]){
        //         answer=i+1;
        //     } 
        // }
        // return answer;
        sort(arr.begin(),arr.end());
        arr.push_back(0);
        int size=arr.size(),count=1,answer=-1;
        for(int i=1;i<size;i++){
            if(arr[i]==arr[i-1]){
                count++;
            }
            else{
                if(arr[i-1]==count) answer=arr[i-1];
                count=1;
            }
        }
        return answer;
    }   
};