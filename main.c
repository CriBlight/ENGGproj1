#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <ctype.h>
//Current Build = Tio
//Auther: Christopher Baita C33289270

void rEncrypt() //funtion prototype. May want to change this to return the decrypted msg, NEEDS FILE AURGUMENT.(test) remember to put everything to uppercase to avoid confusion
{
    FILE *input, *output;
    int opt, key, i = 0;
    char eMsg[1024], dMsg[1024], fMsg[1024], space[] = {" "};
    
    memset(eMsg,0,strlen(eMsg));
    memset(dMsg,0,strlen(dMsg));
    memset(fMsg,0,strlen(fMsg));

    printf("Enter 1 for file input\nEnter 2 for typed encrypt\n");
    scanf("%d", &opt);

    if(opt == 1) //currently input is hard coded.... maybe change to a typed argument?. Might want to remove the opt becuase not currently needed.
    {
        printf("Enter key :\n");
        scanf("%d", &key);

        input = fopen("eIn.txt", "r");

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

        while(fMsg[i] != '\0')
	       {
		        if(fMsg[i] >= 97 && fMsg[i] <= 122)
                {
                    fMsg[i] -= 32;
                }
                
                printf("%c", fMsg[i]);
		        
                if(fMsg[i] != space[0] && !(fMsg[i] < 65))
                {
                    dMsg[i] = fMsg[i] - key;
                    
                    if(dMsg[i] < 65 && dMsg[i] > 39)
                    {
                        dMsg[i] += 26; 
                    }
                    else if(dMsg[i] > 90 && dMsg[i] < 116)
                    {
                        dMsg[i] -= 26;
                    }
                    //else
                    //{
                     //   printf("Key out of range: Key must be a number between 1 and 25");
                    //} 
                    //(prints 3 times for some reason?) found issue lowercase letters out of range. find a way to convert all to capital. 

                }
                else
                {
                    dMsg[i] = fMsg[i];
                }
                
                i++;
	       }
        
        output = fopen("eOut.txt", "w");
        fseek(output, 0, SEEK_SET);
        fprintf(output, "%s\n", dMsg);
        printf("\nYour encrypted message is %s\n", dMsg);
        fclose(input);
        fclose(output);
    }

}

void rDecrypt() //new funtion, new troubles.
{
    FILE *in, *out;
    int i = 0, dkey;
    char inMsg[1024], fullMsg[1024], dcMsg[1024], spce[] = {" "};
    
    memset(inMsg,0,strlen(inMsg));
    memset(fullMsg,0,strlen(fullMsg));
    memset(dcMsg,0,strlen(dcMsg));

    printf("Enter key :\n");
    scanf("%d", &dkey);

    in = fopen("dIn.txt", "r");

    if(in == NULL)
    {
        perror("fopen()");
        return;
    }

    while(!feof(in))
    {
        strcat(fullMsg, inMsg);
        fscanf(in, "%s", inMsg);
        strcat(fullMsg, spce);
    }

    while(fullMsg[i] != '\0')
    {
        if(fullMsg[i] >= 97 && fullMsg[i] <= 122)
        {
            fullMsg[i] -= 32;
        }

        printf("%c", fullMsg[i]);

        if(fullMsg[i] != spce[0] && !(fullMsg[i] < 65))
        {
            dcMsg[i] = fullMsg[i] + dkey;
            
            if(dcMsg[i] < 65 && dcMsg[i] > 39) //if else staement works add here.
            {
                dcMsg[i] += 26; 
            }
            else if(dcMsg[i] > 90 && dcMsg[i] < 116)
            {
                dcMsg[i] -= 26;
            }
        }
        else
        {
            dcMsg[i] = fullMsg[i];
        }
        i++;
    }
    out = fopen("dOut.txt", "w");
    fseek(out, 0, SEEK_SET);
    fprintf(out, "%s\n", dcMsg);
    printf("\nYour decrypted message is %s\n", dcMsg);
    fclose(in);
    fclose(out);
}

void sEncrypt()
{
    char eMsg[1024], fMsg[1024], dMsg[1024], spce[] = {" "};
    int key, i = 0;
    
    memset(eMsg,0,strlen(eMsg));
    memset(dMsg,0,strlen(dMsg));
    memset(fMsg,0,strlen(fMsg));

    printf("Please enter key\n");
    scanf("%d", &key);
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
                case 2: rDecrypt(); //funtion 2 here
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
