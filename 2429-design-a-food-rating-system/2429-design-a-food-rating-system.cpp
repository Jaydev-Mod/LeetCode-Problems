class FoodRatings {
public:
    unordered_map<string, pair<int, string>> foodInfo;
    unordered_map<string, set<pair<int, string>>> cuisineRatings;
    unordered_map<string, unordered_map<string, int>> foodInSets;

    FoodRatings(vector<string>& foods, vector<string>& cuisines,
                vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            foodInfo[food] = {rating, cuisine};

            cuisineRatings[cuisine].insert({-rating, food});
        }
    }

    void changeRating(string food, int newRating) {
        if (foodInfo.find(food) == foodInfo.end())
            return;

        auto& info = foodInfo[food];
        int oldRating = info.first;
        string cuisine = info.second;

        auto it = cuisineRatings[cuisine].find({-oldRating, food});
        if (it != cuisineRatings[cuisine].end()) {
            cuisineRatings[cuisine].erase(it);
        }

        info.first = newRating;

        cuisineRatings[cuisine].insert({-newRating, food});
    }

    string highestRated(string cuisine) {
        if (cuisineRatings.find(cuisine) == cuisineRatings.end() ||
            cuisineRatings[cuisine].empty()) {
            return "";
        }

        return cuisineRatings[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */