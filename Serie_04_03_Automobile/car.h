#ifndef H_CAR
#define H_CAR

#include "vehicle.h"

class Car : Vehicle
{
    public:
        //CONSTRUCTOR
        Car(string _brand="", int _kilometers=0, int _price=0, int _productionYear=CURRENT_YEAR, char _fuelType='B', unsigned char _doorNumber='3')
        : Vehicle(_brand, _kilometers, _price, _productionYear)
        {
            //FUEL TYPE
            if(_fuelType == 'B' || _fuelType == 'D' ||_fuelType == 'E')
            {
                fuelType =_fuelType;
            }
            else
            {
                fuelType ='B';
            }
            //DOOR
            if(_doorNumber == '3' || _doorNumber == '5' || _doorNumber == '7')
            {
                doorNumber = _doorNumber;
            }
            else
            {
                doorNumber = '3';
            }
        }

        //METHODS
        ///display : override
        void show() override
        {
            Vehicle::show();
            cout << "Fuel type: "
                 << fuelType
                 << endl
                 << "Doors: "
                 << doorNumber
                 << endl
                 << "Price estimation: "
                 << estimate()
                 << endl << endl;
        }
        ///estimate price : -10%/year : override
        double estimate() override
        {
            int percentage = (CURRENT_YEAR - productionDate) * 10;
            int valueToSubstract = price / 100 * percentage;

            if(valueToSubstract > price)
            {
                return 0;
            }
            else
            {
                return price - valueToSubstract;
            }
        }

    private:
        char fuelType;  //B, D, E
        unsigned char doorNumber;   //3, 5, ..

};

#endif //H_CAR