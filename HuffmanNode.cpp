#include "HuffmanNode.h"

HuffmanNode::HuffmanNode(char data, unsigned int freq) {
    left = right = nullptr;
    this->data = data;
    this->freq = freq;
}

char HuffmanNode::getData() const {
    return data;
}

unsigned int HuffmanNode::getFreq() const {
    return freq;
}

HuffmanNode *HuffmanNode::getLeft() const {
    return left;
}

HuffmanNode *HuffmanNode::getRight() const {
    return right;
}

void HuffmanNode::setData(char data) {
    HuffmanNode::data = data;
}

void HuffmanNode::setFreq(unsigned int freq) {
    HuffmanNode::freq = freq;
}

void HuffmanNode::setLeft(HuffmanNode *left) {
    HuffmanNode::left = left;
}

void HuffmanNode::setRight(HuffmanNode *right) {
    HuffmanNode::right = right;
}
