<%@page import="java.sql.DriverManager"%>
<%@page import="javax.servlet.jsp.tagext.TryCatchFinally"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.Statement"%>
<%@page import="java.sql.Connection"%>
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
	        String dbName = "count";
	        String user = "root";
	        String pass = "123";
	        String host = "localhost";
	        int port = 3306;

	        String url = "jdbc:mysql://" + host + ":" + port + "/" + dbName;

	        Connection con = null;
	        Statement stmt = null;
	        ResultSet rs = null;

	        try {
	            Class.forName("com.mysql.jdbc.Driver");
	            con = DriverManager.getConnection(url, user, pass);
	            String SQL = "select * from tcount";
	            stmt = con.createStatement();
	            rs = stmt.executeQuery(SQL);

	            if (rs.next()) {
	                count = rs.getInt(1);
	            } else {
	                count = 0;
	            }
// 	            stmt.close();
	            count++;
	            //stmt = con.createStatement();
	             if(count==1){
	              	stmt.executeUpdate("insert into tcount(count) values(1)");
	              } else {
	                  int update = stmt.executeUpdate("update tcount set count="+count);
	  	            System.out.println("update : "+update);
	              } 
	            
	            
	        } catch (Exception e) {
	            e.printStackTrace();
	        } finally {
	            if (rs != null) {
	                try {
	                    rs.close();
	                } catch (Exception e) {
	                    e.printStackTrace();
	                }
	            }
	            if (stmt != null) {
	                try {
	                    stmt.close();
	                } catch (Exception e) {
	                    e.printStackTrace();
	                }
	            }
	            if (con != null) {
	                try {
	                    con.close();
	                } catch (Exception e) {
	                    e.printStackTrace();
	                }
	            }
	        }

	    }
	%>
	当前一共访问次数为:<%=count%>
</body>
</html>