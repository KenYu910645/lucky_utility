import logging 
# logger
# Set up logger
formatter = logging.Formatter('[%(asctime)s] %(levelname)s: %(message)s')
private_logger = logging.getLogger('MQTT')
private_logger.setLevel(logging.DEBUG)

# Record logging message at logging file
h_file = logging.FileHandler("mqtt_private.log")
h_file.setFormatter(formatter)
h_file.setLevel(logging.INFO) # logging.DEBUG
private_logger.addHandler(h_file)
