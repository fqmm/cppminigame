//# ��Ʊ��Ϸ

#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
#include <ctime>
using namespace std;
int money=100;
int t=0;
int tt=-1;
int v;
int d;
void borrow()
{
    if(tt!=-1)
    {
        cout<<"�����ڲ��ܽ�Ǯ"<<endl;
        return;
    }
    cout<<"��Ҫ�����Ǯ��"<<endl;
    cin>>v;
    if (d==1||d==2)
    {
        if (v>1000) cout<<"�㲻�ܽ���ô��Ǯ��"<<endl,cout<<"��Ҫ�����Ǯ��"<<endl,cin>>v;
        if (v<=1000) money+=v,cout<<"10���Ժ���Ҫ��"<<2*v<<"��Ԫ"<<endl;
        return;
    }
    else
    {
        if (v>100) cout<<"�㲻�ܽ���ô��Ǯ��"<<endl,cout<<"��Ҫ�����Ǯ��"<<endl,cin>>v;
        if (v<=100) money+=v,cout<<"10���Ժ���Ҫ��"<<2*v<<"��Ԫ"<<endl;
        return;
    }
}
bool pay()
{
    cout<<"������Ҫ�� "<<2*v<<endl;
    money-=2*v;
    tt=-1;
    v=0;
    if(money<=0) return false;
    else return true;
}
int main(int argc, char *argv[])
{
    cout<<"��ӭ������Ʊ��Ϸ��"<<endl<<endl<<"��ܰ��ʾ������Ϸ������ʹ��С����������Ӣ����ĸ�������ַ�����Ϸ����˵�����⣩��"<<endl<<"�������Ը���"<<"�����ڿ��ܻ���ֿ��٣�������������"<<endl<<endl;
    cout<<"��ѡ���Ѷ�(������ż���):"<<endl<<"1:����"<<" "<<"2:��"<<" "<<"3:��ͨ"<<" "<<"4:�е�"<<" "<<"5:����"<<endl;
    cin>>d;
    if (d==1) cout<<"��ѡ���Ѷ�:����"<<endl<<endl;
    if (d==2) cout<<"��ѡ���Ѷ�:��"<<endl<<endl;
    if (d==3) cout<<"��ѡ���Ѷ�:��ͨ"<<endl<<endl;
    if (d==4) cout<<"��ѡ���Ѷ�:�е�"<<endl<<endl;
    if (d==5) cout<<"��ѡ���Ѷ�:����"<<endl<<endl;
    while(1)
    {
        if (d<1||d>5) cout<<"û�����ѡ��"<<endl<<"��ѡ���Ѷ�(������ż���):"<<endl<<"1:����"<<" "<<"2:��"<<" "<<"3:��ͨ"<<" "<<"4:�е�"<<" "<<"5:����"<<endl,cin>>d;
        if (d>=1&&d<=5) break;
    }
    bool flag=true;
    srand(time(0));
    int a[10000];
    int n,p;
    char c[4];
    if (d==1)
    {
        cout<<"ÿ�Ų�Ʊ �����Ϊ1��Ԫ�����ۼ�Ϊ5��Ԫ�����������"<<endl<<"С����10��Ԫ"<<endl<<"�н���20��Ԫ"<<endl<<"�󽱣�100��Ԫ"<<endl<<"�޶��1,000��Ԫ"<<endl<<"�ܿ˺���10,000��Ԫ"<<endl;
        cout<<"����100��Ԫ������׬�˳���1,000,000,000��Ԫ����ͷ����ˡ�"<<endl<<"�������ʧȥ�����е�Ǯ�����Ʋ��ˡ�"<<endl;
        cout<<"��������Ǯ�����1,000��Ԫ����������룬��0��"<<endl<<"���ס���������ʮ���Ժ�����볥��������"<<endl;
        cout<<"�������Ʊ��������Ʊ����buy/sell��"<<endl;
    }
    if (d==2)
    {
        cout<<"ÿ�Ų�Ʊ �����Ϊ2��Ԫ�����ۼ�Ϊ3��Ԫ�����������"<<endl<<"С����5��Ԫ"<<endl<<"�н���20��Ԫ"<<endl<<"�󽱣�100��Ԫ"<<endl<<"�޶��1,000��Ԫ"<<endl<<"�ܿ˺���10,000��Ԫ"<<endl;
        cout<<"����100��Ԫ������׬�˳���1,000,000,000��Ԫ����ͷ����ˡ�"<<endl<<"�������ʧȥ�����е�Ǯ�����Ʋ��ˡ�"<<endl;
        cout<<"��������Ǯ�����1,000��Ԫ����������룬�밴0��"<<endl<<"���ס���������ʮ���Ժ�����볥��������"<<endl;
        cout<<"�������Ʊ��������Ʊ����buy/sell��"<<endl;
    }
    if (d==3)
    {
        cout<<"ÿ�Ų�Ʊ �ۼ�2��Ԫ�����������"<<endl<<"С����5��Ԫ"<<endl<<"�н���20��Ԫ"<<endl<<"�󽱣�100��Ԫ"<<endl<<"�޶��1,000��Ԫ"<<endl<<"�ܿ˺���10,000��Ԫ"<<endl;
        cout<<"����100��Ԫ������׬�˳���1,000,000,000��Ԫ����ͷ����ˡ�"<<endl<<"�������ʧȥ�����е�Ǯ�����Ʋ��ˡ�"<<endl;
        cout<<"��������Ǯ�����100��Ԫ����������룬�밴0��"<<endl<<"���ס���������ʮ���Ժ�����볥��������"<<endl;
        cout<<"�������Ʊ��������Ʊ����buy/sell��"<<endl;
    }
    if (d==4)
    {
        cout<<"ÿ�Ų�Ʊ �ۼ�3��Ԫ�����������"<<endl<<"С����5��Ԫ"<<endl<<"�н���20��Ԫ"<<endl<<"�󽱣�100��Ԫ"<<endl<<"�޶��1,000��Ԫ"<<endl<<"�ܿ˺���10,000��Ԫ"<<endl;
        cout<<"����100��Ԫ������׬�˳���10,000,000,000��Ԫ����ͷ����ˡ�"<<endl<<"�������ʧȥ�����е�Ǯ�����Ʋ��ˡ�"<<endl;
        cout<<"��������Ǯ�����100��Ԫ����������룬�밴0��"<<endl<<"���ס��������������Ժ�����볥��������"<<endl;
        cout<<"�������Ʊ��������Ʊ����buy/sell��"<<endl;
    }
    if (d==5)
    {
        cout<<"ÿ�Ų�Ʊ �����Ϊ5��Ԫ�����ۼ�Ϊ2��Ԫ�����������"<<endl<<"С����5��Ԫ"<<endl<<"�н���20��Ԫ"<<endl<<"�󽱣�100��Ԫ"<<endl<<"�޶��1,000��Ԫ"<<endl<<"�ܿ˺���5,000��Ԫ"<<endl;
        cout<<"����100��Ԫ������׬�˳���10,000,000,000��Ԫ����ͷ����ˡ�"<<endl<<"�������ʧȥ�����е�Ǯ������Ʋ��ˡ�"<<endl;
        cout<<"��������Ǯ�����100��Ԫ����������룬�밴0��"<<endl<<"���ס��������������Ժ�����볥��������"<<endl;
        cout<<"�������Ʊ��������Ʊ����buy/sell��"<<endl;
    }
    cin>>c;
    if(c[0]=='b'||c[0]=='B')
    {
        while(money>0)
        {
            if (d==1||d==2||d==3) if(money>=1000000000)
                {
                    cout<<"�㷢����! "<<endl;
                    cout<<"�㻨�� "<<t<<"��"<<endl;
                    system("pause");
                    return 0;
                }
            if (d==4||d==5) if(money>=10000000000)
                {
                    cout<<"�㷢����! "<<endl;
                    cout<<"�㻨�� "<<t<<"��"<<endl;
                    system("pause");
                    return 0;
                }
            t++;
            cout<<"��Ҫ����Ʊ��"<<" "<<"����$"<<money<<endl;
            cin>>n;
            if(n==0)
            {
                if (d=4)
                {
                    borrow();
                    tt=t+7;
                }
                if (d=5)
                {
                    borrow();
                    tt=t+5;
                }
                else
                {
                    borrow();
                    tt=t+10;
                }
            }
            if(t==tt)
            {
                flag=pay();
            }
            if(t==tt-1) cout<<"[����]����������컹Ǯ��"<<endl;
            if(flag==false)
            {
                cout<<"�㲻�ܳ�������Ǯ��"<<endl;
                cout<<"���Ʋ��ˡ�"<<endl;
                cout<<"��������"<<t<<"�졣"<<endl;
                system("pause");
                return 0;
            }
            flag=true;
            if(n<0)
            {
                cout<<"��Ϊ��Υ����������ϵͳǿ��ֹͣ�������Ϸ"<<endl;
                system("pause");
            }
            if (d==1) money=money-n;
            if (d==2||d==3) money=money-n*2;
            if (d==4) money=money-n*3;
            if (d==5) money=money-n*5;
            if(money<0)
            {
                cout<<"���Ʋ��ˡ�"<<endl;
                cout<<"��������"<<t<<"��"<<endl;
                system("pause");
                return 0;
            }
            long long xj=0,zj=0,dj=0,jejj=0,jkh=0;
            for(int i=0; i<n; i++)
            {
                p=rand()%12000;
                if(p==0)
                {
                    int q=0;
                    q=rand()%4;
                    if(q==1)
                    {
                        jkh++;
                        if (d==5) money+=5000;
                        else money+=10000;
                    }
                }
                else if(p>=1&&p<=8)
                {
                    int g=0;
                    g=rand()%2;
                    if(g==0)
                    {
                        jejj++;
                        money+=1000;
                    }
                }
                else if(p>=9&&p<=99)
                {
                    dj++;
                    money+=100;
                }
                else if((p>=100&&p<=399)||(p>1500&&p<=1600))
                {
                    zj++;
                    money+=20;
                }
                else if(p>=400&&p<=1500)
                {
                    xj++;
                    if (d==1) money+=10;
                    else money+=5;
                }
            }
            int xjm=5;
            if(d==1)xjm=10;
            if(xj)cout<<"��õ���"<<xj<<"��С��,��"<<xj*xjm<<"Ԫ"<<endl;
			if(zj)cout<<"��õ���"<<zj<<"���н�,��"<<zj*20<<"Ԫ"<<endl;
			if(dj)cout<<"��õ���"<<dj<<"����,��"<<dj*100<<"Ԫ"<<endl;
			if(jejj)cout<<"��õ���"<<jejj<<"���޶��,��"<<jejj*1000<<"Ԫ"<<endl;
    		int jkhm=10000;
			if(d==5)jkhm=5000;
			if(jkh)cout<<"��õ���"<<jkh<<"���ܿ˺�,��"<<jkh*jkhm<<"Ԫ"<<endl;
            if(money<=0)
            {
                cout<<"���Ʋ��ˡ�"<<endl;
                cout<<"��������"<<t<<"�졣"<<endl;
                system("pause");
                return 0;
            }
        }
    }
    if(c[0]=='s'||c[0]=='S')
    {
        if (d==1)
        {
            cout<<"����$"<<money<<endl;
            cout<<"����븶25��Ԫ��һ���̵ꡣ "<<endl;
            cout<<"��ֻ����ͬ��������Ʊ��Ϊ���Ǯ�� "<<endl;
            money-=25;
        }
        if (d==2)
        {
            cout<<"����$"<<money<<endl;
            cout<<"����븶35��Ԫ��һ���̵ꡣ "<<endl;
            cout<<"��ֻ����ͬ��������Ʊ��Ϊ���Ǯ�� "<<endl;
            money-=35;
        }
        if (d==3||d==4)
        {
            cout<<"����$"<<money<<endl;
            cout<<"����븶50��Ԫ��һ���̵ꡣ "<<endl;
            cout<<"��ֻ����ͬ��������Ʊ��Ϊ���Ǯ�� "<<endl;
            money-=50;
        }
        if (d==5)
        {
            cout<<"����$"<<money<<endl;
            cout<<"����븶60��Ԫ��һ���̵ꡣ "<<endl;
            cout<<"��ֻ����ͬ��������Ʊ��Ϊ���Ǯ�� "<<endl;
            money-=60;
        }
        cout<<"����$"<<money<<endl;
        while(money>0)
        {
            if (d==1||d==2||d==3) if(money>=1000000000)
                        {
                            cout<<"�㷢����!"<<endl;
                            cout<<"�㻨��"<<t<<"�졣"<<endl;
                            system("pause");
                            return 0;
                        }
                    if (d==4||d==5) if(money>=10000000000)
                        {
                            cout<<"�㷢����!"<<endl;
                            cout<<"�㻨��"<<t<<"�졣"<<endl;
                            system("pause");
                            return 0;
                        }
            t++;
            cout<<"��Ҫ������Ʊ�� "<<" "<<"����$"<<money<<endl;
            cin>>n;
            if(n==0)
            {
                borrow();
                tt=t+10;
            }
            if(t==tt) bool flag=pay();
            if(flag==false)
            {
                cout<<"�㲻�ܳ�������Ǯ��"<<endl;
                cout<<"���Ʋ��ˣ�"<<endl;
                cout<<"��������"<<t<<" �졣"<<endl;
                system("pause");
                return 0;
            }
            if(n<0 || n>money)
            {
                cout<<"ע��"<<endl;
                cout<<"���Ʋ��ˣ�"<<endl;
                cout<<"��������"<<t<<" ��"<<endl;
                system("pause");
                return 0;
            }
            if (d=1) money=money+n*5;
            if (d=2) money=money+n*3;
            else money=money+n*2;
            if(money<0)
            {
                cout<<"���Ʋ��ˣ�"<<endl;
                cout<<"��������"<<t<<" ��"<<endl;
                system("pause");
                return 0;
            }
            long long xj=0,zj=0,dj=0,jejj=0,jkh=0;
            for(int i=0; i<n; i++)
            {

                p=rand()%12000;
                if(p==0)
                {
                    int y;
                    y=rand()%4;
                    if(y==1)
                    {
                        jkh++;
                        if (d==5) money-=5000;
                        else money-=10000;
                    }
                }
                else if(p>=1&&p<=8)
                {
                    jejj++;
                    money-=1000;
                }
                else if(p>=15&&p<=50)
                {
                    dj++;
                    money-=100;
                }
                else if(p>=61&&p<=360)
                {
                    zj++;
                    money-=20;
                }
                else if(p>=401&&p<=1500)
                {
                    xj++;
                    money-=5;
                }

            }
            if(xj)cout<<"��ʧȥ��"<<xj<<"��С��,��"<<xj*5<<"Ԫ"<<endl;
            if(zj)cout<<"��ʧȥ��"<<zj<<"���н�,��"<<zj*20<<"Ԫ"<<endl;
            if(dj)cout<<"��ʧȥ��"<<dj<<"����,��"<<dj*100<<"Ԫ"<<endl;
            if(jejj)cout<<"��ʧȥ��"<<jejj<<"���޶��,��"<<jejj*1000<<"Ԫ"<<endl;
            int jkhm=10000;
            if(d==5)jkhm=5000;
            if(jkh)cout<<"��ʧȥ��"<<jkh<<"���ܿ˺�,��"<<jkh*jkhm<<"Ԫ"<<endl;
        }
    }
    if(money<=0)
    {
        cout<<"���Ʋ��ˡ�"<<endl;
        cout<<"��������"<<t<<"�졣"<<endl;
        system("pause");
        return 0;
    }
}

