/*Question 18
Given a string s, find the length of the longest substring without duplicate characters.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int last[256];
    int start = 0;
    int maxLength = 0;

    printf("Enter string: ");
    scanf("%s", s);

    // Initialize all positions to -1
    for (int i = 0; i < 256; i++)
    {
        last[i] = -1;
    }

    for (int i = 0; s[i] != '\0'; i++)
    {
        // If character already exists in current substring
        if (last[(unsigned char)s[i]] >= start)
        {
            start = last[(unsigned char)s[i]] + 1;
        }

        // Store latest position of character
        last[(unsigned char)s[i]] = i;

        // Calculate current substring length
        int currentLength = i - start + 1;

        // Update maximum length
        if (currentLength > maxLength)
        {
            maxLength = currentLength;
        }
    }

    printf("Length of longest substring = %d\n", maxLength);

    return 0;
}