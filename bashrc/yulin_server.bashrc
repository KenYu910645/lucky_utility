
source /opt/ros/kinetic/setup.bash
source ~/solab_ws/devel/setup.bash

# export ROS_IP=`ip route get 8.8.8.8 | awk '{print $NF; exit}'`
export ROS_IP='192.168.50.10'
#export ROS_MASTER_URI=http://localhost:11311
export ROS_MASTER_URI=http://192.168.50.11:11311

