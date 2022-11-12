#include <stdio.h> 
#include <math.h> 
#include <conio.h> 
 
int main (void) { 
 int city; 
 printf("Cost of a 10-minute long distance call\n"); 
 printf("1. Moscow(905)\n"); 
 printf("2. Rostov(194)\n"); 
 printf("3. Krasnodar(491)\n"); 
 printf("4. Kirov(800)\n"); 
 printf("Strike Any Other Key to Skip\n"); 
 printf ("Enter your choice:"); 
 scanf("%d", &city); 
 
  
 switch (city) { 
  case 1: 
   printf("\nMoscow: 4.15 rub/min"); 
   break; 
  case 2: 
   printf("\nRostov: 1.98 rub/min"); 
   break; 
  case 3: 
   printf("\nKrasnodar: 2.69 rub/min"); 
   break; 
  case 4: 
   printf("\nKirov: 5.00 rub/min"); 
   break; 
  default: 
   printf("\nNo option selected"); 
   break; 
 } 
 
}