class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low < high) {
            int capacity = low + (high - low) / 2;
            int usedDays = 1;
            int load = 0;

            for (int weight : weights) {
                if (load + weight > capacity) {
                    ++usedDays;
                    load = 0;
                }
                load += weight;
            }

            if (usedDays <= days) {
                high = capacity;
            } else {
                low = capacity + 1;
            }
        }

        return low;
    }
};