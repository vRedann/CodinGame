#include <bits/stdc++.h>
using namespace std;
int main()
{
    int light_x, light_y, initial_tx, initial_ty;
    cin >> light_x >> light_y >> initial_tx >> initial_ty; cin.ignore();
    while (1) {
        int remaining_turns;
        cin >> remaining_turns; cin.ignore();
        if(light_y < initial_ty)
            {cout << "N"; initial_ty--;}
        else if(light_y > initial_ty)
            {cout << "S"; initial_ty++;}
        if(light_x < initial_tx) 
            {cout << "W"; initial_tx--;}
        else if(light_x > initial_tx)
            {cout << "E"; initial_tx++;}
        cout << endl;
    }
}