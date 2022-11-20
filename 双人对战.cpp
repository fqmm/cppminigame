//# 双人对战游戏

#include<iostream>
#include<cstdio>
#include<windows.h>
#include<conio.h>
#include<pthread.h>
#include<string>
#include<ctime>
#include<map>
#pragma comment(lib, "pthreadVC2.lib")
using namespace std;
#define cls; system("cls");
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
#define bluedark 1
#define greendark 2
#define cyandark 3
#define reddark 4
#define purple 5
#define yellowdark 6
#define whitedark 7
#define gray 8
#define blue 9
#define green 10
#define cyan 11
#define red 12
#define pink 13
#define yellow 14
#define white 15
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define brown 4
string plr[1110]= {"","★","▲","●","■","◆"};
string csmp[10][310][310]= {
    {
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","▓","▓","▓","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","▓","▓","▓","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","▓","▓","▓","▓","▓","▓","▓","  ","▓","▓","▓","▓","▓","▓","▓","▓","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","▓","▓","▓","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","▓","▓","▓","  ","  ","▓","▓","▓","▓","▓","▓","▓","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","  "},
        {"▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓"},
    },
    {
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","▓","  ","  ","  ","  ","  ","  ","  ","  ","▓","  ","  ","  ","  ","  "},
        {"  ","▓","▓","▓","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","▓","▓","▓","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","▓","  ","  ","▓","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","▓","▓","▓","▓","▓","▓","▓","  ","  ","▓","▓","▓","▓","▓","▓","▓","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","▓","▓","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","▓","▓","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","▓","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","▓","  ","  ","  ","  "},
        {"  ","  ","  ","▓","▓","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","▓","▓","  ","  ","  "},
        {"  ","▓","▓","▓","▓","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","▓","▓","▓","▓","  "},
        {"▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓"},
    },
    {
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","▓","▓","▓","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","▓","▓","▓","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","▓","▓","  ","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","  ","▓","▓","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","▓","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","▓","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","▓","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","▓","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","▓","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","▓","  ","  ","  ","  ","  ","  ","▓","  ","  ","  ","  ","  ","▓","  ","  ","  "},
        {"  ","  ","▓","▓","▓","  ","  ","  ","  ","▓","  ","  ","  ","  ","  ","▓","▓","▓","  ","  "},
        {"▓","  ","  ","  ","  ","  ","  ","  ","  ","  ","▓","  ","  ","  ","  ","  ","  ","  ","  ","▓"},
        {"▓","  ","  ","  ","  ","  ","  ","  ","  ","▓","  ","  ","  ","  ","  ","  ","  ","  ","  ","▓"},
        {"▓","  ","  ","  ","  ","  ","  ","  ","  ","  ","▓","  ","  ","  ","  ","  ","  ","  ","  ","▓"},
        {"▓","  ","  ","  ","  ","  ","  ","  ","  ","▓","  ","  ","  ","  ","  ","  ","  ","  ","  ","▓"},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","▓","▓","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","  "},
        {"▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓"},
    },
    {
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","▓","  ","  ","  ","  ","  ","  "},
        {"  ","  ","▓","  ","  ","  ","▓","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","▓","  ","  ","  ","  ","  ","  ","▓","  ","  ","  ","  ","  ","▓","  ","▓","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"▓","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","▓","▓","  ","▓","▓","▓","  ","▓","  ","▓","▓","  ","▓","  ","▓","▓","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","▓","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","▓","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","▓","  ","  ","  ","▓","  ","  ","  "},
        {"  ","  ","▓","  ","▓","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","▓","  ","  ","  ","  "},
        {"▓","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"▓","  ","  ","  ","  ","  ","  ","  ","▓","  ","▓","  ","  ","  ","  ","  ","  ","  ","  ","▓"},
        {"▓","  ","  ","  ","  ","▓","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","▓"},
        {"▓","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","▓"},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓"},
    },
};
int STT=1;
int jump1=2,jump2=2;
int x1,y1,x2,y2;
int health1,health2;
int mag1,mag2;
int atk1,atk2;
int cx1,cx2;
int startgame=0;
string js1,js2;
map<string,int>plco;
namespace _game {
    string mp[310][310]= {
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","▓","▓","▓","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","▓","▓","▓","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","▓","▓","▓","▓","▓","▓","▓","  ","▓","▓","▓","▓","▓","▓","▓","▓","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","▓","▓","▓","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","▓","▓","▓","  ","  ","▓","▓","▓","▓","▓","▓","▓","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","  "},
        {"▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓","▓"},
    };
    bool check(char c) {
        return KEY_DOWN(c);
    }
    void place(const int x, const int y) {
        COORD PlaceCursorHere;
        PlaceCursorHere.X = y;
        PlaceCursorHere.Y = x;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), PlaceCursorHere);
        return;
    }
    void color(int x) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
    }
    int click() {
        return GetAsyncKeyState(VK_LBUTTON);
    }
    void hidden() {
        //隐藏光标
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cci;
        GetConsoleCursorInfo(hOut,&cci);
        cci.bVisible=0;
        SetConsoleCursorInfo(hOut,&cci);
        return;
    }
    int search(int x0,int y0,int x,int y) {
        int xx,yy;
        POINT pt;
        HWND h=GetForegroundWindow();
        GetCursorPos(&pt);
        ScreenToClient(h,&pt);
        xx=pt.y/16;
        yy=pt.x/8;
        if(xx>=x0 && xx<=x && yy>=y0 && yy<=y)
            if(click())
                return 2;
            else return 1;
        return 0;
    }
    void jz() {
        int i,xxxx,j;
        string jz[8]= {"▏","▎","▍","▌","▋","▊","▉"};
        color(7);
        for(i=1; i<=136; i++) {
            xxxx=i%8;
            COORD pos = {0, 0};
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            color(15);
            printf(" Please Loading...    \n");
            printf("----------------------------------\n");
            color(10);
            for(j=1; j<=i/8; j++)
                printf("█");
            cout<<jz[xxxx]<<endl;
            color(15);
            printf("----------------------------------\n");
        }
        cls;
    }
}
using namespace _game;
void* xstime(void* args) {
    SYSTEMTIME sys;
    place(51,40);
    GetLocalTime(&sys);
    printf("        %4d/%02d/%02d %02d:%02d:%02d 星期%1d",sys.wYear,sys.wMonth,sys.wDay,sys.wHour,sys.wMinute,sys.wSecond,sys.wDayOfWeek);
    place(0,0);
    return NULL;
}
void op() {
    cls;
    for(int i=0; i<22; i++) {
        for(int j=0; j<20; j++) {
            if(mp[i][j]=="★")color(yellow);
            if(mp[i][j]=="▲")color(cyan);
            if(mp[i][j]=="●")color(pink);
            if(mp[i][j]=="■")color(red);
            if(mp[i][j]=="◆")color(blue);
            if(mp[i][j]=="▓")color(reddark);
            cout<<mp[i][j];
        }
        cout<<endl;
    }
}
void* jumpl1(void* args) {
    double jumpt1,jumpt2;
    jumpt2=jumpt1=clock();
    while(startgame) {
        while(jump1!=2 && mp[x1+1][y1]!="▓" && mp[x1+1][y1]!=js2) {
            jumpt2=clock();
            if(jumpt2-jumpt1>=333) {
                mp[x1][y1]="  ";
                mp[++x1][y1]=js1;
                jumpt1=jumpt2;
                op();
            }
        }
        jump1=2;
    }
}
void* jumpl2(void* args) {
    double jumpt1,jumpt2;
    jumpt2=jumpt1=clock();
    while(startgame) {
        while(jump2!=2 && mp[x2+1][y2]!="▓" && mp[x2+1][y2]!=js1) {
            jumpt2=clock();
            if(jumpt2-jumpt1>=333) {
                mp[x2][y2]="  ";
                mp[++x2][y2]=js2;
                jumpt1=jumpt2;
                op();
            }
        }
        jump2=2;
    }
}
void stgame() {
    cls;
    x1=20,x2=20,y1=0,y2=19;
    int win;
    int cho=1;
    char ch;
    while(1) {
        cls;
        printf("Player1选择角色:\n");
        for(int i=1; i<=5; i++) {
            if(cho==i) color(plco[plr[i]]);
            else color(gray);
            cout<<plr[i];
        }
        color(white);
        ch=getch();
        if(ch=='a' || ch=='A' || ch==LEFT) {
            if(cho>1) {
                cho--;
            }
        }
        if(ch=='d' || ch=='D' || ch==RIGHT) {
            if(cho<5) {
                cho++;
            }
        }
        if(ch==13) {
            printf("\nPlayer1:");
            switch(cho) {
                case 1:
                    color(yellow);
                    printf("★");
                    health1=1000;
                    js1="★";
                    atk1=20;
                    break;
                case 2:
                    color(cyan);
                    printf("▲");
                    health1=600;
                    js1="▲";
                    atk1=40;
                    break;
                case 3:
                    color(pink);
                    printf("●");
                    health1=800;
                    js1="●";
                    atk1=30;
                    break;
                case 4:
                    color(red);
                    printf("■");
                    health1=2000;
                    js1="■";
                    atk1=15;
                    break;
                case 5:
                    color(blue);
                    printf("◆");
                    health1=700;
                    js1="◆";
                    atk1=10;
                    break;
            }
            break;
        }
    }
    color(white);
    Sleep(1000);
    while(1) {
        cls;
        printf("Player2选择角色:\n");
        for(int i=1; i<=5; i++) {
            if(cho==i) color(plco[plr[i]]);
            else color(gray);
            cout<<plr[i];
        }
        color(white);
        ch=getch();
        if(ch=='a' || ch=='A' || ch==LEFT) {
            if(cho>1) {
                cho--;
            }
        }
        if(ch=='d' || ch=='D' || ch==RIGHT) {
            if(cho<5) {
                cho++;
            }
        }
        if(ch==13) {
            printf("\nPlayer2:");
            switch(cho) {
                case 1:
                    color(yellow);
                    printf("★");
                    health2=1000;
                    atk2=20;
                    js2="★";
                    break;
                case 2:
                    color(cyan);
                    printf("▲");
                    health2=600;
                    atk2=40;
                    js2="▲";
                    break;
                case 3:
                    color(pink);
                    printf("●");
                    health2=800;
                    atk2=30;
                    js2="●";
                    break;
                case 4:
                    color(red);
                    printf("■");
                    health2=2000;
                    atk2=15;
                    js2="■";
                    break;
                case 5:
                    color(blue);
                    printf("◆");
                    health2=700;
                    js2="◆";
                    atk2=10;
                    break;
            }
            break;
        }
    }
    color(white);
    Sleep(1000);
    cho=0;
    int rett=1;
    while(1) {
        cls;
        color(white);
        printf("选择地图:\n");
        if(cho==0) {
            printf("%d:随机地图\n",cho+1);
            color(brown);
            for(int i=0; i<22; i++) {
                for(int j=0; j<20; j++) {
                    printf("？");
                }
                printf("\n");
            }
        }
        if(cho==1) {
            printf("%d:海盗船\n",cho+1);
            color(brown);
            for(int i=0; i<22; i++) {
                for(int j=0; j<20; j++) {
                    cout<<csmp[0][i][j];
                }
                printf("\n");
            }
        }
        if(cho==2) {
            printf("%d:竞技场\n",cho+1);
            color(brown);
            for(int i=0; i<22; i++) {
                for(int j=0; j<20; j++) {
                    cout<<csmp[1][i][j];
                }
                printf("\n");
            }
        }
        if(cho==3) {
            printf("%d:空中祭坛\n",cho+1);
            color(brown);
            for(int i=0; i<22; i++) {
                for(int j=0; j<20; j++) {
                    cout<<csmp[2][i][j];
                }
                printf("\n");
            }
        }
        if(cho==4) {
            printf("%d:浮空岛\n",cho+1);
            color(brown);
            for(int i=0; i<22; i++) {
                for(int j=0; j<20; j++) {
                    cout<<csmp[3][i][j];
                }
                printf("\n");
            }
        }
        ch=getch();
        if(ch=='a' || ch=='A' || ch==LEFT) {
            if(cho>0) {
                cho--;
            }
        }
        if(ch=='d' || ch=='D' || ch==RIGHT) {
            if(cho<4) {
                cho++;
            }
        }
        if(ch==13) {
            if(cho==0) rett=rand()%4;
            else rett=cho-1;
            break;
        }
    }
    for(int i=0; i<22; i++) {
        for(int j=0; j<20; j++) {
            mp[i][j]=csmp[rett][i][j];
        }
    }
    cls;
    Sleep(1000);
    mag1=mag2=0;
    cx1=cx2=0;
    mp[x1][y1]=js1;
    mp[x2][y2]=js2;
    char choice;
    double mpsx,sx;
    mpsx=sx=clock();
    startgame=1;
    double jumpt1,jumpt2;
    double jumpe1,jumpe2;
//  pthread_t tid1,tid2;
//  pthread_create(&tid1,NULL,&jumpl1,NULL);
//  pthread_create(&tid2,NULL,&jumpl2,NULL);
    op();
    while(health1>0 && health2>0) {
        color(red);
        place(23,0);
        printf("P1:hp:%4d      P2:hp:%4d",health1,health2);
        place(24,0);
        color(blue);
        printf("P1:mp:%4d      P2:mp:%4d",mag1,mag2);
        if(mp[x1+1][y1]=="▓" || mp[x1+1][y1]==js2) jump1=2;
        if(mp[x2+1][y2]=="▓" || mp[x2+1][y2]==js1) jump2=2;
        jumpe1=jumpe2=clock();
        if(jump1==2 && (mp[x1+1][y1]=="▓" || mp[x1+1][y1]==js2)) jumpt1=jumpe1;
        else if(jumpe1-jumpt1>=233) {
            color(plco[js1]);
            place(x1,y1*2);
            mp[x1][y1]="  ";
            cout<<"  ";
            mp[++x1][y1]=js1;
            place(x1,y1*2);
            cout<<js1;
            jumpt1=jumpe1;
        }
        if(jump2==2 && (mp[x2+1][y2]=="▓" || mp[x2+1][y2]==js1)) jumpt2=jumpe2;
        else if(jumpe2-jumpt2>=233) {
            color(plco[js2]);
            place(x2,y2*2);
            mp[x2][y2]="  ";
            cout<<"  ";
            mp[++x2][y2]=js2;
            place(x2,y2*2);
            cout<<js2;
            jumpt2=jumpe2;
        }
        sx=clock();
        if(kbhit()) {
            choice=getch();
            if(choice=='a') {
                if(y1-1>=0 && mp[x1][y1-1]!="▓" && mp[x1][y1-1]!=js2) {
                    mp[x1][y1]="  ";
                    mp[x1][--y1]=js1;
                    place(x1,y1*2);
                    color(plco[js1]);
                    cout<<js1<<"  ";
                }
                cx1=-1;
            }
            if(choice=='d') {
                if(y1+1<=19 && mp[x1][y1+1]!="▓" && mp[x1][y1+1]!=js2) {
                    place(x1,y1*2);
                    mp[x1][y1]="  ";
                    mp[x1][++y1]=js1;
                    color(plco[js1]);
                    cout<<"  "<<js1;
                }
                cx1=1;
            }
            if(choice=='k' && jump1>0) {
                jumpt1=jumpe1;
                jump1--;
                for(int i=1; i<=3; i++)
                    if(x1-1>=0 && mp[x1-1][y1]!="▓" && mp[x1-1][y1]!=js2) {
                        place(x1,y1*2);
                        color(plco[js1]);
                        mp[x1][y1]="  ";
                        cout<<"  ";
                        mp[--x1][y1]=js1;
                        place(x1,y1*2);
                        cout<<js1;
                    } else break;
            }
            if(choice=='j') {
                if(js1=="★" && x1==x2 && (y2-y1)*cx1<=3 && (y2-y1)*cx1>=0) {
                    health2-=atk1;
                    mag2+=5;
                    mag1+=10;
                    if(health2<=0) {
                        win=1;
                        break;
                    }
                }
                if(js1=="▲" && (abs(x2-x1)<=3 && abs(y2-y1)<=3)) {
                    health2-=atk1;
                    mag2+=5;
                    mag1+=10;
                    if(health2<=0) {
                        win=1;
                        break;
                    }
                }
                if(js1=="●" && ((abs(x1-x2)<=3 && y1==y2) || (abs(y1-y2)<=3 && x1==x2))) {
                    health2-=atk1;
                    mag2+=5;
                    mag1+=10;
                    if(health2<=0) {
                        win=1;
                        break;
                    }
                }
                if(js1=="■" && (abs(x2-x1)<=1 && abs(y2-y1)<=1)) {
                    health2-=atk1;
                    mag2+=5;
                    mag1+=10;
                    if(health2<=0) {
                        win=1;
                        break;
                    }
                }
                if(js1=="◆" && x1==x2 && (y2-y1)*cx1<=10 && (y2-y1)*cx1>=0) {
                    int dam=40;
                    for(int i=y1+cx1; i>=0 && i<=19; i+=cx1) {
                        if(mp[x1][i]=="▓") break;
                        if(mp[x1][i]==js2) {
                            health2-=dam;
                            mag2+=5;
                            mag1+=10;
                            break;
                        }
                        dam-=4;
                    }
                    if(health2<=0) {
                        win=1;
                        break;
                    }
                }
            }
            if(choice=='y' && mag1>=30) {
                mag1-=30;
                for(int i=1; i<=3; i++) {
                    if(y1+cx1<=19 && y1+cx1>=0) {
                        if(mp[x1][y1+cx1]!="▓" && mp[x1][y1+cx1]!=js2) {
                            if(cx1==1) {
                                mp[x1][y1]="  ";
                                place(x1,y1*2);
                                color(plco[js1]);
                                cout<<"  "<<js1;
                                y1+=cx1;
                                mp[x1][y1]=js1;
                            } else {
                                mp[x1][y1]="  ";
                                y1+=cx1;
                                mp[x1][y1]=js1;
                                place(x1,y1*2);
                                color(plco[js1]);
                                cout<<js1<<"  ";
                            }
                        } else break;
                    }
                }
            }
            if(choice=='l' && mag1>=100) {
                mag1-=100;
                if(js1=="★") {
                    if(x1==x2 && (y2-y1)*cx1>0) {
                        mp[x2][y2]="  ";
                        health2-=150;
                        for(int i=1; i<=3; i++) {
                            if(y2+cx1>=0 && y2+cx1<=19 && mp[x2][y2+cx1]!="▓") {
                                y2+=cx1;
                            }
                        }
                        mp[x2][y2]=js2;
                    }
                }
                if(js1=="▲") {
                    int dam=0;
                    mp[x1][y1]="  ";
                    for(; y1+cx1>=0 && y1+cx1<=19 && y1+cx1!=y2 && mp[x1][y1+cx1]!="▓"; y1+=cx1) {
                        dam+=30;
                    }
                    mp[x1][y1]=js1;
                    if(y1+cx1==y2 && x1==x2) {
                        health2-=dam;
                        mp[x2][y2]="  ";
                        if(y2+cx1>0 && y2+cx1<19) {
                            y2+=cx1;
                        }
                        mp[x2][y2]=js2;
                    }
                }
                if(js1=="●") {
                    if(x1==x2 || y1==y2) {
                        health2-=150;
                    }
                }
                if(js1=="■") {
                    if(x1==x2) {
                        health2-=200;
                    }
                }
                if(js1=="◆") {
                    mp[x1][y1]="  ";
                    if((y2==0) && (mp[x2][1]=="▓") || (y2==19) && (mp[x2][18]=="▓")){
                        mag1+=100;
                        continue;
                    }
                    if(y2>=18 || mp[x2][y2+1]=="▓") {
                        y1=y2-2;
                        cx1=1;
                    } else if(y2<=1 || mp[x2][y2-1]=="▓") {
                        y1=y2+2;
                        cx1=-1;
                    } else {
                        y1=y2+cx2*2;
                        cx1=-cx2;
                    }
                    x1=x2;
                    mp[x1][y1]=js1;
                    health2-=200;
                    mp[x2][y2]="  ";
                    for(int i=1; i<=3; i++) {
                        if(y2+cx1>=0 && y2+cx1<=19 && mp[x2][y2+cx1]!="▓") {
                            y2+=cx1;
                        }
                    }
                    mp[x2][y2]=js2;
                }
                op();
            }

            //

            if(choice==LEFT) {
                if(y2-1>=0 && mp[x2][y2-1]!="▓" && mp[x2][y2-1]!=js1) {
                    mp[x2][y2]="  ";
                    mp[x2][--y2]=js2;
                    place(x2,y2*2);
                    color(plco[js2]);
                    cout<<js2<<"  ";
                }
                cx2=-1;
            }
            if(choice==RIGHT) {
                if(y2+1<=19 && mp[x2][y2+1]!="▓" && mp[x2][y2+1]!=js1) {
                    place(x2,y2*2);
                    mp[x2][y2]="  ";
                    mp[x2][++y2]=js2;
                    color(plco[js2]);
                    cout<<"  "<<js2;
                }
                cx2=1;
            }
            if(choice=='2' && jump2>0) {
                jumpt2=jumpe2;
                jump2--;
                for(int i=1; i<=3; i++)
                    if(x2-1>=0 && mp[x2-1][y2]!="▓" && mp[x2-1][y2]!=js1) {
                        place(x2,y2*2);
                        color(plco[js2]);
                        mp[x2][y2]="  ";
                        cout<<"  ";
                        mp[--x2][y2]=js2;
                        place(x2,y2*2);
                        cout<<js2;
                    } else break;
            }
            if(choice=='1') {
                if(js2=="★" && x1==x2 && (y1-y2)*cx2<=3 && (y1-y2)*cx2>=0) {
                    health1-=atk2;
                    mag1+=5;
                    mag2+=10;
                    if(health1<=0) {
                        win=2;
                        break;
                    }
                }
                if(js2=="▲" && (abs(x1-x2)<=3 && abs(y1-y2)<=3)) {
                    health1-=atk2;
                    mag1+=5;
                    mag2+=10;
                    if(health1<=0) {
                        win=2;
                        break;
                    }
                }
                if(js2=="●" && ((abs(x1-x2)<=3 && y1==y2) || (abs(y1-y2)<=3 && x1==x2))) {
                    health1-=atk2;
                    mag1+=5;
                    mag2+=10;
                    if(health1<=0) {
                        win=2;
                        break;
                    }
                }
                if(js2=="■" && (abs(x1-x2)<=1 && abs(y1-y2)<=1)) {
                    health1-=atk2;
                    mag1+=5;
                    mag2+=10;
                    if(health1<=0) {
                        win=2;
                        break;
                    }
                }
                if(js2=="◆" && x1==x2 && (y1-y2)*cx2<=10 && (y1-y2)*cx2>=0) {
                    int dam=40;
                    for(int i=y2+cx2; i>=0 && i<=19; i+=cx2) {
                        if(mp[x2][i]=="▓") break;
                        if(mp[x2][i]==js1) {
                            health1-=dam;
                            mag1+=5;
                            mag2+=10;
                            break;
                        }
                        dam-=4;
                    }
                    if(health1<=0) {
                        win=2;
                        break;
                    }
                }
            }
            if(choice=='3' && mag2>=30) {
                mag2-=30;
                for(int i=1; i<=3; i++) {
                    if(y2+cx2<=19 && y2+cx2>=0) {
                        if(mp[x2][y2+cx2]!="▓" && mp[x2][y2+cx2]!=js1) {
                            if(cx2==1) {
                                mp[x2][y2]="  ";
                                place(x2,y2*2);
                                color(plco[js2]);
                                cout<<"  "<<js2;
                                y2+=cx2;
                                mp[x2][y2]=js2;
                            } else {
                                mp[x2][y2]="  ";
                                y2+=cx2;
                                mp[x2][y2]=js2;
                                place(x2,y2*2);
                                color(plco[js2]);
                                cout<<js2<<"  ";
                            }
                        } else break;
                    }
                }
            }
            if(choice=='8' && mag2>=100) {
                mag2-=100;
                if(js2=="★") {
                    if(x1==x2 && (y1-y2)*cx2>0) {
                        mp[x1][y1]="  ";
                        health1-=150;
                        for(int i=1; i<=3; i++) {
                            if(y1+cx2>=0 && y1+cx2<=19 && mp[x1][y1+cx2]!="▓") {
                                y1+=cx2;
                            }
                        }
                        mp[x1][y1]=js1;
                    }
                }
                if(js2=="▲") {
                    int dam=0;
                    mp[x2][y2]="  ";
                    for(; y2+cx2>=0 && y2+cx2<=19 && y2+cx2!=y1 && mp[x2][y2+cx2]!="▓"; y2+=cx2) {
                        dam+=30;
                    }
                    mp[x2][y2]=js2;
                    if(y2+cx2==y1 && x1==x2) {
                        health1-=dam;
                        mp[x1][y1]="  ";
                        if(y1+cx2>0 && y1+cx2<19) {
                            y1+=cx2;
                        }
                        mp[x1][y1]=js1;
                    }
                }
                if(js2=="●") {
                    if(x1==x2 || y1==y2) {
                        health1-=150;
                    }
                }
                if(js2=="■") {
                    if(x1==x2) {
                        health1-=200;
                    }
                }
                if(js2=="◆") {
                    if((y1==0) && (mp[x1][1]=="▓") || (y1==19) && (mp[x1][18]=="▓")){
                        mag1+=100;
                        continue;
                    }
                    mp[x2][y2]="  ";
                    if(y1>=18 || mp[x1][y1+1]=="▓") {
                        y2=y1-2;
                        cx2=1;
                    } else if(y1<=1 || mp[x1][y1-1]=="▓") {
                        y2=y1+2;
                        cx2=-1;
                    } else {
                        y2=y1+cx1*2;
                        cx2=-cx1;
                    }
                    x2=x1;
                    mp[x2][y2]=js2;
                    health1-=200;
                    mp[x1][y1]="  ";
                    for(int i=1; i<=3; i++) {
                        if(y1+cx2>=0 && y1+cx2<=19 && mp[x1][y1+cx2]!="▓") {
                            y1+=cx2;
                        }
                    }
                    mp[x1][y1]=js1;
                }
                op();
            }
        }
    }
    if(health1<health2) {
        win=2;
        health1=0;
    } else {
        win=1;
        health2=0;
    }
    color(red);
    place(23,0);
    printf("P1:hp:%4d      P2:hp:%4d",health1,health2);
    place(24,0);
    color(blue);
    printf("P1:mp:%4d      P2:mp:%4d",mag1,mag2);
    if(win==1) {
        color(plco[js1]);
        place(10,0);
        printf("                                             ");
        place(11,0);
        printf("               Player1胜出!                  ");
        place(12,0);
        printf("                                             ");
        Sleep(1000);
        getch();
        cls;
        return;
    }
    if(win==2) {
        color(plco[js2]);
        place(10,0);
        printf("                                             ");
        place(11,0);
        printf("               Player2胜出!                  ");
        place(12,0);
        printf("                                             ");
        Sleep(1000);
        getch();
        cls;
        return;
    }
}
void about() {
    cls;
    place(0,0);
    printf("Game Of Square:GOS :                      \n");
    color(yellow);
    printf("★ ");
    color(white);
    printf("创作者:                       \n");
    color(cyan);
    printf("▲ ");
    color(white);
    printf("技术支持:                        \n");
    color(pink);
    printf("● ");
    color(white);
    printf("游戏试玩:                      \n");
    printf("     版本号:1.0.5                       \n");
    printf("     updating~~                         \n");
    printf("     1.0.1:加入了三张新地图             \n");
    printf("     1.0.2:冲刺与大招解锁               \n");
    printf("     1.0.3:帮助界面修改,界面缩小,加入选择地图\n");
    printf("     1.0.4:新加入角色弓手               \n");
    printf("     1.0.5:界面大改革                   \n");
    printf("                                        \n");
    printf("                                        \n");
    printf("                                        \n");
    printf("                                        \n");
    printf("                                        \n");
    printf("                                        \n");
    printf("                                        \n");
    printf("                                        \n");
}
void help() {
    cls;
    color(white);
    int choice=1;
    char ch;
    while(1) {
        cls;
        printf("游戏帮助 ");
        color(yellow);
        printf("★");
        color(cyan);
        printf("▲");
        color(pink);
        printf("●");
        color(red);
        printf("■");
        color(blue);
        printf("◆\n");
        color(white);
        switch(choice) {
            case 1:
                printf("========================================\n\n");
                printf("本游戏采用竖剖面设计,攻击敌人攒法力\n");
                printf("操作规则:\n");
                color(pink);
                printf("P1:AD移动,K跳,J攻击,Y闪现,L大招\n");
                color(yellow);
                printf("P2:左右移动,2跳,1攻击,3闪现,8大招\n");
                color(white);
                printf("这个游戏有五个角色（方向键选择）\n\n");
                printf("========================================\n\n");
                break; 
            case 2:
                printf("========================================\n\n");
                printf("First:基本角色:");
                color(yellow);
                printf("★\n");
                color(white);
                color(red);
                printf("血量: 1000");
                color(yellow);
                printf("  攻击力:20\n");
                color(white);
                printf("普攻:攻击前方三格\n");
                printf("大招:攻击前方并附带击退效果，伤害150\n\n");
                printf("========================================\n\n");
                break; 
            case 3:
                printf("========================================\n\n");
                printf("Second:刺客:");
                color(cyan);
                printf("▲\n");
                color(white);
                color(red);
                printf("血量: 600");
                color(yellow);
                printf("  攻击力:40\n");
                color(white);
                printf("普攻:三格内都可以打到\n");
                printf("大招:向前冲刺，撞到敌人时附带击退三格，\n冲刺时距离敌人越远伤害越高\n\n");
                printf("========================================\n\n");
                break; 
            case 4:
                printf("========================================\n\n");
                printf("Third:樱花:");
                color(pink);
                printf("●\n");
                color(white);
                color(red);
                printf("血量: 800");
                color(yellow);
                printf("  攻击力:30\n");
                color(white);
                printf("普攻:攻击三格之内十字区域\n");
                printf("大招:攻击整行整列，伤害150\n\n");
                printf("========================================\n\n");
                break; 
            case 5:
                printf("========================================\n\n");
                printf("Fourth:坦克:");
                color(red);
                printf("■\n");
                color(white);
                color(red);
                printf("血量: 2000");
                color(yellow);
                printf("  攻击力:15\n");
                color(white);
                printf("普攻:攻击你周围一圈\n");
                printf("大招:攻击一整行，伤害200\n\n");
                printf("========================================\n\n");
                break; 
            case 6:
                printf("========================================\n\n");
                printf("Last:弓手:");
                color(blue);
                printf("◆\n");
                color(white);
                color(red);
                printf("血量: 700");
                color(yellow);
                printf("  攻击力:距离敌人越近越大\n");
                color(white);
                printf("普攻:攻击你前方10格\n");
                printf("大招:闪现并且攻击击退敌人，伤害200\n\n");
                printf("========================================\n\n"); 
                break; 
        }
        color(green);
        if(choice==1) printf("  ");
        else printf("←");
        if(choice==6) printf("  ");
        else printf("→");
        color(pink);
        printf("\n\n(e退出)");
        color(white);
        ch=getch();
        if(ch=='a' || ch==LEFT) {
            if(choice>1) choice--;
        }
        if(ch=='d' || ch==RIGHT) {
            if(choice<6) choice++;
        }
        if(ch=='e') {
            break;
        }
    }
    cls;
}
void home() {
    srand((unsigned)time(0));
    char choi,choi2;
    plco["★"]=yellow;
    plco["▲"]=cyan;
    plco["●"]=pink;
    plco["■"]=red;
    plco["◆"]=blue;
    while(1) {
        place(0,0);
        printf("      ╭──╮　╭──╮　╭──╮\n");
        printf("      │╭─╯　│╭╮│　│╭─╯\n");
        printf("      ││╭╮　││││　│╰─╮\n");
        printf("      ││││　││││　╰─╮│\n");
        printf("      │╰╯│　│╰╯│　╭─╯│\n");
        printf("      ╰──╯  ╰──╯  ╰──╯\n");

        printf("      Game Of Square:GOS ");
        color(yellow);
        printf("★");
        color(cyan);
        printf("▲");
        color(pink);
        printf("●");
        color(red);
        printf("■");
        color(blue);
        printf("◆\n\n");
        color(white);
        printf("     ╭─────────────╮\n\n");
        printf("     │");color(yellow);printf("    ★[1.开始游戏]★      ");color(white);printf("┃\n\n");
        color(white);
        printf("     │");color(cyan);printf("    ▲[2.游戏帮助]▲      ");color(white);printf("┃\n\n");
        color(white);
        printf("     │");color(pink);printf("    ●[3.关于我们]●      ");color(white);printf("┃\n\n");
        color(white);
        printf("     │");color(red);printf("    ■[4.退出游戏]■      ");color(white);printf("┃\n\n");
        color(white);
        printf("     ╰━━━━━━━━━━━━━╯\n\n");
        xstime(NULL);
        if(kbhit()) {
            choi=getch();
            if(choi=='1') {
                stgame();
            }
            if(choi=='2') {
                help();
            }
            if(choi=='3') {
                about();
                getch();
                cls;
            }
            if(choi=='4') {
                cls;
                printf("确认退出吗?0否1是");
                choi2=getch();
                while(choi2!='0' && choi2!='1')choi2=getch();
                if(choi2=='1') {
                    jz();
                    Sleep(1000);
                    return;
                } else {
                    cls;
                }
            }
        }
    }
}
int main() {
    SetConsoleTitle("双人对战游戏");
    system("mode con cols=42 lines=26");
    hidden();
    if(MessageBox(NULL,"本游戏需要获取本地资源，是否同意？","获取资源",MB_ICONEXCLAMATION|MB_OKCANCEL)==IDCANCEL) return 0;
    jz();
    printf("\nBingo!");
    Sleep(1000);
    home();
    STT=0;
    return 0;
}

