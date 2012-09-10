<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ page import="java.io.*"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
	<%!// 一个同步用的锁
    private static final Object lock = new Object();
    // 注意默认的文件目录在tomcat/bin目录下面
    //private static final File file = new File("counter.dat");
    private static File file = null;%>

	Hello Word!

	<%
	    Integer count = 0;
	    synchronized (lock) {
	        // 初始化文件名
	        if (file == null) {
	            file = new File(application.getRealPath(".")
	                    + "/WEB-INF/classes/counter.dat");
	        }

	        // 我们从文件读取数据
	        // 如果文件不存在，则需要初始化
	        if (!file.exists()) {
	            // 创建一个新的文件
	            file.createNewFile();
	            count = 0;
	        } else {
	            // 准备读取文件
	            FileReader reader = new FileReader(file);
	            // 从文件里读取int数据
	            count = reader.read();
	            // 关闭文件
	            reader.close();
	        }
	        count++;
	        // 准备写入文件
	        FileWriter writer = new FileWriter(file);
	        // 写入
	        writer.write(count);
	        // 关闭文件
	        writer.close();
	    }
	%>
	当前一共访问次数为:<%=count%>
</body>
</html>