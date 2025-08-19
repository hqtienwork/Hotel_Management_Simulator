#include <iostream>
#include "Customer.cpp"
#include "Room.cpp"

using namespace std;

CUSTOMER a[100];
ROOM b[100];

class HOTEL{
    protected:
        int countCustomer=0;
        int countRoom=0;
    public:
        void addCustomer(){
		    a[countCustomer].addCustomer();
			countCustomer++;
		}
        void showCustomer(){
			cout<<left<<setw(25)<<"Ma KH"<<left<<setw(25)<<"Ho va ten"<<left<<setw(25)<<"Dia chi"<<left<<setw(25)<<"So CMND/CCCD"<<left<<setw(25)<<"So dien thoai"<<"Ma phong"<<endl;
			for (int i=0; i<countCustomer; i++){
				a[i].showCustomer();
				for (int j=0; j<countRoom; j++){
					if (a[i].customerCode==b[j].ownerCode)
						cout<<left<<setw(25)<<b[j].roomID;
				}
				cout<<endl;
			}
		}
		void searchCustomer(){
			string searchCustomerCode;
			int found=0;
			cout<<"Nhap ma khach hang can tim kiem: "; fflush(stdin); getline(cin, searchCustomerCode);
			cout<<endl;
			cout<<"Thong tin khach hang:"<<endl;
			cout<<endl;
			cout<<left<<setw(25)<<"Ma KH"<<left<<setw(25)<<"Ho va ten"<<left<<setw(25)<<"Dia chi"<<left<<setw(25)<<"So CMND/CCCD"<<left<<setw(25)<<"So dien thoai"<<endl;
			for (int i=0; i<countCustomer; i++)
				if (a[i].customerCode == searchCustomerCode){
					found=1;
					a[i].showCustomer();
                }
			if (found==0){
				cout<<"==========================================================="<<endl;
				cout<<"Ma khach hang khong ton tai, ban hay kiem tra lai!"<<endl;
			}
		}
		void deleteCustomer(){
			int found=0;
			string deleteCustomerCode;
			cout<<"Nhap ma khach hang can xoa: "; fflush(stdin); getline(cin,deleteCustomerCode);
			for (int i=0; i<countCustomer; i++)
				if (a[i].customerCode == deleteCustomerCode){
					found=1;
					for (int j=i; j<countCustomer; j++){
               			a[j] = a[j+1];
               		}
            	}
            if (found==0){
				cout<<"Ma khach hang khong ton tai, ban hay kiem tra lai!"<<endl;
			}
			else {
				countCustomer--;
			}
			for (int j=0; j<countRoom; j++){
				if (b[j].ownerCode == deleteCustomerCode){
					b[j].ownerCode = "";
                    b[j].ownerName = "";
                    b[j].ownerPhoneNum = "";
					b[j].roomStatus = "OK";
					b[j].d1=0;
					b[j].m1=0;
					b[j].y1=0;
					b[j].d2=0;
					b[j].m2=0;
					b[j].y2=0;
				}
			}
		}
		void editCustomer(){
			int found=0;
			string editCustomerCode;
			cout<<"Nhap ma khach hang can chinh sua thong tin: "; fflush(stdin); getline(cin, editCustomerCode);
			for (int i=0; i<countCustomer; i++)
				if (a[i].customerCode == editCustomerCode){
					found=1;
					a[i].addCustomer();
				}
			if (found==0){
				cout<<"Ma khach hang khong ton tai, ban hay kiem tra lai!"<<endl;
			}
		}
		void addRoom(){
			b[countRoom].addRoom();
			countRoom++;	
		}
        void addCustomerRoom(){
            string customerCodeAdd;
            string searchIDRoom;
            int found=-1;
            cout<<"Nhap ma khach hang ban muon them vao phong: "; fflush(stdin); getline(cin, customerCodeAdd);
            for (int i=0; i<countCustomer; i++){
				if (a[i].customerCode == customerCodeAdd){
                	cout<<"Nhap ma phong ban muon cho khach hang thue: "; fflush(stdin); getline(cin, searchIDRoom);
                    for (int j=0; j<countRoom; j++){
                        if (b[j].roomStatus=="OK"){
				             if (b[j].roomID == searchIDRoom){
								b[j].roomStatus="Da dat";
                                found=1;
                                b[j].ownerCode = a[i].customerCode;
                                b[j].ownerName = a[i].customerName;
                                b[j].ownerPhoneNum = a[i].phoneNum;
								b[j].addDate();
								break;
                            }
                        }
                        else found=0;
                    }
                }
            }
			if (found==0){
				cout<<"Phong da co nguoi thue hoac ma phong khong dung! Vui long thu lai..."<<endl;
            }
			if (found==-1){
				cout<<"Ma khach hang khong ton tai, ban hay kiem tra lai!"<<endl;
			}
		}
		void showRoom(){
			cout<<left<<setw(25)<<"Ma phong"<<left<<setw(25)<<"Loai phong"<<left<<setw(25)<<"Tinh trang phong"<<left<<setw(25)<<"Ma khach hang"<<left<<setw(25)<<"Ten khach hang"<<left<<setw(25)<<"So dien thoai"<<left<<setw(25)<<"Ngay dat"<<left<<setw(25)<<"Ngay tra"<<endl;
			for (int j=0; j<countRoom; j++){
				b[j].showRoom();
				
			}
		}
		void searchRoom(){
			string searchRoomID;
			int found=0;
			cout<<"Nhap ma phong can tim kiem: "; fflush(stdin); getline(cin, searchRoomID);
			cout<<endl;
			cout<<"Thong tin phong:"<<endl;
			cout<<endl;
			cout<<left<<setw(25)<<"Ma phong"<<left<<setw(25)<<"Loai phong"<<left<<setw(25)<<"Tinh trang phong"<<left<<setw(25)<<"Ma khach hang"<<left<<setw(25)<<"Ten khach hang"<<left<<setw(25)<<"So dien thoai"<<left<<setw(25)<<"Ngay dat"<<left<<setw(25)<<"Ngay tra"<<endl;
			for (int j=0; j<countRoom; j++)
				if (b[j].roomID == searchRoomID){
					found=1;
					b[j].showRoom();
                }
			if (found==0){
				cout<<"==========================================================="<<endl;
				cout<<"Ma phong khong ton tai, ban hay kiem tra lai!"<<endl;
			}
		}
		void checkout(){
			int found = 0;
			int checkoutTotal;
			string checkoutRoomID;
			cout<<"Nhap ma phong can thanh toan: "; fflush(stdin); getline(cin, checkoutRoomID);
			cout<<endl;
			for (int j=0; j<countRoom; j++)
				if (b[j].roomID == checkoutRoomID){
					found = 1;
					b[j].checkout();
				}
			if (found==0){
				cout<<"Ma phong khong ton tai, ban hay kiem tra lai!"<<endl;
			}
		}
};