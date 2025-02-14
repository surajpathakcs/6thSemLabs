using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using MySql.Data.MySqlClient;

namespace WebApplication1.Pages
{
    public class DeleteModel : PageModel
    {
        public void OnGet(int Id)
        { 
            string constr = "server=localhost;user=root;password=;database=ncc";
            MySqlConnection conn = new MySqlConnection(constr);
            conn.Open();

            string sql = "Delete from Person where Id = @Id";
            MySqlCommand cmd = new MySqlCommand(sql, conn);

            //cmd.Parameters.AddWithValue("@Id", Id);
            cmd.ExecuteNonQuery();
            conn.Close();

            Response.Redirect("/Display");

        }
    }
}
