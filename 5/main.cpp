#include "BinaryTreeOfInteger.h"


BinaryTreeOfInteger testMoveConstructor(BinaryTreeOfInteger& tree) {
	
	//tree.insert(7, std::vector<int>{});
	BinaryTreeOfInteger tree2(tree); //ÒÓÒ ÑĞÀÁÎÒÀË ÊÎÍÑÒĞÓÊÒÎĞ ÊÎÏÈĞÎÂÀÍÈß
	return tree2; //À ÒÓÒ ÊÎÍÑÒĞÓÊÒÎÒĞ ÏÅĞÅÌÅÙÅÍÈß (ÂÎÇÂĞÀÙÀÅÒÑß R-VALUE ÁÅÇÛÌßÍÍÛÉ ÎÁÚÅÊÒ, ÎÏÒÈÌÈÇÀÖÈß)
}

BinaryTreeOfInteger testMoveOperator(BinaryTreeOfInteger& tree) {

	//tree.insert(-1000, std::vector<int>{});
	BinaryTreeOfInteger tree2(tree); //ÒÓÒ ÑĞÀÁÎÒÀË ÊÎÍÑÒĞÓÊÒÎĞ ÊÎÏÈĞÎÂÀÍÈß
	return tree2; //À ÒÓÒ ÊÎÍÑÒĞÓÊÒÎÒĞ ÏÅĞÅÌÅÙÅÍÈß (ÂÎÇÂĞÀÙÀÅÒÑß R-VALUE ÁÅÇÛÌßÍÍÛÉ ÎÁÚÅÊÒ, ÎÏÒÈÌÈÇÀÖÈß)
}

int main() {


	setlocale(LC_ALL, "ru");

	//ÑÎÇÄÀÅÌ ÄÅĞÅÂÎ
	BinaryTreeOfInteger tree;
	tree.insert(0, std::vector<int>());     //           0
	tree.insert(1, std::vector<int>{0});    //       1      2
	tree.insert(2, std::vector<int>{1});    //    3    4
	tree.insert(3, std::vector<int>{0,0});
	tree.insert(4, std::vector<int>{0, 1});

	//ÂÛÂÎÄÈÌ ÄÅĞÅÂÎ
	std::cout << tree << std::endl;

	//ÏĞÎÂÅĞßÅÌ ÎØÈÁÊÈ ÂÑÒÀÂÊÈ ÏĞÈ ÍÅÂÅĞÍÎÌ ÏÓÒÈ (ÑËÈØÊÎÌ ÄËÈÍÍÛÉ ÈËÈ ÍÅÊÎĞĞÅÊÒÍÛÅ ×ÈÑËÀ - ÍÅ 0 ÈËÈ 1)
	try {
		tree.insert(100, std::vector<int>{1, 1, 1, 1});
	}
	catch (std::invalid_argument ex) {
		std::cout << std::endl << ex.what() << std::endl;
	}
	try {
		tree.insert(100, std::vector<int>{-1});
	}
	catch (std::invalid_argument ex) {
		std::cout << std::endl << ex.what() << std::endl;
	}

	//ÏĞÎÂÅĞßÅÌ ÊÎĞĞÅÊÒÍÓÁ ÂÑÒÀÂÊÓ
	tree.insert(-1, std::vector<int>{0, 1});
	std::cout << std::endl << "Ìåíÿåì ıëåìåíò ñ ïóòåì {0, 1}: " << tree << std::endl;

	//ÑÎÇÄÀÅÌ ÂÒÎĞÎÅ ÄÅĞÅÂÎ Ñ ÏÎÌÎÙÜŞ ÊÎÍÑÒĞÓÊÒÎĞÀ ÊÎÏÈĞÎÂÀÍÈß
	std::cout << std::endl << "Ñîçäàåì âòîğîå äåğåâî ñ ïîìîùüş êîíñòğóêòîğà êîïèğîâàíèÿ: ";
	BinaryTreeOfInteger tree2(tree);
	std::cout << tree2 << std::endl;

	//ÏĞÎÂÅĞßÅÌ ×ÒÎ İÒÎ ĞÀÇÍÛÅ ÔÈÇÈ×ÅÑÊÈ ÄÅĞÅÂÜß, ÇÀÎÄÍÎ ÅÙÅ ĞÀÇ ÒÅÑÒÈÌ ÂÑÒÀÂÊÓ Â ÊÎĞÅÍÜ
	tree2.insert(100, std::vector<int>{});
	tree.insert(-100, std::vector<int>{1});
	std::cout << std::endl << "Ïğîâåğÿåì, ÷òî îíè èçìåíÿşòñÿ íåçàâèñèìî äğóã îò äğóãà: " << tree << " || " << tree2 << std::endl;

	//ÏĞÎÂÅĞßÅÌ ÊÎÍÑÒĞÓÊÒÎĞ ÏÅĞÅÌÅÙÅÍÈß
	std::cout << std::endl << "Ïğîâåğÿåì êîíñòğóêòîğ ïåğìåùåíèÿ(âñòàâêà â êîğåíü ïåğâîãî äåğåâî 1000): ";
	BinaryTreeOfInteger tree3(testMoveConstructor(tree));
	tree.insert(1000, std::vector<int>{});
	std::cout << tree << " || " << tree3 << std::endl;

	//ÏĞÎÂÅĞßÅÌ ÎÏÅĞÀÒÎĞ ÏĞÈÑÂÀÈÂÀÍÈß	
	std::cout << std::endl << "Ïğîâåğÿåì îïåğàòîğ ïğèñâàèâàíèÿ 1=2 è (óäàëÿåì ëèñòüÿ â tree3): ";
	tree = tree3;
	tree3.removeAllLeaf();// À çàîäíî óäàëåíèå ëèñòüåâ
	std::cout << tree << " || " << tree3 << std::endl;

	//ÏĞÎÂÅĞßÅÌ ÎÏÅĞÀÒÎĞ ÏÅĞÅÌÅÙÅÍÈß
	std::cout << std::endl << "Ïğîâåğÿåì îïåğàòîğ ïåğìåùåíèÿ (âñòàâêà â êîğåíü ïåğâîãî äåğåâî 0): ";
	tree = testMoveConstructor(tree3);
	tree.insert(1000, std::vector<int>{});
	std::cout << tree << " || " << tree3 << std::endl;

	//ÊÎËÈ×ÅÑÒÂÎ ×ÅÒÍÛÕ ×ÈÑÅË Â ÄÅĞÅÂÅ
	std::cout << std::endl << tree2 << "   ÷åòíûõ: " << tree2.getNumberOfEven();
	//      100
	//    1     2
	//  3   -1
	
	//ÏĞÎÂÅĞÊÀ ×ÒÎ ÒÎËÜÊÎ ÏÎËÎÆÈÒÅËÜÍÛÅ ×ÈÑËÀ
	std::cout << std::endl << tree2 << "   òîëüêî ïîëîæèòåëüíûå?: " << tree2.isContainPositiveOnly();
	std::cout << std::endl << tree << "   òîëüêî ïîëîæèòåëüíûå?: " << tree.isContainPositiveOnly();
	
	//ÑĞÅÄÍÅÅ ÀĞÈÔÌÅÒÈ×ÅÑÊÎÅ
	std::cout << std::endl << tree2 << "ñğåäíåå àğèôìåòè÷åñêîå: " << tree2.getArithmeticalMean();
	tree2.insert(99, std::vector<int>{});
	std::cout << std::endl << tree2 << "ñğåäíåå àğèôìåòè÷åñêîå: " << tree2.getArithmeticalMean();
	tree2.~BinaryTreeOfInteger();
	std::cout << std::endl << tree2 << "ñğåäíåå àğèôìåòè÷åñêîå: " << tree2.getArithmeticalMean();
	

	tree.insert(0, std::vector<int>());     //             0
	tree.insert(1, std::vector<int>{0});    //       1          2
	tree.insert(2, std::vector<int>{1});    //    3    4
	tree.insert(3, std::vector<int>{0, 0}); //            5
	tree.insert(4, std::vector<int>{0, 1});
	tree.insert(5, std::vector<int>{0, 1, 1});

	//ÈÙÅÌ ×ÈÑËA
	std::cout << std::endl << tree << "ïóòü ê ıëåìåíòó 5: ";
	std::vector<int> path(tree.find(5));
	for (int i : path) {
		std::cout << i << " ";
	}
	std::cout << std::endl << tree << "ïóòü ê ıëåìåíòó 100: ";
	path = tree.find(100);
	for (int i : path) {
		std::cout << i << " ";
	}
	std::cout << std::endl << tree << "ïóòü ê ıëåìåíòó 3: ";
	path = tree.find(3);
	for (int i : path) {
		std::cout << i << " ";
	}
	


}