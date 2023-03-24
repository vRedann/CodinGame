#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
    int n, result;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t; cin.ignore();
        if(i == 0)
            result = t;
        else{
            if(abs(t) < abs(result))
                result = t;
            else if(abs(t) == abs(result)){
                if(t <= 0 && result <= 0)
                    result = t;
                else
                    result = abs(t);
            }

                
        }
    }
    cout << result << endl;
}