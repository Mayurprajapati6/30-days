class Solution {
public:
    int binarySearch(long long target, const vector<int>& potions) {
        int m = potions.size();
        int l = 0, r = m - 1;
        int result = m; // assume none meet the target

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (potions[mid] >= target) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return m - result; // count of successful potions
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size();
        vector<int> ans(n);

        for (int i = 0; i < n; ++i) {
            long long spell = spells[i];
            long long target = (success + spell - 1) / spell; // integer ceiling division
            if (target > potions.back()) ans[i] = 0;
            else ans[i] = binarySearch(target, potions);
        }

        return ans;
    }
};
