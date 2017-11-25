#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
class multiplayer
{
    string name1; ///player 1 name
    string name2; ///player 2 name
    int hpp1; ///hit point player 1
    int hpp2; ///hit point player 2
    int mpp1; ///magic point player 1
    int mpp2; ///magic point player 2
    int move1; ///player 1 move
    int move2; ///player 2 move
public:
    multiplayer()
    {
        hpp1=100;
        hpp2=100;
        mpp1=0;
        mpp2=0;
    }
    int m_player();
    void show();
    void name();
    void turn1();
    void turn2();
    void m1();
    void m2();
    void choicep1();
    void choicep2();
    void sowrdp1();///6
    void sowrdp2();
    void magicp1();///14
    void magicp2();
    void ultip1();///23
    void ultip2();
    void winp1();
    void winp2();
    int result();
};
void multiplayer::name()
{
    cout<<"Enter The Names:"<<endl<<"Player 1: ";
    cin>>name1;
    cout<<"Player 2: ";
    cin>>name2;
}
void multiplayer::show()
{
    cout<<"Hit Point: "<<name1<<": "<<hpp1<<". "<<name2<<": "<<hpp2<<"."<<endl;
    cout<<"Magic Point: "<<name1<<": "<<mpp1<<". "<<name2<<": "<<mpp2<<"."<<endl;
    cout<<"Make your choice:"<<endl<<"To use sword press 1."<<endl<<"To use magic press 2 (requires at least magic point 3)"<<endl<<"To use ULTIMATE power press 3 (requires at least magic point 5)"<<endl;
}
void multiplayer::turn1()
{
    cout<<name1<<"'s turn."<<endl<<"Enter your choice (1/2/3): ";
}
void multiplayer::turn2()
{
    cout<<name2<<"'s turn."<<endl<<"Enter your choice (1/2/3): ";
}
void multiplayer::m1()
{
    cin>>move1;
}
void multiplayer::m2()
{
    cin>>move2;
}
void multiplayer::sowrdp1()
{
    cout<<name1<<" used his sword."<<endl;
    hpp2-=6;
    if(mpp1<5) mpp1+=1;
}
void multiplayer::sowrdp2()
{
    cout<<name2<<" used his sword."<<endl;
    hpp1-=6;
    if(mpp2<5) mpp2+=1;
    Sleep(2000);

}
void multiplayer::magicp1()
{
    if(mpp1==3||mpp1==4)
    {
        cout<<name1<<" used a magic."<<endl;
        hpp2-=11;
        mpp1-=3;
    }
    else if(mpp1==5)
    {
        cout<<name1<<" used a powerful magic."<<endl;
        hpp2-=14;
        mpp1-=4;
    }
    else
    {
        cout<<"Magic using failed. Using magic requires 3 magic points."<<endl;
    }
}
void multiplayer::magicp2()
{
    if(mpp2==3||mpp2==4)
    {
        cout<<name2<<" used a magic."<<endl;
        hpp1-=11;
        mpp2-=3;
    }
    else if(mpp2==5)
    {
        cout<<name2<<" used a powerful magic."<<endl;
        hpp1-=14;
        mpp2-=3;
    }
    else
    {
        cout<<"Magic using failed. Using magic requires 3 magic points."<<endl;
    }
    Sleep(2000);
}
void multiplayer::ultip1()
{
    if(mpp1==5)
    {
        cout<<name1<<" used ultimate power."<<endl;
        hpp2-=23;
        mpp1-=5;
    }
    else
    {
        cout<<"Ultimate Power using failed. Ultimate Power requires 5 magic points."<<endl;
    }
}
void multiplayer::ultip2()
{
    if(mpp2==5)
    {
        cout<<name2<<" used ultimate power."<<endl;
        hpp1-=23;
        mpp2-=5;
    }
    else
    {
        cout<<"Ultimate Power using failed. Ultimate Power requires 5 magic points."<<endl;
    }
    Sleep(2000);
}
void multiplayer::winp1()
{
    system("cls");
    cout<<name1<<" won."<<endl;
}
void multiplayer::winp2()
{
    system("cls");
    cout<<name2<<" won."<<endl;
}
void multiplayer::choicep1()
{
    if(move1==1) sowrdp1();
    if(move1==2) magicp1();
    if(move1==3) ultip1();
}
void multiplayer::choicep2()
{
    if(move2==1) sowrdp2();
    if(move2==2) magicp2();
    if(move2==3) ultip2();
}
int multiplayer::result()
{
    if(hpp1<=0) {winp2(); return 1;}
    if(hpp2<=0) {winp1(); return 1;}
}
int multiplayer::m_player()
{
    int p=0;///player turn counter
    multiplayer m;
    m.name();
    fight:
    system("cls");
    m.show();
    if(p%2==0)///player1
    {
        m.turn1();
        m.m1();
        m.choicep1();
        m.result();
        if(m.result()==1) return 1;
        p+=1;
    }
    if(p%2==1)///player2
    {
        m.turn2();
        m.m2();
        m.choicep2();
        m.result();
        if(m.result()==1) return 1;
        p+=1;
    }
    goto fight;
}
int main()
{///to be added in main_menu 
    multiplayer m;
    m.m_player();

}
