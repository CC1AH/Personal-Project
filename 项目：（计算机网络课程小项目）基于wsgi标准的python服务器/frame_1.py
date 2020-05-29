#动态资源函数分支
def login():
    body =  "<h1>动态资源请求页面示例-处理脚本：login.py（项目没有要求，前端逻辑没有实现）</h1>"
    return body

#start_response参数格式：status,headers(list)
def application(env,start_response):
    start_response('200 OK',[('Content-Type','text/html;charset=utf-8')])
    file_name = env['PATH_INFO']
    if file_name == "/login.py":
        return login()
    else:
        return "<h1>没有定义的资源<h1>"