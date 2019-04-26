#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sDecrpty()
{
    FILE *in, *out; //add a file io for key
    char eMsg[1024], fMsg[1024], dMsg[1024], spce[] = {" "}, key[28]; //key[] = {'U','W','G','T','L','Z','Y','X','J','M','A','K','S','B','O','C','I','N','Q','P','E','V','F','H','D','R','\0'}; //KEY = uwgtlzyxjmaksbocinqpevfhdr
    int i = 0, ki = 0, x = 1;
    
    memset(eMsg,0,strlen(eMsg));
    memset(dMsg,0,strlen(dMsg));
    memset(fMsg,0,strlen(fMsg));

    in = fopen("test.txt", "r");
    
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
    fprintf(out, "#%s\n", key);
    fprintf(out, "%s\n", dMsg);
    printf("\nYour decrypted message is %s\n", dMsg);
    fclose(in);
    fclose(out);
}




void main()
{
    sDecrpty();
}

/*char getKey(FILE *in)
{
    int i = 0;
    char key[27];
    if(key[i] == '#')
    {
        i++;
        while(key[i] != 10)
        {
            fscanf(in, "%c", key[i]);
            i++;
        }

    }
    else
    {
        printf("No file key found\n");
        printf("Enter key : ");
        scanf("%s", &key);
    }
    printf("%s", key);
    return key;
} */

