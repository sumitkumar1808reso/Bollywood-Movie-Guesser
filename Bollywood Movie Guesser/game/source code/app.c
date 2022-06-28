#include<stdio.h>
#include<string.h>
#include"printer.h"
#include"randomiser.h"
#include"wordchanger.h"
#include"wordchecker.h"
#include"saver.h"
#define line printf("_ _ _ _ _ _ _ _ _\n");
#define bollywood printf("BOLLYWOOD v1.0\n\n\n");
#define cls system("cls");
void main()
{
	/*cmd pmt settings*/
	system("mode con: cols=39 lines=22");
	system("color f0");
	system("title ");
	
	
	
	FILE *fp;
	char ch,s[50],end[]="end";
	int j,score,highscore,n,chances,level=1,cost;
	
	/* menu is checkpoint to replay the game*/
	menu:
	cls
	bollywood
	
	fp=fopen("score.dat","r");
	fscanf(fp,"%d",&highscore);
	fclose(fp);
	printf("HIGH SCORE=%d\n",highscore);
	 
	printf("choose level:\n");
	line
	printf("\nEASY		e\nMEDIUM		m\nHARD		h\n");
	line
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("about		a");
	
	/*selection of files according to difficulty*/
	ch=getch();
	switch(ch)
	{
		case'e':
		fp=fopen("MOVIES EASY.dat","r"); n=2;
		break;
		case'm':
		fp=fopen("MOVIES MEDIUM.dat","r"); n=3;
		break;
		case'h':
		fp=fopen("MOVIES HARD.dat","r"); n=5;
		break;
		case'a':
		case'A':
			
		/* about section*/
		cls
		bollywood
		printf("1.Hi my name is Akshat Jaiswal.\n");
		printf("2.This game is written completely in C and developed via DevC++ IDE.\n");
		printf("3.Turn off CAPSLOCK before playing this game.\n");
		printf("4.Database of movies is sourced from\n  imdb.com\n  hindigeetmala.net\n  wikipedia.org\n");	
		printf("5.Stay safe, stay home.\n\n\n\n\n\n\n");
		printf("\n\nPress any key to return to main menu");
	
		getch();
		goto menu;
		
		default: 
		goto menu;
		
	}
	if(fp==NULL)
	{
	cls
	printf("files missing");
	}
	
	
	/* help screen */
	cls
	printf(" Here's how to play:\n\n");
	printf("1.A movie name will be given like this:\n     __O_A_\n\n");
	printf("2.You can guess letters you think are\nin the place of the blanks.\nfor ex if you click S, it will become\n     S_O_A_\n\n");
	printf("3.You have 9 letter guesses but if you\nguess wrong, the less you score.\n\n");
	printf("4.Keep guessing letters till you guess\nthe whole movie.\n      SHOLAY\n");
	printf("\n\n\n\n\nPress any key to start...");
	getch();
	

	game:
	/*game is checkpoint for next level*/
	/*movie selector*/
	chances=9;
	for(j=0;j<random();j++)
		{
			fgets(s,50,fp);
			if(strcmp(end,s)==0)
			{
			rewind(fp);	
			fgets(s,50,fp);
			}
		}
	for(j=0;s[j]!='(';j++)
		{
		if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u')
			{
			s[j]=s[j]-32;
			}
		}
		
		
		
	/*game screen*/	
	while(chances!=0&&checker(s)==1)
	{
	cls
	printf("LEVEL= %d\n",level);
	printf("Guess this movie:\n\n\n");
	print(&s[0]);
	printf("\n\n\n>>press any letter to guess it.\n  You have %d chances left.",chances);
	ch= getch();
	cost=changer(s,ch);
	chances=chances-cost;
	}
		
	/*lost screen*/
	cls
	if(chances==0){
	printf("\n\nOOPS! you lost on level %d\n",level);
	printf("\nThe movie was:");
	
	for(j=0;s[j]!='\0';j++)
	{
		if(s[j]>96&&s[j]<123)
		s[j]=s[j]-32;
		printf("%c",s[j]);
	}
	
	if(score>highscore)
	{
	printf("\nNEW HIGH SCORE\n");
	save(score);
	}
	printf("\nYour score is %d.",score);
	printf("\n\nWELL DONE you already have more\n filmy knowledge than me. lol.");
	printf("\n\n\n\n\n\n\n\n\n\n\nPress any key to return to main menu...");
	level=1;
	score=0;
	fclose(fp);
	getch();
	goto menu;
	}
	
	/*intermediate screen*/
	else
	{
	printf("\n\nYOU GUESSED IT RIGHT!!!!\nit was:");
	puts(s);
	printf("\nthere you go, next movie is coming up..\n\n");
	printf("\n\n\nPress any key to continue....");
	level=level+1;
	score=score+chances*n;
	getch();
	goto game;
	}
	
		
			
		
}
	

