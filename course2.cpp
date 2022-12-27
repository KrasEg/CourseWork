#include "course.h"
#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
using namespace chrono;
void course2()
{
	setlocale(0, "");
	const int N = 100;
	int input;
	int arr[N];
	int sortarr[N];
	cout << "1. ������������� ����� ������\n";
	cout << "2. ������������� ������\n";
	cout << "3. ����� ������������ � ����������� �������� �������\n";
	cout << "4. ����� ������� �������� ������������� � ������������ ��������\n";
	cout << "5. ����� ���������� ��������� ������� ����� X\n";
	cout << "6. ����� ���������� ��������� ������� ����� X\n";
	cout << "7. �������� ������� �������� �������\n";
	cout << "8. ����� �� �������\n";
Menu: {
	cout << "������� ����� ��������, ������� ������ ���������: ";
	cin >> input;
	cout << "\n";
	}
switch (input) {
case 1: {
	cout << "����� ������:\n";
	for (int i = 0; i < 100; ++i) {
		arr[i] = -99 + rand() % 199;
		sortarr[i] = arr[i];
		cout << arr[i] << ' ';
	}
	cout << "\n";
	goto Menu;
}
case 2: {
	auto start = steady_clock::now();
	for (int step = 1; step < N; step++) {
		int key = sortarr[step];
		int j = step - 1;
		while (key < sortarr[j] && j >= 0) {
			sortarr[j + 1] = sortarr[j];
			--j;
		}
		sortarr[j + 1] = key;
	}
	auto end = steady_clock::now();
	duration<double> sec = end - start;
	cout << "��������������� ������:";
	for (int i = 0; i < N; i++)
		cout << sortarr[i] << " ";
	cout << '\n';
	cout << duration_cast<microseconds>(end - start).count() << " �����������\n";
	goto Menu;
}
case 3: {
	cout << "������������:" << sortarr[N - 1] << "\n�����������:" << sortarr[0];
	auto start = steady_clock::now();
	int min = 100;
	int max = -100;
	for (int i = 0; i < 100; i++) {
		if (sortarr[i] > max)
			max = sortarr[i];
		if (sortarr[i] < min)
			min = sortarr[i];
	}
	auto end = steady_clock::now();
	cout << "\n����� ������ � ���������������: " << duration_cast<microseconds>(end - start).count() << " �����������\n";
	start = steady_clock::now();
	min = 100;
	max = -100;
	for (int i = 0; i < 100; i++) {
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	end = steady_clock::now();
	cout << "����� ������ � ���������������: " << duration_cast<microseconds>(end - start).count() << " �����������\n";
	goto Menu;
}
case 4: {
	int max = sortarr[N - 1], min = sortarr[0];
	int mid = (max + min) / 2;
	int count = 0;
	cout << "������� �����, ������ ��������: ";
	for (int i = 0; i < 100; i++) {
		if (sortarr[i] == mid)
			cout << i << ' ';
	}
	auto start = steady_clock::now();
	for (int i = 0; i < 100; i++) {
		if (sortarr[i] == mid)
			count += 1;
	}
	auto end = steady_clock::now();
	cout << "\n������� " << count << " �����, ������ ��������\n";
	cout << "����� ������ � ���������������: " << duration_cast<microseconds>(end - start).count() << " �����������\n";
	start = steady_clock::now();
	for (int i = 0; i < 100; i++) {
		if (arr[i] == mid)
			count += 1;
	}
	end = steady_clock::now();
	cout << "����� ������ � ���������������: " << duration_cast<microseconds>(end - start).count() << " �����������\n";
	goto Menu;
}
case 5: {
	cout << "������� �����:";
	int num;
	int count = 0;
	cin >> num;
	int i = 0;
	while (sortarr[i] < num) {
		++count;
		++i;
	}
	cout << '\n' << count << " �����, ������� " << num << '\n';
	goto Menu;
}
case 6: {
	cout << "������� �����:";
	int num;
	int count = 0;
	cin >> num;
	int i = N - 1;
	while (sortarr[i] > num) {
		++count;
		--i;
	}
	cout << '\n' << count << " �����, ������� " << num << '\n';
	goto Menu;
}
case 7: {
	cout << "������� ������� �����: ";
	int inp1, inp2;
	cin >> inp1 >> inp2;
	auto start = steady_clock::now();
	swap(sortarr[inp1], sortarr[inp2]);
	auto end = steady_clock::now();
	cout << '\n';
	for (int i = 0; i < N; i++)
		cout << sortarr[i] << " ";
	duration<double> sec = end - start;
	cout << "\n����� ������: " << duration_cast<microseconds>(end - start).count() << " �����������\n";
	swap(sortarr[inp1], sortarr[inp2]);
	goto Menu;
}
case 8: {
	break;
}
}
}