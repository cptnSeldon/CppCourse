#ifndef H_VEHICLE
#define H_VEHICLE

#include <iostream>
#include <cmath>

static int CURRENT_YEAR = 2019;

using namespace std;

class Vehicle
{
    public:
        //CONSTRUCTOR
        Vehicle(string brand="", int kilometers=0, int price=0, int productionDate=CURRENT_YEAR)
        {
            this->brand = brand;

            //KM
            if(kilometers < 0)
            {
                this->kilometers = 0;
            }
            else
            {
                this->kilometers = kilometers;
            }
            //PRICE
            if(price < 0)
            {
                this->price = 0;
            }
            else
            {
                this->price = price;
            }
            //PRODUCTION DATE
            if(productionDate > CURRENT_YEAR)
            {
                this->productionDate = CURRENT_YEAR;
            }
            else if(productionDate < 1886)
            {
                this->productionDate = 1886;
            }
            else
            {
                this->productionDate = productionDate;
            }
        }

        //METHODS
        ///display
        virtual void show()
        {
            cout << "Brand: " << brand << "\n"
                 << "Km/h: " << kilometers << "\n"
                 << "Price: " << price << "\n"
                 << "Production date: " << productionDate
                 << endl;
        }
        ///estimate price
        virtual double estimate() = 0;

    protected:  //should be accessed only by the child classes
        string brand;
        int kilometers;
        int price;
        int productionDate;
};


#endif //H_VEHICLE