#ifndef FOV_H
#define FOV_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gamedefinitions.h"

#define PI 3.141592

void printMatrix(int **A, int height, int width)
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

void renderFOV(char ActualCave[SCREEN_HEIGHT][SCREEN_LENGTH], char RenderedCave[SCREEN_HEIGHT][SCREEN_LENGTH], Player player){
    // Declara o campo verdadeiro e o campo que o player consegue ver
    int posX = player.coord.x;
    int posY = player.coord.y;
    int visionDistance = 10;

    int partitions = 20;

    float dA = PI / partitions;

    float sx;
    float sy;
    int dx;
    int dy;
    int x;
    int y;

    for (float currentAngle = 0.0; currentAngle < 2.1 * PI; currentAngle += dA)
    {
        sx = visionDistance * cos(currentAngle);
        sy = visionDistance * sin(currentAngle);

        dx = (int)(sx / abs(sx));
        dy = (int)(sy / abs(sy));

        x = (int)ceil(abs(sx));
        y = (int)ceil(abs(sy));
        //printf("(%d, %d)\n", x, y);

        for (int i = 0; abs(i) < y; i += dy)
        {
            for (int j = 0; abs(j) < x; j += dx)
            {
                //printf("(%d, %d)\n", posY + i, posX + j);
                RenderedCave[posY + i][posX + j] = ActualCave[posY + i][posX + j];
            }
        }
    }
}

#endif