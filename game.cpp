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

class LevelsandStore
{
    public:

int store()
    {
while(1)
{   
    int a;
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
    cin>>a;
    switch(a)
        {
            case    1   :   coins-=1000;
                            armor=50;
                            break;
            case    2   :   coins-=2000;
                            armor=100;
                            break;
            case    3   :   coins-=1000;
                            IH++;
                            break;
            case    4   :   coins-=1000;
                            DB++;
                            break;
            case    5   :   coins-=750;
                            IV++;
                            break;
            case    6   :   coins-=1250;
                            AC++;
                            break;  
            case    7   :   inventory();
                            break;         
            case    8   :   system("CLS");
                            return 0;
                            break;

                default :   system("CLS");
                            error_put();
        }
}
    }

int level(int leveldecider)
    {
        int choice,ehealth=50,checkdb=0,checkiv=0,checkcurser=0;
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
    cout<<"-------------\t\t\t\t\t\t\t\t\t\t\t\t-------------"<<endl;
    cout<<"|   Player  |\t\t\t\t\t\t\t\t\t\t\t\t|  Oponent  |"<<endl;
    cout<<"-------------\t\t\t\t\t\t\t\t\t\t\t\t-------------"<<endl;
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
    cout<<"\n[6] EXIT TO HOMESCREEN"<<endl;
    cout<<"\n\nChoice : ";
    cin>>choice;
    srand(time(0));
    switch(choice)
        {
            case    1   :   if(checkdb==1)
                            {   ehealth-=(rand()%21 +35);  checkdb=0;   } 
                            else 
                                ehealth-=(rand()%21 +15);
                            
                            cout<<"\n\nYou dealt damage of "<<temp2-ehealth;

                            if(ehealth<1)
                                {cout<<"\n\nCongrats!"; int cc=getcoins(leveldecider);
                                cout<<"\nYou got "<<cc<<" coins"; coins+=cc;  getch(); return 0;}

                            if(checkiv==1)
                            {   health-=0;  checkiv=0;   } 
                            else 
                            {   
                                if(checkcurser==1)
                                {cout<<"\nU r cursed\n"; health-=getdamage(leveldecider+10);}
                                else
                                {    health-=getdamage(leveldecider); checkcurser=curser(leveldecider);}
                            }
                                
                            cout<<"\nYour enemy dealt damage of "<<temp-health;

                            if(health<1)
                                {cout<<"\n\nYou Lost!"; getch(); return 0;}
                            getch();
                            break;
            
            case    2   :   if(IH>0&&health<100)
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
            
            case    3   :   if(DB>0)
                            {
                                checkdb=1;
                                DB--;
                            }
                            else
                                {cout<<"You dont have enough potions!"; getch();}
                            break;
            
            case    4   :   if(IV>0)
                            {
                                checkiv=1;
                                IV--;
                            }
                            else
                                {cout<<"You dont have enough potions!"; getch();}
                            break;

            case    5   :   if(AC>0)
                            {
                                checkcurser=0;
                                AC--;
                            }
                            else
                                {cout<<"You dont have enough potions!"; getch();}
                            break;

            case    6   :   return 0;
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
    cout<<"Rules & Recommendation for the HARDCORE LEVEL : \n";
    cout<<"\n > Store would be accessible once before the 1st level starts";
    cout<<"\n > You won't be allowed to access the store in between the levels";
    cout<<"\n > Recommended gear for the ultimate quest : ";
    cout<<"\n\n\t\t * Full Armor ";
    cout<<"\n\t\t * 10 Health Potions ";
    cout<<"\n\t\t * 8 Damage Boosters ";
    cout<<"\n\t\t * 7 Invisibility Potion ";
    cout<<"\n\t\t * 3 Anti-Curse  ";
    cout<<"\n > About 32000 coins would be needed for all of these ";
    cout<<"\n\nPress any key to continue.";
    getch();
    level(1);
    level(2);
    level(3);
    level(4);
    level(5);
    }
};

int main()
{
    int choice;
    LevelsandStore obj;
    hardcore obj2;
while(1)
{   
    system("CLS");
    nameofgame();
    health=100;
    cout<<"Select Level : \n[1] Level 1\n[2] Level 2\n[3] Level 3\n[4] Level 4\n[5] Level 5\n[6] Hard Core\n[7] Store\n[8] Inventory\n[9] Exit";
    cout<<"\n\nChoice : ";
    cin>>choice;
    switch(choice)
    {
        case 1 : obj.level(1);
                break;
        case 2 : obj.level(2);
                break;
        case 3 : obj.level(3);
                break;
        case 4 : obj.level(4);
                break;
        case 5 : obj.level(5);
                break;
        case 6 : obj2.hc();
                break;
        case 7 : obj.store();
                break;
        case 8 : inventory();
                break;
        case 9 : return 0;

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
        printf("%c",177);
        Sleep(x);
    }
    nameofgame();
}
void nameofgame()
{
    system("CLS");
    cout<<endl;
    cout<<"\t\t\t\t\t\t"<<"--------------------"<<endl;
    cout<<"\t\t\t\t\t\t"<<"|                  |"<<endl;
    cout<<"\t\t\t\t\t\t"<<"|   Go Mickey Go   |"<<endl;
    cout<<"\t\t\t\t\t\t"<<"|                  |"<<endl;
    cout<<"\t\t\t\t\t\t"<<"--------------------"<<endl;
}
void error_put()
{
    system("CLS");
    cout<<"Error. Please enter a Valid choice. Press any key to Continue.\n\n";
    getch();
    main();
}

int getdamage(int level)
{
    srand(time(0));
    int x;
    switch(level)
    {
    case 1   :   x=(rand()%6 +15);
                break;
    case 11  :   x=(rand()%6 +30);
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
    case 5   :   x=(rand()%16 +25);
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
                    { cout<<"\n\nYou got Cursed!\n\n";    return 1; }
                break;
    case 2   :   x=(rand()%50);
                    if(x==32||x==12||x==47)
                    { cout<<"\n\nYou got Cursed!\n\n";    return 1; }
                break;
    case 3   :   x=(rand()%50);
                    if(x==32||x==12||x==47||x==22||x==43)
                    { cout<<"\n\nYou got Cursed!\n\n";    return 1; }
                break;
    case 4   :   x=(rand()%20);
                    if(x==13||x==9||x==3)
                    { cout<<"\n\nYou got Cursed!\n\n";    return 1; }
                break;
    case 5   :   x=(rand()%10);
                    if(x==3||x==7)
                    { cout<<"\n\nYou got Cursed!\n\n";    return 1; }
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
    case 5   :   x=5000;
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
                                    cout<<"| Armor | "<<armor<<" |"<<endl;
    if(armor<9)
        cout<<"-------------\n";
    else if(armor>=10&&armor<=99)
        cout<<"--------------\n";
    else if(armor>=100)
        cout<<"---------------\n";


    cout<<"\t\t\t--------------------------------"<<endl;
    cout<<"\t\t\t|    Instant Health    |   "<<IH<<"   |"<<endl;
    cout<<"\t\t\t--------------------------------"<<endl;
    cout<<"\t\t\t|    Damage Booster    |   "<<DB<<"   |"<<endl;
    cout<<"\t\t\t--------------------------------"<<endl;
    cout<<"\t\t\t| Invisibility Potions |   "<<IV<<"   |"<<endl;
    cout<<"\t\t\t--------------------------------"<<endl;
    cout<<"\t\t\t|      Anti-Curse      |   "<<AC<<"   |"<<endl;
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
    
    cout<<"| Coins | "<<coins<<" |"<<endl;

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