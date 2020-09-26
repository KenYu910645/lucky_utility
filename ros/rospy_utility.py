#!/usr/bin/env python
import rospy
import tf2_ros 
from geometry_msgs.msg import TransformStamped
import tf # conversion euler
from math import atan2,acos,sqrt,pi,sin,cos,tan
from visualization_msgs.msg import Marker, MarkerArray # Debug drawing
from geometry_msgs.msg import Point
import tf_conversions
import time 

############################
### Visulization Markers ###
############################
ARC_RESO = 300 # points/radain
class Marker_Manager():

    def __init__(self, topic_name):
        self.pub = rospy.Publisher(topic_name, MarkerArray, queue_size = 1, latch=False)
        self.markers_info = {} # {"<name_of_this_marker>": Marker_Info(), ......}
        self.marker_array = MarkerArray()
    
    def register_marker(self, name, marker_type, frame_id, RGB, size):
        '''
        Init marker
        Marker_type:
            uint8 ARROW=0
            uint8 CUBE=1
            uint8 SPHERE=2
            uint8 CYLINDER=3
            uint8 LINE_STRIP=4
            uint8 LINE_LIST=5
            uint8 CUBE_LIST=6
            uint8 SPHERE_LIST=7
            uint8 POINTS=8
            uint8 TEXT_VIEW_FACING=9
            uint8 MESH_RESOURCE=10
            uint8 TRIANGLE_LIST=11
            uint8 ADD=0
            uint8 MODIFY=0
            uint8 DELETE=2
            uint8 DELETEALL=3
        '''
        if name in self.markers_info:
            rospy.logerror("[Marker_Manager] Name collision: " + str(name))
            return
        
        # marker_id indicate which index in markerarray
        marker_id = len(self.marker_array.markers)
        self.markers_info[name] = marker_id

        marker = Marker()
        marker.header.frame_id = frame_id
        marker.id = marker_id
        marker.ns = "tiles"
        marker.header.stamp = rospy.get_rostime()
        marker.type = marker_type
        marker.action = marker.ADD
        marker.text = "Hello World"
        marker.scale.x = size
        marker.scale.y = size
        marker.scale.z = size
        
        marker.color.a = 1.0
        marker.color.r = RGB[0]/255.0
        marker.color.g = RGB[1]/255.0
        marker.color.b = RGB[2]/255.0
        marker.pose.orientation.x = 0.0
        marker.pose.orientation.y = 0.0
        marker.pose.orientation.z = 0.0
        marker.pose.orientation.w = 1.0
        self.marker_array.markers.append(marker)

    def update_marker(self, name, points, text = None, radius = None, angle_range = None):
        '''
        points : ((x1,y1), (x2,y2), ....) - for line
        points : (x1,xy) - for shpere
        points : (x,y) - for arc, represent arc center
        text - string
        radius - float - for ARC
        angle_range - (-pi,pi) - for ARC, draw from ang[0] to ang[1], counter-clockwise
        '''
        try:
            array_idx = self.markers_info[name]
        except KeyError:
            rospy.logerror("[Marker_Manager] Can't find marker name: " + str(name))
            return
        else:
            self.marker_array.markers[array_idx].header.stamp = rospy.get_rostime()
            type_id = self.marker_array.markers[array_idx].type
            if type_id == 2: # SPHERE
                self.marker_array.markers[array_idx].pose.position.x = points[0]
                self.marker_array.markers[array_idx].pose.position.y = points[1]
            elif type_id == 4: # LINE_STRIP
                # Get point_list
                p_list = []
                if radius != None and angle_range != None:
                    # ARC
                    ang_distance = cal_ang_distance(angle_range[0], angle_range[1], clockwise = False)
                    num_seg = int(ang_distance*ARC_RESO)
                    ang_increment = 1.0/ARC_RESO
                    ang = angle_range[0]
                    for i in range(num_seg):
                        p_list.append(Point(points[0] + radius*cos(ang), points[1] + radius*sin(ang), 0.0))
                        ang += ang_increment
                else:
                    for i in points:
                        p_list.append(Point(i[0], i[1], 0.0))
                
                # Markers update
                self.marker_array.markers[array_idx].points = p_list
            elif type_id == 7 or type_id == 5: # SPHERE_LIST or LINE_LIST
                p_list = []
                for i in points:
                    p = Point()
                    p.x = i[0]
                    p.y = i[1]
                    p_list.append(p)
                self.marker_array.markers[array_idx].points = p_list
            elif type_id == 9: # TEXT_VIEW_FACING
                self.marker_array.markers[array_idx].pose.position.x = points[0]
                self.marker_array.markers[array_idx].pose.position.y = points[1]
                self.marker_array.markers[array_idx].text = text
    
    def publish(self):
        self.pub.publish(self.marker_array)
###################
### Arithmetic  ###
###################
def sign(value):
    if value >= 0:
        return 1 
    if value < 0:
        return -1

def is_same_sign(a, b):
    '''
    Check whether a,b are same sign 
    arguments:
        a - float/int
        b - float/int
    Return: 
        Bool - True means a,b have same sign, False means they don't
    '''
    if (a >= 0 and b >= 0) or (a < 0 and b < 0):
        return True
    else:
        return False

def normalize_angle(angle):
    '''
    Make angle inside range [-pi, pi]
    Arguments:
        angle - flaot
    Return:
        float
    '''
    ans = (abs(angle) % (2*pi))*sign(angle)
    if ans < -pi: # [-2pi, -pi]
        ans += 2*pi
    elif ans > pi: # [pi, 2pi]
        ans -= 2*pi
    return ans

def cal_ang_distance(ang1, ang2, clockwise = False):
    '''
    calcualte angle distance from ang1 to ang2
    '''
    ang1 = normalize_angle(ang1)
    ang2 = normalize_angle(ang2)
    if clockwise:
        rospy.logerror("GGGGGGGG didn't implemnt")
    else: # Counter-clockwise
        if (not is_same_sign(ang1, ang2)) and ang2 < 0:
            ang2 += 2*pi
        return abs(ang2 - ang1)

def cal_avg_angle(ang_list):
    '''
    Argument:
        ang_list : [ang1, ang2, ang3, ....]
    Return:
        flaot - angle that in [-pi, pi]
    '''
    sum_x = 0
    sum_y = 0 
    for ang in ang_list:
        sum_x += cos(ang)
        sum_y += sin(ang)
    return atan2(sum_y/len(ang_list), sum_x/len(ang_list))

def vec_trans_coordinate(vec, trans):
    '''
    Transform a vector from coordinate_A to coordinate_B
    Argument:
        vec: (x,y), vector that measure at coordinate_A
        trans:(x,y,theta), coordinate_A measure at coordinate_B
    Return:
        vec: (x,y), vector that measure at coordinate_B
    For example:
        if coordinate_A is /map, coordinate_B is /base_link, you want to know 
        the point that 1m in front of robot relative to /map.
        vec will be (1,0), since it's 1m in front of /base_link
        trans will be /map->/base_link, localization result
        Return vec will be on /map
    '''
    return (trans[0] + cos(trans[2])*vec[0] - sin(trans[2])*vec[1],
            trans[1] + sin(trans[2])*vec[0] + cos(trans[2])*vec[1])

##########
### TF ###
##########
def get_tf(tf_buffer, frame_id, child_frame_id, ignore_time=False, is_warn=True):
    '''
    get tf frame_id -> child_frame_id
    Arguments:
        frame_id(str): e.g: "map", "odom"
        child_frame_id(str): e.g: "base_link"
    Return:
        (x,y,theta)
        None, if tf is unvaliable
    '''
    try:
        t = tf_buffer.lookup_transform(frame_id,
                                        child_frame_id,
                                        rospy.Time(0), # should be rospy.Time.now()
                                        rospy.Duration(0.1))
    except (tf2_ros.LookupException, tf2_ros.ConnectivityException, tf2_ros.ExtrapolationException):
        if is_warn:
            rospy.logwarn("[get_tf] Can't get tf frame: " + frame_id + " -> " + child_frame_id)
        return None
    else:
        if (not ignore_time) and (rospy.Time.now() - t.header.stamp).to_sec() > 0.5: # sec
            return None
        quaternion = (
            t.transform.rotation.x,
            t.transform.rotation.y,
            t.transform.rotation.z,
            t.transform.rotation.w)
        (_,_,yaw) = tf.transformations.euler_from_quaternion(quaternion)
        return (t.transform.translation.x, t.transform.translation.y, yaw)

def send_tf(xyt, frame_id, child_frame_id, z_offset=0.0):
    '''
    Argument:
        xyt: (x,y,theta)
    '''
    br = tf2_ros.TransformBroadcaster()
    t = TransformStamped()
    t.header.stamp = rospy.Time.now()
    t.header.frame_id = frame_id
    t.child_frame_id = child_frame_id
    t.transform.translation.x = xyt[0]
    t.transform.translation.y = xyt[1]
    t.transform.translation.z = z_offset
    q = tf_conversions.transformations.quaternion_from_euler(0, 0,xyt[2])
    t.transform.rotation.x = q[0]
    t.transform.rotation.y = q[1]
    t.transform.rotation.z = q[2]
    t.transform.rotation.w = q[3]
    br.sendTransform(t)
