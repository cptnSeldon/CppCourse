#include "chain.h"

//CONSTRUCTORS
///default
Chain::Chain()
{
    length = 0;
    text = new char[1];
    text[0] = 0;
}
///parameterized
Chain::Chain(char * text)
{
    length = strlen(text);
    this->text = new char[length+1];
    strcpy(this->text, text);
}
///copy
Chain::Chain(const Chain & other)
{
    this->length = other.length;
    this->text = new char[this->length + 1];
    strcpy(this->text, other.text);
}

//DESTRUCTOR
Chain::~Chain()
{
    delete [] this->text;
}

//OPERATOR OVERLOAD
/// =   : allows -> t3 = t2 = t1;
Chain & Chain::operator=(const Chain & other)
{
    if (this != &other)
    {
        delete [] this->text;
        length = other.length;
        this->text = new char[this->length + 1];
        strcpy(this->text, other.text);
    }

    return * this;
}
/// ==
bool Chain::operator==(Chain & other) const
{
    if(strcmp(this->text, other.text))
    {
        return false;
    }
    else
    {
        return true;
    }
}
/// []
char & Chain::operator[](int index) const
{
    if(index > 0 && index <= this->length)
    {
        return this->text[index];
    }
    else
    {
        return this->text[this->length - 1];
    }
}

//FRIEND FUNCTIONS
/// +
Chain operator+(const Chain & a, const Chain & b)
{
    Chain result;

    result.length = a.length + b.length;
    result.text = new char[result.length + 1];

    strcpy(result.text, a.text);
    strcpy(result.text + a.length, b.text);

    return result;
}
/// <<
ostream & operator<<(ostream & stream, const Chain & text)
{
    stream << text.text;

    return stream;
}
