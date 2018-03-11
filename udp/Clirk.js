var buffer = require('buffer');
var udp = require('dgram');
// creating a client socket
var client = udp.createSocket('udp4');

//buffer msg
var data = Buffer.from('Bangladesh');

client.send(data,0,11,904,'127.0.0.1',function(error){
    if(error){
      client.close();
    }else{
      console.log('Data sent !!!');
    }
  });
  
client.on('message',function(msg,info){
  console.log('Data received from server : ' + msg.toString());
  console.log('Received %d bytes from %s:%d\n',msg.length, info.address, info.port);
});

//sending msg

