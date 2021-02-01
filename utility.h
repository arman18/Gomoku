#ifndef UTILITY_H
#define UTILITY_H


class Utility
{
public:
    Utility();
    //double utility(const int (*gameState)[10], int x, int y);
    double utility(int (*gameState)[10], int x, int y);
};

#endif // UTILITY_H
