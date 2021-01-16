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

bool criticalPt(QPair<int,int> point){
    int cnt = 0;
    for(int i = point.first-1;i<=point.first+1;i++)
    for(int j=point.second-1;j<=point.second+1;j++){
        if(i<0||j<0||i>=10||j>=10) continue;
        if(state[i][j]==-1) cnt++;
    }
    if(cnt>3) return true;
    return false;

}
int Min(int pre,QSet<QPair<int,int>> options,int depth);

QPair<int,QPair<int,int>> Max(int pre,QSet<QPair<int,int>> options,int depth){

    if(options.isEmpty()) return QPair<int,QPair<int,int>>(0,QPair<int,int>()); //draw
    bool isNegative = false;
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
        if(result==-1) isNegative = true;
        //if(depth==1) qDebug()<<eachOptn.first+1<<","<<eachOptn.second+1<<" "<<result<<endl;
        if(tempMax<result){
            tempMax = result;
            temPair = eachOptn;
        }
        state[eachOptn.first][eachOptn.second] = 0;
        if(tempMax>=pre) break;
    }
    //if(depth==1 && !tempMax && isNegative) tempMax = 2; // to protect man from wining
    return QPair<int,QPair<int,int>>(tempMax,temPair);
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
        if(depth==maxDepth) {
            state[eachOptn.first][eachOptn.second] = 0;
            continue;
        }
        // or return minimum of all other options
        QPair<int,QPair<int,int>> result;
        result = Max(tempMIn,insertAdj(options,eachOptn),depth+1);  // check this
        tempMIn = min(tempMIn,result.first);
        state[eachOptn.first][eachOptn.second] = 0;
        if(tempMIn<=pre) break;

    }
    if(depth==maxDepth) return 0;
    return tempMIn;

}



int main()
{
    QSet<QPair<int,int>> options;
    int i,j;
    QPair<int,QPair<int,int>> result;
    while(true){
        bool critical = false;
        cout<<"man: ";
        cin>>i>>j;
        i--;j--;
        state[i][j] = -1;
        if(fiveInRow(i,j)) {
            cout<<"You win"<<endl;
            return -1;
        }
        options = insertAdj(options,QPair<int,int>(i,j));
        result  = Max(99999,options,1);
//        if(!result.first){
//            for(int ii = i-1;ii<=i+1;ii++)
//            {
//            for(int jj=j-1;jj<=j+1;jj++){
//                    if(ii<0||jj<0||ii>=10||jj>=10) continue;
//                    if(state[ii][jj]) continue;
//                    critical = criticalPt(QPair<int,int>(ii,jj));
//                    if(critical){
//                        i = ii;
//                        j = jj;
//                        break;
//                    }
//                }
//              if(critical) break;
//            }
//        }
        //if(!critical){
            i = result.second.first;
            j = result.second.second;
        //}
        qDebug()<<"computer: "<<i+1<<" "<<j+1<<"utility: "<<result.first<<endl;
        //qDebug()<<"computer: "<<i+1<<" "<<j+1<<endl;
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
