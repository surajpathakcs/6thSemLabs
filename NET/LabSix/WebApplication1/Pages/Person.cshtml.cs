using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using MySql.Data.MySqlClient;


namespace WebApplication1.Pages
{
    public class PersonModel : PageModel
    {
        [BindProperty]
        public string Name { get; set; }
        [BindProperty]
        public string Phone { get; set; }
        [BindProperty]
        public string Email { get; set; }

        public string message = "";

        public void OnPost()
        {
            string constr = "server=localhost;user=root;password=;database=ncc";
            MySqlConnection conn = new MySqlConnection(constr);
            conn.Open();

            string sql = $"insert into person (name , phone ,email ) values ('{Name}' , {Phone} , '{Email}')";
            MySqlCommand cmd = new MySqlCommand(sql, conn);

            int r = cmd.ExecuteNonQuery();
            if (r > 0)
            {
                message = "Saved Successfully";
            }
            else
            {
                message = "Saving Failed";
            }
            conn.Close();
        }
        public void OnGet()
        {
            
        }
    }
}
