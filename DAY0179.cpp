// 2353. Design a Food Rating System
class FoodRatings {
private:
    unordered_map<string,pair<int,string>>foodInfo; //food -> rating cuisine
    unordered_map<string,set<pair<int,string>>>topFood; //cuisine -> sorted food
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
       for(int i=0;i<foods.size();i++){
            foodInfo[foods[i]]={ratings[i],cuisines[i]};
            topFood[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [oldRating,cuisine]=foodInfo[food];
        topFood[cuisine].erase({-oldRating,food});
        topFood[cuisine].insert({-newRating,food});
        foodInfo[food].first=newRating;
    }
    
    string highestRated(string cuisine) {
        return topFood[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */