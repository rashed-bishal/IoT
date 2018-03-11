from flask import Flask
from flask import request
from pymongo import MongoClient
 
app = Flask(__name__)

client = MongoClient(port=27017)
db=client.myDatabase
 
@app.route('/value', methods = ['POST'])
def postJsonHandler():
    content = request.get_json()
    result=db.sensorData.insert_one(content)
    print (content)
    return 'JSON posted'

if __name__ == '__main__':
   app.run(host='0.0.0.0',debug=True)