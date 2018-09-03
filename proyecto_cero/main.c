

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int main( int argc, char *argv[] )  {

   char months[12][20]= {"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
   
   int month;
   int day;
   int year;
   printf("Enter a date");
   scanf("%d/%d/%d",&month,&day,&year);
   printf("You entered the date: %s %d, %d",months[month-1],day,year);
}
