#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
private:
    int id;
    string name;
    float marks;

public:
    // Constructor
    Student(int i, string n, float m) {
        id = i;
        name = n;
        marks = m;
    }

    // Getter for marks (used in sorting)
    float getMarks() const {
        return marks;
    }

    // Function to display student details
    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Marks: " << marks << endl;
    }
};

// Function to compare students by marks (for sorting)
bool compareByMarks(const Student &a, const Student &b) {
    return a.getMarks() > b.getMarks(); // Descending order
}

int main() {
    vector<Student> students;
    int n, id;
    string name;
    float marks;

    cout << "Enter number of students: ";
    cin >> n;

    // Input student data
    for (int i = 0; i < n; ++i) {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> id;
        cout << "Name: ";
        cin.ignore(); // clear newline
        getline(cin, name);
        cout << "Marks: ";
        cin >> marks;

        students.push_back(Student(id, name, marks));
    }

    // Sort students by markss
    sort(students.begin(), students.end(), compareByMarks);

    // Display sorted students
    cout << "\n--- Students Sorted by Marks (Descending) ---\n";
    for (const Student &s : students) {
        s.display();
    }

    return 0;
}


