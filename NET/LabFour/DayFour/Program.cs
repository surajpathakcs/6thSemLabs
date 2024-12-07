using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DayFour
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Student student = new Student();
            student.Show();
            student.Select();
            student.Create();
            student.Delete();
            student.Update();

            Console.ReadKey();
        }
    }
}
