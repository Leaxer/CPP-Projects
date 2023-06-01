#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include "Student.h"

using namespace std;

namespace PA4
{
    // Forward declaration of student class
    class Student;
    class Course {
        public:
            /*Default Constructor
             *Sets all values to zero or null
             *Sets courseReferences to nullptr
             */
            Course();
            /*                          Gets name and code from parameter and sets to this class's values
             *                          Sets courseRegistered to zero
             *                          Sets studentReferences to nullptr
             */
            Course(const string _name, const string _code);
            /*                          Copy the parameter constructor.
             *@param other              Other Course object which will be copied
             */
            Course(const Course& other);
            /*                          Destructor
             *                          Delete the studentReferences memory
             */
            ~Course();
            /*                          Sets name of student
             *@param _name              New name
             */
            void SetName(string _name);
            /*@return name              name value
             */
            string GetName() const;
            /*                          Sets code of course
             *@param _code              New code
             */
            void SetCode(string _code);
            /*@return code              code value
             */
            string GetCode() const;
            /*                          Sets studentReferences
             *@param studentReferences  New studentReferences
             *@param size               Size of students enrolled in the course
             */
            void SetStudentReferences(Student *_studentReferences, int size);
            /*@return studentReferences Dynamic array of student enrolled in the course
             */
            Student* GetStudentReferences() const;
            /*                          Add new student to studentReferences
             *@param studentName        Student name
             *@param id                 Student id
             */
            void AddStudent(string studentName, int id);
            /*                          Delete the specific student from studentReferences
             *@param id                 Student id
             */
            void DeleteStudent(int id);
            /*                          = operator for Course class
             *@param other              Other Course object which will be copied
             *@return Course&           Reference of course object
             */
            Course& operator =(const Course& other);
            friend ostream& operator <<(ostream &outputStream, const Course& other);
            friend class Student;
            friend class SchoolManagementSystem;
        private:
            string name; // Name of course
            string code; // Code of course
            Student *studentReferences; // Dynamic array of student enrolled in the course
            int registeredStudents; // Size of students enrolled in the course
    };
}

#endif