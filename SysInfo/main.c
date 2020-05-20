#ifndef UNICODE
#define UNICODE
#endif
#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "netapi32.lib")

#include <windows.h>
#include <stdio.h>
#include <assert.h>
#include <lm.h>
#include <sddl.h>     
#include <locale.h>
#include <string.h>
#include <tchar.h>
#include <time.h> 

#define INFO_BUFFER_SIZE 32767

int main(int argc, wchar_t* argv[])
{
    TCHAR  infoBuf[INFO_BUFFER_SIZE];
    DWORD  bufCharCount = INFO_BUFFER_SIZE;
    int i;
    // Get and display the name of the computer. 
    bufCharCount = INFO_BUFFER_SIZE;
    if (!GetComputerName(infoBuf, &bufCharCount))
        printf("Error\n");
    printf("Computer name: ");
    WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), infoBuf, wcslen(infoBuf), &i, 0);


    // Get and display the user name. 
    bufCharCount = INFO_BUFFER_SIZE;
    if (!GetUserName(infoBuf, &bufCharCount))
        printf("Error\n");
    printf("\nUser name: ");
    WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), infoBuf, wcslen(infoBuf), &i, 0);

    struct tm newtime;
    time_t now = time(0);
    localtime_s(&newtime, &now);
    int Month = 1 + newtime.tm_mon;
    int Day = newtime.tm_mday;
    int Year = 1900 + newtime.tm_year;
    int Hour = newtime.tm_hour;
    int Min = newtime.tm_min;
    int Sec = newtime.tm_sec;
    printf("\nDate: %.2d.%.2d.%.4d ", Day, Month, Year);
   
    int WeekDay = newtime.tm_wday;
    switch (WeekDay) {
    case 0:
        printf("Sunday");
        break;
    case 1:
        printf("Monday");
        break;
    case 2:
        printf("Tuesday");
        break;
    case 3:
        printf("Wednesday");
        break;
    case 4:
        printf("Thursday");
        break;
    case 5:
        printf("Friday");
        break;
    case 6:
        printf("Saturday");
        break;
    } 
    printf("\nTime: %.2d:%.2d:%.2d\n", Hour, Min, Sec);
    return 0;
}