class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int answer = 0;

        for (int left = 0; left < n; ++left) {
            long long product = 1;
            long long currentLcm = 1;
            int currentGcd = 0;

            for (int right = left; right < n; ++right) {
                int x = nums[right];

                currentGcd = gcd(currentGcd, x);
                currentLcm = currentLcm / gcd(currentLcm, (long long)x) * x;

                // The product only grows, so once it exceeds this target,
                // this subarray and all its extensions cannot be valid.
                long long target = currentGcd * currentLcm;
                if (product > target / x) {
                    break;
                }
                product *= x;

                if (product == target) {
                    answer = max(answer, right - left + 1);
                }
            }
        }

        return answer;
    }
};