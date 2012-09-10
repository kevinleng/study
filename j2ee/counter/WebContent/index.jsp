<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
<%!// 一个同步用的锁
  private static final Object lock = new Object();%>
Hello Word!
<%
  Integer count = 0;
  // 此处是否有同步问题呢？
  // 比如2个用户同时拿到了当前的计数器，
  // 访问次数加1
  // 当更新时是否会丢失访问次数呢？
  // 
  // 会的,你可以在count=的代码后面增加如下的语句模拟一下就知道了
  // 所以此处同样要同步
  // 那我们自己定义一个同步锁吧，取名叫lock,放在了JSP的静态代码段里，
  synchronized (lock) {

    // 我们使用application 记录页面访问的计数器
    // 先从里面拿到数据
    // 注意这里一定要是使用Integer,而不是int
    // 因为如果第一次访问，则会返回null,再从Integer转化为int时会出现nullPointerException
    //
    count = (Integer) application.getAttribute("INDEX_COUNTER");

    //
    // 让线程等待10秒，这是你可以开2个浏览器，分别刷新，
    // 最后的计数器是只增加1的，而不是我们预期的2
    Thread.sleep(10000);

    // 如果是第一次访问，则进行初始化
    if (count == null) {
      // 这里使用了JDK5.0以后支持的自动box方式
      count = 0;

      // 保存到application里面
      application.setAttribute("INDEX_COUNTER", count);
    }
    count++;
    // 保存到application里面
    application.setAttribute("INDEX_COUNTER", count);
  }
%>
当前一共访问次数为:<%=count%>
</body>
</html>