#include<iostream>
#include<stack>
using namespace std;

bool isoperator(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/')
    return true;
    else
    return false;
}

bool ishigherPrecedence(char a, char b)
{
    if(a == '*' || a == '/' && b == '+' || b == '-') return true;
    else if(a == '+' && b == '-' || a == '*' && b == '/') return true;
    else return false;
}

string infixtoPostfix(string s)
{
    stack<char> st;
    string res="";
    for(int i=0;i<s.length();i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
            res += s[i];
            
        if(isoperator(s[i]))    
        {
            while(!st.empty() && ishigherPrecedence(st.top(), s[i]))
            {
                res += st.top();
                st.pop();
            }
        st.push(s[i]);
        }
        
    }
    
    while(!st.empty())
    {
        res += st.top();
        st.pop();
    }
    
    return res;
}
int main()
{
    string s;
    cin >> s;
    cout << infixtoPostfix(s);
}