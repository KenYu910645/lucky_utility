from lib_mqtt import MQTT_OBJ
import time # for sleep

# ------ MQTT Connection ------ #
# mqtt_obj = MQTT_OBJ(client_id="solamr_2", broker_ip="broker.hivemq.com", port=1883, keepalive=10, clean_session=True)
mqtt_obj = MQTT_OBJ(client_id="solamr_2", broker_ip="192.168.0.10", port=1883, keepalive=10, clean_session=True)

# ------ Add Subscriber -----#
def topic_CB(client, userdata, message):# Callback fucntion 
    print("[MQTT] topic_CB :  " + str(message.payload) + "(Q" + str(message.qos) + ", R" + str(message.retain) + ")")
    mqtt_obj.publish("topic_2_to_1", "I'm fine, thank you, and you?", qos = 0, retain = False) # non-blocking msg
mqtt_obj.add_subscriber([( "topic_1_to_2", 2, topic_CB)])

# Spin, avoid exit
while True:
    time.sleep(0.1)