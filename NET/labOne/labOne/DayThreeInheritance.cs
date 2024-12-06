
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace labOne
{

    //Programmer -> Employee -> DotNetDeveloper (single , multilevel)
     class Employee
    {
        public double salary = 300000;

    }

    class Programmer : Employee {
        public double bonus = 200000;
        public double equity = 40000000;
    }

    class DotNetDeveloper : Programmer {
        public double insurance = 1000000;
    }

    //GrandFather ->Father -> Son , Daughter (Hierarchial , Multiple , Hybrid)

    class GrandFather
    {
        public string grandFather_name = "ugrasena";
    }
    class Father : GrandFather {
        public string father_name = "Vasudev";
    }
    interface IMother { 
       void ShowMotherName();
    }
    class son : Father , IMother{
        public string name = "krishna";

        public void ShowSonDetails()
        {
            Console.WriteLine("Son :" + name);
        }

        public void ShowMotherName()
    {
        Console.WriteLine("Mother's Name: Devaki");
    }
}
    class daughter : Father , IMother
    {
        public string name = "subhadra";

        public void ShowDaughterDetails()
        {
            Console.WriteLine("Daughter : " + name);
        }

        public void ShowMotherName()
        {
            Console.WriteLine("Mother's Name: Devaki");
        }

    }

   




}
