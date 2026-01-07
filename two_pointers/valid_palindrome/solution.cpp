// Two pointers over a filtered string (skip non-alnum), compare case-insensitively.
// Time: O(n), Space: O(n)
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isAlphanumeric(char c) {
        return isalpha(c) || (c >= '0' && c <= '9');
    }
    bool isPalindrome(string s) {
        string filtered;

        for (char c : s) {
            if (isAlphanumeric(c)) filtered += c;
        }

        int left = 0, right = filtered.size() - 1;


        while (left < right) {

            if (tolower(filtered[left++]) != tolower(filtered[right--])) return false;
        }

        return true;
    }
};
