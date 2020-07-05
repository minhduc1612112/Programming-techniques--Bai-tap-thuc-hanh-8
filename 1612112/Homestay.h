#pragma once
#include "Room.h"

void Them1Phong(ROOM* homestay, int n, ROOM* r);
void XuatHomestay(ROOM* homestay, int n);
ROOM* TimKiemPhongTheoMa(ROOM* homestay, int n, char* rID);
void XoaPhong(ROOM* homestay, int& n, char* rID);
ROOM* TimKiemPhong(int& m, ROOM* homestay, int n, unsigned int numOfPeople, bool haveBreakfast);
void XoaPhongTheoSoLuongNguoi(ROOM* homestay, int& n, int k);