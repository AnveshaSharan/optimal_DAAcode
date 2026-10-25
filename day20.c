/* Q20: Longest substring without repeating characters
   Time: O(n), Auxiliary space: O(1) for a fixed 256-byte character set.
*/
#include <stdio.h>

int longestUniqueSubstring(const char *s) {
    int lastSeen[256];
    for (int i = 0; i < 256; i++) lastSeen[i] = -1;

    int left = 0, maxLength = 0;
    for (int right = 0; s[right] != '\\0'; right++) {
        unsigned char ch = (unsigned char)s[right];
        if (lastSeen[ch] >= left) left = lastSeen[ch] + 1;
        lastSeen[ch] = right;

        int length = right - left + 1;
        if (length > maxLength) maxLength = length;
    }
    return maxLength;
}

int main(void) {
    const char *s = "abcabcbb";
    printf("String: %s\\n", s);
    printf("Longest substring length: %d\\n", longestUniqueSubstring(s));
    return 0;
}
