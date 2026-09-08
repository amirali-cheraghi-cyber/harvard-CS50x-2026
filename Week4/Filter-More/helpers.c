#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int r = image[i][j].rgbtRed;
            int g = image[i][j].rgbtGreen;
            int b = image[i][j].rgbtBlue;

            int average = (int)((r + g + b) / 3.0 + 0.5);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
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
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sum_red = 0;
            int sum_green = 0;
            int sum_blue = 0;
            int count = 0;
            
            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    int new_i = i + x;
                    int new_j = j + y;
                    
                    if (new_i >= 0 && new_i < height && new_j >= 0 && new_j < width)
                    {
                        sum_red = sum_red + copy[new_i][new_j].rgbtRed;
                        sum_green = sum_green + copy[new_i][new_j].rgbtGreen;
                        sum_blue = sum_blue + copy[new_i][new_j].rgbtBlue;
                        count = count + 1;
                    }
                }
            }
            
            image[i][j].rgbtRed = (int)((float)sum_red / count + 0.5);
            image[i][j].rgbtGreen = (int)((float)sum_green / count + 0.5);
            image[i][j].rgbtBlue = (int)((float)sum_blue / count + 0.5);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    
    int gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    
    int gy[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float gx_red = 0;
            float gy_red = 0;
            float gx_green = 0;
            float gy_green = 0;
            float gx_blue = 0;
            float gy_blue = 0;
            
            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    int new_i = i + x;
                    int new_j = j + y;
                    
                    if (new_i >= 0 && new_i < height && new_j >= 0 && new_j < width)
                    {
                        gx_red = gx_red + copy[new_i][new_j].rgbtRed * gx[x + 1][y + 1];
                        gy_red = gy_red + copy[new_i][new_j].rgbtRed * gy[x + 1][y + 1];
                        
                        gx_green = gx_green + copy[new_i][new_j].rgbtGreen * gx[x + 1][y + 1];
                        gy_green = gy_green + copy[new_i][new_j].rgbtGreen * gy[x + 1][y + 1];
                        
                        gx_blue = gx_blue + copy[new_i][new_j].rgbtBlue * gx[x + 1][y + 1];
                        gy_blue = gy_blue + copy[new_i][new_j].rgbtBlue * gy[x + 1][y + 1];
                    }
                }
            }
            
            int red = (int)(sqrt(gx_red * gx_red + gy_red * gy_red) + 0.5);
            int green = (int)(sqrt(gx_green * gx_green + gy_green * gy_green) + 0.5);
            int blue = (int)(sqrt(gx_blue * gx_blue + gy_blue * gy_blue) + 0.5);
            
            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }
            
            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
    }
    return;
}
