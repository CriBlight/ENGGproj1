#include <stdio.h> //imports libarys used for funtions.
#include <stdlib.h>
#include <string.h>
//Auther: Christopher Baita C33289270


/*
# ROTATION CIPHER Encrypt (rEncrypt)
# Takes in a file called eIn.txt, encrypts it by subtracting a user given key value from the ascii values of the charaters in the message, Puts the charaters to uppercase if they are lowercase, prints the key and the message to both stdout and a file.
# There is no return value (void) as the funtion prints the output to a file. 
# Inputs are the file, and the key given by the user, output is the encrypted message both to a file called eOut.txt and to stdout, the key is also printed to the file.
# Checks if key is a vaild number, will crash on non int input.
*/
void rEncrypt()
{
    FILE *input, *output; //Initialise file streams for input and output
    int key, i = 0; //Initialise the key and primary loop counter
    char eMsg[1024], dMsg[1024], fMsg[1024], space[] = {" "}; //Initialise four charater arrays eMsg for the temp store, fMsg for peacing together the string and to store the full message, dMsg for storing the encrypted message and space to add a space.
    
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

    if(input == NULL) //If there is no file, print an error message and exit to main.
    {
        perror("fopen()");
        return;
    }
    
    while(!feof(input)) //Takes input string by string until it reaches the end of the file, adding a space each time.
    {
        fscanf(input, "%s", eMsg); //takes a word in (until it reaches a new line or a space)
        strcat(fMsg, eMsg); //joins the word gotten above it to the full string
        strcat(fMsg, space); //adds a space after the word
    }

    for(int f = 0; f < sizeof(fMsg); f++) //Removes the space placed at the end of the string
    {
        if(fMsg[f] == '\0')
        {
                fMsg[f - 1] = '\0';
                break;
        }
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
    dMsg[i] = '\0'; //assigns the null pointer to the end of the string (so the string will stop reading)     
    output = fopen("eOut.txt", "w"); //opens the file stream for output in writing mode and assigns a pointer to output.
    fseek(output, 0, SEEK_SET); //Sets the file seeker to the start of the file
    fprintf(output, "#%d\n", key); //prints the key to the file defined by a #
    fprintf(output, "%s", dMsg); //prints the encrpted message to a file
    printf("\nYour encrypted message is : %s\n", dMsg); //prints the encrypted message to stdout
    fclose(input); //closes the file streams
    fclose(output);
}


/*
# ROTATION CIPHER Decrypt (rDecrypt)
# Takes in a file called eOut.txt decrypts it by adding a key specified in the file header to the ASCII values of the charaters. Puts the charaters to uppercase if they are lowercase, print to both stdout and a file.
# There is no return value (void) as the funtion prints the output to a file.
# Inputs are the file and the key in the file header, output is the decrypted message both to a file called dOut.txt and to stdout
# Does not take non int input.
*/
void rDecrypt()
{
    FILE *in, *out; //Initialise file streams for input and output
    int i = 0, f = 1, dckey = 0; //Initialise the key and loop counter
    char inMsg[1024], fullMsg[1024], dcMsg[1024], spce[] = {' ', '\0'}, dkey[4]; //Initialise five charater arrays inMsg for the temp store, fullMsg for peacing together the string and to store the full message, dcMsg for storing the decrypted message, space to add a space, and key to store the key.
    
    memset(inMsg,0,strlen(inMsg)); //Resets the memory of the arrays (clears out junk and previous data)
    memset(fullMsg,0,strlen(fullMsg)); //Resets the memory of the arrays (clears out junk and previous data)
    memset(dcMsg,0,strlen(dcMsg)); //Resets the memory of the arrays (clears out junk and previous data)
    memset(dkey,0,strlen(dkey)); //Resets the memory of the arrays (clears out junk and previous data)

    in = fopen("eOut.txt", "r"); //opens the file in read mode and assigns a pointer (location) to in.

    if(in == NULL) //If there is no file print an error message and exit to main.
    {
        perror("fopen()");
        return;
    }

    fscanf(in, "%s", dkey); //Scans the first word of the file.

    if(dkey[0] == '#') //if the first word starts with a #, prints the key for checking.
    {
        printf("Key : %s\n", dkey);
    }
    else //if no key is found, the user is prompted for a key
    {
        printf("No file key found\n");
        printf("Enter key : ");
        scanf("%s", &dkey);
        fseek(in, 0, SEEK_SET); //the fseek point is then set back to the start of the file to read the message if the was no key.
    }
    
    if(dkey[0] == '#') //if the first word starts with a #, everything in the word (before a space or new line) is assigned to key
    {
        while(dkey[f] != '\0') //loop to remove the # at the start the key
        {
            dkey[f - 1] = dkey[f]; //shifts all charaters one to the left
            f++;
        }
        dkey[f - 1] = '\0'; //Assigns the null pointer to the end of the array
    }

    sscanf(dkey, "%d", &dckey); //coverts the key to an intiger.
    
    while(!feof(in)) //Takes input string by string until it reaches the end of the file adding a space each time
    {
        fscanf(in, "%s", inMsg); //takes a word in (until it reaches a new line or a space)
        strcat(fullMsg, inMsg); //joins the word gotten above it to the full string
        strcat(fullMsg, spce); //adds a space after the word
    }
    
    
    printf("Input is : %s", fullMsg); //Prints the input (for checking purposes)

    while(fullMsg[i] != '\0') //Encrpytion loop for each letter the stops after the end of the string
    {
        if(fullMsg[i] >= 97 && fullMsg[i] <= 122) //convert any lowercase letters to upper by subtracting 32 from its ASCII value
        {
            fullMsg[i] -= 32;
        }

        if(fullMsg[i] != spce[0] && !(fullMsg[i] < 65)) //checks if the charater is a number or a space if it is, print it as is. Otherwise add the key to the letters ASCII value.
        {
            dcMsg[i] = fullMsg[i] + dckey;
            
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
    dcMsg[i] = '\0'; //assigns the null pointer to the end of the string (so the string will stop reading)
    out = fopen("dOut.txt", "w"); //opens the file stream for output in writing mode and assigns a pointer to output.
    fseek(out, 0, SEEK_SET); //Sets the file seeker to the start of the file
    fprintf(out, "%s\n", dcMsg); //Prints the decrypted message to a file
    printf("\nYour decrypted message is %s\n", dcMsg); //Prints the decrypted to stdout
    fclose(in); //closes the file streams
    fclose(out);
}

/*
# SUBSTITUTION CIPHER Encrypt (sEncrypt)
# Takes in a file called sIn.txt decrypts it by substituting a letter with another letter, print to both a file called sOut.txt and stdout, the key is also printed to the file with a #.
# There is no return value (void) as the funtion prints the output to a file.
# Input is the file, the key can either be a user input or a default key (to save time). Output is the decrypted message both to a file called sOut.txt and to stdout.
# will accept lowercase key and convert to upper. however if key is not in correct format (26 letters in a row) encryption will either be junk or not take place.
*/
void sEncrypt()
{
    FILE *in, *out; //Initialise file streams for input and output
    char eMsg[1024], fMsg[1024], dMsg[1024], spce[] = {" "}, key[27], pkey[] = {'U','W','G','T','L','Z','Y','X','J','M','A','K','S','B','O','C','I','N','Q','P','E','V','F','H','D','R','\0'}; //Initialise five charater arrays eMsg for the temp store, fMsg for peacing together the string and to store the full message, dMsg for storing the encrypted message, space for adding a space and key to store the key.(KEY = uwgtlzyxjmaksbocinqpevfhdr)
    int i = 0, opt = 0, x = 0; //Primary loop counter
    
    memset(eMsg,0,strlen(eMsg));//Resets the memory of the arrays (clears out junk and previous data) 
    memset(dMsg,0,strlen(dMsg));//Resets the memory of the arrays (clears out junk and previous data)
    memset(fMsg,0,strlen(fMsg));//Resets the memory of the arrays (clears out junk and previous data)
    memset(key,0,strlen(key));//Resets the memory of the arrays (clears out junk and previous data)

    do //gets key from either user or default key (did this to save some time).
    {
        printf("Enter 1 to use the default key\nEnter 2 to specify a custom key\nOption : ");
        scanf("%d", &opt);
        if(opt == 1)
        {
            strcat(key, pkey); //copys default key to used key
        }
        else if(opt == 2)
        {
            printf("Enter key : ");
            scanf("%s", &key); //user inputs key
        }
        else
        {
            printf("Invaild option\n"); //prints error if invaild opt.
        }
        
    }while(opt != 1 && opt != 2);
    
    while (key[x] != '\0') //converts any lowercase letter to uppercase by subtracting 32 from there ascii value
    {
        if(key[x] >= 97 && key[x] <= 122)
        {
            key[x] -= 32;
        }
        x++;
    }
    
    in = fopen("sIn.txt", "r"); //opens sIn.txt in reading mode and assigns a pointer to it stored in "in"

    if(in == NULL) //if the file is not found it will show an error message and return to main
    {
        perror("fopen()");
        return;
    }
 

    while(!feof(in)) //Takes input string by string until it reaches the end of the file adding a space each time
    {
        fscanf(in, "%s", eMsg); //takes a word in (until it reaches a new line or a space)
        strcat(fMsg, eMsg); //joins the word gotten above it to the full string
        strcat(fMsg, spce); //adds a space after the word
    }

    for(int f = 0; f < sizeof(fMsg); f++) //Removes the space placed at the end of the string
    {
        if(fMsg[f] == '\0')
        {
                fMsg[f - 1] = '\0';
                break;
        }
    }

    printf("Input is : %s", fMsg); //Prints input (for checking purposes)

    while(fMsg[i] != '\0') //Encrpytion loop for each letter the stops after the end of the string
    {
        if(fMsg[i] >= 97 && fMsg[i] <= 122) //converts anything in lowercase to uppercase.
        {
            fMsg[i] -= 32;
        }
        
        switch(fMsg[i]) //Swaps each letter in the message with the corresponding letter in the key
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
        i++; //increments i to get though the entire string
    }
    
    dMsg[i] = '\0'; //assigns the null pointer to the end of the string (so the string will stop reading)
    out = fopen("sOut.txt", "w");  //opens the file stream for output and assins the pointer to out
    fseek(out, 0, SEEK_SET); //sets the file seeker to the start of the file
    fprintf(out, "#%s\n", key); //print a '#' followed by the key to the file then a new line charater
    fprintf(out, "%s", dMsg); //Prints the Encrypted message to the file
    printf("\nYour encrypted message is %s\n", dMsg); //Prints the encrypted message to stdout (checking purposes)
    fclose(in); //closes the file streams the they are accessable to other funtions
    fclose(out);
}

/*
# SUBSTITUTION CIPHER Decrypt (sDecrypt)
# Takes in a file called sOut.txt and the key in the file (determined by a # at the start). Then decrypts it by substituting the letter in the key with the corresponding alphabet letter, prints to both a file called sdOut.txt and stdout.
# There is no return value (void) as the funtion prints the output to a file.
# Input is the file, which includes the key (determined by a #). Output is the decrypted message both to a file called sdOut.txt and to stdout
# will accept lowercase key and convert to upper. however if key is not in correct format (26 letters in a row) encryption will either be junk or not take place.
*/
void sDecrypt()
{
    FILE *in, *out; //Initialise file streams for input and output
    char eMsg[1024], fMsg[1024], dMsg[1024], spce[] = {" "}, key[28];//Initialise five charater arrays eMsg for the temp store, fMsg for peacing together the string and to store the full message, dMsg for storing the encrypted message, space for adding a space and key to store the key.
    int i = 0, ki = 0, x = 1, c = 0; //Initialise loop varaibles
    
    memset(eMsg,0,strlen(eMsg)); //clears the memory
    memset(dMsg,0,strlen(dMsg));
    memset(fMsg,0,strlen(fMsg));

    in = fopen("sOut.txt", "r"); //opens the file stream for input and assings it to in
    
    if(in == NULL) //Prints an error message if there is no file
    {
        perror("fopen()");
        return;
    }

    fscanf(in, "%s", key); //Scans the word line of the file

    if(key[ki] == '#') //if the first word starts with a #, prints the key for checking
    {
        printf("Key : %s\n", key);
    }
    else //if no key is found, the user is prompted for a key
    {
        printf("No file key found\n");
        printf("Enter key : ");
        scanf("%s", &key);
        fseek(in, 0, SEEK_SET); //the fseek point is then set back to the start of the file to read the message.
    }
    
    if(key[0] == '#') //if the first word starts with a #, everything in the word (before a space or new line) is assigned to key
    {
        while(key[x] != '\0') //loop to remove the # at the start the key
        {
            key[x - 1] = key[x]; //shifts all charaters one to the left
            x++;
        }
        key[x - 1] = '\0'; //Assigns the null pointer to the end of the array
    }

    x = 0; //re-initialise x for a new loop
    
    while (key[x] != '\0') //converts any lowercase letter to uppercase by subtracting 32 from there ascii value
    {
        if(key[x] >= 97 && key[x] <= 122)
        {
            key[x] -= 32;
        }
        x++;
    }
    

    while(!feof(in)) //Takes input string by string until it reaches the end of the file adding a space each time
    {
        fscanf(in, "%s", eMsg); //takes a word in (until it reaches a new line or a space)
        strcat(fMsg, eMsg); //joins the word gotten above it to the full string
        strcat(fMsg, spce); //adds a space after the word
    }
    
    printf("Input is : %s", fMsg); //Prints input for checking

    while(fMsg[i] != '\0') //swaps each key letter with the correct alphabet letter
    {
        
        if(fMsg[i] >= 97 && fMsg[i] <= 122) //converts any lowercase letters to  uppercase
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
        else //If the charater is not a letter leave it as it is
        {
            dMsg[i] = fMsg[i];
        }
        i++; //increments i so that the next letter will be decrypted.
    }
    
    dMsg[i - 1] = '\0'; //adds the null pointer to the end of the string
    out = fopen("sdOut.txt", "w"); //opens the filestream for output and assins it to out
    fseek(out, 0, SEEK_SET); //sets the file seeker to the start of the file
    fprintf(out, "%s", dMsg); //prints the decrypted message to the file
    printf("\nYour decrypted message is %s\n", dMsg); //prints the decrypted message to stdout
    fclose(in); //closes the file streams so they can be used by other funtions.
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
