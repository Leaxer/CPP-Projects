#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>

using namespace std;

bool ControlInput();
inline bool CheckRange(const float& number);

struct RGB {
    int red;
    int green;
    int blue;
};

class Image {
    private:
        string header; // Image format of the ppm file(P3,P6 etc)
        int imageHeight,imageWidth; // Width and height of the image
        int maxValue; // The scale of values possible for the color intensities
        vector<vector<RGB>> rgbValues;
    public:
        /*Basic Contructor
         *Sets imageHeight, imageWidth and maxValue values to 0.
         */
        Image();
        /*                   Sets header.
         *                   Set imageHeight, imageWidth and maxValue values to 0.
         *@param inputHeader New header
         */
        Image(const string& inputHeader);
        /*                     Sets header, imageHeight, imageWidth and maxValue values to parameters.
         *@param inputHeader   New header
         *@param inputHeight   New height of image
         *@param inputWidth    New width of image
         *@param inputMaxValue New max value
         */
        Image(const string& inputHeader, const int& inputHeight, const int& inputWidth, const int& inputMaxValue);
        /*                   Sets header.
         *@param inputHeader New header
         */
        void SetHeader(const string& inputHeader);
        /*@return header value
         */
        string GetHeader();
        /*                   Sets imageHeight.
         *@param inputHeight New height of image
         */
        void SetImageHeight(const int& inputHeight);
        /*@return imageHeight height of image
         */
        int GetImageHeight();
        /*                  Sets imageWidth.
         *@param inputWidth New width of image
         */
        void SetImageWidth(const int& inputWidth);
        /*@return imageWidth width of image
         */
        int GetImageWidth();
        /*                     Sets maxValue.
         *@param inputMaxValue New max value
         */
        void SetMaxValue(const int& inputMaxValue);
        /*@return maxValue max value
         */
        int GetMaxValue();
        /*                      Sets rgbValues.
         *@param inputRGBValues New rgbValues vector
         */
        void SetRGBValues(const vector<vector<RGB>>& inputRGBValues);
        /*@return rgbValues vector of rgb values
         */
        vector<vector<RGB>> GetRGBValues();
};

class ImageEditor {
    private:
        Image img; // Create an Image object
    public:
        ImageEditor(); // Constructor
        /*Method to see main menu
         *Shows the main dialog of program
         */
        void MainMenu();
        void OpenImageMenu(); // Shows the open image menu dialog
        void SaveImageMenu(); // Shows the save image menu dialog
        void ScriptsMenu(); // Shows the scripts menu dialog
        /*Method to load ppm image whose name is entered by the user
         *Gets file name and read the file
         */
        void LoadImage();
        /*Method to save ppm image whose name is entered by the user
         *Gets file name and write the image informations to file
         */
        void SaveImage();
        /*User enters coefficients and convert each color(RGB) to grayscale using formula
         */
        void ConvertToGrayScale();
};

int main() {
    ImageEditor imgEditor; // Create an ImageEditor object
    imgEditor.MainMenu(); // Call MainMenu function to see menu dialog
    return 0;
}

ImageEditor::ImageEditor() {
}

void ImageEditor::MainMenu() {
    int choice = -1;
    // Loop until user enter zero
    while(choice != 0) {
        cout << "MAIN MENU" << endl;
        cout << "0 - Exit" << endl;
        cout << "1 - Open An Image(D)" << endl;
        cout << "2 - Save Image Data(D)" << endl;
        cout << "3 - Scripts(D)" << endl;
        cin >> choice;
        while(!ControlInput()) {
            cout << "Please enter valid number" << endl;
            cin >> choice;
        }
        // If choice is 0 do nothing
        if(choice == 0) {
            
        }
        // If choice is 1 call OpenImageMenu function
        else if(choice == 1) {
            OpenImageMenu();
        }
        // If choice is 2 call SaveImageMenu function
        else if(choice == 2) {
            SaveImageMenu();
        }
        // If choice is 31 call ScriptsMenu function
        else if(choice == 3) {
            ScriptsMenu();
        }
        // If user enters invalid number give error and continue to loop
        else {
            cout << "Invalid Number!" << endl;
        }
    }
}

void ImageEditor::OpenImageMenu() {
    int choice = -1;
    // Loop until user enter zero
    while(choice != 0) {
        cout << "OPEN AN IMAGE MENU" << endl;
        cout << "0 - UP" << endl;
        cout << "1 - Enter The Name Of The Image File" << endl;
        cin >> choice;
        while(!ControlInput()) {
            cout << "Please enter valid number" << endl;
            cin >> choice;
        }
        // If choice is 0 do nothing
        if(choice == 0) {
        }
        // If choice is 1 call LoadImage function
        else if(choice == 1) {
            LoadImage();
        }
        // If user enters invalid number give warning and continue to loop
        else {
            cout << "Invalid Number!" << endl;
        }
    }
}
void ImageEditor::SaveImageMenu() {
    int choice = -1;
    // Loop until user enter zero
    while(choice != 0) {
        cout << "SAVE IMAGE DATA MENU" << endl;
        cout << "0 - UP" << endl;
        cout << "1 - Enter A File Name" << endl;
        cin >> choice;
        while(!ControlInput()) {
            cout << "Please enter valid number" << endl;
            cin >> choice;
        }
        // If choice is 0 do nothing
        if(choice == 0) {
        }
        // If choice is 1 call SaveImage function
        else if(choice == 1) {
            SaveImage();
        }
        // If user enters invalid number give warning and continue to loop
        else {
            cout << "Invalid Number!" << endl;
        }
    }
}
void ImageEditor::ScriptsMenu() {
    int choice;
    // Loop until user enter zero
    while(choice != 0) {
        cout << "SCRIPTS MENU" << endl;
        cout << "0 - UP" << endl;
        cout << "1 - Convert To Grayscale(D)" << endl;
        cin >> choice;
        while(!ControlInput()) {
            cout << "Please enter valid number" << endl;
            cin >> choice;
        }
        // If choice is 0 do nothing
        if(choice == 0) {

        }// If choice is 1 show and loop Convert to grayscale menu
        else if(choice == 1) {
            int secondChoice;
            // Loop until user enter zero
            while(secondChoice != 0) {
                cout << "CONVERT TO GRAYSCALE MENU" << endl;
                cout << "0 - UP" << endl;
                cout << "1 - Enter Coefficients For RED GREEN And BLUE Channels." << endl;
                cin >> secondChoice;
                while(!ControlInput()) {
                    cout << "Please enter valid number" << endl;
                    cin >> secondChoice;
                }
                // If secondChoice is 0 do nothing
                if(secondChoice == 0) {
                }
                // If choice is 1 call ConvertToGrayScale function
                else if(secondChoice == 1) {
                    ConvertToGrayScale();
                }
                // If user enters invalid number give warning and continue to loop
                else {
                    cout << "Invalid Number!" << endl;
                }
            }
        }
        // If user enters invalid number give warning and continue to loop
        else {
            cout << "Invalid Number!" << endl;
        }
    }

}

void ImageEditor::LoadImage() {
    string fileName; // File name
    cin >> fileName; // Input file name
    ifstream file(fileName); // Opens the file to read
    // If file couldn't open give warning and return to finish function
    if(!file.is_open()) {
        cout << "File couldn't open" << endl;
        return;
    }
    string header; // Image format of image
    getline(file,header); // Get first line of the file
    if(header == "P3") { // If the header is equal to correct image format
        int tempImageHeight,tempImageWidth; // Height and width of the image
        int tempImageMaxValue; // Max value of the image
        // Get values from the file
        file >> tempImageWidth;
        file >> tempImageHeight;
        file >> tempImageMaxValue;
        vector<vector<RGB>> tempRGBValues; // Create and temp 2d RGB vector to hold RGB values
        for(int i = 0; i < tempImageHeight;++i) {
                tempRGBValues.push_back(vector<RGB>(tempImageWidth)); // Adds new element to vector
            for(int j = 0; j < tempImageWidth;++j) {
                file >> tempRGBValues[i][j].red >> tempRGBValues[i][j].green >> tempRGBValues[i][j].blue; // Sets the values of vector's element
            }
        }
        // Sets the values of Image object
        img.SetHeader(header);
        img.SetImageWidth(tempImageWidth);
        img.SetImageHeight(tempImageHeight);
        img.SetMaxValue(tempImageMaxValue);
        img.SetRGBValues(tempRGBValues);
    }
    // If header is not correct image format, give warning
    else {
        cout << "Invalid format" << endl;
    }
    file.close(); // Closes the file
}
void ImageEditor::SaveImage() {
    // If no photo has been loaded i.e. the img object is empty
    if(img.GetHeader() == "not") {
        cout << "You should load an image first" << endl;
        return;
    }
    string fileName; // File name
    cin >> fileName; // Input file name
    ofstream file(fileName); // Opens the file to write
    // If file couldn't open give warning and return to finish function
    if(!file.is_open()) {
        cout << "File couldn't open" << endl;
        return;
    }
    file << img.GetHeader() << endl; // Gets header of img object and write to file and go to next line
    file << img.GetImageWidth() << " " << img.GetImageHeight() << endl; // Gets width and height of img object and write to file and go to next line
    file << img.GetMaxValue() << endl; // Gets max value of img object and write to file and go to next line
    vector<vector<RGB>> tempRGBValues = img.GetRGBValues(); // Create temp 2D RGB vector to hold RGB values and sets values to img object's RGB values
    // Loop height of image times(It's like rows)
    for(int i = 0; i < img.GetImageHeight();++i) {
        // Loop width of image times(It's like columns)
        for(int j = 0; j < img.GetImageWidth();++j) {
            file << tempRGBValues[i][j].red << " " << tempRGBValues[i][j].green << " " << tempRGBValues[i][j].blue << " "; // Write RGB values of the vector at the given index
        }
        file << endl; // Go to next line
    }
    file.close();
}

void ImageEditor::ConvertToGrayScale() {
    // If no photo has been loaded i.e. the img object is empty
    if(img.GetHeader() == "not") {
        cout << "You should load an image first" << endl;
        return;
    }
    float c_r,c_g,c_b; // Coefficient floats
    bool checkFirst,checkSecond;
    cin >> c_r >> c_g >> c_b; // User enters coefficients
    while(!ControlInput() || !CheckRange(c_r) || !CheckRange(c_g) || !CheckRange(c_b)) {
        cout << "Please enter valid numbers" << endl;
        cin >> c_r >> c_g >> c_b;
    }
    vector<vector<RGB>> tempRGBValues = img.GetRGBValues(); // Create temp 2D RGB vector to hold RGB values and sets values to img object's RGB values
    // Loop height of image times(It's like rows)
    for(int i = 0; i < img.GetImageHeight();++i) {
        // Loop width of image times(It's like columns)
        for(int j = 0; j < img.GetImageWidth();++j) {
            float formula; // Result of formula
            formula = (c_r * tempRGBValues[i][j].red) + (c_g * tempRGBValues[i][j].green) + (c_b * tempRGBValues[i][j].blue);
             // Sets new value of colors
            tempRGBValues[i][j].red = formula;
            tempRGBValues[i][j].green = formula;
            tempRGBValues[i][j].blue = formula;
            /*Controls the values
             *If value is greater than 255 set value to 255
            */
            if(tempRGBValues[i][j].red > 255) tempRGBValues[i][j].red = 255;
            if(tempRGBValues[i][j].green > 255) tempRGBValues[i][j].green = 255;
            if(tempRGBValues[i][j].blue > 255) tempRGBValues[i][j].blue = 255;
        }
    }
    img.SetRGBValues(tempRGBValues);
}

Image::Image() {
    // Sets values to zero
    header = "not";
    imageHeight = 0;
    imageWidth = 0;
    maxValue = 0;
}
Image::Image(const string& inputHeader) {
    header = inputHeader; // Sets header to parameter
    // Sets values to zero
    imageHeight = 0;
    imageWidth = 0;
    maxValue = 0;
}
Image::Image(const string& inputHeader, const int& inputHeight, const int& inputWidth, const int& inputMaxValue) {
    // Sets values of image
    header = inputHeader;
    imageHeight = inputHeight;
    imageWidth = inputWidth;
    maxValue = inputMaxValue;
}
void Image::SetHeader(const string& inputHeader) {
    header = inputHeader; // Sets image format of image
}
string Image::GetHeader() {
    return header; // Returns image format
}
void Image::SetImageHeight(const int& inputHeight) {
    imageHeight = inputHeight; // Sets height of image
}
int Image::GetImageHeight() {
    return imageHeight; // Returns height of image
}
void Image::SetImageWidth(const int& inputWidth) {
    imageWidth = inputWidth; // Sets width of image
}
int Image::GetImageWidth() {
    return imageWidth; // Returns width of image
}
void Image::SetMaxValue(const int& inputMaxValue) {
    maxValue = inputMaxValue; // Sets max value
}
int Image::GetMaxValue() {
    return maxValue; // Returns max value
}
void Image::SetRGBValues(const vector<vector<RGB>>& inputRGBValues) {
    rgbValues = inputRGBValues; // Sets vector of RGB values
}
vector<vector<RGB>> Image::GetRGBValues() {
    return rgbValues; // Returns vector of RGB values
}

bool ControlInput() {
    // If input is not int
    if(!std::cin.good()) {
        std::cin.clear(); // Clear buffer
        std::cin.ignore(2147483647,'\n');
        return false;
    }else {
        return true;
    }
}

inline bool CheckRange(const float& number) {
    if(number >= 1.0 || number < 0) {
        return false;
    }else {
        return true;
    }
}