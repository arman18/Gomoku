#include "utility.h"
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

Utility::Utility()
{

}

double Utility::utility(int (*gameState)[10], int x, int y)
{
string patternComputer[] = {"XXXXX", "XXXX-", "XX-XX", "XXX-X", "-XXX-", "XXX--", "-XX-X", //7
        "XX-X-", "--XX-", "-XX--", "XX---", "XX--X", "X-X--", "X---X",  "X--X-", "-X-X-",
         "X-X-X", "--X--", "-X---", "X----"}; //14

string patternMan[] = {"OOOOO", "OOOO-", "OO-OO", "OOO-O", "-OOO-", "OOO--", "-OO-O", //7
        "OO-OO-", "--OO-", "-OO--", "OO---", "OO--O", "O-O--", "O---O", "O--O-",
         "-O-O-", "O-O-O", "--O--", "-O---", "O----"};


double profit[] = {200000000.0, 50000.0, 15000.0, 15000.0, 780.0, 620.0, 450.0, 450.0, 300.0, 200.0,
                    80.0, 50.0, 30.0, 30.0, 30.0, 30.0, 30.0, 15.0, 15.0, 10.0};

string state[10][10];

for (int i=0; i<10; i++)
{
    for(int j=0; j<10; j++)
    {
        if(gameState[i][j] == 1) state[i][j] = "X";
        else if(gameState[i][j] == -1) state[i][j] = "O";
        else state[i][j] = "-";
    }
}

if(state[x][y] == "X")
{
    state[x][y] = "-";
    double mult = 1.0;
    double pcProfit = 0;

    for(int iter=0; iter<5; iter++)
    {
        int pr = x + iter; //r for right diagonal
        int qr = y - iter; //l for left diagonal
        int pl = x + iter;
        int ql = y + iter;
        string sr = "";
        string sl = "";

        for(int iterr=0; iterr<5; iterr++)
        {
            if (pr>-1 && pr<10 && qr>-1 && qr<10)
            {
                sr += state[pr][qr];
                pr -= 1;
                qr += 1;
            }


            if (pl>-1 && pl<10 && ql>-1 && ql<10)
            {
                sl += state[pl][ql];
                pl -= 1;
                ql -= 1;
            }

        }

        int k = 1;
        string sr2 = sr;
        reverse(sr2.begin(), sr2.end());

        for(int i=0; i<20; i++)
            {
                if(sr == patternMan[i] || sr2 == patternMan[i])
                {
                    pcProfit += mult * profit[i];
                    k = 0;
                    break;

                }
            }
        if(k)
        {
            sr[iter] = 'X';
            string sr3 = sr;
            reverse(sr3.begin(), sr3.end());

            for(int i=0; i<20; i++)
            {
                if(sr == patternComputer[i] || sr3 == patternComputer[i])
                {
                    pcProfit += mult * profit[i];
                    //k = 0;
                    break;

                }
            }

        }

        int k2 = 1;
        string sl2 = sl;
        reverse(sl2.begin(), sl2.end());

        for(int i=0; i<20; i++)
            {
                if(sl == patternMan[i] || sl2 == patternMan[i])
                {
                    pcProfit += mult * profit[i];
                    k2 = 0;
                    break;

                }
            }
        if(k2)
        {
            sl[iter] = 'X';
            string sl3 = sr;
            reverse(sl3.begin(), sl3.end());

            for(int i=0; i<20; i++)
            {
                if(sl == patternComputer[i] || sl3 == patternComputer[i])
                {
                    pcProfit += mult * profit[i];
                    //k = 0;
                    break;

                }
            }

        }


    }

    //up down left right
    for(int iter=0; iter<5; iter++)
    {
        int pu = x + iter; //r for right diagonal
        int qu = y; //l for left diagonal
        int ph = x;
        int qh = y - iter;
        string su = "";
        string sh = "";

        for(int iterr=0; iterr<5; iterr++)
        {
            if (pu>-1 && pu<10 && qu>-1 && qu<10)
            {
                su += state[pu][qu];
                pu -= 1;
                //qr += 1;
            }


            if (ph>-1 && ph<10 && qh>-1 && qh<10)
            {
                sh += state[ph][qh];
                //pl -= 1;
                qh -= 1;
            }

        }

        int k = 1;
        string su2 = su;
        reverse(su2.begin(), su2.end());

        for(int i=0; i<20; i++)
            {
                if(su == patternMan[i] || su2 == patternMan[i])
                {
                    pcProfit += mult * profit[i];
                    k = 0;
                    break;

                }
            }
        if(k)
        {
            su[iter] = 'X';
            string su3 = su;
            reverse(su3.begin(), su3.end());

            for(int i=0; i<20; i++)
            {
                if(su == patternComputer[i] || su3 == patternComputer[i])
                {
                    pcProfit += mult * profit[i];
                    //k = 0;
                    break;

                }
            }

        }

        int k2 = 1;
        string sh2 = sh;
        reverse(sh2.begin(), sh2.end());

        for(int i=0; i<20; i++)
            {
                if(sh == patternMan[i] || sh2 == patternMan[i])
                {
                    pcProfit += mult * profit[i];
                    k2 = 0;
                    break;

                }
            }
        if(k2)
        {
            sh[iter] = 'X';
            string sh3 = sh;
            reverse(sh3.begin(), sh3.end());

            for(int i=0; i<20; i++)
            {
                if(sh == patternComputer[i] || sh3 == patternComputer[i])
                {
                    pcProfit += mult * profit[i];
                    //k = 0;
                    break;

                }
            }

        }


    }

    return pcProfit;
}


else
{
    state[x][y] = "-";
    double mult = -1.0;
    double manProfit = 0.0;

    for(int iter=0; iter<5; iter++)
    {
        int pr = x + iter; //r for right diagonal
        int qr = y - iter; //l for left diagonal
        int pl = x + iter;
        int ql = y + iter;
        string sr = "";
        string sl = "";

        for(int iterr=0; iterr<5; iterr++)
        {
            if (pr>-1 && pr<10 && qr>-1 && qr<10)
            {
                sr += state[pr][qr];
                pr -= 1;
                qr += 1;
            }


            if (pl>-1 && pl<10 && ql>-1 && ql<10)
            {
                sl += state[pl][ql];
                pl -= 1;
                ql -= 1;
            }

        }

        int k = 1;
        string sr2 = sr;
        reverse(sr2.begin(), sr2.end());

        for(int i=0; i<20; i++)
            {
                if(sr == patternComputer[i] || sr2 == patternComputer[i])
                {
                    manProfit += mult * profit[i];
                    k = 0;
                    break;

                }
            }
        if(k)
        {
            sr[iter] = 'O';
            string sr3 = sr;
            reverse(sr3.begin(), sr3.end());

            for(int i=0; i<20; i++)
            {
                if(sr == patternMan[i] || sr3 == patternMan[i])
                {
                    manProfit += mult * profit[i];
                    //k = 0;
                    break;

                }
            }

        }

        int k2 = 1;
        string sl2 = sl;
        reverse(sl2.begin(), sl2.end());

        for(int i=0; i<20; i++)
            {
                if(sl == patternComputer[i] || sl2 == patternComputer[i])
                {
                    manProfit += mult * profit[i];
                    k2 = 0;
                    break;

                }
            }
        if(k2)
        {
            sl[iter] = 'O';
            string sl3 = sr;
            reverse(sl3.begin(), sl3.end());

            for(int i=0; i<20; i++)
            {
                if(sl == patternMan[i] || sl3 == patternMan[i])
                {
                    manProfit += mult * profit[i];
                    //k = 0;
                    break;

                }
            }

        }


    }

    //up down left right
    for(int iter=0; iter<5; iter++)
    {
        int pu = x + iter; //r for right diagonal
        int qu = y; //l for left diagonal
        int ph = x;
        int qh = y - iter;
        string su = "";
        string sh = "";

        for(int iterr=0; iterr<5; iterr++)
        {
            if (pu>-1 && pu<10 && qu>-1 && qu<10)
            {
                su += state[pu][qu];
                pu -= 1;
                //qr += 1;
            }


            if (ph>-1 && ph<10 && qh>-1 && qh<10)
            {
                sh += state[ph][qh];
                //pl -= 1;
                qh -= 1;
            }

        }

        int k = 1;
        string su2 = su;
        reverse(su2.begin(), su2.end());

        for(int i=0; i<20; i++)
            {
                if(su == patternComputer[i] || su2 == patternComputer[i])
                {
                    manProfit += mult * profit[i];
                    k = 0;
                    break;

                }
            }
        if(k)
        {
            su[iter] = 'O';
            string su3 = su;
            reverse(su3.begin(), su3.end());

            for(int i=0; i<20; i++)
            {
                if(su == patternMan[i] || su3 == patternMan[i])
                {
                    manProfit += mult * profit[i];
                    //k = 0;
                    break;

                }
            }

        }

        int k2 = 1;
        string sh2 = sh;
        reverse(sh2.begin(), sh2.end());

        for(int i=0; i<20; i++)
            {
                if(sh == patternComputer[i] || sh2 == patternComputer[i])
                {
                    manProfit += mult * profit[i];
                    k2 = 0;
                    break;

                }
            }
        if(k2)
        {
            sh[iter] = 'O';
            string sh3 = sh;
            reverse(sh3.begin(), sh3.end());

            for(int i=0; i<20; i++)
            {
                if(sh == patternMan[i] || sh3 == patternMan[i])
                {
                    manProfit += mult * profit[i];
                    //k = 0;
                    break;

                }
            }

        }


    }

    return manProfit;
    }
}


int main()
{
    string s[] = {"X", "X", "X","X", "X", "X"};
    s[2] = "O";
    cout<<s[2]<<endl;
    string sr= "123456";
    string sr2 = sr;
    reverse(sr2.begin(), sr2.end());
    cout<<sr2<<endl;
    sr[2]='#';
    cout<<sr<<endl;
    string st = "awer";
    st+= "zz";
    cout<<st<<endl;

}
