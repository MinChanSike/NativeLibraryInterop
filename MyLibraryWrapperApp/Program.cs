using MyLibraryWrapper;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace MyLibraryWrapperApp {
    class Program {
        static void Main(string[] args) {
            Console.WriteLine("MyLibraryWrapperApp");

            var myLib = new MyLib(10, 20);
            myLib.OnEventHappen += MyLib_OnEventHappen;

            var sumResult = myLib.getSum();
            Console.WriteLine($"Sum result {sumResult}");

            var start = DateTime.Now;
            Console.WriteLine($"Deeploop start at {start}");
            var dResult = myLib.deepLoopTest(50000);
            var end = DateTime.Now;
            Console.WriteLine($"Deeploop result: {dResult}");
            Console.WriteLine($"Deeploop end at {end}, TotalMiliSec: {(end - start).TotalMilliseconds} ");

            var recStr = myLib.passString("Hello..");
            Console.WriteLine($"Received String: {recStr}");

            var recObjStr = myLib.passObject(new CustomObj {
                FirstProp = 5,
                SecondProp = 6,
                ThirdProp = 7
            });
            Console.WriteLine($"Received ObjString: {recObjStr}");

            SendPingPong(myLib);

            Console.ReadLine();
        }

        private static void MyLib_OnEventHappen(DotNetEventArg arg) {
            Console.WriteLine($"OnNativeEventHappen -> {arg.ArgString}");            
        }

        private static void SendPingPong(MyLib lib) {
            while (true) {
                Thread.Sleep(1000);
                lib.pokeNativeEvent("Ping from .net");
            }
        }

    }
}
