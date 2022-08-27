// Section 20
// Challenge 4
// Identifying palindrome strings using a stack and queue
#include <cctype>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <iomanip>

bool is_palindrome(const std::string& s)
{
    // You must implement this function.
    // Since we are learning the STL - use a stack and a queue to solve the problem.
    //s.toupper();
    std::queue<char> q;
    std::stack<char> st;
    for (const auto &c: s) {
        if(std::isalpha(c)) {
            q.push(toupper(c));
            st.push(toupper(c));
        }
    }
    
    char c1 {};
    char c2 {};
    
    while(!q.empty()) {
        c1 = q.front();
        c2 = st.top();
        q.pop();
        st.pop();
        if (c1 != c2)
            return false;
    }
    return true;
    
//    for (const auto &c: s) {
//        if(std::isalpha(c))
//            st.push(toupper(c));
//    }
        
//    std::string word {};
//    while (!q.empty()) {
//    word += q.front();
//    q.pop();
//    }
    //std::cout << word;
        
//    std::string word_reverse {};
//    while (!st.empty()) {
//    word_reverse += st.top();
//    st.pop();
//    }
    //std::cout << word_reverse;
    
//    if (word == word_reverse) 
//        return true;
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
   
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}