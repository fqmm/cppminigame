
#include<bits/stdc++.h> 
#include<conio.h>
#include<windows.h>
using namespace std;
void Color(int a)
{
    if(a==0) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    if(a==1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
    if(a==2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
    if(a==3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
    if(a==4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
    if(a==5) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
    if(a==7) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN);
    if(a==8) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|BACKGROUND_RED);
}
void Setpos(int x,int y){COORD pos;pos.X=y*2,pos.Y=x;SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);}
int R[5];
void SlowDisplay(int x,char *p){while(1){if(*p!=0) printf("%c",*p++);else break;Sleep(x);}}
struct xg{int xgx,xgy;bool fx,sw=0; }xg[21];
int ys=0,hd=0,sj=0,sl=0,mg=0,hp=0,hss=0,hsx=0,jt=0,s=0;
char ch[35][35];
char ch1[35][35]={"", "      #####     #####  ########"," #&##       ###       ###      ","      #### #    ## ####   #### ","  ### ##   # ####!      ##     ","  ###&   ###   +##  ###### ####"," ######&############!        ##"," #  *#      !  ######### ###-##"," # ### #####             #     "," # ###*#   ############### ### "," # ###&###                 ####"," #      #  # ##-############## "," ######   #####!               "," #+     #  ###### ############ ", " ##&########## ### ### ### ##  "," #                   !      ! #","   ############################","  #       ! #       ! #       #","    #     !   #     !   ####   "," #&########################### "," )                             ",}; 
char ch2[35][35]={""," ##############################"," #*                           #"," ########&###################-#"," #                          # #"," # # ################&#####-# #"," # # #               !   +# # #"," # # # ##&############### # # #"," # # # #                # # # #"," # # # # ###########&## # # # #"," # # # # #)- !        # # # & #"," # # # # ###      !   # # # # #", " # # # ##########&####### # # #"," # # #              !       # #"," # # ##################&##### #"," # #       !               *# #"," # #####&####### ############ #"," #     !       # #   !        #"," # ############# ###########  #"," #              !             #"," ##############################", };
char ch3[31][33]={""," ##############################"," #.          +               .#"," #                      !     #"," #      +     !               #"," #                            #"," #          ! +               #"," #     !               +    ! #"," #                  +         #"," #           +          !     #", " #  +                      !  #"," #      !           +         #"," #+           _____           #"," #           |_ _ _|     +    #"," #     +     |_|||_|          #"," #        +  |MMMMM|         !#"," #           |WWWWW|          #"," #!          |_____|          #"," #                      !     #"," #.        +                 .#"," ##############################", }; 
char ch4[35][35]={"","         ###*###       ########","     ###!      # ##### #     *#"," ###&#+####### # #   # # ######"," #          !# # #-# # # #    #"," ###&#######     # #   # # ## #","           ####### ##### # ## #","  ####&###        !  !  !# ## #","  #       ################ ## #","    ###             !!     ##  "," #### ##&##################### "," #                !         !# "," #-############&######### #&## "," #-#ooooooooooo   o     # #*## "," o ooo   o   o  o o ooo # #### "," o   o o   o   oo o   o #      "," ooo o ooooooo oo ooo o #######"," ooo o o   o   oo     o       #"," ooo   o o o*oooooooooooooooo-#"," ooooooo o oo   o   o   o   o #"," )       o    o   o   o   o   #",};
char ch5[35][35]={"","  oooo     oooooooooooooooooooo","       ooo    o   oo+oo   o   o"," ooooooo*oooo !   o   ! o   o o"," o          o  o    o   o   o o"," oooooooooo ooooooooooooooooo o"," o     !       !              o"," oooooooo ooooooooooooooooooooo"," oooooooo ooooooooooooooooooooo", " o              !             o"," o^^^^^^^^^^^^^^^^^^^^^^^^^^^^o"," o    !   !   !   !   !       o"," o^^^^^^^^^^^^^^^^^^^^^^^^^^^^o"," o^*^! !^! !^!  ^^! +^! !^! *^o"," o^^^^^^^^^^^^^^^^^^^^^^^^^^^^o"," o   !   !   !   !   !        o"," #^^^^^^^^^^^^^^^^^^^^^^^^^^^^#"," #                 !          #"," ####oooooooooo--oooooooooooo##"," ########oooooo--ooooooo#######"," ###########ooo))oooo##########", };
char ch6[35][35]={""," oooooooooooooo .oooooooooooooo"," o+oooooooooooo  oooooooooooo+o"," ooooooooooooo#  #ooooooooooooo"," oooooooooooo#^^^^#oooooooooooo"," oooo*oooooo#^    ^#oooooo*oooo"," oooooooooo# ^    ^ #oooooooooo"," ooooooooo#  ^    ^  #ooooooooo"," oooooooo#^^^^^^^^^^^^#oooooooo"," ooooooo#^   ^#--#^   ^#ooooooo"," .       ^   ^-NO-^   ^         ","         ^   ^-IP-^   ^       ."," ooooooo#^   ^#--#^   ^#ooooooo"," oooooooo#^^^^^^^^^^^^#oooooooo"," ooooooooo#  ^    ^  #ooooooooo"," oooooooooo# ^    ^ #oooooooooo"," oooo*oooooo#^    ^#oooooo*oooo"," oooooooooooo#^^^^#oooooooooooo"," ooooooooooooo#  #ooooooooooooo"," o+oooooooooooo  oooooooooooo+o"," oooooooooooooo. oooooooooooooo",};
void map1(int x,int y,int k){
    for(int i=1;i<=20;++i)
    for(int j=1;j<=30;++j){
        bool f=1;
        for (int l=1;l<=k;++l)
        if (xg[l].xgx==i&&xg[l].xgy==j&&xg[l].sw==0) {Setpos(i,j);Color(4),cout<<"▼";f=0;break;}
        if (f==1)
        {Setpos(i,j);
        if (i==x&&j==y) Color(1),cout<<"●";
        else if (ch[i][j]=='#'||ch[i][j]=='&') Color(7),cout<<"■";
        else if (ch[i][j]==')') Color(5),cout<<"☆";
        else if (ch[i][j]=='*') Color(5),cout<<"♂";
        else if (ch[i][j]=='-') Color(3),cout<<"▋"; 
        else if (ch[i][j]=='+') Color(2),cout<<"◆";
        else if (ch[i][j]=='.') Color(1),cout<<"◆";
        else if (ch[i][j]=='o') Color(8),cout<<"~ "; 
        else if (ch[i][j]=='_') Color(3),cout<<"▁";
        else if (ch[i][j]=='^') Color(3),cout<<"▲";
        else if (ch[i][j]=='|') Color(3),cout<<"|";
        else if (ch[i][j]=='M') Color(3),cout<<'M'<<'M';
        else if (ch[i][j]=='W') Color(3),cout<<'W'<<'W';
        else if (ch[i][j]=='N') Color(2),cout<<"NO";
        else if (ch[i][j]=='I') Color(2),cout<<"..";
        else if (ch[i][j]=='O') Color(2),cout<<"I!";
        else if (ch[i][j]=='P') Color(2),cout<<".P";
        else Color(0),cout<<"  ";
        }
    }
    Setpos(21,3);Color(5),cout<<"["<<ys<<" ♂]      ",Color(2),cout<<"["<<hd<<" ◆]";
}
int yx(int a)
{
    int k=0,T=0,x,y,boss=0,win=0;ys=0,hd=0,sj=0;
    system("cls");
if(a==1) {for(int i=0;i<35;i++)for(int j=0;j<35;j++) ch[i][j]=ch1[i][j];x=1,y=1;}
if(a==2) {for(int i=0;i<35;i++)for(int j=0;j<35;j++) ch[i][j]=ch2[i][j];x=2,y=29;}
if(a==3) {for(int i=0;i<35;i++)for(int j=0;j<35;j++) ch[i][j]=ch3[i][j];x=10,y=15;boss=1;}
if(a==4) {for(int i=0;i<35;i++)for(int j=0;j<35;j++) ch[i][j]=ch4[i][j];x=1,y=1;}
if(a==5) {for(int i=0;i<35;i++)for(int j=0;j<35;j++) ch[i][j]=ch5[i][j];x=1,y=1;}
if(a==6) {for(int i=0;i<35;i++)for(int j=0;j<35;j++) ch[i][j]=ch6[i][j];x=1,y=15;boss=2;}
    if(boss==1){for (int i=1;i<=200;++i) {int xx=rand()%21,yy=rand()%31;if ((xx!=x||yy!=y)&&ch[xx][yy]!='_'&&ch[xx][yy]!='W'&&ch[xx][yy]!='|'&&ch[xx][yy]!='M'&&ch[xx][yy]!='.') ch[xx][yy]='o';}map1(x,y,k);} 
    for(int i=1;i<35;++i)for(int j=1;j<35;++j) if (ch[i][j]=='!')k++,xg[k].xgx=i,xg[k].xgy=j,ch[i][j]=' ';
    map1(x,y,k);

while (1)
{
    T++;
        Setpos(x,y),cout<<"  ";
        if(GetAsyncKeyState(VK_UP)&0x8000&&x!=1&&ch[x-1][y]!='#') x--;
        else if(GetAsyncKeyState(VK_DOWN)&0x8000&&x!=20&&ch[x+1][y]!='#') x++;
        else if(GetAsyncKeyState(VK_LEFT)&0x8000&&y!=1&&ch[x][y-1]!='#') y--;
        else if(GetAsyncKeyState(VK_RIGHT)&0x8000&&y!=30&&ch[x][y+1]!='#') y++;
        Setpos(x,y),Color(1),cout<<"●";

    if(boss!=0&&T%20==5){
        for (int i=1;i<=20;++i)for (int j=1;j<=30;++j)if (ch[i][j]=='o') ch[i][j]=' ';
        for (int i=1;i<=200*boss;++i) {int xx=rand()%21,yy=rand()%31;if ((xx!=x||yy!=y)&&ch[xx][yy]==' ') ch[xx][yy]='o';}
        map1(x,y,k);} 

    if(T%20==0) map1(x,y,k);if(T%20==10){for(int i=1;i<35;++i)for(int j=1;j<35;++j) if(ch[i][j]=='^')Setpos(i,j),cout<<"  ";}
    if(T%4==0&&k!=0)
        for (int i=1;i<=k;i++){
            if (xg[i].fx==0&&(ch[xg[i].xgx][xg[i].xgy+1]==' '||(ch[xg[i].xgx][xg[i].xgy-1]=='^'&&T%20>=10))&&xg[i].xgy!=30)     Setpos(xg[i].xgx,xg[i].xgy),cout<<"  ",xg[i].xgy++,Setpos(xg[i].xgx,xg[i].xgy),Color(4),cout<<"▼";
            else if (xg[i].fx==1&&(ch[xg[i].xgx][xg[i].xgy-1]==' '||(ch[xg[i].xgx][xg[i].xgy-1]=='^'&&T%20>=10))&&xg[i].xgy!=1) Setpos(xg[i].xgx,xg[i].xgy),cout<<"  ",xg[i].xgy--,Setpos(xg[i].xgx,xg[i].xgy),Color(4),cout<<"▼";
            else if (xg[i].fx==1) xg[i].fx=0;else xg[i].fx=1;}
    for (int i=1;i<=k;i++){
        if (xg[i].xgx==x&&xg[i].xgy==y&&xg[i].sw==0&&hd==0) {system("cls");cout<<"怪物啊!!!";Sleep(2000);system("cls");return 0;}
        else if (xg[i].xgx==x&&xg[i].xgy==y&&hd>0&&xg[i].sw==0) {system("cls");cout<<"护盾保护了你!";Sleep(1000);system("cls");map1(x,y,k);hd--;xg[i].sw=1;}}

    if (ch[x][y]==')') {system("cls");cout<<"You Win!";Sleep(2000);system("cls");win=1;}
    if (ch[x][y]=='*') {system("cls");cout<<"你找到了钥匙!";ys++;Sleep(1000);system("cls");map1(x,y,k);ch[x][y]=' ';} 
    if (ch[x][y]=='.') {system("cls");cout<<"你破坏了水晶!";sj++;Sleep(1000);system("cls");map1(x,y,k);ch[x][y]=' ';}
    if (ch[x][y]=='-'&&ys>0) {system("cls");cout<<"门开了!";ys--;Sleep(1000);system("cls");map1(x,y,k);ch[x][y]=' ';}else if (ch[x][y]=='-') {system("cls");cout<<"你没有钥匙!";--x;Sleep(3000);system("cls");map1(x,y,k);}
    if (ch[x][y]=='+') {system("cls");cout<<"你找到了护盾!";hd++;Sleep(1000);system("cls");map1(x,y,k);ch[x][y]=' ';}
    if (ch[x][y]=='o'&&hd==0) {system("cls");cout<<"烫死啦!!!";Sleep(2000);return 0;} 
    else if (hd>0&&ch[x][y]=='o') {system("cls");cout<<"护盾保护了你!";ch[x][y]=' ';hd--;Sleep(1000);system("cls");map1(x,y,k);} 
    if (ch[x][y]=='^'&&T%20<10&&hd==0) {system("cls");cout<<"被刺穿啦!!!";Sleep(2000);return 0;} 
    else if (hd>0&&ch[x][y]=='^'&&T%20<10) {system("cls");cout<<"护盾保护了你!";ch[x][y]=' ';hd--;Sleep(1000);system("cls");map1(x,y,k);} 

    if ((a==3||a==6)&&sj==4)   {system("cls");cout<<"You Win!";Sleep(2000);system("cls");win=1;}

    for (int i=1;i<=k;i++)
        if (xg[i].xgx==x&&xg[i].xgy==y&&xg[i].sw==0&&hd==0) {system("cls");cout<<"怪物啊!!!";Sleep(1000);system("cls");return 0;}
        else if (xg[i].xgx==x&&xg[i].xgy==y&&hd>0&&xg[i].sw==0) {system("cls");cout<<"护盾保护了你!";Sleep(1000);system("cls");map1(x,y,k);map1(x,y,k);hd--;xg[i].sw=1;}
    if(win==1){if(a==1)sl=1;if(a==2)mg=1;if(a==3)hp=1;if(a==4)hss=1;if(a==5)hsx=1;return 0;}
Sleep(100);
}}
bool dd()
{
    system("cls");cout<<"9%......";Sleep(200);system("cls");cout<<"26%......";Sleep(200);system("cls");cout<<"33%......";Sleep(200);system("cls");cout<<"47%......";Sleep(200);system("cls");cout<<"68%......";Sleep(200);system("cls");cout<<"82%......";Sleep(200);system("cls");cout<<"94%......";Sleep(200);system("cls");cout<<"100%......"<<endl;
    int r=rand()%5;R[r]++;
    if(R[0]==1){R[0]=2;Sleep(1000),cout<<"你TM以为我会让你进去吗哈哈哈！",Sleep(1000);int k=100;while(k!=0) k--,Setpos(0,0),cout<<k<<"%......   ",Sleep(20);return 0;}
    if(R[1]==1){R[1]=2;Sleep(1000),cout<<"你TM以为这就结束了吗哈哈哈！等到10000吧！",Sleep(1000);int k=100;while(k<=200)k++,Setpos(0,0),cout<<k<<"%......   ",Sleep(10);while(k<=1050) k+=9,Setpos(0,0),cout<<k<<"%......   ",Sleep(10);while(k<=4900) k+=123,Setpos(0,0),cout<<k<<"%......   ",Sleep(10);while(k<=9920) k+=467,Setpos(0,0),cout<<k<<"%......   ",Sleep(10);while(k<=9999) k++,Setpos(0,0),cout<<k<<"%......   ",Sleep(10);}
    if(R[2]==1){R[2]=2;int k=99,i=1;Sleep(1000),Setpos(0,0),cout<<"99%...... ",Sleep(1000);while(i<=8){i++;if(i%2==1)k++;if(i%2==0)k--;Setpos(0,0),cout<<k<<"%......   ",Sleep(1000);if(i==3) Setpos(1,0),cout<<"啊咧咧咧......";}cout<<"100%......"<<endl;}
    if(R[3]==1){R[3]=2;Sleep(1000);SlowDisplay(50,"\nWarning!\nSYSTEM ERROR...\nThe system is about to collapse......"),Sleep(500);int k=0;while(k!=2000){k++;int R=rand()%5+1;int p;for(int j=1;j<=R;j++) p=rand()%10+'0',printf("%c",p);cout<<"%......\n";}cout<<"100%......"<<endl;}
    if(R[4]==1){R[4]=2;Setpos(0,0),cout<<"99%...... ";Sleep(1000),cout<<"long double !",Sleep(1000);double k,i=1.1;while(i<=12){i+=0.1,k=100.0-1.0/(double)i,Setpos(0,0),printf("%0.7f",k),cout<<"%......   ",Sleep(1);}cout<<"100%......"<<endl;}
    system("cls");
    return 1;
}
void ml(){while(1){
    system("cls");Color(0); 
    cout<<"1、迷雾森林   ";cout<<endl;
    if (sl==0) cout<<"2、 ? ? ? ?   ";else cout<<"2、巨石迷宫（图中如果走可穿透墙，能避开所有的怪）   "; cout<<endl;
    if (mg==0) cout<<"3、 ? ? ? ?   ";else cout<<"3、熔岩喷泉（BOSS，图中随机出现熔岩）   ";cout<<endl;
    if (hp==0) cout<<"4、 ? ? ? ?   ";else cout<<"4、火山口（上）   ";cout<<endl;
    if (hss==0) cout<<"5、 ? ? ? ?   ";else cout<<"5、火山口（下）   ";cout<<endl;
    if (hsx==0) cout<<"6、 ? ? ? ?   ";else cout<<"6、火山祭坛（BOSS）";cout<<endl;
    cout<<"选择关卡（序号）"<<endl;cout<<"退出输入0"<<endl;
    int a;cin>>a;
    if (a==1&&dd()) {yx(1);}if (a==2&&sl==1&&dd()){yx(2);}if (a==3&&mg==1&&dd()) {yx(3);}if (a==4&&hp==1&&dd()) {yx(4);}if (a==5&&hss==1&&dd()){yx(5);}if (a==6&&hsx==1&&dd()){yx(6);}if (a==0) return;
}}
void gz() {
    system("cls");
    cout<<"由上下左右键控制"<<endl;
    cout<<"●是你"<<endl;
    cout<<"■是墙"<<endl;
    cout<<"☆是终点"<<endl;
    cout<<"▼是小怪（只会左右移动）"<<endl;
    cout<<"▋是门"<<endl;
    cout<<"♂是钥匙"<<endl;
    cout<<"◆是护盾（不可杀怪）"<<endl;
    cout<<"■是可穿透墙（每一关几乎都有）"<<endl; 
    cout<<"◆是水晶（BOSS关破坏所有水晶通关）"<<endl;
    cout<<"~ 是熔岩"<<endl; 
    cout<<"▁是尖刺（未升起）"<<endl;
    cout<<"▲是尖刺（升起）"<<endl;
    cout<<"输入1开始!"<<endl;
    int a;
    cin>>a;
    if (a==1) ml();
    else gz(); 
}
int main(){ 
    CONSOLE_CURSOR_INFO cursor_info={1,0};SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);srand((unsigned)time(NULL));
    cout<<"欢迎来到超级迷宫！"<<endl;cout<<"作者:whsx"<<endl;cout<<"1、开始！"<<endl;cout<<"2、规则..."<<endl;
    int a;cin>>a;if (a==1){system("cls");ml();}else if (a==2){gz();}
    return 0;
}

