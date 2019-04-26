#ifndef H_POLYNOMIAL
#define H_POLYNOMIAL

#include <cstring>
#include <ostream>

using namespace std;

class Polynomial
{
    public:
        //CONSTRUCTOR
        ///A. default
        Polynomial();
        ///B. parameterized
        Polynomial(double _a, double _b, double _c);
        ///D. copy
        Polynomial(const Polynomial & other);
        ///E. conversion : BONUS : explicit
        explicit Polynomial(double _c);

        //DESTRUCTOR
        ///F.
        ~Polynomial();

        //METHODS
        ///C. check if null
        bool isNull() const;
        ///G. reset values
        void reset(double _a);
        void reset(double _a, double _b, double _c);

        ///AVOID CODE DUPLICATION: update magnitude
        void updateMagnitude();
        ///AVOID CODE DUPLICATION: update type
        void updateType();

        ///BONUS
        static int getInstanceNumber();

        //OVERLOAD
        ///I. =
        Polynomial & operator=(const Polynomial & other);
        ///J. +=
        Polynomial &operator+=(const Polynomial & other);
        ///H.  <<
        friend ostream& operator<<(ostream & os, const Polynomial & p);

    private:
        double a, b, c;
        double magnitude;       //a*a + b*b + c*c
        char * type = nullptr;  //constant, linear, parabole, empty
        //BONUS
        static int instanceNumber;
};

//OVERLOAD
/// + : called in the main function
Polynomial operator+(Polynomial p1, Polynomial p2);

#endif // H_POLYNOMIAL