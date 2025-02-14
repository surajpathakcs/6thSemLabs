using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using MySql.Data.MySqlClient;
using Org.BouncyCastle.Bcpg.OpenPgp;

namespace WebApplication1.Pages
{
    

    public class EditModel : PageModel
    {
        public int Id { get; set; }
            
        [BindProperty]
        public string Name { get; set; }
        
        [BindProperty]
        public string Email { get; set; }

        [BindProperty]
        public string Phone { get; set; }

        public void OnGet(int Id)
        {
            string constr = "server=localhost;user=root;password=;database=ncc";
            MySqlConnection conn = new MySqlConnection(constr);
            conn.Open();

            string sql = "SELECT * FROM person where id =" + Id;
            MySqlCommand cmd = new MySqlCommand(sql, conn);

            MySqlDataReader reader = cmd.ExecuteReader();
            while (reader.Read())
            {
                Id = reader.GetInt32(0);
                Name = reader.GetString(1);
                Email = reader.GetString(2);
                Phone = reader.GetString(3);
                ;
            }
            conn.Close();
        }

        public void OnPost(int Id)
        {
            string constr = "server=localhost;user=root;password=;database=ncc";
            MySqlConnection conn = new MySqlConnection(constr);
            conn.Open();

            string sql = $"UPDATE person SET Name='{Name}', Phone='{Phone}',Email='{Email}' where id ="+Id;
            MySqlCommand cmd = new MySqlCommand(sql, conn);

            int reader = cmd.ExecuteNonQuery();
            
            conn.Close();
        }
    }
}
