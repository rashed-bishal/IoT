import json, ast
from flask import Flask
from flask import request
from pymongo import MongoClient # Database connector
from bson.objectid import ObjectId # For ObjectId to work


client = MongoClient('localhost', 27017)    #Configure the connection to the database
db = client.sensor   #Select the database
todos = db.sensor_data #Select the collection
 
app = Flask(__name__)
 
@app.route('/body', methods = ['POST'])
def postJsonHandler():
    print (request.is_json)
    content = request.get_json()
    test = ast.literal_eval(json.dumps(content))
    print (test)


    timestamp=test["timestamp"]
    name=test["name"]
    value=test["value"]
    id=test["id"]
    todos.insert({ "timestamp":timestamp, "name":name, "value":value, "id":id})
    
    #file=open('test.tx','a')
    #file.write("data"+str(test))
    #print("File Read Successed")
    #file.close()
    return 'JSON posted'
app.run(host='192.168.6.101', port= 8081)

