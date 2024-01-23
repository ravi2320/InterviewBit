/*
Atoi
Programming
Strings
Medium
19.2% Success

133

266

Bookmark
Asked In:
There are certain questions where the interviewer would intentionally frame the question vague.

The expectation is that you will ask the correct set of clarifications or state your assumptions before you jump into coding.

Implement atoi to convert a string to an integer.

Example :

Input : "9 2704"
Output : 9
*/

int Solution::atoi(const string A) {
    int ans = 0;
    int n = A.size();
    int i = 0;

    // Skip leading whitespaces
    while (i < n && A[i] == ' ') {
        i++;
    }

    int sign = 1;
    if (i < n && (A[i] == '-' || A[i] == '+')) {
        sign = (A[i] == '-') ? -1 : 1;
        i++;
    }

    while (i < n && isdigit(A[i])) {
        int digit = A[i] - '0';

        // Check for integer overflow
        if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > INT_MAX % 10)) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        ans = ans * 10 + digit;
        i++;
    }

    return ans * sign;
}
