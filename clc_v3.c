#include <stdio.h>
#include <math.h>
#include <string.h>
#include<ctype.h>//allows me to use the toupper() 
float a=0,b=0,c=0,d=0,e=0; //had to make thses all global varibales due to having multiple different functions using all of them (it was alot easier then declaing new ones in each function)
float memory[21]={0};
char option,operation='l',variable='l',secondaryOption,num,sel;
float num1=0, num2=0;
int spot=1,choice;
int main(void){
  float get_Num(float number),assort_Variables(char var,float number),operation_Assignment(char Operation,float num1,float num2),binary(),urnary(),special_case_get_Num(),special_case_get_pos_Num(),advanced();
  void reset(),variable_function(),memory_function();
  char option_selection(char option);
  //these are all my functions there descriptions will be down at the bottom with them
  printf("Welcome to my Command-Line Calculator (CLC)\nDeveloper: Lindsey Ferguson\nVersion: 2\nDate: november 2020\n\n");
  printf("Options:\nB) - Binary Mathematical Operations, such as addition and subtraction.\nU) - Unary Mathematical Operations, such as square root, and log.\nA) - Advances Mathematical Operations, using variables, arrays.\nV) - Define variables and assign them values.\nM) - To see Calculator Memory\nR) - to reset calculator memory\nE) - Exit\n");
  while(1){
    option= option_selection(option);
    if(option=='E'){//i did this instead of putting it i  the loop so it exits immediatly instead of looping one more time
      break;
    }   
    if(option=='B'){
      printf("The Result its:\t%.2f\n",binary());
    }
    else if(option =='U'){
     printf("The Result its:\t%.2f\n",urnary());
    }
    else if(option =='V'){
      variable_function();
    }
    else if(option =='M'){
      memory_function();
    }
    else if(option =='R'){
      reset();
    }
    else if(option=='A'){
       printf("The Result its:\t%.2f\n",advanced());
    }
    spot+=1; //goes to the next spot in memory after each use made
    option =' ';//since these are global varibales i have to reset them or else it stays the same
    operation = ' ';
    num1=0;
    num2=0;
  }
  printf("Thanks for using my Simple Calculator. Hope to see you soon again, Goodbye!");
}
  
float get_Num(float number){//this function gets a number from the user making sure it is a valid number (ex. not a letter)
  while(scanf("%f",&number)==0){
    printf("Invalid input. Please enter a number:\n");
    scanf("%*s");
  }
  return number;
}

float assort_Variables(char var, float num){//this assorts each varibale into the correct one
  if(var =='a'){
    return num =a;
  }
  else if(var =='b'){
    return num =b;
  }
  else if(var =='c'){
    return num =c;
  }
  else if(var =='d'){
    return num =d;
  }
  else{
    return num =e;
  }
}

float special_case_get_Num(){//this is used in the advanced function to get a number while checking for variable use
  while(1){
    printf("Please enter a value:\n");//this sees if the input was a number
    if(scanf("%f",&num1)==1){
      return num1;
      break;
    }
    scanf(" %c",&num);//this sees if the input was a char value aka a variable
    if(num == 'a'||num == 'b'||num == 'c'||num == 'd'||num == 'e'){
      num1 =assort_Variables(num,num1); // then it uses the assort variable to get the stored num
      return num1;
      break;
    }
  }
}

float special_case_get_pos_Num(){//this is alos used in the advanced funtion but it gets a positive number instead
  while(1){
    printf("Please enter a positive value:\n");
    if(scanf(" %f",&num1)==1){
      if(num1>0){//same thing as special_case_get_Num() but it makes sure the num is greater than zero (so no negative numbers)
        return num1;
        break;
      }
    }
    scanf(" %c",&num);
    if(num == 'a'||num == 'b'||num == 'c'||num == 'd'||num == 'e'){
      if(num>0){
        num1 =assort_Variables(num,num1); 
        return num1;
        break;
      }
    }
  }
}

float operation_Assignment(char operation, float num1, float num2){//this is used to get the numbers and operation from the user and return the correct sum 
  if(operation == '+'){//ex. if the operation is + it adds the 2 numbers
      return num1+num2;
  }
  else if(operation == '-'){
    return num1-num2;
  }
  else if(operation == '*'){
   return num1*num2;
  }
  else if(operation == '/'){
      return num1/num2;
  }
  else if(operation == '%'){
    return fmod(num1,(num2));
  }
  else if(operation == 'P'){
    return pow(num1,num2);
  }
  else if(operation == 'X'){
    if(num1>=num2){
      return num1;
    }
    else{
      return num2;
    }
  }
  else{
    if(num1<=num2){
      return num1;
    }
    else{
      return num2;
    }
  }
}

float binary(){//this is the binary function
  printf("Please enter the first number:\n");
  num1 = get_Num(num1);//using my other function to get a valid number
  while(operation!='+'&& operation!='-'&&operation!='*'&&operation!='/'&&operation!='%'&&operation!='P'&&operation!='X'&&operation!='I'){
    printf("Please enter the operation( + , - , * , / , %c, P (for power) , X (for maximum) , I (for minimum):\n",'%');
    scanf(" %c",&operation); //scans until a valid operation is given
  }
  if(operation =='/'){//special case for divison as the denominator (num2) cannot be zero
    while(num2==0){
      printf("Please enter the second number (non-zero):\n");
      num2 = get_Num(num2);
    }
  }
  else{//if the operation isnt divison its the same process as num1
    printf("Please enter the second number:\n");
    num2 = get_Num(num2);
  }
  return memory[spot]+=operation_Assignment(operation,num1,num2);//then I use my operation_Assignment to get the correct value and then add the value to the memory
}

float urnary(){//this is the urnary function
  while(operation!='S'&& operation!='L'&& operation!='E'&& operation!='C'&& operation!='F'){//same process for operation as binary()
      printf("Please enter the operation( S (for square root) , L (for logarithm) , E (for exponential) , C (for ceil) , F (for floor) :\n");
      scanf(" %c",&operation);
  }
  if(operation =='S'){
    while(num1<1){
      printf("Please enter a positive number:\n");
      num1 = get_Num(num1);//same process as binary() but gets a positive num
    }
    return memory[spot]+=sqrt(num1);//same process as binary()
  }
  else if(operation =='L'){
    while(num1<1){
      printf("Please enter a positive number:\n");
      num1 = get_Num(num1);
      }
    return memory[spot]+=log(num1);
  }
  else if(operation =='E'){
      printf("Please enter the number:\n");
      return memory[spot]+=exp(get_Num(num1));
  }
  else if(operation == 'C'){
    printf("Please enter the number:\n");
    return memory[spot]+=ceil(get_Num(num1));
  }
  else if(operation == 'F'){
    return memory[spot]+=floor(get_Num(num1));
  }
  else{
    return 0;
  }
}

void memory_function(){//this is the memory function
  if(spot==1){//since when entering zero to get the full list, i use spot 1 as my 'zero'
    printf("Memory has nothing in it!\n");//if spot is 1 then theres nothing in the memory
  }
  else{//if spot is greater than 1 then there are items stored in the memory
    printf("the memory has %d items stored\n",spot-1);//subtracting the one to get the correct amount
    while(1){
      while(1){//this gets a valid memory spot
        printf("pick a memory spot from 1-%d or enter zero to see all values:\n",spot-1);//saying which spots to choose from 
        scanf("%d",&choice);
        if(choice >-1 || choice<spot-1 ){//if the option is valid it breaks
          break;
        }
      }
      if(choice==0){
        for(int i =1;i<spot;i++){//if choice is equal to zero then it prints out the whole list
          printf("[%d] %.2f\n",i,memory[i]);
        }
      }
      else{
        printf("[%d] %.2f\n",choice,memory[choice]);//if choice isnt equal to 0 then it just prints out what the users choice is
      }
      printf("Enter B to go back and get more values from meory\nEnter E to exit back to main menu\n");
      scanf(" %c",&option);
      if(option=='e'||option=='E'){//if the user enters E it goes back to main menu
        break;
      }
    }
  }
  spot-=1;//since i add a spot after every action, i have to subtract 1 from meory since im not actually storing anything
}

void variable_function(){
  spot-=1;//same thing as memory function, since no operation has taken place nothing get sstored in memory
  while(variable != 'a' && variable!='b' && variable!='c'&&variable!='d'&& variable!='e'){
    printf("please enter a single character between 'a' to'e'\n");
    scanf(" %c",&variable);//make ssure its a valid varibal option
  }
  printf("Please enter the value:\n");
  num1 = get_Num(num1);
  if(variable == 'a'){//this assigns the number to the variable
    a=num1;
  }
  else if(variable == 'b'){
    b=num1;
  }
  else if(variable == 'd'){
    c=num1;
  }
  else if(variable == 'd'){
    d=num1;
  }
  else if(variable == 'e'){
    e=num1;
  }
  printf("you have assigned the value %.2f to the variable %c\n",num1,variable);
  variable=' ';//resets varibale since its global
}

void reset(){//reset memory function
  printf("Are you sure you want to clear memory? (y-yes/n-no)\n");//double checks if you want to erase the memroy
  scanf(" %c",&sel);
  if(sel =='y'){//if yes then memory is replaced by zeros
    for(int i =0;i<20;i++){
      memory[i]=0;
      spot=0;//spot is also reset to zero, it gets technically reset to one since i add one spot after each funtion
    }
    printf("cleared Memory\n");
  }
  else{
    printf("Memory NOT cleared\n");
  }
}

float advanced(){//this is the advanced function 
  char secondaryOperation='l';
  while(1){
    printf("Select one of the following items:\nB) - Binary Mathematical Operations, such as addition and subtraction.\nU) - Unary Mathematical Operations, such as square root, and log.\nE) - Exit and back to the main menu\n");//listing the options
    scanf(" %c",&secondaryOption);
    secondaryOption = toupper(secondaryOption);//making sure its uppercase
    if(secondaryOption =='E'){
      break;
    }//if e is cliked then youir brought back to thje main menu 
    if(secondaryOption =='B'){//binary
      while(1){
        printf("enter value:\n");
        if(scanf("%f",&num1)==1){
          break;
        }
        scanf(" %c",&num);
        if(num == 'a'||num == 'b'||num == 'c'||num == 'd'||num == 'e'){
          num1 =assort_Variables(num,num1); 
          break;
        }
      }
      while(1){
        scanf("%c",&secondaryOperation);
        if(secondaryOperation=='+'|| secondaryOperation=='-'||secondaryOperation=='*'||secondaryOperation=='/'||secondaryOperation=='%'||secondaryOperation=='P'||secondaryOperation=='X'||secondaryOperation=='I'){
          break;
        }
        secondaryOperation = toupper(secondaryOperation);
        printf("Please enter the operation( + , - , * , / , %c, P (for power) , X (for maximum) , I (for minimum):\n",'%');
      }
      if(secondaryOperation == '/'){//if the operation is dividon thee denominator cannot be zero
        while(1){
          printf("enter non-zero value:\n");
          if(scanf("%f",&num2)==1){
            if(num2>0){
              break;
            }
          }
          scanf(" %c",&num);
          if(num == 'a'||num == 'b'||num == 'c'||num == 'd'||num == 'e'){
            num2 =assort_Variables(num,num2);//this allows for no variables to be equal to zero, to be the denimator
            if(num2>0){//if not greater then zero it doesnt break 
              break;
            }
          }
        }
      }
      else{//if its not divison then it proceeds as normally
        while(1){
          printf("enter value:\n");
          if(scanf("%f",&num2)==1){
            break;
          }
          scanf(" %c",&num);
          num2 =assort_Variables(num,num2);
          break;
        }
      }
      printf("The result is\t %.2f\n",memory[spot]+=operation_Assignment(secondaryOperation,num1,num2));
    }
    else if(secondaryOption =='U'){//urnary
      printf("Please enter the operation( S (for square root) , L (for logarithm) , E (for exponential) , C (for ceil) , F (for floor) :\n");
      while(secondaryOperation!='S'&& secondaryOperation!='L'&& secondaryOperation!='E'&& secondaryOperation!='C'&& secondaryOperation!='F'){
        scanf(" %c",&secondaryOperation);
      }
      if(secondaryOperation =='S'){
        return memory[spot]+=sqrt(special_case_get_pos_Num());
      }
      else if(secondaryOperation =='L'){//another special case since logs cant be negative
        return memory[spot]+=log(special_case_get_pos_Num());
      }
      else if(secondaryOperation =='E'){        
        return memory[spot]+=exp(special_case_get_Num());
      }
      else if(secondaryOperation == 'C'){
        return memory[spot]+=ceil(special_case_get_Num());
      }
      else if(secondaryOperation == 'F'){
        return memory[spot]+=floor(special_case_get_Num());
      }
    }
  }
  return 0;
}
char option_selection(char option){//gives the user the options and gets a valid ans
  while(option!='B'&& option!='U'&&option!='V'&&option!='A'&&option!='M'&&option!='R'&&option!='E'){
    printf("please select your option:\nB (Binary operation), U (Unary operation) , A (Advanced), V (Variables), M (memory), R(clear memory) E (Exit)\n");
    scanf(" %c",&option);
    option = toupper(option);//makes the option uppercase
  }
  return option;
}