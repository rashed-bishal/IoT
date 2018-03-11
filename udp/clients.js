var buffer = require('buffer');
const udp = require('dgram');
var client = udp.createSocket('udp4');
//var access = require('mraa');
var request = require('request');

//var temperaturePin = new access.Aio(0);
//var lightPin = new access.Aio(1);

const B = 4275;
const R0 = 100000; 


/*function getSensorValues(sensorName)
{
    switch(sensorName)
    {
        case 10:

            var R = 1023.0/temperaturePin.read()-1.0;
            R = R0*R;
            var temperature = 1.0/(Math.log(R/R0)/B+1/298.15)-273.15;
            return temperature.toFixed(2);
            break;
        
        case 20:
            return lightPin.readFloat().toFixed(2)*1000;
            break;

    
    };
}*/

//

var data = Buffer.from('hello!');

client.send(data,2777,'127.0.0.1', function(error){
    if(error)
    {
        client.close();
    }
    else
    {
         console.log('Data has been send to server');
    } 
 });
 
 client.on('message', function(ibeam, infox){
     console.log('Data Received from server: '+ibeam.toString());
 });
 
