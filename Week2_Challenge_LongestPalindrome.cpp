#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        int length = 0;
        bool hasOdd = false;

        for (auto &pair : freq) {
            if (pair.second % 2 == 0) {
                length += pair.second;  // Use all even counts
            } else {
                length += pair.second - 1;  // Use the even part of odd counts
                hasOdd = true;  // Mark that we have at least one odd count
            }
        }

        if (hasOdd) {
            length += 1;  // Add one center character if an odd frequency exists
        }

        return length;
    }
};
