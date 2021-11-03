#include <iostream>
#include <string.h>
using namespace std;

struct SinhVien {
	char maSV[50];
	char tenSV[50];
	float diem;
};

struct Node {
	SinhVien data;
	Node *next;
};

typedef Node* DS;

DS Create_Node(SinhVien a) {
	DS p = new Node();
	p->data = a;
	p->next = NULL;
	return p;
}

void Add_Tail(DS &pHead, SinhVien a) {
	DS p = Create_Node(a);
	if (pHead == NULL) {
		pHead = p;
	} else {
		DS q = pHead;
		while (q->next != NULL) {
			q = q->next;
		}
		q->next = p;
	}
}

bool Kiem_Tra_Ton_Tai(DS pHead, char ma[]) {
	for (DS p = pHead; p != NULL; p = p->next) {
		if (strcmp(p->data.maSV, ma) == 0) {
			return true;
		}
	}
	
	return false;
}

SinhVien Nhap_Mot_Sinh_Vien(DS pHead) {
	SinhVien a;
	
	fflush(stdin);
	do {
		cout << "\t- Nhap ma sinh vien: ";
		gets(a.maSV);
		
		if (strcmp(a.maSV, "") == 0) {
			cout << "\n\t!!! Ban chua nhap ma cho sinh vien, vui long nhap lai !!!" << endl;
		}
		
		if (Kiem_Tra_Ton_Tai(pHead, a.maSV)) {
			cout << "\n\t!!! Da ton tai ma sinh vien nay, vui long nhap lai !!!" << endl;
		}
	} while (Kiem_Tra_Ton_Tai(pHead, a.maSV) || strcmp(a.maSV, "") == 0);
	
	do {
		cout << "\t- Nhap ten sinh vien: ";
		gets(a.tenSV);
		
		if (strcmp(a.tenSV, "") == 0) {
			cout << "\n\t!!! Ban chua nhap ten cho sinh vien, vui long nhap lai !!!" << endl;
		}
	} while (strcmp(a.tenSV, "") == 0);
	
	do {
		cout << "\t- Nhap diem sinh vien: ";
		cin >> a.diem;
		
		if (a.diem < 0 || a.diem > 10) {
			cout << "\n\t!!! Nhap khong hop le, vui long nhap lai !!!" << endl;
		}
	} while (a.diem < 0 || a.diem > 10);
	
	return a;
}

void Nhap_Nhieu_Sinh_Vien(DS &pHead) {
	int n;
	
	do {
		cout << "Nhap so luong sinh vien: ";
		cin >> n;
		
		if (n < 1) {
			cout << "\n!!! Nhap khong hop le, vui long nhap lai !!!" << endl;
		}
	} while (n < 1);
	
	for (int i = 1; i <= n; i++) {
		cout << "\nNhap sinh vien thu " << i << ":" << endl;
		SinhVien a = Nhap_Mot_Sinh_Vien(pHead);
		Add_Tail(pHead, a);
	}
}

void In_Sinh_Vien_Dang_Bang(DS pHead) {
	cout << "STT\tMaSV\tTenSV\t\tDiem\n";
	int i = 1;
	for (DS p = pHead; p != NULL; p = p->next) {
		cout << i++ << "\t" << p->data.maSV << "\t" << p->data.tenSV << "\t\t" << p->data.diem << endl;
	}
}

void Hoan_Vi(SinhVien &a, SinhVien &b) {
	SinhVien tam = a;
	a = b;
	b = tam;
}

void Sap_Xep_Sinh_Vien_Theo_Diem(DS pHead) {
	for (DS p = pHead; p->next != NULL; p = p->next) {
		for (DS q = p->next; q != NULL; q = q->next) {
			if (p->data.diem < q->data.diem) {
				Hoan_Vi(p->data, q->data);
			}
		}
	}
}

DS Tim_Kiem_Sinh_Vien(DS pHead, char ma[]) {
	for (DS p = pHead; p != NULL; p = p->next) {
		if (strcmp(p->data.maSV, ma) == 0) {
			return p;
		}
	}
	
	return NULL;
}

void Tim_Kiem_Sinh_Vien_Theo_Ma(DS pHead) {
	char ma[50];
	
	cout << "\nNhap ma sinh vien can tim kiem: ";
	fflush(stdin);
	gets(ma);
	
	DS p = Tim_Kiem_Sinh_Vien(pHead, ma);
	
	if (p != NULL) {
		cout << "\nThong tin sinh vien can tim kiem:" << endl;
		cout << "- Ma sinh vien: " << p->data.maSV << endl;
		cout << "- Ten sinh vien: " << p->data.tenSV << endl;
		cout << "- Diem: " << p->data.diem;
	} else {
		cout << "\n!!! Khong tim thay sinh vien co ma: " << ma << " !!!";
	}
}

int main() {
	DS pHead = NULL;
	
	Nhap_Nhieu_Sinh_Vien(pHead);
	
	cout << "\nDanh sach sinh vien sau khi nhap:" << endl;
	In_Sinh_Vien_Dang_Bang(pHead);
	
	Sap_Xep_Sinh_Vien_Theo_Diem(pHead);
	cout << "\nDanh sach sinh vien sau khi sap xep:" << endl;
	In_Sinh_Vien_Dang_Bang(pHead);
	
	Tim_Kiem_Sinh_Vien_Theo_Ma(pHead);
}