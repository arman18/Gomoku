#include "board.h"
#include "displayinfo.h"
#include "utility.h"

#include <QApplication>
#include <QPoint>
#include <QSet>
#include <iostream>
#include <QDebug>
#include <QCoreApplication>
using namespace  std;
int state[10][10];
Utility utilObj;
const int maxDepth = 4;

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
int fiveInRow(const int &i,const int &j,QPoint &start,QPoint &end){
    if(i<0||j<0||i>=10||j>=10){
        cout<<"error from fiveInRow()"<<endl;
        exit(0);
    }
    int value = state[i][j];
    int cnt = 1,jj,ii,row=5;
    jj=j+1;
    start = QPoint(i,j);
    end = QPoint(i,j);
    while(jj<10){
        if(state[i][jj]!=value) break;
        cnt++;
        end = QPoint(i,jj++);
        if(cnt==row) return value;
    }
    jj = j-1;
    while(jj>-1){
        if(state[i][jj]!=value) break;
        cnt++;
        start = QPoint(i,jj--);
        if(cnt==row) return value;
    }
    cnt = 1;
    ii=i+1;
    start = QPoint(i,j);
    end = QPoint(i,j);
    while(ii<10){
        if(state[ii][j]!=value) break;
        cnt++;
        end = QPoint(ii++,j);
        if(cnt==row) return value;
    }
    ii = i-1;
    while(ii>-1){
        if(state[ii][j]!=value) break;
        cnt++;
        start = QPoint(ii--,j);
        if(cnt==row) return value;
    }
    cnt = 1;
    ii = i-1; jj = j+1;
    start = QPoint(i,j);
    end = QPoint(i,j);
    while(ii>-1 && jj<10){
        if(state[ii][jj]!=value) break;
        cnt++;
        start = QPoint(ii--,jj++);
        if(cnt==row) return value;
    }
    ii = i+1; jj = j-1;
    while(ii<10 && jj>-1){
        if(state[ii][jj]!=value) break;
        cnt++;
        end = QPoint(ii++,jj--);
        if(cnt==row) return value;
    }
    cnt = 1;
    ii = i-1; jj = j-1;
    start = QPoint(i,j);
    end = QPoint(i,j);
    while(ii>-1 && jj>-1){
        if(state[ii][jj]!=value) break;
        cnt++;
        start = QPoint(ii--,jj--);
        if(cnt==row) return value;
    }
    ii = i+1; jj = j+1;
    while(ii<10 && jj<10){
        if(state[ii][jj]!=value) break;
        cnt++;
        end = QPoint(ii++,jj++);
        if(cnt==row) return value;
    }
    return 0;
}

QPair<double,QPair<int,int>> Min(const double alpha,QSet<QPair<int,int>> options,int depth);

QPair<double,QPair<int,int>> Max(const double beta,QSet<QPair<int,int>> options,int depth){ /// never call with empty options from main
    //if(depth==1) qDebug()<<"////////////";
    QCoreApplication::processEvents();
    if(options.isEmpty()) return QPair<double,QPair<int,int>>(0,QPair<int,int>()); //draw
    double alpha = -9999999999;
    QPoint start,end;
    QPair<int,int> tempPoint;
    QPair<double,QPair<int,int>> result;
    double maxUtil = 200000000.0/depth;
    foreach (auto option, options) {
        if(depth==2 && logged) qDebug()<<option.first+1<<" "<<option.second+1<<endl;
        state[option.first][option.second] = 1;
        if(fiveInRow(option.first,option.second,start,end))
            result = QPair<double,QPair<int,int>>(maxUtil,QPair<int,int>());
        else{
            if(depth==maxDepth) {
                //double res = utilObj.utility(state,option.first,option.second);
                result = QPair<double,QPair<int,int>>(0/depth,QPair<int,int>());
            }
            else result =  Min(alpha,insertAdj(options,option),depth+1);
            if(result.first==0 && depth==1){
                double res = utilObj.utility(state,option.first,option.second);
                result = QPair<double,QPair<int,int>>(res/maxDepth,QPair<int,int>());
            }
        }
        state[option.first][option.second] = 0;
        //if(depth==1) qDebug()<<result.first<<option;
        if(alpha<result.first) {

            alpha = result.first;
            tempPoint = option;
        }

        if(alpha>=beta || alpha == maxUtil) break;
    }

    return QPair<double,QPair<int,int>>(alpha,tempPoint);
}

QPair<double,QPair<int,int>> Min(const double alpha,QSet<QPair<int,int>> options,int depth){
    QCoreApplication::processEvents();
    if(options.isEmpty()) return QPair<double,QPair<int,int>>(0,QPair<int,int>()); //draw
    double beta = 9999999999;
    QPair<double,QPair<int,int>> result;
    QPoint start,end;
    double maxUtil = -200000000.0/depth;
    foreach (auto option, options) {
        state[option.first][option.second] = -1;
        if(fiveInRow(option.first,option.second,start,end)){
            result = QPair<double,QPair<int,int>>(maxUtil,QPair<int,int>());
        }

        else{
            if(depth==maxDepth) {
//                if(board.info.restartBtnClick){

//                }
                //double res = utilObj.utility(state,option.first,option.second);
                result = QPair<double,QPair<int,int>>(0/depth,QPair<int,int>());
            }
            else result =  Max(beta,insertAdj(options,option),depth+1);
        }
        state[option.first][option.second] = 0;
        if(beta>result.first) beta = result.first;
        if(beta<=alpha || beta == maxUtil) break;
    }

    return QPair<double,QPair<int,int>>(beta,QPair<int,int>());
}

int playByMan(QSet<QPair<int,int>> &options,Board &board){
    int i,j;
    QPoint start,end;
    QPair<double,QPair<int,int>> result;
    while(true){
        if(board.info.restartBtnClick){
            board.info.restartBtnClick = 0;
            return 1;
        }
        QCoreApplication::processEvents();
        QPoint userClicked = board.getClickLocation();
        i = userClicked.x(); j = userClicked.y();
        board.setManImage(i,j);
        state[i][j] = -1;
        if(fiveInRow(i,j,start,end)) {
            board.man_won(start,end);
            return board.info.getButtonClick();
        }
        options = insertAdj(options,QPair<int,int>(i,j));
        if(options.isEmpty()) {
                board.info.draw();
                return board.info.getButtonClick();
        }
// computer turn-------------------------------

        result  = Max(9999999999,options,1);
        if(board.info.restartBtnClick){
            board.info.restartBtnClick = 0;
            return 1;
        }
        i = result.second.first; j = result.second.second;
        //qDebug()<<result.first;
        board.setComputerImage(i,j);
        state[i][j] = 1;
        if(fiveInRow(i,j,start,end)) {
            //qDebug()<<"i,j"<<i<<","<<j<<"start "<<start<<"end "<<end;
            board.computer_won(start,end);
            return board.info.getButtonClick();
        }
        options = insertAdj(options,QPair<int,int>(i,j));
        if(options.isEmpty()) {
                board.info.draw();
                return board.info.getButtonClick();
        }

    }
}

void clearState(Board &board,QSet<QPair<int,int>> &options){
    board.resetCells();
    for(int ii = 0;ii<10;ii++)
        for(int jj=0;jj<10;jj++) state[ii][jj] = 0;
    options.clear();
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Board board;
    board.show();
    QSet<QPair<int,int>> options;
    int i,j;
    while (true) {
        while(true){
            clearState(board,options);
            i = 4; j = 4;
            board.setComputerImage(i,j);
            state[i][j] = 1;
            options = insertAdj(options,QPair<int,int>(i,j));
            if(playByMan(options,board)==1) continue;
            else break;
        }


//        cout<<"\n----------------play again-------------------"<<endl;

        while(true){
            clearState(board,options);
            board.info.manTurn();
            QCoreApplication::processEvents();
            QPoint userClicked = board.getClickLocation();
            i = userClicked.x(); j = userClicked.y();
            board.setManImage(i,j);
            state[i][j] = -1;
            options = insertAdj(options,QPair<int,int>(i,j));

                if(!state[4][4]){
                    i=4;j=4;
                }
                else {
                    i = 5;j = 5;
                }

            board.setComputerImage(i,j);
            state[i][j] = 1;
            options = insertAdj(options,QPair<int,int>(i,j));
            if(playByMan(options,board)==1) continue;
            else break;
        }
    }

    return a.exec();
}
