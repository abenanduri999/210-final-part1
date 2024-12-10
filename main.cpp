#include <iostream>
#include <string>
#include <array>
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

void addCustomer(Coffee * head, string n, string o)
{
    Coffee* newCoffee = new Coffee; 
    newCoffee->name = n; 
    newCoffee->order = o;

    newCoffee->next = head;
    head = newCoffee; 
}

int main(){


    string names[30] = {"Olivia", "Liam", "Emma", "Noah", "Ava", "James", "Sophia", "Benjamin", "Isabella", "Elijah", 
         "Mia", "Lucas", "Amelia", "Henry", "Harper", "Alexander", "Charlotte", "Mason", "Evelyn", "Daniel", 
         "Scarlett", "Jack", "Grace", "Samuel", "Ella", "William", "Zoe", "Jack", "Lily", "Michael"};
     //names generated online

    string drinks[10] = {"Espresso", "Americano", "Cappachino",  "Latte",  "Macchiato", "Mocha", 
                     "Flat White", "Cold Brew",  "Iced Latte",  "Affogato"};

    Coffee* coffeeLine = nullptr;
    
     

    int cust = rand() % 30; 
    int ord = rand() % 10;
    
    addCustomer(coffeeLine, names[cust], drinks[ord]); 
    
   /* for(int i = 0; i < 10; i++)
    {

    }*/


    return 0; 
}
