
#include <stdio.h>

int main()
{
    int a = 1;

    char mystring[50];
    char *cptr; 

    FILE *f1 = fopen("alternate.txt", "w"); 

    if(f1) {
        printf ("Enter a string to copy alternate texts on file: ");
        scanf  ("%s",mystring);

        cptr = mystring;
        while(*cptr != '\0') {
            if(a) {
                fprintf(f1, "%c", *cptr);
                printf("%c", *cptr);
                a = 0;
            } else {
                a = 1;
            }
            cptr++;
        }
        
        printf(" (write succesfull)");
        fclose (f1);
    }

    else {
        printf("Unable to open file");
    }

    printf("\n");
}


/* =================================================================
 * Output :
 
	 Enter a string to copy alternate texts on file: Test12345 
	 Ts135 (write succesfull)
	 
  ================================================================= */
