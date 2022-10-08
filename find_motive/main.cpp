#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{

    ifstream file;
    file.open (argv[1]);
    if (!file) {
        cout << "The file " << argv[1] << " could not be opened.";
        return 1;
    }

    int occ = 0;
    string word;
    while (file >> word) {
        int i = 0;
        if (word.find(argv[2]) != std::string::npos) {
            occ++;
        }
    }

    cout << "The file " << argv[1] << " contains "<< occ << " words containing the motive "<< argv[2];

    file.close();
    return 0;
}
