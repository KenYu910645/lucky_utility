from tkinter import *

class app():
    def __init__(self):
        self.root = Tk()
        # Create a button
        self.bt = Button(self.root, text="draw line",command = self.bt_CB)
        self.bt.pack()

        self.canvas = Canvas(self.root, width=300, height=300)
        self.canvas.pack()

        self.line_counter = 0
        # self.draw_next_line()
        print ("Before mainloop")
        self.root.mainloop()
        print ("After  mainloop")

    def bt_CB(self):
        self.root.after(1, self.draw_next_line)

    def draw_next_line(self):
        self.canvas.create_line(0, 0, 50, self.line_counter * 50 + 10)
        self.line_counter += 1
        # self.root.after(1000, self.draw_next_line)
        '''
        if self.line_counter != 5:
            # call this function again after 1000 milliseconds
            self.root.after(1000, self.draw_next_line)
        '''
app()