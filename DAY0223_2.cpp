// 735. Asteroid Collision
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int i=1,j=1;
        int size=asteroids.size();
        for(j=1;j<size;j++){
            bool flag=false;
            while(i>0&&asteroids[j]<0&&asteroids[i-1]>0){
                if(abs(asteroids[j])<asteroids[i-1]){
                    flag=true;
                    break;
                }
                else if(abs(asteroids[j])==asteroids[i-1]){
                    i--;
                    flag=true;
                    break;
                }
                else{
                    i--;
                }
            }
            if(!flag){
                asteroids[i]=asteroids[j];
                i++;
            }
        }
        asteroids.erase(asteroids.begin()+i,asteroids.end());
        return asteroids;
    }
};