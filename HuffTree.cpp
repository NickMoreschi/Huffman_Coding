#include "HuffTree.h"
#include "PQueue.h"
#include <string>
using namespace std;

string HuffTree::getCode(char chr) {
    string code = findNode(chr, _root, "");
    return code;
}

string HuffTree::findNode(char chr, HuffNode *node, string str) { 
    string find;
    if (!node -> left && !node -> right) {
        if (node -> data == chr) {
            find = str;
        }
    }
    else {
        if ((find = findNode(chr, node -> left, str + "0")) == "") {
            find = findNode(chr, node -> right, str + "1");
        }
        if ((find = findNode(chr, node -> right, str + "1")) == "") {
            find = findNode(chr, node -> left, str + "0");
        }
    }
    return find;
}

HuffTree::~HuffTree() {
    deleteFullTree(_root);
}

void HuffTree::deleteFullTree(HuffNode *rootNode) {
    if (rootNode == 0) {
        return;
    }
    deleteFullTree(rootNode -> left);
    deleteFullTree(rootNode -> right);
    delete rootNode;
}

void HuffTree::buildTree(char *chs, int* freqs, int size) {
    PQueue<HuffNode, 1000> q;

    for (int i = 0; i < size; i++) {
        q.insert(HuffNode(0, 0, freqs[i], chs[i]));
    }

    while (q.size() != 1) {
        HuffNode *min1 = new HuffNode();
        *min1 = q.findMin();
        q.deleteMin();

        HuffNode *min2 = new HuffNode();
        *min2 = q.findMin();
        q.deleteMin();

        HuffNode *total = new HuffNode;

        total -> left = min1;
        total -> right = min2;
        total -> freq = (min1 -> freq + min2 -> freq);
        total -> data = 0;

        q.insert(*total);

        _root = total;
    }

    //printTree(cout, 0, _root);
}

void HuffTree::printTree(ostream& out, int level, HuffNode *p) const{
	int i;
	if (p) {
		printTree(out, level+1, p->right);
		for(i=0;i<level;i++) {
			out << "\t";
		}
		out << p->freq << " " << p->data << '\n';
		printTree(out, level+1, p->left);
	}
}

bool HuffNode::operator < (const HuffNode node) {
    return freq < node.freq;
}

bool HuffNode::operator <= (const HuffNode node) {
    return freq <= node.freq;
}

bool HuffNode::operator > (const HuffNode node) {
    return freq > node.freq;
}

bool HuffNode::operator >= (const HuffNode node) {
    return freq >= node.freq;
}