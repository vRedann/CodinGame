#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool isIn(const string& source, char c)
{
    for(int i = 0; i < source.size(); i++)
    {
        if(source[i] == c)
            return true;
    }
    return false;
}

int main() {
  int w, h, n;
  cin >> w >> h >> n;cin.ignore();
  int x0, y0;
  cin >> x0 >> y0;cin.ignore();
  int LX = 0, LY = 0, HX = w, HY = h;
  while (1) {
    string bomb_dir;
    cin >> bomb_dir;cin.ignore();

    if(isIn(bomb_dir, 'U'))
        HY = y0;
    else if(isIn(bomb_dir, 'D'))
        LY = y0;

    if(isIn(bomb_dir, 'L'))
        HX = x0;
    else if(isIn(bomb_dir, 'R'))
        LX = x0;

    cerr << HX << " " << LX << " " << HY << " " << LY << " "
         << "x0 " << x0 << "y0 " << y0 << endl;
    x0 = (HX + LX) / 2 ;
    y0 = (HY + LY) / 2 ;
    cout << x0 << " " << y0 << endl;
  }
}