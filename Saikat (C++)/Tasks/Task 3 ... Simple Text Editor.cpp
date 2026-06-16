#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to create a new file and write data
void createFile() 
{
    string FName, data;
    cout<<"\n|----------------------------------------------------------------------------------------|\n";
    cout<<"|                                                                                         \n";
    cout<<"|  Create the name of the new file with extension, '.txt' , '.docs' ) : ";
    cin>>FName;
    ofstream outFile( FName );
    if( !outFile ) 
	{
		cout<<"|                                                                                        |\n";
        cout<<"|                            Error in creating the file!                                 |\n";
        cout<<"|----------------------------------------------------------------------------------------|\n";
        return;
    } 
	cout<<"|                                                                                        |\n";  
    cout<<"|                  Enter the data. Type 'END' on a new line to finish.                   |\n";
    cout<<"|                                                                                        |\n";
    cout<<"| ";
    cin.ignore(); 
    while( true ) 
	{
        getline(cin, data);
        if( data=="END" )
            break;
        outFile<<data<< endl;
    }
    outFile.close();
    cout<<"|                                                                                        |\n";
    cout<<"|                   File is created and data is saved successfully.                      |\n";
    cout<<"|----------------------------------------------------------------------------------------|\n";
}

// Function to open and display the data of an existing file
void openFile() 
{
    string FName, line;
    cout<<"\n|------------------------------------------------------------------|\n";
    cout<<"|                                                                     \n";
    cout<<"|  Enter the name of the file to open (with extension) : ";
    cin>>FName;
    ifstream inFile( FName );
    if( !inFile ) 
	{
		cout<<"|                                                                  |\n";
        cout<<"|         Error in opening file. Make sure the file exists.        |\n";
        cout<<"|------------------------------------------------------------------|\n";
        return;
    }
    cout<<"|                                                                  |\n";
    cout<<"|                ... The Data of this file is ...                  |\n";
    cout<<"|                                                                  |\n";
    cout<<"| ";
    while( getline(inFile,line) ) 
	{
        cout<<line<<endl;
    }
    cout<<"|                                                                  |\n";
    cout<<"|------------------------------------------------------------------|\n";
    inFile.close();
}

// Function to edit an existing file by updating content
void editFile() 
{
    string FName, data;
    cout<<"\n|--------------------------------------------------------------------|\n";
    cout<<"|                                                                       \n";
    cout<<"| Enter the name of the file to edit (with extension) : ";
    cin>>FName;
    ofstream outFile( FName, ios::app );
    if( !outFile ) 
	{
		cout<<"|                                                                       |\n";
        cout<<"|  Error in opening the file for editing. Make sure the file exists.    |\n";
        cout<<"|-----------------------------------------------------------------------|\n";
        return;
    }
    cout<<"|                                                                    |\n";
    cout<<"|  ~~ Enter the new content. Type 'END' on a new line to finish ~~   |\n";
    cout<<"|                                                                    |\n";
    cout<<"| ";
    cin.ignore(); 
    while( true ) 
	{
        getline(cin,data);
        if( data=="END" )
            break;
        outFile<<data<<endl;
    }
    outFile.close();
    cout<<"|                                                                     |\n";
    cout<<"|                  Data is updated successfully.                      |\n";
    cout<<"|---------------------------------------------------------------------|\n";
}

// Main function to manage the text editor
int main() 
{
    int c;
    do {
    	cout<<"\n|---------------------------------|\n";
    	cout<<"|                                 |\n";
        cout<<"|  ~~ Simple Text Editor Menu ~~  |\n";
        cout<<"|                                 |\n";
        cout<<"|  1. Create a New File.          |\n";
        cout<<"|  2. Open an Existing File.      |\n";
        cout<<"|  3. Edit an Existing File.      |\n";
        cout<<"|  4. Exit.                       |\n";
        cout<<"|                                 |\n";
        cout<<"|---------------------------------|\n";
        cout<<"\n Enter your choice: ";
        cin>>c;

        switch(c) 
		{
            case 1:
                createFile();
                break;
                
            case 2:
                openFile();
                break;
                
            case 3:
                editFile();
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
