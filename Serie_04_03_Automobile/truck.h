#ifndef H_TRUCK
#define H_TRUCK

#include "vehicle.h"

class Truck : Vehicle
{
    public:
        //CONSTRUCTOR
        Truck(string _brand, int _kilometers, int _price, int _productionYear, float _height, float _volume) : Vehicle(_brand, _kilometers, _price, _productionYear)
        {
            //HEIGHT
            if(height < 1 || height > 3)
            {
                height = 1;
            }
            else
            {
                height = _height;
            }
            //VOLUME
            if(volume < 2 || volume > 64)
            {
                volume = 2;
            }
            else
            {
                volume = _volume;
            }
        }

        //METHODS
        ///display : override
        void show() override
        {
             Vehicle::show();
            cout << "Height: "
                << height
                << endl
                << "Volume: "
                << volume
                << endl
                << "Estimated price: " << estimate()
                << endl << endl;
        }
        ///estimate price : -5%/year : override
        double estimate() override
        {
           int percentage = (CURRENT_YEAR - productionDate) * 5;
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
        float height;
        float volume;
};

#endif //H_TRUCK