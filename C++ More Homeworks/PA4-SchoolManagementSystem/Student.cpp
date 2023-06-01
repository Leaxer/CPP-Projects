#include "Student.h"

namespace PA4
{
    Student::Student() {
        // Sets values
        name = "";
        id = 0;
        courseReferences = nullptr;
        registeredCourses = 0;
    }
    Student::Student(const string _name, const int _id) {
        // Sets values
        name = _name;
        id = _id;
        courseReferences = nullptr;
        registeredCourses = 0;
    }
    Student::Student(const Student& other) {
        // Sets values
        name = other.name;
        id = other.id;
        registeredCourses = other.registeredCourses;
        // If size of courses taken by the student is zero, set array to nullptr
        if(other.registeredCourses == 0) {
            courseReferences = nullptr;
        }else {
            courseReferences = new Course[other.registeredCourses]; // Allocate memory
            for(int i = 0;i < other.registeredCourses;i++) { // Set course objects one by one
                courseReferences[i] = other.courseReferences[i];
            }
        }
    }
    Student::~Student() {
        // If it's not allocated
        if(courseReferences != nullptr) {
            delete[] courseReferences; // Free memory
        }
    }
    void Student::SetName(string _name) {
        name = _name;
    }
    string Student::GetName() const {
        return name;
    }
    void Student::SetID(int _id) {
        id = _id;
    }
    int Student::GetID() const {
        return id;
    }
    void Student::SetCourseReferences(Course *_courseReferences,int size) {
        // If size of course is not zero
        if(registeredCourses != 0) {
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
        registeredCourses = size; // Set size to parameter
    }
    Course* Student::GetCourseReferences() const {
        return courseReferences;
    }
    void Student::AddCourse(string courseCode,string courseName) {
        Course *temp = new Course[registeredCourses+1]; // Initialize new temp dynamic array and allocate one more memory than size
        for(int i = 0;i < registeredCourses;i++) {
            temp[i] = courseReferences[i]; // Set course objects one by one
        }
        // If size of course is not zero
        if(registeredCourses != 0) {
            delete[] courseReferences; // Free memory
        }
        // Set last index's values
        temp[registeredCourses].SetCode(courseCode);
        temp[registeredCourses].SetName(courseName);
        registeredCourses++; // Increase size one
        courseReferences = temp; // Set temp array to courseReferences
    }
    void Student::DeleteCourse(string courseCode) {
        Course *temp = new Course[registeredCourses-1]; // Initialize new temp dynamic array and allocate one less memory than size
        int a = 0;
        for(int i = 0;i < registeredCourses;i++) {
            // If code is given by parameter is not equal to courseReferences[i].code
            // That means we do not add the desired course to be deleted
            if(courseCode != courseReferences[i].code) {
                temp[a] = courseReferences[i]; // Set course objects one by one
                ++a; // It increases every time program set one course object
            }
        }
        registeredCourses--; // Decrease size one
        delete[] courseReferences; // Free memory
        courseReferences = temp; // Set temp array to courseReferences
    }
    Student& Student::operator =(const Student& other) {
        // If we allocated memory for courseReferences
        if(courseReferences != nullptr) {
            delete[] courseReferences; // Free memory
        }
        // Set name and id values
        this->name = other.name;
        this->id = other.id;
        // If other object's size is zero, set courseReferences to nullptr and size to zero
        if(other.registeredCourses == 0) {
            courseReferences = nullptr;
            registeredCourses = 0;
        }
        // If other object's size is not zero
        else {
            registeredCourses = other.registeredCourses; // Set size to other object's size
            courseReferences = new Course[registeredCourses]; // Allocate memory by registeredCourse(size)
            for (int i = 0; i < registeredCourses; i++) {
                courseReferences[i] = other.courseReferences[i]; // Set course objects one by one
            }
        }
        return *this; // Return this object
    }
    ostream& operator <<(ostream &outputStream, const Student& other) {
        outputStream << "Student Name: " << other.name << " Student ID: " << other.id;
        return outputStream;
    }
}