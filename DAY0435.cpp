// 2126. Destroying Asteroids
class Solution {
public:
    bool asteroidsDestroyed(long long mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        for(auto &a:asteroids){
            if(mass>=a) mass+=a;
            else return false;
        }
        return true;
    }
};