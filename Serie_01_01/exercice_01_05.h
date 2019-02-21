#include <iostream>
#include <iomanip>

using namespace std;

struct Room
{
    //attributes
    string name;
    int length;
    int width;
    int height;

    //constructor by default
    Room() {}

    //constructor by copy
    Room(string name_, int length_, int width_, int height_)
    {
        name = name_;
        length = length_;
        width = width_;
        height = height_;
    }

    //getter
    int getSurfaceFloor()
    {
        return width * length;
    }

    int getSurfaceWalls()
    {
        return (2 * length + 2 * width) * height;
    }

    int getVolume()
    {
        return length * width * height;
    }

    void printAll()
    {
        cout << name << ", [l ,w, g] : "
            << length << ", "
            << width << ", "
            << height << endl;

        cout << "Floor surface : " << getSurfaceFloor() << endl;
        cout << "Wall surface : " << getSurfaceWalls() << endl;
        cout << "Volume : " << getVolume() << endl;
    }
};

void printExercise05()
{
    Room r = Room("room", 2, 4, 6);
    r.printAll();
}