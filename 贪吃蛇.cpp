//# 贪吃蛇Ⅱ
//```cpp
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<ctime>
#include<conio.h>
#include<windows.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
using namespace std;
HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
COORD coord;
void locate(int x, int y)
{
    coord.X=y*2;
    coord.Y=x;
    SetConsoleCursorPosition(hout,coord);
};
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
void hide() {CONSOLE_CURSOR_INFO cursor_info={1,0};SetConsoleCursorInfo(hout,&cursor_info);}
double random(double start, double end) {return start+(end-start)*rand()/(RAND_MAX+1.0);}
int m,n,hard;
char g;
bool b11,b21,b12,b22,b13,b23,b14,b24;
const int Ti=1e4;
struct node {int x, y;}snake1[1000],snake2[1000];
node food[2];
int snake_length1,snake_length2,dir1,dir2;
int direct[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
void print_wall()
{
    cout<<"■";for(int i=1;i<=n+1;i++) cout<<"■";cout<<endl;
    for(int j=0;j<=m-1;j++)
    {
        cout<<"■";
        for(int i=1;i<=n;i++)
        cout<<"  ";cout<<"■"<<endl;
    }
    cout<<"■";for(int i=1;i<=n+1;i++) cout<<"■";
}
void print_snake()
{
    locate(snake1[0].x,snake1[0].y);
    Color(3),cout<< "●",Color(0);
    for(int i=1;i<snake_length1-1;i++) {locate(snake1[i].x,snake1[i].y);Color(5),cout<<"●",Color(0);}
    locate(snake2[0].x,snake2[0].y);
    Color(3),cout<<"●",Color(0);
    for (int i=1;i<snake_length2-1;i++) {locate(snake2[i].x,snake2[i].y);Color(1),cout<<"●",Color(0);}
}
bool is_correct1()
{
    if(g!='3'&&(snake1[0].x== 0||snake1[0].y==0 || snake1[0].x == m + 1 || snake1[0].y == n + 1)) return false;
    if(g=='3')
    {
        if(snake1[0].x == 0) snake1[0].x =m;
        if(snake1[0].x == m+1) snake1[0].x =1;
        if(snake1[0].y == 0) snake1[0].y =n;
        if(snake1[0].y == n+1) snake1[0].y =1;
    }
    for(int i=1;i<=snake_length1-1;i++)if(snake1[0].x==snake1[i].x&&snake1[0].y==snake1[i].y) return false;
    for(int i=0;i<=snake_length2-1;i++)if(snake1[0].x==snake2[i].x&&snake1[0].y==snake2[i].y) return false; 
    return true;
}
bool is_correct2()
{
    if(g!='3'&&(snake2[0].x == 0 || snake2[0].y == 0 || snake2[0].x == m + 1 || snake2[0].y == n + 1))return false;
    if(g=='3')
    {
        if(snake2[0].x == 0) snake2[0].x =m;
        if(snake2[0].x == m+1) snake2[0].x =1;
        if(snake2[0].y == 0) snake2[0].y =n;
        if(snake2[0].y == n+1) snake2[0].y =1;
    }
    for (int i = 1; i <= snake_length2 - 1; i++)if(snake2[0].x == snake2[i].x  &&  snake2[0].y == snake2[i].y)return false; 
    for (int i = 0; i <= snake_length1 - 1; i++)if(snake2[0].x == snake1[i].x  &&  snake2[0].y == snake1[i].y)return false; 
    return true;
}
bool print_food(bool a)
{
    bool e;
    while (1)
    {
        e=true;
        int i=(int)random(0,m)+1;
        int j=(int)random(0,n)+1;
        food[a].x = i; food[a].y = j;
        for (int k = 0; k <= snake_length1 - 1; k++)
        if (snake1[k].x == food[a].x  &&  snake1[k].y == food[a].y){e= false; break; }
        for (int k = 0; k <= snake_length2 - 1; k++)
        if (snake2[k].x == food[a].x  &&  snake2[k].y == food[a].y){e= false;break; }
        if (food[0].x == food[1].x  &&  food[0].y == food[1].y) e= false;
        if (e)break;
    }
    locate(food[a].x,food[a].y);
    Color(2),cout << "◆",Color(0);
    return true;
}
bool go_ahead1()
{
    node tmp;
    bool e = false;
    tmp = snake1[snake_length1-1];
    for (int i = snake_length1 - 1; i >= 1;i--) snake1[i] = snake1[i - 1];
    snake1[0].x += direct[dir1][0];
    snake1[0].y += direct[dir1][1];
    locate(snake1[1].x, snake1[1].y);
    Color(5),cout << "●",Color(0);
    if(snake1[0].x==food[0].x&&snake1[0].y==food[0].y){snake_length1++;e=true;snake1[snake_length1-1]=tmp;print_food(0);}
    if(snake1[0].x==food[1].x&&snake1[0].y==food[1].y)
    {
        snake_length1++;e=true;
        snake1[snake_length1-1]=tmp;
        print_food(1);
    }
    if (!e)
    {
        locate(tmp.x, tmp.y);
        cout<<"  ";
    }
    locate(snake1[0].x, snake1[0].y);
    Color(3),cout << "●",Color(0);
    if (!is_correct1())
    {
        system("color 7F");Color(5);
        if(g=='1') locate(10,8),cout << "You lose!";
        if(g=='2'||g=='3') {locate(9,8);cout << "1p lose!";locate(11,8);cout<<"Length: "<<snake_length1;}
        Color(0);
        return false;
    }
    return true;
}
bool go_ahead2()
{
    node tmp;
    bool e=false;
    tmp=snake2[snake_length2-1];
    for (int i=snake_length2-1;i>=1;i--) snake2[i]=snake2[i - 1];
    snake2[0].x+=direct[dir2][0];
    snake2[0].y+=direct[dir2][1];
    locate(snake2[1].x, snake2[1].y);Color(1),cout << "●",Color(0);
    if(snake2[0].x==food[0].x&&snake2[0].y==food[0].y) {snake_length2++;e=true;snake2[snake_length2-1]=tmp;print_food(0);}
    if(snake2[0].x==food[1].x&&snake2[0].y==food[1].y) {snake_length2++;e=true;snake2[snake_length2-1]=tmp;print_food(1);}
    if(!e) {locate(tmp.x, tmp.y);cout<<"  ";}
    locate(snake2[0].x, snake2[0].y);Color(3),cout << "●",Color(0);
    if(!is_correct2())
    {
        system("color 7F");Color(1);
        if(g=='1') locate(10,8),cout << "You lose!";
        if(g=='2'||g=='3') {locate(9,8);cout<<"2p lose!";locate(11,8);cout<<"Length: "<<snake_length2;Color(0);return false;}
    }
    return true;
}
int Start()
{
    print_wall();
    print_snake();Color(2);
    locate(8,5);cout<<"◆";Color(4),cout<<" 双 人 贪 吃 蛇";Color(2),cout<<" ◆"; Color(5);
    locate(10,1);cout<<" 1.单人模式（A W S D↑←↓→八键位系统）"; Color(1);
    locate(12,1);cout<<" 2.双人模式（双人 2*4 键位系统）";Color(3);
    locate(14,1);cout<<" 3.双人·“无限宇宙”模式";Color(0);
    A:if(kbhit()) g=_getch();
    if(g!='1'&&g!='2'&&g!='3') goto A;
}
int main()
{
    system("mode con cols=45 lines=26");
    CONSOLE_CURSOR_INFO cursor_info={1,0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
    srand((unsigned)time(NULL));
    m=20,n=20,hard=10*Ti;ST:
    snake_length1=snake_length2 = 5;
    double hard_len;
    dir1=3;dir2=2;
    for(int i=0;i<=4;i++) {snake1[i].x=6;snake1[i].y=6-i;}
    for(int i=0;i<=4;i++) {snake2[i].x=15;snake2[i].y=15+i;}
    Start();
    system("cls");
    hide();
    print_wall();
    print_food(0);
    if(g=='2'||g=='3') print_food(1);
    print_snake();
    locate(m+2,0);cout<<"Now Length 1:";
    locate(m+3,0);cout<<"Now Length 2:";
    locate(m+4,0);cout<<"按 k/l 加/减 速   速度：";locate(m+4,13),cout<<hard/100;
    locate(10,4);Color(4);cout<<"Please point 'y' to Start";Color(0);
    SS: char ee=_getch(); if(ee!='y') goto SS;
    locate(10,4);cout<<"                           ";
    while (1)
    {
        b11=b21=b12=b22=b13=b23=b14=b24=0;
        for(int i=1;i<=hard;i++)
        {
            if(g=='1')
            {
                if(KEY_DOWN(87)||KEY_DOWN(40)) {if (dir1 == 2 || dir1 == 3){dir1 = 0;if(b11==0) b11=1,go_ahead1();}}
                else if(KEY_DOWN(83)||KEY_DOWN(38)) {if (dir1 == 2 || dir1 == 3){dir1 = 1;if(b12==0) b12=1,go_ahead1();}}
                else if(KEY_DOWN(65)||KEY_DOWN(39)) {if (dir1 == 0 || dir1 == 1){dir1 = 2;if(b13==0) b13=1,go_ahead1();}}
                else if(KEY_DOWN(68)||KEY_DOWN(37)) {if (dir1 == 0 || dir1 == 1){dir1 = 3;if(b14==0) b14=1,go_ahead1();}}
                if(KEY_DOWN(38)||KEY_DOWN(83)) {if (dir2 == 2 || dir2 == 3){dir2 = 0;if(b21==0) b21=1,go_ahead2();}}
                else if(KEY_DOWN(40)||KEY_DOWN(87)) {if (dir2 == 2 || dir2 == 3){dir2 = 1;if(b22==0) b22=1,go_ahead2();}}
                else if(KEY_DOWN(37)||KEY_DOWN(68)) {if (dir2 == 0 || dir2 == 1){dir2 = 2;if(b23==0) b23=1,go_ahead2();}}
                else if(KEY_DOWN(39)||KEY_DOWN(65)) {if (dir2 == 0 || dir2 == 1){dir2 = 3;if(b24==0) b24=1,go_ahead2();}}
            }
            if(g=='2'||g=='3')
            {
                if(KEY_DOWN(87)) {if (dir1 == 2 || dir1 == 3){dir1 = 0;if(b11==0) b11=1,go_ahead1();}}
                else if(KEY_DOWN(83)) {if (dir1 == 2 || dir1 == 3){dir1 = 1;if(b12==0) b12=1,go_ahead1();}}
                else if(KEY_DOWN(65)) {if (dir1 == 0 || dir1 == 1){dir1 = 2;if(b13==0) b13=1,go_ahead1();}}
                else if(KEY_DOWN(68)) {if (dir1 == 0 || dir1 == 1){dir1 = 3;if(b14==0) b14=1,go_ahead1();}}
                if(KEY_DOWN(38)) {if (dir2 == 2 || dir2 == 3){dir2 = 0;if(b21==0) b21=1,go_ahead2();}}
                else if(KEY_DOWN(40)) {if (dir2 == 2 || dir2 == 3){dir2 = 1;if(b22==0) b22=1,go_ahead2();}}
                else if(KEY_DOWN(37)) {if (dir2 == 0 || dir2 == 1){dir2 = 2;if(b23==0) b23=1,go_ahead2();}}
                else if(KEY_DOWN(39)) {if (dir2 == 0 || dir2 == 1){dir2 = 3;if(b24==0) b24=1,go_ahead2();}}
            }
            if(KEY_DOWN(76)) hard=min(hard+10,20*Ti),locate(m+4,13),cout<<2000-hard/100<<"   ";
            if(KEY_DOWN(75)) hard=max(hard-10,2*Ti),locate(m+4,13),cout<<2000-hard/100<<"   ";
        }
        if(snake_length1>snake_length2) {if(!go_ahead2()) break;if(!go_ahead1()) break;}
        if(snake_length1<snake_length2) {if(!go_ahead1()) break;if(!go_ahead2()) break;}
        if(snake_length1==snake_length2) {int r=rand()%2;if(r==0&&!go_ahead1()) break;if(r==0&&!go_ahead2()) break;if(r==1&&!go_ahead2()) break;if(r==1&&!go_ahead1()) break;}
        locate(m+2,12);cout<<snake_length1;
        locate(m+3,12);cout<<snake_length2;
    }
    char e;
    locate(13,4);cout<<"Please point 'y' to Play AGain.";
    A:e=_getch(); if(e=='y') goto ST; else goto A;
    return 0;
}

