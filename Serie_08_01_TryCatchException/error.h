#ifndef ERROR_H
#define ERROR_H

#include <exception>
#include<cstring>

using namespace std;

class Error : public exception
{
    public:
        Error() throw()
        {
            errorText = new char[128];
            strcpy(errorText, "Error : ");
        }

        Error(const char * message)
        {
            errorText = new char[128];
            strcpy(errorText, message);
        }

        const char * what() const throw()
        {
            return errorText;
        }

    private:
        char * errorText;
};

#endif //ERROR_H