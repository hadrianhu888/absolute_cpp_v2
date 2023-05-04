/**
 * @file pfArray_main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"
#include "pfArray.cpp"

using namespace std;
using namespace pfarray;
using namespace pfarray_derived;

int main(int argc, char **argv);
void printArrayElements(PFArrayD &pfArrayD);
void saveArrayToDateTimeStampFile(PFArrayD &pfArrayD, string fileName);

int main(int argc, char **argv)
{
    PFArrayD pfArrayD(5);
    pfArrayD.addElement(1);
    pfArrayD.addElement(2);
    pfArrayD.addElement(3);
    pfArrayD.addElement(4);
    pfArrayD.addElement(5);
    printArrayElements(pfArrayD);
    saveArrayToDateTimeStampFile(pfArrayD, "pfArrayD.txt");
    cout << "Capacity: " << pfArrayD.getCapacity() << endl;
    cout << "Number Used: " << pfArrayD.getNumberUsed() << endl;
    return 0;
}

void printArrayElements(PFArrayD &pfArrayD)
{
    for (int i = 0; i < pfArrayD.getNumberUsed(); i++)
    {
        cout << pfArrayD.a[i] << endl;
    }
}

void saveArrayToDateTimeStampFile(PFArrayD &pfArrayD, string fileName)
{
    ofstream outFile;
    outFile.open(fileName);
    if (outFile.fail())
    {
        cout << "Output file open failed." << endl;
        exit(1);
    }
    outFile << pfArrayD.getNumberUsed() << endl;
    for (int i = 0; i < pfArrayD.getNumberUsed(); i++)
    {
        outFile << pfArrayD.a[i] << endl;
    }
    outFile.close();
}
