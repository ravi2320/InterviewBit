/*
Longest valid Parentheses
Programming
Dynamic Programming
Medium
44.0% Success

Asked In: Google

Given a string A containing just the characters ’(‘ and ’)’.

Find the length of the longest valid (well-formed) parentheses substring.


Input Format:

The only argument given is string A.
Output Format:

Return the length of the longest valid (well-formed) parentheses substring.
Constraints:

1 <= length(A) <= 750000
For Example

Input 1:
    A = "(()"
Output 1:
    2
    Explanation 1:
        The longest valid parentheses substring is "()", which has length = 2.

Input 2:
    A = ")()())"
Output 2:
    4
    Explanation 2:
        The longest valid parentheses substring is "()()", which has length = 4.
*/
//Time Complexity-O(n) space Complexity-O(n)
int Solution::longestValidParentheses(string A) {
    stack<int> st;
    st.push(-1);
    int cnt = 0;
    for(int i=0; i<A.size(); i++){
        if(A[i] == '(')
            st.push(i);
        else
        {
            st.pop();
            if(st.empty()){
                st.push(i);
            }
            else{
                cnt = max(cnt, i-st.top());
            }
        }
    }
    return cnt;
}

//Time Complexity-O(n) space Complexity-O(1)
int Solution::longestValidParentheses(string A) {
    
    int cnt = 0, open = 0, close = 0;
    for(char ch : A){
        if(ch == '(')
            open++;
        else
            close++;
            
        if(open == close)
            cnt = max(cnt, open+close);
        else if(close > open)
            open = close = 0;
    }
    open = 0;
    close = 0;
    for(int i=A.size()-1; i>=0; i--){
        if(A[i] == '(')
            open++;
        else
            close++;
            
        if(open == close)
            cnt = max(cnt, open+close);
        else if(close < open)
            open = close = 0;
    }
    return cnt;
}
