#include "Course.h"

namespace PA4
{
    Course::Course() {
        // Sets values
        name = "";
        code = "";
        studentReferences = nullptr;
        registeredStudents = 0;
    }
    Course::Course(const string _name, const string _code) {
        // Sets values
        name = _name;
        code = _code;
        studentReferences = nullptr;
        registeredStudents = 0;
    }
    Course::Course(const Course& other) {
        // Sets values
        name = other.name;
        code = other.code;
        registeredStudents = other.registeredStudents;
        // If size of students enrolled in the course is zero, set array to nullptr
        if(other.registeredStudents == 0) {
            studentReferences = nullptr;
        }else {
            studentReferences = new Student[other.registeredStudents]; // Allocate memory
            for(int i = 0;i < other.registeredStudents;i++) {
                studentReferences[i] = other.studentReferences[i]; // Set student objects one by one
            }
        }
    }
    Course::~Course() {
        // If it's not allocated
        if(studentReferences != nullptr) {
            delete[] studentReferences; // Free memory
        }
    }
    void Course::SetName(string _name) {
        name = _name;
    }
    string Course::GetName() const {
        return name;
    }
    void Course::SetCode(string _code) {
        code = _code;
    }
    string Course::GetCode() const {
        return code;
    }
    void Course::SetStudentReferences(Student *_studentReferences, int size) {
        // If size of student is not zero
        if(registeredStudents != 0) {
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
        registeredStudents = size; // Set size to parameter
    }
    Student* Course::GetStudentReferences() const {
        return studentReferences;
    }
    void Course::AddStudent(string studentName, int id) {
        Student *temp = new Student[registeredStudents+1]; // Initialize new temp dynamic array and allocate one more memory than size
        for(int i = 0;i < registeredStudents;i++) {
            temp[i] = studentReferences[i]; // Set student objects one by one
        }
        // If size of student is not zero
        if(registeredStudents != 0) {
            delete[] studentReferences; // Free memory
        }
        // Set last index's values
        temp[registeredStudents].SetName(studentName);
        temp[registeredStudents].SetID(id);
        registeredStudents++; // Increase size one
        studentReferences = temp; // Set temp array to studentReferences
    }
    void Course::DeleteStudent(int id) {
        Student *temp = new Student[registeredStudents-1];// Initialize new temp dynamic array and allocate one less memory than size
        int a = 0;
        for(int i = 0;i < registeredStudents;i++) {
            // If id is given by parameter is not equal to studentReferences[i].id
            // That means we do not add the desired student to be deleted
            if(id != studentReferences[i].id) {
                temp[a] = studentReferences[i]; // Set student objects one by one
                ++a; // It increases every time program set one student object
            }
        }
        registeredStudents--; // Decrease size one
        delete[] studentReferences; // Free memory
        studentReferences = temp; // Set temp array to studentReferences
    }
    Course& Course::operator =(const Course& other) {
        // If we allocated memory for studentReferences
        if(studentReferences != nullptr) {
            delete[] studentReferences; // Free memory
        }
        // Set name and code values
        this->name = other.name;
        this->code = other.code;
        // If other object's size is zero, set studentReferences to nullptr and size to zero
        if(other.registeredStudents == 0) {
            studentReferences = nullptr;
            registeredStudents = 0;
        }
        // If other object's size is not zero
        else {
            registeredStudents = other.registeredStudents; // Set size to other object's size
            studentReferences = new Student[registeredStudents]; // Allocate memory by registeredStudent(size)
            for (int i = 0; i < registeredStudents; i++) {
                studentReferences[i] = other.studentReferences[i]; // Set student objects one by one
            }
        }
        return *this; // Return this object
    }
    ostream& operator <<(ostream &outputStream, const Course& other) {
        outputStream << other.code << " " << other.name;
        return outputStream;
    }
}