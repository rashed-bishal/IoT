using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace testingThread
{
    public class ThreadWorker
    {
        int ID;
        Thread rashed;

       
        
        public ThreadWorker(int ID)
        {
            this.ID = ID;
            rashed = new Thread(new ThreadStart(getWork));
            rashed.Start();
        }

        void getWork()
        {
            for(int i=0; i<10; i++)
            {
                Console.WriteLine("Thread number "+ID+" is running...");
            }

            Console.WriteLine("Thread number "+ID+" is finished!");
        }
    }

    class Program
    {
       
        static void Main(string[] args)
        {
            for(int a=0; a<10; a++)
            {
                ThreadWorker ROCY = new ThreadWorker(a);
            }
            Console.ReadLine();
        }

        
    }
}
