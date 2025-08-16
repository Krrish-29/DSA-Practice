// 1323. Maximum 69 Number
class Solution {
public:
    int maximum69Number (int num) {
        string number=to_string(num); 
        num=0;
        bool flag=false;
        for(char & nums:number){
            if(nums=='6'&&!flag) {
                nums='9';
                flag=true;
            }
            printf("%d ",num);
            num=(num*10+(int)nums-'0');
        }   
        return num;
    }
};