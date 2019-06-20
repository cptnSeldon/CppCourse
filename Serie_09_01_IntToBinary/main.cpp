#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

bool fileExists(const string fileName)
{
    ifstream file(fileName.c_str());

    return !file.fail();    //no close() needed -> automatic closure
}

int main()
{
    string fileName;
    char answer;

    int n;

    bool ok = false;

    //CREATE FILE
    cout << "Enter filename : " << endl;
    getline(cin, fileName);

    ofstream outFile;
    //GET INPUT :
    while(!ok)
    {
        //WRITE TO FILE
        ///if exists : ask confirmation then override if confirmed
        if(fileExists(fileName))
        {
            cout << "This file already exists. Do you want to override it ? (y/n)" << endl;
            cin >> answer;

            cin.ignore( numeric_limits<streamsize>::max(), '\n' );

            if(answer == 'y')
            {
                //override file + exit loop
                outFile.open(fileName.c_str(), ios::out | ios::binary);
                ok = true;
            }
            if(answer == 'n')
            {
                cout << "Enter new file name : " << endl;
                getline(cin, fileName);
            }
        }
        ///if doesn't exists -> create new
        else
        {
            outFile.open(fileName.c_str(), ios::out | ios::binary);
            ok == true;
        }
    }
    ///file couldn't be opened
    if(outFile.fail())
    {
        cout << "Something went wrong.." << endl;
        exit(1);
    }

    ///test if int : 0 -> end of file
    do
    {
        cout << "Enter an int : " ;
        cin >> n ;

        if (cin.fail())
        {
            n = 1;
            cout << "Please, enter an int this time :\n";

            cin.clear();
            cin.ignore( numeric_limits<streamsize>::max(), '\n' );
        }
        else if (n) outFile.write ((char *)&n, sizeof(int)) ;
    }
    while (n && outFile) ;

    outFile.close ();

    cout << "\nPress on any key... ";
    cin.clear();
    cin.ignore( numeric_limits<streamsize>::max(), '\n' );
    cin.get();
    return 0;
}