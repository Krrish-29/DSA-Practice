// 380. Insert Delete GetRandom O(1)
#include <ctime>
#include <cstdlib>
class RandomizedSet {
private:
    unordered_map<int,int>hashmap;
    vector<int>key;
    int size=0;
public:
    RandomizedSet(){}
    
    bool insert(int val) {
        if(hashmap.find(val)!=hashmap.end()){
            return false;
        }
        hashmap[val]=size;
        key.push_back(val);
        size++;
        return true;

    }
    
    bool remove(int val) {
        if(hashmap.find(val)==hashmap.end()){
            return false;
        }
        int i1=hashmap[val],i2=size-1;
        hashmap[key[i2]]=i1;
        swap(key[i1],key[i2]);
        hashmap.erase(val);
        key.pop_back();
        size--;
        return true; 
    }
    
    int getRandom() {
        return key[rand()%size];

    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */