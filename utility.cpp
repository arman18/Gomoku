#include<iostream>
#include<bits/stdc++.h>

using namespace std;

double utility(int gameState[][10], int x, int y)
{
    string patternComputer[] = {"XXXXX", "XXXX-", "XX-XX", "XXX-X", "-XXX-", "XXX--", "-XX-X", //7
			"XX-X-", "--XX-", "-XX--", "XX---", "XX--X", "X-X--", "X---X",  "X--X-", "-X-X-",
			 "X-X-X", "--X--", "-X---", "X----"}; //14

    string patternMan[] = {"OOOOO", "OOOO-", "OO-OO", "OOO-O", "-OOO-", "OOO--", "-OO-O", //7
			"OO-OO-", "--OO-", "-OO--", "OO---", "OO--O", "O-O--", "O---O", "O--O-",
			 "-O-O-", "O-O-O", "--O--", "-O---", "O----"};


    double profit[] = {200000000.0, 500000.0, 30000.0, 30000.0, 10000.0, 900.0, 450.0, 450.0, 300.0, 200.0,
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
        double pcProfit = 0.0;

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
            //cout<<sr<<endl;
            cout<<sl<<endl;

            int k = 1;
            string sr2 = sr;
            reverse(sr2.begin(), sr2.end());
            cout<<sr<<endl;
            cout<<sr2<<endl;

            for(int i=0; i<20; i++)
                {
                    if(sr == patternMan[i] || sr2 == patternMan[i])
                    {
                        pcProfit += mult * profit[i];
                        cout<<profit[i]<<endl;
                        k = 0;
                        break;

                    }
                }
            if(k)
            {
                //sr[iter] = 'X';
                string sr3 = sr;
                reverse(sr3.begin(), sr3.end());

                for(int i=0; i<20; i++)
                {
                    if(sr == patternComputer[i] || sr3 == patternComputer[i])
                    {
                        pcProfit += mult * profit[i];
                        cout<<profit[i]<<endl;
                        //k = 0;
                        break;

                    }
                }

            }

            int k2 = 1;
            string sl2 = sl;
            reverse(sl2.begin(), sl2.end());
            cout<<sl<<endl;
            cout<<sl2<<endl;

            for(int i=0; i<20; i++)
                {
                    if(sl == patternMan[i] || sl2 == patternMan[i])
                    {
                        pcProfit += mult * profit[i];
                        cout<<profit[i]<<endl;
                        k2 = 0;
                        break;

                    }
                }
            if(k2)
            {
                //sl[iter] = 'X';
                string sl3 = sr;
                reverse(sl3.begin(), sl3.end());

                for(int i=0; i<20; i++)
                {
                    if(sl == patternComputer[i] || sl3 == patternComputer[i])
                    {
                        pcProfit += mult * profit[i];
                        cout<<profit[i]<<endl;
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
                //su[iter] = 'X';
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
                //sh[iter] = 'X';
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
        double mult = 1.0;
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
                //sr[iter] = 'O';
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
                //sl[iter] = 'O';
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
                //su[iter] = 'O';
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
                //sh[iter] = 'O';
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

        return manProfit * -1.00;
    }






}



int main()
{
    int state[10][10] = {
//   0 1 2 3 4 5 6 7 8 9
    {0,0,0,0,0,0,0,0,-1,0},//0
    {0,0,0,0,0,0,0,1,0,0},//1
    {0,0,0,0,0,0,1,0,0,0},//2
    {0,0,0,0,0,1,1,0,0,0},//3
    {0,0,0,0,1,0,1,0,0,0},//4
    {0,0,0,-1,0,-1,0,0,0,0},//5
    {0,0,0,0,-1,0,0,0,0,0},//6
    {0,0,0,0,0,-1,0,0,0,0},//7
    {0,0,0,0,0,0,0,0,0,0},//8
    {0,0,0,0,0,0,0,0,0,0}//9
    };

    //double value = utility(state, 5, 4); //1.74433e-006
    //double value = utility(state, 5, 7); //2.64753e-006
    //double value = utility(state, 6, 4); //4.36773e-006
    //double value = utility(state, 4, 6); //3.55417e-006
    //double value = utility(state, 5, 3); //4.37807e-007
    //double value = utility(state, 4, 5); //3.69895e-006

    //double value = utility(state, 6, 3); //-1.44787e-007
    //double value = utility(state, 6, 6); //-1.79604e-006
    //double value = utility(state, 6, 2); //-1.62368e-006
    //double value = utility(state, 2, 4); //-1.69952e-006
    //double value = utility(state, 3, 5); //-2.86815e-006

    //double value = utility(state, 7, 5); //3.21633e-006
    //double value = utility(state, 4, 2); //3.19909e-006
    //double value = utility(state, 5, 2); //2.34416e-007
    //double value = utility(state, 6, 5); //1.82017e-006

    //double value = utility(state, 5, 3); //3.67827e-006
    //double value = utility(state, 8, 7); //3.67827e-006//105
    //double value = utility(state, 3, 3); //2.65442e-007
    //double value = utility(state, 6, 3); //9.54902e-007
    //double value = utility(state, 6, 5); //1.82017e-006
    //double value = utility(state, 4, 5); //2.14422e-006
    //double value = utility(state, 4, 6); //13235 //690
    //double value = utility(state, 8, 7); //0 600
    //double value = utility(state, 4, 6); //820
    //double value = utility(state, 8, 6); //600 //10900
    double value = utility(state, 4, 6); //1450
    cout<<value<<endl; //-0.000174065 //-5.01582e-006

}
