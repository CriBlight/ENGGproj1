#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Auther: Christopher Baita C33289270


/*
# ROTATION CIPHER Encrypt (rEncrypt)
# Takes in a file called eIn.txt, encrypts it by subtracting a user given key value from the ascii values of the charaters, Puts the charaters to uppercase if they are lowercase, print to both stdout and a file.
# There is no return value (void) as the funtion prints the output to a file 
# Inputs are the file, and the key given by the user, output is the encrypted message both to a file called eOut.txt and to stdout
# Checks if key is a vaild number, does not take non int input.
*/
void rEncrypt()
{
    FILE *input, *output; //Initialise file streams for input and output
    int key, i = 0; //Initialise the key and primary loop counter
    char eMsg[1024], dMsg[1024], fMsg[1024], space[] = {" "}; //Initialise three charater arrays eMsg for the temp store, fMsg for peacing together the string and to store the full message, dMsg for storing the encrypted message.
    
    memset(eMsg,0,strlen(eMsg)); //Resets the memory of the arrays (clears out junk and previous data)
    memset(dMsg,0,strlen(dMsg)); //Resets the memory of the arrays (clears out junk and previous data)
    memset(fMsg,0,strlen(fMsg)); //Resets the memory of the arrays (clears out junk and previous data)

    do //loop that keeps getting user input till the input is vaild.
    {
    printf("Enter key :\n"); //promts the user for input
    scanf("%d", &key); //gets the input and assigns it to key
    if(key > 25 || key < 1) //check if the key is out range
    {
        printf("Invaild key\n"); //print error message if invaild
    }
    }while(key > 25 || key < 1);
    
    input = fopen("eIn.txt", "r"); //opens the file in read mode and assigns a pointer (location) to input.

    if(input == NULL) //If there is no file print an error message and exit to main.
    {
        perror("fopen()");
        return;
    }
    
    while(!feof(input)) //Takes input string by string until it reaches the end of the file adding a space each time
    {
        fscanf(input, "%s", eMsg); //takes a word in (until it reaches a new line or a space)
        strcat(fMsg, eMsg); //joins the word gotten above it to the full string
        strcat(fMsg, space); //addes a space after the word
    }

    printf("Input is : %s", fMsg); //Prints the input (for checking purposes)

    while(fMsg[i] != '\0') //Encrpytion loop for each letter the stops after the end of the string
	{
		if(fMsg[i] >= 97 && fMsg[i] <= 122) //if the letter is lowercase convert it to upper by subtracting 32 from its ASCII value.
        {
            fMsg[i] -= 32;
        }
                
		        
        if(fMsg[i] != space[0] && !(fMsg[i] < 65)) //checks if the charater is a number or a space if it is, print it as is. Otherwise subtract the key from the letters ASCII value.
        {
            dMsg[i] = fMsg[i] - key; 
                    
            if(dMsg[i] < 65 && dMsg[i] > 39) //if the letter, once the key is subtracted, falls out of the ASCII range of letters 26 is added so we come back into the range therefore a - 1 = z.
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
            dMsg[i] = fMsg[i]; //print without encryption
        }
                
        i++; //increments i to put the next letter though the loop untill the end of the string is reached
	}
        
    output = fopen("eOut.txt", "w"); //opens the file stream for output in writing mode and assigns a pointer to output.
    fseek(output, 0, SEEK_SET); //Sets the file seeker to the start of the file
    fprintf(output, "%s\n", dMsg); //prints the encrpted message to a file
    printf("\nYour encrypted message is : %s\n", dMsg); //prints the encrypted message to stdout
    fclose(input); //closes the file streams
    fclose(output);
}


/*
# ROTATION CIPHER Decrypt (rDecrypt)
# Takes in a file called dIn.txt decrypts it by adding a user given key to the ASCII values of the charaters. Puts the charaters to uppercase if they are lowercase, print to both stdout and a file
# There is no return value (void) as the funtion prints the output to a file.
# Inputs are the file, and the key given by the user, output is the encrypted message both to a file called dOut.txt and to stdout
# Checks if key is a vaild number, does not take non int input.
*/
void rDecrypt()
{
    FILE *in, *out; //Initialise file streams for input and output
    int i = 0, dkey; //Initialise the key and primary loop counter
    char inMsg[1024], fullMsg[1024], dcMsg[1024], spce[] = {" "}; //Initialise three charater arrays inMsg for the temp store, fullMsg for peacing together the string and to store the full message, dcMsg for storing the decrypted message.
    
    memset(inMsg,0,strlen(inMsg)); //Resets the memory of the arrays (clears out junk and previous data)
    memset(fullMsg,0,strlen(fullMsg)); //Resets the memory of the arrays (clears out junk and previous data)
    memset(dcMsg,0,strlen(dcMsg)); //Resets the memory of the arrays (clears out junk and previous data)

    do //loop that keeps getting user input till the input is vaild.
    {
    printf("Enter key :\n"); //promts the user for input
    scanf("%d", &dkey); //gets the input and assigns it to key
    if(dkey > 25 || dkey < 1) //check if the key is out range
    {
        printf("Invaild key\n"); //print error message if invaild
    }
    }while(dkey > 25 || dkey < 1);

    in = fopen("dIn.txt", "r"); //opens the file in read mode and assigns a pointer (location) to in.

    if(in == NULL) //If there is no file print an error message and exit to main.
    {
        perror("fopen()");
        return;
    }

    while(!feof(in)) //Takes input string by string until it reaches the end of the file adding a space each time
    {
        fscanf(in, "%s", inMsg); //takes a word in (until it reaches a new line or a space)
        strcat(fullMsg, inMsg); //joins the word gotten above it to the full string
        strcat(fullMsg, spce); //addes a space after the word
    }

    while(fullMsg[i] != '\0') //Encrpytion loop for each letter the stops after the end of the string
    {
        if(fullMsg[i] >= 97 && fullMsg[i] <= 122) //convert any lowercase letters to upper by subtracting 32 from its ASCII value
        {
            fullMsg[i] -= 32;
        }

        printf("Input is : %c", fullMsg[i]); //Prints the input (for checking purposes)

        if(fullMsg[i] != spce[0] && !(fullMsg[i] < 65)) //checks if the charater is a number or a space if it is, print it as is. Otherwise add the key to the letters ASCII value.
        {
            dcMsg[i] = fullMsg[i] + dkey;
            
            if(dcMsg[i] < 65 && dcMsg[i] > 39) //if the letter, once the key is subtracted, falls out of the ASCII range of letters 26 is subtracted so we come back into the range therefore z + 1 = a.
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
            dcMsg[i] = fullMsg[i]; //Prints without decryption
        }
        i++; //increments i to put the next letter though the loop untill the end of the string is reached
    }
    out = fopen("dOut.txt", "w"); //opens the file stream for output in writing mode and assigns a pointer to output.
    fseek(out, 0, SEEK_SET); //Sets the file seeker to the start of the file
    fprintf(out, "%s\n", dcMsg); //Prints the decrypted message to a file
    printf("\nYour decrypted message is %s\n", dcMsg); //Prints the decrypted to stdout
    fclose(in); //closes the file streams
    fclose(out);
}

/*
# SUBSTITUTION CIPHER Encrypt (sEncrypt)
# 
*/
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

/*
# SUBSTITUTION CIPHER Decrypt (sDecrypt)
# 
*/
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
    
    dMsg[i - 1] = '\0';
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
        scanf("%d", &opt); //gets the selection from the user and assigns it to opt
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
