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




                try
                {
                    var divident = 15;
                
                    var divisor = 0;
              
                    if ( divisor == 0 )
                    {   
                      throw new MyException("Divisor is zero");
                    
                    }

                var result = divident / divisor;

                }
                catch (MyException ex)
                {
                    Console.WriteLine(ex.Message);
                }
            /*catch (DivideByZeroException ex)
            {
                Console.WriteLine(ex.Message);
            }*/

            Console.ReadKey();


        }
    }
}
