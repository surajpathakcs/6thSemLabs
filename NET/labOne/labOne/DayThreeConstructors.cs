using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace labOne
{
    internal class Student
    {
        public string Name = " ";
        public string Address = " ";

        //Default Constructor
        public Student()
        {
            Name = "Suraj";
            Address = "Kathmandu";
            Console.WriteLine(Name);
        }

        static Student()
        {
            Console.WriteLine("This is static constructor");
        }

        private Student(string a)
        {
            Name = "Private";
            Address=a;
        }
        public Student(string a, string b) 
        { Name = a; Address = b; }

        public Student(Student obj) 
        { 
            Name = obj.Name; Address = obj.Address;
            Console.WriteLine(Name+"\n");
            Console.WriteLine(Address+"\n");
        }
        

    }
}
