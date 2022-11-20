//
// Created by voit on 10.10.2022.
//

#include <iostream>
#include "CTreeStatic.h"
#include "CTreeDynamic.h"

void v_tree_static_test()
{
	CTreeStatic c_tree;
	c_tree.pcGetRoot() -> vAddNewChild();
	c_tree.pcGetRoot() -> vAddNewChild();
	c_tree.pcGetRoot() -> pcGetChild(0)->vSetValue(1);
	c_tree.pcGetRoot() -> pcGetChild(1)->vSetValue(2);
	c_tree.pcGetRoot() -> pcGetChild(0)->vAddNewChild();
	c_tree.pcGetRoot() -> pcGetChild(0)->vAddNewChild();
	c_tree.pcGetRoot() -> pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_tree.pcGetRoot() -> pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	c_tree.pcGetRoot() -> pcGetChild(1)->vAddNewChild();
	c_tree.pcGetRoot() -> pcGetChild(1)->vAddNewChild();
	c_tree.pcGetRoot() -> pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_tree.pcGetRoot() -> pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	std::cout << "Print up from 11:";
	c_tree.pcGetRoot() -> pcGetChild(0)->pcGetChild(0)->vPrintUp();

	std::cout << "Print tree:\n";
	c_tree.vPrintTree();
	std::cout << "\n";

	CTreeStatic c_sub_tree;
	c_sub_tree.pcGetRoot()->vSetValue(3);
	c_sub_tree.pcGetRoot()->vAddNewChild();
	c_sub_tree.pcGetRoot()->vAddNewChild();
	c_sub_tree.pcGetRoot()->pcGetChild(0)->vSetValue(31);
	c_sub_tree.pcGetRoot()->pcGetChild(1)->vSetValue(32);

	std::cout << "Move sub tree: " << std::boolalpha << c_sub_tree.bMoveSubTree(c_tree.pcGetRoot()->pcGetChild(0), c_sub_tree.pcGetRoot()) << "\n";

	std::cout << "Sub tree after move:\n";
	c_sub_tree.vPrintTree();
	std::cout << "\nTree after move:\n";
	c_tree.vPrintTree();

	std::cout << "Print up from 31:";
	c_tree.pcGetRoot() -> pcGetChild(0)-> pcGetChild(2)->pcGetChild(1)->vPrintUp();

	CTreeStatic c_sub_tree2;
	c_sub_tree2.pcGetRoot()->vSetValue(4);
	c_sub_tree2.pcGetRoot()->vAddNewChild();
	c_sub_tree2.pcGetRoot()->vAddNewChild();
	c_sub_tree2.pcGetRoot()->pcGetChild(0)->vSetValue(41);
	c_sub_tree2.pcGetRoot()->pcGetChild(1)->vSetValue(42);

	std::cout << "Move sub tree: " << std::boolalpha << c_sub_tree2.bMoveSubTree(c_tree.pcGetRoot()->pcGetChild(0), c_sub_tree2.pcGetRoot()->pcGetChild(0)) << "\n";

	std::cout << "Sub tree after move:\n";
	c_sub_tree2.vPrintTree();
	std::cout << "\nTree after move:\n";
	c_tree.vPrintTree();

}// void v_tree_static_test()


void v_tree_dynamic_test(){
	CTreeDynamic c_tree;
	c_tree.pcGetRoot()->vAddNewChild();
	c_tree.pcGetRoot()->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	c_tree.pcGetRoot()->pcGetChild(1)->vSetValue(2);
	c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	std::cout << "Print tree:\n";
	c_tree.vPrintTree();
	std::cout << "\n";

	CTreeDynamic c_sub_tree;
	c_sub_tree.pcGetRoot()->vSetValue(3);
	c_sub_tree.pcGetRoot()->vAddNewChild();
	c_sub_tree.pcGetRoot()->vAddNewChild();
	c_sub_tree.pcGetRoot()->pcGetChild(0)->vSetValue(31);
	c_sub_tree.pcGetRoot()->pcGetChild(1)->vSetValue(32);

	std::cout << "Move sub tree: " << std::boolalpha << c_sub_tree.bMoveSubTree(c_tree.pcGetRoot()->pcGetChild(0), c_sub_tree.pcGetRoot()) << "\n";

	std::cout << "Sub tree after move:\n";
	c_sub_tree.vPrintTree();
	std::cout << "\nTree after move:\n";
	c_tree.vPrintTree();


	CTreeDynamic c_sub_tree2;
	c_sub_tree2.pcGetRoot()->vSetValue(4);
	c_sub_tree2.pcGetRoot()->vAddNewChild();
	c_sub_tree2.pcGetRoot()->vAddNewChild();
	c_sub_tree2.pcGetRoot()->pcGetChild(0)->vSetValue(41);
	c_sub_tree2.pcGetRoot()->pcGetChild(1)->vSetValue(42);

	std::cout << "Move sub tree: " << std::boolalpha << c_sub_tree2.bMoveSubTree(c_tree.pcGetRoot()->pcGetChild(0), c_sub_tree2.pcGetRoot()->pcGetChild(0)) << "\n";

	std::cout << "Sub tree after move:\n";
	c_sub_tree2.vPrintTree();
	std::cout << "\nTree after move:\n";
	c_tree.vPrintTree();

}// v_tree_dynamic_test()


int main(){

	std::cout << "------------------\nStatic test\n";
	v_tree_static_test();

	std::cout << "------------------\nDynamic test\n";
	v_tree_dynamic_test();

	return 0;
}