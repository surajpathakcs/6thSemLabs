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


            try
            {
                var a = 15;
                
                var b = 0;
                var c = a/b;
              
                if ( b == 0 )
                {   
                  throw new MyException("Divisor is zero");
                    
                }

            }
            catch (MyException ex)
            {
                Console.WriteLine(ex.Message);
            }
            catch (DivideByZeroException ex)
            {
                Console.WriteLine(ex.Message);
            }

            Console.ReadKey();


        }
    }
}
