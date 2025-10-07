class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1); // default dry any lake
        unordered_map<int, int> full; // lake -> last rain day
        set<int> dryDays; // indices of zeros

        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                dryDays.insert(i);
            } else {
                int lake = rains[i];
                if (full.count(lake)) {
                    // find dry day after last rain day
                    auto it = dryDays.lower_bound(full[lake]);
                    if (it == dryDays.end()) return {}; // no dry day → flood
                    ans[*it] = lake; // dry this lake
                    dryDays.erase(it);
                }
                full[lake] = i;
                ans[i] = -1; // raining day
            }
        }

        return ans;
    }
};
