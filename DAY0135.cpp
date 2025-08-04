// 904. Fruit Into Baskets
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int size=fruits.size(),total=0,max_fruits=0,count;
        set<int>hashtable;
        for(int i=0;i<size;i++){
            if(hashtable.find(fruits[i])==hashtable.end()){
                if(hashtable.size()==2){
                    hashtable.clear();
                    hashtable.insert(fruits[i-1]);
                    total=0;
                    total+=count;
                }
                hashtable.insert(fruits[i]);
            }
            if(hashtable.find(fruits[i])!=hashtable.end()){
                count=1;
                while(i+1<size&&fruits[i]==fruits[i+1]){
                    i++;
                    count++;
                }
                total+=count;
            }
            max_fruits=max(max_fruits,total);
        }
        return max_fruits;
        
    }
};