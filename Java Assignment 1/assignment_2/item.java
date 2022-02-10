//item.java
package assignment_2;

public class item {
    private String name;
    private double rate;
    private long code;
    private int quantity;

    public item() {
        this.name = "";
        this.rate = 0;
        this.code = 0;
        this.quantity = 0;
    }

    public item(String name, double rate, long code, int quantity) {
        this.name = name;
        this.rate = rate;
        this.code = code;
        this.quantity = quantity;
    }

    public item(item Item) {
        this.name = Item.name;
        this.rate = Item.rate;
        this.code = Item.code;
        this.quantity = Item.quantity;

    }
    
    public String toString() {
        String item_code=(name.substring(0,3)).concat(Integer.toString(quantity));
        System.out.println("item_code: "+item_code);
        return "Item [name=" + name + ", rate=" + rate + ", code=" + code
                + ", quantity=" + quantity + ", item_code=" + item_code + "]";
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getRate() {
        return rate;
    }

    public void setRate(double rate) {
        this.rate = rate;
    }

    public long getCode() {
        return code;
    }

    public void setCode(long code) {
        this.code = code;
    }

    public int getQuantity() {
        return quantity;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }
}