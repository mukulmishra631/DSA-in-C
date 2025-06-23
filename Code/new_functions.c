#include <stdio.h>
#include <math.h>

int main()
{
    // float x = 1.44;
    // float y = 1.78;
    int x = ceil(1.44);
    int y = ceil(1.78);
    int z = floor(1.44);
    int a = floor(1.78);
    // printf("%d %d %d %d",ceil(1.44), ceil(1.78), floor(1.44), floor(1.78) );
    printf("%d %d %d %d", x, y, z, a);
    return 0;
}