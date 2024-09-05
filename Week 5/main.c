#include <stdio.h>
#include <stdlib.h>
typedef enum
{
    CIRCLE,
    SQUARE
} ShapeType;

typedef struct
{
    ShapeType type;
    union
    {
        struct
        {
            double radius;
        } circle;
        struct
        {
            double side_length;
        } square;
    } dimensions;
} Shape;
double calculateArea(Shape *shape)
{
    switch (shape->type)
    {
    case CIRCLE:
        return 3.14159 * shape->dimensions.circle.radius * shape->dimensions.circle.radius;
    case SQUARE:
        return shape->dimensions.square.side_length * shape->dimensions.square.side_length;
    }
}

int main() {

    Shape *circle = (Shape *)malloc(sizeof(Shape));
    circle->type = CIRCLE;
    circle->dimensions.circle.radius = 5.0;


    Shape *square = (Shape *)malloc(sizeof(Shape));
    square->type = SQUARE;
    square->dimensions.square.side_length = 4.0;


    printf("Area of the circle: %f\n", calculateArea(circle));
    printf("Area of the square: %f\n", calculateArea(square));


    free(circle);
    free(square);

    return 0;
}

