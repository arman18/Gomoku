#include <QPoint>
#include <QSet>
#include <iostream>
#include <QDebug>
using namespace  std;
int state[10][10];
const int maxDepth = 6;
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

double Min(double pre,QSet<QPair<int,int>> options,int depth);

QPair<double,QPair<int,int>> Max(int pre,QSet<QPair<int,int>> options,int depth){

    if(options.isEmpty()) return QPair<int,QPair<int,int>>(0,QPair<int,int>()); //draw
    QPair<int,int> eachOptn;
    double tempMax = -9999999;
    QPair<int,int> temPair;
    foreach (eachOptn, options) {
        if(depth==1) qDebug()<<eachOptn<<" ";
        state[eachOptn.first][eachOptn.second] = 1;
        if(fiveInRow(eachOptn.first,eachOptn.second)){
            state[eachOptn.first][eachOptn.second] = 0;
            temPair = eachOptn;
            tempMax =1;
            if(depth==1) qDebug()<<tempMax<<endl;
            break;
        }
        double result;
        result = Min(tempMax,insertAdj(options,eachOptn),depth+1); // check
        if(tempMax<result){ // never do it equal
            tempMax = result;
            temPair = eachOptn;
        }

        if(depth==1) qDebug()<<tempMax<<endl;
        state[eachOptn.first][eachOptn.second] = 0;
        if(tempMax>=pre || tempMax==1) break;
    }
    return QPair<int,QPair<int,int>>(tempMax,temPair);
}

double Min(double pre,QSet<QPair<int,int>> options,int depth){
    if(options.isEmpty()) return 0; //draw
    QPair<int,int> eachOptn;
    int tempMIn = 9999999,density = 0;
    foreach (eachOptn, options) {
        if(depth==2) qDebug()<<"    "<<eachOptn<<" ";
        state[eachOptn.first][eachOptn.second] = -1;
        if(fiveInRow(eachOptn.first,eachOptn.second)){
            state[eachOptn.first][eachOptn.second] = 0;
            if(depth==2) qDebug()<<"    "<<-2<<endl;
            if(depth==2 && pre<0) return -2;

            return -1; // as we cant more minimize
        }
        if(depth==maxDepth) {
            state[eachOptn.first][eachOptn.second] = 0;
            continue;
        }
        // or return minimum of all other options
        QPair<int,QPair<int,int>> result;
        result = Max(tempMIn,insertAdj(options,eachOptn),depth+1);  // check this
        tempMIn = min(tempMIn,result.first);
        state[eachOptn.first][eachOptn.second] = 0;
        if(depth==2) qDebug()<<"f    "<<tempMIn<<endl;
        if(depth==2 && pre<0 && result.first==-1) {
            density-=1;
            continue;
        }
        if(tempMIn<=pre) break;

    }
    if(depth==2 && pre<0) return (density+0.0)/options.count();
    if(depth==maxDepth) return 0;
    return tempMIn;

}


int main()
{
    QSet<QPair<int,int>> options;
    int i,j;
    bool first = true;
    QPair<double,QPair<int,int>> result;
    while(true){
        cout<<"man: ";
        cin>>i>>j;
        i--;j--;
        state[i][j] = -1;
        if(fiveInRow(i,j)) {
            cout<<"You win"<<endl;
            return -1;
        }
        options = insertAdj(options,QPair<int,int>(i,j));
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
            result  = Max(99999,options,1);

            i = result.second.first;
            j = result.second.second;
        }

        qDebug()<<"computer: "<<i+1<<" "<<j+1<<"utility: "<<result.first<<endl;
        state[i][j] = 1;
        if(fiveInRow(i,j)) {
            cout<<"You loosed"<<endl;
            return 1;
        }
        options = insertAdj(options,QPair<int,int>(i,j));
        if(options.isEmpty()) {
            if(fiveInRow(i,j)) {
                cout<<"draw"<<endl;
                return 1;
            }
        }
    }



}
