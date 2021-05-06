#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
bool game_over;
int final_score;
int DessionOfToss()
{
    int choice_for_toss=0;
    bool result_of_toss=false;
    int toss_winner_choice=0;
    cout<<"\n\t\t\t TOSS OF MATCH "<<endl;
    cout<<"\n Instructions::\n1.you can choose head or tail.\n\n2.enter 1 for head or 2 for tail.\n\n3.if result of toss match with your selected option you will win the toss.\n\n"<<endl;
    do
    {
    cout<<"enter your chooice::";
    cin>>choice_for_toss;
    if(choice_for_toss!=1 && choice_for_toss!=2)
     cout<<"\nERROR!enter 1 or 2"<<endl;
    }
    while(choice_for_toss!=1 && choice_for_toss!=2);
	int result_of_coinflip=0;
	srand(time(0));
	result_of_coinflip = (rand()%2)+1;
	cout << " result_of_coinflip = " << result_of_coinflip << endl;
	if(result_of_coinflip==choice_for_toss)
    {
       result_of_toss=true;
       cout<<"\t\t\t CONGRATULATIONS!you won the toss! \t\t"<<endl;
       cout<<"\n\nNow you can decide either to bat first or field"<<endl;
       cout<<"enter 1 to bat or 2 to field first";
      do
         {
            cout<<"\n\nyour choice::";
            cin>>toss_winner_choice;
            if(toss_winner_choice!=1 && toss_winner_choice!=2)
            cout<<"\nERROR!enter 1 or 2"<<endl;
         }
    while(toss_winner_choice!=1 && toss_winner_choice!=2);
    }
    else
    {
        cout<<"\t\t\t  SORRY!you loss the toss \t\t\nyou have to::"<<endl;
        toss_winner_choice = (rand()%2)+1;
    }
        return toss_winner_choice;
}

int batting(int toss_winner_choice,bool noball,bool wide,bool bouncer,bool spin)
{
    int score_to_add=0;
    bool isstrike=false;
    int random_isstrike=0;
    if(toss_winner_choice==1)
    {
        int strike=0;
        static int count_for_strike=0;
        if(count_for_strike==0)
        {
           cout<<"\n\t\tBATTING\n\nWELCOME!you are here to bat first.\n\nINSTRUCTIONS::"<<endl;
           cout<<"\n1.you have one over to play select either to strike(1) or not(0) when asked for it."<<endl;
           cout<<"\n2.if you choose to strike you will be able to score 0,1,2,4,6."<<endl;
          cout<<"\n3.on striking there will be possibilty of being caught out or run out."<<endl;
           cout<<"\n4.if you lose wicket you will loose the match and game will over."<<endl;
          cout<<"\n5.enter  1 to strike 0 for not to strike. "<<endl;
          count_for_strike++;
        }
          do
         {
             cout<<"\ndo you want to strike or not?"<<endl;
             cout<<"\nyour choice::";
             cin>>strike;
             if(strike!=1 && strike!=0)
             cout<<"\nERROR!enter 1 or 0"<<endl;
         }
        while(strike!=1 && strike!=0);
       if(strike==1) isstrike=true;
       if(strike==0) isstrike=false;
    }
    if(toss_winner_choice==2)
    {
       random_isstrike = (rand()%3)+1;
       if(random_isstrike < 3 ) isstrike=true;
       if(random_isstrike==3) isstrike=false;
    }
    if(noball==true)
    {
            int random_choice_for_noball=0;
            random_choice_for_noball = (rand()%2)+1;
            if(random_choice_for_noball==1) score_to_add=4;
            if(random_choice_for_noball==2) score_to_add=6;
    }
    if(wide==true) score_to_add=4;
    if(bouncer==true) score_to_add=6;
    if (spin==true)
    {
            int random_choice_for_spin=0;
            random_choice_for_spin = (rand()%5)+1;
            if(random_choice_for_spin==1) score_to_add=0;
            if(random_choice_for_spin==2) score_to_add=1;
            if(random_choice_for_spin==3) score_to_add=2;
            if(random_choice_for_spin==4) score_to_add=4;
            if(random_choice_for_spin==5) score_to_add=6;
    }
     int random_out=0;
    if(isstrike==true)
    {
            random_out = (rand()%5)+1;
            if(random_out==3)
                game_over=true;
    }
    if(random_out==3|| isstrike==false) score_to_add=0;
    cout<<"\n new score to is::"<<score_to_add;
    if(game_over==true)
        {
            cout<<"\n\t\tOOOPS! OUT";
            cout<<"\n\t\tyou lose the game"<<endl;
            return 0;
        }
    else return score_to_add;
}
int bowling( int toss_winner_choice)
{
    const int const_distanceV=70;
    const int const_distanceH=80;
    const int const_height=60;
    int score=0;
    int entered_distanceV,entered_distanceH,entered_height,angle_of_deviation=0;
    int leftoverballs=6;
    if(toss_winner_choice==2 )
    cout<<"\n\t\tBOWLLING\nyou are here to ball carefully enter required information.\n";
    if(leftoverballs<=0) game_over=true;
    while(leftoverballs!=0 && game_over==false)
    {
        bool noball=false,wide=false,bouncer=false,spin=false;
        if(toss_winner_choice==2)
        {
            cout<<"\nenter vertical distance::";
            cin>>entered_distanceV;
            cout<<"\nenter horizontal distance::";
            cin>>entered_distanceH;
            cout<<"\nenter height::";
            cin>>entered_height;
            cout<<"\nenter angle of deviation::";
            cin>>angle_of_deviation;
        }
        if(toss_winner_choice==1)
        {
                 int choice_for_angle_of_deviation=0;
                 entered_distanceV= rand()%100;
                 entered_distanceH= rand()%100;
                 entered_height= rand()%2;
                 choice_for_angle_of_deviation= (rand()%2)+1;
                 if(choice_for_angle_of_deviation==1) angle_of_deviation=90;
                 if(choice_for_angle_of_deviation==2) angle_of_deviation=80;

        }
       if(const_distanceV<entered_distanceV)
       {
           noball=true;
           leftoverballs++;
       }
       if(const_distanceH<entered_distanceH)                       wide=true;
       if(const_height<entered_height)                                  bouncer=true;
       if(angle_of_deviation<85 || angle_of_deviation>95)   spin=true;
            leftoverballs--;
       score=batting( toss_winner_choice , noball , wide , bouncer , spin );
       if(game_over==false )
       final_score=final_score+score;
       cout<<"\ncurrent total score is::"<<final_score<<endl;
    }
    if(leftoverballs==0) game_over=true;
}

int main()
{
    int toss_winner_choice;
    toss_winner_choice=DessionOfToss();
    while(game_over==false)
        bowling(toss_winner_choice);
     cout<<"\n\nRESULT::\n\t\tGame over:: your FINAL SCORE is::   "<<final_score<<endl;
	return 0;
}
