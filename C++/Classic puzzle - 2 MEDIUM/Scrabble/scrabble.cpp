#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char>> lettersPoints { {'e', 'a', 'i', 'o', 'n', 'r', 't', 'l', 's', 'u'},
                                {'d', 'g'},
                                {'b', 'c', 'm', 'p'},
                                {'f', 'h', 'v', 'w', 'y'},
                                {'k'},
                                {'j', 'x'},
                                {'q', 'z'}};

bool isValid(char s, const string& l)
{
    if(find(l.begin(), l.end(), s) != l.end())
        return true;
    return false;
}

bool isTwice(const string& s)
{
    vector<char> v;
    for(int i = 0; i < s.size(); i++)
    {
        if(find(v.begin(), v.end(), s[i]) != v.end())
            return true;
        else
            v.push_back(s[i]);
    }
    return false;
}

int points(const string& s, const string& l)
{
    int n = 0;
    vector<char> twice;
    if(s.length() > 7)
        return 0;
    for(int i = 0; i < lettersPoints.size(); i++)
    {
        for(int j = 0; j < s.size(); j++)
        {
            if(isValid(s[j], l) && find(twice.begin(), twice.end(), s[j]) == twice.end())
            {
                if(find(lettersPoints[i].begin(), lettersPoints[i].end(), s[j]) != lettersPoints[i].end())
                { 
                    if( i < 5)
                        n += i + 1;
                    if(i == 5)
                        n += 8;
                    else if(i == 6)
                        n += 10;
                    twice.push_back(s[j]);
                }
            }
            else if(!isValid(s[j], l))
                return -1;
        }
    }
    return n;
}        

int maxWord(vector<string> dictionary, const string& l)
{
    int max = 0, pos = 0;
    for(int i = 0; i < dictionary.size(); i++)
    {
        int p = points(dictionary[i], l);
        if( p > max)
        {
            max = p;
            pos = i;
        }
        if(p == max && dictionary[pos].size() > dictionary[i].size())
        {
            max = p;
            pos = i;
        }
    }
    return pos;
}

int main()
{
    int n;
    cin >> n; cin.ignore();
    vector<string> dictionary;
    for (int i = 0; i < n; i++) {
        string w;
        getline(cin, w);
        dictionary.push_back(w);
    }
    string letters;
    getline(cin, letters);
    cout << dictionary[maxWord(dictionary, letters)] << endl;
}