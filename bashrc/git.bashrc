
RED='\033[0;31m'
NC='\033[0m' # No Color

function luckypull {
    roscd solamr
    echo "${RED}===== Big project ====="
    git pull
    roscd rap_controller/script/lucky_utility/
    echo "${RED}===== rap_controller/lucky_utility ====="
    git pull
    roscd obstacle_detector/script/lucky_utility/
    echo "${RED}===== obstacle_detector/lucky_utility ====="
    git pull
    roscd solamr/scripts/lucky_utility/
    echo "${RED}===== solamr/lucky_utility ====="
    git pull
    roscd ros_mqtt_bridge/script/lucky_utility/
    echo "${RED}===== ros_mqtt_bridge/lucky_utility ====="
    git pull
    roscd solamr
}
