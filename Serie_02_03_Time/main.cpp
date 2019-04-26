#include "time.h"

int main()
{
    Time t1;
    Time t2;
    Time t3;
    Time t4 = 3600; //conversion => Time t4(3600); -> explicit to avoid doing this

    t1.show();

    //t1.adjust(0,0,59);
    //t2.adjust(0,0,1);

    t1.setSecond(59);
    t2.setSecond(1);

    t3 = t1.add(t2);

    t1.show();
    t2.show();
    t3.show();
    t4.show();

    /*t1.adjust(  0,  0, 60);
    t1.show();

    t1.adjust(  0, 60,  0);
    t1.show();

    t1.adjust( 24,  0,  0);
    t1.show();

    t1.adjust(  0,  0,360060);
    t1.show();

    t1.adjust(  0,361,  0);
    t1.show();

    t1.adjust( 20,  0,  0);
    t1.show();*/
    /*t1.adjust(20, 361, 360060);
    t1.show();
    t1.adjust(12,50,30);
    t1.show();

    t2.setHour(12);
    t2.setSecond(61);
    t2.setMinute(-40); // -40 < 0 --> 0
    t2.show();

    t3 = t2.add(t1);
    t3.show();*/
}