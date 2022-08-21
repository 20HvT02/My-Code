#include<bits/stdc++.h>
using namespace std;

class KhachHang {
    private:
        string tenKH;
        int maKH;
        string gioiTinh;
        string ngayGui;
        int kiHan;
        double tienGui;
    public:
        KhachHang(string tenKH; int maKH; bool gioiTinh; string ngayGui; int kiHan; double tienGui) {
        this -> tenKH = tenKH;
        this -> maKH = maKH;
        this -> gioiTinh = gioiTinh;
        this -> ngayGui = ngayGui;
        this -> kiHan = kiHan;
        this -> tienGui = tienGui;
        }
        getTenHK() {
            return tenKH;
        }
        getMaKH() {
            return maKH;
        }
        getGioiTinh() {
            reuturn gioiTinh;
        }
        getNgayGui() {
            return ngayGui;
        }
        getKiHan() {
            return kiHan;
        }
        getTienGui() {
            return tienGui;
        }
        void Nhap() {
            cout <<"Nhap ten khach hang: ";
            getline(tenKH, cin);
            cout <<"\nNhap gioi tinh: ";
            getline(gioiTinh, cin);
            cout <<"\nNhap ngay gui: ";
            getline(ngayGui, cin);
            cout 
        }
};

void Nhap(KhachHang &a; int id)

int main() {

    return 0;
}