#include<iostream>
#include<vector>
using namespace std;

// Structure to represent a task
struct Task 
{
    string dscrp;
    bool isComplete;
};

// Function to add a task
void AddTask( vector<Task>& TList ) 
{
    Task T;
    cout<<"\n|------------------------------------------|\n";
    cout<<"|                                             \n";
    cout<<"|  Enter task description : ";
    cin.ignore();
    getline(cin, T.dscrp);
    T.isComplete = false; // Task starts as incomplete
    TList.push_back(T);
    cout<<"|                                          |\n";
    cout<<"|         Task added successfully...       |\n";
    cout<<"|------------------------------------------|\n";
}

// Function to mark a task as complete
void MarkTaskComplete( vector<Task>& TList ) 
{
    int TNo;
    if( TList.empty() ) 
	{
		cout<<"\n|-------------------------------------------|\n";
        cout<<"|                                           |\n";
        cout<<"|  No tasks available to mark as complete.  |\n";
        cout<<"|                                           |\n";
        cout<<"|-------------------------------------------|\n";
        return;
    }
    cout<<"\n|--------------------------------------------------|\n";
    cout<<"|                                                  |\n";
    cout<<"| Enter the task number to mark as complete : ";
    cin>>TNo;
    cout<<"|                                                  |\n";
    if( TNo<1 || TNo>TList.size() ) 
	{
        cout<<"|         Invalid task number! Try again.          |\n";
        cout<<"|--------------------------------------------------|\n";
    } 
	else 
	{
        TList[ TNo-1 ].isComplete = true;
        cout<<"|            Task marked as complete.              |\n";
        cout<<"|--------------------------------------------------|\n";
    }
}

// Function to list all tasks
void ListTasks( const vector<Task>& TList ) 
{
    if( TList.empty() ) 
	{
		cout<<"\n|--------------------------------|\n";
        cout<<"|                                | \n";
        cout<<"|  No tasks in the to-do list.   |\n";
        cout<<"|                                |\n";
        cout<<"|--------------------------------|\n";
        return;
    }
    cout<<"\n|--------------------------------|\n";
    cout<<"|                                |\n";
    cout<<"|       ~~ To-Do List ~~         |\n";
    cout<<"|                                |\n";
    for( size_t i=0; i<TList.size(); ++i ) 
	{
        cout<<"| "<<i+1<<".  "<<TList[i].dscrp;
        if( TList[i].isComplete ) 
		{
            cout<<" [Completed]... \n";
        }
        cout<<"  \n";
    }
    cout<<"|                                |\n";
    cout<<"|--------------------------------|\n";
}

// Function to delete a task
void DeleteTask( vector<Task>& TList ) 
{
    int TNo;
    if( TList.empty() ) 
	{
		cout<<"\n|--------------------------------|\n";
        cout<<"|                                |\n";
        cout<<"|  No tasks available to delete. |\n";
        cout<<"|                                |\n";
        cout<<"|--------------------------------|\n";
        return;
    }
    cout<<"\n|---------------------------------------|\n";
    cout<<"|                                       |\n";
    cout<<"|  Enter the task number to delete : ";
    cin>>TNo;
    cout<<"|                                       |\n";
    if( TNo<1 || TNo>TList.size() ) 
	{
        cout<<"|   Invalid task number. Try again...   |\n";
        cout<<"|---------------------------------------|\n";
    } 
	else 
	{
        TList.erase( TList.begin()+TNo-1 );
        cout<<"|       Task deleted successfully.      |\n";
        cout<<"|---------------------------------------|\n";
    }
}

// Main function to manage the to-do list application
int main() 
{
    vector<Task> TList;
    int c;

    do{
    	cout<<"\n|-----------------------------|\n";
    	cout<<"|                             |\n";
        cout<<"|    ~~ To-Do List Menu ~~    |\n";
        cout<<"|                             |\n";
        cout<<"|  1. Add Task.               |\n";
        cout<<"|  2. Mark Task as Complete.  |\n";
        cout<<"|  3. List All Tasks.         |\n";
        cout<<"|  4. Delete Task.            |\n";
        cout<<"|  5. Exit.                   |\n";
        cout<<"|                             |\n";
        cout<<"|-----------------------------|\n";
        cout<<"\nEnter your choice : ";
        cin>>c;

        switch(c) 
		{
            case 1:
                AddTask(TList);
                break;
                
            case 2:
                MarkTaskComplete(TList);
                break;
                
            case 3:
                ListTasks(TList);
                break;
                
            case 4:
                DeleteTask(TList);
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
