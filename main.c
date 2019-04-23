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

        strcat(fMsg, eMsg);

        while(!feof(input))
        {
            fscanf(input, "%s", eMsg);
            strcat(fMsg, eMsg);
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
    FILE *in, *out; //add a file io for key
    char eMsg[1024], fMsg[1024], dMsg[1024], spce[] = {" "}, key[] = {'U','W','G','T','L','Z','Y','X','J','M','A','K','S','B','O','C','I','N','Q','P','E','V','F','H','D','R','\0'}; //KEY = uwgtlzyxjmaksbocinqpevfhdr
    int i = 0;
    
    memset(eMsg,0,strlen(eMsg));
    memset(dMsg,0,strlen(dMsg));
    memset(fMsg,0,strlen(fMsg));

    in = fopen("sIn.txt", "r");

    if(in == NULL)
    {
        perror("fopen()");
        return;
    }

    strcat(fMsg, eMsg);

    while(!feof(in))
    {
        fscanf(in, "%s", eMsg);
        strcat(fMsg, eMsg);
        strcat(fMsg, spce);
    }

    printf("Input is : %s", fMsg);

    while(fMsg[i] != '\0')
    {
        if(fMsg[i] >= 97 && fMsg[i] <= 122)
        {
            fMsg[i] -= 32;
        }
        
        switch(fMsg[i])
        {
            case 'A' : dMsg[i] = key[0];
            break;
            case 'B' : dMsg[i] = key[1];
            break;
            case 'C' : dMsg[i] = key[2];
            break;
            case 'D' : dMsg[i] = key[3];
            break;
            case 'E' : dMsg[i] = key[4];
            break;
            case 'F' : dMsg[i] = key[5];
            break;
            case 'G' : dMsg[i] = key[6];
            break;
            case 'H' : dMsg[i] = key[7];
            break;
            case 'I' : dMsg[i] = key[8];
            break;
            case 'J' : dMsg[i] = key[9];
            break;
            case 'K' : dMsg[i] = key[10];
            break;
            case 'L' : dMsg[i] = key[11];
            break;
            case 'M' : dMsg[i] = key[12];
            break;
            case 'N' : dMsg[i] = key[13];
            break;
            case 'O' : dMsg[i] = key[14];
            break;
            case 'P' : dMsg[i] = key[15];
            break;
            case 'Q' : dMsg[i] = key[16];
            break;
            case 'R' : dMsg[i] = key[17];
            break;
            case 'S' : dMsg[i] = key[18];
            break;
            case 'T' : dMsg[i] = key[19];
            break;
            case 'U' : dMsg[i] = key[20];
            break;
            case 'V' : dMsg[i] = key[21];
            break;
            case 'W' : dMsg[i] = key[22];
            break;
            case 'X' : dMsg[i] = key[23];
            break;
            case 'Y' : dMsg[i] = key[24];
            break;
            case 'Z' : dMsg[i] = key[25];
            break;
            default : dMsg[i] = fMsg[i];
            break;
        }
        i++;
    }
    out = fopen("sOut.txt", "w");
    fseek(out, 0, SEEK_SET);
    fprintf(out, "%s\n", dMsg);
    printf("\nYour encrypted message is %s\n", dMsg);
    fclose(in);
    fclose(out);
}

void sDecrypt()
{
    FILE *in, *out; //add a file io for key
    char eMsg[1024], fMsg[1024], dMsg[1024], spce[] = {" "}, key[] = {'U','W','G','T','L','Z','Y','X','J','M','A','K','S','B','O','C','I','N','Q','P','E','V','F','H','D','R','\0'}; //KEY = uwgtlzyxjmaksbocinqpevfhdr
    int i = 0;
    
    memset(eMsg,0,strlen(eMsg));
    memset(dMsg,0,strlen(dMsg));
    memset(fMsg,0,strlen(fMsg));

    in = fopen("sdIn.txt", "r");

    if(in == NULL)
    {
        perror("fopen()");
        return;
    }

    strcat(fMsg, eMsg);

    while(!feof(in))
    {
        fscanf(in, "%s", eMsg);
        strcat(fMsg, eMsg);
        strcat(fMsg, spce);
    }

    printf("Input is : %s", fMsg);

    while(fMsg[i] != '\0')
    {
        if(fMsg[i] >= 97 && fMsg[i] <= 122)
        {
            fMsg[i] -= 32;
        }
        
        if(fMsg[i] == key[0])
        {
            dMsg[i] = 'A';
        }
        else if (fMsg[i] == key[1])
        {
            dMsg[i] = 'B';
        }
        else if (fMsg[i] == key[2])
        {
            dMsg[i] = 'C';
        }
        else if (fMsg[i] == key[3])
        {
            dMsg[i] = 'D';
        }
        else if (fMsg[i] == key[4])
        {
            dMsg[i] = 'E';
        }
        else if (fMsg[i] == key[5])
        {
            dMsg[i] = 'F';
        }
        else if (fMsg[i] == key[6])
        {
            dMsg[i] = 'G';
        }
        else if (fMsg[i] == key[7])
        {
            dMsg[i] = 'H';
        }
        else if (fMsg[i] == key[8])
        {
            dMsg[i] = 'I';
        }
        else if (fMsg[i] == key[9])
        {
            dMsg[i] = 'J';
        }
        else if (fMsg[i] == key[10])
        {
            dMsg[i] = 'K';
        }
        else if (fMsg[i] == key[11])
        {
            dMsg[i] = 'L';
        }
        else if (fMsg[i] == key[12])
        {
            dMsg[i] = 'M';
        }
        else if (fMsg[i] == key[13])
        {
            dMsg[i] = 'N';
        }
        else if (fMsg[i] == key[14])
        {
            dMsg[i] = 'O';
        }
        else if (fMsg[i] == key[15])
        {
            dMsg[i] = 'P';
        }
        else if (fMsg[i] == key[16])
        {
            dMsg[i] = 'Q';
        }
        else if (fMsg[i] == key[17])
        {
            dMsg[i] = 'R';
        }
        else if (fMsg[i] == key[18])
        {
            dMsg[i] = 'S';
        }
        else if (fMsg[i] == key[19])
        {
            dMsg[i] = 'T';
        }
        else if (fMsg[i] == key[20])
        {
            dMsg[i] = 'U';
        }
        else if (fMsg[i] == key[21])
        {
            dMsg[i] = 'V';
        }
        else if (fMsg[i] == key[22])
        {
            dMsg[i] = 'W';
        }
        else if (fMsg[i] == key[23])
        {
            dMsg[i] = 'X';
        }
        else if (fMsg[i] == key[24])
        {
            dMsg[i] = 'Y';
        }
        else if (fMsg[i] == key[25])
        {
            dMsg[i] = 'Z';
        }
        else
        {
            dMsg[i] = fMsg[i];
        }
        i++;
    }
    out = fopen("sdOut.txt", "w");
    fseek(out, 0, SEEK_SET);
    fprintf(out, "%s\n", dMsg);
    printf("\nYour decrypted message is %s\n", dMsg);
    fclose(in);
    fclose(out);
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
                case 3: sEncrypt();
                break;
                case 4: sDecrypt();
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
