#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure to represent an inventory item
struct Items 
{
    string n;
    int q;
    double p;
};

// Function to add an item to the inventory
void AddItem( vector<Items>& inventory ) 
{
    Items i;
    cout<<"\n|--------------------------------------------|\n";
    cout<<"|                                             \n";
    cout<<"|    Enter item name : ";
    cin.ignore();
    getline( cin,i.n );
    cout<<"|    Enter item quantity : ";
    cin>>i.q;
    cout<<"|    Enter item price : ";
    cin>>i.p;
    inventory.push_back( i );
    cout<<"|                                            |\n";
    cout<<"|         Item added successfully...         |\n";
    cout<<"|--------------------------------------------|\n";
}

// Function to update an existing item
void UpdateItem( vector<Items>& inventory ) 
{
    int INo;
    if( inventory.empty() ) 
	{
		cout<<"\n|--------------------------------------------|\n";
        cout<<"|         No items available to update.      |\n";
        cout<<"|--------------------------------------------|\n";
        return;
    }
    cout<<"\n|--------------------------------------------|\n";
    cout<<"|                                            |\n";
    cout<<"|  Enter the item number to update : ";
    cin>>INo;
    cout<<"|                                            |\n";
    if( INo<1 || INo>inventory.size() ) 
	{
        cout<<"|       Invalid item number! Try again.      |\n";
        cout<<"|--------------------------------------------|\n";
    } 
	else 
	{
        Items& i = inventory[ INo-1 ];
        cout<<"|  Enter new quantity for "<<i.n<<" : ";
        cin>>i.q;
        cout<<"|  Enter new price for "<<i.n<<" : ";
        cin>>i.p;
        cout<<"|                                            |\n";
        cout<<"|          Item updated successfully         |\n";
        cout<<"|--------------------------------------------|\n";
    }
}

// Function to remove an item from the inventory
void RemoveItem( vector<Items>& inventory ) 
{
    int INo;
    if( inventory.empty() ) 
	{
		cout<<"\n|--------------------------------------------|\n";
        cout<<"|       No items available to remove.        |\n";
        cout<<"|--------------------------------------------|\n";
        return;
    }
    cout<<"\n|--------------------------------------------|\n";
    cout<<"|                                            |\n";
    cout<<"|  Enter the item number to remove : ";
    cin>>INo;
    cout<<"|                                            |\n";
    if( INo<1 || INo>inventory.size() ) 
	{
        cout<<"|       Invalid item number! Try again.      |\n";
    } 
	else 
	{
        cout<<"|  "<<inventory[INo - 1].n<<" removed from inventory. \n";
        inventory.erase(inventory.begin() + INo - 1);
    }
    cout<<"|                                            |\n";
    cout<<"|--------------------------------------------|\n";
}

// Function to display all items in the inventory
void ViewInventory( const vector<Items>& inventory ) 
{
    if( inventory.empty() ) 
	{
		cout<<"\n|--------------------------------------------|\n";
        cout<<"|          The inventory is empty.           |\n";
        cout<<"|--------------------------------------------|\n";
        return;
    }
    cout<<"\n|--------------------------------------------|\n";
    cout<<"|                                            |\n";
    cout<<"|             Inventory List                 |\n";
    cout<<"|                                            |\n";
    cout<<"|  No.  Name               Quantity  Price   |\n";
    cout<<"|                                            |\n";
    for( size_t i=0; i<inventory.size(); ++i) 
	{
        cout<<"|  "<<i+1<<".   "<<inventory[i].n;
        cout<<string( 20-inventory[i].n.length(),' ' )<<inventory[i].q;
        cout<<"        "<<inventory[i].p<<"$ \n";
    }
    cout<<"|                                            |\n";
    cout<<"|--------------------------------------------|\n";
}

// Main function to manage the inventory
int main() 
{
    vector<Items> inventory;
    int c;
    do 
	{
		cout<<"\n|---------------------------------------|\n";
    	cout<<"|                                       |\n";
        cout<<"|    ~~ Inventory Management Menu ~~    |\n";
        cout<<"|                                       |\n";
        cout<<"|    1. Add Item.                       |\n";
        cout<<"|    2. Update Item.                    |\n";
        cout<<"|    3. Remove Item.                    |\n";
        cout<<"|    4. View Inventory.                 |\n";
        cout<<"|    5. Exit.                           |\n";
        cout<<"|                                       |\n";
        cout<<"|---------------------------------------|\n";
        cout<<"\nEnter your choice : ";
        cin>>c;

        switch(c) 
		{
            case 1:
                AddItem(inventory);
                break;
                
            case 2:
                UpdateItem(inventory);
                break;
                
            case 3:
                RemoveItem(inventory);
                break;
                
            case 4:
                ViewInventory(inventory);
                break;
                
            case 5:
                cout<<"\n|----------------------------------|\n";
                cout<<"|                                  |\n";
                cout<<"|  Exiting the program. Goodbye !! |\n";
                cout<<"|                                  |\n";
                cout<<"|----------------------------------|\n";
                break;
                
            default:
                cout<<"\n|-------------------------------------|\n";
                cout<<"|                                     |\n";
                cout<<"|  Invalid choice! Please try again.  |\n";
                cout<<"|                                     |\n";
                cout<<"|-------------------------------------|\n";
        }
    } 
	while( c!=5 );
    return 0;
}
