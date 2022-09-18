#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    while (1) {
        vector<int> vi;
        for (int i = 0; i < 8; i++) {
            int mountain_h; // represents the height of one mountain.
            cin >> mountain_h; cin.ignore();
            vi.push_back(mountain_h);
        }
        auto it = max_element(begin(vi), end(vi));
        cout << distance(begin(vi), it) << endl;
    }
}