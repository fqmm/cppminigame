//# 五子棋

#include <cstdio>
#include <windows.h>
#include <cstdlib>
#include <conio.h>
#include <iostream>
#include <cstring>
using namespace std;
#define Forij(x) for(int i=1;i<=x;i++)for(int j=1;j<=x;j++)
#define N 25 
typedef long long LL;
LL fx[4][2]={{1,1},{1,0},{0,1},{1,-1}};
LL Q,GG;
string C[20]={"●","○","﹢","═","║","╔","╚","╗","╝","·"};//╋
void color(LL a){//颜色函数
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
void gotoxy(LL x,LL y){
    COORD pos;
    pos.X=2*x;
    pos.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

struct Gomoku{
    LL m[50][50],nx,ny;
    void reset(){
        system("cls");
        memset(m,-1,sizeof(m));
        color(7);
        for (LL i=1; i<=N; i++){
            gotoxy(0,i);cout<<C[4]; gotoxy(N+1,i);cout<<C[4];
            gotoxy(i,0);cout<<C[3]; gotoxy(i,N+1);cout<<C[3];
        }
        gotoxy(0,0);cout<<C[5]; gotoxy(0,N+1);cout<<C[6];
        gotoxy(N+1,0);cout<<C[7]; gotoxy(N+1,N+1);cout<<C[8];
        color(3);
        Forij(N){
            gotoxy(i,j); cout<<C[2];
        }
        nx=ny=N/2+1; gotoxy(nx,ny);
    }

    void _drop(LL x,LL i,LL j){
        m[i][j]=x;
        gotoxy(i,j);
        color(15); cout<<C[x];
    }

    LL check(){
        Forij(N){
            for (LL Fx=0,tmp,lst,xx,yy; Fx<4; Fx++) if(m[i][j]!=-1){
                xx=i,yy=j,tmp=0,lst=m[i][j];
                for (LL k=1; k<=5; k++){
                    if (xx>N || yy>N) break;
                    if (m[xx][yy]==(lst^1)){break;}
                    if (m[xx][yy]==lst) tmp++;
                    xx+=fx[Fx][0],yy+=fx[Fx][1];
                }
                if (tmp==5){
                    return lst;
                }
            }
        }
        return -1;
    }
    LL arnd(LL x,LL y){
        LL cnt=0;
        for (LL i=x-1; i<=x+1; i++) if (i>0 && i<=N)
            for (LL j=y-1; j<=y+1; j++) if (j>0 && j<=N)
                if (m[i][j]>-1) cnt++;
        return cnt;
    }
    void get_val(LL x,LL y,LL &val){
        val=0;
        Forij(N){
            for (LL Fx=0,tmp,tk,xx,yy; Fx<4; Fx++){
                xx=i,yy=j,tmp=tk=0;
                for (LL k=1; k<=5; k++){
                    if (xx>N || yy>N){tmp=0; break;}
                    if (m[xx][yy]==(x^1)){tmp=0; break;}
                    if (m[xx][yy]==x) tmp++,tk+=(1<<(k-1));
                    xx+=fx[Fx][0],yy+=fx[Fx][1];
                }
                switch(tmp){
                    case 5:
                        val+=8000000000; break; 
                    case 4:
                        val+=1000+350*y; break;
                    case 3:
                        val+=(tk==14)?(300+600*y):(300+200*y); break;
                    case 2:
                        val+=3+2*y; break;
                    case 1:
                        val+=1+y; break;
                }
            }
        }
    }

    void AI(LL x){
        LL best,brnd,bi,bj,v1,v2,kkk;
        best=-2147483647;
        brnd=-2147483647;
        Forij(N) if (m[i][j]==-1){
            m[i][j]=x;
            get_val(x,10,v1); //gotoxy(N+5,N/2);printf("%d                ",v1);
            get_val(x^1,80,v2); //gotoxy(N+5,N/2+1);printf("%d             ",v2);
            if (v1-v2>best) bi=i,bj=j,best=v1-v2;
            if (v1-v2==best)
                if ((kkk=arnd(i,j))>brnd)
                    brnd=kkk,bi=i,bj=j;
            m[i][j]=-1;
        }
        _drop(x,bi,bj);
    }

    void HM(LL x){
        char ch=getch();
        for (;;ch=getch()){
            if (ch=='w') {if (ny>1) ny--;}
            else if (ch=='s') {if (ny<N) ny++;}
            else if (ch=='a') {if (nx>1) nx--;}
            else if (ch=='d') {if (nx<N)nx++;}
            else if (m[nx][ny]==-1){_drop(x,nx,ny); return;}
            gotoxy(nx,ny);
        }
    }
} A;

int main(){
	SetConsoleTitle("五子棋");
    for (;;){
        A.reset();
        for (GG=-1;;){
            gotoxy(A.nx,A.ny);
            A.HM(0); GG=A.check(); if (GG>-1) break;
            A.AI(1); GG=A.check(); if (GG>-1) break;
        }
        gotoxy(5,N+3);
        if (GG==0) printf("玩家胜利！！！");
        if (GG==1) printf("AI胜利！！！");
        while (kbhit()) getch();
        Sleep(3000);
        gotoxy(5,N+3);
        printf("按任意建以重新来一局");
        getch();
    }
}

