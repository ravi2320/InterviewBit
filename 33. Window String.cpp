/*
Window String
Programming
Hashing
Medium
31.4% Success

234

18

Bookmark
Asked In:
Problem Description
 
 

Given a string A and a string B, find the window with minimum length in A, which will contain all the characters in B in linear time complexity.
 Note that when the count of a character c in B is x, then the count of c in the minimum window in A should be at least x.

Note:

If there is no such window in A that covers all characters in B, return the empty string.
If there are multiple such windows, return the first occurring minimum window ( with minimum start index and length )
 



Problem Constraints
1 <= size(A), size(B) <= 106



Input Format
The first argument is a string A.
The second argument is a string B.



Output Format
Return a string denoting the minimum window.



Example Input
Input 1:

 A = "ADOBECODEBANC"
 B = "ABC"
Input 2:

 A = "Aa91b"
 B = "ab"
 



Example Output
Output 1:

 "BANC"
Output 2:

 "a91b"


Example Explanation
Explanation 1:

 "BANC" is a substring of A which contains all characters of B.
Explanation 2:

 "a91b" is the substring of A which contains all characters of B.
*/

string Solution::minWindow(string A, string B) {
    int windowStart = 0, windowEnd = 0;
    unordered_map<int, int> mp;
    int minLen = INT_MAX;
    int minStart = 0;
    int charCount = B.size();
    
    for(char c : B)
        mp[c]++;
        
    while(windowEnd < A.size()){
        
        if(mp.find(A[windowEnd]) != mp.end()){
            if(mp[A[windowEnd]] > 0)
                charCount--;
            mp[A[windowEnd]]--;
        }
        
        while(charCount == 0){
            if(windowEnd - windowStart + 1 < minLen){
                minLen = windowEnd - windowStart + 1;
                minStart = windowStart;
            }
            
            if(mp.find(A[windowStart]) != mp.end()){
                mp[A[windowStart]]++;
                if(mp[A[windowStart]] > 0)
                    charCount++;
            }
            windowStart++;
        }
        windowEnd++;
    }
    return minLen == INT_MAX ? "":A.substr(minStart, minLen);
}
