#include "polynomial.h"

int Polynomial::instanceNumber = 0;

//CONSTRUCTOR
///A. default
Polynomial::Polynomial() : a(0), b(0), c(0)
{
    //set type
    updateType();
    //update magnitude
    updateMagnitude();
    //BONUS : update instance number
    instanceNumber++;
}
///B. parameterized
Polynomial::Polynomial(double _a, double _b, double _c) : a(_a), b(_b), c(_c)
{
    //set type
    updateType();
    //update magnitude
    updateMagnitude();
    //BONUS : update instance number
    instanceNumber++;
}
///D. copy
Polynomial::Polynomial(const Polynomial & other) : Polynomial(other.a, other.b, other.c) { }
///E. conversion : BONUS : explicit
Polynomial::Polynomial(double _c) : Polynomial(0, 0, _c) { }

//DESTRUCTOR
///F.
Polynomial::~Polynomial()
{
    //delete pointer
    delete[] type;
    //BONUS : update instance number
    instanceNumber--;
}

//METHODS
///C. check if null
bool Polynomial::isNull() const
{
    if(magnitude == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
///G. reset values
void Polynomial::reset(double _a)
{
    reset(_a, _a, _a);
}
void Polynomial::reset(double _a, double _b, double _c)
{
    a = _a;
    b = _b;
    c = _c;

    //update type
    updateType();
    //update magnitude
    updateMagnitude();
}

///AVOID CODE DUPLICATION: update magnitude
void Polynomial::updateMagnitude()
{
    magnitude = a * a + b * b + c * c;
}

///AVOID CODE DUPLICATION: update type
void Polynomial::updateType()
{
    //delete pointer content
    if(type != nullptr)
    {
        delete[] type;
    }
    //empty
    if(a == 0 && b == 0 && c == 0)
    {
        type = new char[6]; //empty + 1
        strcpy(type, "empty");
    }
    //parabole
    else if(a != 0 && b != 0)
    {
        type = new char[9]; //parabole + 1
        strcpy(type, "parabole");
    }
    //linear
    else if(b != 0)
    {
        type = new char[7]; //linear + 1
        strcpy(type, "linear");
    }
    //constant
    else
    {
        type = new char[9]; //constant + 1
        strcpy(type, "constant");
    }
}

///BONUS
int Polynomial::getInstanceNumber()
{
    return instanceNumber;
}

//OVERLOAD
///I. =
Polynomial & Polynomial::operator=(const Polynomial & other)
{
    if(this != & other)
    {
        a = other.a;
        b = other.b;
        c = other.c;

        //update type
        updateType();

        //update magnitude
        updateMagnitude();
    }

    return *this;
}
///J. +=
Polynomial & Polynomial::operator+=(const Polynomial & other)
{
    a += other.a;
    b += other.b;
    c += other.c;

    //update type
    updateType();

    //update magnitude
    updateMagnitude();

    return *this;
}
///H.  <<
ostream& operator<<(ostream & stream, const Polynomial & p)
{
    stream << p.type << " : " << p.a << "x^2 + " << p.b << "x + " << p.c;
    return stream;
}
/// + : called in the main function
Polynomial operator+(Polynomial p1, Polynomial p2)
{
    Polynomial c(p1);

    return c += p2;
}