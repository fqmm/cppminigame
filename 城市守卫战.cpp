//# 城市守卫战

#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
using namespace std;
int t,nl,dl,Money,Moo,Dao,Yi,Shan,Qing,Hu;
int Biao,Biaob,Bao=1,Baob,Baod=1,Baodb,Hub,Fengb,Sha,Jian,Shab,Jianb;
int X[10];
bool Daob,Yib,Shanb,Qingb,Hubb;
struct node {int Zhong,Xue,Bing,Hui,Du;} N[100001],D[100001];
void Yan(int a)
{
    if(a==0) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
    if(a==1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
    if(a==2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
    if(a==3) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
    if(a==4) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
    if(a==5) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN);
    if(a>=6) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
}
void Bai() {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);}
void Cout(int x,int a)
{
    Yan(a);int k;
    if(x==1) {if(a==0) cout<<"城墙";if(a==1) cout<<"加农炮";if(a==2) cout<<"重机枪";if(a==3) cout<<"迫击炮";if(a==4) cout<<"喷火器";if(a==5) cout<<"火箭炮";if(a>=6) cout<<"电磁炮";}
    if(x==2)
    {
        if(a==1) cout<<"步兵",Money+=20,k=20;if(a==2) cout<<"骑兵",Money+=30,k=30;if(a==3) cout<<"炮兵",Money+=30,k=30;if(a==4) cout<<"药兵",Money+=30,k=30;if(a==6||a==7) cout<<"炮灰",Money+=10,k=10;if(a==5) cout<<"坦克",Money+=50,k=50;
        if(a==8) Yan(3),cout<<"金刚机甲",Money+=100;if(a==9) Yan(1),cout<<"寒冰机甲",Money+=100;if(a==10) Yan(2),cout<<"木毒机甲",Money+=100;if(a==11) Yan(3),cout<<"飓风机甲",Money+=100;if(a==12) Yan(4),cout<<"烈焰机甲",Money+=100;if(a>=8) k=100;
    }
    Yan(4);Sleep(200),cout<<"......爆！！！";
    if(x==2) Yan(5),cout<<"掉落"<<k<<"金币！";cout<<endl<<endl,Sha++;
    if(Sha%20==0&&Shab<Sha) Yan(5),cout<<"成就：杀死"<<Sha<<"个敌人，完成！加30金币！"<<endl<<endl,Sleep(500),Bai(),Money+=30,Shab=Sha;
    if(Money>=500) Money=500,Yan(3),cout<<"金币储量已达上限！"<<endl<<endl,Bai(),Sleep(500);
    Bai();
}
void War()
{
    int zn=0,zd=0;if(nl-5>0) zn=nl%5;if(dl-5>0) zd=dl%5;cout<<"┌";
    for(int i=0;i<=40;i++) cout<<'-';cout<<"┐"<<endl<<"┆";
    for(int i=5;i>0;i--) if(i>=nl+1) cout<<"    ";
    for(int i=5;i>0;i--)
    {
        if(i>=nl+1) continue;
        Yan(1);if(i<=0) break;
        if(N[i].Bing>0) Yan(6);
        if(N[i].Du>0) Yan(2);
        if(N[i].Hui>0) Yan(3);
        cout<<setw(4)<<N[i].Xue; Bai();
    }
    for(int i=1;i<=5;i++)
    {
        Yan(4);
        if(i>dl) {cout<<"    ";continue;}
        if(Baodb!=0) Yan(2);
        if(D[i].Zhong>=8) Yan(3);
        cout<<setw(4)<<D[i].Xue; Bai();
    }Bai();
    cout<<" ┆"<<endl<<"┆";
    for(int i=5;i>0;i--) if(i>=nl+1) cout<<"    ";
    for(int i=5;i>0;i--)
    {
        if(i>=nl+1) continue;
        Yan(N[i].Zhong);if(N[i].Bing>0) Yan(6);
        if(N[i].Zhong==0) cout<<"  ▎";if(N[i].Zhong==1) cout<<"  ●";if(N[i].Zhong==2) cout<<"  ■";if(N[i].Zhong==3) cout<<"  ▲";if(N[i].Zhong==4) cout<<"  ▼";if(N[i].Zhong==5) cout<<"  ★";if(N[i].Zhong>=6) cout<<"  ◆"; 
        Bai();
    }
    for(int i=1;i<=5;i++)
    {
        if(i>dl) {cout<<"    ";continue;}
        Yan(D[i].Zhong);if(D[i].Bing>0) Yan(4);
        if(D[i].Zhong==1) cout<<"  ○";if(D[i].Zhong==2) cout<<"  □";if(D[i].Zhong==3) cout<<"  △";if(D[i].Zhong==4) cout<<"  ▽";if(D[i].Zhong==5) cout<<"  ☆";if(D[i].Zhong>=6&&D[i].Zhong<=7) cout<<"  ◇";if(D[i].Zhong==8) Yan(5),cout<<"  金";if(D[i].Zhong==9) Yan(1),cout<<"  冰";if(D[i].Zhong==10) Yan(2),cout<<"  毒";if(D[i].Zhong==11) Yan(3),cout<<"  风";if(D[i].Zhong==12) Yan(4),cout<<"  火";
        Bai();
    }
    if(zn>0||zd>0)
    {
    cout<<" ┆"<<endl<<"┆";
    for(int i=5-zn;i>0;i--) cout<<"    ";
    for(int i=5+zn;i>5;i--)
    {
        Yan(1);if(i<=0) break;
        if(N[i].Bing>0) Yan(6);
        if(N[i].Du>0) Yan(2);
        if(N[i].Hui>0) Yan(3);
        cout<<setw(4)<<N[i].Xue; Bai();
    }
    for(int i=6;i<=10;i++)
    {
        Yan(4);
        if(i>dl) {cout<<"    ";continue;}
        if(Baodb!=0) Yan(2);
        if(D[i].Zhong>=8) Yan(3);
        cout<<setw(4)<<D[i].Xue; Bai();
    }Bai();
    cout<<" ┆"<<endl<<"┆";
    for(int i=5-zn;i>0;i--) {cout<<"    ";continue;}
    for(int i=5+zn;i>5;i--)
    {
        Yan(N[i].Zhong);if(N[i].Bing>0) Yan(6);
        if(N[i].Zhong==0) cout<<"  ▎";if(N[i].Zhong==1) cout<<"  ●";if(N[i].Zhong==2) cout<<"  ■";if(N[i].Zhong==3) cout<<"  ▲";if(N[i].Zhong==4) cout<<"  ▼";if(N[i].Zhong==5) cout<<"  ★";if(N[i].Zhong>=6) cout<<"  ◆"; 
        Bai();
    }
    for(int i=6;i<=10;i++)
    {
        if(i>dl) {cout<<"    ";continue;}
        Yan(D[i].Zhong);if(D[i].Bing>0) Yan(4);
        if(D[i].Zhong==1) cout<<"  ○";if(D[i].Zhong==2) cout<<"  □";if(D[i].Zhong==3) cout<<"  △";if(D[i].Zhong==4) cout<<"  ▽";if(D[i].Zhong==5) cout<<"  ☆";if(D[i].Zhong>=6&&D[i].Zhong<=7) cout<<"  ◇";if(D[i].Zhong==8) Yan(5),cout<<"  金";if(D[i].Zhong==9) Yan(1),cout<<"  冰";if(D[i].Zhong==10) Yan(2),cout<<"  毒";if(D[i].Zhong==11) Yan(3),cout<<"  风";if(D[i].Zhong==12) Yan(4),cout<<"  火";
        Bai();
    }
    }
    cout<<" ┆"<<endl<<"└";
    for(int i=0;i<=40;i++) cout<<'-';cout<<"┘"<<endl;
    Sleep(500);
}
void Ju(int a)
{
    Sleep(1000);system("cls");Bai();
    if(a==0)
    {
        cout<<"┌---------------------┐"<<endl;
        cout<<"┆新道具解锁！         ┆"<<endl;
        cout<<"┆                     ┆"<<endl;
        cout<<"┆导弹：               ┆"<<endl;
        cout<<"┆攻击力：300          ┆"<<endl;
        cout<<"┆目标：指定目标       ┆"<<endl;
        cout<<"└---------------------┘"<<endl;
    }
    if(a==1)
    {
        cout<<"┌---------------------┐"<<endl;
        cout<<"┆新道具解锁！         ┆"<<endl;
        cout<<"┆                     ┆"<<endl;
        cout<<"┆医疗包：             ┆"<<endl;
        cout<<"┆目标：指定目标       ┆"<<endl;
        cout<<"┆攻击力：-30*5（回血）┆"<<endl;
        cout<<"┆持续时间：5回合      ┆"<<endl;
        cout<<"└---------------------┘"<<endl;
    }
    if(a==2)
    {
        cout<<"┌---------------------┐"<<endl;
        cout<<"┆新道具解锁！         ┆"<<endl;
        cout<<"┆                     ┆"<<endl;
        cout<<"┆闪光弹：             ┆"<<endl;
        cout<<"┆目标：指定目标       ┆"<<endl;
        cout<<"┆效果：使一个指定敌人 ┆"<<endl;
        cout<<"┆    停止攻击，并使所 ┆"<<endl;
        cout<<"┆    有炮塔攻击该敌人.┆"<<endl;
        cout<<"┆持续时间：5回合      ┆"<<endl;
        cout<<"└---------------------┘"<<endl;
    }
    if(a==3)
    {
        cout<<"┌---------------------┐"<<endl;
        cout<<"┆新道具解锁！         ┆"<<endl;
        cout<<"┆                     ┆"<<endl;
        cout<<"┆狂暴血清：           ┆"<<endl;
        cout<<"┆目标：所有炮塔       ┆"<<endl;
        cout<<"┆效果：使炮塔攻击2次  ┆"<<endl;
        cout<<"┆持续时间：2回合      ┆"<<endl;
        cout<<"└---------------------┘"<<endl;
    }
    if(a==4)
    {
        cout<<"┌---------------------┐"<<endl;
        cout<<"┆新道具解锁！         ┆"<<endl;
        cout<<"┆                     ┆"<<endl;
        cout<<"┆无敌护罩：           ┆"<<endl;
        cout<<"┆效果：使所有炮塔无敌 ┆"<<endl;
        cout<<"┆持续时间：3回合      ┆"<<endl;
        cout<<"└---------------------┘"<<endl;
    }
    Sleep(1000);system("pause");system("cls");
}
void Die(int m)
{
    if(D[m].Xue<=0)
    {
        if(Biao==m) Biao=0;
        if(D[m].Zhong>=8) Moo=0;
        Cout(2,D[m].Zhong);
        for(int i=m;i<dl;i++)
        {
            if(Biao==i) Biao--;
            D[i].Xue=D[i+1].Xue;
            D[i].Zhong=D[i+1].Zhong;
            D[i].Bing=D[i+1].Bing;
        }
        D[dl].Xue=0,D[dl].Zhong=0,D[dl].Bing=0;dl--;
        int a=rand()%10;
        if(a==0&&t<1000)
        {
            Yan(4);
            cout<<"从敌人尸体中发现道具——"; Sleep(500);
            int b=rand()%5;
            if(b==0) {cout<<"导弹！"<<endl<<endl,Dao++;Sleep(2000);if(Daob==0) Ju(0);Daob=1;}
            if(b==1) {cout<<"医疗包！"<<endl<<endl,Yi++;Sleep(2000);if(Yib==0) Ju(1);Yib=1;}
            if(b==2) {cout<<"闪光弹！"<<endl<<endl,Shan++;Sleep(2000);if(Shanb==0) Ju(2);Shanb=1;}
            if(b==3) {cout<<"狂暴血清！"<<endl<<endl,Qing++;Sleep(2000);if(Qingb==0) Ju(3);Qingb=1;}
            if(b==4) {cout<<"无敌护罩！"<<endl<<endl,Hu++;Sleep(2000);if(Hubb==0) Ju(4);Hubb=1;}
            Bai();War();
        }
    }
}
void DieN(int m)
{
    if(N[m].Xue<=0)
    {
        Cout(1,N[m].Zhong);
        for(int i=m;i<nl;i++)
        {
            N[i].Xue=N[i+1].Xue;
            N[i].Zhong=N[i+1].Zhong;
            N[i].Bing=N[i+1].Bing;
            N[i].Hui=N[i+1].Hui;
        }
        N[nl].Xue=0,N[nl].Zhong=0,N[nl].Bing=0,N[nl].Hui=0;nl--;
    }
}
void Zao(int a)
{
    if((a==1&&Money<100)||(a==2&&(Money<120||X[2]>=5))||(a==3&&(Money<150||X[3]>=5))||(a==4&&(Money<200||X[4]>=3))||(a==5&&(Money<250||X[0]>0))||(a==6&&(Money<270||X[6]+X[7]+X[8]>=2))||(a==7&&(Money<300||X[5]>=3)))
    {Yan(3),cout<<endl<<"无效输入。",Bai( );Sleep(500);return;}nl++;
    if(a==1) N[nl].Xue=100,N[nl].Zhong=1,Money-=100;
    if(a==2) N[nl].Xue=80,N[nl].Zhong=2,Money-=120;
    if(a==3) N[nl].Xue=150,N[nl].Zhong=3,Money-=150;
    if(a==4) N[nl].Xue=200,N[nl].Zhong=4,Money-=200;
    if(a==5){N[nl].Xue=N[nl].Zhong=0,Money-=250;for(int i=nl;i>0;i--) swap(N[i],N[i-1]);N[1].Xue=500;}
    if(a==6) N[nl].Xue=400,N[nl].Zhong=6,Money-=270;
    if(a==7) N[nl].Xue=300,N[nl].Zhong=5,Money-=300;
    Yan(5);cout<<endl<<"建造成功！"<<endl<<endl;Sleep(500);cout<<"你的金币数量："<<Money;Bai();Jian++;
    if(Jian%10==0&&Jianb<Jian) Yan(5),cout<<endl<<endl<<"成就：建造"<<Jian<<"个炮塔，完成！加30金币！",Sleep(500),Bai(),Money+=30,Jianb=Jian;
    if(Money>=300) Money=300,Yan(3),cout<<"金币储量已达上限！"<<endl<<endl,Bai(),Sleep(500);
}
void ZaoN(int a)
{
    dl++;
    if(a==1) D[dl].Xue=50,D[dl].Zhong=1;
    if(a==2) D[dl].Xue=100,D[dl].Zhong=2;
    if(a==3) D[dl].Xue=30,D[dl].Zhong=3;
    if(a==4) D[dl].Xue=100,D[dl].Zhong=4;
    if(a==5) D[dl].Xue=200,D[dl].Zhong=5;
    if(a==6) D[dl].Xue=10,D[dl].Zhong=6;
    if(a>=8) D[dl].Xue=1000,D[dl].Zhong=a;
}
void Yong(int a)
{
    int b;
    if(a==0) return;
    if((a==1&&Dao==0)||(a==2&&Yi==0)||(a==3&&Shan==0)||(a==4&&Qing==0)||(a==5&&Hu==0)) {cout<<"无效输入。"<<endl;Sleep(500);return;}
    if(a==1)
    {
        cout<<endl<<"导弹随时准备发射！";Sleep(500);cout<<"目标是第几个敌人？-- ";
        char b=_getch();cout<<b<<endl;b-=48; if(b>dl||b<=0) {cout<<"无效输入。"<<endl;Sleep(500);return;}
        Yan(4),cout<<endl<<"导弹发射！命中目标！"<<endl<<endl;Bai(),D[b].Xue-=300;Die(b),Bai(),Dao--; return;
    }
    if(a==2)
    {
        cout<<endl<<"医疗包随时准备空投！";Sleep(500);cout<<"目标是第几个炮塔？-- ";
        char b=_getch();cout<<b<<endl;b-=48; if(b>nl||b<=0) {cout<<"无效输入。"<<endl;Sleep(500);return;}
        Yan(4),cout<<endl<<"医疗包开始医疗！"<<endl<<endl;Bai(),N[nl-b+1].Hui+=5,Bai(),Yi--; return;
    }
    if(a==3)
    {
        cout<<endl<<"闪光弹随时准备发射！";Sleep(500);cout<<"目标是第几个敌人？-- ";
        char b=_getch();cout<<b<<endl;b-=48; if(b>dl||b<=0) {cout<<"无效输入。"<<endl;Sleep(500);return;}
        Yan(4),cout<<endl<<"闪光弹发射！命中目标！"<<endl<<endl;Bai(),Biao=b,D[b].Bing+=5,Biaob+=5,Shan--; return;
    }
    if(a==4) cout<<endl<<"狂暴血清爆发！"<<endl<<endl,Bai(),Baob+=2,Bai(),Qing--;
    if(a==5) cout<<endl<<"无敌护罩开启！"<<endl<<endl,Bai(),Hub+=3,Bai(),Hu--;
}
void Mo()
{
    int x=rand()%5;
    if(x==0)
    {
        Yan(5);
        cout<<"金刚机甲出现了！"<<endl<<endl;
        Sleep(1000);system("cls");Bai();
        cout<<"┌-----------------------------┐"<<endl;
        cout<<"┆新敌人出现！                 ┆"<<endl;
        cout<<"┆                             ┆"<<endl;
        cout<<"┆金刚机甲：                   ┆"<<endl;
        cout<<"┆特殊技能——扫射：           ┆"<<endl;
        cout<<"┆     攻击力：40*n            ┆"<<endl;
        cout<<"┆     目标：所有炮塔          ┆"<<endl;
        cout<<"┆攻击力：200                  ┆"<<endl;
        cout<<"┆目标：第一个炮塔             ┆"<<endl;
        cout<<"┆血量：1000                   ┆"<<endl;
        cout<<"┆掉落金币：100                ┆"<<endl;
        cout<<"┆符号： ";Yan(5);cout<<"金";Bai();cout<<"                    ┆"<<endl;
        cout<<"└-----------------------------┘"<<endl;Sleep(2000);
        system("pause");system("cls");
        ZaoN(8);
    }
    if(x==1)
    {
        Yan(1);
        cout<<"寒冰机甲出现了！"<<endl<<endl;
        Sleep(1000);system("cls");Bai();
        cout<<"┌-----------------------------┐"<<endl;
        cout<<"┆新敌人出现！                 ┆"<<endl;
        cout<<"┆                             ┆"<<endl;
        cout<<"┆寒冰机甲：                   ┆"<<endl;
        cout<<"┆特殊技能——冰冻：           ┆"<<endl;
        cout<<"┆   攻击力：30                ┆"<<endl;
        cout<<"┆   效果：冰冻任意一个炮塔    ┆"<<endl;
        cout<<"┆     持续时间：3回合         ┆"<<endl;
        cout<<"┆血量：1000                   ┆"<<endl;
        cout<<"┆掉落金币：100                ┆"<<endl;
        cout<<"┆符号： ";Yan(1);cout<<"冰";Bai();cout<<"                    ┆"<<endl;
        cout<<"└-----------------------------┘"<<endl;Sleep(2000);
        system("pause");system("cls");
        ZaoN(9);
    }
    if(x==2)
    {
        Yan(2);                         
        cout<<"木毒机甲出现了！"<<endl<<endl;
        Sleep(1000);system("cls");Bai();
        cout<<"┌-----------------------------┐"<<endl;
        cout<<"┆新敌人出现！                 ┆"<<endl;
        cout<<"┆                             ┆"<<endl;
        cout<<"┆木毒机甲：                   ┆"<<endl;                                                                      
        cout<<"┆特殊技能——狂毒：           ┆"<<endl;
        cout<<"┆   效果：使每个敌人攻击2次   ┆"<<endl;
        cout<<"┆   持续时间：2回合           ┆"<<endl;
        cout<<"┆攻击力：10*4                 ┆"<<endl;
        cout<<"┆目标：所有炮塔               ┆"<<endl;
        cout<<"┆持续时间：4回合              ┆"<<endl;
        cout<<"┆血量：1000                   ┆"<<endl;
        cout<<"┆符号： ";Yan(2);cout<<"毒";Bai();cout<<"                    ┆"<<endl;
        cout<<"└-----------------------------┘"<<endl;Sleep(2000);                       
        system("pause");system("cls");
        ZaoN(10);
    }
    if(x==3)
    {
        Yan(3);
        cout<<"飓风机甲出现了！"<<endl<<endl;
        Sleep(1000);system("cls");Bai();
        cout<<"┌-----------------------------┐"<<endl;
        cout<<"┆新敌人出现！                 ┆"<<endl;
        cout<<"┆                             ┆"<<endl;
        cout<<"┆飓风机甲：                   ┆"<<endl;
        cout<<"┆特殊技能——幻风：           ┆"<<endl;
        cout<<"┆   攻击力：50*2（对炮塔）    ┆"<<endl;
        cout<<"┆   效果：调换2个单位的位置   ┆"<<endl;
        cout<<"┆   目标：任意2个炮塔或敌人   ┆"<<endl;
        cout<<"┆攻击力：30%*该炮塔血量       ┆"<<endl;
        cout<<"┆目标：前三个炮塔             ┆"<<endl;
        cout<<"┆血量：1000                   ┆"<<endl;
        cout<<"┆符号： ";Yan(3);cout<<"风";Bai();cout<<"                    ┆"<<endl;
        cout<<"└-----------------------------┘"<<endl;Sleep(2000);
        system("pause");system("cls");
        ZaoN(11);
    }
    if(x==4)
    {
        Yan(4);
        cout<<"烈焰机甲出现了！"<<endl<<endl;
        Sleep(1000);system("cls");Bai();
        cout<<"┌-----------------------------┐"<<endl;
        cout<<"┆新敌人出现！                 ┆"<<endl;
        cout<<"┆                             ┆"<<endl;
        cout<<"┆烈焰机甲：                   ┆"<<endl;
        cout<<"┆特殊技能——火球：           ┆"<<endl;
        cout<<"┆   攻击力：30*5              ┆"<<endl;
        cout<<"┆   目标：任意五个炮塔        ┆"<<endl;
        cout<<"┆攻击力：40+30+20+10+5        ┆"<<endl;
        cout<<"┆目标：前五个炮塔             ┆"<<endl;
        cout<<"┆血量：1000                   ┆"<<endl;
        cout<<"┆符号： ";Yan(4);cout<<"火";Bai();cout<<"                    ┆"<<endl;
        cout<<"└-----------------------------┘"<<endl;Sleep(2000);
        system("pause");system("cls");
        ZaoN(12);
    }
    Moo=1;
}
void Mai(int x)
{
    char a;
    if(x==0) Money+=10,Yan(5),Sleep(500),cout<<"你的金币+10。"<<endl<<endl,Bai();
    if(x==1) Money+=30,Yan(3),Sleep(500),cout<<"机甲临城，",Yan(5),cout<<"你的金币+30。"<<Money<<endl<<endl,Bai();
    if(Money>=300) Money=300,Yan(3),cout<<"金币储量已达上限！"<<endl<<endl,Bai(),Sleep(500);
    Yan(5),Sleep(500),cout<<"你的金币数量："<<Money<<endl<<endl,Bai(),Sleep(500);
    y:
    while(Money>=100)
    {
        memset(X,0,sizeof(X));
        for(int i=1;i<=nl;i++) X[N[i].Zhong]++;
        if(Money>=100) cout<<"你现在可以购买：1.加农炮（100金币）  ";if(Money>=120&&X[2]<5) cout<<"2.重机枪（120金币）  ";if(Money>=150&&X[3]<5) cout<<"3.迫击炮（150金币）  ";if(Money>=200&&X[4]<3) cout<<"4.喷火器  ";
        if(Money>=250&&X[0]==0) cout<<"5.城墙（250金币）  ";if(Money>=270&&X[6]+X[7]+X[8]<2) cout<<"6.电磁炮（270金币）  ";if(Money>=300&&X[5]<3) cout<<"7.火箭炮（300金币）";
        if(Money>=100)
        {
            cout<<endl<<endl<<"---你想购买什么？（按0取消）---  ";a=_getch();cout<<a<<endl;
            if(a=='0') break;
            if(a<'0'||a>'7') {cout<<"无效输入。"<<endl<<endl;Sleep(500);goto y;}
            Zao(a-'0');cout<<endl<<endl;Bai();War();
            goto y;
            Yan(5),Sleep(500),cout<<"你的金币数量："<<Money<<endl<<endl,Bai(),Sleep(500);
        }
    }cout<<endl;
    z:
    while(Dao>0||Yi>0||Shan>0||Qing>0||Hu>0)
    {
        War();
        if(Dao>0||Yi>0||Shan>0||Qing>0||Hu>0) cout<<"你现在可以使用："; if(Dao>0) cout<<"1.导弹("<<Dao<<"个) ";if(Yi>0) cout<<"2.医疗包("<<Yi<<"个) ";if(Shan>0) cout<<"3.闪光弹("<<Shan<<"个) ";if(Qing>0) cout<<"4.狂暴血清("<<Qing<<"个) ";if(Hu>0) cout<<"5.无敌护罩("<<Hu<<"个) ";
        if(Dao>0||Yi>0||Shan>0||Qing>0||Hu>0)
        {
            cout<<endl<<endl<<"---你想使用什么？（按0取消）---  ";a=_getch();cout<<a<<endl;
            if(a=='0') break;
            if(a<'0'||a>'9') {cout<<"无效输入。"<<endl<<endl;Sleep(500);goto y;}
            Yong(a-'0');cout<<endl<<endl;
            goto z;
        }
    }cout<<endl;
}
void Chu(int y)
{
    if(y<=1) Yan(1),cout<<"呀！来了个步兵！"<<endl<<endl,ZaoN(1);
    if(y>=2&&y<4) Yan(2),cout<<"呀！来了个骑兵！"<<endl<<endl,ZaoN(2);
    if(y>=4&&y<5) Yan(3),cout<<"呀！来了个炮兵！"<<endl<<endl,ZaoN(3);
    if(y>=5&&y<6) Yan(4),cout<<"呀！来了个药兵！"<<endl<<endl,ZaoN(4);
    if(y>=6&&y<7) Yan(6),cout<<"呀！来了个炮灰！"<<endl<<endl,ZaoN(6);
    if(y>=7&&y<10) Yan(5),cout<<"呀！来了个坦克！"<<endl<<endl,ZaoN(5);
    if(y>=10) cout<<"没有新敌人出现。"<<endl<<endl;
    Sleep(1000);
}
void Huo(int n)
{
    Sleep(100);
    bool k[31];int R=15+rand()%11;
    memset(k,0,sizeof(k));
    for(int i=1;i<=7;i++)
    {
        int y=rand()%n+1;
        if(Biao!=0) y=Biao; 
        D[y].Xue-=R;
        k[y]=1;
        cout<<y;Sleep(50);
        if(i!=7) cout<<"、";Sleep(50);
    }cout<<"个目标，";Sleep(100);cout<<R<<"*7点伤害！"<<endl<<endl;
    for(int i=30;i>0;i--) if(k[i]==1) Die(i);
}
void Jiu(int n)
{
    Sleep(100);int R=15+rand()%11;
    int y=rand()%n+1;
    D[y].Xue+=R;
    cout<<y;Sleep(100);
    cout<<"个目标，";Sleep(100);cout<<R<<"点血！"<<endl<<endl;
    Bai(); War();
}
void Bjing(int n,int i)
{
    int x=rand()%5;int y=rand()%10;int R=190+rand()%21,R2=30+rand()%21;
    if(x==0&&D[i].Bing==0){ Yan(4),cout<<"金刚机甲锤击！"<<R<<"点伤害！"<<endl<<endl;if(Hub==0&&D[i].Bing==0) N[1].Xue-=R,DieN(1);return;}
    if(x>=1&&x<3&&D[i].Bing==0)
    {
        Yan(4),cout<<"金刚机甲扫射！"<<R2<<"*"<<nl<<"点伤害！"<<endl<<endl;
        if(Hub==0&&D[i].Bing==0) for(int i=1;i<=nl;i++) N[i].Xue-=R2,DieN(i);return;
    }
    if(nl<4&&dl>=3) {cout<<"金刚机甲蓄力。"<<endl<<endl;return;}
    if(x==3) {Yan(4),cout<<"金刚机甲召唤！"<<endl<<endl;Chu(y);Bai();War();}
    if(x==4) {Yan(4),cout<<"金刚机甲召唤！"<<endl<<endl;Chu(y);if(dl<3) y=rand()%10,Chu(y);Bai();War();}
    Bai();Sleep(100);
}
void Bbing(int n,int i)
{
    int x=rand()%5;int y=rand()%n+1;int z=rand()%10;int R=20+rand()%21;
    if(x<2&&D[i].Bing==0)
    {
        if(Hub==0&&D[i].Bing==0) N[y].Bing=3,N[y].Xue-=30,DieN(y);
        Yan(4),cout<<"寒冰机甲攻击！冰冻了你方第";cout<<nl-y+1;Sleep(100);
        cout<<"个目标，";Sleep(300);cout<<R<<"点伤害！"<<endl<<endl;
        Bai();Sleep(500),War();
        return;
    }
    if((dl>=3&&nl<4)||x==2) {cout<<"寒冰机甲蓄力。"<<endl<<endl;return;}
    if(x==3) {Yan(4),cout<<"寒冰机甲召唤！"<<endl<<endl;Chu(z);Bai();War();}
    if(x==4) {Yan(4),cout<<"寒冰机甲召唤！"<<endl<<endl;Chu(z);if(dl<3) z=rand()%10,Chu(z);Bai();War();}
    Bai();
}
void Bdu(int n,int i)
{
    int x=rand()%8;int y=rand()%10;
    if(x<2&&D[i].Bing==0)
    {
        Yan(4),cout<<"木毒机甲向你放毒！";
        if(Hub==0&&D[i].Bing==0)
        {
            cout<<"所有炮塔中毒！"; 
            for(int i=1;i<=nl;i++) N[i].Du=4;
        }
        cout<<endl<<endl;return;
    }
    if(x==2&&D[i].Bing==0) {Yan(4),cout<<"木毒机甲向己方放毒！所有敌人中毒，攻速*2！"<<endl<<endl,Baodb=2;return;}
    if((x>4)||(nl<4&&dl>=3)) {cout<<"木毒机甲蓄力。"<<endl<<endl;return;}
    if(x>2&&x<=4) {Yan(4),cout<<"木毒机甲召唤！"<<endl<<endl;Chu(y);Bai();War();}
    if(x==5) {Yan(4),cout<<"木毒机甲召唤！"<<endl<<endl;Chu(y);if(dl<3) y=rand()%10,Chu(y);Bai();War();}
    Bai();Sleep(100);
}
void Bju(int n,int m,int i)
{
    int x=rand()%5,xx=rand()%10,y,yy,z,zz;int R=40+rand()%21;
    if(nl==1) while (x==0) x=rand()%5;
    else {y=rand()%n+1;z=y; while(z==y) z=rand()%n+1;}
    if(dl==1) while (x==1) x=rand()%5;
    else {yy=rand()%m+1;zz=yy; while(zz==yy) zz=rand()%m+1;}
    if(x==0&&D[i].Bing==0)
    {
        Yan(4),cout<<"飓风机甲刮起狂风！调换了你方第"<<n-y+1<<"个和"<<n-z+1<<"个炮塔的位置，";swap(N[y],N[z]);
        if(Hub==0) Sleep(300);cout<<R<<"*2点伤害！",N[y].Xue-=R,N[z].Xue-=R,DieN(y),DieN(z);
        cout<<endl<<endl;Bai();Sleep(500),War();return;
    }
    if(x==1&&Fengb==1) x=5;
    if(x==1&&D[i].Bing==0&&Fengb==0)
    {
        Yan(4),cout<<"飓风机甲刮起狂风！调换了己方第"<<yy<<"个和"<<zz<<"个敌人的位置！"<<endl<<endl;swap(D[yy],D[zz]);
        Bai();Sleep(500),War();Fengb=1;
        return;
    }
    if((dl>=3&&nl<4)||x==5) {cout<<"飓风机甲蓄力。"<<endl<<endl;return;}
    if(x==2) if(Hub==0&&D[i].Bing==0){cout<<"飓风机甲刮起狂风！前三个炮塔血量减30%！"<<endl<<endl;if(N[3].Xue!=0) N[3].Xue*=0.7,DieN(3);if(N[2].Xue!=0) N[2].Xue*=0.7,DieN(2);if(N[1].Xue!=0) N[1].Xue*=0.7,DieN(1);}
    if(x==3) {Yan(4),cout<<"飓风机甲召唤！"<<endl<<endl;Chu(xx);Bai();War();}
    if(x==4) {Yan(4),cout<<"飓风机甲召唤！"<<endl<<endl;Chu(xx);if(dl<3) xx=rand()%10,Chu(xx);Bai();War();}
    Bai();
}
void Byan(int n,int i)
{
    int x=rand()%5;int y=rand()%10;
    if(x==0&&D[i].Bing==0)
    {
        int R=35+rand()%11,R1=25+rand()%11,R2=15+rand()%11,R3=5+rand()%11,R4=1+rand()%10;
        Yan(4),cout<<"烈焰机甲红焰迸出，火势燎原！";
        if(Hub==0&&D[i].Bing==0) cout<<R<<"+"<<R1<<"+"<<R2<<"+"<<R3<<"+"<<R4<<"点伤害！";cout<<endl<<endl;
        if(nl>=5) N[5].Xue-=R4,DieN(5);
        if(nl>=4) N[4].Xue-=R3,DieN(4);
        if(nl>=3) N[3].Xue-=R2,DieN(3);
        if(nl>=2) N[2].Xue-=R1,DieN(2);
        if(nl>=1) N[1].Xue-=R,DieN(1); return;
    }
    if(x==1&&D[i].Bing==0)
    {
        bool k[31];int R=25+rand()%11;
        memset(k,0,sizeof(k));
        Yan(4),cout<<"烈焰机甲的火焰聚成5个火球，向你飞来！";
        if(Hub==0&&D[i].Bing==0)
        {
            cout<<"击中了第";
            for(int i=0;i<5;i++)
            {
                int z=rand()%n+1;
                N[z].Xue-=R;
                k[z]=1;
                cout<<nl-z+1;Sleep(50);
                if(i!=4) cout<<"、";Sleep(50);
            }
            cout<<"个目标，";Sleep(100);cout<<R<<"*5伤害！";cout<<endl<<endl;
            for(int i=30;i>0;i--) if(k[i]==1) DieN(i);
        }
        return;
    }
    if((nl<4&&dl>=3)||x==2) {cout<<"烈焰机甲蓄力。"<<endl<<endl;return;}
    if(x==3) {Yan(4),cout<<"烈焰机甲召唤！"<<endl<<endl;Chu(y);Bai();War();}
    if(x==4) {Yan(4),cout<<"烈焰机甲召唤！"<<endl<<endl;Chu(y);if(dl<3) y=rand()%10,Chu(y);Bai();War();}
    Bai();Sleep(100);
}
void Round()
{
    system("cls");t++;int R,R2,R3;
    if(t>=3305536) cout<<"第"<<t-3305536<<"天"<<endl<<endl;
    else cout<<"第"<<t<<"天"<<endl<<endl;
    if(t%10==0&&t>=30) Yan(5),cout<<"成就：坚守"<<t<<"天，完成！加30金币！"<<endl,Bai(),Money+=30;
    if(Money>=300) Money=300,Yan(3),cout<<endl<<"金币储量已达上限！"<<endl<<endl,Bai(),Sleep(500);
    War();Fengb=0;
    for(int i=1;i<=nl;i++) if(N[i].Hui!=0) N[i].Xue+=30;
    for(int i=1;i<=nl;i++) if(N[i].Du!=0) N[i].Xue-=10,DieN(i);
    if(Baob!=0) Bao=2;if(Baob==0) Bao=1;if(Baodb!=0) Baod=2;if(Baodb==0) Baod=1;if(Biaob==0) Biao=0;
    if(D[1].Xue<=0)
    {
        if(t!=0) cout<<"炮塔暂时没有发现敌人。"<<endl<<endl;Sleep(500);
        for(int i=nl;i>0;i--)
        {   int b=0;Yan(N[i].Zhong);
            if(N[i].Zhong==0) {cout<<"城墙巍然不动。"<<endl<<endl;}
            if(b==0&&N[i].Zhong==6&&N[i].Bing==0) cout<<"电磁炮，",Yan(4),Sleep(200),cout<<"第1环，点亮！"<<endl<<endl,Bai(),N[i].Zhong++,b=1;
            if(b==0&&N[i].Zhong==7&&N[i].Bing==0) cout<<"电磁炮，",Yan(4),Sleep(200),cout<<"第2环，点亮！"<<endl<<endl,Bai(),N[i].Zhong++,b=1;
            if(b==0&&N[i].Zhong==8&&N[i].Bing==0) {cout<<"电磁炮，",Yan(4),Sleep(200),cout<<"第3环，点亮！";Sleep(200);cout<<"蓄势待发！"<<endl<<endl;Bai();}
        }Bai();
    }
    else
    {
        if(Hub!=0) Yan(5),cout<<"无敌护罩耀耀生辉，将所有敌人的攻击阻挡在外。"<<endl<<endl,Sleep(500);
        for(int j=1;j<=Baod;j++)
        {
            if(j==2) Yan(4),cout<<"在毒性的催发下，敌人疯狂攻击着！"<<endl<<endl,Sleep(500); 
            for(int i=1;i<=dl;i++)
            {
            int c=0;Yan(D[i].Zhong);
            if(D[i].Bing!=0) Yan(4),cout<<"在闪光弹的强光下,敌人睁不开眼睛！"<<endl<<endl,Sleep(500);
            if(D[i].Zhong==1&&nl>=0&&Hub==0&&D[i].Bing==0) R=20+rand()%21,cout<<"步兵开枪了！"<<R<<"点伤害！"<<endl<<endl,N[1].Xue-=R,DieN(1);
            if(D[i].Zhong==2&&nl>=0&&Hub==0&&D[i].Bing==0) R=10+rand()%21,cout<<"骑兵身形一抖，向前一刺！"<<R<<"点伤害！"<<endl<<endl,N[1].Xue-=20,DieN(1);
            if(D[i].Zhong==3&&nl>=0&&Hub==0&&D[i].Bing==0) R=40+rand()%21,cout<<"炮兵点火，炮声响彻天际！"<<R<<"点伤害！"<<endl<<endl,N[1].Xue-=50,DieN(1);
            if(D[i].Zhong==4&&nl>=0&&D[i].Bing==0) cout<<"药兵开始治疗！恢复了第",Jiu(dl);
            if(D[i].Zhong==5&&nl>=0&&Hub==0&&D[i].Bing==0) R=70+rand()%21,cout<<"坦克的穿甲弹从炮管口滚滚白烟中冲出！"<<R<<"点伤害！"<<endl<<endl,N[1].Xue-=80,DieN(1);
            if(c==0&&D[i].Zhong==6&&nl>=0&&D[i].Bing==0) cout<<"炮灰点燃了",Yan(4),cout<<"炸弹的引信！"<<endl<<endl,D[i].Zhong++,c=1;
            if(c==0&&D[i].Zhong==7&&nl>=0&&D[i].Bing==0) {R=490+rand()%21,cout<<"炮灰",Yan(4),cout<<"爆炸！！！",Sleep(500),cout<<R<<"点伤害！"<<endl<<endl;if(Hub==0) N[1].Xue-=500,DieN(1);D[i].Xue-=500,Die(i),c=1;}
            if(D[i].Zhong==8&&nl>=0) Yan(5),Bjing(nl,i);
            if(D[i].Zhong==9&&nl>=0) Yan(1),Bbing(nl,i);
            if(D[i].Zhong==10&&nl>=0) Yan(2),Bdu(nl,i);
            if(D[i].Zhong==11&&nl>=0) Yan(3),Bju(nl,dl,i);
            if(D[i].Zhong==12&&nl>=0) Yan(4),Byan(nl,i);
            if(nl>=0) Sleep(200);Bai();
            }
        }
        for(int j=1;j<=Bao;j++)
        {
            if(j==2) Yan(4),cout<<"狂暴血清爆发了，炮塔疯狂地发射着子弹！"<<endl<<endl,Sleep(500),Baob--; 
            for(int i=nl;i>0;i--)
            {
            int b=0;Yan(N[i].Zhong);
            if(N[i].Zhong==0) {cout<<"城墙巍然不动。"<<endl<<endl;Sleep(200);}
            if(N[i].Zhong==1&&D[1].Zhong!=0&&N[i].Bing==0) {if(D[1].Zhong!=0)R=20+rand()%21,cout<<"加农炮一炮发出！"<<R<<"点伤害！"<<endl<<endl;if(Biao!=0) D[Biao].Xue-=R,Die(Biao);else D[1].Xue-=R,Die(1);Sleep(200);}
            if(N[i].Zhong==2&&D[1].Zhong!=0&&N[i].Bing==0) {if(D[1].Zhong!=0)R=40+rand()%21,cout<<"重机枪射出复仇的子弹！"<<R<<"点伤害！"<<endl<<endl;if(Biao!=0) D[Biao].Xue-=R,Die(Biao);else D[1].Xue-=R,Die(1);Sleep(200);}
            if(N[i].Zhong==3&&D[1].Zhong!=0&&N[i].Bing==0) {if(D[1].Zhong!=0)R=60+rand()%21,cout<<"迫击炮的炮弹划出一条完美的抛物线！"<<R<<"点伤害！"<<endl<<endl;if(Biao!=0) D[Biao].Xue-=R,Die(Biao);else D[dl].Xue-=R,Die(dl);Sleep(200);}
            if(N[i].Zhong==4&&D[1].Zhong!=0&&N[i].Bing==0) {if(D[1].Zhong!=0)R=40+rand()%21,R2=20+rand()%21,R3=rand()%21,cout<<"喷火器喷出熊熊烈火！"<<R<<"+"<<R2<<"+"<<R3<<"点伤害！"<<endl<<endl;if(Biao!=0){if(D[Biao+2].Zhong!=0)D[Biao+2].Xue-=R3,Die(Biao+2);if(D[Biao+1].Zhong!=0)D[Biao+1].Xue-=R2,Die(Biao+1);if(D[Biao].Zhong!=0)D[Biao].Xue-=R,Die(Biao);}else{if(D[3].Zhong!=0)D[3].Xue-=R3,Die(3);if(D[2].Zhong!=0)D[2].Xue-=R2,Die(2);if(D[1].Zhong!=0)D[1].Xue-=R,Die(1);}Sleep(200);}
            if(N[i].Zhong==5&&D[1].Zhong!=0&&N[i].Bing==0) {if(dl!=0) cout<<"火箭炮的7枚火箭依次冲出！命中第";Huo(dl);Sleep(200);}
            if(b==0&&N[i].Zhong==6&&N[i].Bing==0) cout<<"电磁炮，",Yan(4),Sleep(200),cout<<"第1环，点亮！"<<endl<<endl,Bai(),N[i].Zhong++,b=1,Sleep(200);
            if(b==0&&N[i].Zhong==7&&N[i].Bing==0) cout<<"电磁炮，",Yan(4),Sleep(200),cout<<"第2环，点亮！"<<endl<<endl,Bai(),N[i].Zhong++,b=1,Sleep(200);
            if(b==0&&N[i].Zhong==8&&N[i].Bing==0){cout<<"电磁炮，",Yan(4),Sleep(200),cout<<"第3环，点亮！";if(D[1].Zhong!=0){R=290+rand()%21,R2=90+rand()%21,Sleep(200);cout<<"然后...",Sleep(200),cout<<"轰！！！",Sleep(200),cout<<R<<"+"<<R2<<"点伤害！"<<endl<<endl,N[i].Zhong-=2;if(Biao!=0){if(D[Biao+1].Zhong!=0)D[Biao+1].Xue-=R2,Die(Biao+1);D[Biao].Xue-=R,Die(Biao),b=1;} else {if(D[2].Zhong!=0)D[2].Xue-=R2,Die(2);D[1].Xue-=R,Die(1),b=1;}}else cout<<"蓄势待发！"<<endl<<endl;Bai();Sleep(200);}
            Bai();
            }
        }
        for(int i=nl;i>0;i--) if(N[i].Hui!=0) N[i].Hui--;
        for(int i=nl;i>0;i--) if(N[i].Bing!=0) N[i].Bing--;
        for(int i=nl;i>0;i--) if(N[i].Du!=0) N[i].Du--;
        for(int i=dl;i>0;i--) if(D[i].Bing!=0) D[i].Bing--;
        if(Baodb!=0) Baodb--;if(Biaob!=0) Biaob--;
        if(nl<=0)
        {
            Yan(4);Sleep(2000);system("cls");
            cout<<endl<<"城破了，你输了！！！"<<endl<<endl;Sleep(1000);
            cout<<"你坚守了"<<t<<"天。"<<endl<<endl;Bai();Sleep(1000);system("pause");
            return;
        }
    }
    if(Hub!=0) Hub--;
    if(t>=3305536&&dl<=0) return;
    if(t<3305536) Mai(Moo);
    if(t<3305536&&Moo==0)
    {
        int u=0;
        x: Bai();
        Sleep(200);
        int y=rand()%11;
        if(t<10)
        {
            if(dl>=2) y=0;
            if(y<5) cout<<"没有新敌人出现。"<<endl<<endl;
            if(y>=5&&y<9) Yan(1),cout<<"呀！来了个步兵！"<<endl<<endl,ZaoN(1);
            if(y>=9) Yan(2),cout<<"呀！来了个骑兵！"<<endl<<endl,ZaoN(2);
        }
        if(t<20&&t>=10)
        {
            if(dl>=2) y=7;
            if(y>=7) {cout<<"没有新敌人出现。"<<endl<<endl;y=0;}
            else Chu(y);u++;
            int w=rand()%3;
            if(dl<2&&w<3&&u<2) goto x;
        }
        if(t<29&&t>=20)
        {
            if(dl>=2) y=9;
            if(y>=9) {cout<<"没有新敌人出现。"<<endl<<endl;}
            else Chu(y);u++;
            int w=rand()%3;
            if(dl<2&&w<3&&u<2) goto x;
        }
        if(t==29) Mo();
        if(t<45&&t>=30)
        {
            if(dl>=3) y=10;
            if(y>=10) {cout<<"没有新敌人出现。"<<endl<<endl;}
            else Chu(y);u++;
            int w=rand()%2;
            if(dl<2&&w<1&&u<2) goto x;
        }
        if(t<59&&t>=45)
        {
            if(dl>=nl+1) y=20;
            if(y==20) {cout<<"没有新敌人出现。"<<endl<<endl;}
            else Chu(y);u++;
            if(u<3) goto x;
        }
        if(t==59) Mo();if(t==60) Mo();
        if(t<79&&t>60)
        {
            if(dl>=nl+2) y=20;
            if(y==20) {cout<<"没有新敌人出现。"<<endl<<endl;}
            else Chu(y);u++;
            if(u<3) goto x;
            if(u==3&&y==0) goto x;
        }
        if(t==79) Mo();if(t==80) Mo();if(t==81) Mo();
        if(t<99&&t>81)
        {
            if(dl>=nl+2) y=20;
            if(y==20) {cout<<"没有新敌人出现。"<<endl<<endl;}
            else Chu(y);u++;
            if(u<3) goto x;
            if(u==3&&y==0) goto x;
        }
        if(t==99)
        {
            system("cls");Sleep(500);
            cout<<"第100天"<<endl<<endl;Yan(5);
            cout<<"飞机的轰鸣声响过，你的视野变为雪白......"<<endl<<endl; Sleep(1000);
            cout<<"激烈的战场瞬间寂静，机甲轰然倒塌......"<<endl<<endl;  Sleep(1000);
            cout<<"在层层迷雾中，远方若隐若现地显出军队的轮廓......"<<endl<<endl; Sleep(1000);
            cout<<"啊，你的援军到了！！！"<<endl<<endl;  Sleep(1000);
            cout<<"伟大的将帅啊，我们的首都，保住了！！！"<<endl<<endl;Sleep(3000);
            system("cls");Bai();
            cout<<endl<<"游戏目标达成，游戏结束！"<<endl<<endl;Sleep(2000);
            system("pause");return;
        }
        Bai();
    }
    Sleep(300);
    Round();
}
void Jiao()
{
    char a;Bai();
    cout<<endl<<" 现在进行教学模式。"<<endl;Sleep(1000);system("cls");
    cout<<"┌-------------------------┐"<<endl;
    cout<<"┆新武器解锁！             ┆"<<endl;
    cout<<"┆                         ┆"<<endl;
    cout<<"┆加农炮：                 ┆"<<endl;
    cout<<"┆攻击力：30               ┆"<<endl;
    cout<<"┆血量：100                ┆"<<endl;
    cout<<"┆价值：100                ┆"<<endl;
    cout<<"┆目标：第一个敌人         ┆"<<endl;
    cout<<"┆最多建造数量：∞         ┆"<<endl;
    cout<<"┆符号： ";Yan(1);cout<<"●";Bai();cout<<"                ┆"<<endl;
    cout<<"└-------------------------┘"<<endl;Sleep(2000);
    cout<<"请按1键以建造加农炮。"<<endl<<endl;a=_getch();N[1].Zhong=1,N[1].Xue=100,nl++;War(); 
    cout<<"好极了，他应该能帮我们守住城市。"<<endl<<endl;Sleep(1000);
    system("pause");system("cls");
    cout<<"┌-------------------------┐"<<endl;
    cout<<"┆新敌人出现！             ┆"<<endl;
    cout<<"┆                         ┆"<<endl;
    cout<<"┆步兵：                   ┆"<<endl;
    cout<<"┆攻击力：30               ┆"<<endl;
    cout<<"┆血量：50                 ┆"<<endl;
    cout<<"┆掉落金币：20             ┆"<<endl;
    cout<<"┆目标：第一个炮塔         ┆"<<endl;
    cout<<"┆符号： ";Yan(1);cout<<"○";Bai();cout<<"                ┆"<<endl;
    cout<<"└-------------------------┘"<<endl;Sleep(2000);
    D[1].Zhong=1,D[1].Xue=50,dl=1;
    system("pause");system("cls");War(); 
    cout<<"现在看看你的加农炮能把它怎么样！"<<endl<<endl;Sleep(1000);
    t=3305536,Round();
    cout<<"加农炮血多价廉，是战斗前期的必备。"<<endl<<endl;Sleep(1000);
    system("pause");system("cls");
    cout<<"┌-------------------------┐"<<endl;
    cout<<"┆新武器解锁！             ┆"<<endl;
    cout<<"┆                         ┆"<<endl;
    cout<<"┆重机枪：                 ┆"<<endl;
    cout<<"┆攻击力：50               ┆"<<endl;
    cout<<"┆血量：80                 ┆"<<endl;
    cout<<"┆价值：120                ┆"<<endl;
    cout<<"┆目标：第一个敌人         ┆"<<endl;
    cout<<"┆最多建造数量：5          ┆"<<endl;
    cout<<"┆符号： ";Yan(2);cout<<"■";Bai();cout<<"                ┆"<<endl;
    cout<<"└-------------------------┘"<<endl;Sleep(2000);
    cout<<"重机枪攻击力高，可以大量输出火力。"<<endl<<endl;Sleep(1000);
    system("pause");system("cls");
    cout<<"┌-------------------------┐"<<endl;
    cout<<"┆新敌人出现！             ┆"<<endl;
    cout<<"┆                         ┆"<<endl;
    cout<<"┆骑兵：                   ┆"<<endl;
    cout<<"┆攻击力：20               ┆"<<endl;
    cout<<"┆血量：100                ┆"<<endl;
    cout<<"┆掉落金币：30             ┆"<<endl;
    cout<<"┆目标：第一个炮塔         ┆"<<endl;
    cout<<"┆符号： ";Yan(2);cout<<"□";Bai();cout<<"                ┆"<<endl;
    cout<<"└-------------------------┘"<<endl;Sleep(2000);
    cout<<"骑兵血多，但攻击力低。"<<endl<<endl;Sleep(1000);
    system("pause");system("cls");
    cout<<"┌-------------------------┐"<<endl;
    cout<<"┆新武器解锁！             ┆"<<endl;
    cout<<"┆                         ┆"<<endl;
    cout<<"┆迫击炮：                 ┆"<<endl;
    cout<<"┆攻击力：70               ┆"<<endl;
    cout<<"┆血量：150                ┆"<<endl;
    cout<<"┆价值：150                ┆"<<endl;
    cout<<"┆最多建造数量：5          ┆"<<endl;
    cout<<"┆目标：最后一个敌人       ┆"<<endl;
    cout<<"┆符号： ";Yan(3);cout<<"▲";Bai();cout<<"                ┆"<<endl;
    cout<<"└-------------------------┘"<<endl;Sleep(2000);
    cout<<"迫击炮攻击力高，并可以在一些血少敌人出场时将其击杀。"<<endl<<endl;Sleep(1000);
    system("pause");system("cls");
    cout<<"┌-------------------------┐"<<endl;
    cout<<"┆新敌人出现！             ┆"<<endl;
    cout<<"┆                         ┆"<<endl;
    cout<<"┆炮兵：                   ┆"<<endl;
    cout<<"┆攻击力：50               ┆"<<endl;
    cout<<"┆血量：30                 ┆"<<endl;
    cout<<"┆掉落金币：20             ┆"<<endl;
    cout<<"┆目标：第一个炮塔         ┆"<<endl;
    cout<<"┆符号： ";Yan(3);cout<<"△";Bai();cout<<"                ┆"<<endl;
    cout<<"└-------------------------┘"<<endl;Sleep(2000);
    cout<<"炮兵攻击力高，需要速决。"<<endl<<endl;Sleep(1000);
    system("pause");system("cls");
    cout<<"┌-------------------------┐"<<endl;
    cout<<"┆新武器解锁！             ┆"<<endl;
    cout<<"┆                         ┆"<<endl;
    cout<<"┆喷火器：                 ┆"<<endl;
    cout<<"┆攻击力：50+30+10         ┆"<<endl;
    cout<<"┆血量：200                ┆"<<endl;
    cout<<"┆价值：200                ┆"<<endl;
    cout<<"┆目标：前三个敌人         ┆"<<endl;
    cout<<"┆最多建造数量：5          ┆"<<endl;
    cout<<"┆符号： ";Yan(4);cout<<"▼";Bai();cout<<"                ┆"<<endl;
    cout<<"└-------------------------┘"<<endl;Sleep(2000);
    cout<<"喷火器，超值攻击礼包。"<<endl<<endl;Sleep(1000);
    system("pause");system("cls");
    cout<<"┌-------------------------┐"<<endl;
    cout<<"┆新武器解锁！             ┆"<<endl;
    cout<<"┆                         ┆"<<endl;
    cout<<"┆城墙：                   ┆"<<endl;
    cout<<"┆血量：500                ┆"<<endl;
    cout<<"┆价值：250                ┆"<<endl;
    cout<<"┆最多建造数量：1          ┆"<<endl;
    cout<<"┆符号： ▎                ┆"<<endl;
    cout<<"└-------------------------┘"<<endl;Sleep(2000);
    cout<<"救场神器！相当于无敌多回合！"<<endl<<endl;
    cout<<"城墙会自动放置在战场最前方。"<<endl<<endl;Sleep(1000);
    system("pause");system("cls");
    cout<<"┌-------------------------┐"<<endl;
    cout<<"┆新敌人出现！             ┆"<<endl;
    cout<<"┆                         ┆"<<endl;
    cout<<"┆药兵：                   ┆"<<endl;
    cout<<"┆攻击力：-20（治愈敌方）  ┆"<<endl;
    cout<<"┆血量：100                ┆"<<endl;
    cout<<"┆掉落金币：30             ┆"<<endl;
    cout<<"┆目标：任意一个敌方       ┆"<<endl;
    cout<<"┆符号： ";Yan(4);cout<<"▽";Bai();cout<<"                ┆"<<endl;
    cout<<"└-------------------------┘"<<endl;Sleep(2000);
    cout<<"药兵血多，不过不会攻击。"<<endl<<endl;Sleep(1000);
    system("pause");system("cls");
    cout<<"┌-------------------------┐"<<endl;
    cout<<"┆新武器解锁！             ┆"<<endl;
    cout<<"┆                         ┆"<<endl;
    cout<<"┆电磁炮：                 ┆"<<endl;
    cout<<"┆攻击力：300+100          ┆"<<endl;
    cout<<"┆       （蓄力2回合）     ┆"<<endl;
    cout<<"┆血量：400                ┆"<<endl;
    cout<<"┆价值：270                ┆"<<endl;
    cout<<"┆目标：第一个敌人         ┆"<<endl;
    cout<<"┆最多建造数量：2          ┆"<<endl;
    cout<<"┆符号： ";Yan(6);cout<<"◆";Bai();cout<<"                ┆"<<endl;
    cout<<"└-------------------------┘"<<endl;Sleep(2000);
    cout<<"电磁炮是对付坦克的必备法宝。"<<endl<<endl;Sleep(1000);
    system("pause");system("cls");
    cout<<"┌-------------------------┐"<<endl;
    cout<<"┆新敌人出现！             ┆"<<endl;
    cout<<"┆                         ┆"<<endl;
    cout<<"┆炮灰：                   ┆"<<endl;
    cout<<"┆攻击力：500（蓄力1回合） ┆"<<endl;
    cout<<"┆血量：10                 ┆"<<endl;
    cout<<"┆掉落金币：10             ┆"<<endl;
    cout<<"┆目标：第一个炮塔         ┆"<<endl;
    cout<<"┆符号： ";Yan(6);cout<<"◇";Bai();cout<<"                ┆"<<endl;
    cout<<"└-------------------------┘"<<endl;Sleep(2000);
    cout<<"炮灰出场时，务必第一时间将其击杀。"<<endl<<endl;
    cout<<"炮灰爆炸时，自己也会死亡。"<<endl<<endl;Sleep(1000);
    system("pause");system("cls");
    cout<<"┌-------------------------┐"<<endl;
    cout<<"┆新武器解锁！             ┆"<<endl;
    cout<<"┆                         ┆"<<endl;
    cout<<"┆火箭炮：                 ┆"<<endl;
    cout<<"┆攻击力：20*7             ┆"<<endl;
    cout<<"┆血量：300                ┆"<<endl;
    cout<<"┆价值：300                ┆"<<endl;
    cout<<"┆目标：任意九个敌人       ┆"<<endl;
    cout<<"┆最多建造数量：3          ┆"<<endl;
    cout<<"┆符号： ";Yan(5);cout<<"★";Bai();cout<<"                ┆"<<endl;
    cout<<"└-------------------------┘"<<endl;Sleep(2000);
    cout<<"火箭炮极其有用，后期必备。"<<endl<<endl;Sleep(1000);
    system("pause");system("cls");
    cout<<"┌-------------------------┐"<<endl;
    cout<<"┆新敌人出现！             ┆"<<endl;
    cout<<"┆                         ┆"<<endl;
    cout<<"┆坦克：                   ┆"<<endl;
    cout<<"┆攻击力：80               ┆"<<endl;
    cout<<"┆血量：200                ┆"<<endl;
    cout<<"┆掉落金币：50             ┆"<<endl;
    cout<<"┆目标：第一个炮塔         ┆"<<endl;
    cout<<"┆符号： ";Yan(5);cout<<"☆";Bai();cout<<"                ┆"<<endl;
    cout<<"└-------------------------┘"<<endl;Sleep(2000);
    cout<<"坦克，你的噩梦！"<<endl<<endl;Sleep(2000);
    system("pause");system("cls");
    cout<<endl<<"开局时，你有一个城墙。"<<endl<<endl;Sleep(2000);
    cout<<"建造炮塔要花费金币，你的金币每回合+10。"<<endl<<endl;Sleep(2000);
    cout<<"后期会出BOSS——机甲，这时你的金币每回合+30。"<<endl<<endl;Sleep(2000);
    cout<<"你的金币储量上限为300。"<<endl<<endl,Sleep(2000);
    cout<<"打爆一个敌人有几率掉道具。"<<endl<<endl;Sleep(2000);
    cout<<"每个炮塔一回合只能攻击一次。"<<endl<<endl;Sleep(2000);
    cout<<"当所有炮塔阵亡时，游戏结束。"<<endl<<endl;Sleep(2000);
    cout<<"伟大的将帅啊，请你保卫我们的首都！"<<endl<<endl;Sleep(2000);
    system("pause");system("cls");
}
int main()
{
    srand((unsigned)time(NULL));
    system("mode con cols=46 lines=40");
    ST:system("cls");
    memset(N,0,sizeof(N));memset(D,0,sizeof(D));memset(X,0,sizeof(X));
    t=nl=dl=Moo=Biao=Biaob=Bao=Baob=Baod=Baodb=Hub=Fengb=Sha=Jian=Shab=Jianb=0;
    Bai(); cout<<endl<<" ----------------城市守卫战------------------"<<endl;
    cout<<" --------------------------作者：whsx--------"<<endl<<endl;
    cout<<" 建塔和用道具";Yan(3);cout<<"不需要按回车！"<<endl<<endl;Bai();
    cout<<" 输入： 1.教学模式   2.战争模式"<<endl;
    st:
    char a;a=_getch();
    if(a=='1') {Jiao(),N[1].Zhong=0,N[1].Xue=500,nl=1,Money=90;cout<<endl<<"现在进行战争模式。"<<endl<<endl;Sleep(1000);t=0;Round();goto ST;}
    else if(a=='2') {N[1].Zhong=0,N[1].Xue=500,nl=1,Money=90;cout<<endl<<" 现在进行战争模式。"<<endl<<endl;Sleep(1000);t=0;Round();goto ST;}
    else goto st;
    Bai();
    return 0;
}

