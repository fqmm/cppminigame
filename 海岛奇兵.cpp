//# 海岛奇兵

#include<bits/stdc++.h>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
using namespace std;
typedef BOOL (WINAPI *PROCSETCONSOLEFONT)(HANDLE, DWORD);
PROCSETCONSOLEFONT SetConsoleFont;
POINT Windowpos(){POINT pt;GetCursorPos(&pt);HWND h=GetForegroundWindow();ScreenToClient(h,&pt);pt.x=(pt.x+4)/10+0.5;pt.y=pt.y/8+0.5;swap(pt.x,pt.y);return pt;}
int mouse;POINT pt;float kx,ky;int ti(float a) {return ((int)(a*10+5))/10;}
void Print(int a){HMODULE hKernel32 = GetModuleHandle("kernel32");SetConsoleFont = (PROCSETCONSOLEFONT)GetProcAddress(hKernel32,"SetConsoleFont");SetConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE),a);}
void Setpos(float x,float y){COORD pos;pos.X=ti(y*4)/2;pos.Y=ti(x);SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);}
//Setpos中，横5和竖5是一样的长度，在C,N中我们把y*2存入，/2输出 ,所以 支持4.5 
struct node {float x,y,fx,fy;int kind,staytime,blood,CD,enemy,turn=6;bool life;} M[100001],E[100001];//Mytower Enemy Bullet
struct bullet {float x,y,vx,vy,h;int kind,staytime,enemy,endx,endy,up;bool life;} B[100001];//,ice,medical,durg,
float Espeed[7]=    {-1,    0.14,   0.2,    0.08,   0.3,    0.3,    0.1};//敌人速度 
float Bspeed[7]=    {-1,    0.6,    0.6,    0.6,    1,      0.1,    0.6};//打塔的子弹速度 
float Bfspeed[7]=   {-1,    0.4,    0.4,    -1,     0.3,    1,  0.4};//打敌的子弹速度 
float MR[7]=        {-1,    12,     10,     25,     8,      15,     20};
float ER[7]=        {-1,    5,      1.8,    8,      7,      1,      10};
int MCDmax[7]=      {10000, 10,     7,      60,     2,      90,     50};
int ECDmax[7]=      {-1,    30,     10,     40,     25,     1,      40};
int Mblood[7]=      {-1,200,150,300,250,400,300};
int Eblood[7]=      {-1,50,100,30,100,10,200};
bool Zhan[50][50];
//Pk_Pb : personkill_or_placeboom
int m[51][101],n[51][101],o[51][101],T,CD,CDmax,Day,ml,mr,el,er,bl,br,money,Level=1;
void Color(int a)
{
    if(a==0) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    if(a==1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
    if(a==2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
    if(a==3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
    if(a==4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
    if(a==5) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
    if(a>=6) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
}
void C(int i,int j){Color(0);
    Setpos(i,j/2.0);int N=n[i][j];if(N==-1) printf(" ");if(N>=0&&N<=9) printf("%d",N);
    if(N==-2) printf("+");if(N==-3) Color(5),printf("+"),n[i][j]=-1,o[i][j]=4;if(N==-4) Color(3),printf("+"),n[i][j]=-1,o[i][j]=4;
    //以下字符占2格 
    if(N==11) Color(1),printf("О");if(N==13) Color(3),printf("◎");if(N==14) Color(4),printf("＋");if(N==16) Color(5),printf("◎");
    if(N==-11) Color(1),printf("⊙");if(N==-12) Color(2),printf("⊙");if(N==-13) Color(3),printf("⊙");if(N==-14) Color(4+rand()%2),printf("█");if(N==-15) Color(1),printf("●");if(N==-16) Color(5),printf("¤");
    if(N==49) Color(0),printf("营");if(N==50) Color(0),printf("墙");if(N==51) Color(1),printf("●");if(N==52) Color(2),printf("■");if(N==53) Color(3),printf("▲");if(N==54) Color(4),printf("▼");if(N==55) Color(6),printf("◆");if(N==56) Color(5),printf("★");
    if(N==81) Color(1),printf("○");if(N==82) Color(2),printf("□");if(N==83) Color(3),printf("△");if(N==84) Color(4),printf("▽");if(N==85) Color(6),printf("◇");if(N==86) Color(5),printf("☆");
    if(N==1001)  printf("╔");//if(N==1002)  printf("╦");
    if(N==1003)  printf("╗");if(N==1004)  printf("╠");if(N==1005)  printf("╣");if(N==1006)  printf("╚");if(N==1007)  printf("╩");if(N==1008)  printf("╝");
    if(N==1011)  printf("↖");if(N==1012)  printf("↑");if(N==1013)  printf("↗");if(N==1014)  printf("←");if(N==1015)  printf("→");if(N==1016)  printf("↙");if(N==1017)  printf("↓");if(N==1018)  printf("↘");

}
void Map(int a){if(a==1){for(int i=1;i<=50;i++)for(int j=1;j<=100;j++){
if(n[i][j]!=m[i][j]||T%800==0){C(i,j);if(n[i][j]>=50||n[i][j]<=-10) n[i][j+1]=-1,j++;}
if(o[i][j]==1) C(i,j);if(o[i][j]>0) o[i][j]--;
}
for(int i=1;i<=50;i++)for(int j=1;j<=100;j++){m[i][j]=n[i][j];}}
}
void N(float x,float y,int w){int xx=(int)(x+0.5),yy=(int)(y*2.0+0.5);if(xx>49||yy>98||xx<1||yy<1) return;else n[xx][yy]=w;}
int Turn[9][2]={{0,0},{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
void Circle(int x,int y,int kind,int ex)
{int R;
    if(kind==1){int k=M[ex].kind;R=MR[k];int next=20-0.5*R;
    for(int i=0;i<=360;i+=next) N(x+R*sin(3.1416*i/180),y+R*cos(3.1416*i/180),-2);
    if(k==3) for(int i=0;i<=360;i+=15) R=10,N(x+R*sin(3.1416*i/180),y+R*cos(3.1416*i/180),-2);
    }
    if(kind==-1){int k=M[ex].kind;R=MR[k];int next=20-0.5*R;
    for(int i=0;i<=360;i+=next) N(x+R*sin(3.1416*i/180),y+R*cos(3.1416*i/180),-1);
    if(k==3) for(int i=0;i<=360;i+=15) R=10,N(x+R*sin(3.1416*i/180),y+R*cos(3.1416*i/180),-1);
    }
    if(kind==2){R=ex;int next=20-0.5*R;
    for(int i=0;i<=360;i+=next) N(x+R*sin(3.1416*i/180),y+R*cos(3.1416*i/180),-3);
    }
    if(kind==-2){R=ex;int next=20-0.5*R;
    for(int i=0;i<=360;i+=next) N(x+R*sin(3.1416*i/180),y+R*cos(3.1416*i/180),-4);
    }
}
void Cout(int a,int kind){
    if(kind==1)//炮台
    {
        float x=M[a].x,y=M[a].y;
        N(x,y,M[a].kind+50);
        if(a==1) N(x,y,49);
        int i=1;if(M[a].blood>=100) i=2;
        for(i;i<=8;i++) N(x+Turn[i][0],y+Turn[i][1],1000+i),Zhan[(int)x+Turn[i][0]][(int)y+Turn[i][1]]=1;
        int t=M[a].turn;
//      N(Turn[t][0],y+Turn[t][1],1010+t);
        int b=max(0,M[a].blood),bb=0;while(b>0){bb++;N(x-1,y+1-0.5*bb,b%10);b/=10;}
    }
    if(kind==2)//人 
    {
        float x=E[a].x,y=E[a].y;
        N(x,y,E[a].kind+80);
        N(x+1,y,1012);//////////
        Zhan[(int)x][(int)y]=Zhan[(int)x+1][(int)y]=1;
//      N(x+1,y,1010+E[a].turn);
        int b=max(0,E[a].blood),bb=0;while(b>0){bb++;N(x-1,y+1-0.5*bb,b%10);b/=10;}
    }
    if(kind==3)//对塔子弹 
    {
        float x=B[a].x,y=B[a].y;
        N(x,y,10+B[a].kind);
    }
    if(kind==4)//对人子弹 
    {
        float x=B[a].x,y=B[a].y;
        N(x-B[a].h,y,-10+B[a].kind);
    }
}
int Find_enemy(int Who,int good_or_bad){
    int ans=-1,r=rand()%2;float ansx=1e9,x;//搜敌人 
if(good_or_bad>=1){float X=M[Who].x,Y=M[Who].y;
    if(good_or_bad==2) X=E[Who].x,Y=E[Who].y;
    for(int i=el;i<=er;i++){if(E[i].life==0) continue;x=sqrt((E[i].x-X)*(E[i].x-X)+(E[i].y-Y)*(E[i].y-Y));
    if(good_or_bad==2&&E[i].kind==4) continue;
    if(M[Who].kind==3&&x<10) continue;//迫击炮 
    if(M[Who].kind==6&&ans!=-1&&ansx>x) ansx=x;//火箭炮
    if(ansx>x) ansx=x,ans=i;
    if(ansx==x) {int r=rand()%2;if(r==1) ansx=x,ans=i;}}}
    if(good_or_bad==0){float X=E[Who].x,Y=E[Who].y;for(int i=ml;i<=mr;i++) {if(M[i].life==0) continue;x=sqrt((M[i].x-X)*(M[i].x-X)+(M[i].y-Y)*(M[i].y-Y));if(ansx>x) ansx=x,ans=i;if(ansx==x) {int r=rand()%2;if(r==1) ansx=x,ans=i;}}}
    return ans;
}
void Find_boomkill(int Who,float r,bool good_or_bad,int kill){
    float x,X=B[Who].x,Y=B[Who].y;int kk=(float)kill/2.5;kill+=rand()%kk-kk/5;
    if(good_or_bad==1){for(int i=el;i<=er;i++){if(E[i].life==0) continue;x=sqrt((E[i].x-X)*(E[i].x-X)+(E[i].y-Y)*(E[i].y-Y));if(r>=x) E[i].blood=min(E[i].blood-kill,Eblood[E[i].kind]+Day+50);}
}//搜敌人
    else{for(int i=ml;i<=mr;i++){if(M[i].life==0) continue;x=sqrt((M[i].x-X)*(M[i].x-X)+(M[i].y-Y)*(M[i].y-Y));if(r>=x) M[i].blood-=kill;}
}//搜炮台
}
void Die(){
    for(int i=ml;i<=mr;i++){
        if(M[i].blood<=0) M[i].life=0;
//      if(M[i].life==0&&i==ml) ml++;
    }
    for(int i=el;i<=er;i++){
        if(E[i].blood<=0) E[i].life=0;
//      if(E[i].life==0&&i==el) el++;
    }
    for(int i=bl;i<=br;i++){
        if(B[i].x+B[i].vx<1||B[i].x+B[i].vx>49||B[i].y+B[i].vy<1||B[i].y+B[i].vy>98) {B[i].life=0;}
        if(B[i].staytime>=100) B[i].life=0;
//      if(B[i].life==0&&i==bl) bl++;
    }
//  if(el>er) el=er=0,memset(E,0,sizeof(E));if(bl>br) bl=br=0,memset(B,0,sizeof(B));
}
void Move(int a){
    if(a==2)
    {
    for(int i=ml;i<=mr;i++){if(M[i].life==0) continue;Cout(i,1);}
    for(int i=el;i<=er;i++){if(E[i].life==0) continue;Cout(i,2);}
    return;
    }
    for(int i=ml;i<=mr;i++){
        if(M[i].life==0) continue;
        else{M[i].staytime++;int e=M[i].enemy;if(E[e].life==0) M[i].enemy=-1;

            if(M[i].kind==5&&M[i].enemy==-1&&M[i].CD<=70&&T%2==0) M[i].CD++;
            if(M[i].kind==0&&M[i].blood<=500&&T%20==0) M[i].blood++;
        if(M[i].enemy==-1||M[i].kind==4) M[i].enemy=Find_enemy(i,1);//喷火器 
        if(M[i].enemy!=-1)
    {int k=M[i].enemy;
        float X=M[i].x,Y=M[i].y,Ax=E[k].x-X,Ay=E[k].y-Y;if(Ay==0) Ay=1e-6;float Turnn=abs(Ax/Ay*1.0),Dis=sqrt((E[k].x-X)*(E[k].x-X)+(E[k].y-Y)*(E[k].y-Y));

        if(Dis>MR[M[i].kind]){M[i].enemy=-1;}
        else
        {M[i].CD++;
            if((M[i].kind!=6&&M[i].CD>=MCDmax[M[i].kind])||(M[i].kind==6&&M[i].CD<=21&&M[i].CD%4==0))//火箭炮 
            {
            if(M[i].kind==6) M[i].enemy=Find_enemy(i,1);
            if(Turnn>=sqrt(2)+1){if(Ay>0) M[i].turn=2;else M[i].turn=7;}
            else if(Turnn>=1.0/(sqrt(2)+1)*1.0){if(Ax>0&&Ay>0) M[i].turn=1;else if(Ax<0&&Ay>0) M[i].turn=3;else if(Ax<0&&Ay<0) M[i].turn=8;else M[i].turn=6;}
            else {if(Ax>0) M[i].turn=5;else M[i].turn=4;}
            br++,B[br].x=X,B[br].y=Y;
            B[br].kind=-M[i].kind;///////
            B[br].life=1,B[br].enemy=M[i].enemy,B[br].endx=E[M[i].enemy].x,B[br].endy=E[M[i].enemy].y,B[br].staytime=0;
            }
            if(M[i].CD>=MCDmax[M[i].kind]) M[i].CD=0;
        }
    }Cout(i,1);}}
    for(int i=el;i<=er;i++){
        if(E[i].life==0) continue;
        else{E[i].staytime++;E[i].CD++;
        int e=E[i].enemy;if(M[e].life==0||(E[i].kind==4&&E[e].life==0)) E[i].enemy=-1;
//        if(T%100==1) E[i].enemy=-1;
        if(E[i].enemy==-1) {E[i].enemy=Find_enemy(i,0);if(E[i].kind==4) E[i].enemy=Find_enemy(i,2);}
        if(E[i].enemy!=-1){int k=E[i].enemy;int Mkx=M[k].x;int Mky=M[k].y;if(E[i].kind==4) Mkx=E[k].x,Mky=E[k].y;
        float X=E[i].x,Y=E[i].y;float Dis=sqrt((Mkx-X)*(Mkx-X)+(Mky-Y)*(Mky-Y));
        float Ax=Mkx-X,Ay=Mky-Y,S=Espeed[E[i].kind];if(Ay==0) Ay=1e-6;float Turnn=abs(Ax/Ay*1.0);
        if(Dis>ER[E[i].kind]){float vx=Ax*S/Dis*1.0,vy=Ay*S/Dis*1.0;E[i].x+=vx,E[i].y+=vy;}
        else{
        if(E[i].CD>=ECDmax[E[i].kind]){
//        if(Turnn>=sqrt(2)+1){if(Ay>0) E[i].turn=7;else E[i].turn=2;}
//        else if(Turnn>=1.0/(sqrt(2)+1)*1.0){if(Ax>0&&Ay>0) E[i].turn=8;else if(Ax<0&&Ay>0) E[i].turn=6;else if(Ax<0&&Ay<0) E[i].turn=1;else E[i].turn=3;}
//        else {if(Ax>0) E[i].turn=4;else E[i].turn=5;}

        if(E[i].kind==5) E[i].blood=-1;//炮灰 ///////////
        if(E[i].kind==4){
            br++,B[br].x=X,B[br].y=Y;
            B[br].kind=4;///////
            B[br].life=1,B[br].enemy=E[i].enemy,B[br].endx=E[E[i].enemy].x,B[br].endy=E[E[i].enemy].y,B[br].staytime=0;
        }
        else{
        br++,B[br].x=X,B[br].y=Y;
        B[br].kind=E[i].kind;///////
        B[br].life=1,B[br].enemy=E[i].enemy,B[br].endx=M[E[i].enemy].x,B[br].endy=M[E[i].enemy].y,B[br].staytime=0;
        }

        E[i].CD=0;}
        }
        }Cout(i,2);
        }
    }
    for(int i=bl;i<=br;i++){
        if(B[i].life==0) continue;
        else if(B[i].kind>0)//对塔子弹 >0
        {
            B[i].staytime++;
            int k=B[i].enemy;
            int Mkl=M[k].life,Mkx=M[k].x,Mky=M[k].y;
            if(B[i].kind==4) Mkl=B[k].life,Mkx=B[k].x,Mky=B[k].y;
            if(k!=-1&&Mkl==1) B[i].endx=Mkx,B[i].endy=Mky;
            float kx=B[i].endx,ky=B[i].endy,X=B[i].x,Y=B[i].y;float Ax=kx-X,Ay=ky-Y,S=Bspeed[B[i].kind];float Dis=sqrt(Ax*Ax+Ay*Ay);float vx=Ax*S/Dis*1.0,vy=Ay*S/Dis*1.0;
            B[i].x+=vx,B[i].y+=vy;//别改，对的！ 
            if(Dis<=S){
                //打中了，减血 
                B[i].x=B[i].endx,B[i].y=B[i].endy;
                if(B[i].kind==1) Find_boomkill(i,1.5,0,20),Circle(B[i].endx,B[i].endy,-2,1);
                if(B[i].kind==2) Find_boomkill(i,1.5,0,10),Circle(B[i].endx,B[i].endy,-2,1);
                if(B[i].kind==3) Find_boomkill(i,3,0,20),Circle(B[i].endx,B[i].endy,-2,3);
                if(B[i].kind==4) Find_boomkill(i,2,1,-5),Circle(B[i].endx,B[i].endy,-2,2);
                if(B[i].kind==5) Find_boomkill(i,3,0,50),Circle(B[i].endx,B[i].endy,-2,3);//炮灰 
                if(B[i].kind==6) Find_boomkill(i,2,0,20),Circle(B[i].endx,B[i].endy,-2,2);
                B[i].life=0;continue;
            }
            Cout(i,3);
        }
        else//对人子弹 <0
        {
            B[i].staytime++;
            int k=B[i].enemy;if(k!=-1&&E[k].life==1) B[i].endx=E[k].x,B[i].endy=E[k].y;
            float kx=B[i].endx,ky=B[i].endy,X=B[i].x,Y=B[i].y;float Ax=kx-X,Ay=ky-Y,S=Bfspeed[-B[i].kind];float Dis=sqrt(Ax*Ax+Ay*Ay);float vx=Ax*S/Dis*1.0,vy=Ay*S/Dis*1.0;

            if(B[i].kind==-3){B[i].x+=1.0/(49.0-B[i].staytime)*Ax;B[i].y+=1.0/(49.0-B[i].staytime)*Ay;

            if(T%2==0){
            if(B[i].up==1){if(B[i].h<3) B[i].h++;else if(B[i].h<6) B[i].h+=0.5;else B[i].up++;}else if(B[i].up<=6) B[i].up++;else{if(B[i].h>3) B[i].h-=0.5;else B[i].h--;}}
            }
            else B[i].x+=vx,B[i].y+=vy;//抛物线
            if(B[i].kind==-3&&B[i].staytime>=48) {B[i].x=B[i].endx,B[i].y=B[i].endy,Find_boomkill(i,5,1,30),Circle(B[i].endx,B[i].endy,2,4);B[i].life=0;continue;}
            else if(B[i].kind!=-3&&Dis<=S)//打中了，减血 
            {
                if(B[br].kind==-2) B[i].endx+=rand()%7-3,B[i].endy+=rand()%7-3;//重机枪 
                B[i].x=B[i].endx,B[i].y=B[i].endy;
                if(B[i].kind==-1) Find_boomkill(i,2,1,20),Circle(B[i].endx,B[i].endy,2,2);
                if(B[i].kind==-2) Find_boomkill(i,2,1,20),Circle(B[i].endx,B[i].endy,2,2);
                if(B[i].kind==-4) Find_boomkill(i,2,1,5),Circle(B[i].endx,B[i].endy,2,2);
                if(B[i].kind==-5) Find_boomkill(i,3,1,120),Circle(B[i].endx,B[i].endy,2,3);
                if(B[i].kind==-6) Find_boomkill(i,3,1,40),Circle(B[i].endx,B[i].endy,2,3);
                B[i].life=0;continue;
            }
            Cout(i,4);
        }
    }
    Die();//开始处理 life=0,前面不要有 life=0 
}
void StartWar(int D)
{
  for(int i=-1;i<=(int)T/1000;i++){
    int XY=rand()%4,W=rand()%49+1,x,y,k,R=rand()%100;
    if(Level==2) XY=3;if(Level==3) XY=3*(rand()%2);
    if(XY==0) x=1,y=W;if(XY==1) x=49,y=W;if(XY==2) x=W,y=1;if(XY==3) x=W,y=49;
    k=rand()%6+1;///////////////////
    er++,E[er].x=x,E[er].y=y,E[er].kind=k,E[er].life=1,E[er].blood=Eblood[k]+Day;
  }
}
void Start()
{Color(0);
    Setpos(51,0),printf("┏━━┓┏━━┓┏━━┓┏━━┓┏━━┓┏━━┓");
    Setpos(52,0),printf("┃$100┃┃$120┃┃$150┃┃$180┃┃$200┃┃$250┃");
    Setpos(53,0),printf("┃ ● ┃┃ ■ ┃┃ ▲ ┃┃ ▼ ┃┃ ◆ ┃┃ ★ ┃");Setpos(53,30),printf("Money: %d     ",money);
    Setpos(54,0),printf("┗━━┛┗━━┛┗━━┛┗━━┛┗━━┛┗━━┛");Setpos(53,40),printf("Day: %d     ",Day);
}
void Click()
{
    int What;
    pt=Windowpos();
    if(pt.x<50||pt.y>25) return;
    else What=pt.y/4+1;
    if(What==1) if(money>=100) money-=100;else return;
    if(What==2) if(money>=120) money-=120;else return;
    if(What==3) if(money>=150) money-=150;else return;
    if(What==4) if(money>=180) money-=180;else return;
    if(What==5) if(money>=200) money-=200;else return;
    if(What==6) if(money>=250) money-=250;else return;
    Color(0),Setpos(53,30),printf("Money: %d     ",money);
    mr++;M[mr].x=25;M[mr].kind=What;M[mr].blood=Mblood[What];M[mr].life=1;M[mr].CD=MCDmax[What]-1;
    while(mouse)
    { 
        mouse=GetAsyncKeyState(VK_LBUTTON)&0x8000;
        pt=Windowpos();
        M[mr].x=min(48,max(2,(int)pt.x)),M[mr].y=min(48,max(2,(int)pt.y));
        Circle(M[mr].x,M[mr].y,1,mr);
        Move(2);Map(1);Sleep(30);
        for(int i=0;i<=8;i++) N(M[mr].x+Turn[i][0],M[mr].y+Turn[i][1],-1),N(M[mr].x+Turn[i][0],M[mr].y+Turn[i][1]+0.5,-1); 
        Circle(M[mr].x,M[mr].y,-1,mr);
    }
    system("cls");memset(n,-1,sizeof(n));memset(m,-1,sizeof(m));Start();
}
void Menu()
{
    system("mode con cols=50 lines=28");Print(1);Color(0);
    Setpos(5,7);cout<<"欢迎来到  海岛奇兵  ！";
    Setpos(7,12);cout<<"作者：w h s x";
    Setpos(10,2);cout<<"规则：鼠标拖动炮塔，可以自己摸索，进入地图后将窗口最大化";
    Setpos(12,5);cout<<"请选择地图：";Setpos(13,7);cout<<"1.围城  ";Setpos(14,7);cout<<"2.长城  ";Setpos(15,7);cout<<"3.王者  ";Setpos(16,7);cout<<"4.放射  ";Setpos(17,7);cout<<"5.真空（魔鬼难度）";
    A:char a=_getch();if(a<'1'||a>'5') goto A;else Level=a-'0';
    system("mode con cols=100 lines=56");Print(2);
}
int main(){
	SetConsoleTitle("海岛奇兵"); 
    CONSOLE_CURSOR_INFO cursor_info={1,0};SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);srand((unsigned)time(NULL));
    St:Menu();Start();
    memset(n,-1,sizeof(n));memset(m,-1,sizeof(m));memset(M,0,sizeof(M));memset(E,0,sizeof(E));memset(B,0,sizeof(B));
    T=ml=mr=el=er=bl=br=0;CDmax=160;Day=1;
    money=1000;if(Level==5) money=1500;
    mr++,M[mr].x=25,M[mr].y=25,M[mr].kind=0,M[mr].life=1,M[mr].blood=2000;
    if(Level==2) M[mr].y=2;
    if(Level==3) M[mr].x=48,M[mr].y=2;
if(Level==1) for(int i=0;i<=360;i+=30) mr++,M[mr].x=25+10*sin(3.1416*i/180),M[mr].y=25+10*cos(3.1416*i/180),-2,M[mr].kind=0,M[mr].life=1,M[mr].blood=500;
if(Level==2) for(int i=5;i<50;i+=6) mr++,M[mr].x=i,M[mr].y=20,M[mr].kind=0,M[mr].life=1,M[mr].blood=500,mr++,M[mr].x=i,M[mr].y=10,M[mr].kind=0,M[mr].life=1,M[mr].blood=500;
if(Level==3) for(int i=-90;i<=0;i+=45) mr++,M[mr].x=48+8*sin(3.1416*i/180),M[mr].y=2+8*cos(3.1416*i/180),-2,M[mr].kind=0,M[mr].life=1,M[mr].blood=500,mr++,M[mr].x=48+16*sin(3.1416*i/180),M[mr].y=2+16*cos(3.1416*i/180),-2,M[mr].kind=0,M[mr].life=1,M[mr].blood=500,mr++,M[mr].x=48+24*sin(3.1416*i/180),M[mr].y=2+24*cos(3.1416*i/180),-2,M[mr].kind=0,M[mr].life=1,M[mr].blood=500;
if(Level==4) for(int i=30;i<=390;i+=60) mr++,M[mr].x=25+8*sin(3.1416*i/180),M[mr].y=25+8*cos(3.1416*i/180),-2,M[mr].kind=0,M[mr].life=1,M[mr].blood=500,mr++,M[mr].x=25+15*sin(3.1416*i/180),M[mr].y=25+15*cos(3.1416*i/180),-2,M[mr].kind=0,M[mr].life=1,M[mr].blood=500;
    while(M[1].life==1)
    {
        T++;
        memset(n,-1,sizeof(n));//这里默认全输空格 
        //鼠标,键盘,暂停操作
        mouse=GetAsyncKeyState(VK_LBUTTON)&0x8000;
        pt=Windowpos();N(pt.x,pt.y,-2);
        if(mouse) Click();
        if(Day>=100) break;
        CD--;if(CD<=0){CD=CDmax;StartWar(Day);Day++;Setpos(53,40),printf("Day: %d     ",Day);}
            if(T%50==0) money=min(money+10,1000),Setpos(53,30),printf("Money: %d     ",money);
        Move(1);Map(1);Sleep(30);
    }
    if(Day>=100) {system("color 6E"),Sleep(1000);for(int i=1;i<=1000;i++) cout<<"YOU WIN !!  ";system("pause");system("color 0F");}
    else {system("color 7F"),Sleep(1000);for(int i=1;i<=1000;i++) cout<<"GAME OVER...  ";system("pause");system("color 0F");}
    system("cls");
    goto St;
    return 0;
}

