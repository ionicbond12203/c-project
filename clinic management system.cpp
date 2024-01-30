#include <iostream>
#include <vector>
using namespace std;

int calculateTotal(int num1, int num2, int num3);
int total = 0;

int main(){

    string name;
    string ic_number;
    int choice;
    char ans;


    vector<string> medicineArray;

    int PneumoniaMedicinePrice1   = 10;
    int PneumoniaMedicinePrice2   = 23;
    int PneumoniaMedicinePrice3   = 21;
    int ChickenPoxMedicinePrice1  = 10;
    int ChickenPoxMedicinePrice2  = 23;
    int DiarheaMedicinePrice1     = 21;
    int DiarheaMedicinePrice2     = 10;
    int MalariaMedicinePrice1     = 23;
    int MalariaMedicinePrice2     = 21;

    string PneumoniaMedicine1   = "Baxdela - RM " + to_string(PneumoniaMedicinePrice1);
    string PneumoniaMedicine2   = "Zithromax - RM " + to_string(PneumoniaMedicinePrice2);
    string PneumoniaMedicine3   = "Azactam - RM " + to_string(PneumoniaMedicinePrice3);
    string ChickenPoxMedicine1  = "Acyclovir - RM " + to_string(ChickenPoxMedicinePrice1);
    string ChickenPoxMedicine2  = "Valaclyclovir - RM " + to_string(ChickenPoxMedicinePrice2);
    string DiarheaMedicine1     = "Loperamide - RM " + to_string(DiarheaMedicinePrice1);
    string DiarheaMedicine2     = "Bismuth Subsalicylate - RM " + to_string(DiarheaMedicinePrice2);
    string MalariaMedicine1     = "Atovaquone - RM " + to_string(MalariaMedicinePrice1);
    string MalariaMedicine2     = "Cholorquine - RM " + to_string(MalariaMedicinePrice2);

    cout << "Enter Name: ";
    getline (cin, name);

    cout << "Enter IC Number: ";
    cin  >> ic_number;

do{
    cout << "Have you been here before?: \n"
         << "(y/n): ";
    cin  >> ans;


    if (ans == 'y'|| ans =='Y')
        {
            cout << "\n\nWelcome back to Andora Clinic." << endl;
    }
    else if (ans == 'n' || ans == 'N')
        {
            cout << "Your data has been registered";
    }
        else {
            cout << "\nInvalid input!\n"
                 << "Please try again!\n\n";
        }
}while (ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N');

     cout <<"\n\nWelcome to Andora Clinic! " << endl;
     cout << "Name: " << name << endl;
     cout << "IC Number: "<< ic_number<< endl;
     cout << "\nPlease Enter Disease Type: \n"
         << "1) Pneumonia \n"
         << "2) Chickenpox\n"
         << "3) Diarhea\n"
         << "4) Malaria\n"
         << "\nYour disease <1/2/3/4> is: ";

     cin >> choice;


  switch(choice){

        case 1:
            cout << "\nYou have been diagnosed with Pneumonia\n\n"
                 << "Medicine List:\n\n";

            medicineArray.push_back(PneumoniaMedicine1);
            medicineArray.push_back(PneumoniaMedicine2);
            medicineArray.push_back(PneumoniaMedicine3);

            for (const auto &medicine : medicineArray) {
                cout << medicine << endl;
            }

            total = calculateTotal(PneumoniaMedicinePrice1, PneumoniaMedicinePrice2, PneumoniaMedicinePrice3);

            cout << "\nThe total price will be RM " << total << endl;
            cout << "\nPlease pay at the counter. Thank You ~" << endl;

            break;

        case 2:
            cout << "\nYou have been diagnosed with Chickenpox\n\n"
                 << "Medicine List:\n\n";

            medicineArray.push_back(ChickenPoxMedicine1);
            medicineArray.push_back(ChickenPoxMedicine2);

            for (const auto &medicine : medicineArray) {
                cout << medicine << endl;
            }

            total = calculateTotal(ChickenPoxMedicinePrice1, ChickenPoxMedicinePrice2, 0);

            cout << "\nThe total price will be RM " << total << endl;
            cout << "\nPlease pay at the counter. Thank You ~" << endl;

            break;

        case 3:
            cout << "\nYou have been diagnosed with Diarhea\n\n"
                 << "Medicine List:\n\n";
            medicineArray.push_back(DiarheaMedicine1);
            medicineArray.push_back(DiarheaMedicine2);

            for (const auto &medicine : medicineArray) {
                cout << medicine << endl;
            }

            total = calculateTotal(DiarheaMedicinePrice1, DiarheaMedicinePrice2, 0);

            cout << "\nThe total price will be RM " << total << endl;
            cout << "\nPlease pay at the counter. Thank You ~" << endl;

            break;

        case 4:
            cout << "\nYou have been diagnosed with Malaria\n\n"
                 << "Medicine List:\n\n";
            medicineArray.push_back(MalariaMedicine1);
            medicineArray.push_back(MalariaMedicine2);

            for (const auto &medicine : medicineArray) {
                cout << medicine << endl;
            }

            total = calculateTotal(MalariaMedicinePrice1, MalariaMedicinePrice2, 0);

            cout << "\nThe total price will be RM " << total << endl;
            cout << "\nPlease pay at the counter. Thank You ~" << endl;
            break;

        default:
            cout << "\nInvalid Disease";
    }
    return 0;
}

int calculateTotal(int num1, int num2, int num3) {
    int total = num1 + num2 + num3;
    return total;
}





