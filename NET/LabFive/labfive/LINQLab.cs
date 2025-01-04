using System;
using System.Collections.Generic;
using System.ComponentModel.Design;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace labfive
{
    class Employees
    {
        public string Name { get; set; }
        public string Address { get; set; }
        public double Salary { get; set; }


    }
    class linq 
    { 
        public linq()
        {
            Console.WriteLine("LINQ Part :");
            List<Employees> Employeelist = new List<Employees>() { 
                new Employees{Name="Anish Acharya", Address = "Palpa" , Salary = 20000},
                new Employees{Name="Suraj Pathak" , Address = "Kathmandu" , Salary = 420000},
                new Employees{Name="Ankit ", Address = "Kathmandu" , Salary = 70000},
            };

            var emp = from e in Employeelist where e.Salary > 20000 && e.Address == "Kathmandu" select e;
            foreach(Employees a in emp)
            {
                Console.WriteLine( a.Name);
            }

            Console.WriteLine(" ");

            List<int> Num = new List<int>() 
        {
             1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 
        };

        var result = Num.FindAll(x=>(x%2)==0); //Lambda Expression
        //var result = from List in Num where List%2==0 select List;

        foreach(var a in result)
            {
                Console.WriteLine(a.ToString());
            }
        Console.WriteLine(" ");
        

        }

    }

}
