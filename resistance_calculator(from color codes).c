/*
Made by: Shivam Shekhar
*/
#include "alphabet.h"
void printcol(void);
long long int power(int,int);
void title(void);
int main()
{
    HANDLE in,out;
    DWORD info;
    CONSOLE_SCREEN_BUFFER_INFO scrinfo;
    INPUT_RECORD input;
    char _resistormap[3][15]={"   AXXXXXXB   ",
                              "XXXY      YXXX",
                              "   CXXXXXXD   "};
    char sign[28]="Written by: Shivam Shekhar";
    int i,j,k=0,lines[4]={0,0,0,20},linesindex[4]={19,20,21,22};
    long long int resistance;
    SMALL_RECT resistorrect={33,14,47,17};
    CHAR_INFO _resistor[42];
    COORD resistorsz={14,3},zerozero={0,0},anspos={30,18},signpos={50,23};
    //
    SetConsoleTitle("Resistance Calculator");
    title();
    system("cls");
    in=GetStdHandle(STD_INPUT_HANDLE);
    out=GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(out,&scrinfo);
    SetConsoleCursorPosition(out,signpos);
    puts(sign);
    for(i=0;i<3;i++)
    {
        for(j=0;j<14;j++)
        {
            if(_resistormap[i][j]=='X')
            {
                _resistor[j+14*i].Char.AsciiChar=205;
                _resistor[j+14*i].Attributes=7;
            }
            else if(_resistormap[i][j]=='Y')
            {
                _resistor[j+14*i].Char.AsciiChar=186;
                _resistor[j+14*i].Attributes=7;
            }
            else if(_resistormap[i][j]=='A')
            {
                _resistor[j+14*i].Char.AsciiChar=201;
                _resistor[j+14*i].Attributes=7;
            }
            else if(_resistormap[i][j]=='B')
            {
                _resistor[j+14*i].Char.AsciiChar=187;
                _resistor[j+14*i].Attributes=7;
            }
            else if(_resistormap[i][j]=='C')
            {
                _resistor[j+14*i].Char.AsciiChar=200;
                _resistor[j+14*i].Attributes=7;
            }
            else if(_resistormap[i][j]=='D')
            {
                _resistor[j+14*i].Char.AsciiChar=188;
                _resistor[j+14*i].Attributes=7;
            }
            else
            {
                _resistor[j+14*i].Char.AsciiChar=' ';
                _resistor[j+14*i].Attributes=7;
            }
        }
    }
    WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
    printcol();
    while(1)
    {
        SetConsoleMode(in,ENABLE_MOUSE_INPUT);
        ReadConsoleInput(in,&input,1,&info);
        if(input.EventType==MOUSE_EVENT)
        {
            if(input.Event.MouseEvent.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED)
            {
                if(input.Event.MouseEvent.dwMousePosition.Y==6)
                {
                    //black
                    if(input.Event.MouseEvent.dwMousePosition.X<19 && input.Event.MouseEvent.dwMousePosition.X>13)
                    {
                        _resistor[linesindex[0]].Char.AsciiChar=221;
                        _resistor[linesindex[0]].Attributes=7;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[0]=0;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                        ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                    //brown
                    if(input.Event.MouseEvent.dwMousePosition.X<25 && input.Event.MouseEvent.dwMousePosition.X>19)
                    {
                        _resistor[linesindex[0]].Char.AsciiChar=221;
                        _resistor[linesindex[0]].Attributes=6;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[0]=1;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                        ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                    //red
                    if(input.Event.MouseEvent.dwMousePosition.X<29 && input.Event.MouseEvent.dwMousePosition.X>25)
                    {
                        _resistor[linesindex[0]].Char.AsciiChar=221;
                        _resistor[linesindex[0]].Attributes=4;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[0]=2;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                         ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                    //orange
                    if(input.Event.MouseEvent.dwMousePosition.X<36 && input.Event.MouseEvent.dwMousePosition.X>29)
                    {
                        _resistor[linesindex[0]].Char.AsciiChar=221;
                        _resistor[linesindex[0]].Attributes=12;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[0]=3;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                         ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                    //yellow
                    if(input.Event.MouseEvent.dwMousePosition.X<43 && input.Event.MouseEvent.dwMousePosition.X>36)
                    {
                        _resistor[linesindex[0]].Char.AsciiChar=221;
                        _resistor[linesindex[0]].Attributes=14;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[0]=4;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                         ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                    //green
                    if(input.Event.MouseEvent.dwMousePosition.X<49 && input.Event.MouseEvent.dwMousePosition.X>43)
                    {
                        _resistor[linesindex[0]].Char.AsciiChar=221;
                        _resistor[linesindex[0]].Attributes=10;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[0]=5;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                          ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                    //blue
                    if(input.Event.MouseEvent.dwMousePosition.X<54 && input.Event.MouseEvent.dwMousePosition.X>49)
                    {
                        _resistor[linesindex[0]].Char.AsciiChar=221;
                        _resistor[linesindex[0]].Attributes=9;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[0]=6;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                          ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                    //violet
                    if(input.Event.MouseEvent.dwMousePosition.X<61 && input.Event.MouseEvent.dwMousePosition.X>54)
                    {
                        _resistor[linesindex[0]].Char.AsciiChar=221;
                        _resistor[linesindex[0]].Attributes=5;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[0]=7;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                          ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                    //grey
                    if(input.Event.MouseEvent.dwMousePosition.X<66 && input.Event.MouseEvent.dwMousePosition.X>61)
                    {
                        _resistor[linesindex[0]].Char.AsciiChar=221;
                        _resistor[linesindex[0]].Attributes=8;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[0]=8;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                         ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                    //white
                    if(input.Event.MouseEvent.dwMousePosition.X<72 && input.Event.MouseEvent.dwMousePosition.X>66)
                    {
                        _resistor[linesindex[0]].Char.AsciiChar=221;
                        _resistor[linesindex[0]].Attributes=15;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[0]=9;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                         ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                }
                else if(input.Event.MouseEvent.dwMousePosition.Y==8)
                {
                    //black
                    if(input.Event.MouseEvent.dwMousePosition.X<19 && input.Event.MouseEvent.dwMousePosition.X>13)
                    {
                        _resistor[linesindex[1]].Char.AsciiChar=221;
                        _resistor[linesindex[1]].Attributes=7;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[1]=0;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                        ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                    //brown
                    if(input.Event.MouseEvent.dwMousePosition.X<25 && input.Event.MouseEvent.dwMousePosition.X>19)
                    {
                        _resistor[linesindex[1]].Char.AsciiChar=221;
                        _resistor[linesindex[1]].Attributes=6;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[1]=1;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                        ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                    //red
                    if(input.Event.MouseEvent.dwMousePosition.X<29 && input.Event.MouseEvent.dwMousePosition.X>25)
                    {
                        _resistor[linesindex[1]].Char.AsciiChar=221;
                        _resistor[linesindex[1]].Attributes=4;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[1]=2;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                         ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                    //orange
                    if(input.Event.MouseEvent.dwMousePosition.X<36 && input.Event.MouseEvent.dwMousePosition.X>29)
                    {
                        _resistor[linesindex[1]].Char.AsciiChar=221;
                        _resistor[linesindex[1]].Attributes=12;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[1]=3;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                         ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                    //yellow
                    if(input.Event.MouseEvent.dwMousePosition.X<43 && input.Event.MouseEvent.dwMousePosition.X>36)
                    {
                        _resistor[linesindex[1]].Char.AsciiChar=221;
                        _resistor[linesindex[1]].Attributes=14;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[1]=4;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                         ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                    //green
                    if(input.Event.MouseEvent.dwMousePosition.X<49 && input.Event.MouseEvent.dwMousePosition.X>43)
                    {
                        _resistor[linesindex[1]].Char.AsciiChar=221;
                        _resistor[linesindex[1]].Attributes=10;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[1]=5;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                          ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                    //blue
                    if(input.Event.MouseEvent.dwMousePosition.X<54 && input.Event.MouseEvent.dwMousePosition.X>49)
                    {
                        _resistor[linesindex[1]].Char.AsciiChar=221;
                        _resistor[linesindex[1]].Attributes=9;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[1]=6;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                          ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                    //violet
                    if(input.Event.MouseEvent.dwMousePosition.X<61 && input.Event.MouseEvent.dwMousePosition.X>54)
                    {
                        _resistor[linesindex[1]].Char.AsciiChar=221;
                        _resistor[linesindex[1]].Attributes=5;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[1]=7;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                          ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                    //grey
                    if(input.Event.MouseEvent.dwMousePosition.X<66 && input.Event.MouseEvent.dwMousePosition.X>61)
                    {
                        _resistor[linesindex[1]].Char.AsciiChar=221;
                        _resistor[linesindex[1]].Attributes=8;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[1]=8;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                         ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                    //white
                    if(input.Event.MouseEvent.dwMousePosition.X<72 && input.Event.MouseEvent.dwMousePosition.X>66)
                    {
                        _resistor[linesindex[1]].Char.AsciiChar=221;
                        _resistor[linesindex[1]].Attributes=15;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[1]=9;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                         ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                }
                else if(input.Event.MouseEvent.dwMousePosition.Y==10)
                {
                    //black
                    if(input.Event.MouseEvent.dwMousePosition.X<19 && input.Event.MouseEvent.dwMousePosition.X>13)
                    {
                        _resistor[linesindex[2]].Char.AsciiChar=221;
                        _resistor[linesindex[2]].Attributes=7;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[2]=0;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                        ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                    //brown
                    if(input.Event.MouseEvent.dwMousePosition.X<25 && input.Event.MouseEvent.dwMousePosition.X>19)
                    {
                        _resistor[linesindex[2]].Char.AsciiChar=221;
                        _resistor[linesindex[2]].Attributes=6;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[2]=1;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                        ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                    //red
                    if(input.Event.MouseEvent.dwMousePosition.X<29 && input.Event.MouseEvent.dwMousePosition.X>25)
                    {
                        _resistor[linesindex[2]].Char.AsciiChar=221;
                        _resistor[linesindex[2]].Attributes=4;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[2]=2;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                         ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                    //orange
                    if(input.Event.MouseEvent.dwMousePosition.X<36 && input.Event.MouseEvent.dwMousePosition.X>29)
                    {
                        _resistor[linesindex[2]].Char.AsciiChar=221;
                        _resistor[linesindex[2]].Attributes=12;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[2]=3;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                         ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                    //yellow
                    if(input.Event.MouseEvent.dwMousePosition.X<43 && input.Event.MouseEvent.dwMousePosition.X>36)
                    {
                        _resistor[linesindex[2]].Char.AsciiChar=221;
                        _resistor[linesindex[2]].Attributes=14;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[2]=4;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                         ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                    //green
                    if(input.Event.MouseEvent.dwMousePosition.X<49 && input.Event.MouseEvent.dwMousePosition.X>43)
                    {
                        _resistor[linesindex[2]].Char.AsciiChar=221;
                        _resistor[linesindex[2]].Attributes=10;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[2]=5;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                          ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                    //blue
                    if(input.Event.MouseEvent.dwMousePosition.X<54 && input.Event.MouseEvent.dwMousePosition.X>49)
                    {
                        _resistor[linesindex[2]].Char.AsciiChar=221;
                        _resistor[linesindex[2]].Attributes=9;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[2]=6;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                          ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                    //violet
                    if(input.Event.MouseEvent.dwMousePosition.X<61 && input.Event.MouseEvent.dwMousePosition.X>54)
                    {
                        _resistor[linesindex[2]].Char.AsciiChar=221;
                        _resistor[linesindex[2]].Attributes=5;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[2]=7;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                          ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                    //grey
                    if(input.Event.MouseEvent.dwMousePosition.X<66 && input.Event.MouseEvent.dwMousePosition.X>61)
                    {
                        _resistor[linesindex[2]].Char.AsciiChar=221;
                        _resistor[linesindex[2]].Attributes=8;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[2]=8;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                         ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                    //white
                    if(input.Event.MouseEvent.dwMousePosition.X<72 && input.Event.MouseEvent.dwMousePosition.X>66)
                    {
                        _resistor[linesindex[2]].Char.AsciiChar=221;
                        _resistor[linesindex[2]].Attributes=15;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[2]=9;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                         ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                }
                else if(input.Event.MouseEvent.dwMousePosition.Y==12)
                {
                    //gold
                    if(input.Event.MouseEvent.dwMousePosition.X<18 && input.Event.MouseEvent.dwMousePosition.X>13)
                    {
                        _resistor[linesindex[3]].Char.AsciiChar=221;
                        _resistor[linesindex[3]].Attributes=14;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[3]=5;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                        ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                    //silver
                    if(input.Event.MouseEvent.dwMousePosition.X<25 && input.Event.MouseEvent.dwMousePosition.X>18)
                    {
                        _resistor[linesindex[3]].Char.AsciiChar=221;
                        _resistor[linesindex[3]].Attributes=8;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[3]=10;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                        ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                    //no line
                    if(input.Event.MouseEvent.dwMousePosition.X<33 && input.Event.MouseEvent.dwMousePosition.X>25)
                    {
                        _resistor[linesindex[3]].Char.AsciiChar=221;
                        _resistor[linesindex[3]].Attributes=0;
                        WriteConsoleOutput(out,_resistor,resistorsz,zerozero,&resistorrect);
                        lines[3]=20;
                        resistance=(lines[0]*10 + lines[1])*power(10,lines[2]);
                        SetConsoleCursorPosition(out,anspos);
                        printf("                                                                                         ");
                        SetConsoleCursorPosition(out,anspos);
                        printf("Resistance= %lld %c %d%c %c",resistance,241,lines[3],37,234);
                    }
                }
            }
        }
    }
    getch();
    return 0;
}
///
void printcol()
{
    COORD textpos={5,6},colorssz={60,1},colors2sz={21,1},zerozero={0,0};
    int _colorcode[10]={240,6,4,12,14,10,9,5,8,15},_colorcode2[3]={224,135,7},i,j,k=0;
    char _colorsmap[10][10]={" Black ",
                             "Brown ",
                             "Red ",
                             "Orange ",
                             "Yellow ",
                             "Green ",
                             "Blue ",
                             "Violet ",
                             "Grey ",
                             "White "},
    _colorsmap2[3][10]={" Gold ","Silver ","No line "};
    SMALL_RECT colorsrect={13,6,73,6},colorsrect2={13,12,34,12};
    CHAR_INFO _colors[60],_colors2[21];
    for(i=0;i<10;i++)
    {
        for(j=0;_colorsmap[i][j]!='\0';j++)
        {
            _colors[k].Char.AsciiChar=_colorsmap[i][j];
            _colors[k].Attributes=_colorcode[i];
            k++;
        }
    }
    _colors[0].Attributes=7;
    _colors[6].Attributes=7;
    k=0;
    for(i=0;i<3;i++)
    {
        for(j=0;_colorsmap2[i][j]!='\0';j++)
        {
            _colors2[k].Char.AsciiChar=_colorsmap2[i][j];
            _colors2[k].Attributes=_colorcode2[i];
            k++;
        }
    }
    _colors2[0].Attributes=7;
    _colors2[5].Attributes=7;
    _colors2[12].Attributes=7;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),textpos);
    printf("Line 1:");
    textpos.Y+=2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),textpos);
    printf("Line 2:");
    textpos.Y+=2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),textpos);
    printf("Line 3:");
    textpos.Y+=2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),textpos);
    printf("Line 4:");
    WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE),_colors,colorssz,zerozero,&colorsrect);
    colorsrect.Top+=2;
    colorsrect.Bottom+=2;
    WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE),_colors,colorssz,zerozero,&colorsrect);
    colorsrect.Top+=2;
    colorsrect.Bottom+=2;
    WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE),_colors,colorssz,zerozero,&colorsrect);
    WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE),_colors2,colors2sz,zerozero,&colorsrect2);
}
///
long long int power(int a,int b)
{
    int i;
    long long int c=1;
    for(i=0;i<b;i++)
    {
        c=a*c;
    }
    return c;
}
///
void title()
{
    char texttoprint[2][15]={"resistance", "calculator"};
    int i,j;
    SMALL_RECT rect={10,7,15,12};
    srand(time(NULL));
    for(i=0;i<2;i++)
    {
        for(j=0;texttoprint[i][j]!='\0';j++)
        {
            fillchar(texttoprint[i][j],221,rand()%7+9);
            printchar(texttoprint[i][j],rect);
            Sleep(100);
            rect.Left+=6;
            rect.Right+=6;
        }
        rect.Left=10;
        rect.Right=15;
        rect.Top+=6;
        rect.Bottom+=6;
    }
    Sleep(2000);
}
