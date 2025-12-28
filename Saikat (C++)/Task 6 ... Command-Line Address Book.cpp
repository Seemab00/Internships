#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Contact 
{
    string name, phoneNumber, email;
};

// Function to add a new contact
void AddContact( vector<Contact>& addressBook ) 
{
    Contact newContact;
    cout<<"\n|----------------------------------------------|\n";
    cout<<"|                                               \n";
    cout<<"|    Enter contact name : ";
    cin.ignore(); 
    getline( cin,newContact.name );
    cout<<"|    Enter phone number : ";
    getline( cin,newContact.phoneNumber );
    cout<<"|    Enter email address : ";
    getline( cin,newContact.email );
    addressBook.push_back( newContact );
    cout<<"|                                              |\n";
    cout<<"|       The Contact is added successfully      |\n";
    cout<<"|                                              |\n";
    cout<<"|----------------------------------------------|\n";
}

// Function to search for a contact by name
void SearchContact( const vector<Contact>& addressBook ) 
{
    string searchName;
    cout<<"\n|--------------------------------------------------|\n";
    cout<<"|                                                   \n";
    cout<<"|  Enter the name you want to search : ";
    cin.ignore();
    getline( cin,searchName );
    bool found = false;
    for( const auto& contact : addressBook ) 
	{
        if( contact.name==searchName ) 
		{
            cout<<"|                                                  |\n";
            cout<<"|               ~~ Contact Found ~~                |\n";
            cout<<"|                                                  |\n";
            cout<<"|    Name : "<<contact.name;
            cout<<"|    Phone Number : "<<contact.phoneNumber;
            cout<<"|    Email : "<<contact.email;
            cout<<"|                                                  |\n";
            cout<<"|--------------------------------------------------|\n";
            found = true;
            break;
        }
    }

    if(!found) 
	{
		cout<<"|                                                  |\n";
        cout<<"|               Contact is not found               |\n";
        cout<<"|                                                  |\n";
        cout<<"|--------------------------------------------------|\n";
    }
}

// Function to display all contacts
void DisplayContacts( const vector<Contact>& addressBook ) 
{
    if( addressBook.empty() )  
	{
		cout<<"\n|--------------------------------|\n";
        cout<<"|                                |\n";
        cout<<"|     Address book is empty.     |\n";
        cout<<"|                                |\n";
        cout<<"|--------------------------------|\n";
        return;
    }
    cout<<"\n|--------------------------------|\n";
    cout<<"|                                |\n";
    cout<<"|           All Contacts         |\n";
    for( const auto& contact : addressBook ) 
	{
		cout<<"|                                |\n";
        cout<<"|    Name : "<<contact.name<<" \n";
        cout<<"|    Phone Number : "<<contact.phoneNumber<<" \n";
        cout<<"|    Email : "<<contact.email<<" \n";
        cout<<"|                                |\n";
    }
    cout<<"|--------------------------------|\n";
}

// Main function to control the address book program
int main() 
{
    vector<Contact> addressBook;
    int c;

    do{
    	cout<<"\n|--------------------------------|\n";
    	cout<<"|                                |\n";
        cout<<"|     ~~ Address Book Menu ~~    |\n";
        cout<<"|                                |\n";
        cout<<"|  1. Add Contact.               |\n";
        cout<<"|  2. Search Contact.            |\n";
        cout<<"|  3. Display All Contacts.      |\n";
        cout<<"|  4. Exit.                      |\n";
        cout<<"|                                |\n";
        cout<<"|--------------------------------|\n";
        cout<<"\nEnter your choice : ";
        cin>>c;
        switch(c) 
		{
            case 1:
                AddContact(addressBook);
                break;
                
            case 2:
                SearchContact(addressBook);
                break;
                
            case 3:
                DisplayContacts(addressBook);
                break;
                
            case 4:
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
	while( c!=4 );

    return 0;
}
