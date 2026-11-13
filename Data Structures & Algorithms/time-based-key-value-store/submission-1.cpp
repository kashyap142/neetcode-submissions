class TimeMap {
    using psi = pair<string, int>;

   private:
    unordered_map<string, vector<psi>> mp;

   public:
    TimeMap() { mp.clear(); }

    void set(string key, string value, int timestamp) {
        mp[key].push_back(make_pair(value, timestamp));
    }

    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) {
            return "";
        }

        const auto& temp = mp[key];

        int l = 0, r = temp.size() - 1;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (temp[mid].second == timestamp) {
                return temp[mid].first;
            } else if (temp[mid].second > timestamp) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if(r < 0)
            return "";

        return temp[r].first;
    }
};
