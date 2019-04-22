#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
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

    while(!feof(in))
    {
        strcat(fMsg, eMsg);
        fscanf(in, "%s", eMsg);
        strcat(fMsg, spce);
    }

    printf("%s", fMsg);

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