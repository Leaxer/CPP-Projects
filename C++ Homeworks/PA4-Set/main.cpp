#include <limits>
#include "DayOfYearSet.hpp"

using namespace DayOfYearSpace;

int main() {
    auto day = 0,month = 0;
    std::cout << "Enter month and day" << std::endl;
    std::cin >> month;
    while(!CheckValidDate(month,0))
    {
       std::cin.clear();
       std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       std::cin >> month;
    }
    std::cin >> day;
    while(!CheckValidDate(month,day))
    {
       std::cin.clear();
       std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       std::cin >> day;
    }
    /*
    Constructor
    */
    DayOfYearSet s1(day, month),s2(2,3),s3(6,7),s4(3,8),s5(9,10),s6;
    DayOfYearSet::DayOfYear d1(9,12),d2(2,10),d3(7,3),d4(10,11);
    std::cout << "Sets(S1 and S2):" << std::endl;
    std::cout << "Current S1:" << std::endl;  
    std::cout << s1;
    std::cout << "Current S2:" << std::endl;  
    std::cout << s2 << std::endl;
    /*
    Add date
    */
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Current S1:" << std::endl;
    std::cout << s1;
    std::cout << "Current S2:" << std::endl;    
    std::cout << s2 << std::endl;
    std::cout << "Add Date:" << std::endl;
    s1 = s1 + d1;
    std::cout << "S1 = S1 + D1" << std::endl << s1 << std::endl;
    s2 = s1 + d2;
    std::cout << "S2 = S1 + D2" << std::endl <<  s2 << std::endl;
    s1 = s1 + d3;
    std::cout << "S1 = S1 + D3" << std::endl << s1 << std::endl;
    /*
    Union
    */
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Current S2:" << std::endl;
    std::cout << s2;
    std::cout << "Current S3:" << std::endl;  
    std::cout << s3 << std::endl;
    std::cout << "Union:" << std::endl;
    s2 = s1 + s2;
    std::cout << "S2 = S1 + S2" << std::endl << s2 << std::endl;
    s3 = s1 + s2;
    std::cout << "S3 = S1 + S2" << std::endl << s3 << std::endl;
    /*
    Removes an element
    */
   std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Current S3:" << std::endl;
    std::cout << s3;
    std::cout << "Removes an element:" << std::endl;
    s3 = s3 - d1;
    std::cout << "S3 = S3 - D1" << std::endl << s3 << std::endl;
    s3 = s2 - d2;
    std::cout << "S3 = S2 - D2" << std::endl << s3 << std::endl;
    /*
    Difference
    */
   std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Current S3:" << std::endl;
    std::cout << s3;
    std::cout << "Added some dates to s3:" << std::endl;
    s3 = s3 + d2;
    std::cout << "Current s3:" << std::endl;
    std::cout << s3;
    std::cout << "Difference:" << std::endl;
    s3 = s3 - s1;
    std::cout << "S3 = S3 - S1" << std::endl << s3 << std::endl;
    s4 = s2 - s1;
    std::cout << "S4 = S2 - S1" << std::endl << s3 << std::endl;
    s1.DeleteMemory();
    s2.DeleteMemory();
    /*
    Intersection
    */
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Current S4:" << std::endl;
    std::cout << s4;
    std::cout << "Current S6:" << std::endl;  
    std::cout << s6;
    std::cout << "Intersection:" << std::endl;
    s4 = s4^s3;
    std::cout << "S4 = S4^S3" << std::endl << s4 << std::endl;
    s6 = s4^s5;
    std::cout << "S6 = S4^S5" << std::endl << s6 << std::endl;
    s3.DeleteMemory();
    s6.DeleteMemory();
    /*
    Complement
    */
    decltype(s1) s11;
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Current S4:" << std::endl;
    std::cout << s4 << std::endl;
    std::cout << "Current S11:" << std::endl;  
    std::cout << s11 << std::endl;
    std::cout << "Complement:" << std::endl;
    s4 = !s4;
    std::cout << "S4 = !S4" << std::endl << s4 << std::endl;
    s11 = !s5;
    std::cout << "S11 = !S5" << std::endl << s11 << std::endl;
    s4.DeleteMemory();
    s5.DeleteMemory();
    s11.DeleteMemory();
    /*
    []operator 
    */
    std::cout << "------------------------------------------------------" << std::endl;
    decltype(s1) s7,s8;
    decltype(d1) d5(8,12),d6(7,11);
    std::cout << "Current S7:" << std::endl;
    std::cout << s7 << std::endl;
    std::cout << "Current S8:" << std::endl;  
    std::cout << s8 << std::endl;
    s7 = s7 + d5;
    s7 = s7 + d4;
    std::cout << "Current S7:" << std::endl;
    std::cout << s7 << std::endl;
    s8 = s8 + d6;
    std::cout << "Current S8:" << std::endl;  
    std::cout << s8 << std::endl;
    std::cout << "[]operator:" << std::endl;
    s7 = s7 + s8[1];
    std::cout << "S7 = S7 + S8[1]" << std::endl << s7 << std::endl;
    s8 = s8 + s7[2];
    std::cout << "S8 = S8 + S7[2]" << std::endl << s8 << std::endl;
    /*
    == operator
    */
    std::cout << "------------------------------------------------------" << std::endl;
    decltype(s1) s9,s10;
    s9 = s9 + d5;
    s10 = s10 + d5;
    std::cout << "Current S9:" << std::endl;
    std::cout << s9 << std::endl;
    std::cout << "Current S10:" << std::endl;  
    std::cout << s10 << std::endl;
    std::cout << "== operator:" << std::endl;
    if(s9 == s10) {
      std::cout << "S9 and S10 are equal" << std::endl;
    }else std::cout << "S9 and S10 are not equal" << std::endl;
    if(s8 == s10) {
      std::cout << "S8 and S10 are equal" << std::endl;
    }else std::cout << "S8 and S10 are not equal" << std::endl;
    /*
    != operator
    */
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "!= operator:" << std::endl;
    if(s9 != s10) {
      std::cout << "S9 and S10 are not equal" << std::endl;
    }else std::cout << "S9 and S10 are equal" << std::endl;
    if(s8 != s10) {
      std::cout << "S8 and S10 are not equal" << std::endl;
    }else std::cout << "S8 and S10 are equal" << std::endl;
    s10.DeleteMemory();
    /*
    Remove
    */
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Current S7:" << std::endl;
    std::cout << s7 << std::endl;
    std::cout << "S7 remove:" << std::endl;
    s7.remove(d4);
    s7.remove(d5);
    std::cout << "S7 remove d4 and d5:" << std::endl;
    std::cout << s7 << std::endl;
    s7.DeleteMemory();
    /*
    Size
    */
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Current S8:" << std::endl;
    std::cout << s8 << std::endl;
    std::cout << "Current S9:" << std::endl;  
    std::cout << s9 << std::endl;
    std::cout << "S8 size:" << s8.size() << std::endl;
    std::cout << "S9 size:" << s9.size() << std::endl;
    s8.DeleteMemory();
    s9.DeleteMemory();
    std::list<DayOfYearSet::DayOfYear> listOfDates{d1,d2,d3};
    listOfDates.push_back(d4);
    listOfDates.push_back(d5);
    decltype(s1) s12(listOfDates);
    std::cout << s12;
    s12.DeleteMemory();
}