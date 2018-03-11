var udp = require('dgram');
var PORT = 904;
var HOST = '192.168.0.3';
// --------------------creating a udp server --------------------

// creating a udp server
var server = udp.createSocket('udp4');
server.bind(PORT);

// emits when any error occurs
server.on('error',function(error){
  console.log('Error: ' + error);
  server.close();
});

server.on('listening', function(){
  console.log('Server started at ', PORT);
});
// emits on new datagram msg
server.on('message',function(msg,info){
  console.log('Data received from client : ' + msg.toString());
  console.log('Received %d bytes from %s:%d\n',msg.length, info.address, info.port);

//sending msg
server.send(msg,0,11,info.port,'192.168.0.2',function(error){
  if(error){
    console.log('Client Error!');
  }else{
    console.log('Data sent !!!');
  }

});

});

//emits when socket is ready and listening for datagram msgs




setTimeout(function(){
server.close();
},1000000);