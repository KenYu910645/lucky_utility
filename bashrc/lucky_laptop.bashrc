
# source /opt/ros/kinetic/setup.bash
# source ~/holy_ws/devel/setup.bash
# source ~/solab_ws/devel/setup.bash
# source ~/yc_ws/devel/setup.bash

# export ROS_IP=`ip route get 8.8.8.8 | awk '{print $NF; exit}'`
export ROS_IP='127.0.0.1'
export ROS_MASTER_URI=http://localhost:11311

# --- Check current working env -----# 
ENV=$(cat ~/.working_env)
if [ "$ENV" = "kinematics" ];then
    alias start='roslaunch multirobot_kinematics kinematics_big_car.launch'
    roscd multirobot_kinematics
fi
if [ "$ENV" = "spider" ];then
    alias start='python3 ~/spider/list_analyse.py'
    cd ~/spider
fi
if [ "$ENV" = "solamr" ];then
    alias tele='rosrun ar teleop_key.py'
    alias tf='rosrun tf view_frames;sleep 6;evince frames.pdf'
    alias start=' roslaunch zed_rtabmap_example rviz_for_solamr.launch'
    export ROS_IP="192.168.50.10"
    #export ROS_MASTER_URI=http://192.168.50.21:11311 # point to rpi
    export ROS_MASTER_URI=http://localhost:11311 # point to rpi
    roscd solamr_monitor
fi
if [ "$ENV" = "naive_controller" ];then
    alias start='rosrun amr_gazebo teleop_key_2in1.py'
    alias tele='rosrun ar teleop_key.py'
    roscd amr_gazebo
fi
if [ "$ENV" = "solamr_simulator" ];then
    alias start='roslaunch amr_gazebo solamr_linked_2in1.launch'
    roscd amr_gazebo
fi
#----Working Space -----# 
alias ki='rm ~/.working_env;
          echo "kinematics" > ~/.working_env;
          code --goto ~/solab_ws/src/multirobot_kinematics;
          source ~/.bashrc'
alias spi='rm ~/.working_env;
           echo "spider" > ~/.working_env;
           code --goto ~/spider/;
           source ~/.bashrc'
alias sol='rm ~/.working_env;
           echo "solamr" > ~/.working_env;
           source ~/.bashrc;'
alias nai='rm ~/.working_env;
           echo "naive_controller" > ~/.working_env;
           source ~/.bashrc;'
alias link='rm ~/.working_env;
          echo "solamr_simulator" > ~/.working_env;
          code --goto ~/solab_ws/src/solamr_simulator/src/amr_gazebo;
          source ~/.bashrc'

# Application 
alias zedex='./../../usr/local/zed/tools/ZED_Explorer'
alias record='rosservice call --wait /zedA/zed_node_A/start_svo_recording ~/solab_ws/src/zed-ros-examples/examples/zed_rtabmap_example/rosbag/zed_two.svo ; rosservice call --wait /zedB/zed_node_B/start_svo_recording ~/solab_ws/src/zed-ros-examples/examples/zed_rtabmap_example/rosbag/zed_one.svo'
alias stop='rosservice call --wait /zedA/zed_node_A/stop_svo_recording ; rosservice call --wait /zedB/zed_node_B/stop_svo_recording'
