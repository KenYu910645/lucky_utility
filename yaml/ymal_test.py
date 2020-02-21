#!/usr/bin/env python
import signal
import sys
import yaml

f = open("/home/lucky/hello-git/pa.yaml",'r')
params_raw = f.read()
f.close()
param_dict = yaml.load(params_raw)
print param_dict['table']
table = param_dict['table']

print "table[open]", table['open']
#print "param_dict: ", param_dict
