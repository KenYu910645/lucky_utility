# 引入套件
import tkinter as tk
import tkinter.messagebox
from PIL import Image
from PIL import ImageTk

# 建立主視窗和 Frame（把元件變成群組的容器）
window = tk.Tk()
window.title("hello_world") # title of window
# window.geometry('500x500') # dont specify, tk will automatic assign a proper size.

# window.resizable(0,0) # disable resize window   

# 將元件分為 top/bottom 兩群並加入主視窗
top_frame = tk.Frame(window)
top_frame.pack()
bottom_frame = tk.Frame(window)
bottom_frame.pack(side=tk.BOTTOM)

# 建立事件處理函式（event handler），透過元件 command 參數存取
def echo_hello():
    print('hello world :)')


# window element 
lucky_frame = tk.Frame(window)
lucky_frame.pack()
###----------   label   ----------###
label = tk.Label(lucky_frame, text='This is a label.')
label.pack(side=tk.LEFT)
# label.grid(column = 0, row = 0 )
###----------   entry   ----------###
entry = tk.Entry(lucky_frame,show = '*',font=('Arial',24)) # whatever you type become '*'
entry.pack(side=tk.LEFT)

###----------   Text   ----------###
text = tk.Text(lucky_frame,height = 2)
text.pack()

###----------   Listbox   ----------###
OptionList = ["1F","2F","3F","4F"] 
variable = tk.StringVar(lucky_frame)
variable.set(OptionList[0])

opt = tk.OptionMenu(lucky_frame, variable, *OptionList)
opt.config(width=3, font=('Helvetica', 12))
opt.pack(side="top")
# Show what you choose
labelTest = tk.Label(text="", font=('Helvetica', 12), fg='red')
labelTest.pack(side="top")

def listbox_callback(*args):
    labelTest.configure(text="The selected item is {}".format(variable.get()))

variable.trace("w", listbox_callback)

###----------   canvas   ----------###
canvas = tk.Canvas(lucky_frame,bg = "green", height = 300 , width = 500)
img =  ImageTk.PhotoImage(Image.open("pic/0_digit.pgm").resize((50,50), Image.ANTIALIAS))
canvas.create_image (100,100,anchor = 'center', image = img) # where to put pic on canvas
canvas.pack()

###----------   message box    ----------###
def blue_buttom():
    tkinter.messagebox.showinfo(title="hello msg box" , message="This is a msg box.")

###---------- custom button   -----------###

custom_button = tk.Button(lucky_frame, text="custom button", height = 100)
img = tk.PhotoImage(file="pic/round_button.pgm") # make sure to add "/" not "\"
custom_button.config(image=img)
custom_button.pack() # Displaying the button


def insert_point(): # insert text at cursor point
    text.insert("insert",entry.get())

def insert_end():   # insert text at the end of Text
    text.insert("end"   ,entry.get())

# 以下為 top 群組
# 讓系統自動擺放元件，預設為由上而下（靠左）
left_button = tk.Button(top_frame, text='insert point', fg='red' ,font=('Arial',24), width = 30 , height = 10, command = insert_point) # fg : color of text
left_button.pack(side=tk.LEFT)

middle_button = tk.Button(top_frame, text='insert end', fg='green', command = insert_end)
middle_button.pack(side=tk.LEFT)

right_button = tk.Button(top_frame, text='Blue', fg='blue', command = blue_buttom)
right_button.pack(side=tk.LEFT)



# 以下為 bottom 群組
# bottom_button 綁定 echo_hello 事件處理，點擊該按鈕會印出 hello world :)
bottom_button = tk.Button(bottom_frame, text='Black', fg='black', command=echo_hello)
# 讓系統自動擺放元件（靠下方）
bottom_button.pack(side=tk.BOTTOM)

# 運行主程式
window.mainloop()