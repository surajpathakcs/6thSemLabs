using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using MySql.Data.MySqlClient;
using System.Collections.Generic;

namespace WebApplication1.Pages
{
    public class Person { 
        public int Id { get; set; }
        public string Name { get; set; }
        public string Email { get; set; }
        public string Contact { get; set; }
    }
    public class DisplayModel : PageModel
    {
        public List<Person> personList { get; set; } = new List<Person>();
        public void OnGet()
        {
            string constr = "server=localhost;user=root;password=;database=ncc";
            MySqlConnection conn = new MySqlConnection(constr);
            conn.Open();

            string sql = "SELECT * FROM person";
            MySqlCommand cmd = new MySqlCommand(sql, conn);

            MySqlDataReader reader = cmd.ExecuteReader();
            while (reader.Read())
            {
                Person person = new Person();
                person.Id = reader.GetInt32(0);
                person.Name = reader.GetString(1);
                person.Email = reader.GetString(2);
                person.Contact = reader.GetString(3);
                personList.Add(person);
;            }
            conn.Close();
        }

       
    }
}
