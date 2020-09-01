#---- General hotkey -----#
alias e='exit'
alias rc='vim ~/.bashrc'
alias lucky='nmcli connection up lucky'

#---- SSH hotkey -----# 
alias rpi1='sshpass -p "husarion" ssh -o StrictHostKeyChecking=no husarion@192.168.50.11'
alias rpi2='sshpass -p "husarion" ssh -o StrictHostKeyChecking=no husarion@192.168.50.21'
alias nano='sshpass -p "chanky.123#" ssh -o StrictHostKeyChecking=no ken@192.168.50.173'
alias solab='sshpass -p "chanky.123#" ssh -o StrictHostKeyChecking=no solab@meet.solab.me.ntu.edu.tw'

# Ros hotkey
alias t='rostopic list'
alias rviz_sol='roslaunch solamr_monitor rviz_for_solamr.launch'
# alias simu='roslaunch ar ar_amcl.launch is_simulation:=true'

