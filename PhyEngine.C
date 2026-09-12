#include <stdio.h>
#include <math.h>
#define dt 0.016f
#define PI 3.14159265358979323846f
#define gravity 9.81f
#define mass 1.0f

typedef struct vec2 {
    float x;
    float y;
} vec2;
typedef struct box{
    vec2 a;
    vec2 b;
    vec2 c;
    vec2 d;
    vec2 center;
}

vec2 addVec(vec2 a, vec2 b){
    vec2 sum;
    sum.x = a.x + b.x;
    sum.y = a.y + b.y;
    return sum;
}

float magnitude(vec2 a) {
    return sqrtf(a.x*a.x + a.y*a.y);
}
vec2 subVec(vec2 a, vec2 b){
    vec2 sub;
    sub.x = a.x - b.x;
    sub.y = a.y - b.y;
    return sub;
}
vec2 mulVec(vec2 a, float b){
    vec2 mul;
    mul.x = a.x * b;
    mul.y = a.y * b;
    return mul;
}
vec2 sqrVec(vec2 a, int b){
    for (int i = 1; i < b; i++){
        a.x = a.x * a.x;
        a.y = a.y * a.y;
    }
    return a;
}
float dotVec(vec2 a, vec2 b){
    float theta = acosf(((magnitude(a)*magnitude(a)) + (magnitude(b)*magnitude(b)) - (magnitude(subVec(a, b))*magnitude(subVec(a, b)))) / (2 * magnitude(a) * magnitude(b)));
    return magnitude(a) * magnitude(b) * cosf(theta);
}
float CrossVec(vec2 a, vec2 b){
    float theta = acosf(((magnitude(a)*magnitude(a)) + (magnitude(b)*magnitude(b)) - (magnitude(subVec(a, b))*magnitude(subVec(a, b)))) / (2 * magnitude(a) * magnitude(b)));
    return magnitude(a) * magnitude(b) * sinf(theta);
}

vec2 divVec(vec2 a, float b){
    vec2 div;
    div.x = a.x / b;
    div.y = a.y / b;
    return div;
}
float vec2Dist(vec2 a, vec2 b) {
    vec2 result;
    result.x = (a.x-b.x)*(a.x-b.x);
    result.y = (a.y-b.y)*(a.y-b.y);
    return sqrtf(result.x + result.y);
}
float vec2Vel(vec2 a, vec2 b){
    return vec2Dist(a,b)/dt;
}
float vec2Acc(vec2 a, vec2 b){
    return vec2Vel(a,b)/dt;
}
float vec2Force(vec2 a, vec2 b){
    return mass * vec2Acc(a,b);
}

int main() {
    vec2 a,b;
    a.x = 1.0f;
    a.y = 0.0f;
    b.x = 0.0f;
    b.y = 1.0f;
    printf("Distance : %f\n", vec2Dist(a,b));
    printf("Speed : %f\n", vec2Vel(a,b));
    printf("Dot: %f\n", dotVec(a,b));
    printf("Cross: %f\n", CrossVec(a, b));
    for (int i = 0; i < 10; i++){
        a.x += gravity * 0.1f;
        a.y += gravity * 0.1f;
        printf("Distance : %f\n", vec2Dist(a,b));
        printf("Speed : %f\n", vec2Vel(a,b));
        printf("Dot: %f\n", dotVec(a,b));
        printf("Cross: %f\n", CrossVec(a, b));
    }
}


