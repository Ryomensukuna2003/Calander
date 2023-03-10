#include <stdio.h>
#include <stdbool.h>
#include <time.h>

//                      「本 物 の 柔 術 を 見 せ て や る」

char *months[]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
void display_time(){
    time_t t = time(NULL);
    char date[11];
    // string format time
    strftime(date, sizeof(date), "%m-%d-%Y", localtime(&t));
    printf("\n\n |--[  %s  ]\n |  \n", date);
    
}

// Leap year 
bool leap_year(int year){
    if(((year % 4 == 0) && (year % 100!= 0)) || (year%400 == 0))  {
        return true;
    }
    return false;
    
}

// Full calander printing
void calander_print(){
    int year,month,day,daysInMonth,weekDay=0,startingDay;
   printf("  |--Enter year: ");
   scanf("%d",&year);


   int monthDay[]={31,28,31,30,31,30,31,31,30,31,30,31};

   if(leap_year(year)) monthDay[1]=29;

   startingDay=(year + year / 4 - year / 100 + year / 400) % 7;

   for(month=0;month<12;month++){

        daysInMonth=monthDay[month];
        printf("\n\n   ---------------%s-------------------\n",months[month]);
        printf("\n     Sun  Mon  Tue  Wed  Thu  Fri  Sat\n"); 

        for(weekDay=0;weekDay<startingDay;weekDay++) printf("     "); 

        for(day=1;day<=daysInMonth;day++){
            printf("%5d",day);    
            if(++weekDay>6){
                printf("\n   ");
                weekDay=0;
            }
            startingDay=weekDay;
        }   
   }
   printf("\n");
}

// Number of days in a month
void num_of_days(){
    printf("  |--Enter Month and Year: ");
    int month , year; scanf("%d %d",&month , &year);printf("   |\n");
    switch ( month ) {
        case 1  : printf("   |--Number of days in %s is %d\n",months[month-1],31); break;  
        case 2  : if (leap_year(year)) printf("   |--Number of days in %s is %d\n",months[month-1],29);  
                  else printf("   |--Number of days in %s is %d\n",months[month-1],28); break;          
        case 3  : printf("   |--Number of days in %s is %d\n",months[month-1],31) ; break;  
        case 4  : printf("   |--Number of days in %s is %d\n",months[month-1],30) ; break;  
        case 5  : printf("   |--Number of days in %s is %d\n",months[month-1],31) ; break;  
        case 6  : printf("   |--Number of days in %s is %d\n",months[month-1],30) ; break;  
        case 7  : printf("   |--Number of days in %s is %d\n",months[month-1],31) ; break;  
        case 8  : printf("   |--Number of days in %s is %d\n",months[month-1],31) ; break;  
        case 9  : printf("   |--Number of days in %s is %d\n",months[month-1],30) ; break;  
        case 10 : printf("   |--Number of days in %s is %d\n",months[month-1],31) ; break;  
        case 11 : printf("   |--Number of days in %s is %d\n",months[month-1],30) ; break;  
        case 12 : printf("   |--Number of days in %s is %d\n",months[month-1],31) ; break;  
        default : printf("   |--Number of days in %s is %d\n",months[month-1],-1) ; break;  
    }   
    printf("\n");
}

void leapyear_range(){
    int start,end;
    printf("  |--Enter Starting year : ");
    scanf("%d",&start);
    printf("  |--Enter Ending Year : ");
    scanf("%d",&end);
    printf("   |\n   |--All Leap year between %d and %d are : ",start,end);
    for(int i=start;i<=end;i++){
        if(leap_year(i)){
            printf("%d ",i);
        }
    }
    printf("\n   ");
}

void day_of_date(){
    int day, month, year;
    printf("  |--Enter date (dd mm yyyy): ");
    scanf("%d %d %d", &day, &month, &year);
    printf("   |\n");


    if (month < 3) {
        month += 12;
        year--;
    }

    // Apply Zeller's congruence formula
    int q = day;
    int m = month;
    int K = year % 100;
    int J = year / 100;
    int h = (q + 13*(m+1)/5 + K + K/4 + J/4 + 5*J) % 7;

    // Determine the day of the week
    switch (h) {
        case 0: printf("   |--Day at %d-%d-%d is Saturday\n",day,month,year); break;
        case 1: printf("   |--Day at %d-%d-%d is Sunday\n",day,month,year); break;
        case 2: printf("   |--Day at %d-%d-%d is Monday\n",day,month,year); break;
        case 3: printf("   |--Day at %d-%d-%d is Tuesday\n",day,month,year); break;
        case 4: printf("   |--Day at %d-%d-%d is Wednesday\n",day,month,year); break;
        case 5: printf("   |--Day at %d-%d-%d is Thursday\n",day,month,year); break;
        case 6: printf("   |--Day at %d-%d-%d is Friday\n",day,month,year); break;
        default: printf("   |--Invalid input\n"); break;
    }

}

void birthday(){
    int birth_year, birth_month, age;
    
    printf("  |--Enter your birth year and month (mm/yy): ");
    scanf("%d %d", &birth_month, &birth_year);
    
    time_t t = time(NULL);
    struct tm* now = localtime(&t);
    
    int current_year = now->tm_year + 1900;
    int current_month = now->tm_mon + 1;
    
    age = current_year - birth_year;
    
    if (birth_month > current_month) {
        age--;
    }
    printf("   |\n   |--You are now %d years old.\n", age);

}

int main(){
       while(true){
        display_time();

        printf(" |  Enter 1 for Full calander \n");
        printf(" |  Enter 2 for Number of days in month \n");
        printf(" |  Enter 3 for Leap year in range \n");
        printf(" |  Enter 4 for Day at given date \n");
        printf(" |  Enter 5 for Age \n");
        printf(" |  CTRL+C to exit ;-)\n");

        printf(" |--");

        int choice;scanf("%d",&choice);
        printf("  |\n");
        switch(choice){
            case 1: calander_print(); break;
            case 2: num_of_days(); break;
            case 3: leapyear_range(); break;
            case 4: day_of_date(); break;
            case 5: birthday(); break;
            default:printf(" |--BRO WHAT THE FUCK \n "); break;
        }
        // for .5s buffer;
        for(int i=0;i<1900000000;i++);

        printf("\n");
        printf("_______________________________________________________________");
    }
}
