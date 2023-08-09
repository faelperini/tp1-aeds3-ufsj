#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "points.h"
#include "files.h"

Point *points;
int Npoints, result;
float A, B;

float getCoefficient(float x2, float y2, float x1, float y1) {
    float m;
    return m = (y2 - y1) / (x2 - x1);
}

int comparator(const void *a, const void *b) {
    if (((Point *)a)->y > ((Point *)b)->y) {
      return 1;
   } else if (((Point *)a)->y < ((Point *)b)->y) {
      return -1;
   } else {
      return 0;
   }
}

void solve() {
    result = 1;
    float mA, mB;

    qsort(points, Npoints, sizeof(Point), comparator);
    int *vector = malloc(sizeof(int) * (Npoints + 1));
    for(int i = 0; i < Npoints; i++) {
        vector[i] = 1;
    }

    for(int n = 0; n < Npoints; n++) {
        mA = getCoefficient(A, 0, points[n].x, points[n].y);
        mB = getCoefficient(B, 0, points[n].x, points[n].y);

        for(int i = n - 1; i >= 0; i--) {
            if(vector[i] >= vector[n]){
                if(check(mA, mB, points[n].x, points[n].y, points[i].x, points[i].y)) {
                    vector[n] = vector[i] + 1;
                    if(vector[n] > result) {
                        result = vector[n];
                        break;
                    }
                }
            }
        }
    }
    free(vector);
}

int check(float mA, float mB, float x1, float y1, float x2, float y2) {
    float m;

    if(mA < 0) {
        m = getCoefficient(x2, y2, x1, y1);
        if(x1 < x2 && m < mB && m > mA) {
            return 1;
        }
        return 0;
    }else if (mB > 0) {
        m = getCoefficient(x1, y1, x2, y2);
        if(x1 > x2 && m < mB && m > mA) {
            return 1;
        }
        return 0;
    }else {
        if(x1 > x2) {
            m = getCoefficient(x1, y1, x2, y2);
            if(m > mA) {
                return 1;
            }
            return 0;
        }else {
            m = getCoefficient(x2, y2, x1, y1);
            if(m < mB) {
                return 1;
            }
            return 0;
        }
    }
}