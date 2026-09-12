#include <stdio.h>
#include <math.h>

typedef struct vec2 {
    float x;
    float y;
} vec2;

vec2 addVec(vec2 a, vec2 b){
    vec2 sum;
    sum.x = a.x + b.x;
    sum.y = a.y + b.y;
    return sum;
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
vec2 divVec(vec2 a, float b){
    vec2 div;
    div.x = a.x / b;
    div.y = a.y / b;
    return div;
}
float vec2Dist(vec2 a, vec2 b) {
    vec2 result, res1, res2;
    res1 = mulVec(a,a);
    res2 = mulVec(b,b);
    result = subVec(res1,res2);
    return sqrtf(result.x + result.y);
}

int main() {

}


