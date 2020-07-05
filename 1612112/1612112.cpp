// 1612112.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Homestay.h"

int main()
{
	int n = 0;
	ROOM* homestay = (ROOM*)malloc(n);
	ROOM* r = NULL;
	ROOM* tmpR = NULL;
	char* rID = new char[4];
	unsigned int numOfPeople;
	char c = 'n';
	bool haveBreakfast = false;
	int m = 0;
	ROOM* search = NULL;
	int k;

	int choose;
	bool flag = true;
	do {
		cout << endl << "============ MENU ============" << endl;
		cout << "1. Danh sach phong" << endl;
		cout << "2. Them 1 phong moi" << endl;
		cout << "3. Xoa 1 phong" << endl;
		cout << "4. Tim kiem phong" << endl;
		cout << "5. Xoa cac phong theo dieu kien" << endl;
		cout << "Xin moi chon: ";
		cin >> choose;
		cin.ignore();
		cout << endl;
		switch (choose)
		{
		case 1:
			cout << "DANH SACH PHONG" << endl;
			XuatHomestay(homestay, n);
			break;
		case 2:
			cout << "THEM 1 PHONG" << endl;
			r = new ROOM;
			cin >> *r;
			tmpR = TimKiemPhongTheoMa(homestay, n, r->rID);
			if (tmpR != NULL) {
				cout << "Ma phong da ton tai, vui long tao ma phong khac." << endl;
				break;
			}
			n++;
			homestay = (ROOM*)realloc(homestay, n * sizeof(ROOM));
			Them1Phong(homestay, n, r);
			break;
		case 3:
			cout << "XOA 1 PHONG" << endl;
			cout << "Nhap ma phong can xoa: ";
			cin.getline(rID, 4);
			XoaPhong(homestay, n, rID);
			break;
		case 4:
			cout << "TIM KIEM PHONG" << endl;
			cout << "Nhap so luong nguoi:";
			cin >> numOfPeople;
			cout << "Phong co bua an sang mien phi (y/n): ";
			cin >> c;
			if (c == 'y' || c == 'Y') {
				haveBreakfast = true;
			}
			search = TimKiemPhong(m, homestay, n, numOfPeople, haveBreakfast);
			cout << "Ket qua tim kiem phong:" << endl;
			XuatHomestay(search, m);
			break;
		case 5:
			cout << "XOA CAC PHONG THEO DIEU KIEN" << endl;
			cout << "Nhap muc k (cac phong co so nguoi lon hon muc k se bi xoa): ";
			cin >> k;
			XoaPhongTheoSoLuongNguoi(homestay, n, k);
			cout << "Danh sach phong sau khi xoa:" << endl;
			XuatHomestay(homestay, n);
			break;
		default:
			flag = false;
			break;
		}
	} while (flag);
}
