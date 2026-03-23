#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int snakes[101]={0};
int ladder[101]={0};
int player1 =0;
int player2 =0;
int rolldie(){
return rand()%6+1;
}
void printscorecard(){
	printf("--------------------- CURRENT SCORE ---------------------\n");
	printf("PLAYER 1 = %d\n",player1);
	printf("PLAYER 2 = %d\n",player2);

}
void printboard()
{
	for(int row=10;row>=1;row--)
{
	int start=(row-1)*10+1;
	int end = row*10;
	if(row%2==0)
	{
		for(int i=end;i>=start;i--)
		{

			if(i==player1)
				printf("%5s","#p1");
			else if(i==player2)
				printf("%5s","#p2");
			else 
				printf("%5d",i);
		}
		printf("\n");

	}
	else {
		for(int i=start;i<=end;i++)
		{
				if(i==player1)
				printf("%5s","#p1");
			else if(i==player2)
				printf("%5s","#p2");
			else 
				printf("%5d",i);
		}
		printf("\n");
	}
}
}	
	
int moveplayer(int currentplayer,int roll){
	int np= currentplayer +roll;
	if(np>100)
		return currentplayer;
	if(snakes[np]!=0)
	{
		printf("Snake ! Come down to %d\n",snakes[np]);
		np=snakes[np];
	}
	if(ladder[np]!=0)
	{
		printf(" Ladder! Go up to %d\n",ladder[np]);
		np=ladder[np];
	}
	return np;
}
void startgame()
{
    
	int currentplayer=1,won=0;
	while(!won){ 
	    int ch;
    printf("What you want to do?\n");
    printf("1.Roll die\n2.Print scorecard\n3.Print board\n4.Quit\n");
    scanf("%d",&ch);
    getchar();
    if(ch==1)
    {
        printf("Press enter to roll die...\n");
    	getchar();
    	int roll=rolldie();
	    printf("Rolled : %d\n",roll);
	    	
	if(currentplayer==1)
	{
		player1=moveplayer(player1,roll);
		  printf("Player 1 position: %d\n", player1);
		  
		 
		if(player1==100)
		{	
			printf("Player 1 wins!\n");
			 won = 1;
		}
		}else{
				player2=moveplayer(player2,roll);
				printf("Player 2 position: %d\n", player2);
				
				if(player2==100)
				{
					
					printf("Player 2 wins!\n");
					won=1;
				}
			}
		currentplayer = 3 - currentplayer;
    }
    else if(ch==2)
    {
        printscorecard();
    }
    else if(ch==3)
    {
        printboard();
    }
    else if(ch==4)
    {
        printf("Exiting program.......\n");
        break;
    }
    else 
    printf("Invalid input\n");
    

	}
}

	
int main()
{
	int choice;
	srand(time(0));
	snakes[1]=0;
	snakes[24]=6;
	snakes[54]=27;
	snakes[91]=73;
	snakes[85]=65;
	ladder[9]=28;
	ladder[18]=44;
	ladder[45]=55;
	ladder[50]=53;
	ladder[60]=64;
	ladder[87]=95;
	
	printf("=========================================================\n");
	printf("		  SNAKE AND LADDER IN C			 \n");
	printf("=========================================================\n");
	do{
		printf("-------------------------------------\n");
		printf("1.Start Game\n2.Print board \n3.Print scorecard\n4.Exit\n");
		printf("Enter your choice:\n");
		printf("-------------------------------------\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			startgame();
		}
		else if(choice==2)
		{
			printboard();
		}
		else if(choice==3)
		{
			printscorecard();
		}
		else if(choice==4)
		{
			printf("Returning to console......\n");
			break;
		}
		else
			printf("Invalid input\n");
	}while(choice!=4);
return 0;
}
		