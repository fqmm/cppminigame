//# 战斗躲避游戏

#include<bits/stdc++.h>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
using namespace std;
typedef BOOL (WINAPI *PROCSETCONSOLEFONT)(HANDLE, DWORD);
PROCSETCONSOLEFONT SetConsoleFont;
POINT Windowpos(){POINT pt;GetCursorPos(&pt);HWND h=GetForegroundWindow();ScreenToClient(h,&pt);
pt.x=(pt.x+4)/8+0.5;pt.y=pt.y/16+0.5;//鼠标矫正此处 
swap(pt.x,pt.y);return pt;}
int mouse;POINT pt;
void Print(int a){HMODULE hKernel32 = GetModuleHandle("kernel32");SetConsoleFont = (PROCSETCONSOLEFONT)GetProcAddress(hKernel32,"SetConsoleFont");SetConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE),a);}
int ti(float a) {return ((int)(a*10+5))/10;}
void Setpos(float x,float y){COORD pos;pos.X=ti(y*4)/2;pos.Y=ti(x+2);SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);}
void Color(int a){if(a==0) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
if(a==-1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE);
                  if(a==-8) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED);if(a==1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
                  if(a==-11) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_GREEN|BACKGROUND_BLUE);if(a==2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);if(a==3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);if(a==4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
                  if(a==-5) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_GREEN);if(a==5) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);if(a==6) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
                  if(a==-6) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_BLUE);
                  if(a==7) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
                  if(a==8) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED);if(a==9) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_GREEN|BACKGROUND_BLUE);if(a==10) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_BLUE);if(a==11) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_BLUE);if(a==12) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_GREEN);if(a==13) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);if(a==14) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN|FOREGROUND_BLUE);}
void Slow(char *p,int a) {while(1){if(*p!=0) printf("%c",*p++);else break;Sleep(a);}} 

int to(float a) {if(a>0) return int(a+0.5);else if(a<0) return int(-a-0.5);if(a==0) return 0;}
float Sin(int a) {return sin(3.1416*a/180);}float Cos(int a) {return cos(3.1416*a/180);}
float Sin0(int a) {return sin(3.1416*a);}float Cos0(int a) {return cos(3.1416*a);}//多少pai 
//------------------------------------杂七杂八的图像函数------------------------------------
int m[51][101],n[51][101],s[51][101];////speacial
int bl,br,Life,level,T,Turnx,Turny,End,Lev,people,unkillT,unkillTmax,Tempty;
float X,X2,Y,Y2,speed=30,Attack=1,Anc,Anv,Anb,cMin,vMin,bMin,skillC,skillV,skillB,Blood,Bloodmax,EXP,EXPmax;

int D[2][5]={{0,1,-1,0,0},{0,0,0,-1,1}};//上下右左 
float Sx=18,Sy=60,Svx=0,Svy=0,Stx,Sty,Sr=0,Sm=0,Svmax=2,Srmax=5;
int Sleep_1,Sleep_1max,Sleep_2,Sleep_3;
int Bean,BeanBoo,BeanBoom,TimeStop,Thunder,ThunderTime,ThunderTurn,Crab;

struct bullet{float x,y,vx,vy,fx1,fx2,fx3;int w,t,k,l,ex1,ex2,ex3;//what,time,kill,life;
float maxsize,angle,maxangle,minangle,xr,ybig,ysmall,v; 
int turn,staytime,num,source;
}B[1000001];//改时别忘了Delete! 
void Delete_B(int i) {
B[i].x=B[i].y=B[i].vx=B[i].vy=B[i].fx1=B[i].fx2=B[i].fx3=B[i].w=B[i].t=B[i].k=B[i].l=B[i].ex1=B[i].ex2=B[i].ex3=0;
B[i].maxsize=B[i].angle=B[i].maxangle=B[i].minangle=B[i].xr=B[i].ybig=B[i].ysmall=B[i].v=B[i].turn=B[i].staytime=B[i].num=B[i].source=0;}
void S(float x,float y){int i=(int)x,j=(int)y;Setpos(i,j/2.0);printf("a");}
void C(float x,float y){int i=(int)x,j=(int)y;Setpos(i,j/2.0);//直接输出该点 
    if(n[i][j]==0) printf(" ");
    if(n[i][j]==1) Color(-1),printf(" ");
    //以下无伤 
    if(n[i][j]==-1) Color(-8),printf(" ");
    if(n[i][j]==-2) Color(-11),printf(" ");
    if(n[i][j]==-3) Color(-5),printf(" ");
    Color(0);
}
void Map(int a){if(a==1){for(register int i=1;i<=50;i++)for(register int j=1;j<=100;j++){if(n[i][j]!=m[i][j]){C(i,j);}}for(register int i=1;i<=50;i++)for(register int j=1;j<=100;j++){m[i][j]=n[i][j];}}}
//Map1：更新地图 
void N(float x,float y,int w){int xx=(int)x,yy=(int)y;//放置点在地图上
if(xx>40||yy>80||xx<1||yy<1) return;
else if(w<0&&n[xx][yy]>=1) return;//白色盖住红色 
else n[xx][yy]=w;}
void Die(){
    system("cls");system("color 0F");
    Slow("You Die !",50);
    system("color 3B");Sleep(10);system("cls");system("color 0F");}
void Win(){
    system("cls");
    for(register int i=0;i<=3;i++)
    {printf("You Win !");
        system("color 1A");Sleep(10);
        system("color 2B");Sleep(10);
        system("color 3C");Sleep(10);
        system("color 4D");Sleep(10);
        system("color 5D");Sleep(10);
        system("color 6E");Sleep(10);
        system("color 7F");Sleep(10);
    }printf("   好敷衍啊...");Lev=1;system("color 0F");Sleep(5000);system("cls");
}
void Circle(int x,int y,int r,int num,int start,int whatnumber,int source){if(r<0) return;if(r==0) num=1;int next=360/num;for(register int i=0;i<num;i++){br++;
    B[br].w=3;B[br].staytime=3;if(whatnumber==0) whatnumber=1;B[br].num=whatnumber;B[br].source=source;
    B[br].t=0;B[br].l=1;B[br].x=x+Sin(i*next+start)*r;B[br].y=y+2*Cos(i*next+start)*r;}}
void Rock_Circle(float x0,float y0,float xr,float ybig,int staytime,int source,int num){
    if(xr<0) return; 
for(register int i=x0-xr;i<=x0+xr;i++){float Ay=ybig*2*sqrt(xr*xr-(i-x0)*(i-x0));for(register float j=y0-Ay;j<y0+Ay;j++){br++;B[br].w=3;B[br].staytime=staytime;B[br].t=0;B[br].l=1;B[br].x=i;B[br].y=to(j);B[br].staytime=staytime;B[br].num=num;
if(num==-3) B[br].num=-2,B[br].ex2=1;
B[br].source=source;B[br].ex1=B[B[br].source].ex1;}}}
void Rock_line(float x0,float y0,float x,float y,int source){
    float Ax=x-x0,Ay=y-y0,R=sqrt(Ax*Ax+Ay*Ay);
    bool yy=0;
    if(Ax<0) swap(x,x0),swap(y,y0),Ax*=-1,Ay*=-1;if(Ay<0) yy=1;
    float ax=Ax/R*1.0,ay=Ay/R*1.0,j=y0,i=x0;
    while(i<=x&&((j<=y&&yy==0)||(j>=y&&yy==1)))
    {
        br++;B[br].w=3;B[br].t=0;B[br].l=1;B[br].x=to(i);B[br].y=to(j);
        B[br].staytime=to(R);B[br].source=source;B[br].num=B[source].num;
        if(source==-2) B[br].source=0,B[br].num=-2;
        i+=ax;j+=ay;
    }
}
void Circle_bomb(int x,int y,int number,int start,float speed,int source,int num){int next=360/number;for(register int i=0;i<number;i++){br++;B[br].w=2;B[br].t=0;B[br].l=1;B[br].source=source;B[br].num=num;
    B[br].vx=Sin(i*next+start)*speed;B[br].x=x-B[br].vx;
    B[br].vy=2*Cos(i*next+start)*speed;B[br].y=y-B[br].vy;
    }}
void Rand_put_Knife(int turn){
    br++;
B[br].w=1;
B[br].t=0;B[br].l=1;
B[br].x=X+rand()%10-5;
B[br].y=1;
B[br].staytime=3;
B[br].turn=turn;
B[br].angle=0+180*turn;
B[br].maxangle=180;B[br].minangle=0;
B[br].v=7;
if(turn==1) B[br].v*=-1;
B[br].ybig=(rand()%25)/10.0+4;//3 导轨扁度 2为圆 
B[br].ysmall=0.01;// ybig* ysmall=刀光横宽倍数  0.25为圆 
B[br].maxsize=0.01;//刀光纵宽
B[br].xr=(rand()%5-2+(Y-B[br].y))/B[br].ybig*1.0;//导轨大小 
}
void Put_Round_Bullet(int ex,float v){//1:反伤 
for(register int i=0;i<=v*4;i+=5) {br++;B[br].w=5;B[br].t=0;B[br].l=1;B[br].x=X;B[br].y=Y;B[br].angle=i+110;B[br].maxangle=600;
B[br].v=60-(int)v;
B[br].staytime=3;B[br].xr=3+v/10.0;
if(ex==1) B[br].ex1=1;
}if(v>=27)
for(register int i=0;i<=v*4;i+=5) {br++;B[br].w=5;B[br].t=0;B[br].l=1;B[br].x=X;B[br].y=Y;B[br].angle=i+110;B[br].maxangle=600;
B[br].v=60-(int)v;
B[br].staytime=3;B[br].xr=4+v/10.0;
if(ex==1) B[br].ex1=1;
}
}
void Rand_put_Bullet(){
    br++;
B[br].w=2;
B[br].t=0;B[br].l=1;
B[br].x=rand()%40;
B[br].y=1;
B[br].vy=(rand()%25+25)/15.0;
}
void put_Bullet(float x,float y,float vx,float vy,int num){
    vx/=2.0;
if(vy!=0) {br++;B[br].w=2;B[br].t=0;B[br].l=1;B[br].x=x;B[br].y=y-1;B[br].vx=vx;B[br].vy=vy;B[br].num=num;if(num==-4) num=-2,B[br].maxsize=5;}
br++;B[br].w=2;B[br].t=0;B[br].l=1;B[br].x=x;B[br].y=y;B[br].vx=vx;B[br].vy=vy;B[br].num=num;if(num==-4) num=-2,B[br].maxsize=5;}
void Rand_sin_Bullet(){
    br++;
B[br].w=6;
B[br].t=0;B[br].l=1;
B[br].x=rand()%40;
B[br].y=1;
B[br].vy=(rand()%25+25)/15.0;B[br].staytime=10;
B[br].angle=0;B[br].xr=3;B[br].v=(rand()%125+25)/2.0;
}
void Rand_back_Bullet(){
    br++;
B[br].w=7;
B[br].t=0;B[br].l=1;
B[br].x=rand()%40;
B[br].y=1;
B[br].ybig=80-(rand()%5)/2.0;
}
void Rand_brouce_Bullet(){//ex2:弹跳数 
    br++;
B[br].w=8;
B[br].t=0;B[br].l=1;
B[br].x=rand()%40;
B[br].y=1;
B[br].vy=(rand()%25+25)/15.0;
B[br].vx=(rand()%50-25)/15.0;
B[br].xr=(rand()%15)/10.0+1.5;
B[br].ex2=3;
}
void Put_brouce_Bullet(int a,float x,float y,float vx,float vy,float ex2){
    vy*=2;
if(a==0) {br++;B[br].w=8;B[br].t=0;B[br].l=1;B[br].x=x;B[br].y=y;B[br].vx=vx;B[br].vy=vy;B[br].xr=1.5;B[br].num=-3;B[br].ex2=ex2;}
if(a==1) Put_brouce_Bullet(0,X,Y,0,-1.5,0);
if(a==2) Put_brouce_Bullet(0,X,Y,0,-2,5),Put_brouce_Bullet(0,X,Y,0,2,5),Put_brouce_Bullet(0,X,Y,-2,0,5),Put_brouce_Bullet(0,X,Y,2,0,5),Put_brouce_Bullet(0,X,Y,-1.414,1.414,5),Put_brouce_Bullet(0,X,Y,-1.414,-1.414,5),Put_brouce_Bullet(0,X,Y,1.414,1.414,5),Put_brouce_Bullet(0,X,Y,1.414,-1.414,5);
if(a==3) for(int i=1;i<=1;i++) Put_brouce_Bullet(0,X+2.5-rand()%50/10,Y+5-rand()%100/10,0,-1-rand()%25/10,0);
}
void Hurt(int x,int y,int ex){
    br++;
B[br].w=4;
B[br].t=0;B[br].l=1;
B[br].x=x;
B[br].y=y;
if(ex==1) B[br].staytime=3,B[br].v=1,B[br].num=-1;//伤 
if(ex==2) B[br].staytime=5,B[br].v=5,B[br].num=-3;//清 
}
void Level_Bullet(){
    if(T<=50&&T%5==0) Rand_put_Bullet();else if(T<=100) return;
    else if(T<=150&&T%5==0) Rand_put_Knife(T%2);else if(T<=200) return;
    else if(T<=250&&T%7==0) Rand_sin_Bullet();else if(T<=300) return;
    else if(T<=350&&T%7==0) Circle_bomb(20,40,15,T%15,2,0,1);else if(T<=400) return;
    else if(T<=450&&T%7==0) Rand_back_Bullet();else if(T<=500) return;
    else if(T<=550&&T%10==0) Rand_brouce_Bullet();else if(T<=600) return;
    else if(T<=1000){if(T%5==0) Rand_put_Bullet();if(T%21==0) Rand_put_Knife(T%2);if(T%39==0) Rand_sin_Bullet();if(T%90==0) Circle_bomb(20,40,15,T%15,2,0,1);if(T%18==0) Rand_back_Bullet();if(T%34==0) Rand_brouce_Bullet();}
    else if(T<=2000){if(T%6==0) Rand_put_Bullet();if(T%17==0) Rand_put_Knife(T%2);if(T%23==0) Rand_sin_Bullet();if(T%60==0) Circle_bomb(20,40,15,T%15,2,0,1);if(T%9==0) Rand_back_Bullet();if(T%28==0) Rand_brouce_Bullet();}
    else {if(T%10==0) Rand_put_Bullet();if(T%13==0) Rand_put_Knife(T%2);if(T%9==0) Rand_sin_Bullet();if(T%40==0) Circle_bomb(20,40,15,T%15,2,0,1);if(T%8==0) Rand_back_Bullet();if(T%27==0) Rand_brouce_Bullet();}
}
void Move_bullet(){
    for(register int i=bl;i<=br;i++){
        if(B[bl].l==0) bl++;
        if(B[i].l==1&&TimeStop==0) B[i].t++;else continue;
    bool del;
        float x=B[i].x,y=B[i].y,vx=B[i].vx,vy=B[i].vy,fx1=B[i].fx1,fx2=B[i].fx2,fx3=B[i].fx3;
        int w=B[i].w,t=B[i].t,k=B[i].k,ex1=B[i].ex1,ex2=B[i].ex2,ex3=B[i].ex3;
    float maxsize=B[i].maxsize,angle=B[i].angle,maxangle=B[i].maxangle,minangle=B[i].minangle,xr=B[i].xr,ybig=B[i].ybig,ysmall=B[i].ysmall,v=B[i].v,turn=B[i].turn;
    int staytime=B[i].staytime,num=B[i].num,source=B[i].source;
        //what,time,kill,life;简化 
//    if(level==1){
        if(Sleep_1==0&&s[to(x)][to(y)]>=1&&s[to(x)][to(y)]<=2&&w==3&&ex1!=1&&num>=0&&num<=1) {Delete_B(source),del=1,Delete_B(i);EXP+=0.3;if(people!=4) Sleep_1=1;
    if(s[to(x)][to(y)]==1){B[i].w=2;B[i].t=0;B[i].l=1;B[i].num=-2;B[i].x=x;B[i].y=y;B[i].vx=to(x)-X;B[i].vy=to(y)-Y;B[i].vx/=2,B[i].vy/=2;B[i].ex1=1;B[i].staytime=2;}
        }

        if(w==1){//maxsize,angle,rx,ybig,v,x0,y0; 
        if(angle>maxangle||angle<minangle) {del=1,Delete_B(i);
        continue;}
        else {int v0=2;float a=angle;
        for(register int A=min(a+v0,a+v+v0);A<max(a+v0,a+v+v0);A+=v0)
        {
        angle+=v0;
        float rsmall=0.1;
        float y1=y+xr*ybig*Sin(angle)*1.0;
        float x1=x+xr*Cos(angle)*1.0;
        float R=1+rsmall*maxsize*Sin(angle)*1.0;
        Rock_Circle((int)x1,(int)y1,to(R),ybig*ysmall,staytime,i,1);
        }if(TimeStop==0) angle=a+v;}
        }//刀 
        if(w==2){
        if(x>40||y>80||x<1||y<1||(abs(vx)<=0.1&&abs(vy)<=0.1)||(people==4&&t>=6&&num<0)) {del=1,Delete_B(i);continue;}
        else {Rock_line(x,y,x+vx,y+vy,i);
        if(ex1==1) vx*=0.9,vy*=0.9;
        if(TimeStop==0) x+=vx,y+=vy;
        }}
        if(w==3) {
        if(ex2==1&&m[to(x)][to(y)]>0&&Sleep_2==0) Delete_B(source),Sleep_2=1;
        if(x>40||y>80||x<1||y<1||t>=staytime||(ex2==1&&m[to(x)][to(y)]>0&&Sleep_2==0)) {del=1,Delete_B(i),N(x,y,0);if(ex1==1||num==-2) s[to(x)][to(y)]=0;continue;}
        if(num!=0) N(x,y,num);
        else N(x,y,1);
        if(ex1==1) s[to(x)][to(y)]=1;else if(num==-2) s[to(x)][to(y)]=2;
        }//残影
        if(w==4){//Hurt
        Circle(x,y,1+t*v,90,1,num,i);if(t>=staytime) del=1,Delete_B(i);
        }
        if(w==5){//Round
        if(angle>maxangle||angle<minangle) {del=1,Delete_B(i);continue;}
        for(register int a=angle;a<angle+v;a+=3){Rock_Circle((int)(X+Sin(a)*xr),(int)(Y+2*Cos(a)*xr),1,0.5,staytime,i,-2);}
        if(TimeStop==0) angle+=v;
        }
        if(w==6){//Sin
        if(x>40||y>80||x<1||y<1) {del=1,Delete_B(i);continue;}
        for(register int a=angle;a<angle+v;a+=3){Rock_Circle((int)(x+Sin(a)*xr),(int)y,1,0.5,staytime,i,1);
        }if(TimeStop==0) angle+=v,x+=vx,y+=vy;
        }
        if(w==7){//Back
        if(x>40||x<1||y<1) {del=1,Delete_B(i);continue;}
        vy=(ybig-y)/10.0+0.2;if(turn==1) vy*=-1;
        if(TimeStop==0) x+=vx,y+=vy;
        if(y>=ybig) turn=1;
        if(turn==0) Rock_line(x,y,x,y+3,i),Rock_line(x-1,y,x-1,y-2,i),Rock_line(x+1,y,x+1,y-2,i);
        else Rock_line(x,y,x,y-3,i),Rock_line(x-1,y,x-1,y+2,i),Rock_line(x+1,y,x+1,y+2,i);
        }
        if(w==8){//Brouce
        if(x>40||y>80||x<1||y<1) {if(x<1) x=1,vx*=-1;if(x>40) x=40,vx*=-1;if(y<1) y=1,vy*=-1;if(y>80) y=80,vy*=-1;ex2--;}
        if(ex2<0) {del=1,Delete_B(i),N(x,y,0);continue;}
        Rock_Circle(x,y,xr,1,2,i,num);
        if(TimeStop==0) x+=vx,y+=vy;
        }
        if(w==9){//Crab_Attack
        vx=rand()%15-7,vy=rand()%29-14;if(ex1==3) vx=rand()%11-5,vy=rand()%11-5;if(ex1==2) vx=rand()%5+2;
        if(TimeStop==0) {float xx=fmax(fmin(x+vx,39),1),yy=fmax(fmin(y+vy,80),1);Rock_line(x,y,xx,yy,-2);x=xx,y=yy;
        if(ex1==3) X=to(x),Y=to(y),unkillT=2,Crab=1;}
        if(x>=39||y>=80||x<=1||y<=1) {del=1,Delete_B(i);if(ex1==3) Crab=2;continue;}
        }
        //    }
    if(del==0){//事实上不用，有continue了 
        B[i].x=x,B[i].y=y,B[i].vx=vx,B[i].vy=vy;B[i].fx1=fx1,B[i].fx2=fx2,B[i].fx3=fx3;
        B[i].w=w,B[i].t=t,B[i].k=k;B[i].ex1=ex1,B[i].ex2=ex2,B[i].ex3=ex3;

    B[i].maxsize=maxsize,B[i].angle=angle,B[i].maxangle=maxangle,B[i].minangle=minangle,B[i].xr=xr,B[i].ybig=ybig,B[i].ysmall=ysmall,B[i].v=v,B[i].turn=turn;
    B[i].staytime=staytime,B[i].num=num,B[i].source=source;
    }//回复 dd
      }
    if(bl>br) bl=br=0,memset(B,0,sizeof(B));
}
void Scissor(){
        if(Stx!=0&&Svx>=0) Svx=max(Svx/2+Stx/10,Svx+Stx/20);
        else if(Stx!=0&&Svx<0) Svx*=-1,Stx*=-1,Svx=max(Svx/2+Stx/10,Svx+Stx/20),Svx*=-1;
        else Svx*=0.9;
        if(Sty!=0&&Svy>=0) Svy=max(Svy/2+Sty/10,Svy+Sty/20);
        else if(Sty!=0&&Svy<0) Svy*=-1,Sty*=-1,Svy=max(Svy/2+Sty/10,Svy+Sty/20),Svy*=-1;
        else Svy*=0.9;
        Svx=max(-Svmax,min(Svmax,Svx));Svy=max(-Svmax,min(Svmax,Svy));
        Sx+=Svx*1.8,Sy+=Svy*1.8;
        Srmax=fmin(1+1.7*sqrt((Svx*Svx)+(Svy*Svy)),2+sqrt((Svx*Svx)+(Svy*Svy)));
        if(Sx<1) Sx=1,Svx*=-0.6;
        if(Sx>39) Sx=39,Svx*=-0.6;
        if(Sy<1) Sy=1,Svy*=-0.6;
        if(Sy>80) Sy=80,Svy*=-0.6;

        Sr=fmax(0,Sr-0.03);//摩擦 
        Rock_Circle(Sx,Sy,1+Sr,1,3,0,-2);
}
void Thunder_step(int x0,int y0,float l,int tx,int ty){
    int tt=tx+ty*4,e=0;
    for(register float i=X-3;i<=X+1;i++) for(register float j=Y-8;j<=Y+8;j++) C(i,j);
    if(X<=1||X>=39||Y<=1||Y>=80) e=1;
    X+=l*tx;Y+=2*l*ty;unkillT=2;
    if((X<1||X>39||Y<1||Y>80)&&e==1) {X=x0,Y=y0;return;}
    if(Thunder>0&&tt!=ThunderTurn&&tt!=0) Thunder--,ThunderTurn=tt;
    X=max(min((int)X,39),1),Y=max(min((int)Y,80),1);
    Rock_line(x0,y0,X,Y,-2);
}
void Crab_Attack(int x,int y,int a){
    br++;
B[br].w=9;
B[br].t=0;B[br].l=1;
B[br].x=x;
B[br].y=y;
B[br].ex1=a;
}
void Start_level(){level=1;
    system("cls"); 
Slow("  Ready ?! .................. Start !     ",50);
    memset(B,0,sizeof(B));memset(m,0,sizeof(m));memset(n,0,sizeof(n));memset(s,0,sizeof(s));
    bl=br=0;
    X=20,Y=70;
    T=0;Life=1;Blood=Bloodmax;unkillTmax=2;Tempty=1000;
    int an,An,kill,Stop;Turnx=1;Anc=Anv=Anb=unkillT=0;
    while(Life==1&&Lev<10)
    {
        T++;an=0;if(End>0) End--;
        Sleep_1=Sleep_2=0;
        if(GetAsyncKeyState(VK_UP)&0x8000) Turnx=1,an=1;
        else if(GetAsyncKeyState(VK_DOWN)&0x8000) Turnx=2,an=1;
        else Turnx=0;
        if(GetAsyncKeyState(VK_RIGHT)&0x8000) Turny=3,an=1;
        else if(GetAsyncKeyState(VK_LEFT)&0x8000) Turny=4,an=1;
        else Turny=0;
        if(an==1) An++;if(an==0&&An>0) An=0,Turnx=Turny=0,an=1;

    if(people==1) {   if(GetAsyncKeyState(67)&0x8000) {if(Anc==0) Anc=1;Anc=min(9.9,Anc+0.05);}else{if(Anc<0) Anc+=0.02;if(Anc>-0.5&&Anc<0.5) Anc=0,Setpos(X-2,Y/2-2),printf("   ");if(Anc>0) {int cy=Turny;if(Turnx==0&&Turny==0) cy=3;put_Bullet(X,Y,D[0][Turnx]*(Anc+2),D[1][cy]*(Anc+2),-2);Anc=cMin;}}
        if(GetAsyncKeyState(86)&0x8000) {if(Anv==0) Anv=1;Anv=min(9.9,Anv+0.05);}else{if(Anv<0) Anv+=0.02;if(Anv>-0.5&&Anv<0.5) Anv=0,Setpos(X-2,Y/2),printf("     ");if(Anv>0) {Put_Round_Bullet(1,(int)(20+Anv));Anv=vMin;}}
        if(GetAsyncKeyState(66)&0x8000) {if(Anb==0) Anb=1;Anb=min(9.9,Anb+0.05);}else{if(Anb<0) Anb+=0.02;if(Anb>-0.5&&Anb<0.5) Anb=0,Setpos(X-2,Y/2+2),printf("     ");if(Anb>0) {unkillT=5;int nb=(int)(Anb*3);Circle_bomb(X,Y,(nb+3),rand()%(nb+3),Anc*0.1+2,0,-2);Anb=bMin;}}
    }
    if(people==2) {if(GetAsyncKeyState(87)&0x8000) Stx=-1;else if(GetAsyncKeyState(83)&0x8000) Stx=1;else Stx=0;if(GetAsyncKeyState(68)&0x8000) Sty=1;else if(GetAsyncKeyState(65)&0x8000) Sty=-1;else Sty=0;
        if((GetAsyncKeyState(90)&0x8000)||(GetAsyncKeyState(88)&0x8000)) Sr=min(Sr+1,Srmax);//转速 X
        Scissor();
    }
    if(people==3) {
        if(GetAsyncKeyState(86)&0x8000) {if(Anv==0) Anv=1;Anv=min(9.9,Anv+0.05);}else{if(Anv<0) Anv+=0.02;if(Anv>-0.5&&Anv<0.5) Anv=0,Setpos(X-2,Y/2),printf("     ");if(Anv>0) {BeanBoo=8;Anv=vMin;}}
        if(GetAsyncKeyState(66)&0x8000) {if(Anb==0) Anb=1;Anb=min(9.9,Anb+0.05);}else{if(Anb<0) Anb+=0.02;if(Anb>-0.5&&Anb<0.5) Anb=0,Setpos(X-2,Y/2+2),printf("     ");if(Anb>0) {BeanBoom=30;Anb=bMin;}}
    if(BeanBoom>0) Put_brouce_Bullet(3,0,0,0,0,0),BeanBoom--;
    if(BeanBoo>0) BeanBoo--;if(BeanBoo%6==1) Put_brouce_Bullet(2,0,0,0,0,0);
    if(Bean>0) Bean--;if(Bean<=0) Put_brouce_Bullet(1,0,0,0,0,0),Bean=20;
    }
    if(people==4) {Sleep_3=0;
        if((GetAsyncKeyState(67)&0x8000)||(GetAsyncKeyState(86)&0x8000)){if(Anc==0) Anc=1;Anc=min(9.9,Anc+0.05);
        if(Anc>0&&Sleep_3<=2) {Sleep_3++;put_Bullet(X,Y,-3+rand()%60/10,-4-rand()%10/20,-4);Anc=0;if(TimeStop==0) Anc=cMin;}}else{if(Anc<0) Anc+=0.02;if(Anc>-0.5&&Anc<0.5) Anc=0,Setpos(X-2,Y/2-2),printf("   ");}
        if(GetAsyncKeyState(66)&0x8000) {if(Anb==0) Anb=1;Anb=min(9.9,Anb+0.05);}else{if(Anb<0) Anb+=0.02;if(Anb>-0.5&&Anb<0.5) Anb=0,Setpos(X-2,Y/2+2),printf("     ");
        if(Anb>0) {TimeStop=50;unkillT=50;Anb=bMin;}}if(TimeStop>0) TimeStop--;
    }
    if(people==5) {   if(GetAsyncKeyState(67)&0x8000) {if(Anc==0) Anc=1;Anc=min(9.9,Anc+0.05);}else{if(Anc<0) Anc+=0.02;if(Anc>-0.5&&Anc<0.5) Anc=0,Setpos(X-2,Y/2-2),printf("   ");
    if(Anc>0) {int cy=Turny;if(Turnx==0&&Turny==0) cy=4;Thunder_step(X,Y,3*Anc+4,-D[0][Turnx],-D[1][cy]);Anc=cMin;}}
        if(GetAsyncKeyState(86)&0x8000) {if(Anv==0) Anv=1;Anv=min(9.9,Anv+0.05);}else{if(Anv<0) Anv+=0.02;if(Anv>-0.5&&Anv<0.5) Anv=0,Setpos(X-2,Y/2),printf("     ");if(Anv>0) {Thunder=6;Anv=vMin;}}
        if(GetAsyncKeyState(66)&0x8000) {if(Anb==0) Anb=1;Anb=min(9.9,Anb+0.05);}else{if(Anb<0) Anb+=0.02;if(Anb>-0.5&&Anb<0.5) Anb=0,Setpos(X-2,Y/2+2),printf("     ");if(Anb>0) {ThunderTime=30;Anb=bMin;}}
    if(ThunderTime>0) ThunderTime--;if(an==0) ThunderTurn=0;
    }
    if(people==6) {   if(GetAsyncKeyState(67)&0x8000) {if(Anc==0) Anc=1;Anc=min(9.9,Anc+0.05);}else{if(Anc<0) Anc+=0.02;if(Anc>-0.5&&Anc<0.5) Anc=0,Setpos(X-2,Y/2-2),printf("   ");
    if(Anc>0) {Crab_Attack(X,Y,1),Anc=cMin;}}
        if(GetAsyncKeyState(86)&0x8000) {if(Anv==0) Anv=1;Anv=min(9.9,Anv+0.05);}else{if(Anv<0) Anv+=0.02;if(Anv>-0.5&&Anv<0.5) Anv=0,Setpos(X-2,Y/2),printf("     ");if(Anv>0) {Crab_Attack(1,rand()%59+10,2);Anv=vMin;}}
        if(GetAsyncKeyState(66)&0x8000) {if(Anb==0) Anb=1;Anb=min(9.9,Anb+0.05);}else{if(Anb<0) Anb+=0.02;if(Anb>-0.5&&Anb<0.5) Anb=0,Setpos(X-2,Y/2+2),printf("     ");if(Anb>0) {Crab_Attack(X,Y,3);Anb=bMin;}}
    Crab=0;}
    //操作
    if(TimeStop==0) Level_Bullet();
    if(TimeStop==0&&Tempty>0) Tempty--;
        else if(Tempty==0) Tempty=500,system("cls"),memset(B,0,sizeof(B)),memset(m,0,sizeof(m)),memset(n,0,sizeof(n)),memset(s,0,sizeof(s)),bl=br=0,Hurt(20,40,2);
//    //放子弹
    Move_bullet();
    if(Crab==2) system("cls"),Map(1); 
    if(an==1||kill==1||T<=2){
    if(Thunder!=0||ThunderTime!=0){Thunder_step(X,Y,5,-D[0][Turnx],-D[1][Turny]);}
    for(register float i=X-3;i<=X+1;i++) for(register float j=Y-8;j<=Y+8;j++) C(i,j);
    if(Turnx==1) X--;if(Turnx==2) X++;if(Turny==3) Y+=2;if(Turny==4) Y-=2;
            X=fmax(fmin(X,39),1),Y=fmax(fmin(Y,80),1);//你的位置更新 
if(TimeStop>0) Color(1+rand()%5);else if(unkillT>0) Color(8);else Color(1);
        if(Turnx==1||(Turnx==0&&Turny==0)) {Setpos(X-1,Y/2.0),printf("o"),Setpos(X,Y/2.0-0.5),printf("/+\\"),Setpos(X+1,Y/2.0);if(An%2==0) printf("A");else printf("H");}
        else if(Turnx==2) {Setpos(X-1,Y/2.0),printf("o"),Setpos(X,Y/2.0-0.5),printf("\\+/"),Setpos(X+1,Y/2.0);if(An%2==0) printf("A");else printf("H");}
        else if(Turny==3) {Setpos(X-1,Y/2.0+0.5),printf("o"),Setpos(X,Y/2.0-0.5),printf("-+"),Setpos(X+1,Y/2.0-0.5);if(An%2==0) printf("/>");else printf("v|");}
        else if(Turny==4) {Setpos(X-1,Y/2.0-0.5),printf("o"),Setpos(X,Y/2.0),printf("+-"),Setpos(X+1,Y/2.0);if(An%2==0) printf("<\\");else printf("|v");}
    }
    if(skillC==1&&Anc!=0&&Crab==0) Color(1),Setpos(X-2,Y/2-2),printf("C%0.1f   ",Anc);
    if(ThunderTime>0) Color(1+rand()%2*4),Setpos(X-2,Y/2),printf("%d  ",ThunderTime);
    else if(Thunder>0) Color(1+rand()%2*4),Setpos(X-2,Y/2),printf("%d  ",Thunder);
    else if(skillV==1&&Anv!=0&&Y<=76&&Crab==0) Color(2),Setpos(X-2,Y/2),printf("V%0.1f   ",Anv);
    if(TimeStop>0) Color(1+rand()%5),Setpos(X-2,Y/2+2),printf("%d  ",TimeStop);
    else if(skillB==1&&Anb!=0&&Y<=73&&Crab==0) Color(5),Setpos(X-2,Y/2+2),printf("B%0.1f   ",Anb);

    if(T%15==0) Blood=min(Blood+1,Bloodmax);
    if(unkillT<=0) for(register int i=0;i<=4;i++) if(n[(int)X+D[0][i]][(int)Y+D[1][i]]>=1) {Blood-=Attack,kill=1;Hurt(X,Y,1);unkillT=unkillTmax;}
    if(unkillT>0) unkillT--;
    if(EXP>EXPmax) Lev++,EXP=0,Blood*=1.4,Bloodmax*=1.1,EXPmax*=1.5,speed*=0.95,Attack*=1.1;
    Setpos(-1,1),Color(0),printf("T: %d ",T);
    Setpos(-1,5),printf("Level: %d ",Lev);
    Setpos(-1,10),printf("Blood: %d (/%d) ",(int)Blood,(int)Bloodmax);
    Setpos(-1,20),printf("EXP: %d (/%d) ",(int)EXP,(int)EXPmax);
    Setpos(-1,28),printf("距离清场时间还有 %d  ",Tempty);
    if(Blood<1) Life=0;
//判定死亡
        Map(1);
        Sleep(speed);
    }
    if(Lev>=10) system("color 6E"),Sleep(1000),Win();
    else system("color 7F"),Sleep(1000),Die();
}
void Interface(){
    system("cls"); Color(5);
    Setpos(0,9),printf("EASY GAME ",5);
    Setpos(1,3),printf("■■■■    作者：whsx            ■■■");
    Setpos(2,3),printf("■                               ■");
    Setpos(3,3),printf("■■■■   ■     ■■ ■ ■     ■  ■■  ■     ■  ■    ■■");
    Setpos(4,3),printf("■        ■■ ■ ■ ■ ■       ■    ■ ■■   ■ ■ ■  ■■■");
    Setpos(5,3),printf("■■■■ ■  ■ ■■    ■        ■■■ ■  ■ ■  ■  ■  ■■■");
    Color(0),Setpos(7,3),printf("                                                             ",10);
    Color(1),Setpos(11,3),Slow("按 C 修改角色/查看规则，",5);Color(3),Slow(" V 调整速度，",5);Color(-5),Slow(" Y",5);Color(5),Slow(" 开始游戏",5);
    Color(4),Setpos(13,3),Slow("注：因为此游戏运行程序较繁琐，容易卡，建议先调整速度！",5);
    Color(0),Setpos(28,0),printf("                             ");
}
void Time_check(){
    system("cls");
    Setpos(-1,1);Slow("  现在开始速度调整，按 C 加速， V 减速， B 退出",30);
    while(1)
    {if(kbhit()){char g=_getch();if(g=='c') speed*=0.95;else if(g=='v') speed*=1.05;else if(g=='b') break;}
        T++;if(T%2==0) Rand_put_Bullet(); 
    Setpos(-1,0),Color(0),printf("Speed: %0.3f   ",speed);Map(1);Move_bullet();Sleep(speed);} 
    Interface();
}
void Rules(){
    system("cls"); 
    Setpos(1,1),Slow("选择你的角色！ ",10);
    Setpos(3,1),Slow("输入：1.Ke  2.伍六七  3.豌豆  4.DIO  5.善逸  6.Crab_Dave",10);
    while(1){
    if(kbhit()){char a=_getch();
    if(a=='1'){system("cls");
    Setpos(1,1),Slow("↑↓←→操作躲避子弹，活下去。",10);
    Setpos(3,1),Slow("角色名称：Ke",10);
    Setpos(5,1),Slow("角色编号：1",10);people=1;
    Setpos(7,1),Slow("技能：",10);
    Color(1),Setpos(9,1),Slow("C ：遁之子弹（走路时反向发射，冷却时间：快） ",10);skillC=1;cMin=-1;
    Color(3),Setpos(11,1),Slow("V ：护体神盾（有几率反弹子弹！冷却时间：中）",10);skillV=1;vMin=-5;
    Color(5),Setpos(13,1),Slow("B ：元气烟花（无敌升级清场神器！冷却时间：慢）",10);skillB=1;bMin=-9;
    Setpos(15,1),Slow("所有技能，按的时间越久，威力越强！",10);break;}
    else if(a=='2'){system("cls");
    Setpos(1,1),Slow("↑↓←→操作躲避子弹，活下去。",10);
    Setpos(3,1),Slow("角色名称：伍六七",10);
    Setpos(5,1),Slow("角色编号：2",10);people=2;
    Setpos(7,1),Slow("技能：",10);
    Color(1),Setpos(9,1),Slow("AWSD （左手）操作剪刀！",10);skillC=0;
    Color(3),Setpos(11,1),Slow("Z或X ：提升转速，加大范围！",10);skillV=0;
    Color(5),Setpos(13,1),Slow("速度越快，最大范围越大！",10);skillB=0;break;}
    else if(a=='3'){system("cls");
    Setpos(1,1),Slow("↑↓←→操作躲避子弹，活下去。",10);
    Setpos(3,1),Slow("角色名称：豌豆",10);
    Setpos(5,1),Slow("角色编号：3",10);people=3;
    Setpos(7,1),Slow("技能：",10);
    Color(1),Setpos(9,1),Slow("被动 ：发射无穿透性的豌豆",10);skillC=0;
    Color(3),Setpos(11,1),Slow("V ：自动发球机（连续八方向发射豌豆！冷却时间：中）",10);skillV=1;vMin=-4;
    Color(5),Setpos(13,1),Slow("B ：能量豆（你懂的，无敌升级清场神器！冷却时间：慢）",10);skillB=1;bMin=-6;break;}
    else if(a=='4'){system("cls");
    Setpos(1,1),Slow("↑↓←→操作躲避子弹，活下去。",10);
    Setpos(3,1),Slow("角色名称：DIO",10);
    Setpos(5,1),Slow("角色编号：4",10);people=4;
    Setpos(7,1),Slow("技能：",10);
    Color(1),Setpos(9,1),Slow("C或V ：木大直拳（冷却时间：快，时停中极快）",10);skillC=1;cMin=-0.6;
    Color(5),Setpos(13,1),Slow("B ：砸瓦鲁多（你懂的！冷却时间：慢）",10);skillB=1;bMin=-8;break;}
    else if(a=='5'){system("cls");
    Setpos(1,1),Slow("↑↓←→操作躲避子弹，活下去。",10);
    Setpos(3,1),Slow("角色名称：善逸",10);
    Setpos(5,1),Slow("角色编号：5",10);people=5;
    Setpos(7,1),Slow("技能：",10);
    Color(1),Setpos(9,1),Slow("C ：雷霆一步（按得越久冲的越远！冷却时间：快）",10);skillC=1;cMin=-1;
    Color(3),Setpos(11,1),Slow("V ：六连（获得六次瞬移机会！冷却时间：中）",10);skillV=1;vMin=-4;
    Color(5),Setpos(13,1),Slow("B ：化雷（短时获得无限瞬移机会！冷却时间：慢）",10);skillB=1;bMin=-6;break;}
    else if(a=='6'){system("cls");
    Setpos(1,1),Slow("↑↓←→操作躲避子弹，活下去。",10);
    Setpos(3,1),Slow("角色名称：Crab_Dave",10);
    Setpos(5,1),Slow("角色编号：6",10);people=6;
    Setpos(7,1),Slow("技能：",10);
    Color(1),Setpos(9,1),Slow("C ：概率波（用后就知道了hhh~！冷却时间：中）",10);skillC=1;cMin=-3;
    Color(3),Setpos(11,1),Slow("V ：瞬闪柱（贯穿全场的攻击！冷却时间：中）",10);skillV=1;vMin=-5;
    Color(5),Setpos(13,1),Slow("B ：波函动（化为波，短时获得无限瞬移机会！冷却时间：慢）",10);skillB=1;bMin=-8;
    Setpos(15,1),Slow("一直想编一个攻击全看脸的角色呢hhh~",10);break;}
    }}
    Color(5),Setpos(17,1),Slow("所有技能，击中后会增加 EXP ，EXP 满后可以升级！",10);
    Setpos(19,1),Slow("到达 10 级 即可通关！（你的 EXP 可以保留至下一局）",10);
    Setpos(21,1),system("pause");
}
int main()
{
    system("mode con cols=82 lines=44");
    CONSOLE_CURSOR_INFO cursor_info={1,0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
    srand((unsigned)time(NULL));Color(0); 
Rules();
    sxs: Interface();
    while(1) if(kbhit()){
        char g=_getch();
        if(g=='c') {Rules();Interface();}
        else if(g=='v') {Time_check();Interface();}
        else if(g=='y') {
        Lev=1;Blood=Bloodmax=100;EXPmax=30,EXP=0;Start_level();
        goto sxs;
        }
    }
    return 0;
}

