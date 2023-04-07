using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Web.Http;

namespace WebAPI.Controllers
{
    public class CustomersController : ApiController
    {
        //httpGet: dùng để lấy thông tin khách hàng
        //1. Dịch vụ lấy thông tin của toàn bộ khách hàng
        [HttpGet]
        public List<tKhachHang> GetCustomerLists()
        {
            DBCustomersDataContext dbCustomer = new DBCustomersDataContext();
            return dbCustomer.tKhachHangs.ToList();
        }
        //2. Dịch vụ lấy thông tin một khách hàng với mã nào đó

         [HttpGet]
        public tKhachHang GetCustomer(string id)
        {
            DBCustomersDataContext dbCustomer = new DBCustomersDataContext();
            return dbCustomer.tKhachHangs.FirstOrDefault(x =>
           x.MaKH == id);
        }
        //3. httpPost, dịch vụ thêm mới một khách hàng
        [HttpPost]
        public bool InsertNewCustomer(string id, string name,
       string adress, string phoneNumber)
        {
            try
            {
                DBCustomersDataContext dbCustomer = new DBCustomersDataContext();
                tKhachHang customer = new tKhachHang();
                customer.MaKH = id;
                customer.TenKH = name;
                customer.DiaChi = adress;
                customer.DienThoai = phoneNumber;

                dbCustomer.tKhachHangs.InsertOnSubmit(customer);
                dbCustomer.SubmitChanges();
                return true;
            }
            catch
            {
                return false;
            }
        }
        [HttpPut]
        public bool UpdateCustomer(string id, string name,
string adress, string phoneNumber)
        {
            try
            {
                DBCustomersDataContext dbCustomer = new DBCustomersDataContext();
                //Lấy mã khách đã có
                tKhachHang customer =
               dbCustomer.tKhachHangs.FirstOrDefault(x => x.MaKH == id);
                if (customer == null) return false;
                customer.MaKH = id;
                customer.TenKH = name;
                customer.DiaChi = adress;
                customer.DienThoai = phoneNumber;
                dbCustomer.SubmitChanges();//Xác nhận chỉnh sửa
            return true;
            }
            catch
            {
                return false;
            }
        }
        //5.httpDelete để xóa một Khách hàng
        [HttpDelete]
        public bool DeleteCustomer(string id)
        {
            try
            {
                DBCustomersDataContext dbCustomer = new DBCustomersDataContext();
                //Lấy mã khách đã có
                tKhachHang customer =
               dbCustomer.tKhachHangs.FirstOrDefault(x => x.MaKH == id);
                if (customer == null) return false;

                dbCustomer.tKhachHangs.DeleteOnSubmit(customer);
                dbCustomer.SubmitChanges();
                return true;
            }
            catch
            {
                return false;
            }
        }
    }
}
