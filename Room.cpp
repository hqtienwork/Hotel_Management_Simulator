#include <iostream>
#include <string>
#include <iomanip>
#pragma once

using namespace std;

const int monthDays[12] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

class ROOM{
	protected:
		string roomID;
		int roomKind;
		string roomStatus;
        string ownerCode;
        string ownerName;
        string ownerPhoneNum;
		int d1, m1, y1, d2, m2, y2;
		long int dayCount;
		long int checkoutTotal;
	public:
		void addRoom(){
			cout<<"Nhap ma phong: "; fflush(stdin); getline(cin, roomID);
			cout<<"Nhap loai phong (Chon 1-VIP / 2-Thuong): "; cin>>roomKind;
			roomStatus="OK";
		}
		void addDate(){
            cout<<"Nhap ngay dat phong (lan luot ngay, thang, nam): "; cin>>d1>>m1>>y1;
			cout<<"Nhap ngay tra phong (lan luot ngay, thang, nam): "; cin>>d2>>m2>>y2;
		}
		void showRoom(){
		    cout<<left<<setw(25)<<roomID<<left<<setw(25)<<roomKind<<left<<setw(25)<<roomStatus<<left<<setw(25)<<ownerCode<<left<<setw(25)<<ownerName<<left<<setw(25)<<ownerPhoneNum;
			cout<<d1<<"/"<<m1<<"/"<<left<<setw(21)<<y1<<d2<<"/"<<m2<<"/"<<y2<<endl;
		}
		void checkout(){
			long int dayCount1, dayCount2;
			int leapDays; 
			leapDays = y1;
            if (m1<=2)
            	leapDays--;
            dayCount1 = ((leapDays/4)-(leapDays/100)+(leapDays/400)) + (y1*365) + monthDays[m1] + d1;
			leapDays = y2;
			if (m2<=2)
            	leapDays--;
            dayCount2 = ((leapDays/4)-(leapDays/100)+(leapDays/400)) + (y2*365) + monthDays[m2] + d2;
			dayCount = dayCount2 - dayCount1;
			if (roomKind==1){
				checkoutTotal = 5000000*(dayCount);
			}
			else checkoutTotal = 3000000*(dayCount);
			cout<<"So tien khach hang phai thanh toan la: "<<checkoutTotal<<endl;
		}
	friend class HOTEL;
};