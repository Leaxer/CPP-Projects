#include "SchoolManagerSystem.h"

namespace PA4
{
    // Forward declarations for this functions
    void InputNameAndID(string& name, int& id);
    void InputNameAndCode(string& name, string& code);

    SchoolManagementSystem::SchoolManagementSystem() {
        // Sets values
        courseReferences = nullptr;
        studentReferences = nullptr;
        studentSize = 0;
        courseSize = 0;
    }
    SchoolManagementSystem::SchoolManagementSystem(const SchoolManagementSystem& other) {
        // Sets size values
        studentSize = other.studentSize;
        courseSize = other.courseSize;
        // If size of student is zero
        if(studentSize == 0) {
            studentReferences = nullptr; // Set dynamic array to nullptr
        }else {
            studentReferences = new Student[studentSize]; // Allocate memory by given size
            for(int i = 0;i < studentSize;i++) {
                studentReferences[i] = other.studentReferences[i]; // Set student objects one by one
            }
        }
        // If size of course is zero
        if(courseSize == 0) {
            courseReferences = nullptr; // Set dynamic array to nullptr
        }else {
            courseReferences = new Course[courseSize]; // Allocate memory by given size
            for(int i = 0;i < courseSize;i++) {
                courseReferences[i] = other.courseReferences[i]; // Set course objects one by one
            }
        }
    }
    SchoolManagementSystem::~SchoolManagementSystem() {
        // If it's not allocated
        if(courseReferences != nullptr) {
            delete[] courseReferences; // Free memory
        }
        // If it's not allocated
        if(studentReferences != nullptr) {
            delete[] studentReferences; // Free memory
        }
    }
    void SchoolManagementSystem::SetCourseReferences(Course *_courseReferences, int size) {
        // If size of course is not zero
        if(courseSize != 0) {
            delete[] courseReferences; // Free memory
        }
        // If size coming from parameter is not zero
        if(size != 0) {
            courseReferences = new Course[size]; // Allocate memory
            for(int i = 0;i < size;i++) { // Loop until it reaches size
                courseReferences[i] = _courseReferences[i]; // Set course objects one by one
            }
        }
        // If size is zero
        else {
            courseReferences = nullptr;
        }
        courseSize = size; // Set size to parameter
    }
    Course* SchoolManagementSystem::GetCourseReferences() const {
        return courseReferences;
    }
    void SchoolManagementSystem::SetStudentReferences(Student *_studentReferences, int size) {
        // If size of student is not zero
        if(studentSize != 0) {
            delete[] studentReferences; // Free memory
        }
        // If size coming from parameter is not zero
        if(size != 0) {
            studentReferences = new Student[size]; // Allocate memory
            for(int i = 0;i < size;i++) { // Loop until it reaches size
                studentReferences[i] = _studentReferences[i]; // Set student objects one by one
            }
        }
        // If size is zero
        else {
            studentReferences = nullptr;
        }
        studentSize = size; // Set size to parameter
    }
    Student* SchoolManagementSystem::GetStudentReferences() const {
        return studentReferences;
    }
    void SchoolManagementSystem::Menu() {
        int choice;
        // Loop until user choose zero
        do {
            cout << "Main_menu" << endl;
            cout << "0 exit" << endl;
            cout << "1 student" << endl;
            cout << "2 course" << endl;
            cout << "3 list_all_students" << endl;
            cout << "4 list_all_courses" << endl;
            cout << ">> ";
            cin >> choice;
            if(choice == 1) {
                StudentMenu();
            }else if(choice == 2) {
                CourseMenu();
            }else if(choice == 3) {
                ListAllStudents();
            }else if(choice == 4) {
                ListAllCourses();
            }
        }while(choice != 0);
    }
    void SchoolManagementSystem::StudentMenu() {
        int choice;
        // Loop until user choose zero
        do {
            cout << "0 up" << endl;
            cout << "1 add_student" << endl;
            cout << "2 select_student" << endl;
            cout << ">> ";
            cin >> choice;
            if(choice == 1) {
                this->AddStudent();
            }else if(choice == 2) {
                SelectStudentMenu();
            }
        }while(choice != 0);
    }
    void SchoolManagementSystem::SelectStudentMenu() {
        int choice,index = -1;
        string name = "";
        int id;
        InputNameAndID(name,id); // Call function and get name and id values from user
        for(int i = 0;i < studentSize;i++) {
            if(studentReferences[i].id == id && studentReferences[i].name == name) {
                index = i;
                break;
            }
        }
        if(index == -1) {
            cout << "There isn't any student with this id" << endl;
            return;
        }
        do {
            cout << "0 up" << endl;
            cout << "1 delete_student" << endl;
            cout << "2 add_selected_student_to_a_course" << endl;
            cout << "3 drop_selected_student_from_a_course" << endl;
            cout << ">> ";
            cin >> choice;
            if(choice == 1) {
                this->DeleteStudent(index);
                choice = 0;
            }else if(choice == 2) {
                add_selected_student_to_a_course(index);
            }else if(choice == 3) {
                drop_selected_student_from_a_course(index);
            }
        }while(choice != 0);
    }
    void SchoolManagementSystem::CourseMenu() {
        int choice;
        // Loop until user choose zero
        do {
            cout << "0 up" << endl;
            cout << "1 add_course" << endl;
            cout << "2 select_course" << endl;
            cout << ">> ";
            cin >> choice;
            if(choice == 1) {
                this->AddCourse();
            }else if(choice == 2) {
                SelectCourseMenu();
            }
        }while(choice != 0);
    }
    void SchoolManagementSystem::SelectCourseMenu() {
        int choice,index = -1;
        string name = "";
        string code = "";
        InputNameAndCode(name,code); // Call function and get name and code values from user
        for(int i = 0;i < courseSize;i++) {
            if(courseReferences[i].code == code && courseReferences[i].name == name) {
                index = i;
                break;
            }
        }
        if(index == -1) {
            cout << "There isn't any course with this code" << endl;
            return;
        }
        do {
            cout << "0 up" << endl;
            cout << "1 delete_course" << endl;
            cout << "2 list_students_registered_to_the_selected_course" << endl;
            cout << ">> ";
            cin >> choice;
            if(choice == 1) {
                this->DeleteCourse(index);
                choice = 0;
            }else if(choice == 2) {
                // List the students enrolled in course
                for(int j = 0;j < courseReferences[index].registeredStudents;j++) {
                    cout << j+1 << " " << this->courseReferences[index].studentReferences[j].id << " " << this->courseReferences[index].studentReferences[j].name << endl;
                }
            }
        }while(choice != 0);
    }
    void SchoolManagementSystem::ListAllStudents() {
        // List all students
        for(int i = 0;i < studentSize;i++) {
            cout << i+1 << "-" << studentReferences[i] << endl;
        }
    }
    void SchoolManagementSystem::ListAllCourses() {
        // List all courses
        for(int i = 0;i < courseSize;i++) {
            cout << i+1 << "-" << courseReferences[i] << endl;
        }
    }
    void SchoolManagementSystem::AddStudent() {
        string name = "";
        int id;
        InputNameAndID(name,id); // Call function and get name and id values from user
        for(int i = 0;i < studentSize;i++) {
            if(id == studentReferences[i].id) {
                cout << "There is already a student with this id" << endl;
                return;
            }
        }
        Student *tempStudentArr = new Student[studentSize+1];// Initialize new temp dynamic array and allocate one more memory than size
        for(int i = 0;i < studentSize;i++) {
            tempStudentArr[i] = studentReferences[i]; // Set student objects one by one
        }
        tempStudentArr[studentSize] = Student(name,id); // Add the desired student to the last index
        // If size of student is not zero
        if(this->studentSize != 0) {
            delete[] studentReferences; // Free memory
        }
        studentSize++; // Increase size one
        studentReferences = tempStudentArr; // Set temp array to studentReferences
    }
    void SchoolManagementSystem::DeleteStudent(const int index) {
        // Loop the course size
        for(int i = 0;i < courseSize;i++) {
            for(int j = 0;j < courseReferences[i].registeredStudents;j++) {
                // If the id of the student in the course is equal to the id of the student to be deleted, delete this student from course
                if(courseReferences[i].studentReferences[j].id == studentReferences[index].id) {
                    courseReferences[i].DeleteStudent(studentReferences[index].id);
                }
            }
        }
        // Initialize and allocate temp Student array
        Student *temp = new Student[studentSize-1];
        int a = 0;
        for(int i = 0;i < studentSize;i++) {
            if(i != index) {
                temp[a] = studentReferences[i]; // Get the students except index
                ++a;
            }
        }
        studentSize--; // Decrease size
        delete[] studentReferences; // Free memory
        studentReferences = temp;
    }
    void SchoolManagementSystem::add_selected_student_to_a_course(const int index) {
        cout << "0 up" << endl;
        int a = 1;
        int courseChoice;
        int size = courseSize - studentReferences[index].registeredCourses; // Find the range
        // Initialize and allocate temp code and names
        string *tempCode = new string[courseSize];
        string *tempName = new string[courseSize];
        // List courses which is not taken by student
        for(int i = 0;i < courseSize;i++) {
            int check = 0;
            for(int j = 0;j < studentReferences[index].registeredCourses;j++) {
                // If program find the course on student's course
                if(courseReferences[i].code == this->studentReferences[index].courseReferences[j].code) {
                    check = 1; // Check 1
                }
            }
            if(check == 0) {
                // If it's not on the student's courses
                tempCode[a-1] = courseReferences[i].code;
                tempName[a-1] = courseReferences[i].name;
                cout << a << " " << courseReferences[i].code << " " << courseReferences[i].name << endl;
                ++a;
            }
        }
        cout << ">> ";
        // Choose course
        cin >> courseChoice;
        // If choice is not in range
        if(courseChoice <= 0 || courseChoice > size) {

        }else {
            // Add chosen course to student
            studentReferences[index].AddCourse(tempCode[courseChoice-1], tempName[courseChoice-1]);
            for(int i = 0;i < courseSize;i++) {
                // Find the course
                if(tempCode[courseChoice-1] == courseReferences[i].code) {
                    // Add this student to course
                    this->courseReferences[i].AddStudent(studentReferences[index].name,studentReferences[index].id);
                    break;
                }
            }
        }
        // Free memory
        delete[] tempCode;
        delete[] tempName;
    }
    void SchoolManagementSystem::drop_selected_student_from_a_course(const int index) {
        cout << "0 up" << endl;
        int courseChoice;
        // Initialize and allocate temp code
        string *tempCode = new string[courseSize];
        // Loop the courses taken by student and print
        for(int j = 0;j < studentReferences[index].registeredCourses;j++) {
            tempCode[j] = this->studentReferences[index].courseReferences[j].code; // Storage code of courses temporarily
            cout << j+1 << " " << this->studentReferences[index].courseReferences[j].code << " " << this->studentReferences[index].courseReferences[j].name << endl;
        }
        cout << ">> ";
        // Choose course
        cin >> courseChoice;
        if(courseChoice <= 0 || courseChoice > studentReferences[index].registeredCourses) {

        }else {
            studentReferences[index].DeleteCourse(tempCode[courseChoice-1]); // Delete desired course from student
            for(int i = 0;i < courseSize;i++) {
                // If temp code is equal to courseReferences's code
                // That means course is taken by student, we'll remove the student from class
                if(tempCode[courseChoice-1] == courseReferences[i].code) {
                    this->courseReferences[i].DeleteStudent(studentReferences[index].id);
                    break;
                }
            }
        }
        delete[] tempCode; // Free memory
    }
    void SchoolManagementSystem::AddCourse() {
        string name = "";
        string code = "";
        InputNameAndCode(name,code); // Call function and get name and code values from user
        for(int i = 0;i < courseSize;i++) {
            if(code == courseReferences[i].code) {
                cout << "There is already a course with this code" << endl;
                return;
            }
        }
        Course *tempCourseArr = new Course[courseSize+1]; // Initialize new temp dynamic array and allocate one more memory than size
        for(int i = 0;i < courseSize;i++) {
            tempCourseArr[i] = courseReferences[i]; // Set course objects one by one
        }
        tempCourseArr[courseSize] = Course(name,code); // Add the desired course to the last index
        // If size of course is not zero
        if(this->courseSize != 0) {
            delete[] courseReferences; // Free memory
        }
        courseSize++; // Increase size one
        courseReferences = tempCourseArr; // Set temp array to courseReferences
    }
    void SchoolManagementSystem::DeleteCourse(const int index) {
        // Loop the student size
        for(int i = 0;i < studentSize;i++) {
            for(int j = 0;j < studentReferences[i].registeredCourses;j++) {
                // If the code of the course in the student is equal to the code of the course to be deleted, delete this course from student
                if(studentReferences[i].courseReferences[j].code == courseReferences[index].code) {
                    studentReferences[i].DeleteCourse(courseReferences[index].code);
                }
            }
        }
        // Initialize and allocate temp Course array
        Course *temp = new Course[courseSize-1];
        int a = 0;
        for(int i = 0;i < courseSize;i++) {
            if(i != index) {
                temp[a] = courseReferences[i]; // Get the students except index
                ++a;
            }
        }
        courseSize--; // Decrease size
        delete[] courseReferences; // Free memory
        courseReferences = temp;
    }
    void InputNameAndID(string& name, int& id) {
        string line;
        string number = "";
        cout << ">> ";
        cin.ignore(2,'\n');
        getline(cin, line);
        for(char c : line) {
            if(c > 47 && c < 58) {
                number += c;
            }else {
                name += c;
            }
        }
        id = stoi(number);
    }
    void InputNameAndCode(string& name, string& code) {
        cout << ">> ";
        cin.ignore(2,'\n');
        getline(cin, code, ' ');
        getline(cin, name);
    }
}