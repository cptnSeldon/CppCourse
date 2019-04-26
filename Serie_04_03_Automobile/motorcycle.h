#ifndef H_MOTORCYCLE
#define H_MOTORCYCLE

#include "vehicle.h"

class Motorcycle : Vehicle
{
    private:
        int engineSize;

    public:
        //CONSTRUCTOR
        Motorcycle(string _brand="", int _kilometers=0, int _price=0, int _productionYear=CURRENT_YEAR, int _engineSize=50) : Vehicle(_brand, _kilometers, _price, _productionYear)
        {
            if(_engineSize < 50 || _engineSize > 1500 )
            {
                engineSize = 50;
            }
            else
            {
                engineSize = _engineSize;
            }
        }

        //METHODS
        ///display : override
        void show() override
        {
            Vehicle::show();
            cout << "Engine size: "
                << engineSize
                << endl
                << "Estimated price: " << estimate()
                << endl << endl;
        }
        ///estimate price : -3%/10'000km : override
        double estimate() override
        {
            int percentage = (int)floor(kilometers / 10000) * 3;
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
};

#endif //H_MOTORCYCLE