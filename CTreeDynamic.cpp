//
// Created by voit on 10.10.2022.
//

#include <algorithm>
#include "CTreeDynamic.h"


// --------------------------------
//	class CNodeDynamic


CNodeDynamic::CNodeDynamic() {
	i_val = 0;
	pc_parent_node = NULL;
}

CNodeDynamic::~CNodeDynamic() {
//	std::cout << "Deleting node with val " << i_val << '\n';
	for (int i = 0; i < v_children.size(); ++i) {
		delete v_children[i];
	}
}

void CNodeDynamic::vAddNewChild() {
	CNodeDynamic *pcTempNode = new CNodeDynamic;
	pcTempNode->pc_parent_node = this;
	v_children.push_back(pcTempNode);
}

CNodeDynamic *CNodeDynamic::pcGetChild(int iChildOffset) {
	if (iChildOffset < 0 || iChildOffset >= v_children.size())
		return NULL;

	return v_children[iChildOffset];
}

void CNodeDynamic::vPrintAllBelow(int level) {
	for (int i = 0; i < level; ++i) {
		std::cout << "  ";
	}
	vPrint();
	std::cout << "\n";
	for (int i = 0; i < v_children.size(); ++i) {
		v_children[i]->vPrintAllBelow(level+1);
	}
}

void CNodeDynamic::vPrintAllBelow() {
	vPrintAllBelow(0);
}


// --------------------------------
//	class CTreeDynamic


CTreeDynamic::CTreeDynamic() {
	pc_root = new CNodeDynamic;
}

CTreeDynamic::~CTreeDynamic() {
	if (pc_root == NULL) return;

	delete pc_root;
}

void CTreeDynamic::vPrintTree() {
	if (pc_root == NULL) {
		std::cout << "Root is NULL";
		return;
	}
	pc_root->vPrintAllBelow();
}

// Parent from foreign tree and child from this tree
bool CTreeDynamic::bMoveSubTree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode) {
	if (pcParentNode == NULL || pcNewChildNode == NULL) return false;

	// add pcNewChildNode to the new tree
	pcParentNode->v_children.push_back(pcNewChildNode);

	// if newChildNode is a root of this tree, return
	if (pcNewChildNode == pc_root){
		pc_root = NULL;
		return true;
	}

	// temp vector for erase-remove
	std::vector<CNodeDynamic*> v_newChild_parent_children = pcNewChildNode->pc_parent_node->v_children;

	// remove pcNewChildNode from its parent
	v_newChild_parent_children.erase(std::remove(v_newChild_parent_children.begin(), v_newChild_parent_children.end(), pcNewChildNode), v_newChild_parent_children.end());

	return true;
}
