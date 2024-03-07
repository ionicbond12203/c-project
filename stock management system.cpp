#include<iostream>
#include<string>
#include<fstream>
#include <algorithm>

using namespace std;

void Taskoption(){
    cout<< "\n*********Stock System Management*********"<< endl;
    cout << "What task you want to do?: \n";
    cout << "1) Stock department\n";
    cout << "2) Product department\n";
}

class stock{
    int stock_id;
    string product_name;
    int quantity;

public:

void TaskOptionstock(){
    cout << "\n*********Stock System Management*********"<< endl;
    cout << "What task you want to do?: \n";
    cout << "1) Add new stock\n";
    cout << "2) View all stock\n";
    cout << "3) Edit stock details \n";
    cout << "4) Search stock \n";
    cout << "5) Exit\n";
}

void AddStockDetails(){

    cout << "Enter Stock ID: ";
    while(!(cin >> stock_id)){
        cout << "Invalid input. Please enter a valid integer for Stock ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Enter Product Name: ";
    cin  >> product_name;
    cout << "Enter Product Quantity: ";
    while(!(cin >> quantity)){
        cout << "Invalid input. Please enter a valid integer for Product Quantity: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    fstream stock("Stock.txt",ios::in|ios::app);
        if(!stock.is_open()){
            cout << "Error";
        }else{
           stock << stock_id <<","<<product_name<<","<<quantity;
           stock << endl;

           stock.close();
        }
}

void viewstock(){

    string readall;

    cout << "Displaying all record for stock: " << endl << endl;
    fstream displaystock ("Stock.txt", ios::in);
    cout << "ID\tName\tQuantity" << endl << endl;

    if (displaystock.is_open()){
        while(getline(displaystock,readall)){
            replace (readall.begin(),readall.end(),',','\t');
            cout << readall << endl << endl;
        }
    }else{
        cout << "Error" << endl;
    }
}

void editstock(){

    int stockid;
    string olddata;
    string newdata;
    string tmpfile;
    string line;

    cout << "Enter Stock ID that want to edit: ";
    while(!(cin >> stockid)){
        cout << "Invalid input. Please enter a valid integer for Stock ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Enter the detail that want to edit: ";
    cin  >> olddata;
    cout << "Enter new details: ";
    cin  >> newdata;

    ifstream loadfile("Stock.txt");
    if (!loadfile){
        cout << "Error" << endl;
    }

    while (getline(loadfile, line)) {
        size_t position = line.find(to_string(stockid));
        if (position != string::npos) {
            size_t oldData = line.find(olddata);
                line.replace(oldData, olddata.size(), newdata);
        }
        if(!line.empty()){
            tmpfile += line + "\n";
        }
    }

    loadfile.close();

    ofstream WriteFile("Stock.txt");
    if (!WriteFile.is_open()){
        cout << "Error" << endl;
    }

    WriteFile << tmpfile;
    WriteFile.close();

    cout << "\nData has been edited!" << endl;

}

void SearchFile(string searchid){

    string id;
    string fullline;

    fstream searchstock("Stock.txt", ios::in);

    if (!searchstock.is_open()){
        cout << "Error" << endl;
    }else{
        bool found;

        while(getline(searchstock,id,',') && getline(searchstock, fullline)){
            if (id == searchid){
                cout << "stock Found" << endl;
                cout << "ID\tName\tQuantity" << endl << endl;
                replace (fullline.begin(),fullline.end(),',','\t');
                cout << id <<"\t" << fullline << endl;
                found = true;
            }
        }

        if (!found){
            cout << "No record found" << endl;
        }
        return;
    }
}
};

class Product{
    int product_id;
    string product_name;
    double product_price;
    int product_quantity;

public:

   void TaskOptionproduct(){
    cout<< "\n*********Stock System Management*********"<< endl;
    cout << "What task you want to do?: \n";
    cout << "1) Add new product\n";
    cout << "2) View all product\n";
    cout << "3) Edit product details \n";
    cout << "4) Search product \n";
    cout << "5) Exit\n";

}

void Addproductdetails(){

    cout << "Enter Product ID: ";
      while(!(cin >> product_id)) {
        cout << "Invalid input. Please enter a valid integer for Product ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');}
    cout << "Enter Product Name: ";
    cin  >> product_name;
    cout << "Enter Product Price: ";
    cin  >> product_price;
    cout << "Enter Product Quantity: ";
      while(!(cin >> product_quantity)) {
        cout << "Invalid input. Please enter a valid integer for Product Quantity: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');}


    fstream product("Product.txt",ios::in|ios::app);
        if(!product.is_open()){
                cout<<"error";
            }else{

            product << product_id <<","<<product_name<<","<<product_price<<","<<product_quantity;
            product << endl;

            product.close();
            }
}

void viewproduct(){

    string readall;

    cout << "Displaying all record for product: " << endl << endl;
    fstream displayproduct ("Product.txt", ios::in);
    cout << "ID\tName\tPrice\tQuantity" << endl << endl;

    if (displayproduct.is_open()){
        while(getline(displayproduct,readall)){
            replace (readall.begin(),readall.end(),',','\t');
            cout << readall << endl << endl;
        }
    }else{
        cout << "Error" << endl;
    }
}

void editproduct(){

    int productid;
    string olddata;
    string newdata;
    string tmpfile;
    string line;

    cout << "Enter product id that want to edit: ";
    while(!(cin >> productid)){
        cout << "Invalid input. Please enter a valid integer for Product ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Enter the detail that want to edit: ";
    cin  >> olddata;
    cout << "Enter new details: ";
    cin  >> newdata;

    ifstream loadfile("Product.txt");
    if (!loadfile){
        cout << "Error" << endl;
    }

    while(getline(loadfile,line)){
        size_t position = line.find(to_string(productid));
        if (position != string::npos){
            size_t oldData = line.find(olddata);
            line.replace(oldData,olddata.size(),newdata);
        }
        if(!line.empty()){
            tmpfile += line + "\n";
        }
    }

    loadfile.close();

    ofstream WriteFile("Product.txt");
    if (!WriteFile.is_open()){
        cout << "Error" << endl;
    }

    WriteFile << tmpfile;
    WriteFile.close();

    cout << "\nData has been edited!" << endl;

}

void SearchFile(string searchid){

    string id;
    string fullline;

    fstream searchproduct("Product.txt", ios::in);

    if (!searchproduct.is_open()){
        cout << "Error" << endl;
    }else{
        bool found;

        while(getline(searchproduct,id,',') && getline(searchproduct, fullline)){
            if (id == searchid){
                cout << "Product Found" << endl;
                cout << "ID\tName\tPrice\tQuantity" << endl << endl;
                replace (fullline.begin(),fullline.end(),',','\t');
                cout << id <<"\t" << fullline << endl;
                found = true;
            }
        }

        if (!found){
            cout << "No record found" << endl;
        }
        return;
    }
}
};

int main(){

    Taskoption();
    int choice;
    cout << "Enter your choice: ";
    while(!(cin >> choice)){
        cout << "Invalid input. Please enter a valid integer for choice: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if(choice == 1){
        do{
            stock option;
            option.TaskOptionstock();
            cout << "\nEnter preference: ";
            cin  >> choice;

            switch (choice){
            case 1:
                    {
                        stock add;
                        add.AddStockDetails();
                        break;
                    }
            case 2:
                    {
                        stock display;
                        display.viewstock();
                        break;
                    }
            case 3:
                    {
                        stock display;
                        display.viewstock();
                        stock edit;
                        edit.editstock();
                        break;
                    }
            case 4:
                    {
                        string id;
                        cout << "Enter ID to search: ";
                        cin >> id;
                        stock searchid;
                        searchid.SearchFile(id);
                        break;
                    }
            case 5:
                    {
                        char ans;
                        cout << "are u sure to exit?(y/n)" << endl;
                        cout << "Enter ans: ";
                        cin  >> ans;

                        if (ans == 'y' || ans == 'Y'){
                            cout << "Bye bye";
                            return 0;
                        }
                        break;
                    }
            default:
                cout << "Invalid choice! Please try again" << endl;
            }

        }while (choice = 5);

    }else if (choice == 2){
            do{
                Product option;
                option.TaskOptionproduct();
                cout << "\nEnter preference: ";
                cin  >> choice;

                switch (choice){
                case 1:
                        {
                            Product add;
                            add.Addproductdetails();
                            break;
                        }
                case 2:
                        {
                            Product display;
                            display.viewproduct();
                            break;
                        }
                case 3:
                        {
                            Product display;
                            display.viewproduct();
                            Product edit;
                            edit.editproduct();
                            break;
                        }
                case 4:
                        {
                            string id;
                            cout << "Enter ID to search: ";
                            cin  >> id;
                            Product searchid;
                            searchid.SearchFile(id);
                            break;
                        }
                case 5:
                        {
                            char ans;
                            cout << "are u sure to exit?(y/n)" << endl;
                            cout << "Enter ans: ";
                            cin  >> ans;

                            if (ans == 'y' || ans == 'Y'){
                                cout << "Bye bye";
                                return 0;
                            }
                            break;

                        }
            default:
                cout << "Invalid choice! Please try again" << endl;
        }

        }while (choice = 5);

    }else {cout << "Invalid choice" << endl;};
}
