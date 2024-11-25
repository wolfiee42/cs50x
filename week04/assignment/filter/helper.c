#include "helpers.h"
#include <math.h>
#include <stdio.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int cal = round((float)(image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3);
            image[i][j].rgbtBlue = cal;
            image[i][j].rgbtGreen = cal;
            image[i][j].rgbtRed = cal;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
                            .189 * image[i][j].rgbtBlue);
            int green = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                              .168 * image[i][j].rgbtBlue);
            int blue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                             .131 * image[i][j].rgbtBlue);
            if (red < 255)
            {
                image[i][j].rgbtRed = red;
            }
            else
            {
                image[i][j].rgbtRed = 255;
            }

            if (green < 255)
            {
                image[i][j].rgbtGreen = green;
            }
            else
            {
                image[i][j].rgbtGreen = 255;
            }

            if (blue < 255)
            {
                image[i][j].rgbtBlue = blue;
            }
            else
            {
                image[i][j].rgbtBlue = 255;
            }
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            int reflect = width - j - 1;

            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][reflect];
            image[i][reflect] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {

            int totalRed = 0;
            int totalGreen = 0;
            int totalBlue = 0;
            int validPixels = 0;

            for (int dRow = -1; dRow <= 1; dRow++)
            {
                for (int dCol = -1; dCol <= 1; dCol++)
                {
                    int neighborRow = row + dRow;
                    int neighborCol = column + dCol;
                    if (neighborRow >= 0 && neighborRow < height && neighborCol >= 0 &&
                        neighborCol < width)
                    {
                        totalRed += temp[neighborRow][neighborCol].rgbtRed;
                        totalGreen += temp[neighborRow][neighborCol].rgbtGreen;
                        totalBlue += temp[neighborRow][neighborCol].rgbtBlue;

                        validPixels++;
                    }
                }
            }
            image[row][column].rgbtRed = round((float)totalRed / validPixels);
            image[row][column].rgbtGreen = round((float)totalGreen / validPixels);
            image[row][column].rgbtBlue = round((float)totalBlue / validPixels);
        }
    }
    return;
}