using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Tuan1DeMo;
namespace Tuan1DemoWinAp
{
    public partial class Form1 : Form
    {
        List<KhachHang> lst = new List<KhachHang>();
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //thêm thông tin vào ds khách hàng
            string ma, ten, dc;
            DateTime ng;
            long tg;
            int tgg;
            bool loaig=false ;
            ma = MaKhachtxt.Text ;
            ten = TenKhachtxt.Text;
            dc = DiaChitxt.Text;
            tg =long.Parse ( TienGuitxt.Text);
            tgg =int.Parse ( ThoiHanGuicmb.Text);
            if (AnKhangrdb.Checked == true)
                loaig = true;
            if (PhatLocrdb.Checked == true)
                loaig = false ;
            ng = dateTimePicker1.Value;
            KhachHang x = new KhachHang(ma, ten, dc, tg, ng, tgg, loaig);
            lst.Add(x);
            ThemDSbtn.Items.Add(x.ToString ());

        }

        private void TaoDSKHTTbtn_Click(object sender, EventArgs e)
        {
 
            foreach (KhachHang x in lst)
                if (x.Thoigiangui > 6 && x.getTienGui() > 1000000000)
                    khttlst.Items.Add(x.ToString());
        }
    }
}
