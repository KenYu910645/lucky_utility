function pull {
    roscd solamr
    echo "===== Big project ====="
    git pull
    roscd rap_controller/script/lucky_utility/
    echo "===== rap_controller/lucky_utility ====="
    git pull
    roscd obstacle_detector/script/lucky_utility/
    echo "===== obstacle_detector/lucky_utility ====="
    git pull
    roscd solamr/scripts/lucky_utility/
    echo "===== solamr/lucky_utility ====="
    git pull
    roscd ros_mqtt_bridge/script/lucky_utility/
    echo "===== ros_mqtt_bridge/lucky_utility ====="
    git pull
}
