#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i <= height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avgvalue = round(((float)image[i][j].rgbtBlue + (float)image[i][j].rgbtRed + (float)image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtBlue = avgvalue;
            image[i][j].rgbtGreen = avgvalue;
            image[i][j].rgbtRed = avgvalue;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i <= height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int r = round((0.393 * (float)image[i][j].rgbtRed) + (0.769 * (float)image[i][j].rgbtGreen) +
                          (0.189 * (float)image[i][j].rgbtBlue));
            int g = round((0.349 * (float)image[i][j].rgbtRed) + (0.686 * (float)image[i][j].rgbtGreen) +
                          (0.168 * (float)image[i][j].rgbtBlue));
            int b = round((0.272 * (float)image[i][j].rgbtRed) + (0.534 * (float)image[i][j].rgbtGreen) +
                          (0.131 * (float)image[i][j].rgbtBlue));

            if (r > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = r;
            }
            if (g > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = g;
            }
            if (b > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = b;
            }

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE extra[height][width];
    int w = width - 1;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
           extra[i][j] = image[i][w - j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
           image[i][j] = extra[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE extra[height][width];
    float b, g, r;
    int tmp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tmp = 0;
            b = 0;
            g = 0;
            r = 0;
            for (int k = i - 1; k < i + 2; k++)
            {
                for (int l = j - 1; l < j + 2; l++)
                {
                    if ((k >= 0 && k < height) && (l >= 0 && l < width))
                    {
                        b += (float)image[k][l].rgbtBlue;
                        g += (float)image[k][l].rgbtGreen;
                        r += (float)image[k][l].rgbtRed;
                        tmp++;
                    }
                }
            }
            extra[i][j].rgbtBlue = round((float)b / tmp);
            extra[i][j].rgbtGreen = round((float)g / tmp);
            extra[i][j].rgbtRed = round((float)r / tmp);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = extra[i][j];
        }
    }
    return;
}
