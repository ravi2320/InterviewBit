/*
Substring Concatenation
Programming
Hashing
Hard
48.0% Success

180

12

Bookmark
Asked In:
You are given a string, S, and a list of words, L, that are all of the same length.

Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

Example :

S: "barfoothefoobarman"
L: ["foo", "bar"]
You should return the indices: [0,9].

(order does not matter).
*/

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    unordered_map<string, int> mp;
    vector<int> ans;
    int m = B[0].size();
    int n = B.size() * m;
    
    for (string word : B)
        mp[word]++;
    
    if (n > A.size())
        return ans;

    for (int i = 0; i < m; i++) {
        unordered_map<string, int> mp2;
        int left = i;
        for (int j = left; j <= A.size() - m; j += m) {
            string temp = A.substr(j, m);
            if (mp.find(temp) != mp.end()) {
                mp2[temp]++;
                
                while (mp[temp] < mp2[temp]) {
                    mp2[A.substr(left, m)]--;
                    left += m;
                }            
                
                if (j - left + m == n) {
                    ans.push_back(left);
                    mp2[A.substr(left, m)]--;
                    left += m;
                }
            } else {
                mp2.clear();
                left = j + m;
            }
        }
    }
    return ans;
}
