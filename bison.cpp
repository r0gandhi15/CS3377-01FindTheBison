
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <locale>
#include <time.h>
#include <limits>
#include <stdexcept>
#include <cstdlib>

#define BILLION 1000000000L
#include "LineInfo.h"

using namespace std;

const string input_file_name = "bisonsearchin.txt";
const string output_file_name = "bisonfoundin.txt";
const uint8_t max_file_no = 10;

int main(){
    cout.imbue(locale(""));

    uint64_t diff;
    struct timespec start, end;

    string findBison;
    string inputFile, outputFile;
    uint64_t fileCount = 0;

    try{
        do{
            fileCount++;

            inputFile = outputFile = to_string(fileCount);

            if(inputFile.size() == 1){
                inputFile = "0" + inputFile;
                outputFile = "0" + outputFile;

            }

            inputFile = inputFile + input_file_name;
            outputFile = outputFile + output_file_name;

            ifstream inputParensStreamObj(inputFile);
            if(inputParensStreamObj.fail())
                throw domain_error(LineInfo("failed to open file " + inputFile, __FILE__, __LINE__));

            ofstream outputParensStreamObj(outputFile);
            if(outputParensStreamObj.fail())
                throw domain_error(LineInfo("failed to open file " + outputFile, __FILE__, __LINE__));

            outputParensStreamObj.imbue(locale(""));

            inputParensStreamObj >> findBison;

            unsigned bisonPatternCount = 0;
            unsigned backParenCount = 0;

            //start timer
             clock_gettime(CLOCK_MONOTONIC, &start);

            size_t size = findBison.size();
            for(unsigned i = 1; i < size; i++){
                if (findBison[i - 1] == '(' && findBison[i] == '(')
                    backParenCount++;

                else if (findBison[i - 1] == ')' && findBison[i] == ')')
                   bisonPatternCount +=  backParenCount;

            }
            //stop timer
            clock_gettime(CLOCK_MONOTONIC, &end);

            diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
            cout << "time = " << diff << "nanoseconds" << endl;

            outputParensStreamObj << "Time Elapsed in Nanoseconds: " << setw(15) << diff << endl;
            outputParensStreamObj << "Pattern Count: " << bisonPatternCount << endl;

            outputParensStreamObj << "Searched Pattern: " << findBison << endl;

            outputParensStreamObj.close();

        } while( fileCount != max_file_no);
    }
    catch (exception& e) {
        cout << e.what() << endl;
        cout << "Press the enter key once or twice to leave" << endl;
        cin.ignore(); cin.get();
    }

    return EXIT_SUCCESS;
}
