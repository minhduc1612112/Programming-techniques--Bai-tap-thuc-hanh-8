#include "Homestay.h"

void Them1Phong(ROOM* homestay, int n, ROOM* r) {
	*(homestay + n - 1) = *r;
	cout << "Them phong thanh cong" << endl;
}

void XuatHomestay(ROOM* homestay, int n) {
	for (int i = 0; i < n; i++) {
		cout << endl << "Chi tiet phong thu " << i + 1 << endl;
		cout << *(homestay + i);
	}
}

ROOM* TimKiemPhongTheoMa(ROOM* homestay, int n, char* rID) {
	for (int i = 0; i < n; i++) {
		if (strcmp((homestay+i)->rID, rID) == 0) {
			return homestay + i;
		}
	}
	return NULL;
}

void XoaPhong(ROOM* homestay, int& n, char* rID) {
	int index = -1;
	for (int i = 0; i < n; i++) {
		if (strcmp((homestay + i)->rID, rID) == 0) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		cout << "Ma phong khong ton tai" << endl;
		return;
	}
	for (int i = index; i < n - 1; i++) {
		*(homestay + i) = *(homestay + i + 1);
	}
	n--;
	ROOM* tmp = new ROOM[n];
	for (int i = 0; i < n; i++) {
		*(tmp + i) = *(homestay + i);
	}
	homestay = tmp;
	delete[] tmp;
	cout << "Xoa phong thanh cong" << endl;
	return;
}

ROOM* TimKiemPhong(int& m, ROOM* homestay, int n, unsigned int numOfPeople, bool haveBreakfast) {
	int length = 0;
	for (int i = 0; i < n; i++) {
		if ((homestay + i)->numOfPeople == numOfPeople && (homestay + i)->haveBreakfast == haveBreakfast) {
			length++;
		}
	}
	if (length == 0) {
		return NULL;
	}
	m = length;
	int index = 0;
	ROOM* result = new ROOM[m];
	for (int i = 0; i < n; i++) {
		if ((homestay + i)->numOfPeople == numOfPeople && (homestay + i)->haveBreakfast == haveBreakfast) {
			*(result + index) = *(homestay + i);
			index++;
		}
	}
	return result;
}

void XoaPhongTheoSoLuongNguoi(ROOM* homestay, int& n, int k) {
	int length = 0;
	for (int i = 0; i < n; i++) {
		if ((homestay + i)->numOfPeople > k) {
			length++;
		}
	}
	if (length == 0) {
		return;
	}
	ROOM* tmp = new ROOM[n - length];
	int index = 0;
	for (int i = 0; i < n; i++) {
		if ((homestay + i)->numOfPeople <= k) {
			*(tmp + index) = *(homestay + i);
		}
	}
	homestay = tmp;
	n = n - length;

	delete[] tmp;
}