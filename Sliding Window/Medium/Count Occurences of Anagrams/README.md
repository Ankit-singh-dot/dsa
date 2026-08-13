# Count Occurences of Anagrams

| Field | Value |
|-------|-------|
| **Platform** | GeeksForGeeks |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | August 13, 2026 |
| **Link** | [View Problem](https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1) |

## Approach

 if (mp.find(txt[j]) != mp.end()) {

                if (mp[txt[j]] > 0) {
                    count--;
                }

                mp[txt[j]]--;
            }


 if (mp.find(txt[i]) != mp.end()) {

                    mp[txt[i]]++;

                    if (mp[txt[i]] > 0) {
                        count++;
                    }
                }
