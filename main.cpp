#include "HuffmanTree.cpp"
void getDataFromFile(map<char,unsigned > & text, const string& fileName){
    // Open the file
    ifstream MyReadFile(fileName);
    // Check if the file is open
    if (MyReadFile.is_open()) {
        // Use a while loop together with the getline() function to read the file line by line
        string textLine;
        while (getline (MyReadFile, textLine)) {
            // Iterate over each character in the line
            for(char c:textLine){
                // Increment the count of the current character in the map
                text[c]++;
            }
        }
        // Close the file
        MyReadFile.close();
    } else {
        // Print an error message if the file could not be opened
        cout << "error opening file  " << fileName << endl;
    }
}
int main()
{
    map<char,unsigned > text{};
    getDataFromFile(text,"data.txt"); // geting the text data

    HuffmanTree tr(text);
    tr.HuffmanCoder();
    cout<<tr; //

	return 0;
}
/*
 example of execution :

 output:

data size BEFORE Huffmen coding : 4152 bits
data size AFTER Huffmen coding : 2244 bits
compression rate: 54% resized

Huffmen coding based on characters occurrence:
char    code(in bits)
        0101001
0       011101000
4       01010001
5       01110110
7       01010000
8       01110101
b       10010
c       01110111
d       0110
e       11111
f       000
g       1000
h       1100
i       11011
j       1110
k       10011
l       01111
m       1101000
n       1010
o       11110
p       011100
r       1011
s       01011
t       001
u       010101
v       1101001
w       110101
x       011101001
y       0100

 */
