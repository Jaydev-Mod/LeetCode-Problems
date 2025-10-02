class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int bottlesDrunk = numBottles;
        int emptyBottles = numBottles;
        
        while (emptyBottles >= numExchange) {
            emptyBottles -= numExchange;
            bottlesDrunk++;
            emptyBottles++;
            numExchange++;
        }
        return bottlesDrunk;
    }
};