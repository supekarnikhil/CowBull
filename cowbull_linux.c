#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define easy 3
#define normal 4
#define hard 5

// uncomment following in windows.
//#include<conio.h>

int cheat=0;
int level=4;
int cow,bull;			// to indicate number of Cows & Bulls
int steps=0;		// for counting the number of trials.
int user[hard],comp[hard];	// comp[] for secret number & user[] for user input.

int rndm();		// generates the random number.
void menu();			// generates the menu.
void check(int user[]);// compares the entered number with secret number.
void writescore(int score);	// creates highscore file.

void play();		// takes the number from user.
void highscore();		//shows highscore saved by player.
void howto();		// shows the instructions about How to Play the game.
void settings();		// changes the settings of the game.
void about();		// shows the information about us.

//-----------------------------MAIN-------------------------------------

void main()
{
// uncomment following in windows.
//clrscr();

	clear_screen();

	menu();

// uncomment following in windows.
//getch();
}

//-----------------------------Clear Screen-------------------------------------

void clear_screen()
{
	system ("clear");
}

// ---------------------RANDOM NUMBER-----------------------------------

int rndm()
{
   int i,j;
   int flag;
// uncomment following in windows.
//   randomize();	// function call to genrate a randome digit.
   do
   {
      flag=0;
//uncomment following to see the secret number.
//      printf("\n");
      for(j=0;j<level;j++)
      {
	 comp[j]=rand() % 10;      // generates a random digit.
//uncomment following to see the secret number.
//	 printf("\t%d",comp[j]);
      }

      for(i=0;i<level;i++)
      {
	 for(j=0;j<level;j++)
	 {
	    if(comp[i]==comp[j] && i!=j)// generates random number with no
	       flag=1;			// repeatation of digits.
	 }
      }
   }while(flag!=0);
return 0;
}

//--------------------------MENU---------------------------------

void menu()
{
	char ch;
	int opt;
	cow=0; bull=0;steps=0;
	rndm();			//call to the random number generator function.

   do
   {
      printf("\n\n\n\t\t\t  Cow-Bull 1.0\n");
      printf("\n\t\t\t *************** \n\t\t\t");
      printf("  1. PLAY \n\t\t\t");
      printf("  2. HIGHSCORE \n\t\t\t");
      printf("  3. HOW TO PLAY \n\t\t\t");
      printf("  4. SETTINGS \n\t\t\t");
      printf("  5. ABOUT \n\t\t\t");
      printf("  6. EXIT \n\t\t\t");
      printf(" *************** \n\t\t\t:");
      scanf("%s",&ch);
      opt=atoi(&ch);
      switch(opt)
      {
      case 1:      		// Play
	    play();
	    break;
      case 2:			// HighScore
	    highscore();
	    break;
      case 3:			// Help
	    howto();
	    break;
      case 4:			// Settings
	    settings();
	    break;
      case 5:			// About
	    about();
	    break;
      case 6:			// Exit
	    exit(0);
	    break;
      default :
	    printf("\n\t\t\t------------------------------");
	    printf("\n\t\t\t Please, enter correct option!");
	    printf("\n\t\t\t------------------------------");
	main();
	    break;
      }
   }while(opt!=6);
}

// ------------------------PLAY----------------------------------

void play()
{
  int i=0;
  char ch;
  cow=0; bull=0;

   printf("\n\t\t Guess the %d digits : ",level);
   while(i<level)
   {
      scanf("\n%c",&ch);
      switch(ch)
	{
	case 'q':
	case 'Q':			// to return to the main menu.
		 printf("\n\t\t Do you really want to quit? (Y/N) : ");
		 scanf("%s",&ch);
		 	if(ch=='y' || ch=='Y')
		 	   main();
		 	else
		 	   play();
		break;
	case 's':
	case 'S':			// cheat: for unlimited steps.
		if(cheat==1)
		{
			printf("\n\t\t-----------------------------------------------------------");
			printf("\n\t\t\t Cheat activated : Unlimited Steps.\n");
			printf("\n\t\t Note : While playing if you want to quit enter 'q' or 'Q'.");
			printf("\n\t\t-----------------------------------------------------------");
			steps=11;
		}
		else
			{
			printf("\n\t\t\t--------------------------------------");
			printf("\n\t\t\t Please, enter the digits between 0-9.");
			printf("\n\t\t\t--------------------------------------");
			}
		play();
		break;
	case 'c':
	case 'C':			// cheat: to show the secret number.
		if(cheat==1)
		{
			printf("\n\t\t\t-----------------------------");
			printf("\n\t\t\t The secret number is : ");
			for(i=0;i<level;i++)
				printf("%d",comp[i]);
			printf("\n\t\t\t-----------------------------");
		}
		else
			{
			printf("\n\t\t\t--------------------------------------");
			printf("\n\t\t\t Please, enter the digits between 0-9.");
			printf("\n\t\t\t--------------------------------------");
			}
		play();
		break;
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		user[i] = atoi(&ch);	// convert ASCII number to interger.
		i++;
		break;
      default:
		printf("\n\t\t\t--------------------------------------");
		printf("\n\t\t\t Please, enter the digits between 0-9.");
		printf("\n\t\t\t--------------------------------------");
	        play();
		break;
   }
 }check(user);
}

// -------------------------check---------------------------------

void check(int user[level])
{
   char ch;
   int i,j;
   int score=0;
   cow=0;bull=0;

   for(i=0;i<level;i++)
   {
      for(j=0;j<level;j++)
      {
	 if(user[i]==user[j] && i!=j)	// checking whether the same digits are entered.
	 {
	    printf("\n\t\t\t---------------------------");
	    printf("\n\t\t\t Do not repeat same digits.");
	    printf("\n\t\t\t---------------------------");
	    play();
	 }
	 else if(user[i]==comp[j])	// comparing with the secret number.
	 {
	    if(i==j)
	    bull++;
	    else
	    cow++;
	 }
      }
  }

   steps++;				// after each step
   printf("\n\t\t[%d] ",steps);
   for(i=0;i<level;i++)
   printf("%d",user[i]);
   printf("\t %d Bull, %d Cow\n",bull,cow);

   if(bull==level)			// if wins
   {
      score=(100*level)/(steps+1);	// calculation of score.
      
      printf("\n\n\n\t\t\t--------------------\n");
      printf("\n\t\t\t  Congratulation!\n");
      printf("\n\t\t\t      You Win!\n");
      printf("\n\t\t\t     Score: %d\n",score);
      printf("\n\t\t\t---------------------\n\n\n");
      printf("\n\t\t\t Do you want to save your score? (Y/N) : ");
      scanf("%s",&ch);
	if(ch=='y' || ch=='Y')
	  writescore(score);
      menu();
   }
  else if(steps==10)			// if loses
     {
      printf("\n\t\t\t-----------------------\n");
      printf("\n\t\t\t      Score: 0\n\t\t\t");
      printf("\n\t\t\t     Game Over!\n\t\t\t");
      printf("\n\t\t\t Correct no. was ");
	for(i=0;i<level;i++)
		printf("%d",comp[i]);
      printf("\n\n\t\t\t------------------------\n");
  printf("\n\t\t Press any key to go back to return : ");
  fflush(stdin);
  getchar();
  menu();
   }
  else
    play();
}

//-------------------------WRITE HIGHSCORE------------------------------

void writescore(int score)
{
  FILE *fp;
  char name[10];

  fp=fopen("highscore.dat","a");		// creates a highscore.dat file in 'append' mode.
if(fp==NULL)
 {
   printf("\n\t\t\t-------------------------------------");
   printf("\n\t\t\tError : cannot create highscore file.");
   printf("\n\t\t\t-------------------------------------");
 }
else
 {
  printf("\n\tEnter your name :\t");
  scanf("%s",name);
  fprintf(fp,"%s %d %d\n",name,score,level);
  fclose(fp);
 }
}

//---------------------------READ HIGHSCORE-----------------------------

void highscore()
{
  FILE *fp;
  int score;
  char name[10];
  fp=fopen("highscore.dat","r");
   if(fp==NULL)
 {
	printf("\n\t\t\t-------------------------------");
	printf("\n\t\t\t Highscore is not recorded yet.");
	printf("\n\t\t\t-------------------------------");
 }
else
 {
   printf("\n\t\t\t Highscore \n");
   printf("\t\t\t======================== \n");
   printf("\n\t\t\tName \t Score \t Level \n");
   printf("\t\t\t________________________ \n");
   while(fscanf(fp,"%s %d %d",name,&score,&level)!=EOF)
   printf("\t\t\t%s \t %d \t %d \n",name,score,level);
   fclose(fp);
 }
}

//----------------------------SETTINGS----------------------------------

void settings()
{
  char ch;
  int opt;
  char key[20];
do
 {
      printf("\n\n\n\t\t\t SETTINGS \n");
      printf("\n\t\t\t ******************** \n\t\t\t");
      printf("  1. LEVEL \n\t\t\t");
      printf("  2. RESET HIGHSCORE \n\t\t\t");
      printf("  3. Cheat Setting \n\t\t\t");
      printf("  4. BACK \n\t\t\t");
      printf(" ******************** \n\t\t\t:");
      scanf("%s",&ch);
      opt=atoi(&ch);
  switch(opt)
   {
   case 1:					// levels
      printf("\n\n\n\t\t\t  LEVELS \n");
      printf("\n\t\t\t ******************** \n\t\t\t");
      printf("  1. EASY (3-digit) \n\t\t\t");
      printf("  2. NORMAL (4-digit) \n\t\t\t");
      printf("  3. HARD (5-digit) \n\t\t\t");
      printf(" ******************** \n\t\t\t:");
      scanf("%s",&ch);
      opt=atoi(&ch);
	  switch(opt)
	   {
	   case 1:
      		level = easy;		// easy = 3-digits
		break;
	   case 2:
      		level = normal;		// normal = 4-digits
		break;
	   case 3:
      		level = hard;		// hard = 5-digits
		break;
	   default:
		printf("\n\t\t\t---------------------------------");
		printf("\n\t\t\t Enter your choice beween 1 to 3.");
		printf("\n\t\t\t---------------------------------\n");
		break;
	   }
	opt=1;
		printf("\n\n\t\t\t----------------------------");
		printf("\n\t\t\t Difficulty level : %d-digit",level);
		printf("\n\t\t\t----------------------------");
	break;

   case 2:					// delete highscore
     remove("highscore.dat");
	printf("\n\t\t\t--------------------");
	printf("\n\t\t\t Highscore is reset.");
	printf("\n\t\t\t--------------------");
	break;

   case 3:					// Cheat setting
	     if(cheat==0)
	     {
	     	printf("\n\t\t Enter key to activate cheat : ");
	     	scanf("%s",key);
	     	if(strcmp(key,"nikhil.supekar")==0)
		{
	     	cheat=1;
			printf("\n\t\t--------------------------------------------------\n");
			printf("\n\t\t Cheats are activated succesfully.\n");
			printf("\n\t\t Enter following cheats when you start the game.\n");
			printf("\n\t\t cheats:\n\t\t\t 'c' - to show the secret number.\n");
			printf("\n\t\t\t 's' - to activate unlimited steps.\n");
			printf("\n\t\t----------------------------------------------------");
		}
		else
		{
			printf("\n\t\t\t-----------");
			printf("\n\t\t\t Wrong Key!");
			printf("\n\t\t\t-----------");
		}
	     }
	     else
	     {
		cheat=0;
		printf("\n\t\t\t------------------------------------");
		printf("\n\t\t\t Cheats are deactivated succesfully.");
		printf("\n\t\t\t------------------------------------");
	     }
	break;

   case 4:					// go back to main menu
     main();
	break;
   default:
	printf("\n\t\t\t---------------------------------");
	printf("\n\t\t\t Enter your choice beween 1 to 3.");
	printf("\n\t\t\t---------------------------------");
	break;
   }
 }while(opt!=4);
}

//---------------------------HOW TO PLAY--------------------------------

void howto()
{
 printf("\n\n\n\t\t\tHow to Play COW-BULL\n");
 printf("\t\t================================ \n\n");
 printf("\n\n\t -Cow-Bull is a code-breaking game.");
 printf("\n\n\t -The computer will hold a secret number.");
 printf("\n\n\t -All the digits in the number will be different.");
 printf("\n\n\t -You have to guess the secret number, who gives the number of matches,");
 printf("\n\n\t\t within 10 chances.");
 printf("\n\n\t -If the matching digits are on their exact positions, they are BULLs,");
 printf("\n\n\t\t  and if on different positions, they are COWs.");
 printf("\n\n\t -Example for 4-digits: \n\n\t\t Secret number:  4263 \n\n\t\t Opponent's try: 1234");
 printf("\n\n\t\t -Answer: 1 bull and 2 cows.\n\n\t\t -The bull is '2' and the cows are '4' & '3'.");
 printf("\n\n\t Note : You can  quit the game any time by entering 'Q' or 'q'.");
}

//-----------------------------ABOUT US---------------------------------

void about()
{
 printf("\n\n\n\t\t\t\tABOUT US\n");
 printf("\t\t\t====================== \n\n");
 printf("\n\n\t\tThe Cow-Bull game is designed by Nikhil Supekar.\n\n");
}
