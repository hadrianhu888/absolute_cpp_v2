/**
 * @file bar_codes.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "F:/GitHubRepos/absolute_cpp/common.hpp" //always include for every new hpp and cpp file

using namespace std;

int main(int argc, char **argv);

/**
 * @brief encode the binary digit values from left to right: 7, 4, 2, 1, 0 (the rightmost digit is the check digit)
 * 
 */

/**
 * @brief Get a 25 digit binary bar code from the user and print the corresponding zip code
    Split the bar code into 5 groups of 5 digits each
    Convert each group of 5 digits to a decimal number
    Print the decimal numbers as a zip code. Use POSTNET algorithm from US Postal Service for encoding and decoding. 
 */

typedef enum ZIP_CODE_DECODER
{
    BAR_CODE_DECODER_7 = 7,
    BAR_CODE_DECODER_4 = 4,
    BAR_CODE_DECODER_2 = 2,
    BAR_CODE_DECODER_1 = 1,
    BAR_CODE_DECODER_0 = 0
} BAR_CODE_DECODER;

class ZipCode
{
    private: 
        int zip_code;
        int bar_code;
    public: 
        ZipCode();
        ZipCode(int zip_code);
        ~ZipCode();
        int get_zip_code();
        int get_bar_code();
        void set_zip_code(int zip_code);
        void set_bar_code(int bar_code);
        int get_bar_code_from_zip_code(int zip_code);
        int get_zip_code_from_bar_code(int bar_code);
        int zipcode_from_PostNET_algorithm(string bar_code);
}; 

ZipCode::ZipCode()
{
    zip_code = 0;
    bar_code = 0;
}

ZipCode::ZipCode(int zip_code)
{
    this->zip_code = zip_code;
    this->bar_code = get_bar_code_from_zip_code(zip_code);
}

ZipCode::~ZipCode()
{
    /**
     * @brief Create teh zipcode destructor 
     * 
     */
}

int ZipCode::get_zip_code()
{
    return zip_code;
}

int ZipCode::get_bar_code()
{
    return bar_code;
}

void ZipCode::set_zip_code(int zip_code)
{
    this->zip_code = zip_code;
    this->bar_code = get_bar_code_from_zip_code(zip_code);
}

void ZipCode::set_bar_code(int bar_code)
{
    this->bar_code = bar_code;
    this->zip_code = get_zip_code_from_bar_code(bar_code);
}

int ZipCode::get_bar_code_from_zip_code(int zip_code)
{
    /**
     * @brief split the zip code into 5 groups of 5 digits each
     * 
     */
    for(int i = 0; i < 5; i++)
    {
        int digit = zip_code % 10;
        zip_code /= 10;
        /**
         * @brief convert each group of 5 digits to a decimal number
         * 
         */
        switch (digit)
        {
        case 7:
            bar_code += BAR_CODE_DECODER_7;
            break;
        case 4:
            bar_code += BAR_CODE_DECODER_4;
            break;
        case 2:
            bar_code += BAR_CODE_DECODER_2;
            break;
        case 1:
            bar_code += BAR_CODE_DECODER_1;
            break;
        case 0:
            bar_code += BAR_CODE_DECODER_0;
            break;
        default:
            break;
        }
    }
    return bar_code;
}

int ZipCode::get_zip_code_from_bar_code(int bar_code)
{
    /**
     * @brief split the bar code into 5 groups of 5 digits each
     * 
     */
    for(int i = 0; i < 5; i++)
    {
        int digit = bar_code % 10;
        bar_code /= 10;
        /**
         * @brief convert each group of 5 digits to a decimal number
         * 
         */
        switch (digit)
        {
        case BAR_CODE_DECODER_7:
            zip_code += 7;
            break;
        case BAR_CODE_DECODER_4:
            zip_code += 4;
            break;
        case BAR_CODE_DECODER_2:
            zip_code += 2;
            break;
        case BAR_CODE_DECODER_1:
            zip_code += 1;
            break;
        case BAR_CODE_DECODER_0:
            zip_code += 0;
            break;
        default:
            break;
        }
    }
    return zip_code;
}

int ZipCode::zipcode_from_PostNET_algorithm(string bar_code)
{
    /**
     * @split bar code into 5 groups of 5 digits each 
     * Checkt that both length is 25 and the bar code is in binary format
* Apply the POSTNET algorithm to the bar code to get the zip code 
     * 
     */
    if(bar_code.length() != 25 || bar_code.find_first_not_of("01") != string::npos)
    {
        cout << "The bar code is not 25 digits long" << endl;
        return -1;
    }
    else if (bar_code.length() == 25 && bar_code.find_first_not_of("01") == string::npos) 
    {
        /**
         * @brief Apply the POSTNET algorithm to the bar code to get the zip code
         * 
         */
        for(int i = 0; i < 5; i++)
        {
            int digit = 0; 
            /**
             * @brief convert barcode string to int
             * 
             */
            for(int j = 0; j < 5; j++)
            {
                digit = digit * 10 + (bar_code[j] - '0');
            }
            digit = digit % 10;
            bar_code = digit / 10;
            /**
             * @brief convert each group of 5 digits to a decimal number
             * 
             */
            switch (digit)
            {
            case BAR_CODE_DECODER_7:
                zip_code += 7;
                break;
            case BAR_CODE_DECODER_4:
                zip_code += 4;
                break;
            case BAR_CODE_DECODER_2:
                zip_code += 2;
                break;
            case BAR_CODE_DECODER_1:
                zip_code += 1;
                break;
            case BAR_CODE_DECODER_0:
                zip_code += 0;
                break;
            default:
                break;
            }
        }
    }
    return zip_code;
}

int main(int argc, char **argv) 
{
    ZipCode zip_code;
    zip_code.set_zip_code(12345);
    cout << "The zip code is: " << zip_code.get_zip_code() << endl;
    cout << "The bar code is: " << zip_code.get_bar_code() << endl;
    zip_code.set_bar_code(12345);
    cout << "The zip code is: " << zip_code.get_zip_code() << endl;
    cout << "The bar code is: " << zip_code.get_bar_code() << endl;
    string binary_bar_code = "1010101010101010101010101";
    cout << "The zip code is: " << zip_code.zipcode_from_PostNET_algorithm(binary_bar_code) << endl;
    return 0;
}
