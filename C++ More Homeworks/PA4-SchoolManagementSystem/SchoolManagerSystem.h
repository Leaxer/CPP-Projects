#ifndef SCHOOLMANAGERSYSTEM_H
#define SCHOOLMANAGERSYSTEM_H

#include <iostream>
#include <string.h>
#include "Course.h"
#include "Student.h"

using namespace std;

namespace PA4
{
    class SchoolManagementSystem {
        public:
            /*Default Constructor
             *Sets all values to zero and nullptr 
             */
            SchoolManagementSystem();
            /*                          Copy constructor
             *@param other              Other SchoolManagementSystem object which will be copied
             */
            SchoolManagementSystem(const SchoolManagementSystem& other);
            /*                          Destructor
             *                          Delete the courseReferences memory
             *                          Delete the studentReferences memory
             */
            ~SchoolManagementSystem();
            /*                          Sets courseReferences
             *@param _courseReferences  New courseReferences
             *@param size               Size of course taken by the student
             */
            void SetCourseReferences(Course *_courseReferences, int size);
            /*@return courseReferences  Dynamic array of courses taken by the student
             */
            Course* GetCourseReferences() const;
            /*                          Sets studentReferences
             *@param studentReferences  New studentReferences
             *@param size               Size of students enrolled in the course
             */
            void SetStudentReferences(Student *_studentReferences, int size);
            /*@return studentReferences Dynamic array of student enrolled in the course
             */
            Student* GetStudentReferences() const;
            /*                          Menu of school management system
             */
            void Menu();
            void StudentMenu();
            void SelectStudentMenu();
            void CourseMenu();
            void SelectCourseMenu();
            /*                          List the students
            */
            void ListAllStudents();
            /*                          List the courses
            */
            void ListAllCourses();
            void AddStudent();
            void DeleteStudent(const int index);
            void add_selected_student_to_a_course(const int index);
            void drop_selected_student_from_a_course(const int index);
            void AddCourse();
            void DeleteCourse(const int index);
        private:
            Course *courseReferences; // Dynamic array of courses
            Student *studentReferences; // Dynamic array of students
            int studentSize; // Size of Students
            int courseSize; // Size of Courses
    };
}

#endif