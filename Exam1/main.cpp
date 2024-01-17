// by Dang Tai Bui
// Date: 9/25/2023
#include <iostream>
#include "input.h"
#include <fstream>
#include <vector>
using namespace std;

struct Element{
	int atomicNumber = 0;
	double atomicMass = 0.0;
	char symbol[3];
	char name[25] = "Unknown";
	int standardState = 0;
	int chemicalGroupBlock = 0;
	double meltingPoint= 0.0;
    double boilingPoint = 0.0;
	int yearDiscovered = 0;
	char Discoverers[100] = "Unknown";
};

// prototype functions
bool checkFileExist(string fileName);
string findChemicalGroupBlock(int blockNumber);
string findStandardState(int value);
void readPeriodicFile(string fileName);
void displayPeriodicTable();
void updateFile(string fileName, string symbolElement);
void optionA();
void optionB();
void optionC();
int mainMenuOption();
int menuOptionA();
int menuOptionB();
int menuOptionC();
void arrSelectSort(Element arr[], int size);
int main() {

    do {
        system("cls");
        cout << "Chemical Elements by Dang Tai Bui(10/9/2023)" << "\n";
        switch (mainMenuOption()) {
        case 'X':
            exit(1);
            break;
        case 'A':
        {
            system("cls");
            optionA();
            break;
        }
        case 'B':
        {
            system("cls");
            optionB();
            break;
        }
        case 'C':
        {
            system("cls");
            optionC();
            break;
        }
        default:
            cout << "\nPlease enter a valid option!\n";
            break;
        }
        cout << "\n";
        system("pause");
    }
    while (true);
    return EXIT_SUCCESS;
}

int editOptionMenu();
//PreCondition: NA
//PostCondition: returns option charactor for main menu
int mainMenuOption() {
    system("cls");
    
    displayPeriodicTable();
    cout << "\n\t\t" << string(60, char(205));
    cout << "\n\t\tA. Advanced Binary File Operations" << "";
    cout << "\n\t\tB. Dynamic Allocated Array" << "";
    cout << "\n\t\tC. Vector (array)" << "";
    cout << "\n\t\t" << string(60, char(196));
    cout << "\n\t\tX. Exit";
    cout << "\n\t\t" << string(60, char(205));
    return inputChar("\n\t\toption: ");
}
void displayPeriodicTable() {
    
        cout << "\n\t\t               PERIODIC TABLE OF ELEMENTS BY SYMBOL"

        << "\n\t\t[  H]                                                                                [ He]"
        << "\n\t\t[ Li][ Be]                                                  [  B][  C][  N][  O][  F][ Ne]"
        << "\n\t\t[ Na][ Mg]                                                  [ Al][ Si][  P][  S][ Cl][ Ar]"
        << "\n\t\t[  K][ Ca][ Sc][ Ti][  V][ Cr][ Mn][ Fe][ Co][ Ni][ Cu][ Zn][ Ga][ Ge][ As][ Se][ Br][ Kr]"
        << "\n\t\t[ Rb][ Sr][  Y][ Zr][ Nb][ Mo][ Tc][ Ru][ Rh][ Pd][ Ag][ Cd][ In][ Sn][ Sb][ Te][  I][ Xe]"
        << "\n\t\t[ Cs][ Ba]  *  [ Hf][ Ta][  W][ Re][ Os][ Ir][ Pt][ Au][ Hg][ Tl][ Pb][ Bi][ Po][ At][ Rn]"
        << "\n\t\t[ Fr][ Ra]  ** [ Rf][ Db][ Sg][ Bh][ Hs][ Mt][ Ds][ Rg][ Cn][ Nh][ Fl][ Mc][ Lv][ Ts][ Og]"
        << "\n\t\t"
        << "\n\t\t            *  [ La][ Ce][ Pr][ Nd][ Pm][ Sm][ Eu][ Gd][ Tb][ Dy][ Ho][ Er][ Tm][ Yb][ Lu]"
        << "\n\t\t            ** [ Ac][ Th][ Pa][  U][ Np][ Pu][ Am][ Cm][ Bk][ Cf][ Es][ Fm][ Md][ No][ Lr]";
}
// PreCondition: fileName (string);
// PostCondition: return a bool value
bool checkFileExist(string fileName)
{
    struct stat buffer;
    return (stat(fileName.c_str(), &buffer) == 0);
}
// PreCondition: element (Element struct)
// Function print out info of an element
void printInfoOfElement(Element& element)
{
    cout << "\n\t\t Atomic Number             :" << element.atomicNumber ;
    cout << "\n\t\t Symbol                    :" << element.symbol ;
    cout << "\n\t\t Name                      :" << element.name;
    cout << "\n\t\t Atomic Mass               :" << element.atomicMass;
    cout << "\n\t\t Chemical Group Block      :" << findChemicalGroupBlock(element.chemicalGroupBlock);
    cout << "\n\t\t Standard State            :" << findStandardState(element.standardState);
    cout << "\n\t\t Melting Point             :" << element.meltingPoint - 273.15 << "\370C " << "(" << element.meltingPoint << " K)";
    cout << "\n\t\t Boiling Point             :" << element.boilingPoint - 273.15 << "\370C "<< "(" << element.boilingPoint << " K)";
    cout << "\n\t\t Year Discovered           :" << element.yearDiscovered ;
    cout << "\n\t\t Discover By               :" << element.Discoverers ;
    cout << "\n";
}

// Function to read a Periodic binary file 
void readPeriodicFile(string fileName)
{

    ifstream file(fileName, ios::binary);
    Element element;
    int i = 1;
    while (file.read((char*)&element, sizeof(element)))
    {
        cout << sizeof(element);
        cout << "\n" << string(60, char(196));
        cout << "\n\t\t Element (struct) #" << i << "\n";
        printInfoOfElement(element);
        i++;
    }
    file.close();
}
//PreCondition: value (integer 0-3)
//PostCondition: returns a string standard state
string findStandardState(int value)
{
    switch (value)
    {
    case 0:
        return "unknown";
    case 1:
        return "Gas";
    case 2:
        return "Liquid";
    case 3:
        return "Solid";

    default:
        return "unknown";
    }
};

//PreCondition: blockNumber (integer 0-10)
//PostCondition: returns a string of group number
string findChemicalGroupBlock(int blockNumber)
{
    switch (blockNumber)
    {
    case 0:
        return "unknown";
    case 1:
        return "Nonmedal";
    case 2:
        return "Nobel Gas";
    case 3:
        return "Alkali Metal";
    case 4:
        return "Alkali Earth Metal";
    case 5:
        return "Transition Metal";
    case 6:
        return "Post-Transition Metal";
    case 7:
        return "Metaloid";
    case 8:
        return "Halogen";
    case 9:
        return "Lanthanide";
    case 10:
        return "Actinide";
    default:
        return "unknown";
    }
};

// PreCondition: fileName (string), symbol(string)
// PostCondition: NA
// Function to update an element in the file
void updateFile(string fileName, string symbol) {
    fstream file(fileName, ios::binary | ios::out | ios::in);
    Element updateElement;
    int count = -1;
    while (!file.eof()) {
        file.read(reinterpret_cast<char*>(&updateElement), sizeof(updateElement));
        count++;
        if (updateElement.symbol == symbol) {
            break;
        }
    }
    while (true) {
        int updateOption;
        printInfoOfElement(updateElement);
        switch (editOptionMenu()) {
        case 1:
            updateElement.atomicNumber = inputInteger("\nEnter atomic number: ");
            break;
        case 2:
            strcpy_s(updateElement.symbol, inputString("\nEnter the Symbol: ", false).c_str());
            break;
        case 3:
            strcpy_s(updateElement.name, inputString("\nEnter Name: ", false).c_str());
            break;
        case 4:
            updateElement.atomicMass = inputDouble("\nEnter atomic mass: ", true);
            break;
        case 5:
            updateElement.chemicalGroupBlock = inputInteger("\nEnter the Chemical "
                "Group Block (0 - unknown, 1 - Nonmetal, 2 - Nobel Gas, 3 - Alkali Metal, 4 - Alkaline Earth Metal"
                ", 5 - Post-transition Metal, 6 - Metalloid, 7 - Halogen, 8 - Nonmetal, 9 - Lanthanide, or 10 - Actinide): ", 0, 10);
            break;
        case 6:
            updateElement.standardState = inputInteger("\nEnter the Standard State (0 - unknown, 1 - Gas, 2 - Liquid, or 3 - Solid) : ", 0, 3);
            break;
        case 7:
            updateElement.meltingPoint = inputDouble("\nEnter the element's melting point: ");
            break;
        case 8:
            updateElement.boilingPoint = inputDouble("\nEnter the element's boiling point: ");
            break;
        case 9:
            updateElement.yearDiscovered = inputInteger("\nEnter the Year Discovered: ");
            break;
        case 10:
            strcpy_s(updateElement.Discoverers, inputString("\nEnter discoverer: ", true).c_str());
            break;

        case 0:
            file.seekp(sizeof(updateElement) * count, ios::beg);
            file.write(reinterpret_cast<char*>(&updateElement), sizeof(updateElement));
            cout << "\nUpdate Successful...\n";
            return;
        case -1:
            return;
        }
        
    }
}

// PreCondition: array(Element), atomicNumber(integer)
// PostCondition: NA
// Function to update an element in an array (Element)
void updateArray(Element elements[], int atomicNumber) {
    Element updateElement = elements[atomicNumber - 1];
    int editOption;
    while (true) {
        printInfoOfElement(updateElement);
        editOption = editOptionMenu();
        switch (editOption) {
        case 0:
            elements[atomicNumber - 1] = updateElement;
            cout << "\nUpdate array successfully...\n";
            return;
        case 1:
            updateElement.atomicNumber = inputInteger("\nEnter atomic number: ");
            break;
        case 2:
            strcpy_s(updateElement.symbol, inputString("\nEnter the Symbol: ", false).c_str());
            break;
        case 3:
            strcpy_s(updateElement.name, inputString("\nEnter Name: ", false).c_str());
            break;
        case 4:
            updateElement.atomicMass = inputDouble("\nEnter atomic mass: ", true);
            break;
        case 5:
            updateElement.chemicalGroupBlock = inputInteger("\nEnter the Chemical "
                "Group Block (0 - unknown, 1 - Nonmetal, 2 - Nobel Gas, 3 - Alkali Metal, 4 - Alkaline Earth Metal"
                ", 5 - Post-transition Metal, 6 - Metalloid, 7 - Halogen, 8 - Nonmetal, 9 - Lanthanide, or 10 - Actinide): ", 0, 10);
            break;
        case 6:
            updateElement.standardState = inputInteger("\nEnter the Standard State (0 - unknown, 1 - Gas, 2 - Liquid, or 3 - Solid) : ", 0, 3);
            break;
        case 7:
            updateElement.meltingPoint = inputDouble("\nEnter the element's melting point: ");
            break;
        case 8:
            updateElement.boilingPoint = inputDouble("\nEnter the element's boiling point: ");
            break;
        case 9:
            updateElement.yearDiscovered = inputInteger("\nEnter the Year Discovered: ");
            break;
        case 10:
            strcpy_s(updateElement.Discoverers, inputString("\nEnter discoverer: ", true).c_str());
            break;
        case -1:
            return;
        default:
            cout << "\nEnter valid value!";
            break;
        }
    } 
}

// PreCondition: elements (vector<Element>) , updateIndex(integer)
// PostCondition: NA
// Function to update an element in the an vector (Element)
void updateVector(vector<Element> &elements, Element updateElement, int updateIndex) {
    int editOption;
    while (true) {
        printInfoOfElement(updateElement);
        editOption = editOptionMenu();
        switch (editOption) {
        case 0:
            elements[updateIndex] = updateElement;
            cout << "\nUpdate array successfully...\n";
            return;
        case 1:
            updateElement.atomicNumber = inputInteger("\nEnter atomic number: ");
            break;
        case 2:
            strcpy_s(updateElement.symbol, inputString("\nEnter the Symbol: ", false).c_str());
            break;
        case 3:
            strcpy_s(updateElement.name, inputString("\nEnter Name: ", false).c_str());
            break;
        case 4:
            updateElement.atomicMass = inputDouble("\nEnter atomic mass: ", true);
            break;
        case 5:
            updateElement.chemicalGroupBlock = inputInteger("\nEnter the Chemical "
                "Group Block (0 - unknown, 1 - Nonmetal, 2 - Nobel Gas, 3 - Alkali Metal, 4 - Alkaline Earth Metal"
                ", 5 - Post-transition Metal, 6 - Metalloid, 7 - Halogen, 8 - Nonmetal, 9 - Lanthanide, or 10 - Actinide): ", 0, 10);
            break;
        case 6:
            updateElement.standardState = inputInteger("\nEnter the Standard State (0 - unknown, 1 - Gas, 2 - Liquid, or 3 - Solid) : ", 0, 3);
            break;
        case 7:
            updateElement.meltingPoint = inputDouble("\nEnter the element's melting point: ");
            break;
        case 8:
            updateElement.boilingPoint = inputDouble("\nEnter the element's boiling point: ");
            break;
        case 9:
            updateElement.yearDiscovered = inputInteger("\nEnter the Year Discovered: ");
            break;
        case 10:
            strcpy_s(updateElement.Discoverers, inputString("\nEnter discoverer: ", true).c_str());
            break;
        case -1:
            return;
        default:
            cout << "\nEnter valid value!";
            break;
        }
    }
}

// PreCondition: NA
// PostCondition: option(integer)
int editOptionMenu() {
    cout << "\tEdit Element Properties Menu\n";
    cout << "\n\t" << string(60, char(205));
    cout << "\n\t1. Atomic Number";
    cout << "\n\t2. Symbol";
    cout << "\n\t3. Name";
    cout << "\n\t4. Atomic Mass";
    cout << "\n\t5. Chemical Group Block";
    cout << "\n\t6. Standard State";
    cout << "\n\t7. Melting Point";
    cout << "\n\t8. Boiling Point";
    cout << "\n\t9. Discovered Year";
    cout << "\n\t10. Discovered By";
    cout << "\n\t" << string(60, char(196));
    cout << "\n\t-1. return without committing the updates";
    cout << "\n\t0. Committing the updates and return";
    cout << "\n\t" << string(60, char(205));
    return inputInteger("\nOption: ", -1, 10);
}

void optionA() {
    string filename = "";
    do {
        switch (menuOptionA())
        {
        case 0:          
            return;
        case 1:
            filename = inputString("Enter the binary data file name: ", false);
            if (checkFileExist(filename))
            {
                readPeriodicFile(filename);
            }
            else
            {
                cout << "\nERROR: Binary data file, " << filename << " ,cannot be found.";
            };                   
            break;
        case 2:
            if (filename != "")
            {
                if (checkFileExist(filename)) {
                    string searchSymbol = "";
                    searchSymbol = inputString("Enter an Element Symbol to search and update: ", false);
                    updateFile(filename, searchSymbol);
                    system("PAUSE");
                    system("cls");
                    break;
                }
                else {
                    cout << "\nERROR: No binary file has been specified from option 1.\n";
                    system("PAUSE");
                    system("cls");
                    break;
                }
            }
        default:
            cout << "\nPlease enter a valid option.";
            break;
        }
        system("PAUSE");
        system("cls");
    } while (true);
}
void optionB() {
    const int SIZE = 118;
    string filename = "";
    Element* elements = new Element[SIZE];
    fstream file;
    int elementCount = 0;
    do {
        switch (menuOptionB()) {
        case 0:
            // Deallowcate the memory
            delete[] elements;
            return;
        case 1: 
        {
            // Check if file exists and store all the elements to the elements array
            filename = inputString("\nEnter input filename: ", false);
            if (checkFileExist(filename)) {
                file.open(filename, ios::binary | ios::in);
                Element currentElement;
                while (file.read(reinterpret_cast<char*>(&currentElement), sizeof(currentElement))) {
                    elements[elementCount] = currentElement;
                    elementCount++;
                }
                // sort the array based on atomic number
                arrSelectSort(elements, SIZE);
                cout << "\nSUCCESS: "<< SIZE << "(struct) data from "<<filename<<" have been stored into dynamic allocated array and sorted by Atomic Number. \n";
                file.close();
            }
            else {
                cout << "Filename does not exist";
            }
             break;
        }
        case 2:
        {
            // Check if the array is empty 
            if (elementCount == 0) {
                cout << "\nERROR: Binary data has NOT been read into the array from step#1.\n";

            }
            // output the array
            else {

                for (int i = 0; i < SIZE; i++) {
                    cout << "\n\tarray element[" << i << "]";
                    cout << "\n\t" << string(60, char(196));
                    printInfoOfElement(elements[i]);
                }
            }
            break;
        }
        case 3: 
        {
            if (elementCount == 0) {
                cout << "\nERROR: Binary data has NOT been read into the array from step#1.\n";
                break;
            }
            else {
                int searchNum = inputInteger("\nEnter an Atomic Number (1...118) to search and update:", 1, 118);
                cout << "\n\t" << string(60, char(196));
                updateArray(elements, searchNum);
                break;
            }
        }
        case 4:
            if (elementCount != 0) {
                file.open(filename, ios::binary | ios::out);
                file.write(reinterpret_cast<char*>(elements), sizeof(Element) * SIZE);
                cout << "\nUpdate successful...";
            }
            else {
                cout << "\nThe array is empty\n";
            }
            break;
        default:    
            cout << "\nEnter valid option";
            break;
        }
        system("pause");
        system("cls");

    } while (true);
    file.close();
}
void optionC() {
    string filename;
    fstream file;
    int updateIndex = -1;
    vector<Element> ChemistryElements;
    Element updateElement;
    ofstream outFile;

    do {
        displayPeriodicTable();
        switch (menuOptionC()) {
        case 0:          
            return;
        case 1:
            filename = inputString("\nEnter input filename: ", false);
            file.open(filename, ios::binary | ios::in);

            if (checkFileExist(filename)) {
                ChemistryElements.clear();
                Element currentElement;
                while (file.read(reinterpret_cast<char*>(&currentElement), sizeof(currentElement))) {
                    ChemistryElements.push_back(currentElement);                   
                }
                cout << "\n\tSUCCESS: " << ChemistryElements.size() << "(struct) binary data from " << filename <<" have been stored into unsorted vector.\n";
            }
            else
                cout << "\n\tFilename does not exist\n";
            file.close();
            break;
        case 2:
            if (ChemistryElements.size() != 0) {
                for (int i = 0; i < ChemistryElements.size(); i++) {
                    cout << "\n\tarray element[" << i << "]";
                    cout << "\n\t" << string(60, char(196));
                    printInfoOfElement(ChemistryElements[i]);
                }
            }
            else
                cout << "\n\tERROR: Binary data has NOT been read into the vector from step#1.";
            break;
        case 3:
            if (ChemistryElements.size() != 0) {
                while (true) {
                    string name = inputString("\n\tEnter an element's name to search and update:", false);
                    bool isNameExist = true;
                    
                    
                    for (int i = 0; i < ChemistryElements.size();i++) {
                        if (ChemistryElements[i].name == name) {
                            updateIndex = i;
                            updateElement = ChemistryElements[i];
                            break;
                        }
                    }
                    if (updateIndex == -1) {
                        isNameExist = false;
                        cout << "ERROR: Element with name," << name << ", cannot be found.";
                        continue;
                    }
                    updateVector(ChemistryElements, updateElement, updateIndex);
                    break;                  
                }
            }
            else
                cout << "\n\tERROR: Binary data has NOT been read into the vector from step#1.";
            break;
        case 4:
            
            if (ChemistryElements.size() != 0) {
                outFile.open(inputString("\n\tEnter filename to save the changes: ",false), ios::binary | ios::out);
                outFile.write(reinterpret_cast<const char*>(ChemistryElements.data()), sizeof(Element) * ChemistryElements.size());
                cout << "\nUpdate successful...";
                outFile.close();
            }
            else
                cout << "\n ERROR: Binary data has NOT been read into the vector from step#1.\n";
        default:
            cout << "\n\tPlease enter valid option";        
            break;
        }
        system("pause");
        system("cls");
    } while (true);
    
}

// PreCondition: array(Element struture), size (integer)
// PostCondition: NA
// Function for sorting an array of Elements
void arrSelectSort(Element arr[], int size) {
    int startScan, minIndex;
    Element minElem;

    for (startScan = 0; startScan < (size - 1); startScan++) {
        minIndex = startScan;
        minElem = arr[startScan];

        for (int index = startScan + 1; index < size; index++) {
            if (arr[index].atomicNumber < minElem.atomicNumber) {
                minElem = arr[index];
                minIndex = index;
            }
        }

        // Swap the elements
        Element temp = arr[minIndex];
        arr[minIndex] = arr[startScan];
        arr[startScan] = temp;
    }
}
int menuOptionA() {
    cout << "\nAdvanced Binary File Operations Menu"
        << "\n";
    cout << "\n" << string(60, char(205));
    cout << "\n1. Read and Display ALL elements from binary data file";
    cout << "\n2. Search and update an element by Symbol from binary file";
    cout << "\n" << string(60, char(196));
    cout << "\n0. Return to main menu";
    cout << "\n" << string(60, char(205));
    return inputInteger("\noption: ");
}
int menuOptionB() {
    cout << "                       PERIODIC TABLE OF ELEMENTS BY SYMBOL ";
    cout<<"\n\t[  1]                                                                                [  2]"
        <<"\n\t[  3][  4]                                                  [  5][  6][  7][  8][  9][ 10]"
        <<"\n\t[ 11][ 12]                                                  [ 13][ 14][ 15][ 16][ 17][ 18]"
        <<"\n\t[ 19][ 20][ 21][ 22][ 23][ 24][ 25][ 26][ 27][ 28][ 29][ 30][ 31][ 32][ 33][ 34][ 35][ 36]"
        <<"\n\t[ 37][ 38][ 39][ 40][ 41][ 42][ 43][ 44][ 45][ 46][ 47][ 48][ 49][ 50][ 51][ 52][ 53][ 54]"
        <<"\n\t[ 55][ 56]  *  [ 72][ 73][ 74][ 75][ 76][ 77][ 78][ 79][ 80][ 81][ 82][ 83][ 84][ 85][ 86]"
        <<"\n\t[ 87][ 88]  ** [104][105][106][107][108][109][110][111][112][113][114][115][116][117][118]"
        <<"\n"
        <<"\n\t            *  [ 57][ 58][ 59][ 60][ 61][ 62][ 63][ 64][ 65][ 66][ 67][ 68][ 69][ 70][ 71]"
        <<"\n\t            ** [ 89][ 90][ 91][ 92][ 93][ 94][ 95][ 96][ 97][ 98][ 99][100][101][102][103]";
    cout << "\n\n\tDynamic Allocated Array Menu";
    cout << "\n\t";
    cout << "\n\t" << string(60, char(205));
    cout << "\n\t1. Read, store ALL elements from binary file into the sorted array";
    cout << "\n\t2. Display all elements from the array";
    cout << "\n\t3. Search and update an element by Atomic Number from the array";
    cout << "\n\t4. Write ALL elements from the array into the binary file";
    cout << "\n\t" << string(60, char(196));
    cout << "\n\t0. Return to main menu";
    cout << "\n\t" << string(60, char(205));
    return inputInteger("\noption: ");
}
int menuOptionC() {
    cout << "\n\tDynamic Allocated Array Menu"
        << "\n\t";
    cout << "\n\t" << string(60, char(205));
    cout << "\n\t1. Read and store ALL elements from binary file into the unsorted vector (array)";
    cout << "\n\t2. Display all elements from the vector";
    cout << "\n\t3. Search and update an element by Name from the vector";
    cout << "\n\t4. Write ALL elements from the vector into the binary file";
    cout << "\n\t" << string(60, char(196));
    cout << "\n\t0. Return to main menu";
    cout << "\n\t" << string(60, char(205));
    return inputInteger("\n\toption: ");
}
