#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
}retire_info;


void retirement (int startAge,double initial, retire_info working, retire_info retired)
{
  int wAge = startAge +working.months;
  int rAge = wAge + retired.months;
  int cAge = startAge;
  float balance = initial;
  for (; cAge <= wAge ; cAge++){
    
    printf("Age %3d month %2d you have $%.2lf\n",cAge/12 , cAge%12, balance);
   
    balance*= 1+working.rate_of_return;
    balance += working.contribution;
    
  }
  for (; cAge < rAge ; cAge++){
    printf("Age %3d month %2d you have $%.2lf\n",cAge/12, cAge%12 , balance);
    balance+= balance*retired.rate_of_return + retired.contribution;
  }
}

int main (){
  retire_info work;
  retire_info retire;


  
  work.months = 489;
  
  work.contribution=1000;
  
  work.rate_of_return = 0.00375;

  
  retire.months = 384;
  
  retire.contribution = -4000;
  
  retire.rate_of_return = 0.01/12;
  

  
  int age = 327;
  
  float savings =21345.0;
  

  
  retirement (age,savings,work,retire);
  return 0;
}
