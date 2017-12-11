/*Minesweeper V2.0
Written by:-Shivam Shekhar
*/
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
    COORD pos;
    DWORD info;
    HANDLE in;
    HANDLE out;
    CONSOLE_SCREEN_BUFFER_INFO scrinfo;
    INPUT_RECORD input;
    in=GetStdHandle(STD_INPUT_HANDLE);
    out=GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(out,&scrinfo);
    SetConsoleMode(in,ENABLE_PROCESSED_INPUT);
    CHAR_INFO scrbuff1[144],scrbuff2[144],scrbuff3[4];;
    SMALL_RECT rect1={5,5,17,17};
    SMALL_RECT rect2={50,5,54,5};
    COORD gridsz={12,12};
    COORD gridsz1={4,1};
    COORD zerozero={0,0};
    COORD pos1={30,9};
    int i,j,mine=0,k,l,nom=0,nofm=0,begin=0;
    COORD xsys;
    system("color 4F");
    for(;;)
    {
        system("cls");
        SetConsoleCursorPosition(out,pos1);
        printf("1. Play Minesweeper");
        pos1.Y++;
        SetConsoleCursorPosition(out,pos1);
        printf("2. Rules");
        switch(getch())
        {
            case 49:
                begin=1;
                break;
            case 50:
                system("cls");
                printf("Minesweeper v2.0\n1. Your aim is to successfully flag all the mines without opening any mines\n2. Use your mouse to open the squares. Left click on a square to open it\n3. On the top left of your screen, there's a flag button. Click on 'F' to pick up a flag. Once you pick a flag, the button turns red and if you place/drop the flag, the button turns white.\n4. once you pick up a flag, you can place it on a square by left clicking on the square.\n5. To remove a flag from the square, simply left click on the flagged square.\n6. if you open a mine, you lose\n");
                printf("7.If you open a square with a number written on it. The number shows that how many mines are there in the adjacent 8 squares\n");
                printf("For eg:\n%c %c %c\n\n%c 4 %c\n\n%c %c %c",219,219,219,219,219,219,219,219);
                printf("\nHere 4 denoted that there are 4 mines in the remaining uncovered squares");
                printf("\n\n\n");
                system("pause");
                pos1.Y--;
                continue;
        }
        pos1.Y--;
        if(begin==1)
            break;
    }
    system("cls");
    system("color 07");
    FlushConsoleInputBuffer(in);
    scrbuff3[0].Char.AsciiChar='F';
    scrbuff3[1].Char.AsciiChar=':';
    scrbuff3[2].Char.AsciiChar=' ';
    scrbuff3[3].Char.AsciiChar=9+48;
    for(i=0;i<4;i++)
    {
        scrbuff3[i].Attributes=FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE|BACKGROUND_INTENSITY;
    }
    //Initialize my minefield
    for(j=0;j<gridsz.Y;j++)
    {
        if(j%2==0)
        {
            for(i=0;i<gridsz.X;i++)
            {
                if(i%2==0)
                {
                    scrbuff1[i+j*12].Char.AsciiChar=219;
                    scrbuff1[i+j*12].Attributes=FOREGROUND_GREEN|FOREGROUND_INTENSITY;
                   /* if(rand()%2==1)
                    {scrbuff2[i+j*12].Char.AsciiChar=15;}
                    else
                    {scrbuff2[i+j*12].Char.AsciiChar=j+1;}
                    scrbuff2[i+j*12].Attributes=FOREGROUND_RED|FOREGROUND_INTENSITY;*/
                }
                else
                {
                    scrbuff1[i+j*12].Char.AsciiChar=' ';
                    scrbuff1[i+j*12].Attributes=01;
                    scrbuff2[i+j*12].Char.AsciiChar=' ';
                    scrbuff2[i+j*12].Attributes=01;
                }
            }
        }
        else
        {
            for(i=0;i<gridsz.X;i++)
            {
                scrbuff1[i+j*12].Char.AsciiChar=' ';
                scrbuff1[i+j*12].Attributes=01;
                 scrbuff2[i+j*12].Char.AsciiChar=' ';
                scrbuff2[i+j*12].Attributes=01;

            }
        }
    }
    WriteConsoleOutput(out,scrbuff1,gridsz,zerozero,&rect1);
    //taking user input for 1st square
    while(1)
    {SetConsoleMode(in,ENABLE_MOUSE_INPUT);
    ReadConsoleInput(in,&input,1,&info);
    if(input.EventType==MOUSE_EVENT)
    {
        if(input.Event.MouseEvent.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED && input.Event.MouseEvent.dwMousePosition.X >4 && input.Event.MouseEvent.dwMousePosition.X <18 && input.Event.MouseEvent.dwMousePosition.Y >4 && input.Event.MouseEvent.dwMousePosition.Y <18 && (input.Event.MouseEvent.dwMousePosition.X - 5)%2 ==0 && (input.Event.MouseEvent.dwMousePosition.Y - 5)%2==0 && scrbuff1[input.Event.MouseEvent.dwMousePosition.X - 5  + 12*(input.Event.MouseEvent.dwMousePosition.Y - 5)].Char.AsciiChar==-37)
        {
            xsys.X = input.Event.MouseEvent.dwMousePosition.X - 5;
            xsys.Y = input.Event.MouseEvent.dwMousePosition.Y - 5;
            break;
        }
    }
    }
    //printf("%d %d",xsys.X,xsys.Y);
    //random placing of mines
    srand(time(NULL));
    for(;;)
    {
        i=rand()%gridsz.X;
        j=rand()%gridsz.Y;
        if(j%2==0)
        {
           if(i%2==0 &&  scrbuff2[i+j*12].Char.AsciiChar!=15 && (i+ 12*j)!=(xsys.X + xsys.Y*12))
           {
               scrbuff2[i+j*12].Char.AsciiChar=15;
               scrbuff2[i+j*12].Attributes=FOREGROUND_RED|FOREGROUND_INTENSITY;
               mine++;
           }
        }
        if(mine==9)
            break;
    }
    scrbuff2[10+4*12].Char.AsciiChar=1;
    for(j=0;j<gridsz.Y;j++)
    {
        if(j%2==0)
        {
            for(i=0;i<gridsz.X;i++)
            {
                if(i%2==0 && scrbuff2[i+j*12].Char.AsciiChar!=15)
                {
                    for(k=j-2;k<=j+2;k+=2)
                    {
                        for(l=i-2;l<=i+2;l+=2)
                        {
                            if(scrbuff2[l+k*12].Char.AsciiChar==15 && 0<=l && 0<=k && l<12 && k<12)
                            {
                                nom++;
                            }
                        }
                    }
                    scrbuff2[i+j*12].Char.AsciiChar=nom+48;
                    scrbuff2[i+j*12].Attributes=FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED | BACKGROUND_INTENSITY;
                    nom=0;
                }
            }
        }
    }
    for(k=2;k<=6;k+=2)
    {
        for(l=8;l<=10;l+=2)
        {
            if(scrbuff2[l+k*12].Char.AsciiChar==15 && l+k*12 != 10+4*12)
                nom++;
        }
    }
    scrbuff2[10 + 4*12].Char.AsciiChar=nom+48;
    scrbuff2[10+4*12].Attributes=FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED | BACKGROUND_INTENSITY;
    //setting squares around mines
    for(k=xsys.Y-2;k<=xsys.Y+2;k+=2)
    {
        for(l=xsys.X-2;l<=xsys.X+2;l+=2)
        {
            if(0<=l && 0<=k && l<12 && k<12 && scrbuff2[l+k*12].Char.AsciiChar!=15)
            {
                scrbuff1[l+k*12].Char.AsciiChar=scrbuff2[l+k*12].Char.AsciiChar;
                scrbuff1[l+k*12].Attributes=FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY;
            }
        }
    }
    //writing this to console
    WriteConsoleOutput(out,scrbuff1,gridsz,zerozero,&rect1);
    rect1.Left+=15;
    rect1.Right+=15;
    //WriteConsoleOutput(out,scrbuff2,gridsz,zerozero,&rect1);
    rect1.Left-=15;
    rect1.Right-=15;
    WriteConsoleOutput(out,scrbuff3,gridsz1,zerozero,&rect2);
    //finally the game begins
    while(1)
     {
         SetConsoleMode(in,ENABLE_MOUSE_INPUT);
         ReadConsoleInput(in,&input,1,&info);
         if(input.EventType==MOUSE_EVENT)
         {
            if(input.Event.MouseEvent.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED)
            {
                if(scrbuff1[input.Event.MouseEvent.dwMousePosition.X - 5 + (input.Event.MouseEvent.dwMousePosition.Y - 5)*12].Char.AsciiChar==-37 && input.Event.MouseEvent.dwMousePosition.X >4 && input.Event.MouseEvent.dwMousePosition.X <18 && input.Event.MouseEvent.dwMousePosition.Y >4 && input.Event.MouseEvent.dwMousePosition.Y <18 && (input.Event.MouseEvent.dwMousePosition.X - 5)%2 ==0 && (input.Event.MouseEvent.dwMousePosition.Y - 5)%2==0)
                {
                    scrbuff1[input.Event.MouseEvent.dwMousePosition.X - 5 + (input.Event.MouseEvent.dwMousePosition.Y-5)*12].Char.AsciiChar=scrbuff2[input.Event.MouseEvent.dwMousePosition.X - 5 + (input.Event.MouseEvent.dwMousePosition.Y-5)*12].Char.AsciiChar;
                    if(scrbuff1[input.Event.MouseEvent.dwMousePosition.X - 5 + (input.Event.MouseEvent.dwMousePosition.Y-5)*12].Char.AsciiChar!=15)
                    {
                        scrbuff1[input.Event.MouseEvent.dwMousePosition.X-5 + (input.Event.MouseEvent.dwMousePosition.Y-5)*12].Attributes=FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY;
                    }
                    else
                    {
                        scrbuff1[input.Event.MouseEvent.dwMousePosition.X-5 + (input.Event.MouseEvent.dwMousePosition.Y-5)*12].Attributes=FOREGROUND_RED|FOREGROUND_INTENSITY;
                    }
                }
                if(scrbuff1[input.Event.MouseEvent.dwMousePosition.X - 5 + (input.Event.MouseEvent.dwMousePosition.Y-5)*12].Char.AsciiChar=='F')
                {
                    scrbuff3[3].Char.AsciiChar++;
                    scrbuff1[input.Event.MouseEvent.dwMousePosition.X - 5 + (input.Event.MouseEvent.dwMousePosition.Y-5)*12].Char.AsciiChar=-37;
                    scrbuff1[input.Event.MouseEvent.dwMousePosition.X - 5 + (input.Event.MouseEvent.dwMousePosition.Y-5)*12].Attributes=FOREGROUND_GREEN|FOREGROUND_INTENSITY;
                }
                if(input.Event.MouseEvent.dwMousePosition.X==50 && input.Event.MouseEvent.dwMousePosition.Y==5 && scrbuff3[3].Char.AsciiChar>48)
                {
                    scrbuff3[3].Char.AsciiChar--;
                    scrbuff3[0].Attributes=BACKGROUND_RED|BACKGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_INTENSITY;
                     WriteConsoleOutput(out,scrbuff3,gridsz1,zerozero,&rect2);
                     while(1)
                    {
                        SetConsoleMode(in,ENABLE_MOUSE_INPUT);
                        ReadConsoleInput(in,&input,1,&info);
                        if(input.EventType==MOUSE_EVENT)
                        {
                            if(input.Event.MouseEvent.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED)
                            {
                                if(scrbuff1[input.Event.MouseEvent.dwMousePosition.X - 5 + (input.Event.MouseEvent.dwMousePosition.Y-5)*12].Char.AsciiChar==-37)
                                {scrbuff1[input.Event.MouseEvent.dwMousePosition.X - 5 + (input.Event.MouseEvent.dwMousePosition.Y-5)*12].Char.AsciiChar='F';
                                scrbuff1[input.Event.MouseEvent.dwMousePosition.X - 5 + (input.Event.MouseEvent.dwMousePosition.Y-5)*12].Attributes=BACKGROUND_GREEN|BACKGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_INTENSITY;
                                break;}
                                else
                                    {scrbuff3[3].Char.AsciiChar++;
                                    scrbuff3[0].Attributes=BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_INTENSITY;
                                    break;}

                            }
                        }
                    }
                }
                scrbuff3[0].Attributes=BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE|BACKGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_INTENSITY;
                WriteConsoleOutput(out,scrbuff1,gridsz,zerozero,&rect1);
                WriteConsoleOutput(out,scrbuff3,gridsz1,zerozero,&rect2);
                for(k=0;k<gridsz.Y;k++)
                {
                    for(l=0;l<gridsz.X;l++)
                    {
                        if(scrbuff1[l+12*k].Char.AsciiChar=='F' && scrbuff2[l+12*k].Char.AsciiChar==15)
                            nofm++;
                    }
                }
                if(nofm==9)
                {
                    printf("You win!");
                    break;
                }
                nofm=0;
                if(scrbuff1[input.Event.MouseEvent.dwMousePosition.X - 5 + (input.Event.MouseEvent.dwMousePosition.Y-5)*12].Char.AsciiChar==15)
                {
                    printf("game over");
                    break;
                }
            }
        }
     }
     return 0;
}