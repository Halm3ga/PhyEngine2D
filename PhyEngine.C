struct vec2{
    float x;
    float y;
}

float vec2Dist(vec2 a, vec2 b){
    float dX = a.x - b.x;
    float dY = a.y - b.y;
    return sqrt(dX * dX + dY * dY);
}