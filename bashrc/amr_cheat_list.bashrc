RED='\033[0;33m'
NC='\033[0m' # No Color
echo "============   Cheat List   ================"
echo -e "${RED}task q${NC} : task abort"
echo -e "${RED}task 1${NC} : task single_AMR"
echo -e "${RED}task 2${NC} : task double_AMR"
echo -e "${RED}task j1${NC} : jp2 single_AMR" # jp2 single_AMR
echo -e "${RED}task j2${NC} : jp2 Single_Assembled"
echo -e "${RED}task ja${NC} : jp2 Double_Assembled"

echo -e "${RED}gate o${NC} : gate open"
echo -e "${RED}gate c${NC} : gate close"

function gate
{
    if [ $1 = "o" ]; then # open gate 
        rostopic pub /gate_cmd  std_msgs/Bool "data: false"
    elif [ $1 = "c" ]; then # close gate 
        rostopic pub /gate_cmd  std_msgs/Bool "data: true"
    else
        echo -e "${RED}You type wrong command, you dumb-ass!${NC}"
    fi
}

function task
{
    if [ $1 = "q" ]; then
        rosservice call /$(ROBOT_NAME)/fsm/task  "data: 'abort'"

    elif [ $1 = "1" ]; then
        rosservice call /$(ROBOT_NAME)/fsm/task  "data: 'single_AMR'"

    elif [ $1 = "2" ]; then
        rosservice call /$(ROBOT_NAME)/fsm/task  "data: 'double_AMR'"

    elif [ $1 = "j1" ]; then
        rosservice call /$(ROBOT_NAME)/fsm/task  "data: 'jp2Single_AMR'"

    elif [ $1 = "j2" ]; then
        rosservice call /$(ROBOT_NAME)/fsm/task  "data: 'jp2Double_Assembled'"

    elif [ $1 = "ja" ]; then
        rosservice call /$(ROBOT_NAME)/fsm/task  "data: 'jp2Single_Assembled'"
    else
        rosservice call /$(ROBOT_NAME)/fsm/task  "data: '$1'"
    fi
}
