function roscode {
    local rosvals
    if [[ $1 = "--help" ]] || [[ $# -gt 1 ]]; then
        echo -e "usage: roscode package\n\nJump to target package."
        return 0
    fi
    if [ -z $1 ]; then
      if [ ! -z $ROS_WORKSPACE ]; then
        cd ${ROS_WORKSPACE}
        return 0
      fi
      if [ ! -z $CMAKE_PREFIX_PATH ]; then
        IFS=":" read -a workspaces <<< "$CMAKE_PREFIX_PATH"
        for ws in "${workspaces[@]}"; do
          if [ -f $ws/.catkin ]; then
            cd ${ws}
            return 0
          fi
        done
      fi
      echo -e "Neither ROS_WORKSPACE is set nor a catkin workspace is listed in CMAKE_PREFIX_PATH.  Please set ROS_WORKSPACE or source a catkin workspace to use roscode with no arguments."
      return 1
    fi

    _ros_decode_path $1 forceeval
    if [ $? != 0 ]; then
      echo "roscode: No such package/stack '$1'"
      return 1
    elif [ -z $rosvals ]; then
      if [ -z $ROS_WORKSPACE ]; then
        echo -e "No ROS_WORKSPACE set.  Please set ROS_WORKSPACE to use roscode with no arguments."
        return 1
      fi
      cd ${ROS_WORKSPACE}
      return 0
    else
      code ${rosvals[1]}${rosvals[2]}${rosvals[3]}
      return 0
    fi
}
complete -F "_roscomplete_sub_dir" -o "nospace" "roscode"