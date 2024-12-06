
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace labOne
{
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


    class Father {
        public string father_name = "nanda baba";
    }
    class son : Father{
        public string name = "kanaiya";
    }
    class daughter : Father
    {
        public string name = "radha rani";
    }




}
