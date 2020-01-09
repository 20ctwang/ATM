// Chuting Wang loops.cpp : Defines the entry point for the console application.
// 
 
/*----------------------------Chuting Wang loops------------------------------------*/
/*   This program uses funcitons. In set-up section, users are prompted             */
/*   to set up their username and password which are limited to 4 digits only       */
/*   																				*/
/*   In ATM section, at first users are required to enter their passwords           */
/*   they set in the set-up section, and then the animation of 'PROCESSING...'      */
/*   would be printed to screen indicating that users got the passwords right.      */
/*   if they are not, then users might have to enter the passworeds again.          */
/*   After that, a main menu would guide users to determine if they want to         */
/*   deposit, withdraw moeny from the card or exit the card. When depositing        */
/*   moeny, users are prompted to enter the amount of money they want to deposit    */
/*   and then they need to determine if they want to continue to deposit or return  */
/*   to main menu. Therefore, users can determine to deposit money for however      */ 
/*   many times they want. Money withdrawing works the same way as money depositing.*/
/*   However, when users's balance do not have enough money to withdraw the amount  */
/*   of money users want, $0.00 would be withdrawn.                                 */
/*   If users exiting the card, users can determine to juxt exit the card    	    */   
/*   directly, print their recepit or return to the main menu to do more 			*/   
/*   transcations. 																	*/      
/*   																				*/     
/*                   PROGRAM ID:Chuting Wang loops    						        */ 
/*                   PROGRAMMER:Chuting Wang                     					*/
/*                   RUN DATE:September 12th, 2018               				    */ 
/*                                                   							    */
/*----------------------------------------------------------------------------------*/

/*---------PREPROCESSING DIRECTIVES---------*/

#include "stdafx.h"
#include <conio.h>
#include <stdio.h>
#include <windows.h>

/*-----------GOTOXY FUNCTION----------------*/

	void gotoxy(int x, int y)
	{
	  static HANDLE hStdout = NULL;
	  COORD coord;
	
	  coord.X = x;
	  coord.Y = y;
	
	  if(!hStdout)
	  {
	    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	  }
	  
	  SetConsoleCursorPosition(hStdout,coord);
	}

/*---------MAINLINE CONTROL-----------------*/

int main(void)
{

/*------------------TITLE-------------------*/
	
	system("TITLE Chuting Wang loops");

/*----------DECLARE LOCAL VARIABLES---------*/

	float deposit[30];		   	//the amount of deposited money each time
	float withdraw[30];	    	//the amount of withdrawn moeny each time
	float banked[60];           //balance
	float depositTotal[60];     //total deposited money in one case
	float withdrawTotal[60];    //total withdrawn money in one case	
	char  userName[30];         //username
	int   password[2][4];       //password
	int   unrealPassword[2][4]; //password before doing calculation

	//switch
	int   choice;  				//exit choice      	     
	int   choice1[60];			//main menu
	char  yesNo;				//continue or not

	//loops
	int   row=0;          		//for loop
	int   flag=0;				//do-while
	int   in=0;					//for loop - times deposit or withdraw run in once
	int   col=0;				//for-loop - frame
	int   run=1;  				//times user choose in main menu - for receipt
	
/*set text color*/

	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);   
	WORD wOldColorAttrs;                                                        
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;                     
	GetConsoleScreenBufferInfo(h, &csbiInfo);                     
	wOldColorAttrs = csbiInfo.wAttributes;
	
/*Introduction*/
	system ("color F0"); //background and foreground colour
	printf("\n\n\t\t\t================================================================");
	printf("\n\t\t\t|                                                              |");											
	printf("\n\t\t\t|                      THE BANK MACHINE                        |");		
	printf("\n\t\t\t|                       By: CHUTING WANG                       |");		
	printf("\n\t\t\t|                                                              |");		
	printf("\n\t\t\t================================================================\n\n"); 
	printf("\n\t\t\t                  Welcome to THE BANK MACHINE!\n\n");
	printf("\n\t\t\t              Remember to set up your account first!");
	printf("\n\t\t\t   Don't forget to print your receipt when exiting your card!\n\n");
	printf("\n\t\t\t                   Press <ENTER> and START!");
	getch();   //hold the screen
	system("cls");  //clear screen
	
/*set up*/
	system("color 0D");//background and foreground colour
	//set initial value 
	for(row=0;row<60;row++)
	{
		banked[row]=0;
		depositTotal[row]=0;
		withdrawTotal[row]=0;
		withdraw[row]=0;
		deposit[row]=0;
	}
	//set frame
	for(row=0;row<11;row++)
	{
		SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);  //foregrond color
		gotoxy(10,3);
		printf("SET UP"); //print title 
		gotoxy(9,4+row);
		printf("|"); //print frame	
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
	}
	gotoxy(10,5);
	printf("In order to activate your account");
	gotoxy(10,6);
	printf("please enter your username and password.");
	gotoxy(10,8);
	fflush(stdin); //clear keyboard buffer
	printf("USERNAME: "); //prompt user enter username
	scanf("%[^\n]",userName);	
	gotoxy(10,9);
	printf("PASSWORD(four digit): "); //prompt usre enter password 
	for(row=0;row<4;row++)
	{
		unrealPassword[1][row]=_getch(); //scan the place of number user enter on keyboard
		fflush(stdin); 
		//do calculation 
		password[1][row]=unrealPassword[1][row]-48; //calculate the value of number user enter
		printf("*"); //print password to screen 
	}
	getch(); //hold screen
	gotoxy(10,11);
	printf("Press <ENTER> to continue!");
	getch(); //hold screen
	system("cls"); //clear screen

	//set frame
	for(row=0;row<11;row++)
	{
		SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);  //foregrond color
		gotoxy(10,3);
		printf("SET UP");
		gotoxy(9,4+row);
		printf("|");	
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
	}
	gotoxy(10,5);
	printf("USERNAME: %s",userName);
	gotoxy(10,7);
	printf("We have noticed that you have not");
	gotoxy(10,9);
	printf("deposited any money into your card");
	gotoxy(10,11);
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY);  //foregrond color
	printf("So now your current balance is $0.00");
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
	gotoxy(10,13);
	printf("Press <ENTER> and let's get started!");	
	
	//animation of processing card 
	//set frame
	do
	{
		getch(); //hold the screen 
		system("cls"); //clear screen
		//set frame
		for(row=0;row<11;row++)
		{
			SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);  //foregrond color
			gotoxy(10,3);
			printf("ATM");
			gotoxy(9,4+row);
			printf("|");	
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
		}
		gotoxy(10,5);
		printf("A card is inserted.");
		gotoxy(10,7);
		printf("Following please enter your four-digit password and press <ENTER> to continue.");
		for(col=0;col<6;col++)
		{
			SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);  //foregrond color
			gotoxy(13+col,9);
			printf("-");
			gotoxy(13+col,11);
			printf("-");		
			gotoxy(12,10);
			printf("|");
			gotoxy(19,10);
			printf("|");
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
		}
		gotoxy(14,10);
		for(row=0;row<4;row++)
		{
			unrealPassword[2][row]=_getch(); //scan the place of number user enters on keyboard
			fflush(stdin); 
			//do calculation 
			password[2][row]=unrealPassword[2][row]-48; //calculate the value of number user enters
			printf("*"); //print password to screen 
		}
		getch(); //hold screen
		for(row=0;row<4;row++)
		{
			if(password[2][row]!=password[1][row])
			{
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY);  //foregrond color
				gotoxy(10,12);
				printf("WRONG PASSWORD!");
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
				gotoxy(10,13);
				printf("Press <ENTER> to try again!");	
				flag=1;	
			}
			else
			flag=2;
		}//end of for loop
	}while(flag<2);
	//animation
	//set frame
	system("cls");//clear screen
	for(row=0;row<11;row++)
	{
		SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);  //foregrond color
		gotoxy(10,3);
		printf("ATM");
		gotoxy(9,4+row);
		printf("|");	
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
	}
	for(row=0;row<5;row++)
	{
		gotoxy(10,9);
		printf("PROCESSING...");
		Sleep(100);
		gotoxy(10,9);
		printf("PROCESSING......");
		Sleep(100); 
		gotoxy(10,9);
		printf("PROCESSING.........");
		Sleep(100);					
	}		
	system("cls"); //clear screen
	
/*transaction*/			
	do
	{		
		//set frame
		for(row=0;row<11;row++)
		{
			SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);  //foregrond color
			gotoxy(10,3);
			printf("ATM");
			gotoxy(9,4+row);
			printf("|");	
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
		}
		//main menu
		gotoxy(10,5);		
		printf("Welcome!");
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY);  //foregrond color
		gotoxy(10,6);
		printf("Your Current Balance: $%.2f",banked[run]);
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
		gotoxy(10,8);
		printf("What can I do for you today?");
		gotoxy(10,10);
		printf("1] Deposit");
		gotoxy(10,11);
		printf("2] Withdraw");		
		gotoxy(10,12);
		printf("3] Exit");
		gotoxy(10,14);
		printf("Choice: ");
		scanf("%d",&choice1[run]);
		fflush(stdin); //clear keyboard buffer
		system("cls");//clear screen
		//set frame		
		for(row=0;row<11;row++)
		{
			SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);  //foregrond color
			gotoxy(10,3);
			printf("ATM");
			gotoxy(9,4+row);
			printf("|");	
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
		}

		run++; //determine times user deposit and withdraw
		switch(choice1[run-1])
		{		
		case 1:
			for(in=0;in<30;in++)
			{
				gotoxy(10,5);
				printf("Please insert money(enter the amount of deposit): $");
				scanf("%f",&deposit[in]);
				fflush(stdin);
				if(deposit[in] < 0)
				{
					SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);  //foregrond color
					gotoxy(10,7);
					printf("INVALID INPUT!");
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
					gotoxy(10,9);
					printf("Press <ENTER> to try again!");
					getch();
					//clear part of screen 
					gotoxy(10,5);
					printf("\t\t\t\t\t\t\t\t\t\t\t");
					gotoxy(10,7);
					printf("\t\t\t\t\t");
					gotoxy(10,9);
					printf("\t\t\t\t\t");
					in--;
				}
				else
				{
					//animation of processing 
					for(col=0;col<3;col++)
					{
						gotoxy(10,7);
						printf("PROCESSING...");
						Sleep(100);
						gotoxy(10,7);
						printf("PROCESSING......");
						Sleep(100); 
						gotoxy(10,7);
						printf("PROCESSING.........");
						Sleep(100);					
					}				
					//do calculation 
					depositTotal[run]=depositTotal[run]+deposit[in]; //total deposit amount
					banked[run]=banked[run-1]+depositTotal[run]; //current balance			
					gotoxy(10,7);
					printf("Great! $%.2f has been deposited into your account!",deposit[in]);
					gotoxy(10,9);
					printf("Your transcation has been completed.");
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY);  //foregrond color
					gotoxy(10,11);
					printf("Current Balance: $%.2f",banked[run]);
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
					gotoxy(10,13); 
					printf("Press <ENTER> to continue!");
					getch(); //hold screen 
					system("cls"); //clear screen 

					//set frame		
					for(row=0;row<11;row++)
					{
						SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);  //foregrond color
						gotoxy(10,3);
						printf("ATM");
						gotoxy(9,4+row);
						printf("|");	
						SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
					}
					do
					{
						gotoxy(10,5);
						printf("Continue to Deposit Money? Y/N: ");
						yesNo=_getch(); //prompt user determine if they want to deposit again
						fflush(stdin); //celar keyboard buffer
						switch(yesNo)
						{
						case 'y':
						case 'Y':
							flag=1;
							break;
						case 'n':
						case 'N':																			
							gotoxy(10,5);
							printf("Press <ENTER> to continue!          ");								
							getch(); //hold screen
							system("cls"); //clear screen
							flag=1;
							in=30;	 											
							break;
						default:						
							SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);  //foregrond color
							gotoxy(10,5);
							printf("INVALID INPUT!                                             ");
							SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
							gotoxy(10,7);
							printf("Press <ENTER> to try again!");
							getch(); //hold screen 
							gotoxy(10,5);
							printf("\t\t\t\t\t"); //clear line 7
							gotoxy(10,7);
							printf("\t\t\t\t\t"); //clear line 9
							flag=0;						
						}//end of switch
					}while(flag<1);
				}//end of else
			}//end of for loop								
			break;
			
		case 2:
			for(in=0;in<30;in++)
			{
				gotoxy(10,5);
				printf("Please enter the amount of money you want to withdraw: $");
				scanf("%f",&withdraw[in]);
				fflush(stdin);
				
				if(withdraw[in] >= 0)
				{
					//animation of processing 
					for(col=0;col<3;col++)
					{
						gotoxy(10,7);
						printf("PROCESSING...");
						Sleep(100);
						gotoxy(10,7);
						printf("PROCESSING......");
						Sleep(100); 
						gotoxy(10,7);
						printf("PROCESSING.........");
						Sleep(100);					
					}				
					//do calculation 
					withdrawTotal[run]=withdrawTotal[run]+withdraw[in]; //total withdraw amount
					banked[run]=banked[run-1]-withdrawTotal[run]; //current balance		
					if(banked[run]<0) //user cannot withdraw moeny if there is not enough money in their account
					{
						withdrawTotal[run]=withdrawTotal[run]-withdraw[in]; //money withdrawed failed
						banked[run]=banked[run-1]-withdrawTotal[run]; //re-calculate balance
						SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);  //foregrond color
						gotoxy(10,7);
						printf("You don't have enough money! $0.00 has been withdrawn!");
						gotoxy(10,9); 
						SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY);  //foregrond color
						printf("Current Balance: $%.2f",banked[run]);
						SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
						gotoxy(10,11);
						printf("Press <ENTER> to continue!");
					}
					else
					{
						gotoxy(10,7);
						printf("Great! You have withdrawed $%.2f!",withdraw[in]);
						gotoxy(10,9);
						printf("Your transcation has been completed.");
						SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY);  //foregrond color
						gotoxy(10,11);
						printf("Current Balance: $%.2f",banked[run]);
						SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
						gotoxy(10,13); 
						printf("Press <ENTER> to continue!");	
					}//end of else
												
					getch(); //hold screen 
					system("cls"); //clear screen 

					//set frame		
					for(row=0;row<11;row++)
					{
						SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);  //foregrond color
						gotoxy(10,3);
						printf("ATM");
						gotoxy(9,4+row);
						printf("|");	
						SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
					}
					do
					{
						gotoxy(10,5);
						printf("Continue to Withdraw Money? Y/N: ");
						yesNo=_getch(); //prompt user determine if they want to deposit again
						fflush(stdin); //celar keyboard buffer
						switch(yesNo)
						{
						case 'y':
						case 'Y':
							flag=1;
							break;
						case 'n':
						case 'N':																			
							gotoxy(10,5);
							printf("Press <ENTER> to continue!          ");								
							getch(); //hold screen
							system("cls"); //clear screen
							flag=1;
							in=30;	 											
							break;
						default:						
							SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);  //foregrond color
							gotoxy(10,5);
							printf("INVALID INPUT!                                             ");
							SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
							gotoxy(10,7);
							printf("Press <ENTER> to try again!");
							getch(); //hold screen 
							gotoxy(10,5);
							printf("\t\t\t\t\t"); //clear line 7
							gotoxy(10,7);
							printf("\t\t\t\t\t"); //clear line 9
							flag=0;						
						}//end of switch
					}while(flag<1);
				}//end of if
				else
				{
					SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);  //foregrond color
					gotoxy(10,7);
					printf("INVALID INPUT!");
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
					gotoxy(10,9);
					printf("Press <ENTER> to try again!");
					getch();
					//clear part of screen 
					gotoxy(10,5);
					printf("\t\t\t\t\t\t\t\t\t\t\t");
					gotoxy(10,7);
					printf("\t\t\t\t\t");
					gotoxy(10,9);
					printf("\t\t\t\t\t");
					in--;
				}
			}//end of for loop			
			break;
			
		case 3:
			do
			{			
				gotoxy(10,5);
				printf("Are you sure you want to exit your card?");
				gotoxy(10,7);
				printf("1] Yes, exit my card.");
				gotoxy(10,8);
				printf("2] Yes, and I also want to print my recepit.");
				gotoxy(10,9);
				printf("3] No, I need to do more transactions.");
				gotoxy(10,11);
				printf("Choice: ");
				scanf("%d",&choice);
				fflush(stdin); //clear keyboard buffer
				system("cls"); //clear screen
				
				switch(choice)
				{
					case 1:
						flag=3;					
						break;
						
					case 2:
						gotoxy(10,3);
						printf("Press <ENTER> to print your receipt and exit.");
						gotoxy(10,5);
						printf(" Balance ");
						gotoxy(20,5);
						printf("Description");
						for(row=1;row<run+1;row++)
						{
							gotoxy(10,7+row);
							if((choice1[row]==1)||(choice1[row]==2))
							printf(" $ %.2f",banked[row]);
							else if(choice1[row]==3)
							printf(" $ %.2f",banked[row]); //print final balance
							else
							printf(" ");
							gotoxy(22,8+row);
							if(choice1[row]==1)
							{							
								SetConsoleTextAttribute ( h, FOREGROUND_GREEN|FOREGROUND_INTENSITY);  //foregrond color
								printf(" + $ %.2f",depositTotal[row+1]); 
								SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
							}
							else if(choice1[row]==2)
							{							
								SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);  //foregrond color
								printf(" - $ %.2f",withdrawTotal[row+1]);
								SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
							}
							else 
							printf(" ");
						}//end of for loop
						getch(); //hold screen
						system("cls"); //clear screen
						flag=3;							
						break;
						
					case 3:
						flag=2;
						run--;
						break;
						
					default:
						SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);  //foregrond color
						gotoxy(10,12);
						printf("INVALID INPUT!");
						SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
						gotoxy(10,13);
						printf("Press <ENTER> to try again!");	
						flag=1;
						getch();
						//clear part of the screen
						gotoxy(10,11);
						printf("\t\t\t\t\t\t");
						gotoxy(10,12);
						printf("\t\t\t\t\t\t");	
						gotoxy(10,13);
						printf("\t\t\t\t\t\t");			
											
				}//end of switch
			}while(flag<2);
			break;				

		default:
			SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_INTENSITY);  //foregrond color
			gotoxy(10,5);
			printf("INALID NUMBER!");
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
			gotoxy(10,7);
			printf("Please press <ENTER> to try again!");
			flag=2;
			run--;
			getch(); //hold screen
			system("cls"); //clear screen
		}		
		system("cls"); //clear screen 		
	}while(flag<3);
	//set frame
	for(row=0;row<11;row++)
	{
		SetConsoleTextAttribute ( h, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);  //foregrond color
		gotoxy(10,3);
		printf("ATM");
		gotoxy(9,4+row);
		printf("|");	
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_BLUE|FOREGROUND_INTENSITY );
	}
	
	gotoxy(10,5);
	printf("Please press <ENTER> to exit.");

	getch(); //hold screen
	return 0;
} //end main 
