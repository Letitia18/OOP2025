#include "NumberList.h"
#include <iostream>

int main() {
	NumberList list;
	list.Init();
	list.Add(5);
	list.Add(3);
	list.Add(7);
	list.Sort();
	list.Print();

	system("pause");

	return 0;
}
