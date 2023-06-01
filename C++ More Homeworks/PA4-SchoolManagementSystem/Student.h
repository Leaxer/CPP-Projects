#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "Course.h"

using namespace std;

namespace PA4
{
    // Forward declaration of course class
    class Course;
    class Student {
        public:
            /*Default Constructor
             *Sets all values to zero or null
             *Sets courseReferences to nullptr
             */
            Student();
            /*                          Gets name and id from parameter and sets to this class's values
             *                          Sets registeredCourse to zero
             *                          Sets courseReferences to nullptr
             */
            Student(const string _name, const int _id);
            /*                          Copy the parameter constructor.
             *@param other              Other Student object which will be copied
             */
            Student(const Student& other);
            /*                          Destructor
             *                          Delete the courseReferences memory
             */
            ~Student();
            /*                          Sets name of student
             *@param _name              New name
             */
            void SetName(string _name);
            /*@return name              name value
             */
            string GetName() const;
            /*                          Sets id of student
             *@param _id                New id
             */
            void SetID(int _id);
            /*@return id                id value
             */
            int GetID() const;
            /*                          Sets courseReferences
             *@param _courseReferences  New courseReferences
             *@param size               Size of course taken by the student
             */
            void SetCourseReferences(Course *_courseReferences,int size);
            /*@return courseReferences  Dynamic array of courses taken by the student
             */
            Course* GetCourseReferences() const;
            /*                          Add new course to courseReferences
             *@param courseCode         Course code
             *@param courseName         Course name
             */
            void AddCourse(string courseCode,string courseName);
            /*                          Delete the specific course from courseReferences
             *@param courseCode         Course code
             */
            void DeleteCourse(string courseCode);
            /*                          = operator for Student class
             *@param other              Other Student object which will be copied
             *@return Student&          Reference of student object
             */
            Student& operator =(const Student& other);
            friend ostream& operator <<(ostream &outputStream, const Student& other);
            friend class Course;
            friend class SchoolManagementSystem;
        private:
            string name; // Name of student
            int id; // Id of student
            Course *courseReferences; // Dynamic array of courses taken by the student
            int registeredCourses; // Size of courses taken by the student
    };
}

#endif