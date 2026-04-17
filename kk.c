#include<stdio.h>
/*
 1. FACTORIAL OF A NUMBER:
int main(){
int a ,b=1,c=1;
printf("Enter a no.\n");
scanf("%d",&a);
if(a==1 || a==0){printf("The factorial of %d is 1",a);}
else{
 for (int i = 0; i < a; i++)
 {
  b*=c;
  c++;
 }
 printf("The factorial of %d is %d",a,b);

}

return 0;
}
 
2. SUM OF DIGITS OF A NUMBER:
int sum(int a){
int s;
for(s=0 ; a > 0 ;a/=10){
     s+=a%10;
}
 printf("The sum of digits is %d",s);
}
int main(){
int b;
printf("Enter a no.\n");
scanf("%d",&b);
sum(b);
return 0;
}

3. REVERSE A NUMBER:
int main(){
int a,b;
printf("Enter a no. to reverse\n");
scanf("%d",&a);
for (b=0; a>0; a/=10)
{b=b*10 +a%10;
     
}
printf("The reversed no. is %d\n",b);

     return 0;
}

4. FIBONACCI SERIES:
void Fib(int n) {
  
  	// If the number of terms is smaller than 1
    if (n < 1) {
        printf("Invalid Number of terms\n");
        return;
    }
  
  	// First two terms of the series
    int n1 = 1;
    int n2 = 0;

   printf("Fibonacci Series of %d terms is:\n",n);
    for (int i = 1; i <= n; i++) {
      	
      	// Print current term and update previous terms
        if (i > 2) {
            int c = n1 +n2;
            n2 = n1;
            n1 = c;
            printf("%d ", c);
        }
		else if (i == 1)
            printf("%d ", n2);
        else if (i == 2)
            printf("%d ", n1);
    }
}

int main() {
int n ;
printf("Enter no. of terms\n");
scanf("%d",&n);
  	
Fib(n);
return 0;
}

5. COPY CONTENTS OF ONE FILE IN ANOTHER:
#include <stdlib.h> // For exit()

int main()
{
    FILE *fptr1, *fptr2;
    char filename[100];
    int c;

    printf("Enter the filename to open for reading: ");
    scanf("%s", filename);

    // Open one file for reading
    fptr1 = fopen(filename, "r");
    if (fptr1 == NULL)
    {
        printf("Cannot open file %s\n", filename);
        exit(1);
    }

    printf("Enter the filename to open for writing: ");
    scanf("%s", filename);

    // Open another file for writing
    fptr2 = fopen(filename, "w");
    if (fptr2 == NULL)
    {
        printf("Cannot open file %s\n", filename);
        exit(1);
    }

    // Read contents from file
    while ((c = fgetc(fptr1)) != EOF)
    {
        fputc(c, fptr2);
    }

    printf("Contents copied to %s\n", filename);

    fclose(fptr1);
    fclose(fptr2);
    return 0;
}

6. LINEAR SEARCH IN AN ARRAY:

int main()
{
int n,b,i;

printf("Enter the total no. of array elements\n");
scanf("%d",&n);
int a[n];
printf("Enter the array elements\n");
for (int i = 0; i < n; i++)
{
    scanf("%d",&a[i]);
}
printf("Enter the element u want to search\n");
scanf("%d",&b);
for ( int i = 0; i < n; i++)
{
 if (b==a[i])
 {
     printf("%d is the no.%d element in the array.",b,i+1);
 }
 
}
return 0;}

7. REVERSE A STRING WITHOUT USING LIB FUNC 
#include <string.h>

void rev(char* s) {

    // Initialize l and r pointers
    int l = 0;
    int r = strlen(s) - 1;
    char t;

    // Swap characters till l and r meet
    while (l < r) {
      
        // Swap characters
        t = s[l];
        s[l] = s[r];
        s[r] = t;

        // Move pointers towards each other
        l++;
        r--;
    }
}

int main() {
    char s[100];
    printf("Enter a string\n");
     fgets(s, sizeof(s), stdin);

	
  	// Reversing s
    rev(s);
  
    printf("%s", s);
    return 0;
}


8. SUM OF ARRAY USING POINTER 
int main(){
int n,s=0;
int *d;
printf("Enter the total no. of array elements\n");
scanf("%d",&n);
int a[n];
d = a;
printf("Enter the array elements\n");
for (int i = 0; i < n; i++)
{
    scanf("%d",&a[i]);
}

for (int i=0; i < n ; i++)
{
    s+=*d;
    d++;
}
printf("Sum of array elements is :%d\n",s);
return 0;
}

9. LARGEST AND SMALLEST IN ARRAY */
int main(){









     return 0;}