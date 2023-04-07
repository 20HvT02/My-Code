using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net.NetworkInformation;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using HaVanThoi_201200354_CNTT5K61.system;
using Excel = Microsoft.Office.Interop.Excel;

namespace HaVanThoi_201200354_CNTT5K61
{
    public partial class Form1 : Form
    {
        DBconfig dtBase = new DBconfig();
        private DataTable dtCT;
        public Form1()
        {
            InitializeComponent();
        }
        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)
        {


        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string sql;
            sql = $"SELECT *" + $"FROM CongTy";
            loadSQL(sql);
        }

        private void loadSQL(string i)
        {
            dtCT = dtBase.DocBang(i);
            dataGridView1.DataSource = dtCT;

            dataGridView1.Columns[0].HeaderText = "Mã Công Ty";
            dataGridView1.Columns[1].HeaderText = "Tên Công Ty";
            dataGridView1.Columns[2].HeaderText = "Địa Chỉ";
            dataGridView1.Columns[3].HeaderText = "Số Xe";
            dataGridView1.Columns[4].HeaderText = "Ngày Thành Lập";
            dataGridView1.Columns[0].DataPropertyName = "MaCty";
            dataGridView1.Columns[1].DataPropertyName = "TenCty";
            dataGridView1.Columns[2].DataPropertyName = "DiaChi";
            dataGridView1.Columns[3].DataPropertyName = "SoXe";
            dataGridView1.Columns[4].DataPropertyName = "NgayTL";
        }

        private void btnXuat_Click(object sender, EventArgs e)
        {
            string sql;
            sql = $"SELECT * FROM CongTy WHERE YEAR(Ngay) > 2005";
            loadSQL(sql);
            if (dtCT.Rows.Count > 0 && dataGridView1.Rows.Count > 0)
            {
                Excel.Application exApp = new Excel.Application();
                Excel.Workbook exBook = exApp.Workbooks.Add(Excel.XlWBATemplate.xlWBATWorksheet);
                Excel.Worksheet exSheet = (Excel.Worksheet)exBook.Worksheets[1];

                exSheet.get_Range("A3:G3").Font.Bold = true;
                exSheet.get_Range("A3:G3").HorizontalAlignment = Microsoft.Office.Interop.Excel.XlHAlign.xlHAlignCenter;
                exSheet.get_Range("A3").Value = "STT";
                exSheet.get_Range("B3").Value = "Mã Công Ty";
                exSheet.get_Range("C3").Value = "Tên Công Ty";
                exSheet.get_Range("C3").ColumnWidth = 20;
                exSheet.get_Range("D3").Value = "Địa Chỉ";
                exSheet.get_Range("E3").Value = "Số Xe";
                exSheet.get_Range("F3").Value = "Ngày Thành Lập";
                for (int i = 0; i < dtCT.Rows.Count; i++)
                {
                    exSheet.get_Range("A" + (i + 4).ToString() + ":G" + (i + 4).ToString()).Font.Bold = false;
                    exSheet.get_Range("A" + (i + 4).ToString()).Value = (i + 1).ToString();
                    exSheet.get_Range("B" + (i + 4).ToString()).Value = dtCT.Rows[i]["Mact"].ToString();
                    exSheet.get_Range("C" + (i + 4).ToString()).Value = dtCT.Rows[i]["Tenct"].ToString();
                    exSheet.get_Range("D" + (i + 4).ToString()).Value = dtCT.Rows[i]["Diachi"].ToString();
                    exSheet.get_Range("E" + (i + 4).ToString()).Value = dtCT.Rows[i]["Soxe"].ToString();
                    exSheet.get_Range("F" + (i + 4).ToString()).Value = dtCT.Rows[i]["Ngay"].ToString();
                }
                exSheet.Name = "Congty";
                exBook.Activate();
                saveFileDialog1.Filter = "Excel Document(*.xls)|*.xls  |Word Document(*.doc) |*.doc|All files(*.*)|*.*";
                saveFileDialog1.FilterIndex = 1;
                saveFileDialog1.AddExtension = true;
                saveFileDialog1.DefaultExt = ".xls";
                if (saveFileDialog1.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                    exBook.SaveAs(saveFileDialog1.FileName.ToString());
                exApp.Quit();
            }
            else
                MessageBox.Show("Không có danh sách hàng để in");

        }

        private void btnThoat_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void cleanInput()
        {
            txtMa.Text = "";
            txtTen.Text = "";
            txtDiaChi.Text = "";
            txtSoXe.Text = "";
        }
        private void btnLamMoi_Click(object sender, EventArgs e)
        {
            cleanInput();
            Form1_Load(sender, e);
        }

        private bool isCheck()
        {
            if (txtMa.Text.Trim() == "")
            {
                MessageBox.Show("Vui Lòng Nhập Mã Công Ty", "Thông Báo", MessageBoxButtons.OK);
                txtMa.Focus();
                return false;
            }
            if (txtTen.Text.Trim() == "")
            {
                MessageBox.Show("Vui Lòng Nhập Tên Công Ty", "Thông Báo", MessageBoxButtons.OK);
                txtTen.Focus();
                return false;
            }
            if (txtSoXe.Text.Trim() == "")
            {
                MessageBox.Show("Vui Lòng Nhập Số Xe", "Thông Báo", MessageBoxButtons.OK);
                txtSoXe.Focus(); return false;
            }
            if (txtDiaChi.Text.Trim() == "")
            {
                MessageBox.Show("Vui Lòng Nhập Địa Chỉ", "Thông Báo", MessageBoxButtons.OK);
                txtDiaChi.Focus(); return false;
            }

            return true;
        }
        private void btnTim_Click(object sender, EventArgs e)
        {

            string sql;
            sql = "SELECT * FROM Congty WHERE Soxe > 50";
            loadSQL(sql);

            if (dataGridView1.Rows.Count > 2)
            {
                MessageBox.Show("Không tìm thấy dữ liệu vừa nhâp", "Thông Báo", MessageBoxButtons.OK);
            }

        }
        bool isCheckSQL(string a)
        {
            string sql;
            sql = $"SELECT * FROM CongTy WHERE MaCty = N'{a}'";
            try
            {
                dtBase.DocBang(sql);
            }
            catch
            {
                MessageBox.Show("Không tìm thấy dữ liệu vừa nhâp", "Thông Báo", MessageBoxButtons.OK);
                return false;
            }
            return true;
        }
        private void btnSua_Click(object sender, EventArgs e)
        {
            if (isCheck())
            {
                if (isCheckSQL(txtMa.Text.Trim()))
                {
                    int a = int.Parse(txtSoXe.Text);
                    string theDate = dtbNgay.Value.ToString("yyyy-MM-dd");
                    string i = $"UPDATE Congty SET Tenct = N'{txtMa.Text.Trim()}', Diachi = N'{txtDiaChi.Text.Trim()}',Soxe = {a}, Ngay = CAST(N'{theDate}' AS date)  WHERE Mact = N'{txtMa.Text.Trim()}'";
                    if (MessageBox.Show("Bạn có muốn sửa không?", "Thông báo", MessageBoxButtons.YesNo, MessageBoxIcon.Information) == DialogResult.Yes)
                    {
                        dtBase.CapNhatDuLieu(i);
                        Form1_Load(sender, e);
                        cleanInput();
                    }
                }
            }
        }

        private void btnXoa_Click(object sender, EventArgs e)
        {
            string sql;
            sql = $"DELETE FROM Congty WHERE Mact = N'{txtMa.Text.Trim()}'";
            if (MessageBox.Show("Bạn có muốn xóa không?", "Thông báo", MessageBoxButtons.YesNo, MessageBoxIcon.Information) == DialogResult.Yes)
            {
                dtBase.CapNhatDuLieu(sql);
                Form1_Load(sender, e);
                cleanInput();
            }
        }

        private void btnThem_Click(object sender, EventArgs e)
        {
            if (isCheck())
            {
                int a = int.Parse(txtSoXe.Text);
                string theDate = dtbNgay.Value.ToString("yyyy-MM-dd");
                string sql = $"INSERT INTO Congty " +
                    $"VALUES(N'{txtMa.Text}',N'{txtTen.Text}',N'{txtDiaChi.Text}',{a},CAST(N'{theDate}' AS date))";
                if (MessageBox.Show("Bạn có muốn thêm vào không?", "Thông báo", MessageBoxButtons.YesNo, MessageBoxIcon.Information) == DialogResult.Yes)
                {
                    dtBase.CapNhatDuLieu(sql);
                    Form1_Load(sender, e);
                    cleanInput();
                }
            }

        }
        private void txtSoXe_KeyPress(object sender, KeyPressEventArgs e)
        {
            checkNum(e);
        }
        private void checkNum(KeyPressEventArgs e)
        {
            if (!char.IsControl(e.KeyChar) && !char.IsDigit(e.KeyChar))
                e.Handled = true;
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            MessageBox.Show("Running", "Thông Báo");
        }
    }
}
