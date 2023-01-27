#ifndef HUFFMAN_ALGO_HUFFMANTREE_H
#define HUFFMAN_ALGO_HUFFMANTREE_H
#include "HuffmanNode.cpp"

class HuffmanTree {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, compare> minHeap;
    unsigned oldSize{};// text size before using Huffman coding
    unsigned newSize{}; // text size after using Huffman coding
    map<char,string> newCharCoding;// foreach char we give a string that represents its byte presentation (eg: 0010)
    map<char,unsigned int> charOccurrence;// foreach char we get its occurrence
    void calculateSizes();
public:

    explicit HuffmanTree(const map<char,unsigned>&);

    unsigned getOldSize() const;

    unsigned getNewSize() const;

    void HuffmanCoder();
    void HuffmanCodeFiller(HuffmanNode* , const string&  );
    friend ostream & operator<<(ostream & o,HuffmanTree & tr)
    {
        o<<"\ndata size BEFORE Huffmen coding : "<<tr.oldSize<<" bits"<<endl;
        o<<"data size AFTER Huffmen coding : "<<tr.newSize<<" bits"<<endl;
        o<<"compression rate: "<<((tr.newSize*100)/tr.oldSize)<<"% resized\n";
        o<<"\nHuffmen coding based on characters occurrence:  \n";
        o<<"char\tcode(in bits)\n";
        for(auto & a: tr.newCharCoding){
            o<<a.first<<"   \t"<<a.second<<endl;
        }

        return o;
    }

};


#endif //HUFFMAN_ALGO_HUFFMANTREE_H
