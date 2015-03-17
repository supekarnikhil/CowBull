#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
char op;		// to scan the ascii code.
int opt;                // to convert the ascii code.
int i,j;
int cow,bull;		// to indicate number of Cows & Bulls
int flag=0;             // for counting the number of trials.
int x[4],y[4];		// Y[] for secrete number & X[] for user input.

int rndm();		// to generate the random number.
void choice();		// to select the choice from menu.
void skan();            // to scan the option from the user.
void search(int x[]);   // to compare the entered number with secrete number.
void howto();           // shows the help about How to Play the game.
void about();           // shows the information about us.

//---------------------------------------------------------

void main()
{
   clrscr();
   rndm();
   choice();
   getch();
}

// ---------------------------------------------------------

int rndm()
{
   int flag1;
   cow=0; bull=0;flag=0;
   randomize();			// a function call to genrate a randome digit.
   do
   {
      flag1=0;
//      printf("\n");		// to show the random number generated.
      for(j=0;j<4;j++)
      {
	 y[j]=rand() % 10;      // generates a random digit.
//	 printf("\t%d",y[j]);   // to show the random number generated.
      }

      for(i=0;i<4;i++)
      {
	 for(j=0;j<4;j++)
	 {
	    if(y[i]==y[j] && i!=j)
	    {
	       flag1=1;
	    }
	 }
      }
   }while(flag1!=0);
return 0;
}

//-----------------------------------------------------------

void choice()
{
   do
   {
      printf("\n\n\n\t\t\t  Cow-Bull 1.0\n");
      printf("\n\t\t\t--------------- \n\t\t\t");
      printf("  1. NEW \n\t\t\t");
      printf("  2. PLAY \n\t\t\t");
      printf("  3. HIGHSCORE \n\t\t\t");
      printf("  4. HOW TO PLAY \n\t\t\t");
      printf("  5. ABOUT \n\t\t\t");
      printf("  6. EXIT \n\t\t\t");
      printf("---------------\n\t\t\t:");
      scanf("%s",&op);
      opt=op-48;

      switch(opt)
      {
      case 1:		// New
	    main();
	    break;
      case 2:           // Play
	    clrscr();
	    skan();
	    break;
      case 3:		// HighScore
	    clrscr();
	    printf("\n\t\t Under construction! \n");
	    break;
      case 4:		// Help
	    clrscr();
	    howto();
	    break;
      case 5:		// About
	    clrscr();
	    about();
	    break;
      case 6:		// Exit
	    exit(0);
	    break;

      default :
	    clrscr();
	    printf("\n\t\t Please, enter correct option!\n");
	    break;

      }
   }while(opt!=6);
}

// ----------------------------------------------------------

void skan()
{  char c,z[4]={0};
   cow=0;bull=0;j=0;
   printf("\n\t\t Guess the 4 digits (eg.1234):\n\t\t\t\t");
   for(i=0;i<4;i++)
   {
      scanf("\n%c",&z[i]);
      c=z[i];
      switch(c)
      {
      case 'q':
      case 'Q':		// to exit from the game.
	 printf("\n\t\t Do you really want to quit? (Press 1 to Exit)\n\t\t\t");
	 scanf("%s",&op);
	 opt=op-48;     // to convert the ascii code.
	 if(opt==1)
	    main();
	 else
	    skan();
	 break;
      case 48:
      case 49:
      case 50:
      case 51:
      case 52:
      case 53:
      case 54:
      case 55:
      case 56:
      case 57:
	 x[i]=z[i]-48;
	 break;
      default:
	 j++;
	 break;
      }
   }
   if(j==0)
      search(x);
   else
      printf("\n\t Please, enter the digits between 0-9.\n");
      skan();
}

// ----------------------------------------------------------

void search(int x[4])
{
   int score=0;
   for(i=0;i<4;i++)
   {
      for(j=0;j<4;j++)
      {
	 if(x[i]==y[j])
	 {
	    if(i==j)
	    bull++;
	    else
	    cow++;
	 }
	 if(x[i]==x[j] && i!=j)
	 {
	    printf("\n\t Do not repeat the same digit.\n");
	    skan();
	 }
      }
  }
   if(bull==4)
   {
      score=1000/(flag+1);
      clrscr();
      printf("\n\n\n\t\t\t--------------------\n");
      printf("\n \t \t \t  Congratulation!\n");
      printf("\n \t \t \t      You Win!\n");
      printf("\n \t \t \t     Score: %d\n",score);
      printf("\n\t\t\t---------------------\n\n\n");
      rndm();
      choice();
   }
   else if(flag==9)
   {
      clrscr();
      printf("\n\t\t\t-----------------------\n\t\t\t");
      printf("\n\t\t\t      Score: 0\n\t\t\t");
      printf("\n\t\t\t     Game Over!\n\t\t\t");
      printf("\n\t\t\t Correct no. is %d%d%d%d \n\t\t\t",y[0],y[1],y[2],y[3]);
      printf("\n\t\t\t------------------------\n\t\t\t");
      rndm();
      choice();
   }
   else
   {
   flag++;
   printf("\n\t\t[%d]\t\t%d Bull, %d Cow\n\n",flag,bull,cow);
   skan();
   }
}

//------------------------------------------------------------------

void howto()
{
 printf("\n\n\n\t\t\tHow to Play COW-BULL\n\n");

 printf("\n\n\t -CowBull is a code-breaking game.");
 printf("\n\n\t -The computer will hold a 4-digit secret number.");
 printf("\n\n\t -All the digits will be different.");
 printf("\n\n\t -Then, the player has to guess that number,");
 printf("\n\n\t\t who gives the number of matches, within 10 chances.");
 printf("\n\n\t -If the matching digits are on their right positions, they are BULLs,");
 printf("\n\n\t\t if on different positions, they are COWs.");
 printf("\n\n\t -Example: \n\n\t\t Secret number:  4263 \n\n\t\t Opponent's try: 1234");
 printf("\n\n\t\t -Answer: 1 bull and 2 cows.\n\n\t\t -The bull is 2, the cows are 4 and 3.");
}

void about()
{
 printf("\n\n\n\t\t\t\tABOUT US\n\n");
 printf("\n\n\tThis game is designed & developed by Nikhil Supekar.\n\n");
}
