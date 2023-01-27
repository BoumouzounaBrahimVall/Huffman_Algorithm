#include "HuffmanTree.h"

HuffmanTree::HuffmanTree(const map<char, unsigned int>& tokens) {
    oldSize=newSize=0;//initilize oldSize & newSize variables variable
    for(auto & token : tokens)
    {
        oldSize+=token.second; //nbr char in the data
        charOccurrence.insert(token);
        minHeap.push(new HuffmanNode(token.first,token.second));
    }
}

void HuffmanTree::HuffmanCoder() {
    HuffmanNode *left, *right, *top;
// Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1) {
        // Extract the two minimum
        // frequency items from min heap
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        /*Create a new internal node with frequency equal to the sum of the two nodes frequencies.
         Make the two extracted node as left and right children of this new node.
         Add this node to the min heap '$' is a special value for internal nodes, not used*/

        top = new HuffmanNode('$', left->getFreq() + right->getFreq());

        top->setLeft(left );
        top->setRight(right);

        minHeap.push(top);
    }
    HuffmanCodeFiller(minHeap.top(), "");
    calculateSizes();
}

void HuffmanTree::HuffmanCodeFiller(HuffmanNode * root , const string& str)
{
    if (!root)return;
    if (root->getData() != '$') {
        newCharCoding.insert( pair(root->getData(),str));
    }
    HuffmanCodeFiller(root->getLeft(), str + "0");
    HuffmanCodeFiller(root->getRight(), str + "1");
}


unsigned HuffmanTree::getOldSize() const {
    return oldSize;
}

unsigned HuffmanTree::getNewSize() const {
    return newSize;
}

void HuffmanTree::calculateSizes() {
    // old coding size calculation
    oldSize=oldSize*8; // char is 8 bits
    // new coding size calculation
    for(auto & a:newCharCoding){
            newSize+=(a.second.size()*charOccurrence[a.first]);
    }
}
