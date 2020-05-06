#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<dir.h>
int main(){
	//clrscr();
	//Asking Permission
	char p;
	printf("Please Press Y to Continue\n\n");
	p = getch();
	if(p=='Y' || p == 'y'){
		//printf("Confirm");
		
		char x;
		FILE *fp;
		fp = fopen("help.txt","w");
		if(fp){
		fputs("Hello and Welcome to Merger V1.1\n\nHere are the Methods to Use this Apps\n\n1. You need to Choose Option/Menu 'a' then soon after Menu 'a' is executed, a directory\n\nnamed \"ffiles\" will be Created. \n\n2. Now you need to Copy your files to be merge in that directory and make Archive of them\n\nand Copy Photo in which you want to Merge and All done",fp);
		fclose(fp);
		}else{
		printf("Manual Cannot be Generated\n\n");	
		}
		printf("Please Read the Manual if you are new to App or Choose Help Menu\n\n");
		printf("a. Merge File in Image\tb.Help\n\n");
		x = getch();
		switch(x){
			case 'a':
				//
				mkdir("ffile");
				char img[100],file[100];
				FILE *p,*x;
				printf("Enter name of your Image name\n");
				gets(img);
				printf("Enter name of Archive File\n");
				gets(file);
				p = fopen("excute.bat","wb");
				if(p){
					fputs("@echo off\ncd ffile\ncopy /b \"",p);
					fputs(img,p);
					fputs("\" + ",p);
					fputs("\"",p);
					fputs(file,p);
					fputs("\"",p);
					fputs(" ",p);
					fputs("\"",p);
					fputs(img,p);
					fputs("\"",p);
					fputs("\n",p);
					fputs("copy",p);
					fputs(" ",p);
					fputs("\"",p);
					fputs(img,p);
					fputs("\"",p);
					fputs(" ",p);
					fputs("..",p);
					fclose(p);
					x = fopen("ffile\\close.bat","wb");
					fputs("cd ffile &&",p);
					fputs("del \"",x);
					fputs(img,x);
					fputs("\"",p);
					fputs("&&",x);
					fputs("del \"",x);
					fputs(file,x);
					fputs("\"",p);
					fputs("&&del close.bat",p);
					fclose(x);
					system("pause");
					system("excute.bat");
					remove("excute.bat");
					remove("help.txt");
					system("ffile\\close.bat");
					rmdir("ffile");
				}else{
					printf("Sorry, Temporary file Cannot be Created\n\n");
				}
				break;
			case 'b':
				break;
			default:
				printf("You Choose Invalid Options\n\n");
		}
		
		
		
		
		
		
	}else{
		return 0;
	}
}
