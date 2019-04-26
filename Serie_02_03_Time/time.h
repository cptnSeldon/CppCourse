#ifndef TIME_H
#define TIME_H

class Time
{
    private:
        //ATTRIBUTES
        int hour;
        int minute;
        int second;

    public:
        //CONSTRUCTORS
        Time(void);          //default
        Time(int, int, int); //std
        Time(int);           //conversion : t = 4000; is allowed
        //explicit Time(int);   -> t = 4000; is not allowed
        Time(const Time &);  //copy : reference on passed time -> avoids copying the whole object
        //FUNCTIONS
        //getters
        int getHour(void) const { return hour; };     //avoids hour to be changed
        int getMinute(void) const { return minute; }; //avoids minute to be changed
        int getSecond(void) const { return second; }; //avoids second to be changed
        //setters
        void setHour(int);
        void setMinute(int);
        void setSecond(int);
        //misc
        void adjust(int, int, int);
        void show(void);
        Time add(const Time &) const;
};

#endif TIME_H