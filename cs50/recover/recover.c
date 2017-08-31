
/*
int add(int a, int b)
{
    return a + b;
}

void my_read(FILE* f)
int fread(char* buffer, int size, int count, FILE* file);

add(1, int); // wrong: int is not a variable
add(1, argc); // correct: argc is a variable, with correct type int
add(1, inptr); // wrong: inptr is a FILE* not an int

my_read(infile); // wrong : infile is a string(char*), not a FILE*
my_read(FILE*); // wrong: FILE* is a type, not a variable
my_read(inptr); // correct: inptr is a variable of type FILE*
*/

//int get_file_size(FILE* myfile);

#include <stdio.h>
#include <stdbool.h>

int main(int argc, const char** argv)
{
    // 1. Open input image file (card.raw)

    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover infile \n");
        return 1;
    }

    // remember filenames
    const char* inFileName = argv[1]; // inFileName = "card.raw"
    FILE* inFilePointer = fopen(inFileName, "r");

    if (inFilePointer == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", inFileName);
        return 2;
    }

    FILE* outFilePointer = NULL;

    bool iCameAfterTheHeader = false;
    int fileNumber = 0;

    // 2. Find next jpeg
    while(true)
    {
        // 1. check for the header in our image file (inptr)
        unsigned char buffer[512];
        int bytesRead = fread(buffer, 1, 512, inFilePointer);

        if(bytesRead < 512)
        {
            break;
        }

        bool iFoundTheHeader = (buffer[0]== 0xff &&
            buffer[1]== 0xd8 &&
            buffer[2]== 0xff &&
            (buffer[3] & 0xf0) == 0xe0);

        if (iFoundTheHeader)
        {
            // 2. if true, we found an image, start saving it
            char outFileName[8]; // outFileName = ""

            sprintf(outFileName, "%00i.jpg", fileNumber); // outFileName = "000.jpg"

            // 3.     open a new output file
            outFilePointer = fopen(outFileName, "w");

            if (outFilePointer == NULL)
            {
                fprintf(stderr, "Could not open %s.\n", outFileName);
                return 3;
            }

            fileNumber = fileNumber + 1;
        }

        bool iShouldWriteToTheOutputFile = (iFoundTheHeader) || (iCameAfterTheHeader);

        if (iShouldWriteToTheOutputFile)
        {
            // 3.5    save the current contents of the buffer
            fwrite(buffer, 1, 512, outFilePointer);
            iCameAfterTheHeader = true;
        }
    }

    return 0;
}



