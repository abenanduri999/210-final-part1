#include <iostream>
#include <string>
#include <array>
#include <ctime>
#include <deque>


using namespace std; 

struct Customer
{
    string name; 
    string order; 
}; 

struct Coffee
{
    string name; 
    string order; 
    Coffee* next; 
};

void addCustomer(Coffee * &head, string n, string o)
{
    Coffee* newCoffee = new Coffee; 
    newCoffee->name = n; 
    newCoffee->order = o;

    newCoffee->next = head;
    head = newCoffee; 
}

void deleteCustomer(Coffee *&head)
{
    if(head == nullptr)
    {
        cout<<"The list is empty"<<endl;
    }
    
    Coffee* temp = head; 
    head = head -> next; 
    delete temp; 
}

void printList(Coffee *head)
{
    Coffee* current = head; 
    if(current == nullptr)
    {
        cout<<"The list is empty"<<endl; 
    }
    while(current != nullptr)
    {
        cout<<current->name<<" "<<current->order<<endl; 
        current = current->next; 
    }
}

int main(){


    string names[30] = {"Olivia", "Liam", "Emma", "Noah", "Ava", "James", "Sophia", "Benjamin", "Isabella", "Elijah", 
         "Mia", "Lucas", "Amelia", "Henry", "Harper", "Alexander", "Charlotte", "Mason", "Evelyn", "Daniel", 
         "Scarlett", "Jack", "Grace", "Samuel", "Ella", "William", "Zoe", "Jack", "Lily", "Michael"};
     //names generated online

    string drinks[10] = {"Espresso", "Americano", "Cappachino",  "Latte",  "Macchiato", "Mocha", 
                     "Flat White", "Cold Brew",  "Iced Latte",  "Affogato"};

    string muffins[10] ={"Blueberry", "chocolate", "bran", "poppy seed", "cinnamon", 
                        "Pumpkin", "Raspberry", "white choco", "lemon", "almond"}; 

    Coffee* coffeeLine = nullptr;
    deque <pair<string, string>> muffinLine; 

    
     
    srand(time(0));
    
    
    for(int j = 0; j < 3; j++)
    {
        int cust = rand() % 30; 
        int ord = rand() % 10;
        addCustomer(coffeeLine, names[cust], drinks[ord]); 
        cust = rand() % 30; 
        ord = rand() % 10;
        muffinLine.push_back({names[cust], muffins[ord]}); 
    }
    
    cout<<"Coffee Line:"<<endl; 
    printList(coffeeLine);
    cout<<endl; 
    cout<<"Muffin Line:"<<endl; 
    for(string c: coffeeLine)

    for(int i = 0; i < 10; i++)
    {
        int prob = rand() % 100; 
        cout<<"Coffee Line:"<<endl; 
        if(prob <= 50)
        {
            cust = rand() %30;
            ord = rand() % 10; 
            addCustomer(coffeeLine, names[cust], drinks[ord]);
            printList(coffeeLine);
            cout<<endl; 
        }
        else    
        {
            deleteCustomer(coffeeLine); 
            printList(coffeeLine); 
            cout<<endl; 
        }
    }


    return 0; 
}
