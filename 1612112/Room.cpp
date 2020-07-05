#include "Room.h"

istream& operator>>(istream& in, ROOM& r) {
	cout << "Nhap ma phong: ";
	in.getline(r.rID, 4);
	cout << "Nhap dien tich phong co the su dung: ";
	in >> r.usableArea;
	cout << "Nhap so luong nguoi co the o: ";
	in >> r.numOfPeople;

	char furnished = 'n', haveBreakfast = 'n';

	cout << "Phong co san noi that co the su dung (y/n): ";
	cin >> furnished;
	if (furnished == 'Y' || furnished == 'y') {
		r.furnished = true;
	}
	else
	{
		r.furnished = false;
	}

	cout << "Phong co bua sang mien phi (y/n): ";
	cin >> haveBreakfast;
	if (haveBreakfast == 'Y' || haveBreakfast == 'y') {
		r.haveBreakfast = true;
	}
	else
	{
		r.haveBreakfast = false;
	}

	cout << endl;

	return in;
}

ostream& operator<<(ostream& out, ROOM& r) {
	out << "Ma phong: " << r.rID << endl;
	out << "Dien tich: " << r.usableArea << endl;
	out << "So luong nguoi co the o: " << r.numOfPeople << endl;
	if (r.furnished) {
		cout << "Phong co san noi that" << endl;
	}
	else
	{
		cout << "Phong khong co san noi that" << endl;
	}
	if (r.haveBreakfast) {
		cout << "Phong co san bua an sang mien phi" << endl;
	}
	else
	{
		cout << "Phong khong co san bua an sang mien phi" << endl;
	}
	return out;
}