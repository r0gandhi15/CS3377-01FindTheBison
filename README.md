On the UTD Linux systems, the test case files are located in:  
 
/people/cs/s/smd013000/3377/assigns/01/testcases 
 
Use the following command to get the required files into your current working development directory: 
 cp /people/cs/s/smd013000/3377/assigns/01/testcases/* . 
 
Use these test case nbisonsearchin.txt input files to run your program.  
 
Each nbisonsearchin.txt input file contains string of parentheses of length N (1 <= N <= 50,000).  
Example:  file bisonsearchin.txt: 
 )((()())())  
Check to make sure each file nbisonsearchin.txt opens successfully, where n is the file number.  

The following is how to correctly use g++ to correctly build C++ source code on Linux.
g++ -std=c++11 bison.cpp -o bison
To run the execution file:
./bison
