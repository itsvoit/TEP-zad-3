//
// Created by voit on 10.10.2022.
//

#include "CTreeStatic.h"
#include <algorithm>

// --------------------------------
//	class CNodeStatic


void CNodeStatic::vAddNewChild() {
//	std::cout << "Add new child\n";
	CNodeStatic pcTempNode;
	v_children.push_back(pcTempNode);
	vUpdateParentsBelow();
}

CNodeStatic *CNodeStatic::pcGetChild(int iChildOffset) {
	if (iChildOffset < 0 || iChildOffset >= v_children.size())
		return NULL;

	return &v_children[iChildOffset];
}

void CNodeStatic::vPrintAllBelow(int level) {
	for (int i = 0; i < level; ++i) {
		std::cout << "  ";
	}
	vPrint();
	std::cout << "\n";
	for (int i = 0; i < v_children.size(); ++i) {
		v_children[i].vPrintAllBelow(level+1);
	}
}

void CNodeStatic::vPrintAllBelow() {
	vPrintAllBelow(0);
}

CNodeStatic::~CNodeStatic() {
//	std::cout << "Deleting node with value: " << i_val << std::endl;
}

void CNodeStatic::vPrintUp() {
	vPrint();
	if (pc_parent_node != NULL)
		pc_parent_node->vPrintUp();
	else
		std::cout << std::endl;
}

void CNodeStatic::vUpdateParentsBelow(){
	for (std::vector<CNodeStatic>::iterator it = v_children.begin(); it != v_children.end(); ++it){
		it -> pc_parent_node = this;
		if (it -> v_children.size() != 0) it->vUpdateParentsBelow();
	}
}

// --------------------------------
//	class CTreeStatic

CTreeStatic::CTreeStatic() {
	b_root_exists = true;
}

CTreeStatic::~CTreeStatic() {
}

CNodeStatic* CTreeStatic::pcGetRoot() {
	if (!b_root_exists) return NULL;
	return(&c_root);
}

void CTreeStatic::vPrintTree() {
	if (!b_root_exists) {
		std::cout << "Root does not exist";
		return;
	}
	c_root.vPrintAllBelow();
}

bool CTreeStatic::bMoveSubTree(CNodeStatic *pcParentNode, CNodeStatic *pcNewChildNode){
	if (pcParentNode == NULL || pcNewChildNode == NULL) return false;

	// move newChildNode to parentNode
	// fix parents for every node (even already existing because vector can extend)
	pcParentNode -> v_children.push_back(*pcNewChildNode);
	pcParentNode->vUpdateParentsBelow();
	
	// remove newChildNode from its previous parent
	// update parent nodes 
	if (pcNewChildNode == &c_root){
		b_root_exists = false;
		return true;
	}

	std::vector<CNodeStatic> children = pcNewChildNode -> pc_parent_node -> v_children;
	for (std::vector<CNodeStatic>::iterator it = children.begin(); it != children.end(); ++it){
		if (&*it == pcNewChildNode) {
			children.erase(it);
			break;
		}
	}

	pcNewChildNode->pc_parent_node->vUpdateParentsBelow();
	
	return true;
}
