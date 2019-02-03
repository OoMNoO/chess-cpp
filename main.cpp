#include <iostream>
#include <stdlib.h>
using namespace std;

void printboard(char a[8][8]);
void orginize(char a[8][8]);
void Rotate(char a[8][8]);
void coordinate(int X[2][8],int Y[2][8]);
void moverook(char a[8][8],int specifier,int direction,int direction2,int length,int X[2][8],int Y[2][8]);
void movesoldier(char a[8][8],int specifier,int direction,int direction2,int length,int X[2][8],int Y[2][8]);
void movehorse(char a[8][8],int specifier,int direction,int direction2,int length,int X[2][8],int Y[2][8]);
void movebishob(char a[8][8],int specifier,int direction,int direction2,int length,int X[2][8],int Y[2][8]);
void moveking(char a[8][8],int specifier,int direction,int direction2,int length,int X[2][8],int Y[2][8]);
void movequeen(char a[8][8],int specifier,int direction,int direction2,int length,int X[2][8],int Y[2][8]);
void check(char a[8][8],char piece,int specifier,int direction,int direction2,int length,int X[2][8],int Y[2][8]);
//================================================================================================================================================================
//================================================================================================================================================================
int main(){
    char a[8][8];
    int X[2][8],Y[2][8];
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            a[i][j]=' ';
    orginize(a);
    coordinate(X,Y);
    int P=1,specifier,direction,direction2,length;
    char piece;
    while(P==1){
        printboard(a);
        cin>>piece>>specifier>>direction>>direction2>>length;
        check(a,piece,specifier,direction,direction2,length,X,Y);
        //system("cls");
        Rotate(a);
    }
}
//================================================================================================================================================================
//================================================================================================================================================================
void printboard(char a[8][8]){
    for(int i=0;i<8;i++){
        cout<< "|-------------------------------|"<<endl;
        for(int j=0;j<8;j++){
            cout<<"| ";
            cout<<a[i][j];
            cout<<" ";
        }
        cout<<"|"<<endl;
    }
    cout<< "|-------------------------------|"<<endl;
}
//================================================================================================================================================================
void orginize(char a[8][8]){
    for(int i=0;i<8;i+=7)
        for(int j=0;j<8;j+=7)
            a[i][j]='R';
    for(int i=0;i<8;i+=7)
        for(int j=1;j<8;j+=5)
            a[i][j]='H';
    for(int i=0;i<8;i+=7)
        for(int j=2;j<8;j+=3)
            a[i][j]='B';
    for(int i=0,j=4;i<8;i+=7,j--)
        a[i][j]='Q';
    for(int i=0,j=3;i<8;i+=7,j++)
        a[i][j]='K';
    for(int i=1;i<8;i+=5)
        for(int j=0;j<8;j++)
            a[i][j]='S';
}
//================================================================================================================================================================
void Rotate(char a[8][8]){
    char b[8][8];
    for(int i=0,t=7;t>=0;i++,t--){
        for(int j=0,k=7;k>=0;j++,k--){
            b[i][j]=a[t][k];
        }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            a[i][j]=' ';
        }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            a[i][j]=b[i][j];
        }
    }
    printboard(b);
    cout<<endl;
    return;
}
//================================================================================================================================================================
void coordinate(int X[2][8],int Y[2][8]){
    for(int j=0;j<2;j++)
        for(int i=0;i<8;i++)
            X[j][i]=i;
    for(int j=0,t=7;j<2;j++,t--)
        for(int i=0;i<8;i++)
            Y[j][i]=t;
}
//================================================================================================================================================================
//================================================================================================================================================================
void moverook(char a[8][8],int specifier,int direction,int direction2,int length,int X[2][8],int Y[2][8]){
    switch(specifier){
        int T,M;
        case 1:
            if(direction==0){
                for(int i=0;i<length;i++){
                    T=Y[0][0];
                    M=X[0][0];
                    a[T][M]=' ';
                    T--;
                    a[T][M]='R';
                    Y[0][0]=T;
                    X[0][0]=M;
                }
                return;
            }
            if(direction==1){
                for(int i=0;i<length;i++){
                    T=Y[0][0];
                    M=X[0][0];
                    a[T][M]=' ';
                    T++;
                    a[T][M]='R';
                    Y[0][0]=T;
                    X[0][0]=M;
                }
                return;
            }
            if(direction==2){
                for(int i=0;i<length;i++){
                    T=Y[0][0];
                    M=X[0][0];
                    a[T][M]=' ';
                    M++;
                    a[T][M]='R';
                    Y[0][0]=T;
                    X[0][0]=M;
                }
                return;
            }
            if(direction==3){
                for(int i=0;i<length;i++){
                    T=Y[0][0];
                    M=X[0][0];
                    a[T][M]=' ';
                    M--;
                    a[T][M]='R';
                    Y[0][0]=T;
                    X[0][0]=M;
                }
                return;
            }
        case 0:
            if(direction==0){//up
                for(int i=0;i<length;i++){
                    T=Y[0][7];
                    M=X[0][7];
                    a[T][M]=' ';
                    T--;
                    a[T][M]='R';
                    Y[0][7]=T;
                    X[0][7]=M;
                }
                return;
            }
            if(direction==1){
                for(int i=0;i<length;i++){
                    T=Y[0][7];
                    M=X[0][7];
                    a[T][M]=' ';
                    T++;
                    a[T][M]='R';
                    Y[0][7]=T;
                    X[0][7]=M;
                }
                return;
            }
            if(direction==2){
                for(int i=0;i<length;i++){
                    T=Y[0][7];
                    M=X[0][7];
                    a[T][M]=' ';
                    M++;
                    a[T][M]='R';
                    Y[0][7]=T;
                    X[0][7]=M;
                }
                return;
            }
            if(direction==3){
                for(int i=0;i<length;i++){
                    T=Y[0][7];
                    M=X[0][7];
                    a[T][M]=' ';
                    M--;
                    a[T][M]='R';
                    Y[0][7]=T;
                    X[0][7]=M;
                }
                return;
            }
    }
}
//================================================================================================================================================================
void movesoldier(char a[8][8],int specifier,int direction,int direction2,int length,int X[2][8],int Y[2][8]){
    switch(specifier){
        int T,M;
        case 1:
            T=Y[1][0];
            M=X[1][0];
            if(direction2==1){
                a[T][M]=' ';
                T--;
                M++;
                a[T][M]='S';
                Y[1][0]=T;
                X[1][0]=M;
                return;
            }
            if(direction2==0){
                a[T][M]=' ';
                T--;
                a[T][M]='S';
                Y[1][0]=T;
                X[1][0]=M;
                return;
            }
            if(direction2==-1){
                a[T][M]=' ';
                T--;
                M--;
                a[T][M]='S';
                Y[1][0]=T;
                X[1][0]=M;
                return;
            }
        case 2:
            T=Y[1][1];
            M=X[1][1];
            if(direction2==1){
                a[T][M]=' ';
                T--;
                M++;
                a[T][M]='S';
                Y[1][1]=T;
                X[1][1]=M;
                return;
            }
            if(direction2==0){
                a[T][M]=' ';
                T--;
                a[T][M]='S';
                Y[1][1]=T;
                X[1][1]=M;
                return;
            }
            if(direction2==-1){
                a[T][M]=' ';
                T--;
                M--;
                a[T][M]='S';
                Y[1][1]=T;
                X[1][1]=M;
                return;
            }
        case 3:
            T=Y[1][2];
            M=X[1][2];
            if(direction2==1){
                a[T][M]=' ';
                T--;
                M++;
                a[T][M]='S';
                Y[1][2]=T;
                X[1][2]=M;
                return;
            }
            if(direction2==0){
                a[T][M]=' ';
                T--;
                a[T][M]='S';
                Y[1][2]=T;
                X[1][2]=M;
                return;
            }
            if(direction2==-1){
                a[T][M]=' ';
                T--;
                M--;
                a[T][M]='S';
                Y[1][2]=T;
                X[1][2]=M;
                return;
            }
        case 4:
            T=Y[1][3];
            M=X[1][3];
            if(direction2==1){
                a[T][M]=' ';
                T--;
                M++;
                a[T][M]='S';
                Y[1][3]=T;
                X[1][3]=M;
                return;
            }
            if(direction2==0){
                a[T][M]=' ';
                T--;
                a[T][M]='S';
                Y[1][3]=T;
                X[1][3]=M;
                return;
            }
            if(direction2==-1){
                a[T][M]=' ';
                T--;
                M--;
                a[T][M]='S';
                Y[1][3]=T;
                X[1][3]=M;
                return;
            }
        case 5:
            T=Y[1][4];
            M=X[1][4];
            if(direction2==1){
                a[T][M]=' ';
                T--;
                M++;
                a[T][M]='S';
                Y[1][4]=T;
                X[1][4]=M;
                return;
            }
            if(direction2==0){
                a[T][M]=' ';
                T--;
                a[T][M]='S';
                Y[1][4]=T;
                X[1][4]=M;
                return;
            }
            if(direction2==-1){
                a[T][M]=' ';
                T--;
                M--;
                a[T][M]='S';
                Y[1][4]=T;
                X[1][4]=M;
                return;
            }
        case 6:
            T=Y[1][5];
            M=X[1][5];
            if(direction2==1){
                a[T][M]=' ';
                T--;
                M++;
                a[T][M]='S';
                Y[1][5]=T;
                X[1][5]=M;
                return;
            }
            if(direction2==0){
                a[T][M]=' ';
                T--;
                a[T][M]='S';
                Y[1][5]=T;
                X[1][5]=M;
                return;
            }
            if(direction2==-1){
                a[T][M]=' ';
                T--;
                M--;
                a[T][M]='S';
                Y[1][5]=T;
                X[1][5]=M;
                return;
            }
        case 7:
            T=Y[1][6];
            M=X[1][6];
            if(direction2==1){
                a[T][M]=' ';
                T--;
                M++;
                a[T][M]='S';
                Y[1][6]=T;
                X[1][6]=M;
                return;
            }
            if(direction2==0){
                a[T][M]=' ';
                T--;
                a[T][M]='S';
                Y[1][6]=T;
                X[1][6]=M;
                return;
            }
            if(direction2==-1){
                a[T][M]=' ';
                T--;
                M--;
                a[T][M]='S';
                Y[1][6]=T;
                X[1][6]=M;
                return;
            }
        case 8:
            T=Y[1][7];
            M=X[1][7];
            if(direction2==1){
                a[T][M]=' ';
                T--;
                M++;
                a[T][M]='S';
                Y[1][7]=T;
                X[1][7]=M;
                return;
            }
            if(direction2==0){
                a[T][M]=' ';
                T--;
                a[T][M]='S';
                Y[1][7]=T;
                X[1][7]=M;
                return;
            }
            if(direction2==-1){
                a[T][M]=' ';
                T--;
                M--;
                a[T][M]='S';
                Y[1][7]=T;
                X[1][7]=M;
                return;
            }
    }
}
//================================================================================================================================================================
void movehorse(char a[8][8],int specifier,int direction,int direction2,int length,int X[2][8],int Y[2][8]){
    switch(specifier){
        int T,M;
        case 0:
            if(direction==0){
                T=Y[0][6];
                M=X[0][6];
                a[T][M]=' ';
                T-=2;
                M++;
                a[T][M]='H';
                Y[0][6]=T;
                X[0][6]=M;
                return;
            }
            if(direction==1){
                T=Y[0][6];
                M=X[0][6];
                a[T][M]=' ';
                T-=2;
                M--;
                a[T][M]='H';
                Y[0][6]=T;
                X[0][6]=M;
                return;
            }
            if(direction==2){
                T=Y[0][6];
                M=X[0][6];
                a[T][M]=' ';
                T+=2;
                M++;
                a[T][M]='H';
                Y[0][6]=T;
                X[0][6]=M;
                return;
            }
            if(direction==3){
                T=Y[0][6];
                M=X[0][6];
                a[T][M]=' ';
                T+=2;
                M--;
                a[T][M]='H';
                Y[0][6]=T;
                X[0][6]=M;
                return;
            }
            if(direction==4){
                T=Y[0][6];
                M=X[0][6];
                a[T][M]=' ';
                M+=2;
                T--;
                a[T][M]='H';
                Y[0][6]=T;
                X[0][6]=M;
                return;
            }
            if(direction==5){
                T=Y[0][6];
                M=X[0][6];
                a[T][M]=' ';
                M-=2;
                T--;
                a[T][M]='H';
                Y[0][6]=T;
                X[0][6]=M;
                return;
            }
            if(direction==6){
                T=Y[0][6];
                M=X[0][6];
                a[T][M]=' ';
                M+=2;
                T++;
                a[T][M]='H';
                Y[0][6]=T;
                X[0][6]=M;
                return;
            }
            if(direction==7){
                T=Y[0][6];
                M=X[0][6];
                a[T][M]=' ';
                M-=2;
                T++;
                a[T][M]='H';
                Y[0][6]=T;
                X[0][6]=M;
                return;
            }
        case 1:
            if(direction==0){
                T=Y[0][1];
                M=X[0][1];
                a[T][M]=' ';
                T-=2;
                M++;
                a[T][M]='H';
                Y[0][1]=T;
                X[0][1]=M;
                return;
            }
            if(direction==1){
                T=Y[0][1];
                M=X[0][1];
                a[T][M]=' ';
                T-=2;
                M--;
                a[T][M]='H';
                Y[0][1]=T;
                X[0][1]=M;
                return;
            }
            if(direction==2){
                T=Y[0][1];
                M=X[0][1];
                a[T][M]=' ';
                T+=2;
                M++;
                a[T][M]='H';
                Y[0][1]=T;
                X[0][1]=M;
                return;
            }
            if(direction==3){
                T=Y[0][1];
                M=X[0][1];
                a[T][M]=' ';
                T+=2;
                M--;
                a[T][M]='H';
                Y[0][1]=T;
                X[0][1]=M;
                return;
            }
            if(direction==4){
                T=Y[0][1];
                M=X[0][1];
                a[T][M]=' ';
                M+=2;
                T--;
                a[T][M]='H';
                Y[0][1]=T;
                X[0][1]=M;
                return;
            }
            if(direction==5){
                T=Y[0][1];
                M=X[0][1];
                a[T][M]=' ';
                M-=2;
                T--;
                a[T][M]='H';
                Y[0][1]=T;
                X[0][1]=M;
                return;
            }
            if(direction==6){
                T=Y[0][1];
                M=X[0][1];
                a[T][M]=' ';
                M+=2;
                T++;
                a[T][M]='H';
                Y[0][1]=T;
                X[0][1]=M;
                return;
            }
            if(direction==7){
                T=Y[0][1];
                M=X[0][1];
                a[T][M]=' ';
                M-=2;
                T++;
                a[T][M]='H';
                Y[0][1]=T;
                X[0][1]=M;
                return;
            }
    }
}
//================================================================================================================================================================
void movebishob(char a[8][8],int specifier,int direction,int direction2,int length,int X[2][8],int Y[2][8]){
    switch(specifier){
        //a[7][2]='B';
        int T,M;
        case 1:
            if(direction==0){
                for(int i=0;i<length;i++){
                    T=Y[0][2];
                    M=X[0][2];
                    a[T][M]=' ';
                    T--;
                    M++;
                    a[T][M]='B';
                    Y[0][2]=T;
                    X[0][2]=M;
                }
                return;
            }
            if(direction==1){
                for(int i=0;i<length;i++){
                    T=Y[0][2];
                    M=X[0][2];
                    a[T][M]=' ';
                    T--;
                    M--;
                    a[T][M]='B';
                    Y[0][2]=T;
                    X[0][2]=M;
                }
                return;
            }
            if(direction==2){
                for(int i=0;i<length;i++){
                    T=Y[0][2];
                    M=X[0][2];
                    a[T][M]=' ';
                    T++;
                    M++;
                    a[T][M]='B';
                    Y[0][2]=T;
                    X[0][2]=M;
                }
                return;
            }
            if(direction==3){
                for(int i=0;i<length;i++){
                    T=Y[0][2];
                    M=X[0][2];
                    a[T][M]=' ';
                    M--;
                    T++;
                    a[T][M]='B';
                    Y[0][2]=T;
                    X[0][2]=M;
                }
                return;
            }
        case 0:
            if(direction==0){
                for(int i=0;i<length;i++){
                    T=Y[0][5];
                    M=X[0][5];
                    a[T][M]=' ';
                    T--;
                    M++;
                    a[T][M]='B';
                    Y[0][5]=T;
                    X[0][5]=M;
                }
                return;
            }
            if(direction==1){
                for(int i=0;i<length;i++){
                    T=Y[0][5];
                    M=X[0][5];
                    a[T][M]=' ';
                    T--;
                    M--;
                    a[T][M]='B';
                    Y[0][5]=T;
                    X[0][5]=M;
                }
                return;
            }
            if(direction==2){
                for(int i=0;i<length;i++){
                    T=Y[0][5];
                    M=X[0][5];
                    a[T][M]=' ';
                    T++;
                    M++;
                    a[T][M]='B';
                    Y[0][5]=T;
                    X[0][5]=M;
                }
                return;
            }
            if(direction==3){
                for(int i=0;i<length;i++){
                    T=Y[0][5];
                    M=X[0][5];
                    a[T][M]=' ';
                    M--;
                    T++;
                    a[T][M]='B';
                    Y[0][5]=T;
                    X[0][5]=M;
                }
                return;
            }

    }
}
//================================================================================================================================================================
void moveking(char a[8][8],int specifier,int direction,int direction2,int length,int X[2][8],int Y[2][8]){
    switch(direction){
        int T,M;
        case 1:
            T=Y[0][4];
            M=X[0][4];
            if(direction2==1){
                a[T][M]=' ';
                T--;
                M++;
                a[T][M]='K';
                Y[0][4]=T;
                X[0][4]=M;
                return;
            }
            if(direction2==0){
                a[T][M]=' ';
                T--;
                a[T][M]='K';
                Y[0][4]=T;
                X[0][4]=M;
                return;
            }
            if(direction2==-1){
                a[T][M]=' ';
                T--;
                M--;
                a[T][M]='K';
                Y[0][4]=T;
                X[0][4]=M;
                return;
            }
        case 0:
            T=Y[0][4];
            M=X[0][4];
            if(direction2==1){
                a[T][M]=' ';
                T++;
                M++;
                a[T][M]='K';
                Y[0][4]=T;
                X[0][4]=M;
                return;
            }
            if(direction2==0){
                a[T][M]=' ';
                T++;
                a[T][M]='K';
                Y[0][4]=T;
                X[0][4]=M;
                return;
            }
            if(direction2==-1){
                a[T][M]=' ';
                T++;
                M--;
                a[T][M]='K';
                Y[0][4]=T;
                X[0][4]=M;
                return;
            }
    }
}
//================================================================================================================================================================
void movequeen(char a[8][8],int specifier,int direction,int direction2,int length,int X[2][8],int Y[2][8]){
    int T,M;
    if(direction==0){
        for(int i=0;i<length;i++){
            T=Y[0][3];
            M=X[0][3];
            a[T][M]=' ';
            T--;
            a[T][M]='Q';
            Y[0][3]=T;
            X[0][3]=M;
        }
        return;
    }
    if(direction==1){
        for(int i=0;i<length;i++){
            T=Y[0][3];
            M=X[0][3];
            a[T][M]=' ';
            T++;
            a[T][M]='Q';
            Y[0][3]=T;
            X[0][3]=M;
        }
        return;
    }
    if(direction==2){
        for(int i=0;i<length;i++){
            T=Y[0][3];
            M=X[0][3];
            a[T][M]=' ';
            M++;
            a[T][M]='Q';
            Y[0][3]=T;
            X[0][3]=M;
        }
        return;
    }
    if(direction==3){
        for(int i=0;i<length;i++){
            T=Y[0][3];
            M=X[0][3];
            a[T][M]=' ';
            M--;
            a[T][M]='Q';
            Y[0][3]=T;
            X[0][3]=M;
        }
        return;
    }
    if(direction==4){
        for(int i=0;i<length;i++){
            T=Y[0][3];
            M=X[0][3];
            a[T][M]=' ';
            T--;
            M++;
            a[T][M]='Q';
            Y[0][3]=T;
            X[0][3]=M;
        }
        return;
    }
    if(direction==5){
        for(int i=0;i<length;i++){
            T=Y[0][3];
            M=X[0][3];
            a[T][M]=' ';
            T--;
            M--;
            a[T][M]='Q';
            Y[0][3]=T;
            X[0][3]=M;
        }
        return;
    }
    if(direction==6){
        for(int i=0;i<length;i++){
            T=Y[0][3];
            M=X[0][3];
            a[T][M]=' ';
            T++;
            M++;
            a[T][M]='Q';
            Y[0][3]=T;
            X[0][3]=M;
        }
        return;
    }
    if(direction==7){
        for(int i=0;i<length;i++){
            T=Y[0][3];
            M=X[0][3];
            a[T][M]=' ';
            M--;
            T++;
            a[T][M]='Q';
            Y[0][3]=T;
            X[0][3]=M;
        }
        return;
    }
}
//================================================================================================================================================================
//================================================================================================================================================================
void check(char a[8][8],char piece,int specifier,int direction,int direction2,int length,int X[2][8],int Y[2][8]){
    switch(piece){
            case 'B':
                movebishob(a,specifier,direction,direction2,length,X,Y);
                return;
            case 'H':
                movehorse(a,specifier,direction,direction2,length,X,Y);
                return;
            case 'K':
                moveking(a,specifier,direction,direction2,length,X,Y);
                return;
            case 'Q':
                movequeen(a,specifier,direction,direction2,length,X,Y);
                return;
            case 'R':
                moverook(a,specifier,direction,direction2,length,X,Y);
                return;
            case 'S':
                movesoldier(a,specifier,direction,direction2,length,X,Y);
                return;
        }
}
