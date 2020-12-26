#include "circle.h"
Circle::Circle(float radius):_radius(radius){}

float Circle::getArea() const {
    return 3.14159*this->_radius*this->_radius;
}
