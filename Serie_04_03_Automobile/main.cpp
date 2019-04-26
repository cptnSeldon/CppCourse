#include "car.h"
#include "motorcycle.h"
#include "truck.h"

int main()
{
    Car c("Toyota", 300000, 10000, 1994, 'B', '5');
    c.show();

    Motorcycle m("Yamaha", 10000, 10000, 2017, 1500);
    m.show();

    Truck t("Volvo", 10000, 10000, 2017, 2, 6);
    t.show();

    return 0;
}