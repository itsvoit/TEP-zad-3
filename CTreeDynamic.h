//
// Created by voit on 10.10.2022.
//

#ifndef TEP_ZAD_3_CTREEDYNAMIC_H
#define TEP_ZAD_3_CTREEDYNAMIC_H

#include <iostream>
#include <vector>

class CNodeDynamic
{
public:
	CNodeDynamic() {
		i_val = 0;
		pc_parent_node = NULL;
	};
	~CNodeDynamic();
	void vSetValue(int iNewVal) {
		i_val = iNewVal;
	};
	int iGetChildrenNumber() {
		return(v_children.size());
	};
	void vAddNewChild();
	CNodeDynamic *pcGetChild(int iChildOffset);
	void vPrint() {
		std::cout << " " << i_val;
	};
	void vPrintAllBelow();
private:
	std::vector<CNodeDynamic *> v_children;
	CNodeDynamic *pc_parent_node;
	int i_val;

	friend class CTreeDynamic;
}; //class CNodeDynamic

class CTreeDynamic
{
public:
	CTreeDynamic();
	~CTreeDynamic();
	CNodeDynamic *pcGetRoot() {
		return(pc_root);
	}
	void vPrintTree();
	bool bMoveSubTree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode);
private:
	CNodeDynamic *pc_root;
}; //class CTreeDynamic


#endif //TEP_ZAD_3_CTREEDYNAMIC_H
