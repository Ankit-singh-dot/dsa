# First Negative in Windows of Size K

| Field | Value |
|-------|-------|
| **Platform** | GeeksForGeeks |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | August 13, 2026 |
| **Link** | [View Problem](https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1) |

## Approach

list me negative number ko store karo then , usko remove karo last me 
 else {ans.push_back(negative_nums.front());
                 if (arr[i] == negative_nums.front()){
                    negative_nums.pop_front();
                }
                }
                i++;
                j++;
