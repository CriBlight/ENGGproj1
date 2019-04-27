#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Current Build = Tio
//Auther: Christopher Baita C33289270


/*
# ROTATION CIPHER (rEncrypt) #
# Takes in a file, encrypts it by subtracting a user given key value from the ascii values of the charaters, Puts the charaters to uppercase if they are lowercase.
# There is no return value as the funtion prints the output to a file
# Inputs are the file and the key given by the user, output is the encrypted message both to a file and to stdout
# Check if key is a vaild number, does not take non int input.
*/
void rEncrypt()
{
    FILE *input, *output;
    int key, i = 0;
    char eMsg[1024], dMsg[1024], fMsg[1024], space[] = {" "};
    
    memset(eMsg,0,strlen(eMsg));
    memset(dMsg,0,strlen(dMsg));
    memset(fMsg,0,strlen(fMsg));

    do
    {
    printf("Enter key :\n");
    scanf("%d", &key);
    if(key > 25 || key < 1)
    {
        printf("Invaild key\n");
    }
    }while(key > 25 || key < 1);
    
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

    printf("Input is : %s", fMsg);

    while(fMsg[i] != '\0')
	{
		if(fMsg[i] >= 97 && fMsg[i] <= 122)
        {
            fMsg[i] -= 32;
        }
                
        //printf("Input is : %c", fMsg[i]);
		        
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
    printf("\nYour encrypted message is : %s\n", dMsg);
    fclose(input);
    fclose(output);
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

    strcat(fullMsg, inMsg);

    while(!feof(in))
    {
        fscanf(in, "%s", inMsg);
        strcat(fullMsg, inMsg);
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

    for(int f = 0; f < sizeof(fMsg); f++)
    {
        if(fMsg[f] == '\0')
        {
                fMsg[f - 1] = '\0';
                break;
        }
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
    
    dMsg[i] = '\0';
    out = fopen("sOut.txt", "w");
    fseek(out, 0, SEEK_SET);
    fprintf(out, "#%s\n", key);
    fprintf(out, "%s", dMsg);
    printf("\nYour encrypted message is %s\n", dMsg);
    fclose(in);
    fclose(out);
}

void sDecrypt()
{
    FILE *in, *out; //add a file io for key
    char eMsg[1024], fMsg[1024], dMsg[1024], spce[] = {" "}, key[28]; //key[] = {'U','W','G','T','L','Z','Y','X','J','M','A','K','S','B','O','C','I','N','Q','P','E','V','F','H','D','R','\0'}; //KEY = uwgtlzyxjmaksbocinqpevfhdr
    int i = 0, ki = 0, x = 1, c = 0;
    
    memset(eMsg,0,strlen(eMsg));
    memset(dMsg,0,strlen(dMsg));
    memset(fMsg,0,strlen(fMsg));

    in = fopen("sOut.txt", "r");
    
    if(in == NULL)
    {
        perror("fopen()");
        return;
    }

    fscanf(in, "%s", key);

    if(key[ki] == '#')
    {
        printf("%s\n", key);
    }
    else
    {
        printf("No file key found\n");
        printf("Enter key : ");
        scanf("%s", &key);
        fseek(in, 0, SEEK_SET);
    }
    
    if(key[0] == '#')
    {
        while(key[x] != '\0')
        {
            key[x - 1] = key[x];
            x++;
        }
        key[x - 1] = '\0';
    }

    x = 0;
    
    while (key[x] != '\0')
    {
        if(key[x] >= 97 && key[x] <= 122)
        {
            key[x] -= 32;
        }
        x++;
    }

    printf("%s\n", key);
    

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
    fprintf(out, "#%s\n", key);
    fprintf(out, "%s", dMsg);
    printf("\nYour decrypted message is %s\n", dMsg);
    fclose(in);
    fclose(out);
}


/*
# MAIN #
# Runs when the program starts, Function prints the main menu and promts the user for input.
# Takes option number for input, returns 0
# Is an infinite loop so all functions can be used in succession untill exit key is entred (0)
# Checks if the number is out of range, however will not take non intiger input.
*/
int main()
{

    int opt = 0; //initialise varaible for menu choice 
    do //creates an infinite loop which will always return to the menu unless the user enters 0
    {

        printf("Please Select an option from below: \n 1: Encryption using roation cipher\n 2: Decryption using roation cipher\n 3: Encryption using subsitution cipher\n 4: Decryption using subsitution cipher\n 0: Exit \nInput: "); //prints the selection options
        scanf("%d", &opt); //gets the selection from the user
        if(opt > 0 && opt < 5) //checks if the user enters a vaild input
        {
            switch(opt) //
            {
                case 1: rEncrypt(); //calls the Rotation encrypt function
                break; //breaks from the switch statment so that no other functions are called
                case 2: rDecrypt(); //calls the Rotation decrypt function
                break; //breaks from the switch statment so that no other functions are called
                case 3: sEncrypt(); //calls the subsitution encrypt function
                break; //breaks from the switch statment so that no other functions are called
                case 4: sDecrypt(); //calls the subsitution encrypt function
                break; //breaks from the switch statment so that no other functions are called
            }
        }
        else if(opt == 0) //If the user entred 0, the program will exit.
        {
            exit(EXIT_SUCCESS); //exit
        }
        else //if anything else was entered print an error message.
        {
            printf("Invalid Input please select an option from the options provided\n"); //warns the user to choose a vaild input
        }

    } while(1); //infinite
    return 0;
}
