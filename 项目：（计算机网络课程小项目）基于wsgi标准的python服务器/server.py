"""
邢国浩 2020/5
一个符合WSGI标准的简单python服务器和一个对应的实例应用网络框架，保证了应用网络框架和python服务器完全解耦
环境：windows 10
基于多进程
"""
import socket
import re
import multiprocessing as mp
import sys
import os
import tkinter as tk
import tkinter.messagebox

class my_server():
    #定义端口，WSGI标准中规定的函数属性(application(env,start_response))，静态资源的地址，开始监听；
    def __init__(self,port,app,static_path):
        self.tcp_service_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
        #如果端口忙，但TCP状态位于TIME_WAIT，可以重用端口
        self.tcp_service_socket.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1)
        self.tcp_service_socket.bind(("",port))
        self.tcp_service_socket.listen(128)
        self.application = app
        self.static_path = static_path

    #为客户端提供服务
    def service_client(self, new_socket):
        request = new_socket.recv(1024).decode("utf-8")
        request_lines = request.splitlines()
        print(request)
        file_name = ""
        # 提取 GET /？？？
        ret = re.match(r"[^/]+(/[^ ]*)", request_lines[0])
        if ret:
            file_name = ret.group(1)
            if (file_name == "/"):
                file_name = "/index.html"
        # 如果是静态请求
        if not file_name.endswith(".py"):
            try:
                f = open(self.static_path + file_name, "rb")
            except Exception as e:
                response = "HTTP/1.1 404 NOT FOUND\r\n\r\n---the page not founded---"
                new_socket.send(response.encode("utf-8"))
            else:
                html_content = f.read()
                f.close()
                response = "HTTP/1.1 200 OK\r\n\r\n"
                new_socket.send(response.encode("utf-8"))
                new_socket.send(html_content)
        # 如果是动态请求
        else:
            env = dict()
            env['PATH_INFO'] = file_name
            #WSGI接口应用，按照标准规定是一个接受CGI环境变量的字典和设定回应头的函数
            body = self.application(env, self.set_response_header)
            header = "HTTP/1.1 %s\r\n" % self.status
            for tmp in self.headers:
                header += "%s: %s\r\n" % (tmp[0], tmp[1])
            header += "\r\n"
            response = header + body
            new_socket.send(response.encode("utf-8"))
        new_socket.close()

    #设置回应头，服务器方面，在应用框架基础上添加服务器相关的信息 （从浏览器可以看到）
    def set_response_header(self, status, headers):
        self.status = status
        # 服务器信息
        self.headers = [("server", "web_server")]
        self.headers += headers

    def run_forever(self):
        while (True):
            nss, cld = self.tcp_service_socket.accept()
            p = mp.Process(target=self.service_client, args=(nss,))
            p.start()
            nss.close()
        self.tcp_service_socket.close()

#打开配置文件
def on_open():
    os.startfile("config.txt")

#启动服务器
def on_click():
    port = int(port_text.get())
    ret = re.match(r"([^:]+):(.*)", frm_text.get())
    if ret:
        frame_name = ret.group(1)
        app_name = ret.group(2)
    else:
       tk.messagebox.showinfo('Result','输入不合规范')
    with open("config.txt") as f:
        # 字符串转为字典
        conf_info = eval(f.read())
        print(conf_info["sp"])
    sys.path.append(conf_info["dp"])
    frame = __import__(frame_name)
    app = getattr(frame, app_name)
    wsgi_server = my_server(port, app, conf_info["sp"])
    tk.messagebox.showinfo('Result', '服务器已启动，运行中...示例：主页访问：http:127.0.0.1:'+port_text.get())
    wsgi_server.run_forever()

if __name__ == "__main__":
    win = tk.Tk()
    win.title("my_server配置启动_2020/5/20_2018141463075_邢国浩")
    win.geometry("600x600")  # #窗口位置500后面是字母x
    l1 = tk.Label(win, text="请输入服务端口号：")
    l1.pack()  # 这里的side可以赋值为LEFT  RTGHT TOP  BOTTOM
    port_text = tk.StringVar()
    port_string = tk.Entry(win, textvariable=port_text)
    port_string.pack()

    l2 = tk.Label(win, text="请输入框架和应用函数名称,格式：框架名：应用函数名。示例:frame_1:application")
    l2.pack()  # 这里的side可以赋值为LEFT  RTGHT TOP  BOTTOM
    frm_text = tk.StringVar()
    frm = tk.Entry(win, textvariable=frm_text)
    frm.pack()

    tk.Button(win, text="更改配置文件", command=on_open).pack()
    tk.Button(win, text="启动服务器", command=on_click).pack()
    win.mainloop()


