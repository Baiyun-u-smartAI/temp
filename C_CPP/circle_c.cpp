#include "circle_c.h"
#include "circle.h"
extern void* Circle_C_init(float radius){
    return new Circle(radius);
}
extern void Circle_C_free(void* circle){
    Circle *c = (Circle*) circle;
    delete c;
}
extern float Circle_C_getArea(void* circle){
    Circle *c = (Circle*) circle;
    return c->getArea();
}
