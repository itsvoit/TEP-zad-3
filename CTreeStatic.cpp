//
// Created by voit on 10.10.2022.
//

#include "CTreeStatic.h"

void CNodeStatic::vAddNewChild() {
	std::cout << "Add new child\n";
	CNodeStatic *pcTempNode = new CNodeStatic;
	pcTempNode->pc_parent_node = this;
	v_children.push_back(*pcTempNode);
}

CNodeStatic *CNodeStatic::pcGetChild(int iChildOffset) {
	if (iChildOffset < 0 || iChildOffset >= v_children.size())
		return NULL;

	return &v_children[iChildOffset];
}

void CNodeStatic::vPrintAllBelow() {
	for (int i = 0; i < v_children.size(); ++i) {
		v_children[i].vPrint();
		v_children[i].vPrintAllBelow();
	}
}

CNodeStatic::~CNodeStatic() {
	std::cout << "Deleting node with value: " << i_val << std::endl;
}

void CNodeStatic::vPrintUp() {
	vPrint();
	if (pc_parent_node != NULL)
		pc_parent_node->vPrintUp();
	else
		std::cout << std::endl;
}

CTreeStatic::CTreeStatic() {
}

CTreeStatic::~CTreeStatic() {

}

void CTreeStatic::vPrintTree() {
	for (int i = 0; i < c_root.iGetChildrenNumber(); ++i) {
		c_root.pcGetChild(i)->vPrintAllBelow();
	}
}
