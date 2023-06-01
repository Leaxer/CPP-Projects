#include "DayOfYearSet.hpp"

namespace DayOfYearSpace
{
    DayOfYearSet::DayOfYear::DayOfYear() {
        day = 1;
        month = 1;
    }
    DayOfYearSet::DayOfYear::DayOfYear(int inputDay, int inputMonth) {
        day = inputDay;
        month = inputMonth;
    }
    void DayOfYearSet::DayOfYear::SetMonth(int userMonth) {
        month = userMonth;
    }
    void DayOfYearSet::DayOfYear::SetDay(int userDay) {
        day = userDay;
    }
    const int DayOfYearSet::DayOfYear::GetMonth() {
        return month;
    }
    const int DayOfYearSet::DayOfYear::GetDay() {
        return day;
    }
    DayOfYearSet::DayOfYear::~DayOfYear() {
    }
    //If there is no parameter set default and allocate memory
    DayOfYearSet::DayOfYearSet() {
        sizeOfElements = 1;
        dayOfYear = new DayOfYear();
    }
    DayOfYearSet::DayOfYearSet(const int userDay, const int userMonth) {
        sizeOfElements = 1;
        dayOfYear = new DayOfYear[1];
        dayOfYear->SetDay(userDay);
        dayOfYear->SetMonth(userMonth);
    }
    DayOfYearSet::DayOfYearSet(std::list<DayOfYear> &listOfDate) {
        auto i = 0;
        std::list<DayOfYear>::iterator it;
        sizeOfElements = listOfDate.size();
        dayOfYear = new DayOfYear[sizeOfElements];
        for(i,it = listOfDate.begin(); it != listOfDate.end(); ++it,++i) {
            dayOfYear[i] = *it;
        }
    }
    void DayOfYearSet::remove(DayOfYear &d1) {
        if(sizeOfElements == 0) {
            std::cout << "There is no element inside the set." << std::endl;
        }else {//Allocate memory for temp dayofyear and add new dates to temp
            DayOfYear *temp = new DayOfYear[sizeOfElements - 1];
            int count = 0;
            for(auto i = 0; i < sizeOfElements;++i) {//control for the date we don't want
                if(d1.GetDay() != dayOfYear[i].GetDay() || d1.GetMonth() != dayOfYear[i].GetMonth()) {
                    temp[count].SetDay(dayOfYear[i].GetDay());
                    temp[count].SetMonth(dayOfYear[i].GetMonth());
                    ++count;
                }
            }
            delete[] dayOfYear;
            dayOfYear = new DayOfYear[sizeOfElements - 1];
            for(auto i = 0; i < sizeOfElements - 1;++i) {
                dayOfYear[i].SetDay(temp[i].GetDay());
                dayOfYear[i].SetMonth(temp[i].GetMonth());
            }
            delete[] temp;
            --sizeOfElements;
        }
    }
    int DayOfYearSet::size() const{
        return sizeOfElements;
    }
    DayOfYearSet DayOfYearSet::operator +(DayOfYear &d1) {
        if(CheckDuplicate(*this,d1)) {//check duplicate
            DayOfYearSet s1;
            s1.sizeOfElements = sizeOfElements;
            if(sizeOfElements == 0) {
                s1.dayOfYear[0].SetDay(d1.GetDay());
                s1.dayOfYear[0].SetMonth(d1.GetMonth());
            }else {
                DayOfYear *temp = new DayOfYear[sizeOfElements + 1];
                for(auto i = 0; i < sizeOfElements;++i) {
                    temp[i].SetDay(dayOfYear[i].GetDay());
                    temp[i].SetMonth(dayOfYear[i].GetMonth());
                }
                
                temp[sizeOfElements].SetDay(d1.GetDay());
                temp[sizeOfElements].SetMonth(d1.GetMonth());
                s1.dayOfYear = new DayOfYear[sizeOfElements + 1];
                for(auto i = 0; i < sizeOfElements + 1;++i) {
                    s1.dayOfYear[i].SetDay(temp[i].GetDay());
                    s1.dayOfYear[i].SetMonth(temp[i].GetMonth());
                }
                delete[] temp;
            }
            ++s1.sizeOfElements;
            return s1;
        }else {
            std::cout << "Can't add same date" << std::endl;
        }
        return *this;
    }
    DayOfYearSet DayOfYearSet::operator +(DayOfYearSet &s2) {//Ya da eşittir ile dayofyear
        DayOfYearSet s1;
        int count = 0;//allocate for temp dayofyear,add first set's dates to temp.
        s1.sizeOfElements = sizeOfElements + s2.sizeOfElements;
        DayOfYear *temp = new DayOfYear[sizeOfElements + s2.sizeOfElements];
        for(auto i = 0; i < sizeOfElements;++i) {
            temp[i].SetDay(dayOfYear[i].GetDay());
            temp[i].SetMonth(dayOfYear[i].GetMonth());
            ++count;
        }
        //control the dates if they are same and add the different dates
        for(auto i = sizeOfElements; i < sizeOfElements + s2.sizeOfElements;++i) {
            if(CheckDuplicate(*this, s2.dayOfYear[i - sizeOfElements])) {
                temp[count].SetDay(s2.dayOfYear[i - sizeOfElements].GetDay());
                temp[count].SetMonth(s2.dayOfYear[i - sizeOfElements].GetMonth());
                ++count;
            }else {
                --s1.sizeOfElements;
            }
        }
        s1.dayOfYear = new DayOfYear[s1.sizeOfElements];
        for(auto i = 0; i < s1.sizeOfElements;++i) {
            s1.dayOfYear[i].SetDay(temp[i].GetDay());
            s1.dayOfYear[i].SetMonth(temp[i].GetMonth());
        }
        delete[] temp;
        return s1;
    }
    bool DayOfYearSet::operator ==(const DayOfYearSet &s2) const{//Ya da eşittir ile dayofyear
        int count = 0;
        if(sizeOfElements == s2.sizeOfElements) {
            for(auto i = 0; i < sizeOfElements;++i) {
                for(auto j = 0; j < sizeOfElements;++j) {
                    if(dayOfYear[i].GetDay() == s2.dayOfYear[j].GetDay() && dayOfYear[i].GetMonth() == s2.dayOfYear[j].GetMonth()) {
                        ++count;
                    }
                }
            }
        }
        if(count == sizeOfElements) return true;
        else return false;
    }
    bool DayOfYearSet::operator !=(const DayOfYearSet &s2) const {
        int count = 0;
        if(sizeOfElements != s2.sizeOfElements) return true;
        else {
            for(auto i = 0; i < sizeOfElements;++i) {
                for(auto j = 0; j < sizeOfElements;++j) {
                    if(dayOfYear[i].GetDay() == s2.dayOfYear[j].GetDay() && dayOfYear[i].GetMonth() == s2.dayOfYear[j].GetMonth()) {
                        ++count;
                    }
                }
            }
        }
        if(count == sizeOfElements) return false;
        return true;
    }
    DayOfYearSet DayOfYearSet::operator -(DayOfYearSet &s2) {//Ya da eşittir ile dayofyear
         DayOfYearSet s1;
         if(sizeOfElements == 0) {
            s1.sizeOfElements = 0;
            std::cout << "There is no element inside the set." << std::endl;
        }else {
            DayOfYear *temp = new DayOfYear[sizeOfElements];
            int count = 0,currentIndex = 0;
            bool checkValue;
            //check the same dates and don't add them
            while(currentIndex != sizeOfElements) {
                checkValue = false;
                for(auto i = 0; i < s2.sizeOfElements;++i) {
                    if(dayOfYear[currentIndex].GetDay() == s2.dayOfYear[i].GetDay() && dayOfYear[currentIndex].GetMonth() == s2.dayOfYear[i].GetMonth()) checkValue = true;
                }
                if(checkValue == false) {
                    temp[count].SetDay(dayOfYear[currentIndex].GetDay());
                    temp[count].SetMonth(dayOfYear[currentIndex].GetMonth());
                    ++count;
                }
                ++currentIndex;
            }
            s1.dayOfYear = new DayOfYear[count];
            for(auto i = 0; i < count;++i) {
                s1.dayOfYear[i].SetDay(temp[i].GetDay());
                s1.dayOfYear[i].SetMonth(temp[i].GetMonth());
            }
            delete[] temp;
            s1.sizeOfElements = count;
        }
        return s1;
    }
    DayOfYearSet DayOfYearSet::operator -(DayOfYear &d1) {
        DayOfYearSet s1;
        s1.sizeOfElements = sizeOfElements;
        if(sizeOfElements == 0) {
            std::cout << "There is no element inside the set." << std::endl;
        }else {
            DayOfYear *temp = new DayOfYear[sizeOfElements - 1];
            int count = 0;
            for(auto i = 0; i < sizeOfElements;++i) {
                if(d1.GetDay() != dayOfYear[i].GetDay() || d1.GetMonth() != dayOfYear[i].GetMonth()) {
                    temp[count].SetDay(dayOfYear[i].GetDay());
                    temp[count].SetMonth(dayOfYear[i].GetMonth());
                    ++count;
                }
            }
            s1.dayOfYear = new DayOfYear[sizeOfElements - 1];
            for(auto i = 0; i < sizeOfElements - 1;++i) {
                s1.dayOfYear[i].SetDay(temp[i].GetDay());
                s1.dayOfYear[i].SetMonth(temp[i].GetMonth());
            }
            --s1.sizeOfElements;
            delete[] temp;
        }
        return s1;
    }
    DayOfYearSet DayOfYearSet::operator ^(DayOfYearSet &s2) {
        DayOfYearSet s1;
        int highest;
        if(sizeOfElements < s2.sizeOfElements) highest = sizeOfElements;
        else highest = s2.sizeOfElements;
        DayOfYear *temp = new DayOfYear[highest];
        int count = 0,currentIndex = 0;
        bool checkIntersection;
        while(currentIndex != sizeOfElements) {
            checkIntersection = false;
            for(auto i = 0; i < s2.sizeOfElements;++i) {
                if(dayOfYear[currentIndex].GetDay() == s2.dayOfYear[i].GetDay() && dayOfYear[currentIndex].GetMonth() == s2.dayOfYear[i].GetMonth()) checkIntersection = true;
            }
            if(checkIntersection == true) {
                temp[count].SetDay(dayOfYear[currentIndex].GetDay());
                temp[count].SetMonth(dayOfYear[currentIndex].GetMonth());
                ++count;
            }
            ++currentIndex;
        }
        s1.dayOfYear = new DayOfYear[count];
        for(auto i = 0; i < count;++i) {
            s1.dayOfYear[i].SetDay(temp[i].GetDay());
            s1.dayOfYear[i].SetMonth(temp[i].GetMonth());
        }
        delete[] temp;
        s1.sizeOfElements = count;
        if(count == 0) {
            std::cout << "No intersection between this sets" << std::endl;;
        }
        return s1;
    }
    DayOfYearSet DayOfYearSet::operator !() {
        DayOfYearSet s1;
        int whichMonth,count = 0;
        //allocate memory for s1's dayofyear
        s1.dayOfYear = new DayOfYear[365 - sizeOfElements];
        for(auto i = 1; i < 8;++i) {
            if(i == 2) {
                whichMonth = 28;
            }else if(i%2 == 1) whichMonth = 31;
            else if(i%2 == 0) whichMonth = 30;//add the dates we don't have in current set
            for(auto j = 1;j <= whichMonth;++j) {
                for(auto x = 0; x < s1.sizeOfElements;++x) {
                    if(dayOfYear[x].GetMonth() == i && dayOfYear[x].GetDay() == j) {

                    }else {
                        s1.dayOfYear[count].SetDay(j);
                        s1.dayOfYear[count].SetMonth(i);
                        ++count;
                    }
                }
            }
        }
        for(auto i = 8; i < 13;++i) {
            if(i%2 == 1) whichMonth = 30;
            else if(i%2 == 0) whichMonth = 31;
            for(auto j = 1;j <= whichMonth;++j) {
                for(auto x = 0; x < s1.sizeOfElements;++x) {
                    if(dayOfYear[x].GetMonth() == i && dayOfYear[x].GetDay() == j) {

                    }else {
                        s1.dayOfYear[count].SetDay(j);
                        s1.dayOfYear[count].SetMonth(i);
                        ++count;
                    }
                }
            }
        }
        //set size
        s1.sizeOfElements = 365 - sizeOfElements;
        return s1;
    }
    DayOfYearSet::DayOfYear& DayOfYearSet::operator [](const int &index) const{
        return dayOfYear[index];;
    }
    void DayOfYearSet::DeleteMemory() {
        delete[] dayOfYear;
    }
    DayOfYearSet::~DayOfYearSet() {
    }
    std::ostream& operator<<(std::ostream& outputStream, const DayOfYearSet& set) {
        auto i = 0;
        while(i < set.sizeOfElements) {
            outputStream << "Day:" << set.dayOfYear[i].GetDay() << " Month:";
            if(set.dayOfYear[i].GetMonth() == 1) outputStream << "January";
            else if(set.dayOfYear[i].GetMonth() == 2) outputStream << "February";
            else if(set.dayOfYear[i].GetMonth() == 3) outputStream << "March";
            else if(set.dayOfYear[i].GetMonth() == 4) outputStream << "April";
            else if(set.dayOfYear[i].GetMonth() == 5) outputStream << "May";
            else if(set.dayOfYear[i].GetMonth() == 6) outputStream << "June";
            else if(set.dayOfYear[i].GetMonth() == 7) outputStream << "July";
            else if(set.dayOfYear[i].GetMonth() == 8) outputStream << "August";
            else if(set.dayOfYear[i].GetMonth() == 9) outputStream << "September";
            else if(set.dayOfYear[i].GetMonth() == 10) outputStream << "October";
            else if(set.dayOfYear[i].GetMonth() == 11) outputStream << "November";
            else if(set.dayOfYear[i].GetMonth() == 12) outputStream << "December";
            outputStream << std::endl;
            ++i;
        }
        return outputStream;
    }
    bool CheckValidDate(const int &userMonth, const int userDay) {
        if(userMonth < 1 || userMonth > 12 || !std::cin.good()) {
            std::cout << "Please enter valid number" << std::endl;
            return false;
        }else {
            //check if inputs are valid
            if(userDay != 0) {
                if(userMonth == 1 || userMonth == 3 || userMonth == 5 || userMonth == 7 || userMonth == 8 || userMonth == 10 || userMonth == 12) {
                    if(userDay < 1 || userDay > 31) {
                        std::cout << "You should enter the day between 1-31" << std::endl;
                        return false;
                    }
                }else if(userMonth == 4 || userMonth == 6 || userMonth == 9 || userMonth == 11) {
                    if(userDay < 1 || userDay > 30) {
                        std::cout << "You should enter the day between 1-30" << std::endl;
                        return false;
                    }
                }else if(userMonth == 2) {
                    if(userDay < 1 || userDay > 28) {
                        std::cout << "You should enter the day between 1-28" << std::endl;
                        return false;
                    }
                }
            }else return true;
        }
        return true;
    }
    bool CheckDuplicate(const DayOfYearSet &set, DayOfYearSet::DayOfYear &date) {
        for(auto i = 0;i < set.sizeOfElements;++i) {
            if(set.dayOfYear[i].GetDay() == date.GetDay() && set.dayOfYear[i].GetMonth() == date.GetMonth()) return false;
        }
        return true;
    }
}