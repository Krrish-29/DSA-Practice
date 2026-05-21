// 3043. Find the Length of the Longest Common Prefix
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        // rather than making a 1 to 1 maping in the arrays
        // what we need to do is map prefix of each element in any one array 
        // and if a prefix of elem of sec array is seen in the map we can count it
        // at last move over all the prefix values that have been found in array 2 as well
        // an store the max elem and return its len else return 0
        unordered_map<int,int>map;
        int maxEle=0;
        for(int &num:arr1){
            string str=to_string(num);
            int number=0;
            for(int i=0;i<str.size();i++){
                number=number*10+(str[i]-'0');
                map[number]=0;
            }
        }
        for(int &num:arr2){
            string str=to_string(num);
            int number=0;
            for(int i=0;i<str.size();i++){
                number=number*10+(str[i]-'0');
                if(map.count(number)) map[number]=1;
            }
        }
        for(auto it=map.begin();it!=map.end();++it){
            if(it->second==1) {
                maxEle=max(maxEle,it->first);
            }
        }
        return maxEle==0?0:to_string(maxEle).size();
    }
};