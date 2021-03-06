#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <fstream>
#include <vector>
#define width 120
using namespace std;

int health=100,armor=0,IH=1,DB=2,IV=1,AC=1,coins=3500;
void loadingscreen(int x);
void nameofgame();
void error_put();
int getdamage(int level);
int curser(int level);
int getcoins(int level);
void inventory();
void cprinter();
void opponameprinter(int x);
void info();
void typer(string a, int b, int c);
int main();

class LevelsandStore
{
    public:

int store()
    {
while(1)
{   
    char a; 
    system("CLS");
    nameofgame();
    cprinter();
    cout<< "\n\t\t\t [1] Half Armor (1000) "<< endl
        << "\t\t\t [2] Full Armor (2000) "<< endl
        << "\t\t\t [3] Instant Health (1000) "<< endl
        << "\t\t\t [4] Damage Booster (1000) "<< endl
        << "\t\t\t [5] Invisibility Potion (750) "<< endl
        << "\t\t\t [6] Anti-Curse (1250) "<< endl
        << "\t\t\t [7] Inventory "<< endl
        << "\t\t\t [8] Exit " << endl;
    cout<<"\n\nChoice : ";
    string aab;
    cin>>aab;
    a=aab[0];
    switch(a)
        {
            case    '1'   :   coins-=1000;
                            armor=50;
                            break;
            case    '2'   :   coins-=2000;
                            armor=100;
                            break;
            case    '3'  :   coins-=1000;
                            IH++;
                            break;
            case    '4'   :   coins-=1000;
                            DB++;
                            break;
            case    '5'   :   coins-=750;
                            IV++;
                            break;
            case    '6'   :   coins-=1250;
                            AC++;
                            break;  
            case    '7'   :   inventory();
                            break;         
            case    '8'   :   system("CLS");
                            return 0;
                            break;

                default :   system("CLS");
                            error_put();
        }
}
    }

int level(int leveldecider, int checkhc)
    {
        int ehealth=50,checkdb=0,checkiv=0,checkcurser=0;
        char choice;
        switch(leveldecider)
        {
            case 2: ehealth=100; break;
            case 3: ehealth=150; break;
            case 4: ehealth=200; break;
            case 5: ehealth=250; break;
        }
    health+=armor;
    int amm=armor; armor=0;
    while(1)
    {   
        int temp=health,temp2=ehealth;
        system("CLS");
        nameofgame();
    opponameprinter(leveldecider);
    cout<<"HEALTH : "<<health<<"\t\t\t\t\t\t\t\t\t\t\t\tHEALTH : "<<ehealth;
    switch(amm)
    {
        case 0 : cout<<"\nARMOR : No Armor";
                break;
        case 50 : cout<<"\nARMOR : Half Armor";
                break;
        case 100 : cout<<"\nARMOR : Full Armor";
                break;
    }
    cout<<"\n\n\n[1] ATTACK";
    cout<<"\n[2] HEALTH POTION ("<<IH<<" available)";
    cout<<"\n[3] DAMAGE BOOSTER ("<<DB<<" available)";
    cout<<"\n[4] INVISIBILITY POTION ("<<IV<<" available)";
    cout<<"\n[5] ANTICURSE ("<<AC<<" available)";
    if(checkhc==0)
    {    cout<<"\n[6] EXIT TO HOMESCREEN"<<endl;    }
    cout<<"\n\nChoice : ";
    string aab;
    cin>>aab;
    choice=aab[0];
    srand(time(0));
    switch(choice)
        {
            case    '1'   :   if(checkdb==1)
                            {   ehealth-=(rand()%21 +35);  checkdb=0;   } 
                            else 
                                ehealth-=(rand()%21 +15);
                            
                            cout<<"\n\nYou dealt damage of "<<temp2-ehealth;

                            if(ehealth<1)
                                {printf("\x1B[32m\n\nCongrats!\033[0m"); 
                                int cc=getcoins(leveldecider);
                                cout<<"\nYou got ";printf("\x1B[33m%d\033[0m",cc);cout<<" coins!"; coins+=cc;  
                                cout<<"\n\nPress any key to continue."; getch(); return 0;}

                            if(checkiv==1)
                            {   health-=0;  checkiv=0;   } 
                            else 
                            {   
                                if(checkcurser==1)
                                {printf("\x1B[31m\n\nYou are Cursed\033[0m\n");  health-=getdamage(leveldecider+10);}
                                else
                                {    health-=getdamage(leveldecider); checkcurser=curser(leveldecider);}
                            }
                                
                            cout<<"\nYour enemy dealt damage of "<<temp-health;

                            if(health<1)
                                {printf("\x1B[31m\n\nYou Lost!\033[0m");  
                                cout<<"\n\nPress any key to continue."; getch(); 
                                if(checkhc==1) 
                                    main(); 
                                else
                                    return 0;}
                            cout<<"\n\nPress any key to continue.";
                            getch();
                            break;
            
            case    '2'   :   if(IH>0&&health<100)
                            {
                                health+=25;
                                if(health>100)
                                    {    int x=health-100;  health-=x; }
                                IH--;
                            }
                            else if(health>=100)
                                {cout<<"Health is already full!"; getch();}
                            else if(IH<=0)
                                {cout<<"You dont have enough potions!"; getch();}

                            break;
            
            case    '3'   :   if(DB>0)
                            {
                                checkdb=1;
                                DB--;
                            }
                            else
                                {cout<<"You dont have enough potions!"; getch();}
                            break;
            
            case    '4'   :   if(IV>0)
                            {
                                checkiv=1;
                                IV--;
                            }
                            else
                                {cout<<"You dont have enough potions!"; getch();}
                            break;

            case    '5'   :   if(AC>0)
                            {
                                checkcurser=0;
                                AC--;
                            }
                            else
                                {cout<<"You dont have enough potions!"; getch();}
                            break;

            case    '6'   :   if(checkhc==0)
                                return 0;
                            else
                                break;

                default :   system("CLS");
                            error_put();
        }
    }
    }

};

class hardcore : public LevelsandStore
{ 
    public:
    void hc()
    {
    system("CLS");
    nameofgame();
    char ques;
    cout<<"\n\nRules & Recommendation for the HARDCORE LEVEL : \n";
    string text="\n > Store would be accessible once before the 1st level starts\n > You won't be allowed to access the store in between the levels\n > Recommended gear for the ultimate quest : ";
    typer(text,30,0);
    cout<<"\n\n\t\t * Full Armor ";
    cout<<"\n\t\t * 10 Health Potions ";
    cout<<"\n\t\t * 8 Damage Boosters ";
    cout<<"\n\t\t * 7 Invisibility Potion ";
    cout<<"\n\t\t * 3 Anti-Curse  ";
    text="\n\n > About 35000 coins would be needed for all of these ";
    typer(text,30,4);
    text="\n > Once started you can't exit to the homescreen, until you've defeated all the enemies or have been defeated!";
    typer(text,50,3);
    cout<<"\n\nDo you want to continue?\n[1] Yes\n[2] No\n\nChoice : ";
    string aab;
    cin>>aab;
    ques=aab[0];
    switch(ques)
    {
        case '1' : store();
                    level(1,1);
                    level(2,1);
                    level(3,1);
                    level(4,1);
                    level(5,1);
                    break;
    
        case '2' : main();

        default : error_put();
                    break;
    }
    }
};

int main()
{
    loadingscreen(20);
    char choice;
    LevelsandStore obj;
    hardcore obj2;
while(1)
{   
    system("CLS");
    nameofgame();
    health=100;
    cout<<"\n\n\tSelect : \n\t\t\t[0] About The Game\n\t\t\t[1] Level 1\n\t\t\t[2] Level 2\n\t\t\t[3] Level 3\n\t\t\t"
    <<"[4] Level 4\n\t\t\t[5] Level 5\n\t\t\t[6] The Ultimate Quest\n\t\t\t[7] Store\n\t\t\t[8] Inventory\n\t\t\t[9] Exit";
    cout<<"\n\nChoice : ";
    string aab;
    cin>>aab;
    choice=aab[0];
    switch(choice)
    {
        case '0' : info();
                break;
        case '1' : obj.level(1,0);
                break;
        case '2' : obj.level(2,0);
                break;
        case '3' : obj.level(3,0);
                break;
        case '4' : obj.level(4,0);
                break;
        case '5' : obj.level(5,0);
                break;
        case '6' : obj2.hc();
                break;
        case '7' : obj.store();
                break;
        case '8' : inventory();
                break;
        case '9' : nameofgame();
                printf("\x1B[32m\n\nThank You for Playing!\033[0m\n\n"); 
                getch();
                return 0;

        default: system("CLS");
                error_put();
    }
}
    return 0;
}

void loadingscreen(int x)
{
    system("CLS"); 
    cout<<endl;
    cout<< "Loading..."<<endl;
    Sleep(100);
    for(int i=0;i<width;i++)
    {
        printf("%c",124);
        Sleep(x);
    }
}
void nameofgame()
{
    system("CLS");
    cout<<endl;
    
    printf("\x1B[34m\t\t\t\t\t\t------------------\033[0m\n");
    printf("\033[3;104;30m\t\t\t\t\t\t    Go Hero Go    \033[0m\n");
    printf("\x1B[34m\t\t\t\t\t\t------------------\033[0m\n");
    
}
void error_put()
{
    system("CLS");
    printf("\x1B[31mERROR!!!\033[0m");
    cout<<"\nPlease enter a Valid choice. Press any key to Continue.\n";
    getch();
}

int getdamage(int level)
{
    srand(time(0));
    int x;
    switch(level)
    {
    case 1   :   x=(rand()%6 +10);
                break;
    case 11  :   x=(rand()%6 +25);
                break;
    case 2   :   x=(rand()%11 +15);
                break;
    case 12  :   x=(rand()%11 +30);
                break;
    case 3   :   x=(rand()%16 +15);
                break;
    case 13  :   x=(rand()%16 +30);
                break;
    case 4   :   x=(rand()%16 +20);
                break;
    case 14  :   x=(rand()%16 +35);
                break;
    case 5   :   x=(rand()%16 +30);
                break;
    case 15  :   x=(rand()%16 +40);
                break;        
    default  :   x=0;
    }
    return x;
}

int curser(int level)
{
    srand(time(0));
    int x;
    switch(level)
    {
    case 1   :   x=(rand()%100);
                    if(x==32||x==92||x==47)
                    { printf("\x1B[31m\n\nYou got Cursed!\033[0m\n\n");    return 1; }
                break;
    case 2   :   x=(rand()%50);
                    if(x==32||x==12||x==47)
                    { printf("\x1B[31m\n\nYou got Cursed!\033[0m\n\n");     return 1; }
                break;
    case 3   :   x=(rand()%50);
                    if(x==32||x==12||x==47||x==22||x==43)
                    { printf("\x1B[31m\n\nYou got Cursed!\033[0m\n\n");     return 1; }
                break;
    case 4   :   x=(rand()%20);
                    if(x==13||x==9||x==3)
                    { printf("\x1B[31m\n\nYou got Cursed!\033[0m\n\n");     return 1; }
                break;
    case 5   :   x=(rand()%10);
                    if(x==3||x==7)
                    { printf("\x1B[31m\n\nYou got Cursed!\033[0m\n\n");     return 1; }
                break;
    
    default  :   x=0;
    }
    return 0;
}

int getcoins(int level)
{
    srand(time(0));
    int x;
    switch(level)
    {
    case 1   :   x=(rand()%501 +1500);
                break;
    case 2   :   x=(rand()%501 +2000);
                break;
    case 3   :   x=(rand()%501 +2500);
                break;
    case 4   :   x=(rand()%501 +3500);
                break;
    case 5   :   x=10000;
                break;       
    default  :   x=0;
    }
    return x;
}

void inventory()
{
    nameofgame();
    cprinter();
    if(armor<9)
        cout<<"-------------\n";
    else if(armor>=10&&armor<=99)
        cout<<"--------------\n";
    else if(armor>=100)
        cout<<"---------------\n";
                                    cout<<"| Armor | ";printf("\x1B[32m%d\033[0m",armor);cout<<" |"<<endl;
    if(armor<9)
        cout<<"-------------\n";
    else if(armor>=10&&armor<=99)
        cout<<"--------------\n";
    else if(armor>=100)
        cout<<"---------------\n";


    cout<<"\t\t\t--------------------------------"<<endl;
    cout<<"\t\t\t|    Instant Health    |   ";printf("\x1B[35m%d\033[0m",IH);cout<<"   |"<<endl;
    cout<<"\t\t\t--------------------------------"<<endl;
    cout<<"\t\t\t|    Damage Booster    |   ";printf("\x1B[35m%d\033[0m",DB);cout<<"   |"<<endl;
    cout<<"\t\t\t--------------------------------"<<endl;
    cout<<"\t\t\t| Invisibility Potions |   ";printf("\x1B[35m%d\033[0m",IV);cout<<"   |"<<endl;
    cout<<"\t\t\t--------------------------------"<<endl;
    cout<<"\t\t\t|      Anti-Curse      |   ";printf("\x1B[35m%d\033[0m",AC);cout<<"   |"<<endl;
    cout<<"\t\t\t--------------------------------"<<endl;

    cout<<"\n\nPress any key to continue.";
    getch();
}

void cprinter()
{
    if(coins<9)
        cout<<"-------------\n";
    else if(coins>=10&&coins<=99)
        cout<<"--------------\n";
    else if(coins>=100&&coins<=999)
        cout<<"---------------\n";
    else if(coins>=1000&&coins<=9999)
        cout<<"----------------\n";
    else if(coins>=10000&&coins<=99999)
        cout<<"-----------------\n";
    
    cout<<"| Coins | ";printf("\x1B[33m%d\033[0m",coins);cout<<" |"<<endl;
    

     if(coins<9)
        cout<<"-------------\n";
    else if(coins>=10&&coins<=99)
        cout<<"--------------\n";
    else if(coins>=100&&coins<=999)
        cout<<"---------------\n";
    else if(coins>=1000&&coins<=9999)
        cout<<"----------------\n";
    else if(coins>=10000&&coins<=99999)
        cout<<"-----------------\n";
}

void opponameprinter(int x)
{
    
    switch(x)
    {
    case 1   :  cout<<"----------\t\t\t\t\t\t\t\t\t\t\t\t-------------"<<endl;
                cout<<"|  ";printf("\x1B[32mHero\033[0m");cout<<"  |\t\t\t\t\t\t\t\t\t\t\t\t|  ";printf("\x1B[31mTin Man\033[0m");cout<<"  |"<<endl;
                cout<<"----------\t\t\t\t\t\t\t\t\t\t\t\t-------------"<<endl;
                break;

    case 2   :  cout<<"----------\t\t\t\t\t\t\t\t\t\t\t\t-------------------"<<endl;
                cout<<"|  ";printf("\x1B[32mHero\033[0m");cout<<"  |\t\t\t\t\t\t\t\t\t\t\t\t| ";printf("\x1B[31mPerverse Knight\033[0m");cout<<" |"<<endl;
                cout<<"----------\t\t\t\t\t\t\t\t\t\t\t\t-------------------"<<endl;
                break;

    case 3   :  cout<<"----------\t\t\t\t\t\t\t\t\t\t\t\t---------------------"<<endl;
                cout<<"|  ";printf("\x1B[32mHero\033[0m");cout<<"  |\t\t\t\t\t\t\t\t\t\t\t\t| ";printf("\x1B[31mMonster der Nacht\033[0m");cout<<" |"<<endl;
                cout<<"----------\t\t\t\t\t\t\t\t\t\t\t\t---------------------"<<endl;
                break;

    case 4   :  cout<<"----------\t\t\t\t\t\t\t\t\t\t\t\t---------------------"<<endl;
                cout<<"|  ";printf("\x1B[32mHero\033[0m");cout<<"  |\t\t\t\t\t\t\t\t\t\t\t\t| ";printf("\x1B[31mProtector of Dark\033[0m");cout<<" |"<<endl;
                cout<<"----------\t\t\t\t\t\t\t\t\t\t\t\t---------------------"<<endl;
                break;

    case 5   :  cout<<"----------\t\t\t\t\t\t\t\t\t\t\t\t----------------"<<endl;
                cout<<"|  ";printf("\x1B[32mHero\033[0m");cout<<"  |\t\t\t\t\t\t\t\t\t\t\t\t| ";printf("\x1B[31mDemon Dragon\033[0m");cout<<" |"<<endl;
                cout<<"----------\t\t\t\t\t\t\t\t\t\t\t\t----------------"<<endl;
                break;
    
    default  :  cout<<"----------\t\t\t\t\t\t\t\t\t\t\t\t------------"<<endl;
                cout<<"|  ";printf("\x1B[32mHero\033[0m");cout<<"  |\t\t\t\t\t\t\t\t\t\t\t\t| ";printf("\x1B[31mOpponent\033[0m");cout<<" |"<<endl;
                cout<<"----------\t\t\t\t\t\t\t\t\t\t\t\t------------"<<endl;
                break;
    }
}

void typer(string a, int b,int c)
{
    int x=0;
    if(c==0)
    {    while(a[x]!='\0')
        {
	    cout<<a[x];
	    Sleep(b);
	    x++;
        }   }

    else if(c==1)
    {
        while(a[x]!='\0')
        {
	    printf("\x1B[31m%c\033[0m",a[x]);
	    Sleep(b);
	    x++;
        }   }

    else if(c==2)
    {
        while(a[x]!='\0')
        {
	    printf("\x1B[35m%c\033[0m",a[x]);
	    Sleep(b);
	    x++;
        }   }

    else if(c==3)
    {
        while(a[x]!='\0')
        {
	    printf("\x1B[36m%c\033[0m",a[x]);
	    Sleep(b);
	    x++;
        }   }

    else if(c==4)
    {
        while(a[x]!='\0')
        {
	    printf("\x1B[33m%c\033[0m",a[x]);
	    Sleep(b);
	    x++;
        }   }
}
void info()
{
    nameofgame();

    string text="\n\nWelcome to Go Hero Go!\nThe player would have a bunch of different battles to choose from.\nEvery opponent is different from one another, as the level increases it becomes more difficult to win.\nDefeating an opponent would give you rewards in the form of coins that you can use to stack up your inventory!\nLook-Out for the Curses! They'll deal tons of extra damage until cured";
    typer(text,30,0);

    text="\n\nAbout The Opponents : ";
    typer(text,30,0);
    text="\n\n\tTin Man : The Notorious Pawn of Evil.";
    typer(text,30,1);
    cout<<"\n\t\t\t| Damage Range : 10-15 | 3% chance of  giving a Curse | Coins rewarded : 1500-2000 |";

    text="\n\n\tPerverse Knight : The one who swore to fight the Good.";
    typer(text,30,1);
    cout<<"\n\t\t\t| Damage Range : 15-25 | 6% chance of  giving a Curse | Coins rewarded : 2000-2500 |";

    text="\n\n\tMonster der Nacht : The lurker of the Night.";
    typer(text,30,1);
    cout<<"\n\t\t\t| Damage Range : 15-30 | 10% chance of giving a Curse | Coins rewarded : 2500-3000 |";
    
    text="\n\n\tProtector of Dark : The one who pledged to bestow Darkness in the world.";
    typer(text,30,1);
    cout<<"\n\t\t\t| Damage Range : 20-35 | 15% chance of giving a Curse | Coins rewarded : 3500-4000 |";

    text="\n\n\tDemon Dragon : Conqueror of Worlds.";
    typer(text,30,1);
    cout<<"\n\t\t\t| Damage Range : 30-45 | 20% chance of giving a Curse |   Coins rewarded : 10000   |";

    text="\n\nAbout the Potions & Gear :";
    typer(text,30,0);

    text="\n\n\t\t> Health Potion : It'll provide instant 25 health points (Max Health : 100)\n\t\t> Damage Booster : It'll deal extra 20 damage on the opponent (Base Damage Range : 15-35)\n\t\t> Invisibility Potion : It'll hide the Hero from opponent's next attack\n\t\t> Anti-Curse : It can be used to remove the Curse effect\n\t\t> Half Armor will provide 50 and Full armor will provide 100 extra non-regenerative Health Points (Not stackable)";
    typer(text,30,2);

    text="\n\nHow To Play?\nYou have the choice to take this adventure in any direction you want to! Just make sure you press the right KEY ;)";
    typer(text,50,3);
    
    cout<<"\n\nPress any key to continue.";
    getch();

}