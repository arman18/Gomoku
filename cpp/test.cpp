#include <QPoint>
#include <QSet>
#include <iostream>
#include <QDebug>
using namespace  std;
int state[10][10];

QSet<QPair<int,int>> insertAdj(QSet<QPair<int,int>> set,QPair<int,int> point){
    set.remove(point);
    for(int i = point.first-1;i<=point.first+1;i++)
    for(int j=point.second-1;j<=point.second+1;j++){
        if(i<0||j<0||i>=10||j>=10) continue;
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

int Min(int pre,QSet<QPair<int,int>> options,int depth);

QPair<int,QPair<int,int>> Max(int pre,QSet<QPair<int,int>> options,int depth){
    //cout<<"Max:depth "<<depth<<" options "<<options.count()<<endl;
    if(options.isEmpty()) return QPair<int,QPair<int,int>>(0,QPair<int,int>()); //draw
    QPair<int,int> eachOptn;
    int tempMax = -9999999;
    QPair<int,int> temPair;
    foreach (eachOptn, options) {
        state[eachOptn.first][eachOptn.second] = 1;
        if(fiveInRow(eachOptn.first,eachOptn.second)){
            state[eachOptn.first][eachOptn.second] = 0;
            return QPair<int,QPair<int,int>> (1,eachOptn);
        }
        int result;
        result = Min(tempMax,insertAdj(options,eachOptn),depth+1); // check
        //cout<<"result "<<result<<endl;
        if(tempMax<result){
            tempMax = result;
            temPair = eachOptn;
        }
        state[eachOptn.first][eachOptn.second] = 0;
        if(tempMax>=pre) break;
    }
    return QPair<int,QPair<int,int>>(tempMax,eachOptn);
}

int Min(int pre,QSet<QPair<int,int>> options,int depth){
    //cout<<"Min:depth "<<depth<<" options "<<options.count()<<endl;
    if(options.isEmpty()) return 0; //draw
    QPair<int,int> eachOptn;
    int tempMIn = 9999999;
    foreach (eachOptn, options) {
        state[eachOptn.first][eachOptn.second] = -1;
        if(fiveInRow(eachOptn.first,eachOptn.second)){
            state[eachOptn.first][eachOptn.second] = 0;
            return -1; // as we cant more minimize
        }
        if(depth==4) continue;
        // or return minimum of all other options
        QPair<int,QPair<int,int>> result;
        result = Max(tempMIn,insertAdj(options,eachOptn),depth+1);  // check this
        tempMIn = min(tempMIn,result.first);
        state[eachOptn.first][eachOptn.second] = 0;
        if(tempMIn<=pre) break;

    }
    if(depth==4) return 0;
    return tempMIn;

}



int main()
{
    QSet<QPair<int,int>> options;
    int i,j;
    QPair<int,QPair<int,int>> result;
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
        int depth =  1;
        result  = Max(99999,options,depth);
        qDebug()<<"computer: "<<result.second<<"utility: "<<result.first<<endl;
        i = result.second.first;j = result.second.second;
        state[i][j] = 1;
        if(fiveInRow(i,j)) {
            cout<<"You loosed"<<endl;
            return 1;
        }
        options = insertAdj(options,QPair<int,int>(i,j));
    }



}
