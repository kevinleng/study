
package cn.kevin.web.counter.entity;

public class CountEntity {
    private int id;
    private int count;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        this.count = count;
    }

    public CountEntity(int id, int count) {
        super();
        this.id = id;
        this.count = count;
    }

    public CountEntity() {
        super();
    }

    @Override
    public String toString() {
        return "CountEntity [id=" + id + ", count=" + count + "]";
    }

}
