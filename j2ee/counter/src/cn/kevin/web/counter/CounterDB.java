
package cn.kevin.web.counter;

import cn.kevin.web.counter.entity.CountEntity;

import org.hibernate.Session;

public class CounterDB {
    private static CounterDB db = new CounterDB();

    private CounterDB() {
    }

    public static CounterDB getInstance() {
        return db;
    }

    public synchronized int increaseCount() {
       Session session = HibernateUtils.getSessionFactory().getCurrentSession();
        
       session.beginTransaction();
       
       CountEntity count = (CountEntity) session.get(CountEntity.class, 1);
       if(count==null){
           count = new CountEntity();
       }
       count.setCount(count.getCount()+1);
       session.saveOrUpdate(count);
       
       session.getTransaction().commit();
       
       return count.getCount();
    }

}
