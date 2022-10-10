//
// Created by voit on 10.10.2022.
//

#ifndef TEP_ZAD_3_CTREESTATIC_H
#define TEP_ZAD_3_CTREESTATIC_H

#include <iostream>
#include <vector>

class CNodeStatic{
public:
	CNodeStatic() {
		i_val = 0;
		pc_parent_node = NULL;
	};
	~CNodeStatic();

	void vSetValue(int iNewVal) {
		i_val = iNewVal;
	};
	int iGetChildrenNumber() {
		return(v_children.size());
	};
	void vAddNewChild();
	CNodeStatic *pcGetChild(int iChildOffset);
	void vPrint() {
		std::cout << " " << i_val;
	};
	void vPrintAllBelow();
	void vPrintUp();

private:
	std::vector<CNodeStatic> v_children;
	CNodeStatic *pc_parent_node;
	int i_val;
};

class CTreeStatic {
public:
	CTreeStatic();
	~CTreeStatic();
	CNodeStatic *pcGetRoot() {
		return(&c_root);
	}
	void vPrintTree();
private:
	CNodeStatic c_root;
};


#endif //TEP_ZAD_3_CTREESTATIC_H
