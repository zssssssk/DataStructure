/*

设置字体的显示颜色 

Author: 僧德文
Time: 2020.11
*/

#ifndef _SDW_H_
#define _SDW_H_

//用于设置字体显示的颜色的库
#include "windows.h"   



//黑底红字 
void setRedonBlack()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_RED); //设置为红色字体 
}

//黑底绿字 
void setGreenonBlack()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_GREEN); //设置为绿色字体 
}


//黑底黄字
void setYellowonBlack()
{
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY
|FOREGROUND_RED | FOREGROUND_GREEN);
}

//黑底洋红字 Magenta on Black：
void setMagentaonBlack()
{
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY
|FOREGROUND_RED | FOREGROUND_BLUE);
}
//黑底青字Cyan on Black：
void setCyanonBlack()
{
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY
|FOREGROUND_GREEN | FOREGROUND_BLUE);
}

//黑底白字 
void setWhiteonBlack()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
            FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); //设置为白色字体 
} 

//白底红字 
void setRedonWhite()
{
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY |
            FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE |
            FOREGROUND_RED); 
}

//白底黑字 
void setBlackonWhite()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY |
             BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
} 

//白底绿字 
void setGreenonWhite()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY |
            FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE |
            FOREGROUND_GREEN); 
}
 

//其它颜色组合，以system("color 3f")为例
//浅蓝底白字 
void setWhiteon3f()//默认值 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x3f);  
}
//浅蓝底黑字
void setBlackon3f()//默认值 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x30);  
}

//浅蓝底红字
void setRedon3f()//默认值 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x3C); 
}

//浅蓝底黄字
void setYellowon3f()//默认值 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x3e);  
}


//浅蓝底绿字
void setGreenon3f()//默认值 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x3a);  
}

//浅蓝底青字
void setCayonon3f()//默认值 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x3b); 
}

//浅蓝底洋红色的字
void setMagentaon3f()//默认值 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x3d);  
}


//其它颜色组合，以system("color 4f")为例
//紫底白字 
void setWhiteon4f()//默认值 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x4f);  
}
//紫底黑字
void setBlackon4f()//默认值 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x40);  
}

//紫底红字
void setRedon4f()//默认值 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x4C);  
}

//紫底黄字
void setYellowon4f()//默认值 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x4e);  
}

//紫底青字
void setCayonon4f()//默认值 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x4b); 
}


//绿字
void setGreenon4f()//默认值 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x4a); 
}

//紫底洋红色的字
void setMagentaon4f()//默认值 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x4d);  
}

//灰色的字
void setGreyon4f()//默认值 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x48);  
}



//灰色的字
void setGreyon3f()//默认值 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x38);  
}


//灰色的字
void setGreyon5f()//默认值 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x58);  
}


//其它颜色组合，以system("color 5f")为例
//淡紫底白字 
void setWhiteon5f()//默认值 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x5f);  
}
//淡紫底黑字
void setBlackon5f()//默认值 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x50);  
}

//淡紫底红字
void setRedon5f()//默认值 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x5C);  
}

//淡紫底黄字
void setYellowon5f()//默认值 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x5e);  
}

//淡紫底青字
void setCayonon5f()//默认值 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x5b); 
}


//淡紫底绿字
void setGreenon5f()//默认值 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x5a); 
}

//淡紫底洋红色的字
void setMagentaon5f()//默认值 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x5d);  
}

bool color(int _color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),_color);
}

#endif
