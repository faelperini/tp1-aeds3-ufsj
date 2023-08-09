#ifndef _H_PONTOS
#define _H_PONTOS

typedef struct Point{
    float x;
    float y;
}Point;

extern Point *points;
extern int Npoints, result;
extern float A, B;

float getCoefficient(float x2, float y2, float x1, float y1);
int comparator(const void *a, const void *b);
void solve();
int check(float mA, float mB, float x1, float y1, float x2, float y2);

#endif