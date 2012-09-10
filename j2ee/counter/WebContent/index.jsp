<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
hello world!

<%
  // 我们使用application 记录页面访问的计数器
  // 先从里面拿到数据
  // 注意这里一定要是使用Integer,而不是int
  // 因为如果第一次访问，则会返回null,再从Integer转化为int时会出现nullPointerException
  //
  Integer count = (Integer) application.getAttribute("INDEX_COUNTER");

  // 如果是第一次访问，则进行初始化
  if (count == null) {
    // 这里使用了JDK5.0以后支持的自动box方式
    count = 0;

    // 保存到application里面
    application.setAttribute("INDEX_COUNTER", count);
  }
  // 访问次数加1
  count++;

  // 保存到application里面
  application.setAttribute("INDEX_COUNTER", count);
%>
当前一共访问次数为:<%=count%>
</body>
</html>