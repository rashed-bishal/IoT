
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net;
using System.Net.Sockets;
using System.IO;
namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int recv;
            byte[] data = new byte[1024];
            Boolean exception_thrown = false;

            IPEndPoint endpointip = new IPEndPoint(IPAddress.Any, 904);
            Socket newSocket = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
            newSocket.Bind(endpointip);

            IPEndPoint sender = new IPEndPoint(IPAddress.Any, 904);
            EndPoint tmpRemote = (EndPoint)sender;

            recv = newSocket.ReceiveFrom(data, ref tmpRemote);
            Console.WriteLine("Massage received from {0} : ", tmpRemote.ToString());
            Console.WriteLine(Encoding.ASCII.GetString(data, 0, recv));

            Socket sendSocket = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
     
            IPAddress send_to_address = IPAddress.Parse("192.168.0.2");
            IPEndPoint sending_end_point = new IPEndPoint(send_to_address, 904);

            byte[] send_buffer = Encoding.ASCII.GetBytes("World");
            //Buffer buff = new Buffer();

            // Remind the user of where this is going.

            
            try

            {
                sendSocket.SendTo(send_buffer, sending_end_point);
            }
            catch (Exception send_exception)
            {
                exception_thrown = true;
                Console.WriteLine(" Exception {0}", send_exception.Message);
            }
            if (exception_thrown == false)
            {
                Console.WriteLine("Message has been sent to the broadcast address");
            }
            else

            {
                exception_thrown = false;
                Console.WriteLine("The exception indicates the message was not sent.");
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
               
                Console.WriteLine(Encoding.ASCII.GetString(data, 0, recv));
            }
            //newSocket.Close();
        }
    }
}

