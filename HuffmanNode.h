#ifndef HUFFMAN_ALGO_HUFFMANNODE_H
#define HUFFMAN_ALGO_HUFFMANNODE_H
#include <bits/stdc++.h>
using namespace std;


class HuffmanNode {
// One of the input characters
    char data;
    // Frequency of the character
    unsigned freq;
    // Left and right child
    HuffmanNode *left, *right;
public:
    void setData(char data);

    void setFreq(unsigned int freq);

    void setLeft(HuffmanNode *left);

    void setRight(HuffmanNode *right);

    char getData() const;

    unsigned int getFreq() const;

    HuffmanNode *getLeft() const;

    HuffmanNode *getRight() const;

    HuffmanNode(char data, unsigned freq);

};
// For comparison of
// two heap nodes (needed in min heap)

struct compare {
    bool operator()(HuffmanNode* l, HuffmanNode* r)
    {
        return  (l->getFreq()>r->getFreq());
    }
};
#endif //HUFFMAN_ALGO_HUFFMANNODE_H
