#include <QPoint>
#include <QSet>
#include <iostream>
#include <QDebug>
using namespace  std;
int state[10][10];
const int maxDepth = 6;
bool logged = false;
QSet<QPair<int,int>> insertAdj(QSet<QPair<int,int>> set,QPair<int,int> point){
    set.remove(point);
    for(int i = point.first-1;i<=point.first+1;i++)
    for(int j=point.second-1;j<=point.second+1;j++){
        if(i<0||j<0||i>=10||j>=10) {
            //cout<<"---i<0---"<<endl;
            continue;
        }
        if(state[i][j]) continue;
        set.insert(QPair<int,int>(i,j));
    }
    return set;

}

/// if value lies 5 in row then return that value otherwise return 0
int fiveInRow(const int &i,const int &j){
    if(i<0||j<0||i>=10||j>=10){
        cout<<"error from fiveInRow()"<<endl;
        exit(0);
    }
    int value = state[i][j];
    int cnt = 1,jj,ii,row=5;
    jj=j+1;
    while(jj<10){
        if(state[i][jj++]!=value) break;
        cnt++;
        if(cnt==row) return value;
    }
    jj = j-1;
    while(jj>-1){
        if(state[i][jj--]!=value) break;
        cnt++;
        if(cnt==row) return value;
    }
    cnt = 1;
    ii=i+1;
    while(ii<10){
        if(state[ii++][j]!=value) break;
        cnt++;
        if(cnt==row) return value;
    }
    ii = i-1;
    while(ii>-1){
        if(state[ii--][j]!=value) break;
        cnt++;
        if(cnt==row) return value;
    }
    cnt = 1;
    ii = i-1; jj = j+1;
    while(ii>-1 && jj<10){
        if(state[ii--][jj++]!=value) break;
        cnt++;
        if(cnt==row) return value;
    }
    ii = i+1; jj = j-1;
    while(ii<10 && jj>-1){
        if(state[ii++][jj--]!=value) break;
        cnt++;
        if(cnt==row) return value;
    }
    cnt = 1;
    ii = i-1; jj = j-1;
    while(ii>-1 && jj>-1){
        if(state[ii--][jj--]!=value) break;
        cnt++;
        if(cnt==row) return value;
    }
    ii = i+1; jj = j+1;
    while(ii<10 && jj<10){
        if(state[ii++][jj++]!=value) break;
        cnt++;
        if(cnt==row) return value;
    }
    return 0;
}

QPair<double,QPair<int,int>> Min(double pre,QSet<QPair<int,int>> options,int depth);

QPair<double,QPair<int,int>> Max(double pre,QSet<QPair<int,int>> options,int depth){ /// never call with empty options from main

    if(options.isEmpty()) return QPair<double,QPair<int,int>>(0,QPair<int,int>()); //draw
    double tempMax = -9999999;
    QPair<int,int> tempPoint;
    QPair<double,QPair<int,int>> result;
    double maxUtil = 1.0/depth;
    foreach (auto option, options) {
        if(depth==2 && logged) qDebug()<<option.first+1<<" "<<option.second+1<<endl;
        state[option.first][option.second] = 1;
        if(fiveInRow(option.first,option.second))
            result = QPair<double,QPair<int,int>>(maxUtil,QPair<int,int>());
        else{
            if(depth==maxDepth) result = QPair<double,QPair<int,int>>(0,QPair<int,int>());
            else result =  Min(tempMax,insertAdj(options,option),depth+1);
        }
        state[option.first][option.second] = 0;
        if(tempMax<result.first) {
            tempMax = result.first;
            tempPoint = option;
        }
        if(depth==2 && logged) qDebug()<<"tempMIn "<<tempMax<<" result "<<result.first<<endl;
        if(tempMax>=pre || tempMax == maxUtil) break;
    }

    return QPair<double,QPair<int,int>>(tempMax,tempPoint);
}

QPair<double,QPair<int,int>> Min(double pre,QSet<QPair<int,int>> options,int depth){
    if(options.isEmpty()) return QPair<double,QPair<int,int>>(0,QPair<int,int>()); //draw
    double tempMIn = 9999999;
    QPair<double,QPair<int,int>> result;
    double maxUtil = -1.0/depth;
    foreach (auto option, options) {
        if(depth==2 && logged) qDebug()<<"     "<<option.first+1<<" "<<option.second+1<<endl;
        state[option.first][option.second] = -1;
        if(fiveInRow(option.first,option.second))
            result = QPair<double,QPair<int,int>>(maxUtil,QPair<int,int>());
        else{
            if(depth==maxDepth) result = QPair<double,QPair<int,int>>(0,QPair<int,int>());
            else result =  Max(tempMIn,insertAdj(options,option),depth+1);
        }
        state[option.first][option.second] = 0;
        if(tempMIn>result.first) tempMIn = result.first;
        if(depth==2 && logged) qDebug()<<"       tempMIn "<<tempMIn<<" result "<<result.first<<endl;
        if(tempMIn<=pre || tempMIn == maxUtil) break;
    }

    return QPair<double,QPair<int,int>>(tempMIn,QPair<int,int>());
}


int main()
{
    QSet<QPair<int,int>> options;
    int i,j;
    bool first = true;
    QPair<double,QPair<int,int>> result;
    while (true) {
        while(true){
            if(first){
                    i = 4;
                    j = 4;
                    first = false;
                }
            else {
                result  = Max(9999999,options,1);

                i = result.second.first;
                j = result.second.second;
            }

            qDebug()<<"computer: "<<i+1<<" "<<j+1;//<<"utility: "<<result.first<<endl;
            state[i][j] = 1;
            if(fiveInRow(i,j)) {
                cout<<"You loosed"<<endl;
                break;
            }
            options = insertAdj(options,QPair<int,int>(i,j));
            if(options.isEmpty()) {
                if(fiveInRow(i,j)) {
                    cout<<"draw"<<endl;
                    break;
                }
            }
            cout<<"man: ";
            cin>>i>>j;
            i--;j--;
            state[i][j] = -1;
            if(fiveInRow(i,j)) {
                cout<<"You win"<<endl;
                break;
            }
            options = insertAdj(options,QPair<int,int>(i,j));
            if(options.isEmpty()) {
                if(fiveInRow(i,j)) {
                    cout<<"draw"<<endl;
                    break;
                }
            }
        }
        first = true;
        options.clear();
        for(int ii = 0;ii<10;ii++)
            for(int jj=0;jj<10;jj++) state[ii][jj] = 0;
        cout<<"\n----------------play again-------------------"<<endl;
        getchar();
        while(true){
            cout<<"man: ";
            cin>>i>>j;
            i--;j--;
            state[i][j] = -1;
            if(fiveInRow(i,j)) {
                cout<<"You win"<<endl;
                break;
            }
            options = insertAdj(options,QPair<int,int>(i,j));
            if(options.isEmpty()) {
                if(fiveInRow(i,j)) {
                    cout<<"draw"<<endl;
                    break;
                }
            }
            if(first){
                if(!state[4][4]){
                    i=4;j=4;
                }
                else {
                    i = 5;
                    j = 5;
                }
                first = false;
            }
            else {
                result  = Max(9999999,options,1);

                i = result.second.first;
                j = result.second.second;
            }

            qDebug()<<"computer: "<<i+1<<" "<<j+1;//<<"utility: "<<result.first<<endl;
            state[i][j] = 1;
            if(fiveInRow(i,j)) {
                cout<<"You loosed"<<endl;
                break;
            }
            options = insertAdj(options,QPair<int,int>(i,j));
            if(options.isEmpty()) {
                if(fiveInRow(i,j)) {
                    cout<<"draw"<<endl;
                    break;
                }
            }
        }
        cout<<"\n----------------play again-------------------"<<endl;
        getchar();
    }



}
