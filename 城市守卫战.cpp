//# ��������ս

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
    if(x==1) {if(a==0) cout<<"��ǽ";if(a==1) cout<<"��ũ��";if(a==2) cout<<"�ػ�ǹ";if(a==3) cout<<"�Ȼ���";if(a==4) cout<<"�����";if(a==5) cout<<"�����";if(a>=6) cout<<"�����";}
    if(x==2)
    {
        if(a==1) cout<<"����",Money+=20,k=20;if(a==2) cout<<"���",Money+=30,k=30;if(a==3) cout<<"�ڱ�",Money+=30,k=30;if(a==4) cout<<"ҩ��",Money+=30,k=30;if(a==6||a==7) cout<<"�ڻ�",Money+=10,k=10;if(a==5) cout<<"̹��",Money+=50,k=50;
        if(a==8) Yan(3),cout<<"��ջ���",Money+=100;if(a==9) Yan(1),cout<<"��������",Money+=100;if(a==10) Yan(2),cout<<"ľ������",Money+=100;if(a==11) Yan(3),cout<<"쫷����",Money+=100;if(a==12) Yan(4),cout<<"�������",Money+=100;if(a>=8) k=100;
    }
    Yan(4);Sleep(200),cout<<"......��������";
    if(x==2) Yan(5),cout<<"����"<<k<<"��ң�";cout<<endl<<endl,Sha++;
    if(Sha%20==0&&Shab<Sha) Yan(5),cout<<"�ɾͣ�ɱ��"<<Sha<<"�����ˣ���ɣ���30��ң�"<<endl<<endl,Sleep(500),Bai(),Money+=30,Shab=Sha;
    if(Money>=500) Money=500,Yan(3),cout<<"��Ҵ����Ѵ����ޣ�"<<endl<<endl,Bai(),Sleep(500);
    Bai();
}
void War()
{
    int zn=0,zd=0;if(nl-5>0) zn=nl%5;if(dl-5>0) zd=dl%5;cout<<"��";
    for(int i=0;i<=40;i++) cout<<'-';cout<<"��"<<endl<<"��";
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
    cout<<" ��"<<endl<<"��";
    for(int i=5;i>0;i--) if(i>=nl+1) cout<<"    ";
    for(int i=5;i>0;i--)
    {
        if(i>=nl+1) continue;
        Yan(N[i].Zhong);if(N[i].Bing>0) Yan(6);
        if(N[i].Zhong==0) cout<<"  ��";if(N[i].Zhong==1) cout<<"  ��";if(N[i].Zhong==2) cout<<"  ��";if(N[i].Zhong==3) cout<<"  ��";if(N[i].Zhong==4) cout<<"  ��";if(N[i].Zhong==5) cout<<"  ��";if(N[i].Zhong>=6) cout<<"  ��"; 
        Bai();
    }
    for(int i=1;i<=5;i++)
    {
        if(i>dl) {cout<<"    ";continue;}
        Yan(D[i].Zhong);if(D[i].Bing>0) Yan(4);
        if(D[i].Zhong==1) cout<<"  ��";if(D[i].Zhong==2) cout<<"  ��";if(D[i].Zhong==3) cout<<"  ��";if(D[i].Zhong==4) cout<<"  ��";if(D[i].Zhong==5) cout<<"  ��";if(D[i].Zhong>=6&&D[i].Zhong<=7) cout<<"  ��";if(D[i].Zhong==8) Yan(5),cout<<"  ��";if(D[i].Zhong==9) Yan(1),cout<<"  ��";if(D[i].Zhong==10) Yan(2),cout<<"  ��";if(D[i].Zhong==11) Yan(3),cout<<"  ��";if(D[i].Zhong==12) Yan(4),cout<<"  ��";
        Bai();
    }
    if(zn>0||zd>0)
    {
    cout<<" ��"<<endl<<"��";
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
    cout<<" ��"<<endl<<"��";
    for(int i=5-zn;i>0;i--) {cout<<"    ";continue;}
    for(int i=5+zn;i>5;i--)
    {
        Yan(N[i].Zhong);if(N[i].Bing>0) Yan(6);
        if(N[i].Zhong==0) cout<<"  ��";if(N[i].Zhong==1) cout<<"  ��";if(N[i].Zhong==2) cout<<"  ��";if(N[i].Zhong==3) cout<<"  ��";if(N[i].Zhong==4) cout<<"  ��";if(N[i].Zhong==5) cout<<"  ��";if(N[i].Zhong>=6) cout<<"  ��"; 
        Bai();
    }
    for(int i=6;i<=10;i++)
    {
        if(i>dl) {cout<<"    ";continue;}
        Yan(D[i].Zhong);if(D[i].Bing>0) Yan(4);
        if(D[i].Zhong==1) cout<<"  ��";if(D[i].Zhong==2) cout<<"  ��";if(D[i].Zhong==3) cout<<"  ��";if(D[i].Zhong==4) cout<<"  ��";if(D[i].Zhong==5) cout<<"  ��";if(D[i].Zhong>=6&&D[i].Zhong<=7) cout<<"  ��";if(D[i].Zhong==8) Yan(5),cout<<"  ��";if(D[i].Zhong==9) Yan(1),cout<<"  ��";if(D[i].Zhong==10) Yan(2),cout<<"  ��";if(D[i].Zhong==11) Yan(3),cout<<"  ��";if(D[i].Zhong==12) Yan(4),cout<<"  ��";
        Bai();
    }
    }
    cout<<" ��"<<endl<<"��";
    for(int i=0;i<=40;i++) cout<<'-';cout<<"��"<<endl;
    Sleep(500);
}
void Ju(int a)
{
    Sleep(1000);system("cls");Bai();
    if(a==0)
    {
        cout<<"��---------------------��"<<endl;
        cout<<"���µ��߽�����         ��"<<endl;
        cout<<"��                     ��"<<endl;
        cout<<"��������               ��"<<endl;
        cout<<"����������300          ��"<<endl;
        cout<<"��Ŀ�꣺ָ��Ŀ��       ��"<<endl;
        cout<<"��---------------------��"<<endl;
    }
    if(a==1)
    {
        cout<<"��---------------------��"<<endl;
        cout<<"���µ��߽�����         ��"<<endl;
        cout<<"��                     ��"<<endl;
        cout<<"��ҽ�ư���             ��"<<endl;
        cout<<"��Ŀ�꣺ָ��Ŀ��       ��"<<endl;
        cout<<"����������-30*5����Ѫ����"<<endl;
        cout<<"������ʱ�䣺5�غ�      ��"<<endl;
        cout<<"��---------------------��"<<endl;
    }
    if(a==2)
    {
        cout<<"��---------------------��"<<endl;
        cout<<"���µ��߽�����         ��"<<endl;
        cout<<"��                     ��"<<endl;
        cout<<"�����ⵯ��             ��"<<endl;
        cout<<"��Ŀ�꣺ָ��Ŀ��       ��"<<endl;
        cout<<"��Ч����ʹһ��ָ������ ��"<<endl;
        cout<<"��    ֹͣ��������ʹ�� ��"<<endl;
        cout<<"��    �����������õ���.��"<<endl;
        cout<<"������ʱ�䣺5�غ�      ��"<<endl;
        cout<<"��---------------------��"<<endl;
    }
    if(a==3)
    {
        cout<<"��---------------------��"<<endl;
        cout<<"���µ��߽�����         ��"<<endl;
        cout<<"��                     ��"<<endl;
        cout<<"����Ѫ�壺           ��"<<endl;
        cout<<"��Ŀ�꣺��������       ��"<<endl;
        cout<<"��Ч����ʹ��������2��  ��"<<endl;
        cout<<"������ʱ�䣺2�غ�      ��"<<endl;
        cout<<"��---------------------��"<<endl;
    }
    if(a==4)
    {
        cout<<"��---------------------��"<<endl;
        cout<<"���µ��߽�����         ��"<<endl;
        cout<<"��                     ��"<<endl;
        cout<<"���޵л��֣�           ��"<<endl;
        cout<<"��Ч����ʹ���������޵� ��"<<endl;
        cout<<"������ʱ�䣺3�غ�      ��"<<endl;
        cout<<"��---------------------��"<<endl;
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
            cout<<"�ӵ���ʬ���з��ֵ��ߡ���"; Sleep(500);
            int b=rand()%5;
            if(b==0) {cout<<"������"<<endl<<endl,Dao++;Sleep(2000);if(Daob==0) Ju(0);Daob=1;}
            if(b==1) {cout<<"ҽ�ư���"<<endl<<endl,Yi++;Sleep(2000);if(Yib==0) Ju(1);Yib=1;}
            if(b==2) {cout<<"���ⵯ��"<<endl<<endl,Shan++;Sleep(2000);if(Shanb==0) Ju(2);Shanb=1;}
            if(b==3) {cout<<"��Ѫ�壡"<<endl<<endl,Qing++;Sleep(2000);if(Qingb==0) Ju(3);Qingb=1;}
            if(b==4) {cout<<"�޵л��֣�"<<endl<<endl,Hu++;Sleep(2000);if(Hubb==0) Ju(4);Hubb=1;}
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
    {Yan(3),cout<<endl<<"��Ч���롣",Bai( );Sleep(500);return;}nl++;
    if(a==1) N[nl].Xue=100,N[nl].Zhong=1,Money-=100;
    if(a==2) N[nl].Xue=80,N[nl].Zhong=2,Money-=120;
    if(a==3) N[nl].Xue=150,N[nl].Zhong=3,Money-=150;
    if(a==4) N[nl].Xue=200,N[nl].Zhong=4,Money-=200;
    if(a==5){N[nl].Xue=N[nl].Zhong=0,Money-=250;for(int i=nl;i>0;i--) swap(N[i],N[i-1]);N[1].Xue=500;}
    if(a==6) N[nl].Xue=400,N[nl].Zhong=6,Money-=270;
    if(a==7) N[nl].Xue=300,N[nl].Zhong=5,Money-=300;
    Yan(5);cout<<endl<<"����ɹ���"<<endl<<endl;Sleep(500);cout<<"��Ľ��������"<<Money;Bai();Jian++;
    if(Jian%10==0&&Jianb<Jian) Yan(5),cout<<endl<<endl<<"�ɾͣ�����"<<Jian<<"����������ɣ���30��ң�",Sleep(500),Bai(),Money+=30,Jianb=Jian;
    if(Money>=300) Money=300,Yan(3),cout<<"��Ҵ����Ѵ����ޣ�"<<endl<<endl,Bai(),Sleep(500);
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
    if((a==1&&Dao==0)||(a==2&&Yi==0)||(a==3&&Shan==0)||(a==4&&Qing==0)||(a==5&&Hu==0)) {cout<<"��Ч���롣"<<endl;Sleep(500);return;}
    if(a==1)
    {
        cout<<endl<<"������ʱ׼�����䣡";Sleep(500);cout<<"Ŀ���ǵڼ������ˣ�-- ";
        char b=_getch();cout<<b<<endl;b-=48; if(b>dl||b<=0) {cout<<"��Ч���롣"<<endl;Sleep(500);return;}
        Yan(4),cout<<endl<<"�������䣡����Ŀ�꣡"<<endl<<endl;Bai(),D[b].Xue-=300;Die(b),Bai(),Dao--; return;
    }
    if(a==2)
    {
        cout<<endl<<"ҽ�ư���ʱ׼����Ͷ��";Sleep(500);cout<<"Ŀ���ǵڼ���������-- ";
        char b=_getch();cout<<b<<endl;b-=48; if(b>nl||b<=0) {cout<<"��Ч���롣"<<endl;Sleep(500);return;}
        Yan(4),cout<<endl<<"ҽ�ư���ʼҽ�ƣ�"<<endl<<endl;Bai(),N[nl-b+1].Hui+=5,Bai(),Yi--; return;
    }
    if(a==3)
    {
        cout<<endl<<"���ⵯ��ʱ׼�����䣡";Sleep(500);cout<<"Ŀ���ǵڼ������ˣ�-- ";
        char b=_getch();cout<<b<<endl;b-=48; if(b>dl||b<=0) {cout<<"��Ч���롣"<<endl;Sleep(500);return;}
        Yan(4),cout<<endl<<"���ⵯ���䣡����Ŀ�꣡"<<endl<<endl;Bai(),Biao=b,D[b].Bing+=5,Biaob+=5,Shan--; return;
    }
    if(a==4) cout<<endl<<"��Ѫ�屬����"<<endl<<endl,Bai(),Baob+=2,Bai(),Qing--;
    if(a==5) cout<<endl<<"�޵л��ֿ�����"<<endl<<endl,Bai(),Hub+=3,Bai(),Hu--;
}
void Mo()
{
    int x=rand()%5;
    if(x==0)
    {
        Yan(5);
        cout<<"��ջ��׳����ˣ�"<<endl<<endl;
        Sleep(1000);system("cls");Bai();
        cout<<"��-----------------------------��"<<endl;
        cout<<"���µ��˳��֣�                 ��"<<endl;
        cout<<"��                             ��"<<endl;
        cout<<"����ջ��ף�                   ��"<<endl;
        cout<<"�����⼼�ܡ���ɨ�䣺           ��"<<endl;
        cout<<"��     ��������40*n            ��"<<endl;
        cout<<"��     Ŀ�꣺��������          ��"<<endl;
        cout<<"����������200                  ��"<<endl;
        cout<<"��Ŀ�꣺��һ������             ��"<<endl;
        cout<<"��Ѫ����1000                   ��"<<endl;
        cout<<"�������ң�100                ��"<<endl;
        cout<<"�����ţ� ";Yan(5);cout<<"��";Bai();cout<<"                    ��"<<endl;
        cout<<"��-----------------------------��"<<endl;Sleep(2000);
        system("pause");system("cls");
        ZaoN(8);
    }
    if(x==1)
    {
        Yan(1);
        cout<<"�������׳����ˣ�"<<endl<<endl;
        Sleep(1000);system("cls");Bai();
        cout<<"��-----------------------------��"<<endl;
        cout<<"���µ��˳��֣�                 ��"<<endl;
        cout<<"��                             ��"<<endl;
        cout<<"���������ף�                   ��"<<endl;
        cout<<"�����⼼�ܡ���������           ��"<<endl;
        cout<<"��   ��������30                ��"<<endl;
        cout<<"��   Ч������������һ������    ��"<<endl;
        cout<<"��     ����ʱ�䣺3�غ�         ��"<<endl;
        cout<<"��Ѫ����1000                   ��"<<endl;
        cout<<"�������ң�100                ��"<<endl;
        cout<<"�����ţ� ";Yan(1);cout<<"��";Bai();cout<<"                    ��"<<endl;
        cout<<"��-----------------------------��"<<endl;Sleep(2000);
        system("pause");system("cls");
        ZaoN(9);
    }
    if(x==2)
    {
        Yan(2);                         
        cout<<"ľ�����׳����ˣ�"<<endl<<endl;
        Sleep(1000);system("cls");Bai();
        cout<<"��-----------------------------��"<<endl;
        cout<<"���µ��˳��֣�                 ��"<<endl;
        cout<<"��                             ��"<<endl;
        cout<<"��ľ�����ף�                   ��"<<endl;                                                                      
        cout<<"�����⼼�ܡ����񶾣�           ��"<<endl;
        cout<<"��   Ч����ʹÿ�����˹���2��   ��"<<endl;
        cout<<"��   ����ʱ�䣺2�غ�           ��"<<endl;
        cout<<"����������10*4                 ��"<<endl;
        cout<<"��Ŀ�꣺��������               ��"<<endl;
        cout<<"������ʱ�䣺4�غ�              ��"<<endl;
        cout<<"��Ѫ����1000                   ��"<<endl;
        cout<<"�����ţ� ";Yan(2);cout<<"��";Bai();cout<<"                    ��"<<endl;
        cout<<"��-----------------------------��"<<endl;Sleep(2000);                       
        system("pause");system("cls");
        ZaoN(10);
    }
    if(x==3)
    {
        Yan(3);
        cout<<"쫷���׳����ˣ�"<<endl<<endl;
        Sleep(1000);system("cls");Bai();
        cout<<"��-----------------------------��"<<endl;
        cout<<"���µ��˳��֣�                 ��"<<endl;
        cout<<"��                             ��"<<endl;
        cout<<"��쫷���ף�                   ��"<<endl;
        cout<<"�����⼼�ܡ����÷磺           ��"<<endl;
        cout<<"��   ��������50*2����������    ��"<<endl;
        cout<<"��   Ч��������2����λ��λ��   ��"<<endl;
        cout<<"��   Ŀ�꣺����2�����������   ��"<<endl;
        cout<<"����������30%*������Ѫ��       ��"<<endl;
        cout<<"��Ŀ�꣺ǰ��������             ��"<<endl;
        cout<<"��Ѫ����1000                   ��"<<endl;
        cout<<"�����ţ� ";Yan(3);cout<<"��";Bai();cout<<"                    ��"<<endl;
        cout<<"��-----------------------------��"<<endl;Sleep(2000);
        system("pause");system("cls");
        ZaoN(11);
    }
    if(x==4)
    {
        Yan(4);
        cout<<"������׳����ˣ�"<<endl<<endl;
        Sleep(1000);system("cls");Bai();
        cout<<"��-----------------------------��"<<endl;
        cout<<"���µ��˳��֣�                 ��"<<endl;
        cout<<"��                             ��"<<endl;
        cout<<"��������ף�                   ��"<<endl;
        cout<<"�����⼼�ܡ�������           ��"<<endl;
        cout<<"��   ��������30*5              ��"<<endl;
        cout<<"��   Ŀ�꣺�����������        ��"<<endl;
        cout<<"����������40+30+20+10+5        ��"<<endl;
        cout<<"��Ŀ�꣺ǰ�������             ��"<<endl;
        cout<<"��Ѫ����1000                   ��"<<endl;
        cout<<"�����ţ� ";Yan(4);cout<<"��";Bai();cout<<"                    ��"<<endl;
        cout<<"��-----------------------------��"<<endl;Sleep(2000);
        system("pause");system("cls");
        ZaoN(12);
    }
    Moo=1;
}
void Mai(int x)
{
    char a;
    if(x==0) Money+=10,Yan(5),Sleep(500),cout<<"��Ľ��+10��"<<endl<<endl,Bai();
    if(x==1) Money+=30,Yan(3),Sleep(500),cout<<"�����ٳǣ�",Yan(5),cout<<"��Ľ��+30��"<<Money<<endl<<endl,Bai();
    if(Money>=300) Money=300,Yan(3),cout<<"��Ҵ����Ѵ����ޣ�"<<endl<<endl,Bai(),Sleep(500);
    Yan(5),Sleep(500),cout<<"��Ľ��������"<<Money<<endl<<endl,Bai(),Sleep(500);
    y:
    while(Money>=100)
    {
        memset(X,0,sizeof(X));
        for(int i=1;i<=nl;i++) X[N[i].Zhong]++;
        if(Money>=100) cout<<"�����ڿ��Թ���1.��ũ�ڣ�100��ң�  ";if(Money>=120&&X[2]<5) cout<<"2.�ػ�ǹ��120��ң�  ";if(Money>=150&&X[3]<5) cout<<"3.�Ȼ��ڣ�150��ң�  ";if(Money>=200&&X[4]<3) cout<<"4.�����  ";
        if(Money>=250&&X[0]==0) cout<<"5.��ǽ��250��ң�  ";if(Money>=270&&X[6]+X[7]+X[8]<2) cout<<"6.����ڣ�270��ң�  ";if(Money>=300&&X[5]<3) cout<<"7.����ڣ�300��ң�";
        if(Money>=100)
        {
            cout<<endl<<endl<<"---���빺��ʲô������0ȡ����---  ";a=_getch();cout<<a<<endl;
            if(a=='0') break;
            if(a<'0'||a>'7') {cout<<"��Ч���롣"<<endl<<endl;Sleep(500);goto y;}
            Zao(a-'0');cout<<endl<<endl;Bai();War();
            goto y;
            Yan(5),Sleep(500),cout<<"��Ľ��������"<<Money<<endl<<endl,Bai(),Sleep(500);
        }
    }cout<<endl;
    z:
    while(Dao>0||Yi>0||Shan>0||Qing>0||Hu>0)
    {
        War();
        if(Dao>0||Yi>0||Shan>0||Qing>0||Hu>0) cout<<"�����ڿ���ʹ�ã�"; if(Dao>0) cout<<"1.����("<<Dao<<"��) ";if(Yi>0) cout<<"2.ҽ�ư�("<<Yi<<"��) ";if(Shan>0) cout<<"3.���ⵯ("<<Shan<<"��) ";if(Qing>0) cout<<"4.��Ѫ��("<<Qing<<"��) ";if(Hu>0) cout<<"5.�޵л���("<<Hu<<"��) ";
        if(Dao>0||Yi>0||Shan>0||Qing>0||Hu>0)
        {
            cout<<endl<<endl<<"---����ʹ��ʲô������0ȡ����---  ";a=_getch();cout<<a<<endl;
            if(a=='0') break;
            if(a<'0'||a>'9') {cout<<"��Ч���롣"<<endl<<endl;Sleep(500);goto y;}
            Yong(a-'0');cout<<endl<<endl;
            goto z;
        }
    }cout<<endl;
}
void Chu(int y)
{
    if(y<=1) Yan(1),cout<<"ѽ�����˸�������"<<endl<<endl,ZaoN(1);
    if(y>=2&&y<4) Yan(2),cout<<"ѽ�����˸������"<<endl<<endl,ZaoN(2);
    if(y>=4&&y<5) Yan(3),cout<<"ѽ�����˸��ڱ���"<<endl<<endl,ZaoN(3);
    if(y>=5&&y<6) Yan(4),cout<<"ѽ�����˸�ҩ����"<<endl<<endl,ZaoN(4);
    if(y>=6&&y<7) Yan(6),cout<<"ѽ�����˸��ڻң�"<<endl<<endl,ZaoN(6);
    if(y>=7&&y<10) Yan(5),cout<<"ѽ�����˸�̹�ˣ�"<<endl<<endl,ZaoN(5);
    if(y>=10) cout<<"û���µ��˳��֡�"<<endl<<endl;
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
        if(i!=7) cout<<"��";Sleep(50);
    }cout<<"��Ŀ�꣬";Sleep(100);cout<<R<<"*7���˺���"<<endl<<endl;
    for(int i=30;i>0;i--) if(k[i]==1) Die(i);
}
void Jiu(int n)
{
    Sleep(100);int R=15+rand()%11;
    int y=rand()%n+1;
    D[y].Xue+=R;
    cout<<y;Sleep(100);
    cout<<"��Ŀ�꣬";Sleep(100);cout<<R<<"��Ѫ��"<<endl<<endl;
    Bai(); War();
}
void Bjing(int n,int i)
{
    int x=rand()%5;int y=rand()%10;int R=190+rand()%21,R2=30+rand()%21;
    if(x==0&&D[i].Bing==0){ Yan(4),cout<<"��ջ��״�����"<<R<<"���˺���"<<endl<<endl;if(Hub==0&&D[i].Bing==0) N[1].Xue-=R,DieN(1);return;}
    if(x>=1&&x<3&&D[i].Bing==0)
    {
        Yan(4),cout<<"��ջ���ɨ�䣡"<<R2<<"*"<<nl<<"���˺���"<<endl<<endl;
        if(Hub==0&&D[i].Bing==0) for(int i=1;i<=nl;i++) N[i].Xue-=R2,DieN(i);return;
    }
    if(nl<4&&dl>=3) {cout<<"��ջ���������"<<endl<<endl;return;}
    if(x==3) {Yan(4),cout<<"��ջ����ٻ���"<<endl<<endl;Chu(y);Bai();War();}
    if(x==4) {Yan(4),cout<<"��ջ����ٻ���"<<endl<<endl;Chu(y);if(dl<3) y=rand()%10,Chu(y);Bai();War();}
    Bai();Sleep(100);
}
void Bbing(int n,int i)
{
    int x=rand()%5;int y=rand()%n+1;int z=rand()%10;int R=20+rand()%21;
    if(x<2&&D[i].Bing==0)
    {
        if(Hub==0&&D[i].Bing==0) N[y].Bing=3,N[y].Xue-=30,DieN(y);
        Yan(4),cout<<"�������׹������������㷽��";cout<<nl-y+1;Sleep(100);
        cout<<"��Ŀ�꣬";Sleep(300);cout<<R<<"���˺���"<<endl<<endl;
        Bai();Sleep(500),War();
        return;
    }
    if((dl>=3&&nl<4)||x==2) {cout<<"��������������"<<endl<<endl;return;}
    if(x==3) {Yan(4),cout<<"���������ٻ���"<<endl<<endl;Chu(z);Bai();War();}
    if(x==4) {Yan(4),cout<<"���������ٻ���"<<endl<<endl;Chu(z);if(dl<3) z=rand()%10,Chu(z);Bai();War();}
    Bai();
}
void Bdu(int n,int i)
{
    int x=rand()%8;int y=rand()%10;
    if(x<2&&D[i].Bing==0)
    {
        Yan(4),cout<<"ľ����������Ŷ���";
        if(Hub==0&&D[i].Bing==0)
        {
            cout<<"���������ж���"; 
            for(int i=1;i<=nl;i++) N[i].Du=4;
        }
        cout<<endl<<endl;return;
    }
    if(x==2&&D[i].Bing==0) {Yan(4),cout<<"ľ�������򼺷��Ŷ������е����ж�������*2��"<<endl<<endl,Baodb=2;return;}
    if((x>4)||(nl<4&&dl>=3)) {cout<<"ľ������������"<<endl<<endl;return;}
    if(x>2&&x<=4) {Yan(4),cout<<"ľ�������ٻ���"<<endl<<endl;Chu(y);Bai();War();}
    if(x==5) {Yan(4),cout<<"ľ�������ٻ���"<<endl<<endl;Chu(y);if(dl<3) y=rand()%10,Chu(y);Bai();War();}
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
        Yan(4),cout<<"쫷���׹����磡�������㷽��"<<n-y+1<<"����"<<n-z+1<<"��������λ�ã�";swap(N[y],N[z]);
        if(Hub==0) Sleep(300);cout<<R<<"*2���˺���",N[y].Xue-=R,N[z].Xue-=R,DieN(y),DieN(z);
        cout<<endl<<endl;Bai();Sleep(500),War();return;
    }
    if(x==1&&Fengb==1) x=5;
    if(x==1&&D[i].Bing==0&&Fengb==0)
    {
        Yan(4),cout<<"쫷���׹����磡�����˼�����"<<yy<<"����"<<zz<<"�����˵�λ�ã�"<<endl<<endl;swap(D[yy],D[zz]);
        Bai();Sleep(500),War();Fengb=1;
        return;
    }
    if((dl>=3&&nl<4)||x==5) {cout<<"쫷����������"<<endl<<endl;return;}
    if(x==2) if(Hub==0&&D[i].Bing==0){cout<<"쫷���׹����磡ǰ��������Ѫ����30%��"<<endl<<endl;if(N[3].Xue!=0) N[3].Xue*=0.7,DieN(3);if(N[2].Xue!=0) N[2].Xue*=0.7,DieN(2);if(N[1].Xue!=0) N[1].Xue*=0.7,DieN(1);}
    if(x==3) {Yan(4),cout<<"쫷�����ٻ���"<<endl<<endl;Chu(xx);Bai();War();}
    if(x==4) {Yan(4),cout<<"쫷�����ٻ���"<<endl<<endl;Chu(xx);if(dl<3) xx=rand()%10,Chu(xx);Bai();War();}
    Bai();
}
void Byan(int n,int i)
{
    int x=rand()%5;int y=rand()%10;
    if(x==0&&D[i].Bing==0)
    {
        int R=35+rand()%11,R1=25+rand()%11,R2=15+rand()%11,R3=5+rand()%11,R4=1+rand()%10;
        Yan(4),cout<<"������׺���ų���������ԭ��";
        if(Hub==0&&D[i].Bing==0) cout<<R<<"+"<<R1<<"+"<<R2<<"+"<<R3<<"+"<<R4<<"���˺���";cout<<endl<<endl;
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
        Yan(4),cout<<"������׵Ļ���۳�5���������������";
        if(Hub==0&&D[i].Bing==0)
        {
            cout<<"�����˵�";
            for(int i=0;i<5;i++)
            {
                int z=rand()%n+1;
                N[z].Xue-=R;
                k[z]=1;
                cout<<nl-z+1;Sleep(50);
                if(i!=4) cout<<"��";Sleep(50);
            }
            cout<<"��Ŀ�꣬";Sleep(100);cout<<R<<"*5�˺���";cout<<endl<<endl;
            for(int i=30;i>0;i--) if(k[i]==1) DieN(i);
        }
        return;
    }
    if((nl<4&&dl>=3)||x==2) {cout<<"�������������"<<endl<<endl;return;}
    if(x==3) {Yan(4),cout<<"��������ٻ���"<<endl<<endl;Chu(y);Bai();War();}
    if(x==4) {Yan(4),cout<<"��������ٻ���"<<endl<<endl;Chu(y);if(dl<3) y=rand()%10,Chu(y);Bai();War();}
    Bai();Sleep(100);
}
void Round()
{
    system("cls");t++;int R,R2,R3;
    if(t>=3305536) cout<<"��"<<t-3305536<<"��"<<endl<<endl;
    else cout<<"��"<<t<<"��"<<endl<<endl;
    if(t%10==0&&t>=30) Yan(5),cout<<"�ɾͣ�����"<<t<<"�죬��ɣ���30��ң�"<<endl,Bai(),Money+=30;
    if(Money>=300) Money=300,Yan(3),cout<<endl<<"��Ҵ����Ѵ����ޣ�"<<endl<<endl,Bai(),Sleep(500);
    War();Fengb=0;
    for(int i=1;i<=nl;i++) if(N[i].Hui!=0) N[i].Xue+=30;
    for(int i=1;i<=nl;i++) if(N[i].Du!=0) N[i].Xue-=10,DieN(i);
    if(Baob!=0) Bao=2;if(Baob==0) Bao=1;if(Baodb!=0) Baod=2;if(Baodb==0) Baod=1;if(Biaob==0) Biao=0;
    if(D[1].Xue<=0)
    {
        if(t!=0) cout<<"������ʱû�з��ֵ��ˡ�"<<endl<<endl;Sleep(500);
        for(int i=nl;i>0;i--)
        {   int b=0;Yan(N[i].Zhong);
            if(N[i].Zhong==0) {cout<<"��ǽΡȻ������"<<endl<<endl;}
            if(b==0&&N[i].Zhong==6&&N[i].Bing==0) cout<<"����ڣ�",Yan(4),Sleep(200),cout<<"��1����������"<<endl<<endl,Bai(),N[i].Zhong++,b=1;
            if(b==0&&N[i].Zhong==7&&N[i].Bing==0) cout<<"����ڣ�",Yan(4),Sleep(200),cout<<"��2����������"<<endl<<endl,Bai(),N[i].Zhong++,b=1;
            if(b==0&&N[i].Zhong==8&&N[i].Bing==0) {cout<<"����ڣ�",Yan(4),Sleep(200),cout<<"��3����������";Sleep(200);cout<<"���ƴ�����"<<endl<<endl;Bai();}
        }Bai();
    }
    else
    {
        if(Hub!=0) Yan(5),cout<<"�޵л���ҫҫ���ԣ������е��˵Ĺ����赲���⡣"<<endl<<endl,Sleep(500);
        for(int j=1;j<=Baod;j++)
        {
            if(j==2) Yan(4),cout<<"�ڶ��ԵĴ߷��£����˷�񹥻��ţ�"<<endl<<endl,Sleep(500); 
            for(int i=1;i<=dl;i++)
            {
            int c=0;Yan(D[i].Zhong);
            if(D[i].Bing!=0) Yan(4),cout<<"�����ⵯ��ǿ����,�����������۾���"<<endl<<endl,Sleep(500);
            if(D[i].Zhong==1&&nl>=0&&Hub==0&&D[i].Bing==0) R=20+rand()%21,cout<<"������ǹ�ˣ�"<<R<<"���˺���"<<endl<<endl,N[1].Xue-=R,DieN(1);
            if(D[i].Zhong==2&&nl>=0&&Hub==0&&D[i].Bing==0) R=10+rand()%21,cout<<"�������һ������ǰһ�̣�"<<R<<"���˺���"<<endl<<endl,N[1].Xue-=20,DieN(1);
            if(D[i].Zhong==3&&nl>=0&&Hub==0&&D[i].Bing==0) R=40+rand()%21,cout<<"�ڱ���������쳹��ʣ�"<<R<<"���˺���"<<endl<<endl,N[1].Xue-=50,DieN(1);
            if(D[i].Zhong==4&&nl>=0&&D[i].Bing==0) cout<<"ҩ����ʼ���ƣ��ָ��˵�",Jiu(dl);
            if(D[i].Zhong==5&&nl>=0&&Hub==0&&D[i].Bing==0) R=70+rand()%21,cout<<"̹�˵Ĵ��׵����ڹܿڹ��������г����"<<R<<"���˺���"<<endl<<endl,N[1].Xue-=80,DieN(1);
            if(c==0&&D[i].Zhong==6&&nl>=0&&D[i].Bing==0) cout<<"�ڻҵ�ȼ��",Yan(4),cout<<"ը�������ţ�"<<endl<<endl,D[i].Zhong++,c=1;
            if(c==0&&D[i].Zhong==7&&nl>=0&&D[i].Bing==0) {R=490+rand()%21,cout<<"�ڻ�",Yan(4),cout<<"��ը������",Sleep(500),cout<<R<<"���˺���"<<endl<<endl;if(Hub==0) N[1].Xue-=500,DieN(1);D[i].Xue-=500,Die(i),c=1;}
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
            if(j==2) Yan(4),cout<<"��Ѫ�屬���ˣ��������ط������ӵ���"<<endl<<endl,Sleep(500),Baob--; 
            for(int i=nl;i>0;i--)
            {
            int b=0;Yan(N[i].Zhong);
            if(N[i].Zhong==0) {cout<<"��ǽΡȻ������"<<endl<<endl;Sleep(200);}
            if(N[i].Zhong==1&&D[1].Zhong!=0&&N[i].Bing==0) {if(D[1].Zhong!=0)R=20+rand()%21,cout<<"��ũ��һ�ڷ�����"<<R<<"���˺���"<<endl<<endl;if(Biao!=0) D[Biao].Xue-=R,Die(Biao);else D[1].Xue-=R,Die(1);Sleep(200);}
            if(N[i].Zhong==2&&D[1].Zhong!=0&&N[i].Bing==0) {if(D[1].Zhong!=0)R=40+rand()%21,cout<<"�ػ�ǹ���������ӵ���"<<R<<"���˺���"<<endl<<endl;if(Biao!=0) D[Biao].Xue-=R,Die(Biao);else D[1].Xue-=R,Die(1);Sleep(200);}
            if(N[i].Zhong==3&&D[1].Zhong!=0&&N[i].Bing==0) {if(D[1].Zhong!=0)R=60+rand()%21,cout<<"�Ȼ��ڵ��ڵ�����һ�������������ߣ�"<<R<<"���˺���"<<endl<<endl;if(Biao!=0) D[Biao].Xue-=R,Die(Biao);else D[dl].Xue-=R,Die(dl);Sleep(200);}
            if(N[i].Zhong==4&&D[1].Zhong!=0&&N[i].Bing==0) {if(D[1].Zhong!=0)R=40+rand()%21,R2=20+rand()%21,R3=rand()%21,cout<<"�������������һ�"<<R<<"+"<<R2<<"+"<<R3<<"���˺���"<<endl<<endl;if(Biao!=0){if(D[Biao+2].Zhong!=0)D[Biao+2].Xue-=R3,Die(Biao+2);if(D[Biao+1].Zhong!=0)D[Biao+1].Xue-=R2,Die(Biao+1);if(D[Biao].Zhong!=0)D[Biao].Xue-=R,Die(Biao);}else{if(D[3].Zhong!=0)D[3].Xue-=R3,Die(3);if(D[2].Zhong!=0)D[2].Xue-=R2,Die(2);if(D[1].Zhong!=0)D[1].Xue-=R,Die(1);}Sleep(200);}
            if(N[i].Zhong==5&&D[1].Zhong!=0&&N[i].Bing==0) {if(dl!=0) cout<<"����ڵ�7ö������γ�������е�";Huo(dl);Sleep(200);}
            if(b==0&&N[i].Zhong==6&&N[i].Bing==0) cout<<"����ڣ�",Yan(4),Sleep(200),cout<<"��1����������"<<endl<<endl,Bai(),N[i].Zhong++,b=1,Sleep(200);
            if(b==0&&N[i].Zhong==7&&N[i].Bing==0) cout<<"����ڣ�",Yan(4),Sleep(200),cout<<"��2����������"<<endl<<endl,Bai(),N[i].Zhong++,b=1,Sleep(200);
            if(b==0&&N[i].Zhong==8&&N[i].Bing==0){cout<<"����ڣ�",Yan(4),Sleep(200),cout<<"��3����������";if(D[1].Zhong!=0){R=290+rand()%21,R2=90+rand()%21,Sleep(200);cout<<"Ȼ��...",Sleep(200),cout<<"�䣡����",Sleep(200),cout<<R<<"+"<<R2<<"���˺���"<<endl<<endl,N[i].Zhong-=2;if(Biao!=0){if(D[Biao+1].Zhong!=0)D[Biao+1].Xue-=R2,Die(Biao+1);D[Biao].Xue-=R,Die(Biao),b=1;} else {if(D[2].Zhong!=0)D[2].Xue-=R2,Die(2);D[1].Xue-=R,Die(1),b=1;}}else cout<<"���ƴ�����"<<endl<<endl;Bai();Sleep(200);}
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
            cout<<endl<<"�����ˣ������ˣ�����"<<endl<<endl;Sleep(1000);
            cout<<"�������"<<t<<"�졣"<<endl<<endl;Bai();Sleep(1000);system("pause");
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
            if(y<5) cout<<"û���µ��˳��֡�"<<endl<<endl;
            if(y>=5&&y<9) Yan(1),cout<<"ѽ�����˸�������"<<endl<<endl,ZaoN(1);
            if(y>=9) Yan(2),cout<<"ѽ�����˸������"<<endl<<endl,ZaoN(2);
        }
        if(t<20&&t>=10)
        {
            if(dl>=2) y=7;
            if(y>=7) {cout<<"û���µ��˳��֡�"<<endl<<endl;y=0;}
            else Chu(y);u++;
            int w=rand()%3;
            if(dl<2&&w<3&&u<2) goto x;
        }
        if(t<29&&t>=20)
        {
            if(dl>=2) y=9;
            if(y>=9) {cout<<"û���µ��˳��֡�"<<endl<<endl;}
            else Chu(y);u++;
            int w=rand()%3;
            if(dl<2&&w<3&&u<2) goto x;
        }
        if(t==29) Mo();
        if(t<45&&t>=30)
        {
            if(dl>=3) y=10;
            if(y>=10) {cout<<"û���µ��˳��֡�"<<endl<<endl;}
            else Chu(y);u++;
            int w=rand()%2;
            if(dl<2&&w<1&&u<2) goto x;
        }
        if(t<59&&t>=45)
        {
            if(dl>=nl+1) y=20;
            if(y==20) {cout<<"û���µ��˳��֡�"<<endl<<endl;}
            else Chu(y);u++;
            if(u<3) goto x;
        }
        if(t==59) Mo();if(t==60) Mo();
        if(t<79&&t>60)
        {
            if(dl>=nl+2) y=20;
            if(y==20) {cout<<"û���µ��˳��֡�"<<endl<<endl;}
            else Chu(y);u++;
            if(u<3) goto x;
            if(u==3&&y==0) goto x;
        }
        if(t==79) Mo();if(t==80) Mo();if(t==81) Mo();
        if(t<99&&t>81)
        {
            if(dl>=nl+2) y=20;
            if(y==20) {cout<<"û���µ��˳��֡�"<<endl<<endl;}
            else Chu(y);u++;
            if(u<3) goto x;
            if(u==3&&y==0) goto x;
        }
        if(t==99)
        {
            system("cls");Sleep(500);
            cout<<"��100��"<<endl<<endl;Yan(5);
            cout<<"�ɻ��ĺ���������������Ұ��Ϊѩ��......"<<endl<<endl; Sleep(1000);
            cout<<"���ҵ�ս��˲��ž������׺�Ȼ����......"<<endl<<endl;  Sleep(1000);
            cout<<"�ڲ�������У�Զ���������ֵ��Գ����ӵ�����......"<<endl<<endl; Sleep(1000);
            cout<<"�������Ԯ�����ˣ�����"<<endl<<endl;  Sleep(1000);
            cout<<"ΰ��Ľ�˧�������ǵ��׶�����ס�ˣ�����"<<endl<<endl;Sleep(3000);
            system("cls");Bai();
            cout<<endl<<"��ϷĿ���ɣ���Ϸ������"<<endl<<endl;Sleep(2000);
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
    cout<<endl<<" ���ڽ��н�ѧģʽ��"<<endl;Sleep(1000);system("cls");
    cout<<"��-------------------------��"<<endl;
    cout<<"��������������             ��"<<endl;
    cout<<"��                         ��"<<endl;
    cout<<"����ũ�ڣ�                 ��"<<endl;
    cout<<"����������30               ��"<<endl;
    cout<<"��Ѫ����100                ��"<<endl;
    cout<<"����ֵ��100                ��"<<endl;
    cout<<"��Ŀ�꣺��һ������         ��"<<endl;
    cout<<"����ཨ����������         ��"<<endl;
    cout<<"�����ţ� ";Yan(1);cout<<"��";Bai();cout<<"                ��"<<endl;
    cout<<"��-------------------------��"<<endl;Sleep(2000);
    cout<<"�밴1���Խ����ũ�ڡ�"<<endl<<endl;a=_getch();N[1].Zhong=1,N[1].Xue=100,nl++;War(); 
    cout<<"�ü��ˣ���Ӧ���ܰ�������ס���С�"<<endl<<endl;Sleep(1000);
    system("pause");system("cls");
    cout<<"��-------------------------��"<<endl;
    cout<<"���µ��˳��֣�             ��"<<endl;
    cout<<"��                         ��"<<endl;
    cout<<"��������                   ��"<<endl;
    cout<<"����������30               ��"<<endl;
    cout<<"��Ѫ����50                 ��"<<endl;
    cout<<"�������ң�20             ��"<<endl;
    cout<<"��Ŀ�꣺��һ������         ��"<<endl;
    cout<<"�����ţ� ";Yan(1);cout<<"��";Bai();cout<<"                ��"<<endl;
    cout<<"��-------------------------��"<<endl;Sleep(2000);
    D[1].Zhong=1,D[1].Xue=50,dl=1;
    system("pause");system("cls");War(); 
    cout<<"���ڿ�����ļ�ũ���ܰ�����ô����"<<endl<<endl;Sleep(1000);
    t=3305536,Round();
    cout<<"��ũ��Ѫ���������ս��ǰ�ڵıر���"<<endl<<endl;Sleep(1000);
    system("pause");system("cls");
    cout<<"��-------------------------��"<<endl;
    cout<<"��������������             ��"<<endl;
    cout<<"��                         ��"<<endl;
    cout<<"���ػ�ǹ��                 ��"<<endl;
    cout<<"����������50               ��"<<endl;
    cout<<"��Ѫ����80                 ��"<<endl;
    cout<<"����ֵ��120                ��"<<endl;
    cout<<"��Ŀ�꣺��һ������         ��"<<endl;
    cout<<"����ཨ��������5          ��"<<endl;
    cout<<"�����ţ� ";Yan(2);cout<<"��";Bai();cout<<"                ��"<<endl;
    cout<<"��-------------------------��"<<endl;Sleep(2000);
    cout<<"�ػ�ǹ�������ߣ����Դ������������"<<endl<<endl;Sleep(1000);
    system("pause");system("cls");
    cout<<"��-------------------------��"<<endl;
    cout<<"���µ��˳��֣�             ��"<<endl;
    cout<<"��                         ��"<<endl;
    cout<<"�������                   ��"<<endl;
    cout<<"����������20               ��"<<endl;
    cout<<"��Ѫ����100                ��"<<endl;
    cout<<"�������ң�30             ��"<<endl;
    cout<<"��Ŀ�꣺��һ������         ��"<<endl;
    cout<<"�����ţ� ";Yan(2);cout<<"��";Bai();cout<<"                ��"<<endl;
    cout<<"��-------------------------��"<<endl;Sleep(2000);
    cout<<"���Ѫ�࣬���������͡�"<<endl<<endl;Sleep(1000);
    system("pause");system("cls");
    cout<<"��-------------------------��"<<endl;
    cout<<"��������������             ��"<<endl;
    cout<<"��                         ��"<<endl;
    cout<<"���Ȼ��ڣ�                 ��"<<endl;
    cout<<"����������70               ��"<<endl;
    cout<<"��Ѫ����150                ��"<<endl;
    cout<<"����ֵ��150                ��"<<endl;
    cout<<"����ཨ��������5          ��"<<endl;
    cout<<"��Ŀ�꣺���һ������       ��"<<endl;
    cout<<"�����ţ� ";Yan(3);cout<<"��";Bai();cout<<"                ��"<<endl;
    cout<<"��-------------------------��"<<endl;Sleep(2000);
    cout<<"�Ȼ��ڹ������ߣ���������һЩѪ�ٵ��˳���ʱ�����ɱ��"<<endl<<endl;Sleep(1000);
    system("pause");system("cls");
    cout<<"��-------------------------��"<<endl;
    cout<<"���µ��˳��֣�             ��"<<endl;
    cout<<"��                         ��"<<endl;
    cout<<"���ڱ���                   ��"<<endl;
    cout<<"����������50               ��"<<endl;
    cout<<"��Ѫ����30                 ��"<<endl;
    cout<<"�������ң�20             ��"<<endl;
    cout<<"��Ŀ�꣺��һ������         ��"<<endl;
    cout<<"�����ţ� ";Yan(3);cout<<"��";Bai();cout<<"                ��"<<endl;
    cout<<"��-------------------------��"<<endl;Sleep(2000);
    cout<<"�ڱ��������ߣ���Ҫ�پ���"<<endl<<endl;Sleep(1000);
    system("pause");system("cls");
    cout<<"��-------------------------��"<<endl;
    cout<<"��������������             ��"<<endl;
    cout<<"��                         ��"<<endl;
    cout<<"���������                 ��"<<endl;
    cout<<"����������50+30+10         ��"<<endl;
    cout<<"��Ѫ����200                ��"<<endl;
    cout<<"����ֵ��200                ��"<<endl;
    cout<<"��Ŀ�꣺ǰ��������         ��"<<endl;
    cout<<"����ཨ��������5          ��"<<endl;
    cout<<"�����ţ� ";Yan(4);cout<<"��";Bai();cout<<"                ��"<<endl;
    cout<<"��-------------------------��"<<endl;Sleep(2000);
    cout<<"���������ֵ���������"<<endl<<endl;Sleep(1000);
    system("pause");system("cls");
    cout<<"��-------------------------��"<<endl;
    cout<<"��������������             ��"<<endl;
    cout<<"��                         ��"<<endl;
    cout<<"����ǽ��                   ��"<<endl;
    cout<<"��Ѫ����500                ��"<<endl;
    cout<<"����ֵ��250                ��"<<endl;
    cout<<"����ཨ��������1          ��"<<endl;
    cout<<"�����ţ� ��                ��"<<endl;
    cout<<"��-------------------------��"<<endl;Sleep(2000);
    cout<<"�ȳ��������൱���޵ж�غϣ�"<<endl<<endl;
    cout<<"��ǽ���Զ�������ս����ǰ����"<<endl<<endl;Sleep(1000);
    system("pause");system("cls");
    cout<<"��-------------------------��"<<endl;
    cout<<"���µ��˳��֣�             ��"<<endl;
    cout<<"��                         ��"<<endl;
    cout<<"��ҩ����                   ��"<<endl;
    cout<<"����������-20�������з���  ��"<<endl;
    cout<<"��Ѫ����100                ��"<<endl;
    cout<<"�������ң�30             ��"<<endl;
    cout<<"��Ŀ�꣺����һ���з�       ��"<<endl;
    cout<<"�����ţ� ";Yan(4);cout<<"��";Bai();cout<<"                ��"<<endl;
    cout<<"��-------------------------��"<<endl;Sleep(2000);
    cout<<"ҩ��Ѫ�࣬�������ṥ����"<<endl<<endl;Sleep(1000);
    system("pause");system("cls");
    cout<<"��-------------------------��"<<endl;
    cout<<"��������������             ��"<<endl;
    cout<<"��                         ��"<<endl;
    cout<<"������ڣ�                 ��"<<endl;
    cout<<"����������300+100          ��"<<endl;
    cout<<"��       ������2�غϣ�     ��"<<endl;
    cout<<"��Ѫ����400                ��"<<endl;
    cout<<"����ֵ��270                ��"<<endl;
    cout<<"��Ŀ�꣺��һ������         ��"<<endl;
    cout<<"����ཨ��������2          ��"<<endl;
    cout<<"�����ţ� ";Yan(6);cout<<"��";Bai();cout<<"                ��"<<endl;
    cout<<"��-------------------------��"<<endl;Sleep(2000);
    cout<<"������ǶԸ�̹�˵ıر�������"<<endl<<endl;Sleep(1000);
    system("pause");system("cls");
    cout<<"��-------------------------��"<<endl;
    cout<<"���µ��˳��֣�             ��"<<endl;
    cout<<"��                         ��"<<endl;
    cout<<"���ڻң�                   ��"<<endl;
    cout<<"����������500������1�غϣ� ��"<<endl;
    cout<<"��Ѫ����10                 ��"<<endl;
    cout<<"�������ң�10             ��"<<endl;
    cout<<"��Ŀ�꣺��һ������         ��"<<endl;
    cout<<"�����ţ� ";Yan(6);cout<<"��";Bai();cout<<"                ��"<<endl;
    cout<<"��-------------------------��"<<endl;Sleep(2000);
    cout<<"�ڻҳ���ʱ����ص�һʱ�佫���ɱ��"<<endl<<endl;
    cout<<"�ڻұ�ըʱ���Լ�Ҳ��������"<<endl<<endl;Sleep(1000);
    system("pause");system("cls");
    cout<<"��-------------------------��"<<endl;
    cout<<"��������������             ��"<<endl;
    cout<<"��                         ��"<<endl;
    cout<<"������ڣ�                 ��"<<endl;
    cout<<"����������20*7             ��"<<endl;
    cout<<"��Ѫ����300                ��"<<endl;
    cout<<"����ֵ��300                ��"<<endl;
    cout<<"��Ŀ�꣺����Ÿ�����       ��"<<endl;
    cout<<"����ཨ��������3          ��"<<endl;
    cout<<"�����ţ� ";Yan(5);cout<<"��";Bai();cout<<"                ��"<<endl;
    cout<<"��-------------------------��"<<endl;Sleep(2000);
    cout<<"����ڼ������ã����ڱر���"<<endl<<endl;Sleep(1000);
    system("pause");system("cls");
    cout<<"��-------------------------��"<<endl;
    cout<<"���µ��˳��֣�             ��"<<endl;
    cout<<"��                         ��"<<endl;
    cout<<"��̹�ˣ�                   ��"<<endl;
    cout<<"����������80               ��"<<endl;
    cout<<"��Ѫ����200                ��"<<endl;
    cout<<"�������ң�50             ��"<<endl;
    cout<<"��Ŀ�꣺��һ������         ��"<<endl;
    cout<<"�����ţ� ";Yan(5);cout<<"��";Bai();cout<<"                ��"<<endl;
    cout<<"��-------------------------��"<<endl;Sleep(2000);
    cout<<"̹�ˣ����ج�Σ�"<<endl<<endl;Sleep(2000);
    system("pause");system("cls");
    cout<<endl<<"����ʱ������һ����ǽ��"<<endl<<endl;Sleep(2000);
    cout<<"��������Ҫ���ѽ�ң���Ľ��ÿ�غ�+10��"<<endl<<endl;Sleep(2000);
    cout<<"���ڻ��BOSS�������ף���ʱ��Ľ��ÿ�غ�+30��"<<endl<<endl;Sleep(2000);
    cout<<"��Ľ�Ҵ�������Ϊ300��"<<endl<<endl,Sleep(2000);
    cout<<"��һ�������м��ʵ����ߡ�"<<endl<<endl;Sleep(2000);
    cout<<"ÿ������һ�غ�ֻ�ܹ���һ�Ρ�"<<endl<<endl;Sleep(2000);
    cout<<"��������������ʱ����Ϸ������"<<endl<<endl;Sleep(2000);
    cout<<"ΰ��Ľ�˧�������㱣�����ǵ��׶���"<<endl<<endl;Sleep(2000);
    system("pause");system("cls");
}
int main()
{
    srand((unsigned)time(NULL));
    system("mode con cols=46 lines=40");
    ST:system("cls");
    memset(N,0,sizeof(N));memset(D,0,sizeof(D));memset(X,0,sizeof(X));
    t=nl=dl=Moo=Biao=Biaob=Bao=Baob=Baod=Baodb=Hub=Fengb=Sha=Jian=Shab=Jianb=0;
    Bai(); cout<<endl<<" ----------------��������ս------------------"<<endl;
    cout<<" --------------------------���ߣ�whsx--------"<<endl<<endl;
    cout<<" �������õ���";Yan(3);cout<<"����Ҫ���س���"<<endl<<endl;Bai();
    cout<<" ���룺 1.��ѧģʽ   2.ս��ģʽ"<<endl;
    st:
    char a;a=_getch();
    if(a=='1') {Jiao(),N[1].Zhong=0,N[1].Xue=500,nl=1,Money=90;cout<<endl<<"���ڽ���ս��ģʽ��"<<endl<<endl;Sleep(1000);t=0;Round();goto ST;}
    else if(a=='2') {N[1].Zhong=0,N[1].Xue=500,nl=1,Money=90;cout<<endl<<" ���ڽ���ս��ģʽ��"<<endl<<endl;Sleep(1000);t=0;Round();goto ST;}
    else goto st;
    Bai();
    return 0;
}

