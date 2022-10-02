#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main ()
{
    //Declarations
    std::string s1;
    std::string s2;
    std::string list;
    string::size_type n=0;
    string::size_type len_s1;
    string::size_type len_s2;
    string::size_type len_str;

    //input and output files
    string infile = "raw.txt";
    string outfile = "list.txt";

    //Declare file stream and open infile
    std::ifstream infs;
    std::ofstream outfs;

    //Open and read infile to buffer & close infile
    infs.open(infile, std::ios::in);
    std::string str((std::istreambuf_iterator<char>(infs)), std::istreambuf_iterator<char>());
    infs.close();

    //Remove end-of-line char ('\n') so text is single string and get length
    str.erase(std::remove(str.begin(), str.end(), '\n'), str.cend());
    len_str = str.length();

    //Press ENTER to exit
    cout << "Press ENTER key before typing anything to exit program\n" << endl;

    //Get s1
    cout << "Enter start of string (Case Sensitive | Include spaces | Cannot be null: ";
    getline(cin,s1);
    len_s1 = s1.length();

    //Exit if null
    if (len_s1 == 0) {
        cout << "Can't have null value. Program exiting.\n" << endl;
        return(1);
    }

    //Get s2
    cout << "Enter final delimiter(s) (Case Sensitive | Include spaces | Cannot be null: ";
    getline(cin,s2);
    len_s2 = s2.length();

    //Exit if null
    if (len_s2 == 0) {
        cout << "\nCan't have null value. Program exiting.\n" << endl;
        return(1);
    }

    //Print input parameters
    cout << "Check below. Lengths should not be 0. If they are there is a problem with the program." << endl;
    cout << "And your results will be wrong.\n" << endl;
    cout << "\ns1 = \"" << s1 << "\"\ns1 length = " << len_s1 << endl;
    cout << "\ns2 = \"" << s2 << "\"\ns2 length = " << len_s2 << endl;
    cout << "\nstr length = " << len_str << '\n' << endl;

    //Open outfile
    outfs.open(outfile, std::ios::out|std::ios_base::trunc);

    while (n < len_str) {
        std::size_t pos1 = str.find(s1, n);
        if (pos1 == string::npos) break;
        std::size_t pos2 = str.find(s2, pos1+len_s1);
        if (pos2 == string::npos) break;
        list = str.substr(pos1, pos2-pos1);
        n = pos2 + len_s2;
        outfs << list << endl;
    }


        outfs.close();
        return 0;

}






















