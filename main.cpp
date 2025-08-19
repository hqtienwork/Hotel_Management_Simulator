#include <iostream>
#include "Hotel.cpp"
#include <conio.h>

using namespace std;

void pressAnyKey(){
	cout<<"Bam phim bat ky de tiep tuc...";
	getch();
	system("cls");
}
int main(){
	int key=1;
	HOTEL a;
	while (key!=0){
		cout<<"            CHUONG TRINH HE THONG QUAN LY KHACH SAN        "<<endl;
		cout<<"==========================================================="<<endl;
		cout<<"=                HE THONG QUAN LY KHACH HANG              ="<<endl;
		cout<<"==========================================================="<<endl;
		cout<<"=    1. Them khach hang                                   ="<<endl;
		cout<<"=    2. Hien thi danh sach khach hang da dat phong        ="<<endl;
		cout<<"=    3. Tim kiem thong tin khach hang da dat phong        ="<<endl;
		cout<<"=    4. Sua thong tin khach hang                          ="<<endl;
		cout<<"=    5. Xoa thong tin khach hang                          ="<<endl;
		cout<<"==========================================================="<<endl;
		cout<<"=                  HE THONG QUAN LY PHONG                 ="<<endl;
		cout<<"==========================================================="<<endl;
		cout<<"=    6. Them phong                                        ="<<endl;
		cout<<"=    7. Hien thi danh sach tat ca phong                   ="<<endl;
        cout<<"=    8. Them khach hang vao phong                         ="<<endl;
		cout<<"=    9. Tim kiem thong tin phong                          ="<<endl;
		cout<<"=    10. Thanh toan                                       ="<<endl; 
        cout<<"==========================================================="<<endl;
		cout<<"=    0. Thoat chuong trinh                                ="<<endl;
		cout<<"==========================================================="<<endl;
		cout<<"Nhap tuy chon (0-10): ";
		cin>>key;
		switch(key){
			case 1:
                system("cls");
				cout<<"Ban da chon lua chon 1: Them khach hang"<<endl;
				a.addCustomer();
                cout<<"==========================================================="<<endl;
				cout<<"Nhap khach hang thanh cong!"<<endl;
                cout<<"==========================================================="<<endl;
				pressAnyKey();
				break;
			case 2:
                system("cls");
				cout<<"Ban da chon lua chon 2: Hien thi danh sach khach hang da dat phong"<<endl;;
				a.showCustomer();
                cout<<"==========================================================="<<endl;
				pressAnyKey();
				break;
			case 3:
                system("cls");	
				cout<<"Ban da chon lua chon 3: Tim kiem thong tin khach hang da dat phong"<<endl;
				a.searchCustomer();
                cout<<"==========================================================="<<endl;
				pressAnyKey();
				break;
			case 4:
                system("cls");
				cout<<"Ban da chon lua chon 4: Sua thong tin khach hang"<<endl;
				a.editCustomer();
                cout<<"==========================================================="<<endl;
				cout<<"Thong tin khach hang da duoc cap nhat thanh cong!"<<endl;
                cout<<"==========================================================="<<endl;
				pressAnyKey();
				break;
			case 5:
                system("cls");	
				cout<<"Ban da chon lua chon 5: Xoa thong tin khach hang"<<endl;
				a.deleteCustomer();
                cout<<"==========================================================="<<endl;
				cout<<"Xoa thong tin khach hang thanh cong!"<<endl;
                cout<<"==========================================================="<<endl;
				pressAnyKey();
				break;	
			case 6:
                system("cls");
				cout<<"Ban da chon lua chon 6: Them phong"<<endl;
				a.addRoom();
                cout<<"==========================================================="<<endl;
				cout<<"Them phong thanh cong!"<<endl;
                cout<<"==========================================================="<<endl;
				pressAnyKey();
				break;
			case 7:
                system("cls");
				cout<<"Ban da chon lua chon 7: Hien thi danh sach phong"<<endl;
				a.showRoom();
                cout<<"==========================================================="<<endl;
				pressAnyKey();
				break;
            case 8:
                system("cls");
                cout<<"Ban da chon lua chon 8: Them khach hang vao phong"<<endl;
                a.addCustomerRoom();
                cout<<"==========================================================="<<endl;
				pressAnyKey();
				break;
            case 9:
				system("cls");
                cout<<"Ban da chon lua chon 9: Tim kiem thong tin phong"<<endl;
                a.searchRoom();
				cout<<"==========================================================="<<endl;
                pressAnyKey();
                break;
			case 10:
				system("cls");	
				cout<<"Ban da chon lua chon 10: Thanh toan"<<endl;
				a.checkout();
                cout<<"==========================================================="<<endl;
				pressAnyKey();
				break;	
            case 0:
				cout<<"Thoat chuong trinh!"<<endl;;
                cout<<"==========================================================="<<endl;
                pressAnyKey();
				break;
			default:
				cout<<"Khong co lua chon tren, moi ban nhap lai!"<<endl;
                cout<<"==========================================================="<<endl;
				pressAnyKey();
				break;
		}
	}
	return 0;
}