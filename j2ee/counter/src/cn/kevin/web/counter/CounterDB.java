
package cn.kevin.web.counter;

import java.sql.*;

public class CounterDB {
    private static CounterDB db = new CounterDB();

    String dbName = "count";
    String user = "root";
    String pass = "123";
    String host = "localhost";
    int port = 3306;

    String url = "jdbc:mysql://" + host + ":" + port + "/" + dbName;

    private CounterDB() {
        try {
            Class.forName("com.mysql.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

    public static CounterDB getInstance() {
        return db;
    }

    public synchronized int increaseCount() {
        Connection con = null;
        Statement stmt = null;
        ResultSet rs = null;
        int count = 0;
        try {
            
            con = DriverManager.getConnection(url, user, pass);
            String SQL = "select * from tcount";
            stmt = con.createStatement();
            rs = stmt.executeQuery(SQL);

            if (rs.next()) {
                count = rs.getInt(1);
            } else {
                count = 0;
            }
            // stmt.close();
            count++;
            // stmt = con.createStatement();
            if (count == 1) {
                stmt.executeUpdate("insert into tcount(count) values(1)");
            } else {
                int update = stmt.executeUpdate("update tcount set count=" + count);
                System.out.println("update : " + update);
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
        
        return count;
    }

}
