/**
 * @file pesca.cpp
 *
 * @version 01.01 2020-11-5
 *
 * @brief https://training.olinfo.it/#/task/pesca/statement
 *
 * @ingroup pesca
 * (Note: this needs exactly one @defgroup somewhere)
 *
 * @author Castellani Davide
 *
 * Contact: contacts@castellanidavide.it
 *
 */

// Includes
#include <bits/stdc++.h>
using namespace std;

#define DEBUG

// Variabiles
int P, x0, y0_, change, pescati, temp, temp2, max_x;
vector < vector <int> > pesci2;
map <int, int> my_y;  // x, y

// Main code
int main()
{
    // Cncomment the following lines if you want to read/write from files
    freopen("input.txt", "r", stdin);
#ifndef DEBUG
    freopen("output.txt", "w", stdout);
#endif // DEBUG

    // Input
    cin >> P >> x0 >> y0_;
    int x0_m = x0;
    int y0_m = y0_;
    pescati = 0;
    max_x = -1;

#ifdef DEBUG
    cout << "Header readed" << endl;
#endif // DEBUG

    for (int i = 0; i < P; ++i)
    {
        cin >> temp >> temp2;
        if (temp >= pesci2.size())
            pesci2.resize(temp * 95);
        pesci2[temp].push_back(temp2);
        max_x = max(max_x, temp);
    }

#ifdef DEBUG
    cout << "Pesci readed" << endl;
#endif // DEBUG

    my_y[x0] = y0_;

    // First
    do
    {
        cin >> change;
        if (change > 0)
        {
            y0_ += change;
        }

        if (change < 0)
        {
            for (int i = x0 + 1; i < x0 - change + 1; i++)
            {
                my_y[i] = y0_;
            }
            x0 -= change;
        }
#ifdef DEBUG
        cout << "My position is : (" << x0 << ", " << y0_ << ")" << endl;
#endif // DEBUG
    }
    while (change != 0);

#ifdef DEBUG
    cout << "First cicle ok" << endl;
#endif // DEBUG

    // Second
    x0 = x0_m;
    y0_ = y0_m;
    do
    {
        cin >> change;
        if (change > 0)
        {
            y0_ += change;
        }

        if (change < 0)
        {
            for (int i = x0; i < x0 - change && x0 <= max_x; i++)
            {
                for(int j = 0; j < pesci2[i].size(); ++j)
                {
                    if((pesci2[i][j] <= my_y[i] && pesci2[i][j] >= y0_) || (pesci2[i][j] >= my_y[i] && pesci2[i][j] <= y0_))
                    {
#ifdef DEBUG
                        cout << "Taked is : (" << i << ", " << pesci2[i][j] << ")" << endl;
#endif // DEBUG
                        ++pescati;
                    }
                }
            }
            x0 -= change;
        }
#ifdef DEBUG
        cout << "My position is : (" << x0 << ", " << y0_ << ")" << endl;
#endif // DEBUG
    }
    while (change != 0);

#ifdef DEBUG
    cout << "Check last, x0 = " << x0 << endl;
#endif // DEBUG
    if(x0 <= max_x)
    {
        for(int j = 0; j < pesci2[x0].size(); ++j)
        {
            if((pesci2[x0][j] <= my_y[x0] && pesci2[x0][j] >= y0_) || (pesci2[x0][j] >= my_y[x0] && pesci2[x0][j] <= y0_))
            {
#ifdef DEBUG
                cout << "Taked is : (" << x0 << ", " << pesci2[x0][j] << ")" << endl;
#endif // DEBUG
                ++pescati;
            }
        }
    }

#ifdef DEBUG
    cout << "Second cicle ok" << endl;
#endif // DEBUG

    // Output
    cout << pescati << endl;

    // End
    return 0;
}
