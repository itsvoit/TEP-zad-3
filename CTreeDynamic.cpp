//
// Created by voit on 10.10.2022.
//

#include <algorithm>
#include "CTreeDynamic.h"

CNodeDynamic::~CNodeDynamic() {
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

void CNodeDynamic::vPrintAllBelow() {
	vPrint();
	for (int i = 0; i < v_children.size(); ++i) {
		v_children[i]->vPrintAllBelow();
	}
}

CTreeDynamic::CTreeDynamic() {
	pc_root = NULL;
}

CTreeDynamic::~CTreeDynamic() {
	if (pc_root != NULL)
		delete pc_root;
}

void CTreeDynamic::vPrintTree() {
	pc_root->vPrintAllBelow();
}

bool CTreeDynamic::bMoveSubTree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode) {
	if (pcParentNode == NULL || pcNewChildNode == NULL) return false;

	// add pcNewChildNode to the new tree
	pcParentNode->v_children.push_back(pcNewChildNode);

	// temp vector for erase-remove
	std::vector<CNodeDynamic*> v_newChild_parent_children = pcNewChildNode->pc_parent_node->v_children;

	// remove pcNewChildNode from its parent
	v_newChild_parent_children.erase(std::remove(v_newChild_parent_children.begin(), v_newChild_parent_children.end(), pcNewChildNode), v_newChild_parent_children.end());

	return true;
}
