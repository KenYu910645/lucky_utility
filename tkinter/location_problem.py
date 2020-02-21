# 引入套件
import tkinter as tk
import tkinter.messagebox
from PIL import Image
from PIL import ImageTk

# 建立主視窗和 Frame（把元件變成群組的容器）
window = tk.Tk()
window.title("hello_world") # title of window
window.geometry('700x700') # dont specify, tk will automatic assign a proper size.

# window.resizable(0,0) # disable resize window   

# 將元件分為 top/bottom 兩群並加入主視窗
grid_frame = tk.Frame(window)
grid_frame.pack(side=tk.TOP)
pack_frame = tk.Frame(window)
pack_frame.pack()
place_frame = tk.Frame(window)
place_frame.pack()
'''
for i in range(4):
    for j in range(3):
        tk.Label(grid_frame, text=1).grid(row=i, column=j, padx=10, pady=10)
'''

#tk.Label(grid_frame, text=1).grid(row=0, column=0, padx=10, pady=10)
tk.Label(grid_frame, text=1).grid(row=0, column=1, padx=10, pady=10)
#tk.Label(grid_frame, text=1).grid(row=0, column=2, padx=10, pady=10)
# tk.Label(grid_frame, text=1).grid(row=0, column=0, padx=30, pady=10)

tk.Label(grid_frame, text=1).grid(row=1, column=0, padx=10, pady=10)
tk.Label(grid_frame, text=1).grid(row=1, column=1, padx=10, pady=10)
tk.Label(grid_frame, text=1).grid(row=1, column=2, padx=10, pady=10)

tk.Label(grid_frame, text=1).grid(row=2, column=0, padx=10, pady=10)
tk.Label(grid_frame, text=1).grid(row=2, column=1, padx=10, pady=10)
tk.Label(grid_frame, text=1).grid(row=2, column=2, padx=10, pady=10)




tk.Label(pack_frame, text='pack').pack(side='top')#上
tk.Label(pack_frame, text='pack').pack(side='bottom')#下
tk.Label(pack_frame, text='pack').pack(side='left')#左
tk.Label(pack_frame, text='pack').pack(side='right')#右



tk.Label(window, text=1).place(x=20, y=10, anchor='nw')


# 運行主程式
window.mainloop()