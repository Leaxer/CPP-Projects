#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>

using namespace std;

bool ControlInput();
inline bool CheckRange(const float& number);


/*Struct for holding pixel's values
*/
struct RGB {
    int red;
    int green;
    int blue;
    // Operators to get pixel's values easily
    int & operator[](int index);
	const int & operator[](int index) const; 
};

class ppmImage {
    private:
        string header; // Image format of the ppm file(P3,P6 etc)
        int imageHeight,imageWidth; // Width and height of the image
        int maxValue; // The scale of values possible for the color intensities
        vector<vector<RGB>> rgbValues;
    public:
        /*Basic Contructor
         *Sets imageHeight, imageWidth and maxValue values to 0.
         */
        ppmImage();
        /*                     Copy the parameter constructor.
         *@param _ppmImage     Other image object which will be copied
         */
        ppmImage(const ppmImage& _ppmImage);
        /*                     Get file name and set properties inside the file to ppmImage values
         *@param ppmFileName   File name
         */
        ppmImage(const string ppmFileName);
        /*                     Sets imageHeight, imageWidth values to parameters.
        /                      Sets maxValue to 255 and header to "P3"
         *@param inputHeight   New height of image
         *@param inputWidth    New width of image
         */
        ppmImage(const int& inputHeight, const int& inputWidth);
        /*                     Sets header, imageHeight, imageWidth and maxValue values to parameters.
         *@param inputHeader   New header
         *@param inputHeight   New height of image
         *@param inputWidth    New width of image
         *@param inputMaxValue New max value
         */
        ppmImage(const string& inputHeader, const int& inputHeight, const int& inputWidth, const int& inputMaxValue);
        /*                     Sets header.
         *@param inputHeader   New header
         */
        void SetHeader(const string& inputHeader);
        /*@return header value
         */
        string GetHeader() const;
        /*                     Sets imageHeight.
         *@param inputHeight   New height of image
         */
        void SetImageHeight(const int& inputHeight);
        /*@return imageHeight  height of image
         */
        int GetImageHeight() const;
        /*                     Sets imageWidth.
         *@param inputWidth    New width of image
         */
        void SetImageWidth(const int& inputWidth);
        /*@return imageWidth   width of image
         */
        int GetImageWidth() const;
        /*                     Sets maxValue.
         *@param inputMaxValue New max value
         */
        void SetMaxValue(const int& inputMaxValue);
        /*@return maxValue      max value
         */
        int GetMaxValue() const;
        /*                      Sets rgbValues.
         *@param inputRGBValues New rgbValues vector
         */
        void SetRGBValues(const vector<vector<RGB>>& inputRGBValues);
        /*@return rgbValues     vector of rgb values
         */
        vector<vector<RGB>> GetRGBValues() const;
        /*                      Read file according to filename and save the file values to class values
         *@param fileName       Name of file
         *@return int           If file reading is succesfull return 1,otherwise return 0
        */
        int ReadFile(const string fileName);
        /*                      Write file according to filename and save the class values to file
         *@param fileName       Name of file
         *@return int           If file writing is succesfull return 1,otherwise return 0
        */
        int SaveFile(const string fileName) const;
        /*          Print the dimesions of image object
        */
        void PrintDimensions();
        /*                      Read file according to filename and save the file values to class values
         *@param color_choice   which color you want to change
         *@param mainObj        Object which will be copied
        */
        void ChangePixelValue(const int color_choice, const ppmImage& mainObj);
        /*                      Swap the colors on each pixel according to swap_choice
         *@param swap_choice    which colors you want to swap
         *@return int           If swapping values is succesfull return 1,otherwise return 0
        */
        int SwapPixelValues(const int swap_choice);
        /*                      Operator overload to sum 2 image object's properties
         *@param                other second image object
         *@return ppmImage      new image object
        */
        ppmImage operator +(const ppmImage& other);
        /*                      Operator overload to substract 2 image object's properties
         *@param other          second image object
         *@return ppmImage      new image object
        */
        ppmImage operator -(const ppmImage& other);
        /*                      Operator overload to copy second image object's properties to this object
         *@param other          second image object
         *@return ppmImage&     reference of this image object
        */
        ppmImage& operator =(const ppmImage& other);
        /*                      Operator overload to get pixel's one color according to parameters
         *@param row            row
         *@param column         column
         *@param colorChannel   which color you want to return
         *@return int&          reference of int
        */
        int& operator ()(int row, int column, int colorChannel);
        /*                      Operator overload to get pixel's one color according to parameters
         *@param row            row
         *@param column         column
         *@param colorChannel   which color you want to return
         *@return int&          reference of int
        */
        const int& operator()(int row, int column, int colorChannel) const;
        /*                      Operator overload to reach vector RGB using []
         *@param index          which index you want to reach
         *@return vector<RGB>&  reference of vector<RGB>
        */
        vector<RGB>& operator [](int index);
        /*                      Operator overload to reach vector RGB using []
         *@param index          which index you want to reach
         *@return vector<RGB>&  reference of vector<RGB>
        */
        const vector<RGB>& operator[](int index) const;
        friend ostream& operator <<(ostream &outputStream, const ppmImage& other);
};

int read_ppm(const string source_ppm_file_name, ppmImage &destination_object);
int write_ppm(const string destination_ppm_file_name, const ppmImage &source_object);
int test_addition(const string filename_image1, const string filename_image2, const string filename_image3);
int test_subtraction(const string filename_image1, const string filename_image2, const string filename_image3);
int test_print(const string filename_image1);
int swap_channels(ppmImage& image_object_to_be_modified, int swap_choice);
ppmImage single_color(const ppmImage& source, int color_choice);

int main(int argc, char ** argv) {
    // If there at least 4 arguments
    if(argc > 3 ) {
		int choice;
		choice = stoi(argv[1]); // Convert choice string to number
		string fileName1(argv[2]); // Get first file name
        string fileName2(argv[3]); // Get second file name

		ppmImage readPPMImage; // Create object to read
		ppmImage resultPPMImage; // Create empty object to get result to this onbject
        if(choice == 1) {
            if(argc != 5) return 0; // check the existence of the optional arguments. If they are not given, exit
			test_addition(fileName1, fileName2, argv[4]);
        }else if(choice == 2) {
            if(argc != 5) return 0; // check the existence of the optional arguments. If they are not given, exit
			test_subtraction(fileName1, fileName2, argv[4]);
        }else if(choice == 3) {
            read_ppm(fileName1, readPPMImage);
			swap_channels(readPPMImage, 2);
			write_ppm(fileName2, readPPMImage);
        }else if(choice == 4) {
            read_ppm(fileName1, readPPMImage);
			swap_channels(readPPMImage, 3);
			write_ppm(fileName2, readPPMImage);
        }else if(choice == 5) {
            read_ppm(fileName1, readPPMImage);
			resultPPMImage = single_color(readPPMImage, 1);
			write_ppm(fileName2, resultPPMImage);
        }else if(choice == 6) {
            read_ppm(fileName1, readPPMImage);
			resultPPMImage = single_color(readPPMImage, 2);
			write_ppm(fileName2, resultPPMImage);
        }else if(choice == 7) {
            read_ppm(fileName1, readPPMImage);
			resultPPMImage = single_color(readPPMImage, 3);
			write_ppm(fileName2, resultPPMImage);
        }else { 
            cout << "Invalid number!" << endl;
        }
	}
    return 0;
}

int read_ppm(const string source_ppm_file_name, ppmImage &destination_object) {
    // Call image object's read file function
	return destination_object.ReadFile(source_ppm_file_name);
}
int write_ppm(const string destination_ppm_file_name, const ppmImage &source_object) {
    // Call image object's save file function
	return source_object.SaveFile(destination_ppm_file_name);
}
int test_addition(const string filename_image1, const string filename_image2, const string filename_image3) {
    // Create two image and set properties according to parameters' files
    ppmImage img1(filename_image1);
    ppmImage img2(filename_image2);
    // Create third object to sum other image objects
    ppmImage sum;
    sum = img1 + img2; // Sum objects
    return sum.SaveFile(filename_image3); // Save the file and return 1 or 0
}
int test_subtraction(const string filename_image1, const string filename_image2, const string filename_image3) {
    // Create two image and set properties according to parameters' files
    ppmImage img1(filename_image1);
    ppmImage img2(filename_image2);
    // Create third object to substract other image objects
    ppmImage sum;
    sum = img1 - img2; // Substract objects
    return sum.SaveFile(filename_image3); // Save the file and return 1 or 0
}
int test_print(const string filename_image1) {
    // Create a image object and set properties according to filename_image1 parameter
    ppmImage img(filename_image1);
    if(img.GetHeader() == "not") {return 0;} // If it didn't succesfully read the file header will be "not". So return 0
    cout << img; // If reading is succesfull, print the image
    return 1;
}
int swap_channels(ppmImage& image_object_to_be_modified, int swap_choice) {
    // Call SwapPixelValues and send swap choice to function
    return image_object_to_be_modified.SwapPixelValues(swap_choice);
}
ppmImage single_color(const ppmImage& source, int color_choice) {
    //Create temp object
    // This image object created default, so all values are zero
    ppmImage tempObj(source.GetImageHeight(), source.GetImageWidth());
    // Send source and color choice to function and set rgb values
    tempObj.ChangePixelValue(color_choice, source);
    return tempObj;
}


int& RGB::operator[](int index) {
    /*Return a color according to parameter
    */
    if(index == 0) {
        return red;
    }else if(index == 1) {
        return green;
    }else {
        return blue;
    }
}
const int& RGB::operator[](int index) const {
    /*Return a color according to parameter
    */
    if(index == 0) {
        return red;
    }else if(index == 1) {
        return green;
    }else {
        return blue;
    }
}


ppmImage::ppmImage() {
    // Sets values to zero
    header = "P3";
    imageHeight = 0;
    imageWidth = 0;
    maxValue = 255;
}
ppmImage::ppmImage(const ppmImage& other) {
    // Call == overload operator
    *this = other;
}
ppmImage::ppmImage(const string ppmFileName) {
    int a = ReadFile(ppmFileName);
    if(a == 0) header = "not";
}
ppmImage::ppmImage(const int& inputHeight, const int& inputWidth) {
    // Sets values of image
    header = "P3";
    imageHeight = inputHeight;
    imageWidth = inputWidth;
    maxValue = 255;
    rgbValues.resize(imageHeight, vector<RGB>(imageWidth));
    for(int i = 0; i < imageHeight;++i) {
        for(int j = 0; j < imageWidth;++j) {
            rgbValues[i][j].red = 0;
            rgbValues[i][j].green = 0;
            rgbValues[i][j].blue = 0;
        }
    }
}
ppmImage::ppmImage(const string& inputHeader, const int& inputHeight, const int& inputWidth, const int& inputMaxValue) {
    if(inputMaxValue < 0 || inputMaxValue > 255) {
        cout << "Invalid number for max value" << endl;
    }else {
        // Sets values of image
        header = inputHeader;
        imageHeight = inputHeight;
        imageWidth = inputWidth;
        maxValue = inputMaxValue;
    }
}
void ppmImage::SetHeader(const string& inputHeader) {
    header = inputHeader; // Sets image format of image
}
string ppmImage::GetHeader() const{
    return header; // Returns image format
}
void ppmImage::SetImageHeight(const int& inputHeight) {
    imageHeight = inputHeight; // Sets height of image
}
int ppmImage::GetImageHeight() const{
    return imageHeight; // Returns height of image
}
void ppmImage::SetImageWidth(const int& inputWidth) {
    imageWidth = inputWidth; // Sets width of image
}
int ppmImage::GetImageWidth() const{
    return imageWidth; // Returns width of image
}
void ppmImage::SetMaxValue(const int& inputMaxValue) {
    if(inputMaxValue < 0 || inputMaxValue > 255) {
        cout << "Invalid number for max value" << endl;
    }else {
        maxValue = inputMaxValue; // Sets max value
    }
}
int ppmImage::GetMaxValue() const{
    return maxValue; // Returns max value
}
void ppmImage::SetRGBValues(const vector<vector<RGB>>& inputRGBValues) {
    rgbValues = inputRGBValues; // Sets vector of RGB values
}
vector<vector<RGB>> ppmImage::GetRGBValues() const{
    return rgbValues; // Returns vector of RGB values
}
int ppmImage::ReadFile(const string fileName) {
    ifstream file(fileName); // Opens the file to read
    // If file couldn't open give warning and return to finish function
    if(!file.is_open()) {
        cout << "File couldn't open" << endl;
        return 0;
    }
    string header; // Image format of image
    getline(file,header); // Get first line of the file
    // if(header == "P3") { // If the header is equal to correct image format
        // Get values from the file
        file >> imageWidth;
        file >> imageHeight;
        file >> maxValue;
        rgbValues.resize(imageHeight, vector<RGB>(imageWidth));
        for(int i = 0; i < imageHeight;++i) {
            for(int j = 0; j < imageWidth;++j) {
                file >> rgbValues[i][j].red >> rgbValues[i][j].green >> rgbValues[i][j].blue; // Sets the values of vector's element
            }
        }
    // }
    // // If header is not correct image format, give warning
    // else {
    //     cout << "Invalid format" << endl;
    //     return 0;
    // }
    file.close(); // Closes the file
    return 1;
}
int ppmImage::SaveFile(const string fileName) const{
    ofstream file(fileName); // Opens the file to write
    // If file couldn't open give warning and return to finish function
    if(!file.is_open()) {
        cout << "File couldn't open" << endl;
        return 0;
    }
    file << header << endl; // Gets header of img object and write to file and go to next line
    file << imageWidth << " " << imageHeight << endl; // Gets width and height of img object and write to file and go to next line
    file << maxValue << endl; // Gets max value of img object and write to file and go to next line
    // Loop height of image times(It's like rows)
    for(int i = 0; i < imageHeight;++i) {
        // Loop width of image times(It's like columns)
        for(int j = 0; j < imageWidth;++j) {
            file << rgbValues[i][j].red << " " << rgbValues[i][j].green << " " << rgbValues[i][j].blue << " "; // Write RGB values of the vector at the given index
        }
        file << endl; // Go to next line
    }
    file.close();
    return 1;
}
void ppmImage::PrintDimensions() {
    cout << "Width of Image: " << imageWidth << endl;
    cout << "Height of Image: " << imageHeight << endl;
}
void ppmImage::ChangePixelValue(const int color_choice, const ppmImage& mainObj) {
    // If choice is one
    if(color_choice == 1) {
        for(int i = 0; i < imageHeight;++i) {
            for(int j = 0; j < imageWidth;++j) {
                // Set only red color and others will be stay 0
                (*this)(i,j,1) = mainObj(i,j,1);
            }
        }
    }else if(color_choice == 2) {
        for(int i = 0; i < imageHeight;++i) {
            for(int j = 0; j < imageWidth;++j) {
                // Set only red color and others will be stay 0
                (*this)(i,j,2) = mainObj(i,j,2);
            }
        }
    }else if(color_choice == 3) {
        for(int i = 0; i < imageHeight;++i) {
            for(int j = 0; j < imageWidth;++j) {
                // Set only red color and others will be stay 0
                (*this)(i,j,3) = mainObj(i,j,3);
            }
        }
    }
}
int ppmImage::SwapPixelValues(const int swap_choice) { // not finished swap choice kontrol edilecek
    // If choice is one
    if(swap_choice == 1) {
        for(int i = 0; i < imageHeight;++i) {
            for(int j = 0; j < imageWidth;++j) {
                // Call () operator and swap the two colors
                int temp = (*this)(i,j,1);
                (*this)(i,j,1) = (*this)(i,j,2);
                (*this)(i,j,2) = temp;
            }
        }
    }else if(swap_choice == 2) {
        for(int i = 0; i < imageHeight;++i) {
            for(int j = 0; j < imageWidth;++j) {
                // Call () operator and swap the two colors
                int temp = (*this)(i,j,1);
                (*this)(i,j,1) = (*this)(i,j,3);
                (*this)(i,j,3) = temp;
            }
        }
    }else if(swap_choice == 3) {
        for(int i = 0; i < imageHeight;++i) {
            for(int j = 0; j < imageWidth;++j) {
                // Call () operator and swap the two colors
                int temp = (*this)(i,j,2);
                (*this)(i,j,2) = (*this)(i,j,3);
                (*this)(i,j,3) = temp;
            }
        }
    }
    //If choice is invalid return 0
    else {
        return 0;
    }
    return 1;
}
ppmImage ppmImage::operator +(const ppmImage& other) {
    // Create empty object
    ppmImage temp(imageHeight,imageWidth);
    // If dimensions are same
    if(imageHeight == other.imageHeight && imageWidth == other.imageWidth) {
        for(int i = 0; i < imageHeight;++i) {
        // Loop width of image times(It's like columns)
            for(int j = 0; j < imageWidth;++j) {
                // Sum values and set
                temp.rgbValues[i][j].red = rgbValues[i][j].red + other.rgbValues[i][j].red;
                temp.rgbValues[i][j].green = rgbValues[i][j].green + other.rgbValues[i][j].green;
                temp.rgbValues[i][j].blue = rgbValues[i][j].blue + other.rgbValues[i][j].blue;
                // If value is bigger than maxValue set this value to maxValue
                if(temp.rgbValues[i][j].red > maxValue) temp.rgbValues[i][j].red = maxValue;
                if(temp.rgbValues[i][j].green > maxValue) temp.rgbValues[i][j].green = maxValue;
                if(temp.rgbValues[i][j].blue > maxValue) temp.rgbValues[i][j].blue = maxValue;
            }
        }
    }
    // If dimensions are not same return empty object
    else {
        return temp;
    }
    return temp;
}
ppmImage ppmImage::operator -(const ppmImage& other) {
    // Create empty object
    ppmImage temp(imageHeight,imageWidth);
    // If dimensions are same
    if(imageHeight == other.imageHeight && imageWidth == other.imageWidth) {
        for(int i = 0; i < imageHeight;++i) {
        // Loop width of image times(It's like columns)
            for(int j = 0; j < imageWidth;++j) {
                // Substract values and set
                temp.rgbValues[i][j].red = rgbValues[i][j].red - other.rgbValues[i][j].red;
                temp.rgbValues[i][j].green = rgbValues[i][j].green - other.rgbValues[i][j].green;
                temp.rgbValues[i][j].blue = rgbValues[i][j].blue - other.rgbValues[i][j].blue;
                // If value is smaller than 0 set this value to 0
                if(temp.rgbValues[i][j].red < 0) temp.rgbValues[i][j].red = 0;
                if(temp.rgbValues[i][j].green < 0) temp.rgbValues[i][j].green = 0;
                if(temp.rgbValues[i][j].blue < 0) temp.rgbValues[i][j].blue = 0;
            }
        }
    }
    // If dimensions are not same return empty object
    else {
        return temp;
    }
    return temp;
}
ppmImage& ppmImage::operator =(const ppmImage& other) {
    // If objects are same return this object
    if(this == &other) {
        return *this;
    }else {
        // Sets the values
        header = other.header;
        imageHeight = other.imageHeight;
        imageWidth = other.imageWidth;
        maxValue = other. maxValue;
        rgbValues = other.rgbValues;
    }
    return *this;
}
ostream& operator <<(ostream &outputStream, const ppmImage& imageObj) {
    // Print imageObj's properties
    outputStream << "P3" << endl;
	outputStream << imageObj.imageHeight << " " << imageObj.imageWidth << endl;
	outputStream << imageObj.maxValue << endl;
	// Write pixel values
	for(int i = 0; i < imageObj.imageHeight; ++i){
		for(int j = 0; j < imageObj.imageWidth; ++j) {
			outputStream << imageObj.rgbValues[i][j].red << "  " << imageObj.rgbValues[i][j].green << " " << imageObj.rgbValues[i][j].blue << " ";
        }
		outputStream << endl;
	}

	return outputStream;
}
int& ppmImage::operator ()(int row, int column, int colorChannel) {
    return rgbValues[row][column][colorChannel - 1];
}
const int& ppmImage::operator ()(int row, int column, int colorChannel) const{
    return rgbValues[row][column][colorChannel - 1];
}
vector<RGB>& ppmImage::operator [](int index) {
    return rgbValues[index];
}
const vector<RGB>& ppmImage::operator[](int index) const {
    return rgbValues[index];
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