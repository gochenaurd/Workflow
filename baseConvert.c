//This program takes a number of a certain base and converts
// it to a different base as specified by the user.

#include<stdio.h>
#include<math.h>

void printTitle();
void getInput(int*, int*, int*);
int convertValue(int, int, int);
int printResults(long long);

int main()
{
  //Variable Declarations

  int runState;
  int originalNumb;
  int originalBase;
  int newBase;
  long long newNumb;

  //Statements
  printTitle();

  runState = 1;

  while(runState == 1)
  {
    getInput(&originalNumb, &originalBase, &newBase);
    newNumb = convertValue(originalNumb, originalBase, newBase);
    runState = printResults(newNumb);
  }
  printf("\nThank you! Have a nice day.\n");

  return(0);
}

//To print the program title
void printTitle()
{
  printf("\nHello! this program takes a number of any base and converts it to a different base!\n");

  return;
}

//To get the user input
void getInput(int *originalNumb, int *originalBase, int *newBase)
{
  printf("\nEnter the original base: ");
  scanf("%d", originalBase);

  printf("Enter the original number: ");
  scanf("%d", originalNumb);

  printf("Enter the desired base: ");
  scanf("%d", newBase);

  return;
}

//To convert the number to a new base
int convertValue(int originalNumb, int originalBase, int newBase)
{
  int result;
  int digit;
  int length;

  result = 0;
  length = 0;

  while(originalNumb > 0)
  {
    digit = originalNumb % newBase;
    originalNumb /= newBase;
    result = result + digit * pow(originalBase, length);
    length++;
  }

  return(result);
}

//To print the results
int printResults(long long value)
{
  int state;

  printf("\nThe new number is: %lld\n", value);
  printf("\nDo you have another number to convert?\n");
  printf("Enter 1 if yes or 0 if no: ");

  scanf("%d", &state);

  return(state);
}
