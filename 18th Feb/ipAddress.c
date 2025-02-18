// A valid IPv4 address consists of four decimal numbers (0-255) separated by dots (.).
// A valid IPv6 address consists of eight groups of hexadecimal numbers (0-FFFF) separated by colons (:).
// If the given string does not match either format, return "Neither".
// Input
// A single string representing the IP address.
// Output
// Return one of the following:
// "IPv4" if the input is a valid IPv4 address.
// "IPv6" if the input is a valid IPv6 address.
// "Neither" if it is neither a valid IPv4 nor IPv6 address.

// Example Cases

// Example 1:

// Input: "192.168.1.1"  

// Output: "IPv4"

// (Valid IPv4 address with four octets in the range [0,255].)
 
// Example 2:

// Input: "2001:0db8:85a3:0000:0000:8a2e:0370:7334"  

// Output: "IPv6"

// (Valid IPv6 address with eight hexadecimal groups.)
 
// Example 3:

// Input: "256.256.256.256"  

// Output: "Neither"

// (Invalid IPv4 address because values exceed 255.)
 
// Example 4:

// Input: "1.1.1"  

// Output: "Neither"

// (Invalid IPv4 address because it has only three octets instead of four.)
 
// Example 5:

// Input: "2001:db8::85a3::8a2e:370:7334"  

// Output: "Neither"

// (Invalid IPv6 address because it contains two consecutive ::.)
 
// Constraints
// The input string consists only of printable ASCII characters.
// The input does not contain leading or trailing spaces.

#include <stdio.h>
#include <stdlib.h>

int validIPv4(char* inputString) 
{
    int dots = 0;
    int iteratorI = 0;
    int number = 0;

    while (*(inputString + iteratorI) != '\0') 
    {
        if (*(inputString + iteratorI) == '.') 
        {
            if (number > 255) 
            {
                return 0;
            }
            dots++;
            number = 0;
        } 
        else if (*(inputString + iteratorI) >= '0' && *(inputString + iteratorI) <= '9') 
        {
            number = number * 10 + (*(inputString + iteratorI) - '0');
        } 
        else 
        {
            return 0;
        }
        iteratorI++;
    }
    return dots == 3 && number <= 255;
}

int validIPv6(char* inputString) 
{
    int groups = 0;
    int iteratorI = 0;
    int groupValue = 0;

    while (*(inputString + iteratorI) != '\0') 
    {
        if (*(inputString + iteratorI) == ':') 
        {
            if (groupValue == 0 || groupValue > 4) 
            {
                return 0; 
            }
            groups++;
            groupValue = 0;
        } 
        else if ((*(inputString + iteratorI) >= '0' && *(inputString + iteratorI) <= '9') || 
                   (*(inputString + iteratorI) >= 'a' && *(inputString + iteratorI) <= 'f') ||
                   (*(inputString + iteratorI) >= 'A' && *(inputString + iteratorI) <= 'F')) 
        {
            groupValue++;
        } 
        else 
        {
            return 0; 
        }
        iteratorI++;
    }

    if (groupValue == 0 || groupValue > 4) 
    {
        return 0;
    }

    groups++;

    return groups == 8;
}

int main() 
{
    char* inputString = (char*)malloc(200 * sizeof(char));
    printf("Enter IP Address: \n");
    scanf("%s", inputString);

    if (validIPv4(inputString)) 
    {
        printf("IPv4\n");
    } 
    else if (validIPv6(inputString))
    {
        printf("IPv6\n");
    }
    else 
    {
        printf("Neither\n");
    }

    free(inputString);
    return 0;
}
