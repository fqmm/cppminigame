//# Λ«ΘΛΆΤΥ½ΣΞΟ·

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
string plr[1110]= {"","‘ο","‘ψ","‘ρ","‘φ","‘τ"};
string csmp[10][310][310]= {
    {
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","¨","¨","¨","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","¨","¨","¨","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","¨","¨","¨","¨","¨","¨","¨","  ","¨","¨","¨","¨","¨","¨","¨","¨","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","¨","¨","¨","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","¨","¨","¨","  ","  ","¨","¨","¨","¨","¨","¨","¨","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","  "},
        {"¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨"},
    },
    {
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","¨","  ","  ","  ","  ","  ","  ","  ","  ","¨","  ","  ","  ","  ","  "},
        {"  ","¨","¨","¨","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","¨","¨","¨","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","¨","  ","  ","¨","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","¨","¨","¨","¨","¨","¨","¨","  ","  ","¨","¨","¨","¨","¨","¨","¨","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","¨","¨","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","¨","¨","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","¨","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","¨","  ","  ","  ","  "},
        {"  ","  ","  ","¨","¨","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","¨","¨","  ","  ","  "},
        {"  ","¨","¨","¨","¨","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","¨","¨","¨","¨","  "},
        {"¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨"},
    },
    {
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","¨","¨","¨","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","¨","¨","¨","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","¨","¨","  ","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","  ","¨","¨","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","¨","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","¨","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","¨","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","¨","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","¨","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","¨","  ","  ","  ","  ","  ","  ","¨","  ","  ","  ","  ","  ","¨","  ","  ","  "},
        {"  ","  ","¨","¨","¨","  ","  ","  ","  ","¨","  ","  ","  ","  ","  ","¨","¨","¨","  ","  "},
        {"¨","  ","  ","  ","  ","  ","  ","  ","  ","  ","¨","  ","  ","  ","  ","  ","  ","  ","  ","¨"},
        {"¨","  ","  ","  ","  ","  ","  ","  ","  ","¨","  ","  ","  ","  ","  ","  ","  ","  ","  ","¨"},
        {"¨","  ","  ","  ","  ","  ","  ","  ","  ","  ","¨","  ","  ","  ","  ","  ","  ","  ","  ","¨"},
        {"¨","  ","  ","  ","  ","  ","  ","  ","  ","¨","  ","  ","  ","  ","  ","  ","  ","  ","  ","¨"},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","¨","¨","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","  "},
        {"¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨"},
    },
    {
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","¨","  ","  ","  ","  ","  ","  "},
        {"  ","  ","¨","  ","  ","  ","¨","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","¨","  ","  ","  ","  ","  ","  ","¨","  ","  ","  ","  ","  ","¨","  ","¨","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"¨","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","¨","¨","  ","¨","¨","¨","  ","¨","  ","¨","¨","  ","¨","  ","¨","¨","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","¨","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","¨","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","¨","  ","  ","  ","¨","  ","  ","  "},
        {"  ","  ","¨","  ","¨","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","¨","  ","  ","  ","  "},
        {"¨","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"¨","  ","  ","  ","  ","  ","  ","  ","¨","  ","¨","  ","  ","  ","  ","  ","  ","  ","  ","¨"},
        {"¨","  ","  ","  ","  ","¨","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","¨"},
        {"¨","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","¨"},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨"},
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
        {"  ","¨","¨","¨","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","¨","¨","¨","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","¨","¨","¨","¨","¨","¨","¨","  ","¨","¨","¨","¨","¨","¨","¨","¨","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","¨","¨","¨","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","¨","¨","¨","  ","  ","¨","¨","¨","¨","¨","¨","¨","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  ","  "},
        {"  ","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","  "},
        {"¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨","¨"},
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
        //?ώ²ΨΉβ±κ
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
        string jz[8]= {"¨","¨","¨","¨","¨","¨","¨"};
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
                printf("¨");
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
    printf("        %4d/%02d/%02d %02d:%02d:%02d ΠΗΖΪ%1d",sys.wYear,sys.wMonth,sys.wDay,sys.wHour,sys.wMinute,sys.wSecond,sys.wDayOfWeek);
    place(0,0);
    return NULL;
}
void op() {
    cls;
    for(int i=0; i<22; i++) {
        for(int j=0; j<20; j++) {
            if(mp[i][j]=="‘ο")color(yellow);
            if(mp[i][j]=="‘ψ")color(cyan);
            if(mp[i][j]=="‘ρ")color(pink);
            if(mp[i][j]=="‘φ")color(red);
            if(mp[i][j]=="‘τ")color(blue);
            if(mp[i][j]=="¨")color(reddark);
            cout<<mp[i][j];
        }
        cout<<endl;
    }
}
void* jumpl1(void* args) {
    double jumpt1,jumpt2;
    jumpt2=jumpt1=clock();
    while(startgame) {
        while(jump1!=2 && mp[x1+1][y1]!="¨" && mp[x1+1][y1]!=js2) {
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
        while(jump2!=2 && mp[x2+1][y2]!="¨" && mp[x2+1][y2]!=js1) {
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
        printf("Player1Ρ‘Τρ½ΗΙ«:\n");
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
                    printf("‘ο");
                    health1=1000;
                    js1="‘ο";
                    atk1=20;
                    break;
                case 2:
                    color(cyan);
                    printf("‘ψ");
                    health1=600;
                    js1="‘ψ";
                    atk1=40;
                    break;
                case 3:
                    color(pink);
                    printf("‘ρ");
                    health1=800;
                    js1="‘ρ";
                    atk1=30;
                    break;
                case 4:
                    color(red);
                    printf("‘φ");
                    health1=2000;
                    js1="‘φ";
                    atk1=15;
                    break;
                case 5:
                    color(blue);
                    printf("‘τ");
                    health1=700;
                    js1="‘τ";
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
        printf("Player2Ρ‘Τρ½ΗΙ«:\n");
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
                    printf("‘ο");
                    health2=1000;
                    atk2=20;
                    js2="‘ο";
                    break;
                case 2:
                    color(cyan);
                    printf("‘ψ");
                    health2=600;
                    atk2=40;
                    js2="‘ψ";
                    break;
                case 3:
                    color(pink);
                    printf("‘ρ");
                    health2=800;
                    atk2=30;
                    js2="‘ρ";
                    break;
                case 4:
                    color(red);
                    printf("‘φ");
                    health2=2000;
                    atk2=15;
                    js2="‘φ";
                    break;
                case 5:
                    color(blue);
                    printf("‘τ");
                    health2=700;
                    js2="‘τ";
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
        printf("Ρ‘Τρ΅ΨΝΌ:\n");
        if(cho==0) {
            printf("%d:Λζ»ϊ΅ΨΝΌ\n",cho+1);
            color(brown);
            for(int i=0; i<22; i++) {
                for(int j=0; j<20; j++) {
                    printf("£Ώ");
                }
                printf("\n");
            }
        }
        if(cho==1) {
            printf("%d:Ί£΅Α΄¬\n",cho+1);
            color(brown);
            for(int i=0; i<22; i++) {
                for(int j=0; j<20; j++) {
                    cout<<csmp[0][i][j];
                }
                printf("\n");
            }
        }
        if(cho==2) {
            printf("%d:ΎΊΌΌ³‘\n",cho+1);
            color(brown);
            for(int i=0; i<22; i++) {
                for(int j=0; j<20; j++) {
                    cout<<csmp[1][i][j];
                }
                printf("\n");
            }
        }
        if(cho==3) {
            printf("%d:ΏΥΦΠΌΐΜ³\n",cho+1);
            color(brown);
            for(int i=0; i<22; i++) {
                for(int j=0; j<20; j++) {
                    cout<<csmp[2][i][j];
                }
                printf("\n");
            }
        }
        if(cho==4) {
            printf("%d:Έ‘ΏΥ΅Ί\n",cho+1);
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
        if(mp[x1+1][y1]=="¨" || mp[x1+1][y1]==js2) jump1=2;
        if(mp[x2+1][y2]=="¨" || mp[x2+1][y2]==js1) jump2=2;
        jumpe1=jumpe2=clock();
        if(jump1==2 && (mp[x1+1][y1]=="¨" || mp[x1+1][y1]==js2)) jumpt1=jumpe1;
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
        if(jump2==2 && (mp[x2+1][y2]=="¨" || mp[x2+1][y2]==js1)) jumpt2=jumpe2;
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
                if(y1-1>=0 && mp[x1][y1-1]!="¨" && mp[x1][y1-1]!=js2) {
                    mp[x1][y1]="  ";
                    mp[x1][--y1]=js1;
                    place(x1,y1*2);
                    color(plco[js1]);
                    cout<<js1<<"  ";
                }
                cx1=-1;
            }
            if(choice=='d') {
                if(y1+1<=19 && mp[x1][y1+1]!="¨" && mp[x1][y1+1]!=js2) {
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
                    if(x1-1>=0 && mp[x1-1][y1]!="¨" && mp[x1-1][y1]!=js2) {
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
                if(js1=="‘ο" && x1==x2 && (y2-y1)*cx1<=3 && (y2-y1)*cx1>=0) {
                    health2-=atk1;
                    mag2+=5;
                    mag1+=10;
                    if(health2<=0) {
                        win=1;
                        break;
                    }
                }
                if(js1=="‘ψ" && (abs(x2-x1)<=3 && abs(y2-y1)<=3)) {
                    health2-=atk1;
                    mag2+=5;
                    mag1+=10;
                    if(health2<=0) {
                        win=1;
                        break;
                    }
                }
                if(js1=="‘ρ" && ((abs(x1-x2)<=3 && y1==y2) || (abs(y1-y2)<=3 && x1==x2))) {
                    health2-=atk1;
                    mag2+=5;
                    mag1+=10;
                    if(health2<=0) {
                        win=1;
                        break;
                    }
                }
                if(js1=="‘φ" && (abs(x2-x1)<=1 && abs(y2-y1)<=1)) {
                    health2-=atk1;
                    mag2+=5;
                    mag1+=10;
                    if(health2<=0) {
                        win=1;
                        break;
                    }
                }
                if(js1=="‘τ" && x1==x2 && (y2-y1)*cx1<=10 && (y2-y1)*cx1>=0) {
                    int dam=40;
                    for(int i=y1+cx1; i>=0 && i<=19; i+=cx1) {
                        if(mp[x1][i]=="¨") break;
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
                        if(mp[x1][y1+cx1]!="¨" && mp[x1][y1+cx1]!=js2) {
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
                if(js1=="‘ο") {
                    if(x1==x2 && (y2-y1)*cx1>0) {
                        mp[x2][y2]="  ";
                        health2-=150;
                        for(int i=1; i<=3; i++) {
                            if(y2+cx1>=0 && y2+cx1<=19 && mp[x2][y2+cx1]!="¨") {
                                y2+=cx1;
                            }
                        }
                        mp[x2][y2]=js2;
                    }
                }
                if(js1=="‘ψ") {
                    int dam=0;
                    mp[x1][y1]="  ";
                    for(; y1+cx1>=0 && y1+cx1<=19 && y1+cx1!=y2 && mp[x1][y1+cx1]!="¨"; y1+=cx1) {
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
                if(js1=="‘ρ") {
                    if(x1==x2 || y1==y2) {
                        health2-=150;
                    }
                }
                if(js1=="‘φ") {
                    if(x1==x2) {
                        health2-=200;
                    }
                }
                if(js1=="‘τ") {
                    mp[x1][y1]="  ";
                    if((y2==0) && (mp[x2][1]=="¨") || (y2==19) && (mp[x2][18]=="¨")){
                        mag1+=100;
                        continue;
                    }
                    if(y2>=18 || mp[x2][y2+1]=="¨") {
                        y1=y2-2;
                        cx1=1;
                    } else if(y2<=1 || mp[x2][y2-1]=="¨") {
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
                        if(y2+cx1>=0 && y2+cx1<=19 && mp[x2][y2+cx1]!="¨") {
                            y2+=cx1;
                        }
                    }
                    mp[x2][y2]=js2;
                }
                op();
            }

            //

            if(choice==LEFT) {
                if(y2-1>=0 && mp[x2][y2-1]!="¨" && mp[x2][y2-1]!=js1) {
                    mp[x2][y2]="  ";
                    mp[x2][--y2]=js2;
                    place(x2,y2*2);
                    color(plco[js2]);
                    cout<<js2<<"  ";
                }
                cx2=-1;
            }
            if(choice==RIGHT) {
                if(y2+1<=19 && mp[x2][y2+1]!="¨" && mp[x2][y2+1]!=js1) {
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
                    if(x2-1>=0 && mp[x2-1][y2]!="¨" && mp[x2-1][y2]!=js1) {
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
                if(js2=="‘ο" && x1==x2 && (y1-y2)*cx2<=3 && (y1-y2)*cx2>=0) {
                    health1-=atk2;
                    mag1+=5;
                    mag2+=10;
                    if(health1<=0) {
                        win=2;
                        break;
                    }
                }
                if(js2=="‘ψ" && (abs(x1-x2)<=3 && abs(y1-y2)<=3)) {
                    health1-=atk2;
                    mag1+=5;
                    mag2+=10;
                    if(health1<=0) {
                        win=2;
                        break;
                    }
                }
                if(js2=="‘ρ" && ((abs(x1-x2)<=3 && y1==y2) || (abs(y1-y2)<=3 && x1==x2))) {
                    health1-=atk2;
                    mag1+=5;
                    mag2+=10;
                    if(health1<=0) {
                        win=2;
                        break;
                    }
                }
                if(js2=="‘φ" && (abs(x1-x2)<=1 && abs(y1-y2)<=1)) {
                    health1-=atk2;
                    mag1+=5;
                    mag2+=10;
                    if(health1<=0) {
                        win=2;
                        break;
                    }
                }
                if(js2=="‘τ" && x1==x2 && (y1-y2)*cx2<=10 && (y1-y2)*cx2>=0) {
                    int dam=40;
                    for(int i=y2+cx2; i>=0 && i<=19; i+=cx2) {
                        if(mp[x2][i]=="¨") break;
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
                        if(mp[x2][y2+cx2]!="¨" && mp[x2][y2+cx2]!=js1) {
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
                if(js2=="‘ο") {
                    if(x1==x2 && (y1-y2)*cx2>0) {
                        mp[x1][y1]="  ";
                        health1-=150;
                        for(int i=1; i<=3; i++) {
                            if(y1+cx2>=0 && y1+cx2<=19 && mp[x1][y1+cx2]!="¨") {
                                y1+=cx2;
                            }
                        }
                        mp[x1][y1]=js1;
                    }
                }
                if(js2=="‘ψ") {
                    int dam=0;
                    mp[x2][y2]="  ";
                    for(; y2+cx2>=0 && y2+cx2<=19 && y2+cx2!=y1 && mp[x2][y2+cx2]!="¨"; y2+=cx2) {
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
                if(js2=="‘ρ") {
                    if(x1==x2 || y1==y2) {
                        health1-=150;
                    }
                }
                if(js2=="‘φ") {
                    if(x1==x2) {
                        health1-=200;
                    }
                }
                if(js2=="‘τ") {
                    if((y1==0) && (mp[x1][1]=="¨") || (y1==19) && (mp[x1][18]=="¨")){
                        mag1+=100;
                        continue;
                    }
                    mp[x2][y2]="  ";
                    if(y1>=18 || mp[x1][y1+1]=="¨") {
                        y2=y1-2;
                        cx2=1;
                    } else if(y1<=1 || mp[x1][y1-1]=="¨") {
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
                        if(y1+cx2>=0 && y1+cx2<=19 && mp[x1][y1+cx2]!="¨") {
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
        printf("               Player1Κ€³φ!                  ");
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
        printf("               Player2Κ€³φ!                  ");
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
    printf("‘ο ");
    color(white);
    printf("΄΄ΧχΥί:                       \n");
    color(cyan);
    printf("‘ψ ");
    color(white);
    printf("ΌΌΚυΦ§³Φ:                        \n");
    color(pink);
    printf("‘ρ ");
    color(white);
    printf("ΣΞΟ·ΚΤΝζ:                      \n");
    printf("     °ζ±ΎΊΕ:1.0.5                       \n");
    printf("     updating~~                         \n");
    printf("     1.0.1:ΌΣΘλΑΛΘύΥΕΠΒ΅ΨΝΌ             \n");
    printf("     1.0.2:³ε΄ΜΣλ΄σΥΠ½βΛψ               \n");
    printf("     1.0.3:°οΦϊ½ηΓζΠήΈΔ,½ηΓζΛυΠ‘,ΌΣΘλΡ‘Τρ΅ΨΝΌ\n");
    printf("     1.0.4:ΠΒΌΣΘλ½ΗΙ«Ή­ΚΦ               \n");
    printf("     1.0.5:½ηΓζ΄σΈΔΈο                   \n");
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
        printf("ΣΞΟ·°οΦϊ ");
        color(yellow);
        printf("‘ο");
        color(cyan);
        printf("‘ψ");
        color(pink);
        printf("‘ρ");
        color(red);
        printf("‘φ");
        color(blue);
        printf("‘τ\n");
        color(white);
        switch(choice) {
            case 1:
                printf("========================================\n\n");
                printf("±ΎΣΞΟ·²ΙΣΓΚϊΖΚΓζΙθΌΖ,Ή₯»χ΅ΠΘΛΤά·¨Α¦\n");
                printf("²ΩΧχΉζΤς:\n");
                color(pink);
                printf("P1:AD?ΖΆ―,KΜψ,JΉ₯»χ,YΙΑΟΦ,L΄σΥΠ\n");
                color(yellow);
                printf("P2:ΧσΣ??ΖΆ―,2Μψ,1Ή₯»χ,3ΙΑΟΦ,8΄σΥΠ\n");
                color(white);
                printf("ΥβΈφΣΞΟ·ΣΠΞεΈφ½ΗΙ«£¨·½ΟςΌόΡ‘Τρ£©\n\n");
                printf("========================================\n\n");
                break; 
            case 2:
                printf("========================================\n\n");
                printf("First:»ω±Ύ½ΗΙ«:");
                color(yellow);
                printf("‘ο\n");
                color(white);
                color(red);
                printf("ΡͺΑΏ: 1000");
                color(yellow);
                printf("  Ή₯»χΑ¦:20\n");
                color(white);
                printf("ΖΥΉ₯:Ή₯»χΗ°·½ΘύΈρ\n");
                printf("΄σΥΠ:Ή₯»χΗ°·½²’Έ½΄ψ»χΝΛΠ§Ήϋ£¬ΙΛΊ¦150\n\n");
                printf("========================================\n\n");
                break; 
            case 3:
                printf("========================================\n\n");
                printf("Second:΄ΜΏΝ:");
                color(cyan);
                printf("‘ψ\n");
                color(white);
                color(red);
                printf("ΡͺΑΏ: 600");
                color(yellow);
                printf("  Ή₯»χΑ¦:40\n");
                color(white);
                printf("ΖΥΉ₯:ΘύΈρΔΪΆΌΏΙ?Τ΄ς΅½\n");
                printf("΄σΥΠ:ΟςΗ°³ε΄Μ£¬Χ²΅½΅ΠΘΛΚ±Έ½΄ψ»χΝΛΘύΈρ£¬\n³ε΄ΜΚ±Ύΰΐλ΅ΠΘΛΤ½ΤΆΙΛΊ¦Τ½Έί\n\n");
                printf("========================================\n\n");
                break; 
            case 4:
                printf("========================================\n\n");
                printf("Third:Σ£»¨:");
                color(pink);
                printf("‘ρ\n");
                color(white);
                color(red);
                printf("ΡͺΑΏ: 800");
                color(yellow);
                printf("  Ή₯»χΑ¦:30\n");
                color(white);
                printf("ΖΥΉ₯:Ή₯»χΘύΈρΦ?ΔΪΚ?ΧΦΗψΣς\n");
                printf("΄σΥΠ:Ή₯»χΥϋΠΠΥϋΑΠ£¬ΙΛΊ¦150\n\n");
                printf("========================================\n\n");
                break; 
            case 5:
                printf("========================================\n\n");
                printf("Fourth:ΜΉΏΛ:");
                color(red);
                printf("‘φ\n");
                color(white);
                color(red);
                printf("ΡͺΑΏ: 2000");
                color(yellow);
                printf("  Ή₯»χΑ¦:15\n");
                color(white);
                printf("ΖΥΉ₯:Ή₯»χΔγΦάΞ§?»Θ¦\n");
                printf("΄σΥΠ:Ή₯»χ?»ΥϋΠΠ£¬ΙΛΊ¦200\n\n");
                printf("========================================\n\n");
                break; 
            case 6:
                printf("========================================\n\n");
                printf("Last:Ή­ΚΦ:");
                color(blue);
                printf("‘τ\n");
                color(white);
                color(red);
                printf("ΡͺΑΏ: 700");
                color(yellow);
                printf("  Ή₯»χΑ¦:Ύΰΐλ΅ΠΘΛΤ½½όΤ½΄σ\n");
                color(white);
                printf("ΖΥΉ₯:Ή₯»χΔγΗ°·½10Έρ\n");
                printf("΄σΥΠ:ΙΑΟΦ²’Η?Ή₯»χ»χΝΛ΅ΠΘΛ£¬ΙΛΊ¦200\n\n");
                printf("========================================\n\n"); 
                break; 
        }
        color(green);
        if(choice==1) printf("  ");
        else printf("‘ϋ");
        if(choice==6) printf("  ");
        else printf("‘ϊ");
        color(pink);
        printf("\n\n(eΝΛ³φ)");
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
    plco["‘ο"]=yellow;
    plco["‘ψ"]=cyan;
    plco["‘ρ"]=pink;
    plco["‘φ"]=red;
    plco["‘τ"]=blue;
    while(1) {
        place(0,0);
        printf("      ¨q©€©€¨r‘‘¨q©€©€¨r‘‘¨q©€©€¨r\n");
        printf("      ©¦¨q©€¨s‘‘©¦¨q¨r©¦‘‘©¦¨q©€¨s\n");
        printf("      ©¦©¦¨q¨r‘‘©¦©¦©¦©¦‘‘©¦¨t©€¨r\n");
        printf("      ©¦©¦©¦©¦‘‘©¦©¦©¦©¦‘‘¨t©€¨r©¦\n");
        printf("      ©¦¨t¨s©¦‘‘©¦¨t¨s©¦‘‘¨q©€¨s©¦\n");
        printf("      ¨t©€©€¨s  ¨t©€©€¨s  ¨t©€©€¨s\n");

        printf("      Game Of Square:GOS ");
        color(yellow);
        printf("‘ο");
        color(cyan);
        printf("‘ψ");
        color(pink);
        printf("‘ρ");
        color(red);
        printf("‘φ");
        color(blue);
        printf("‘τ\n\n");
        color(white);
        printf("     ¨q©€©€©€©€©€©€©€©€©€©€©€©€©€¨r\n\n");
        printf("     ©¦");color(yellow);printf("    ‘ο[1.ΏͺΚΌΣΞΟ·]‘ο      ");color(white);printf("©§\n\n");
        color(white);
        printf("     ©¦");color(cyan);printf("    ‘ψ[2.ΣΞΟ·°οΦϊ]‘ψ      ");color(white);printf("©§\n\n");
        color(white);
        printf("     ©¦");color(pink);printf("    ‘ρ[3.ΉΨΣΪΞ?ΓΗ]‘ρ      ");color(white);printf("©§\n\n");
        color(white);
        printf("     ©¦");color(red);printf("    ‘φ[4.ΝΛ³φΣΞΟ·]‘φ      ");color(white);printf("©§\n\n");
        color(white);
        printf("     ¨t©₯©₯©₯©₯©₯©₯©₯©₯©₯©₯©₯©₯©₯¨s\n\n");
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
                printf("Θ·ΘΟΝΛ³φΒπ?0·ρ1ΚΗ");
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
    SetConsoleTitle("Λ«ΘΛΆΤΥ½ΣΞΟ·");
    system("mode con cols=42 lines=26");
    hidden();
    if(MessageBox(NULL,"±ΎΣΞΟ·Πθ?ͺ»ρΘ‘±Ύ΅ΨΧΚΤ΄£¬ΚΗ·ρΝ¬?β£Ώ","»ρΘ‘ΧΚΤ΄",MB_ICONEXCLAMATION|MB_OKCANCEL)==IDCANCEL) return 0;
    jz();
    printf("\nBingo!");
    Sleep(1000);
    home();
    STT=0;
    return 0;
}

