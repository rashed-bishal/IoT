var access = require('mraa');
var request = require('request');

var temperaturePin = new access.Aio(0);
var lightPin = new access.Aio(1);
var soundPin = new access.Aio(2);

//temperature sensor calibration

const B = 4275; //B value of thermistor component
const R0 = 100000; // R0 = 100kOhm




var counter = 1;

var fileStructure = 
{
    "recordTime" : "",
    "sensorName" : "",
    "sensorId" : 0,
    "sensorValue" : 0
}

function getSensorValues(sensorName)
{
    switch(sensorName.toLowerCase())
    {
        case "temperature":

            var R = 1023.0/temperaturePin.read()-1.0;
            R = R0*R;
            var temperature = 1.0/(Math.log(R/R0)/B+1/298.15)-273.15;
            return temperature.toFixed(2);
            break;
        
        case "light":
            return lightPin.readFloat().toFixed(2)*1000;
            break;

        case "sound":
            
            return soundPin.readFloat().toFixed(2)*1000;
            break;
    };
}

function transmit()
{
    fileStructure.recordTime = new Date();
    fileStructure.sensorName = sensor;
    fileStructure.sensorId = counter;
    fileStructure.sensorValue = getSensorValues(sensor);
    counter++;

    request({
        method : "POST",
        url : "http://127.0.0.1:8081/1/"+sensor,
        headers: {
            "content-type" : "application/json"
        },
        json : true,
        body : fileStructure
        
    }, function(error,response,body){

    });
}

var T = function (){ transmit("temperature"); };
var L = function (){ transmit("light"); };
var S = function (){ transmit("sound"); };

setInterval(T,5000);
setInterval(L,5000);
setInterval(S,5000);
