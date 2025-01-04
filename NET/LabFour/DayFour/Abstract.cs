using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DayFour
{
    abstract class abstractTest {
        public abstract void Show();
        public abstract void Select();
        public void Delete()
        {
            Console.WriteLine("This is a delete method in Abstract");
        }
    }

    interface ITest {
        void Create();
        void Update();
    }

    class Student : abstractTest, ITest {

        public override void Select()
        {
            Console.WriteLine("This is Select Method from abstract");
        }
        public override void Show()
        {
            Console.WriteLine("This is Show Method from asbstract");
        }
        public void Create() { 
            Console.WriteLine("Interface Create Method from Interface"); 
        }
        public void Update() { 
            Console.WriteLine("Interface Update Method from Interface\n\n"); 
        }
    }



}





                            