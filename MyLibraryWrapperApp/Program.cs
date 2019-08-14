using MyLibraryWrapper;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyLibraryWrapperApp {
    class Program {
        static void Main(string[] args) {
            Console.WriteLine("MyLibraryWrapperApp");

            var myLib = new MyLib(10, 20);
            var sumResult = myLib.getSum();
            Console.WriteLine($"Sum result {sumResult}");

            var start = DateTime.Now;
            Console.WriteLine($"Deeploop start at {start}");
            var dResult = myLib.deepLoopTest(50000);
            var end = DateTime.Now;
            Console.WriteLine($"Deeploop result: {dResult}");
            Console.WriteLine($"Deeploop end at {end}, TotalMiliSec: {(end - start).TotalMilliseconds} ");

            Console.ReadLine();
        }
    }
}
