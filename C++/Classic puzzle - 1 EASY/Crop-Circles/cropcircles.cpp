#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef int elem_t;
typedef vector<int> vi;
typedef vector<vi> vvi;


class Field
{
    public:
        void stamp()
        {
            for(const auto &vv : farmingArea)
            {
                for(auto v : vv)
                {
                    cout << (v ? "{}" : "  ");
                }
                cout << endl;
            }
        }

        void ex(string& s)
        {
            Op operation = Moving;
            if(s.find("PLANTMOW") != string::npos)
            {
                operation = PlantMow;
                s.erase(0, 8);
            }
            else if(s.find("PLANT") != string::npos)
            {
                operation = Plant;
                s.erase(0, 5);
            }
            std::string output = std::regex_replace
            (
                s,
                std::regex("[^0-9]*([0-9]+).*"),
                std::string("$1")
            );
            int diameter = stoi(output);
            int r = diameter/2;
            int x = s[0] - 'a' , y = s[1] - 'a';
            int xMin = x - r, xMax = x + r;
            int yMin = y - r, yMax = y + r;
            for(int i = max(yMin,0); i <= min(yMax, 24); i++)
            {
                for(int j = xMin; j <= xMax; j++)
                {
                    if(isInside(j, i, x, y, diameter))
                    {
                        int lineStart = max(j, 0);
                        int lineEnd = min(2*x-j, 18);
                        cerr << lineStart << " " << lineEnd << endl;
                        while(lineStart <= lineEnd)
                        {
                            performOperation(farmingArea[i][lineStart++], operation); 
                        }
                        break;
                    }
                }
            }
        }

    private:
        vvi farmingArea{25, vi(19, 1)};
        enum Op{Moving, Plant, PlantMow};

        bool isInside(int x1, int y1, int x2, int y2, int diameter)
        {
            return (pow(x1 - x2, 2) + pow(y1 - y2, 2) <= pow(diameter/2.0, 2));
        }

        void performOperation(int &elem, Op operation) {
        switch (operation) {
            case Moving:   elem = false; break;
            case Plant:    elem = true;  break;
            case PlantMow: elem = !elem; break;
        }
    }
};

int main()
{
    Field field;
    string instruction;
    while (cin >> instruction)
        field.ex(instruction);

    field.stamp();
}