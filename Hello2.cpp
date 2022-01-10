// Name : Harish Dhanraj Sugandhi
// Roll No.: 21377
// Class : SE -3 Batch - H4
// Assignment 7nth
/*Problem Statement : write a C++ Program that creates and output file,
writes information to it, closes the file,Open it again as an Input file and read the information from the file.*/

#include <iostream>
using namespace std;
#include <fstream>
class File
{
public:
    string name;
    string ExitCondition = "STOP";
    void Read_File()
    {
        File f;
        ifstream file;
        file.open("NewFile.txt");
        if (!file)
        {
            cout << "Opening File Error" << endl;
            return;
        }
        string Line;

        while (!file.eof())
        {
            getline(file, Line);
            cout << Line << endl;
            file.read((char *)&f, sizeof(f));
            string str = f.name;
        }
        file.close();
    }

    void Write_File()
    {
        File f;

        ofstream file;
        file.open("NewFile.txt", ios::out);
        string Line;
        string str = "Harish";
        f.name = str;

        cout << "Write Data In File As Many As You Want (To Stop Enter STOP and Hit Enter) " << endl;
        file.write((char *)&f, sizeof(f));
        bool Append = true;
        cin.ignore();
        while (Append)
        {
            getline(cin, Line);
            if (ExitCondition.compare(0, 4, Line) == 0)
            {
                cout << "Breaking..."
                     << "\n";
                Append = false;
                break;
            }
            file << Line << endl;
        }

        file.close();
    }

    void Append_File()
    {
        ofstream file;
        file.open("NewFile.txt", ios::app);
        string Line;
        cout << "Append data In file as Many As You Want (To Stop Enter STOP and Hit Enter) " << endl;
        bool Append = true;
        cin.ignore();
        while (Append)
        {
            getline(cin, Line);
            if (ExitCondition.compare(0, 4, Line) == 0)
            {
                cout << "Breaking..."
                     << "\n";
                Append = false;
                break;
            }
            file << Line << endl;
        }
        file.close();
    }
};

int main()
{
    File f;
    bool Loop = true;
    int Choice = 0;
    while (Loop)
    {
        cout << "******** Menu ********" << endl;
        cout << "1] Write Data in File " << endl;
        cout << "2] Append Data in File " << endl;
        cout << "3] Read Data From File " << endl;
        cout << "4] Exit " << endl;
        cin >> Choice;

        switch (Choice)
        {
        case 1:
        {
            f.Write_File();
            break;
        }
        case 2:
        {
            f.Append_File();
            break;
        }
        case 3:
        {
            f.Read_File();
            break;
        }
        case 4:
        {
            cout << "Thank You For Using Our Program " << endl;
            Loop = false;
            break;
        }

        default:
        {
            cout << "Invalid Choice " << endl;
            break;
        }
        }
    }
}
