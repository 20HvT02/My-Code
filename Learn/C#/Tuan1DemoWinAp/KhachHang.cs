using System;

namespace Tuan1DeMo
{
    class KhachHang
    {
        string maK, tenK, diaChi;
        long tiengui;
        DateTime ngaygui;
        int thoigiangui;
        bool loaigui;

        public int Thoigiangui { get => thoigiangui; set => thoigiangui = value; }

        public long getTienGui()
        {
            return tiengui;
        }

        public KhachHang()
        {
        }

        public KhachHang(string maK, string tenK, string diaChi, long tiengui, DateTime ngaygui, int thoigiangui, bool loaigui)
        {
            this.maK = maK;
            this.tenK = tenK;
            this.diaChi = diaChi;
            this.tiengui = tiengui;
            this.ngaygui = ngaygui;
            this.thoigiangui = thoigiangui;
            this.loaigui = loaigui;
        }
        public override string ToString()
        {
            string loaistring = "";
            if (loaigui == true) loaistring = "An khang";
            else loaistring = "Phat loc";
            string s=maK + " " + tenK + " " + diaChi + " "
                + " Tien gui " + tiengui + " thoi gian " + thoigiangui
                + " hinh thuc gui " + loaistring + " tien lai " + tinhlai();

            return s;
        }
        public void nhap()
        {
            Console.Write("nhap ma khach ");
            maK =Console.ReadLine();
            Console.Write("nhap ten khach ");
            tenK = Console.ReadLine();
            Console.Write("nhap dia chi khach ");
            diaChi = Console.ReadLine();
            Console.Write("nhap so tien gui ");
            tiengui  =long.Parse ( Console.ReadLine());
            Console.Write("nhap thoi gian gui 1,3,6,9,12: ");
            thoigiangui  =int.Parse(Console.ReadLine());
            int loai;
            do
            {
                Console.Write("nhap loai gui(1-Phat loc;2-An khang): ");
                loai = Convert.ToInt32(Console.ReadLine());
            } while (loai > 2 || loai < 1);
            if (loai == 1) loaigui = true;
            else loaigui = false;
        }
        public void xuat()
        {
            string loaistring="";
            if (loaigui == true) loaistring = "An khang";
            else loaistring = "Phat loc";
            Console.WriteLine(maK + " " + tenK + " " + diaChi + " "
                +" Tien gui " +tiengui+" thoi gian "+thoigiangui 
                +" hinh thuc gui "+loaistring +" tien lai "+tinhlai ());
        }
        float tinhlai()
        {
            float lai=0,tyle=0F;
            switch(thoigiangui )
            {
                case 1:
                    {
                        tyle = 0.06F;
                        break;
                    }
                case 3:
                    {
                        tyle = 0.07F;
                        break;
                    }
                case 6:
                    {
                        tyle = 0.08F;
                        break;
                    }
                case 12:
                    {
                        tyle = 0.09F;
                        break;
                    }
            }
            if (loaigui == true)
                tyle += 0.01F;
            return tyle*tiengui/12*thoigiangui ;
        }
    }
}
