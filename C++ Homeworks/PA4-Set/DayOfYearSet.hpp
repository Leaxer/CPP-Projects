#ifndef DAYOFYEARSET_HPP
#define DAYOFYEARSET_HPP

#include <iostream>
#include <list>
#include <iterator>

namespace DayOfYearSpace
{
   class DayOfYearSet {
      public:
        class DayOfYear {
            private:
                int day,month;
            public:
                DayOfYear(int inputDay, int inputMonth);
                DayOfYear();
                void SetMonth(int userMonth);
                void SetDay(int userDay);
                const int GetMonth();
                const int GetDay();
                ~DayOfYear();
        };
        DayOfYearSet();
        DayOfYearSet(const int userDay, const int userMonth);
        DayOfYearSet(std::list<DayOfYear> &listOfDate);
        void remove(DayOfYear &d1);
        int size() const;
        DayOfYearSet operator +(DayOfYear &d1);
        DayOfYearSet operator +(DayOfYearSet &s2);
        bool operator ==(const DayOfYearSet &s2) const;
        bool operator !=(const DayOfYearSet &s2) const;
        DayOfYearSet operator -(DayOfYearSet &s2);
        DayOfYearSet operator -(DayOfYear &d1);
        DayOfYearSet operator ^(DayOfYearSet &s2);
        DayOfYearSet operator !();
        DayOfYear& operator [](const int &index) const;
        void DeleteMemory();
        ~DayOfYearSet();
        friend std::ostream& operator<<(std::ostream& outputStream, const DayOfYearSet& set);
        friend bool CheckDuplicate(const DayOfYearSet &set, DayOfYear &date);
      private:
        int sizeOfElements = 0;
        DayOfYear *dayOfYear;
   };
   std::ostream& operator<<(std::ostream& outputStream, const DayOfYearSet& set);
   bool CheckValidDate(const int &userMonth, const int userDay);
   bool CheckDuplicate(const DayOfYearSet &set, DayOfYearSet::DayOfYear &date);
}
#endif