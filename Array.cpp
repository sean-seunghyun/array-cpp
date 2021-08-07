//Array.cpp
#include"Array.h"
#include<iostream>
using namespace std;
int CompareIntergers(void *one, void *other);



int main(int argc, char* argv[]) {
	Array<Long> array(3);
	Long index;
	Array<Long> one;
	Array<Long> other;
	Long count;
	Long(*indexes);
	Long key;
	Long i;
	//1. �迭�� ù��°�� 5�� �����Ѵ�.
	index = array.Store(0, 5);
	cout << array[index] << endl;
	//2. �迭�� �ι�°�� 6�� �����Ѵ�.
	index = array.Store(1, 6);
	cout << array[index] << endl;
	//3. �迭�� �ι��ſ� 8�� �����Ѵ�.
	index = array.Insert(1, 8);
	cout << array[index] << endl;
	//4. �� ù��°�� 9�� �߰��Ѵ�.
	index = array.AppendFromFront(9);
	cout << array[index] << endl;
	//5. �� �ڿ� 1�� �߰��Ѵ�.
	index = array.AppendFromRear(1);
	cout << array[index] << endl;
	//6. �ι�° ��ġ�� �ִ� ���� �����.
	index = array.Delete(1);
	if (index == -1) {
		cout << "���������ϴ�." << endl;
	}
	//7. �� ó�� ���� �����.
	index = array.DeleteFromFront();
	if (index == -1) {
		cout << "���������ϴ�." << endl;
	}
	//8. �� ������ ���� �����.
	index = array.DeleteFromRear();
	if (index == -1) {
		cout << "���������ϴ�." << endl;
	}
	//9. ��� �����.
	array.Clear();

	//10. �迭�� ù��°�� 5�� ����ִ´�.
	index = array.Insert(0, 5);
	cout << array[index] << endl;

	//11. �迭�� ù��°�� 9�� �ٲ۴�.
	index = array.Modify(0, 9);
	cout << array[index] << endl;

	//12. �� �ڿ� 1�� �߰��Ѵ�.
	index = array.AppendFromRear(1);
	cout << array[index] << endl;


	//13. �� �տ� 9�� �߰��Ѵ�.
	index = array.AppendFromFront(9);
	cout << array[index] << endl;

	cout << "=========================" << endl;

	//14. ���߼����˻����� 9�� ã�´�.
	key = 9;
	array.LinearSearchDuplicate(&key, &indexes, &count, CompareIntergers);
	i = 0;
	while (i < count) {
		cout << array[indexes[i]] << endl;
		i++;
	}
	if (indexes != 0) {
		delete[] indexes;
	}
	cout << "=========================" << endl;
	//15. ���� ������ �Ѵ�.
	array.BubbleSort(CompareIntergers);
	i = 0;
	while (i < array.GetLength()) {
		cout << array[i] << endl;
		i++;
	}
	cout << "=========================" << endl;
	//16. ���� �̺а˻����� 9�� ã�´�.
	key = 9;
	array.BinarySearchDuplicate(&key, &indexes, &count, CompareIntergers);
	i = 0;
	while (i < count) {
		cout << array[indexes[i]] << endl;
		i++;
	}
	if (indexes != 0) {
		delete[] indexes;
	}

	//17. �ι�°�� 0���� �ٲ۴�.
	index = array.Modify(1, 0);
	cout << array[index] << endl;

	//18 �ܼ������˻����� 9�� ã�´�.
	key = 9;
	index = array.LinearSearchUnique(&key, CompareIntergers);
	cout << array[index] << endl;


	cout << "=========================" << endl;
	//19. ���������� �Ѵ�.
	array.SelectionSort(CompareIntergers);
	i = 0;
	while (i < array.GetLength()) {
		cout << array[i] << endl;
		i++;
	}
	cout << "=========================" << endl;
	//20. �ܼ��̺а˻����� 1�� ã�´�.
	key = 1;
	index = array.LinearSearchUnique(&key, CompareIntergers);
	cout << array[index] << endl;

	//21. �迭�� 4��°�� 4�� �߰��Ѵ�.
	index = array.Insert(3, 4);
	cout << array[index] << endl;
	cout << "=========================" << endl;
	//22.  ���������� �Ѵ�.
	array.InsertionSort(CompareIntergers);
	i = 0;
	while (i < array.GetLength()) {
		cout << array[i] << endl;
		i++;
	}

	//23. one �迭�� ù��°�� 3�� �����Ѵ�.
	index = one.Store(0, 3);
	cout << one[index] << endl;

	//24. other �迭�� ù��°�� 3�� �����Ѵ�.
	index = other.Store(0, 3);
	cout << other[index] << endl;

	//25. other �迭�� �ι�°�� 4�� �����Ѵ�.
	index = other.Store(1, 4);
	cout << other[index] << endl;
	cout << "=========================" << endl;

	//26. one�� other�� �����Ѵ�.
	array.Merge(one, other, CompareIntergers);
	i = 0;
	while (i < array.GetLength()) {
		cout << array[i] << endl;
		i++;
	}


	return 0;
}





int CompareIntergers(void *one, void *other) {
	Long *one_ = (Long*)one;
	Long *other_ = (Long*)other;
	int ret;

	if (*one_ > *other_) {
		ret = 1;
	}
	else if (*one_ == *other_) {
		ret = 0;
	}
	else if (*one_ < *other_) {
		ret = -1;
	}

	return ret;
}