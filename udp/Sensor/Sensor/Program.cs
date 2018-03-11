using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net;
using System.Net.Sockets;
using System.IO;
using System.Text;

namespace Sensor
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            
                int recv;
            string d;
                byte[] data = new byte[1024];
                IPEndPoint endpointip = new IPEndPoint(IPAddress.Any, 33333);
                Socket newSocket = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
                newSocket.Bind(endpointip);
                Console.WriteLine("Waiting for client.......");
                IPEndPoint sender = new IPEndPoint(IPAddress.Any, 33333);
                EndPoint tmpRemote = (EndPoint)sender;
                recv = newSocket.ReceiveFrom(data, ref tmpRemote);
                //Console.Write("Massage received from {0}", tmpRemote.ToString());
                //Console.WriteLine(Encoding.ASCII.GetString(data, 0, recv));

                

                if (newSocket.Connected)
                {
                    newSocket.Send(data);
                }

                while (true)
                {
                    if (!newSocket.Connected)
                    {
                        //Console.WriteLine("Client Disconnected! :(");
                        // break;
                    }
                    data = new byte[1024];
                    recv = newSocket.ReceiveFrom(data, ref tmpRemote);
                    if (recv == 0)
                    {
                        //newSocket.SendTimeout = 10;
                        // break;
                    }
                    d = Encoding.ASCII.GetString(data, 0, recv);
                }
            Application.Run(new Form1(d));
          


        }


    }
}
