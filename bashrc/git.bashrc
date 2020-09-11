RED='\033[0;33m'
NC='\033[0m' # No Color
function luckypull {
    roscd solamr
    echo -e "${RED}===== Big project =====${NC}"
    git pull
    roscd rap_controller/script/lucky_utility/
    echo -e "${RED}===== rap_controller/lucky_utility =====${NC}"
    git pull
    roscd obstacle_detector/script/lucky_utility/
    echo -e "${RED}===== obstacle_detector/lucky_utility =====${NC}"
    git pull
    roscd solamr/scripts/lucky_utility/
    echo -e "${RED}===== solamr/lucky_utility =====${NC}"
    git pull
    roscd ros_mqtt_bridge/script/lucky_utility/
    echo -e "${RED}===== ros_mqtt_bridge/lucky_utility =====${NC}"
    git pull
    roscd solamr
}


function luckypush
{
    roscd solamr
    git add --all
    git commit 
    git push 
}
