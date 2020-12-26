#include <stdio.h>
#include "circle_c.h"
int main(int argc, char const *argv[]) {
    void* circle=Circle_C_init(1.5f);
    float area=Circle_C_getArea(circle);
    printf("%f\n",area );
    Circle_C_free(circle);
    return 0;
}
