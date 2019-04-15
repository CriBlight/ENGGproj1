#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Current Build = Tio
//Auther: Christopher Baita C33289270

void rEncrypt() //funtion prototype. May want to change this to return the decrypted msg, NEEDS FILE AURGUMENT.(test)
{
    FILE* input, output;
    int opt, key, i = 0;
    char eMsg[1024], dMsg[1024], fMsg[1024], space[] = {" "};
    
    memset(eMsg,0,strlen(eMsg));
    memset(dMsg,0,strlen(dMsg));
    memset(fMsg,0,strlen(fMsg));

    printf("Enter 1 for file input\nEnter 2 for typed encrypt\n");
    scanf("%d", &opt);

    if(opt == 1) //currently input is hard coded.... maybe change to a typed argument?
    {
        printf("Enter key :\n");
        scanf("%d", &key);

        input = fopen("t.txt", "r");

        if(input == NULL)
        {
            perror("fopen()");
            return;
        }

        while(!feof(input))
        {
        	strcat(fMsg, eMsg);
            fscanf(input, "%s", eMsg);
            strcat(fMsg, space);
        }

        while(eMsg[i] != '\0')
	       {
		        printf("%c", eMsg[i]);
		        dMsg[i] = eMsg[i] - key;
		        i++;
	       }

        printf("\nwe got %s\n", fMsg);
    }

}

int main()
{

    int opt = 0, k;
    do
    {

        printf("Please Select an option from below: \n 1: Encryption using roation cipher\n 2: Decryption using roation cipher\n 0: Exit \nInput: ");
        scanf("%d", &opt);
        if(opt > 0 && opt < 9) //9 is currently a placeholder until amount of options is determined.
        {
            switch(opt)
            {
                case 1: rEncrypt(); //funtion for 1 here
                break;
                case 2: printf("case 2\n"); //funtion 2 here
                break;
                //default: printf("Invaild Option\n");
            }
        }
        else if(opt == 0)
        {
            exit(EXIT_SUCCESS);
        }
        else
        {
            printf("Invalid Input please select an option from the options provided\n");
        }

    } while(1);
    return 0;
}
