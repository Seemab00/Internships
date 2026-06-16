#include <iostream>
#include <vector>
using namespace std;

int main() {
    int numCourses;
    cout << "Enter number of courses: ";
    cin >> numCourses;

    vector<string> courseNames(numCourses);
    vector<double> grades(numCourses);
    vector<int> credits(numCourses);

    double totalPoints = 0.0;
    int totalCredits = 0;

    for (int i = 0; i < numCourses; i++) {
        cout << "Enter course name: ";
        cin >> courseNames[i];
        cout << "Enter grade (e.g., A=4.0, B=3.0): ";
        cin >> grades[i];
        cout << "Enter credit hours: ";
        cin >> credits[i];

        totalPoints += grades[i] * credits[i];
        totalCredits += credits[i];
    }

    double cgpa = (totalCredits > 0) ? totalPoints / totalCredits : 0.0;

    cout << "\nIndividual Grades:\n";
    for (int i = 0; i < numCourses; i++) {
        cout << courseNames[i] << ": Grade " << grades[i] << ", Credits " << credits[i] << endl;
    }
    cout << "Final CGPA: " << cgpa << endl;

    return 0;
}