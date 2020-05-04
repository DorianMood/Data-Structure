#include <iostream>
#include <fstream>
#include <string>
#include <stack>

bool correctNestedPlaced(std::string);

#define helperOpen(c) c == '(' || c == '{' || c == '['
#define helperClose(c) c == ')' || c == '}' || c == ']'
#define closeOpen(c) c == ')' ? '(' : (c == '}' ? '{' : '[')

int main()
{
    /**
    Give a string (less than 100 characters),
    which may contains (), [], {} three type of brackets.
    Output ¡°TRUE¡± if these brackets are properly nested and placed.
    Otherwise output ¡°FALSE¡±
    */
    std::ifstream fs("input.txt", std::fstream::in);
    std::string line;

    while (std::getline(fs, line))
    {
        std::cout << (correctNestedPlaced(line) ? "TRUE" : "FALSE") << std::endl;
    }
}

bool correctNestedPlaced(std::string s)
{
    std::stack<char> st;

    for (std::string::iterator c = s.begin(); c != s.end(); c++)
    {
        if (helperOpen(*c))
        {
            st.push(*c);
        }
        else if (helperClose(*c))
        {
            if ((st.size() > 0) && (closeOpen(*c) == st.top()))
                st.pop();
            else
                return false;
        }
    }

    return true;
}
