#include <stdio.h>
#include <stdlib.h>
//Current Build = Tio
//Auther: Christopher Baita C33289270

void rEncrypt(int key) //funtion prototype. May want to change this to return the decrypted msg, NEEDS FILE AURGUMENT.
{

}

int main()
{
    int opt = 0;
    do 
    {

        printf("Please Select an option from below: \n 1: Encryption using roation cipher\n 2: Decryption using roation cipher\n 0: Exit \nInput: ");
        scanf("%d", &opt);
        if(opt > 0 && opt < 9) //9 is currently a placeholder until amount of options is determined.
        {
            switch(opt)
            {
                case 1: printf("case 1\n"); //funtion for 1 here
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
