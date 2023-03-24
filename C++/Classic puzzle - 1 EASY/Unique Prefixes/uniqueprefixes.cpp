#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string charIsHere(string s1, string s2)
{
    int i = 0;
    while(s1[i] == s2[i])
        i++;
    if(i > 0)
        return s1.substr(0, i + 1);
    else
        return s1.substr(0, 1);
}

int main()
{
    vector<string> v;
    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word; cin.ignore();
        v.push_back(word);    
    }

    for(int i = 0; i < v.size(); i++)
    {
        string temp = "";
        for(int j = 0; j < v.size(); j++)
        {
            if(v[i] != v[j])
            {
                string s = charIsHere(v[i], v[j]);
                if(temp.size() <= s.size())
                    temp = s;
            }
        }
        v[i] = temp;
    }

    for(string s : v)
        cout << s << '\n';
}