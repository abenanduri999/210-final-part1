#include <iostream>
#include <string>
#include <ctime>


using namespace std; 

//struct Customer
//{
 //   string name; 
  //  string order; 
//}; 

struct Coffee
{
    string name; 
    string order; 
    Coffee* next; 
};

int main(){


    string names[30] = {"Olivia", "Liam", "Emma", "Noah", "Ava", "James", "Sophia", "Benjamin", "Isabella", "Elijah", 
         "Mia", "Lucas", "Amelia", "Henry", "Harper", "Alexander", "Charlotte", "Mason", "Evelyn", "Daniel", 
         "Scarlett", "Jack", "Grace", "Samuel", "Ella", "William", "Zoe", "Jack", "Lily", "Michael"};
     //names generated online

    string drinks[10] = {"Espresso", "Americano", "Cappachino",  "Latte",  "Macchiato", "Mocha", 
                     "Flat White", "Cold Brew",  "Iced Latte",  "Affogato"};

    Coffee* coffeeLine; 
    

    return 0; 
}
