#!/usr/bin/env python
import signal
import sys
import logging
import argparse

# Set up logger
formatter = logging.Formatter('[%(asctime)s] %(levelname)s: %(message)s')
logger = logging.getLogger('cherrypy')
logger.setLevel(logging.DEBUG)

#Set up args
parser = argparse.ArgumentParser(description='Process some integers.')
parser.add_argument('-v', '--verbose', action='store_true', dest='verbose',
                    help='Enable debug info on consolo')
args = parser.parse_args()

# To print out logging message on console
h_console = logging.StreamHandler()
h_console.setFormatter(formatter)
if args.verbose:
    print "verbose!"
    h_console.setLevel(logging.DEBUG)
else:
    print "Not verbose!!"
    h_console.setLevel(logging.INFO)
logger.addHandler(h_console)

# Record logging message at logging file
h_file = logging.FileHandler("logging_example.log")
h_file.setFormatter(formatter)
h_file.setLevel(logging.INFO)
logger.addHandler(h_file)


# print log
logger.warning("asdf")
logger.info("infomation")
logger.critical("critical" + "add str")
logger.debug("debug : " + str(123) )
logger.error("error : " + "123" )
logger.warn("1234")




