using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace labOne
{
    internal class Program
    {

        public static void Main(string[] args)
        {
            // Demonstrating Single Inheritance
            Console.WriteLine("Single Inheritance (Programmer -> Employee -> DotNetDeveloper):");
            DotNetDeveloper suraj = new DotNetDeveloper();
            Console.WriteLine("Employee Salary: " + suraj.salary);
            Console.WriteLine("Programmer Bonus: " + suraj.bonus);
            Console.WriteLine("Programmer Equity: " + suraj.equity);
            Console.WriteLine("DotNetDeveloper Insurance: " + suraj.insurance);
            Console.WriteLine(); // Line break

            // Demonstrating Multilevel Inheritance
            Console.WriteLine("Multilevel Inheritance (Employee -> Programmer -> DotNetDeveloper):");
            DotNetDeveloper kanha = new DotNetDeveloper();
            Console.WriteLine("Employee Salary: " + kanha.salary);
            Console.WriteLine("Programmer Bonus: " + kanha.bonus);
            Console.WriteLine("Programmer Equity: " + kanha.equity);
            Console.WriteLine("DotNetDeveloper Insurance: " + kanha.insurance);
            Console.WriteLine(); // Line break

            // Demonstrating Hierarchical Inheritance (GrandFather -> Father -> Son/Daughter)
            Console.WriteLine("Hierarchical Inheritance (GrandFather -> Father -> Son, Daughter):");
            son krishna = new son();
            daughter subhadra = new daughter();

            // Showing details of Son
            krishna.ShowSonDetails(); // From Son
            krishna.ShowMotherName(); // From IMother (implemented by Son)

            Console.WriteLine(); // Line break

            // Showing details of Daughter
            subhadra.ShowDaughterDetails(); // From Daughter
            subhadra.ShowMotherName(); // From IMother (implemented by Daughter)

            Console.WriteLine(); // Line break

            Console.WriteLine("");
      
            


          MyChild myChild = new MyChild();
          myChild.show();
          myChild.OverrideMethod();

            

          Console.ReadKey();

           

        

       }
    }
}
