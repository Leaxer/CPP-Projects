#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

const int MAX_ATTEMPT = 100; // Max attempt user can guess
char R_TYPE[] = "-r"; // Char array of -r arg type
char U_TYPE[] = "-u"; // Char array of -u arg type

/*
 *Calculate the length of number and return it
 *@param number Number which we find to find the length
 *@return Size of length
*/
int ControlLength(long long number);

/*
 *Converts the char array to int which entered from console and return it
 *@param arg The number which entered from console
 *@return The number which converted to int from char array
*/
long long ConvertToInt(char argv[]);

/*
 *Control the arg type is "-r" or "-u". if it's not them function will return false
 *@param arg Argument type from console
 *@param type Type of argument which we want
 *@return True or false depends on conditions
*/
bool ControlArgType(char arg[],char type[]);
/*
 *It checks whether all digits of the number which is coming from parameter are numbers.
 *Using this function for the number coming from console before converting to int
 *If all digits are number, returns true
 *@param number Char array of number which coming from console
 *@return True or false depends on number is valid or not
*/
bool IsNumberValid(char number[]);
/*
 *Generates a number in given size with all digits are different.
 *@param size What size should be the number
 *@return The number which generated
*/
long long GenerateSecretNum(int size);
/*
 *Handles game
 *Asks user to input number and calls some functions to continue game until game finishes
 *@param number Secret number
 *@param size Size of secret number
*/
void StartGame(long long number, int size);
/*
 *Checks the number entered by the user.
 *Calls ControlLength and CheckForRandomDigits functions to control the number if it's size is correct and all digits are different.
 *If all function return true function will return true
 *@param userNumber The number entered by the user
 *@param size Size of secret number
 *@return -1,0,1 depends on conditions
*/
int ControlUserInputConditions(long long userNumber, int size);

/*
 *Checks the digits of number are different from each other
 *@param number The number to check
 *@return True or false
*/
bool CheckForRandomDigits(long long number);

/*
 *Finds how many exact and misplaced nums are there on the number which came from user
 *@param number Secret number
 *@param userNumber The number which user enter
 *@param size Size of number
 *@return 1 or 0 depends on if user find number
*/
int FindAndControlNumCounts(long long number, long long userNumber, int size);

int main(int argc, char** argv)
{
    long long num = 0;
    // If argc = 3, that means user entered commands on correct size
    if (argc == 3) {
        srand(time(0)); // Generates random number
        // Get size of number which entered from user
        // If the user enters "./mastermind -r 6" that means size will be 1
        int size = ControlLength(ConvertToInt(argv[2]));
        // If the arg type is "-r", size is one and the digits of number which entered by the user are just numbers. 
        if(ControlArgType(argv[1],R_TYPE) && size == 1 && IsNumberValid(argv[2])) {
            // Reassign size to find how many digits the user wants
            // If user enters "".... -r 6" size will be 6
            size = ConvertToInt(argv[2]);
            num = GenerateSecretNum(size); // Generates the number in given size and assigns num value to this number which coming from function
            StartGame(num, size); // Calls this function to start game
        }
        // If the arg type is "-u"
        // If size is between 0 and 10
        // If the input entered by the user consists of numbers only
        // Convert the char input to int and check the array if the all numbers are different from each other
        else if(ControlArgType(argv[1],U_TYPE) && (size > 0 && size < 10) && IsNumberValid(argv[2]) && CheckForRandomDigits(ConvertToInt(argv[2]))) {
            StartGame(ConvertToInt(argv[2]),size); // Call function to start game
        }
        // If the conditions are not correct print "E0".
        else {
            cout << "E0" << endl;;
        }
    }
    // If the condition is not correct print "E0".
    else {
        cout << "E0" << endl;;
    }
    return 0;
}

int ControlLength(long long number) {
    int i = 0;
    if(number < 0) {
        return -1;
    }
    // Loop until number is zero
    // i will increment one at a time and be equal to the number of digits of that 'number' value.
    while(number) {
        ++i; // Increment i by one to access the next char in the array
        number /= 10; // Divides the number to ten
    }
    // returns "i" value
    return i;
}

long long ConvertToInt(char argv[]) {
    int num = 0;
    int i = 0;
    if(argv[0] == '0') {
        return 0;
    }
    // Loop until it reaches to end of the array
    while(argv[i]) {
        // Convert char argv[i] to ascii and remove 48 from the ascii number to find the exact number.
        // For example ascii code of 2 is 50, so if removes 48 from it we will find exact number
        num = num * 10 + argv[i] - 48;
        ++i; // Increase i to get next index of array
    }
    return num;
}

bool ControlArgType(char arg[],char type[]) {
    int i = 0;
    // Loop until end of char array
    while(arg[i]) {
        // If the first character in the given type parameter is not equal to first char of array return false
        if(arg[0] != type[0]) return false;
        // If the second character in the given type parameter is not equal to second char of array return false
        else if(arg[1] != type[1]) return false;
        ++i; // Increment i by one to access the next char in the array
    }
    // 'i' value equals to char arg[]'s size
    // If i equal to 2, that means input entered by the user is correct, so return true 
    if(i == 2) {
        return true;
    }else {
        return false;
    }
}

bool IsNumberValid(char number[]) {
    int i = 0;
    // Loop until end of char array
    while(number[i]) {
        char c = number[i]; // Assign the character at the specified index to char c.
        // If the ascii code not between 48 and 57 that means char not equal to numbers. It equals letters or something else, so return false
        if(c < 48 || c > 57) {
            return false;
        }
        ++i; // Increment i by one to access the next char in the array
    }
    return true;
}

long long GenerateSecretNum(int size) {
    int num = 0;
    // If size of number is one
    if(size == 1) {
        // Call rand() until the rand()%10 is not zero and assign it to num value
        while(num == 0) {
            num = rand()%10;
        }
        // return num
        return num;
    }
    // Loop for the size of the number.
    for(int i = 0;i < size;++i) {
        int randNum = 0,sameNum = 1,tempNum;
        // Loop while sameNum == 1.
        // When sameNum be zero that means this digit is different from other digits
        while(sameNum == 1) {
            randNum = rand()%10; // Get random number
            // Avoid getting zero at first digit
            while(randNum == 0 && i == 0) {
                randNum = rand()%10; // Get random number
            }
            tempNum = num; // Assign tempNum to original num
            sameNum = 0; // Set sameNum to zero at first
            // Loop until tempNum is zero
            while(tempNum) {
                // If the remainder of dividing a tempNum by 10 is equal to randNum that means randNum is not unique, so set sameNum to 1
                // For exampe if the number is 5421, remainder will be 1, if the randNum also 1 that means randNum is not unique
                if(tempNum % 10 == randNum) {
                    sameNum = 1;
                }
                // To get next digit of tempNum divide it to 10
                // If the number is 5421, divide to ten. New number will be 542, so next remainder of dividing by 10 will be 2
                tempNum /= 10;
            }
        }
        num = num * 10 + randNum; // Multiply by ten to move the previous digit up one digit and add the randNum to the current number
    }
    return num;
}

void StartGame(long long number, int size) {
    // User guess number
    long long userNumber;

    // Condition to check if the game finish
    int controlFinish;
    // Value for user conditions
    int conditionCheck;

    // Continue to game until reaches to max attempt
    for(int k = 0;k < MAX_ATTEMPT;++k) {
        cin>>userNumber;
        // If user doesn't enter a proper integer.
        if(std::cin.fail()){
            cout << "E2" << endl;    // Print the error message.
            controlFinish = 1; // Set controlFinish value to 1
            break;
        }
        conditionCheck = ControlUserInputConditions(userNumber, size);
        // If the number entered by the user does not meet the conditions. If conditionCheck is zero, means length is not correct or digits are not unique
        if(conditionCheck == 0) {
            cout << "E1" << endl;  // Print the error message.
            controlFinish = 1;  // Set controlFinish value to 1
            break;
        }
        // If conditionCheck is -1, first digit is zero
        else if(conditionCheck == -1) {
            cout << "E0" << endl;  // Print the error message.
            controlFinish = 1;  // Set controlFinish value to 1
            break;
        }else {
            controlFinish = FindAndControlNumCounts(number, userNumber, size);  // Calls the function, if exact number is equal to size of number value return 1 and set this value to controlFinish
            if(controlFinish == 1) { // If controlFinish is equal 1 
                k = 100;  // Set k = 100 to finish loop
                cout << "FOUND" << endl; // Print the message
                break;
            }
        }
    }
    if(controlFinish == 0) { // If controlFinish is equal 0, that means user failed
        cout << "FAILED" << endl; // Print the FAILED message
    }
}

int ControlUserInputConditions(long long userNumber, int size) {
    int userNumberSize = ControlLength(userNumber); // Get size of number
    // If the length of userNumber is not equal to size of secret number and not equal to -1(means not negative number)
    if(userNumberSize != size && userNumberSize != -1) {
        return 0;
    }
    // Control if number is less than 0 or digits of number are not unique
    if(userNumberSize == -1 || !CheckForRandomDigits(userNumber)) {
        return -1;
    }
    return 1;
}

bool CheckForRandomDigits(long long number) {
    // A value that increase one if the digits are the same.
    int sameCount;
    long long tempNumber = number;
    // Loop until number is zero
    while(number){
        sameCount = 0; // Set sameCount before checking the digits
        // Loop until tempNumber is zero
        while(tempNumber){
            // If the numbers are same and it's not first time(it means that the digit has found another number other than itself.)
            if(number % 10 == tempNumber % 10 && sameCount != 0){
                return false;
            }
            // If the numbers are same and found it first time(means the digit found itself on number)
            else if(number % 10 == tempNumber % 10) {
                ++sameCount;// Increase sameCount one time
            }
            // To get next digit of tempNumber divide it to 10
            // If the number is 5421, divide to ten. New number will be 542, so next remainder of dividing by 10 will be 2
            tempNumber /= 10;
        }
        number /= 10;
        tempNumber = number;
    }
    return true;
}

int FindAndControlNumCounts(long long number, long long userNumber, int size) {
    // Set values to zero at first
    int exactNumCount = 0,misplacedNumCount = 0;
    int tempUserNumber;
    // Loop until number is zero
    for(int i = 0;number != 0;++i){
        tempUserNumber = userNumber;
        // Loop until tempUserNumber is zero
        for(int j = 0;tempUserNumber != 0;++j){
            // If the numbers are same and the numbers are not in the same digit
            if(number % 10 == tempUserNumber % 10 && i != j){
                ++misplacedNumCount; // Increase the value one time
            }
            // If the numbers are same and the numbers are in the same digit
            else if(number % 10 == tempUserNumber % 10) {
                ++exactNumCount; // Increase the value one time
            }
            tempUserNumber /= 10;
        }
        number /= 10;
    }
    // If exactNumCount is equal to size, that means user found the number. So return 1
    if(exactNumCount == size) return 1;
    // Print exactNumCount and misplacedNumCount values
    cout << exactNumCount << " " << misplacedNumCount << endl;
    return 0;
}