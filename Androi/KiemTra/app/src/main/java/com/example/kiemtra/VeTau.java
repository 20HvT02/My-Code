package com.example.kiemtra;

public class VeTau {
    public Integer MaVe;
    public String NoiDen;
    public String NoiDi;
    public String KieuVe;
    public Integer DonGia;

    public VeTau(Integer maVe, String noiDen, String noiDi, String kieuVe, Integer donGia) {
        MaVe = maVe;
        NoiDen = noiDen;
        NoiDi = noiDi;
        KieuVe = kieuVe;
        DonGia = donGia;
    }

    public Integer getMaVe() {
        return MaVe;
    }

    public void setMaVe(Integer maVe) {
        MaVe = maVe;
    }

    public String getNoiDen() {
        return NoiDen;
    }

    public void setNoiDen(String noiDen) {
        NoiDen = noiDen;
    }

    public String getNoiDi() {
        return NoiDi;
    }

    public void setNoiDi(String noiDi) {
        NoiDi = noiDi;
    }

    public String getKieuVe() {
        return KieuVe;
    }

    public void setKieuVe(String kieuVe) {
        KieuVe = kieuVe;
    }

    public Integer getDonGia() {
        return DonGia;
    }

    public void setDonGia(Integer donGia) {
        DonGia = donGia;
    }
}
