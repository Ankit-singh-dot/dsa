class Solution {
public:
    int search(string &pat, string &txt) {

        int i = 0;
        int j = 0;
        int ans = 0;

        unordered_map<char, int> mp;

        for (char ch : pat) {
            mp[ch]++;
        }

        int count = pat.length();
        int k = pat.length();

        while (j < txt.length()) {

            
            if (mp.find(txt[j]) != mp.end()) {

                if (mp[txt[j]] > 0) {
                    count--;
                }

                mp[txt[j]]--;
            }

            // Window is smaller than k
            if (j - i + 1 < k) {
                j++;
            }

            // Window size == k
            else if (j - i + 1 == k) {

                // All characters matched
                if (count == 0) {
                    ans++;
                }

                // Remove txt[i] from the window
                if (mp.find(txt[i]) != mp.end()) {

                    mp[txt[i]]++;

                    if (mp[txt[i]] > 0) {
                        count++;
                    }
                }

                i++;
                j++;
            }
        }

        return ans;
    }
};