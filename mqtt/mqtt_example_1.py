from lib_mqtt import MQTT_OBJ
import time

#------ parameters -----# 
NOTIFY_MAX_RETRY_TIME = 3 # sec
t_start = time.time()
count = 0
avg = 0
# ------ MQTT Connection ------ #
# Every Mqtt entity MUST have different client_id , otherwise, weird things happen.
# keepalive (sec), How long to disconnect broken if didn't receive response from broker
# publish mqtt server : http://www.mqtt-dashboard.com/
#mqtt_obj = MQTT_OBJ(client_id="solamr_1", broker_ip="broker.hivemq.com", port=1883, keepalive=10, clean_session=True)
mqtt_obj = MQTT_OBJ(client_id="solamr_1", broker_ip="10.0.0.1", port=1883, keepalive=10, clean_session=True)
# ------ Add Subscriber -----#
def topic_CB(client, userdata, message):# Callback fucntion
    dt = time.time() - t_start
    print("[mqtt_example] Latency : " + str(dt) + " sec.")
    avg += dt/10
    print("[mqtt_example] topic_CB :  " + str(message.payload) + "(Q" + str(message.qos) + ", R" + str(message.retain) + ")")
mqtt_obj.add_subscriber([( "topic_2_to_1", 0, topic_CB)])

#-------persistant publisher--------#
while count < 10:
    # MQTT Publish msg, if retain set to True, broker will publish the retain msg to every subscirber whenever they subscribe this topic.
    rc = mqtt_obj.publish("topic_1_to_2", "How are you doing today ?," + str(time.time()), qos = 0, retain = False) # non-blocking msg
    t_start = time.time()
    # Waiting result of publish
    
    while time.time() - t_start <= NOTIFY_MAX_RETRY_TIME:
        try:
            is_pub = rc.is_published()
        except AttributeError: # rc == None # Didn't publish because client is offline
            print ("[mqtt_example] One of the client is offline, didn't publish")
            break
        else:
            if is_pub: # if True , means publisher finished all handshake with broker (qos1, qos2)
                print("[mqtt_example] publish success")
                break # Successfully published
        time.sleep(1)
    
    #----- Check time out -----#
    if time.time() - t_start >= NOTIFY_MAX_RETRY_TIME: 
        print('[mqtt_example] TIMEOUT ABORT. Wait for publish callback for ' + str( time.time() - t_start ) + ' sec.')
    
    time.sleep(1)

print ("Avg latency: " + str(avg))
