#include <iostream>
#include <string>
#include <iomanip>
#pragma once

using namespace std;

class CUSTOMER{
	protected:
		string customerCode;
		string customerName;
		string address;
		string identityCard;
		string phoneNum;
	public:
		virtual void addCustomer(){
			cout<<"Nhap ma khach hang: "; fflush(stdin); getline(cin, customerCode);
			cout<<"Nhap ten khach hang: "; fflush(stdin); getline(cin, customerName);
			cout<<"Nhap dia chi: "; fflush(stdin); getline(cin,address);
			cout<<"Nhap so CMND/CCCD: "; fflush(stdin); getline(cin,identityCard);
			cout<<"Nhap so dien thoai: "; fflush(stdin); getline(cin,phoneNum);
		}
		void showCustomer(){
			cout<<left<<setw(25)<<customerCode<<left<<setw(25)<<customerName<<left<<setw(25)<<address<<left<<setw(25)<<identityCard<<left<<setw(25)<<phoneNum;
		}
	friend class HOTEL;
};