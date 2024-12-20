#include <iostream>
#include <string>
#include <array>
#include <ctime>
#include <deque>
#include <vector>
#include <stack>


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

    else
    {
    Coffee* temp = head; 
    head = head -> next; 
    delete temp;
    } 
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

Customer createCust(string n, string o)
{
    Customer temp;
    temp.name = n;
    temp.order = o;

    return temp;
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

    string friendBColors[10] = {"Blue", "Red", "White", "Black", "Green",
                                "Brown", "Gray", "Purple", "cyan", "Pink"};

    string flavors[10] = {"Choco", "Mint Choco", "Vanilla", "Bubble gum", "pistachio",
                        "mint", "Rocky Road", "fudge", "peanut butter", "cherry"};

    Coffee* coffeeLine = nullptr;
    deque <pair<string, string>> muffinLine; 
    vector<Customer> friendBr; 
    stack<Customer> iceCreamLine; 
    

    
     
    srand(time(0));
    
    int cust = 0;
    int ord = 0;
    for(int j = 0; j < 3; j++)
    {
        int cust = rand() % 30; 
        int ord = rand() % 10;
        addCustomer(coffeeLine, names[cust], drinks[ord]); 
        
        cust = rand() % 30; 
        ord = rand() % 10;
        muffinLine.push_back({names[cust], muffins[ord]}); 

        cust = rand() % 30; 
        ord = rand() % 10;
        Customer temp;
        friendBr.push_back(createCust(names[cust], friendBColors[ord])); 
        //temp.name = names[cust]; 
        //temp.order = friendBColors[ord]; 
        //friendBr.push_back(temp);  

        cust = rand()% 30; 
        ord = rand()% 10;
        iceCreamLine.push(createCust(names[cust], flavors[ord])); 
    }
    
    cout<<"Coffee Line:"<<endl; 
    printList(coffeeLine);
    cout<<endl; 

    cout<<"Muffin Line:"<<endl; 
    for(const auto& pair: muffinLine)
    {
        cout<<pair.first<<" "<<pair.second<<endl; 
    }
    cout<<endl; 

    cout<<"Friendship Bracelet Line:"<<endl; 
    for(int k = 0; k < friendBr.size(); k++)
    {
        cout<<friendBr[k].name<<" "<<friendBr[k].order<<endl;
    }
    cout<<endl;

    cout<<"Ice Cream Line: "<<endl; 
    stack<Customer>temp; 

    while(!iceCreamLine.empty())
    {
        cout<<iceCreamLine.top().name<<" "<<iceCreamLine.top().order<<endl; 
        temp.push(iceCreamLine.top());
        iceCreamLine.pop(); 
    }
    while(!temp.empty())
    {
        iceCreamLine.push(temp.top());
        temp.pop();
    }
    

    for(int i = 0; i < 10; i++)
    {   
        cout<<"Round "<<i<<endl;

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

        prob = rand() % 100; 
        cout<<"Muffin Line:"<<endl; 
        if(prob <= 50)
        {
        cust = rand() % 30; 
        ord = rand() % 10;
        muffinLine.push_back({names[cust], muffins[ord]});
            if(muffinLine.empty())
            {
                cout<<"The muffin Line is empty"<<endl; 
            }
            else
            {
                for(const auto& pair : muffinLine)
                {
                    cout<<pair.first<<" "<<pair.second<<endl;
                }
            }
        cout<<endl;
        }

        else
        {
            if(muffinLine.empty())
            {
                cout<<"The Line is empty"<<endl; 
            }
            else
            {
                muffinLine.pop_front(); 
                for(const auto& pair : muffinLine)
                {
                cout<<pair.first<<" "<<pair.second<<endl;
                }
            }
            cout<<endl;

        }

        prob = rand() % 100; 
        cout<<"Friendship Bracelet Line:"<<endl;
        if(prob <= 50)
            {
                cust = rand() % 30;
                ord = rand() % 10;
                Customer temp; 
                friendBr.push_back(createCust(names[cust], friendBColors[ord]));
                //temp.name = names[cust];
                //temp.order = friendBColors[ord]; 
                //friendBr.push_back(temp);
                for(int l = 0; l < friendBr.size(); l++)
                {
                    cout<<friendBr[l].name<<" "<<friendBr[l].order<<endl;
                }
                cout<<endl; 
            }
        else
            {
                if(!friendBr.empty())
                {
                    friendBr.erase(friendBr.begin());
                }
                else
                {
                    cout<<"List is empty"<<endl; 
                }
                for(int h = 0; h < friendBr.size(); h++)
                {
                    cout<<friendBr[h].name<<" "<<friendBr[h].order<<endl;
                }
                cout<<endl; 
            
            }

        prob = rand() % 100; 
        cout<<"Ice Cream Line:"<<endl;
        if(prob <= 50)
        {
            cust = rand() % 30;
            ord = rand() % 10;
            iceCreamLine.push(createCust(names[cust], flavors[ord]));

            while(!iceCreamLine.empty())
            {
                cout<<iceCreamLine.top().name<<" "<<iceCreamLine.top().order<<endl; 
                temp.push(iceCreamLine.top());
                iceCreamLine.pop(); 
            }
            while(!temp.empty())
            {
                iceCreamLine.push(temp.top());
                temp.pop();
            }

        }
        else
        {
            if(iceCreamLine.empty())
            {
                cout<<"Line is empty"<<endl;
            }
            else
            {
                iceCreamLine.pop();
                while(!iceCreamLine.empty())
                {
                    cout<<iceCreamLine.top().name<<" "<<iceCreamLine.top().order<<endl; 
                    temp.push(iceCreamLine.top());
                    iceCreamLine.pop(); 
                }
                while(!temp.empty())  //copied my own code from up top to print the stack, i that why huge segments appeared 
                {
                    iceCreamLine.push(temp.top());
                    temp.pop();
                }

            }
        }
        cout<<endl;
    }


    return 0; 
}
