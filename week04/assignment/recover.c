#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check for correct usage
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the forensic image file for reading
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file %s.\n", argv[1]);
        return 1;
    }

    // Declare necessary variables
    FILE *img = NULL;    // Pointer to the current JPEG file
    uint8_t buffer[512]; // Buffer to read 512 bytes
    int imgNumber = 0;   // Counter for JPEG file names
    char filename[8];    // Buffer for file names
    int starting = 0;    // Flag to indicate if JPEG recovery has started

    // Read the file in 512-byte blocks
    while (fread(buffer, 1, 512, card) == 512)
    {
        // Check if the block contains a JPEG signature
        if (buffer[0] == 0xFF && buffer[1] == 0xD8 && buffer[2] == 0xFF &&
            (buffer[3] >= 0xE0 && buffer[3] <= 0xEF))
        {
            // If a new JPEG starts, close the previous one (if open)
            if (starting == 1)
            {
                fclose(img);
            }

            // Create a new JPEG file
            sprintf(filename, "%03i.jpg", imgNumber++);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                printf("Could not create file %s.\n", filename);
                fclose(card);
                return 1;
            }

            // Update the starting flag
            starting = 1;

            // Write the current block to the new JPEG file
            fwrite(buffer, 1, 512, img);
        }
        else if (starting == 1)
        {
            // Continue writing to the current JPEG file if recovery has started
            fwrite(buffer, 1, 512, img);
        }
    }

    // Close any remaining open files
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(card);

    return 0;
}
