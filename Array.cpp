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
	//1. 배열의 첫번째에 5를 저장한다.
	index = array.Store(0, 5);
	cout << array[index] << endl;
	//2. 배열의 두번째에 6을 저장한다.
	index = array.Store(1, 6);
	cout << array[index] << endl;
	//3. 배열의 두번쩨에 8을 삽입한다.
	index = array.Insert(1, 8);
	cout << array[index] << endl;
	//4. 맨 첫번째에 9를 추가한다.
	index = array.AppendFromFront(9);
	cout << array[index] << endl;
	//5. 맨 뒤에 1을 추가한다.
	index = array.AppendFromRear(1);
	cout << array[index] << endl;
	//6. 두번째 위치에 있는 값을 지운다.
	index = array.Delete(1);
	if (index == -1) {
		cout << "지워졌습니다." << endl;
	}
	//7. 맨 처음 값을 지운다.
	index = array.DeleteFromFront();
	if (index == -1) {
		cout << "지워졌습니다." << endl;
	}
	//8. 맨 마지막 값을 지운다.
	index = array.DeleteFromRear();
	if (index == -1) {
		cout << "지워졌습니다." << endl;
	}
	//9. 모두 지운다.
	array.Clear();

	//10. 배열의 첫번째에 5를 집어넣는다.
	index = array.Insert(0, 5);
	cout << array[index] << endl;

	//11. 배열의 첫번째를 9로 바꾼다.
	index = array.Modify(0, 9);
	cout << array[index] << endl;

	//12. 맨 뒤에 1을 추가한다.
	index = array.AppendFromRear(1);
	cout << array[index] << endl;


	//13. 맨 앞에 9를 추가한다.
	index = array.AppendFromFront(9);
	cout << array[index] << endl;

	cout << "=========================" << endl;

	//14. 다중선형검색으로 9를 찾는다.
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
	//15. 버블 정렬을 한다.
	array.BubbleSort(CompareIntergers);
	i = 0;
	while (i < array.GetLength()) {
		cout << array[i] << endl;
		i++;
	}
	cout << "=========================" << endl;
	//16. 다중 이분검색으로 9를 찾는다.
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

	//17. 두번째를 0으로 바꾼다.
	index = array.Modify(1, 0);
	cout << array[index] << endl;

	//18 단순선형검색으로 9를 찾는다.
	key = 9;
	index = array.LinearSearchUnique(&key, CompareIntergers);
	cout << array[index] << endl;


	cout << "=========================" << endl;
	//19. 선택정렬을 한다.
	array.SelectionSort(CompareIntergers);
	i = 0;
	while (i < array.GetLength()) {
		cout << array[i] << endl;
		i++;
	}
	cout << "=========================" << endl;
	//20. 단순이분검색으로 1을 찾는다.
	key = 1;
	index = array.LinearSearchUnique(&key, CompareIntergers);
	cout << array[index] << endl;

	//21. 배열의 4번째에 4를 추가한다.
	index = array.Insert(3, 4);
	cout << array[index] << endl;
	cout << "=========================" << endl;
	//22.  삽입정렬을 한다.
	array.InsertionSort(CompareIntergers);
	i = 0;
	while (i < array.GetLength()) {
		cout << array[i] << endl;
		i++;
	}

	//23. one 배열의 첫번째에 3을 저장한다.
	index = one.Store(0, 3);
	cout << one[index] << endl;

	//24. other 배열의 첫번째에 3을 저장한다.
	index = other.Store(0, 3);
	cout << other[index] << endl;

	//25. other 배열의 두번째에 4를 저장한다.
	index = other.Store(1, 4);
	cout << other[index] << endl;
	cout << "=========================" << endl;

	//26. one과 other를 병합한다.
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